#include <stdio.h>
#include <sqlite3.h>
#include <string.h>

#include "slot_manage.h"


// Create slots table if it doesn't exist
void create_slots_table(sqlite3* db) {
    const char* sql = "CREATE TABLE IF NOT EXISTS slots ("
                      "slot_id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "user_id INTEGER NOT NULL, "
                      "slot_name TEXT NOT NULL, "
                      "balance REAL DEFAULT 0.0, "
                      "FOREIGN KEY (user_id) REFERENCES users(id));";
    char* err = NULL;
    if (sqlite3_exec(db, sql, 0, 0, &err) != SQLITE_OK) {
        fprintf(stderr, "Error creating slots table: %s\n", err);
        sqlite3_free(err);
    }
}

// new slot for a user
int create_slot(sqlite3* db, int user_id, const char* slot_name) 
    {
    //sql query to inser a new row into slots
    const char* sql = "INSERT INTO slots (user_id, slot_name) VALUES (?, ?);";
    sqlite3_stmt* stmt;
    //Prepare the sql statement
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) 
     { 
        //error message printing
        fprintf(stderr, "Failed to prepare create_slot statement: %s\n", sqlite3_errmsg(db));
        return 0; //returning 0 indicating error
    }
    //bind user id to first placeholder and slot name to secon
    sqlite3_bind_int(stmt, 1, user_id);
    sqlite3_bind_text(stmt, 2, slot_name, -1, SQLITE_STATIC);
     //execute statment
     int rc = sqlite3_step(stmt);
   
    //clean up the prepared statment
    sqlite3_finalize(stmt);

    //check for insert to be succesful
    if (rc != SQLITE_DONE) 
    {
        fprintf(stderr, "Failed to create slot: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    //meaning succesful slot creation
    return 1;
}

// delete a slot by name for a user
int delete_slot(sqlite3* db, int user_id, const char* slot_name) 
    {
    const char* sql = "DELETE FROM slots WHERE user_id = ? AND slot_name = ?;";
    sqlite3_stmt* stmt;
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare delete_slot statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    sqlite3_bind_int(stmt, 1, user_id);
    sqlite3_bind_text(stmt, 2, slot_name, -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) 
    {
        fprintf(stderr, "Failed to delete slot: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    return 1;
}

// View all slots for a user
void view_slots(sqlite3* db, int user_id) 
    {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT slot_name, balance FROM slots WHERE user_id = ?;";
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare view_slots statement: %s\n", sqlite3_errmsg(db));
        return;
    }

    sqlite3_bind_int(stmt, 1, user_id);

    printf("\n--- Your Slots ---\n");
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        const unsigned char* slot_name = sqlite3_column_text(stmt, 0);
        double balance = sqlite3_column_double(stmt, 1);
        printf("Slot: %s | Balance: %.2f\n", slot_name, balance);
    }
    printf("------------------\n");

    sqlite3_finalize(stmt);
}

// get total balance of user (from users table)
double get_total_balance(sqlite3* db, int user_id) {
    sqlite3_stmt* stmt;
    const char* sql = "SELECT total_balance FROM users WHERE id = ?;";
    double balance = 0.0;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare get_total_balance statement: %s\n", sqlite3_errmsg(db));
        return balance;
    }

    sqlite3_bind_int(stmt, 1, user_id);

    if (sqlite3_step(stmt) == SQLITE_ROW) {
        balance = sqlite3_column_double(stmt, 0);
    }
    sqlite3_finalize(stmt);

    return balance;
}

// update total balance in users table
int update_total_balance(sqlite3* db, int user_id, double new_balance) {
    const char* sql = "UPDATE users SET total_balance = ? WHERE id = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare update_total_balance statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    sqlite3_bind_double(stmt, 1, new_balance);
    sqlite3_bind_int(stmt, 2, user_id);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to update total balance: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    return 1;
}

// add money from total balance to a slot
int transfer_to_slot(sqlite3* db, int user_id, const char* slot_name, double amount) {
    if (amount <= 0) {
        fprintf(stderr, "Amount must be positive.\n");
        return 0;
    }

    double total_balance = get_total_balance(db, user_id);
    if (total_balance < amount) {
        fprintf(stderr, "Insufficient total balance.\n");
        return 0;
    }

    // rmove from total_balance
    if (!update_total_balance(db, user_id, total_balance - amount)) {
        return 0;
    }

    // add to slot balance
    const char* sql = "UPDATE slots SET balance = balance + ? WHERE user_id = ? AND slot_name = ?;";
    sqlite3_stmt* stmt;

    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare transfer_to_slot statement: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    sqlite3_bind_double(stmt, 1, amount);
    sqlite3_bind_int(stmt, 2, user_id);
    sqlite3_bind_text(stmt, 3, slot_name, -1, SQLITE_STATIC);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    if (rc != SQLITE_DONE) {
        fprintf(stderr, "Failed to add money to slot: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    return 1;
}

// withdraw money from slot back to total balance
int transfer_from_slot(sqlite3* db, int user_id, const char* slot_name, double amount) {
    if (amount <= 0) {
        fprintf(stderr, "Amount must be positive.\n");
        return 0;
    }

    //check slot balance
    sqlite3_stmt* stmt;
    const char* sql_balance = "SELECT balance FROM slots WHERE user_id = ? AND slot_name = ?;";
    if (sqlite3_prepare_v2(db, sql_balance, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement for checking slot balance: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    sqlite3_bind_int(stmt, 1, user_id);
    sqlite3_bind_text(stmt, 2, slot_name, -1, SQLITE_STATIC);

    double slot_balance = 0.0;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        slot_balance = sqlite3_column_double(stmt, 0);
    } else {
        fprintf(stderr, "Slot not found.\n");
        sqlite3_finalize(stmt);
        return 0;
    }
    sqlite3_finalize(stmt);

    if (slot_balance < amount) {
        fprintf(stderr, "Insufficient slot balance.\n");
        return 0;
    }

    //Deduct money from slot
    const char* sql_deduct = "UPDATE slots SET balance = balance - ? WHERE user_id = ? AND slot_name = ?;";
    if (sqlite3_prepare_v2(db, sql_deduct, -1, &stmt, NULL) != SQLITE_OK) {
        fprintf(stderr, "Failed to prepare statement for deducting slot balance: %s\n", sqlite3_errmsg(db));
        return 0;
    }
    sqlite3_bind_double(stmt, 1, amount);
    sqlite3_bind_int(stmt, 2, user_id);
    sqlite3_bind_text(stmt, 3, slot_name, -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        fprintf(stderr, "Failed to deduct from slot balance: %s\n", sqlite3_errmsg(db));
        sqlite3_finalize(stmt);
        return 0;
    }
    sqlite3_finalize(stmt);

    //add to total balance
    double total_balance = get_total_balance(db, user_id);
    if (!update_total_balance(db, user_id, total_balance + amount)) {
        return 0;
    }

    return 1;
}

