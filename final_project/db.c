// db.c
#include <sqlite3.h>
#include <stdio.h>
#include "db.h"

sqlite3* connect_db(const char* filename) {
    sqlite3* db;
    if (sqlite3_open(filename, &db) != SQLITE_OK) {
        fprintf(stderr, "Failed to open database: %s\n", sqlite3_errmsg(db));
        return NULL;
    }
    return db;
}

