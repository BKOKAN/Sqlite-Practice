#include <iostream>
#include <fstream>
#include <sqlite3.h>
int main()
{
    // Connect to the database
    sqlite3* db;
    int rc = sqlite3_open("example.db", &db);
    if (rc != SQLITE_OK) {
        // Handle connection error
        return rc;
    }

    // Create a table
    const char* createTableQuery = "CREATE TABLE users (name TEXT, email TEXT);";
    char* errorMessage;
    rc = sqlite3_exec(db, createTableQuery, 0, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        // Handle table creation error
        sqlite3_free(errorMessage);
        return rc;
    }

    // Insert data
    const char* insertQuery = "INSERT INTO users (name, email) VALUES ('John Doe', 'john@example.com');";
    rc = sqlite3_exec(db, insertQuery, 0, 0, &errorMessage);
    if (rc != SQLITE_OK) {
        // Handle data insertion error
        sqlite3_free(errorMessage);
        return rc;
    }

    // Close the database connection
    sqlite3_close(db);

    return 0;
}