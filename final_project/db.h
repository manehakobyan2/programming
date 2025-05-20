// db.h
#ifndef DB_H
#define DB_H

#include <sqlite3.h>

sqlite3* connect_db(const char* filename);

#endif

