#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sqlite3.h>
#include "auth.h"

//when program is run we create table if it doesnt exist in db yet 
int create_users_table(sqlite3* db) 
{
    //sql command to create the user table 
    const char* sql = "CREATE TABLE IF NOT EXISTS users ("
                      "id INTEGER PRIMARY KEY AUTOINCREMENT, "
                      "username TEXT UNIQUE, "
                      "password TEXT, "
                      "total_balance REAL DEFAULT 100000.0);";
    //Creating a variable to store sql error messages
    char* err = 0;
    //check for errors when executing the function
    if (sqlite3_exec(db, sql, 0, 0, &err) != SQLITE_OK) 
    {
       //Print error message
       fprintf(stderr, "Error creating users table: %s\n", err);

       //free the memory
       sqlite3_free(err);
       return 0;
    }
    //if succesful function returns 1
    return 1;
}

//registering users
int register_user(sqlite3 *db, const char *username, const char *password) 
{
    //using sql statement to insert a new user  
    const char *sql = "INSERT INTO users(username, password) VALUES (?, ?);";
    
    //making a pointer to a struct
    sqlite3_stmt *stmt;

    //preparing the sql statement 
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) 
   {
        //print error message
       fprintf(stderr, "Prepare failed: %s\n", sqlite3_errmsg(db));
        return 0;
    }

    //binding the username to the first placeholder 
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
//bind password to second statement
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

     //checks if inserting the username and password has failed
    if (sqlite3_step(stmt) != SQLITE_DONE) 
    {
        //print fail message
        fprintf(stderr, "Insert failed: %s\n", sqlite3_errmsg(db));
        //clean 
        sqlite3_finalize(stmt);
        return 0;
    }
    //again clean prepared statement
    sqlite3_finalize(stmt);
    return 1;
}


int login_user(sqlite3 *db, const char *username, const char *password, int *id) 
{
   //SQL query with two placeholders ? ? username and password
    const char *sql = "SELECT id FROM users WHERE username = ? AND password = ?";
    sqlite3_stmt *stmt;
    //prepare the sql statementr
    if (sqlite3_prepare_v2(db, sql, -1, &stmt, NULL) != SQLITE_OK) return -1;
    //binding values again
    sqlite3_bind_text(stmt, 1, username, -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, password, -1, SQLITE_STATIC);

    //defining a variable to return once
    int ret = 0;
    if (sqlite3_step(stmt) == SQLITE_ROW) 
   {
        //get the id when match is found
        *id = sqlite3_column_int(stmt, 0);  
        ret = 1;
    }

    sqlite3_finalize(stmt);
    return ret;  
}
