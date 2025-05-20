#ifndef AUTH_H
#define AUTH_H

#include <sqlite3.h>

int create_users_table(sqlite3* db);
int register_user(sqlite3* db, const char* username, const char* password);
int login_user(sqlite3* db, const char* username, const char* password, int* user_id);

#endif

