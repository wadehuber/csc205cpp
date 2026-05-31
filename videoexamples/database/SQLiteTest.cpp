// SQLiteTest.cpp
//
// C++ version of SQLiteTest.java.
//
// Java connects to a database through JDBC (the java.sql package). C++ has NO
// built-in or standard database API, so we call the SQLite C library directly
// (#include <sqlite3.h>, link with -lsqlite3).
//
// What this program does (same as the Java): open a connection to the file
// "csc205.db", print a message, then close the connection.
//
// JDBC -> sqlite3 C API mapping used here:
//   Connection conn                                  -> sqlite3* db
//   DriverManager.getConnection("jdbc:sqlite:...")   -> sqlite3_open("...", &db)
//   catch (SQLException e) ... e.getMessage()        -> check return code, sqlite3_errmsg(db)
//   conn.close()                                     -> sqlite3_close(db)
//
// NOTE: Java's "Class.forName("org.sqlite.JDBC")" loaded the JDBC driver. With
// the C API there is no driver to load - we link the library directly - so that
// step has no equivalent here.

#include <sqlite3.h>
#include <iostream>

int main() {
    // In Java, "conn" starts null and is assigned in the try block. Here db is
    // the equivalent handle. sqlite3_open fills it in for us.
    sqlite3* db = nullptr;

    // DriverManager.getConnection("jdbc:sqlite:csc205.db")
    // sqlite3_open returns SQLITE_OK (0) on success, or an error code otherwise.
    int rc = sqlite3_open("csc205.db", &db);

    if (rc == SQLITE_OK) {
        std::cout << "Opened database connection!" << std::endl;
    } else {
        // Mirror Java's catch block printing the error message.
        // sqlite3_errmsg gives a human-readable description of the problem.
        std::cout << "Error: " << sqlite3_errmsg(db) << std::endl;
    }

    // C++ has no "finally" block, so we just do the cleanup here on every path.
    // sqlite3_open allocates the handle even when it fails, so it is always safe
    // (and required) to close it.  conn.close()  ->  sqlite3_close(db)
    sqlite3_close(db);

    return 0;
}
