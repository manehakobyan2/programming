#ifndef SLOT_MANAGE_H
#define SLOT_MANAGE_H
#include <sqlite3.h>

void create_slots_table(sqlite3* db);

int create_slot(sqlite3* db, int user_id, const char* slot_name);

int delete_slot(sqlite3* db, int user_id, const char* slot_name);

void view_slots(sqlite3* db, int user_id);

double get_total_balance(sqlite3* db, int user_id);

int update_total_balance(sqlite3* db, int user_id, double new_balance);

int transfer_to_slot(sqlite3* db, int user_id, const char* slot_name, double amount);

int transfer_from_slot(sqlite3* db, int user_id, const char* slot_name, double amount);

#endif // SLOT_MANAGE_H

