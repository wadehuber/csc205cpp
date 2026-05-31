// DatabaseExample.cpp
//
// C++ version of DatabaseExample.java.
//
// Java talks to the database through JDBC (java.sql). C++ has NO built-in or
// standard database API, so we use the SQLite C library directly
// (#include <sqlite3.h>, link with -lsqlite3).
//
// The program flow is identical to the Java version:
//   1. open the database "csc205.db"
//   2. drop the Movies table if it already exists (ignore the error if not)
//   3. create the Movies table
//   4. insert 10 movies using a prepared statement
//   5. display every row in the table
//   6. close the database
//
// JDBC -> sqlite3 C API mapping used throughout this file:
//   Connection                 -> sqlite3*        (the open database handle)
//   Statement / executeUpdate  -> sqlite3_exec    (run SQL with no results back)
//   PreparedStatement          -> sqlite3_stmt*   (sqlite3_prepare_v2 + bind + step)
//   ResultSet / rs.next()      -> sqlite3_step loop returning SQLITE_ROW
//   rs.getString/getInt        -> sqlite3_column_text / sqlite3_column_int

#include <sqlite3.h>
#include <iostream>
#include <string>

// Forward declarations of the helper functions. In Java these were the private
// static methods (createTable, deleteTable, insertMovie, displayDatabase). Here
// they are free functions that take the sqlite3* handle, mirroring how the Java
// methods took the Connection.
void deleteTable(sqlite3* db);
void createTable(sqlite3* db);
void insertMovie(sqlite3* db, const std::string& title,
                 const std::string& director, int year,
                 const std::string& rating);
void displayDatabase(sqlite3* db, const std::string& tableName);

int main() {
    // Connection conn = null;  ->  sqlite3* db = nullptr;
    sqlite3* db = nullptr;

    // DriverManager.getConnection("jdbc:sqlite:csc205.db")
    int rc = sqlite3_open("csc205.db", &db);
    if (rc != SQLITE_OK) {
        // Mirror Java's catch block: print the error and stop.
        std::cout << "Error: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }
    std::cout << "Opened database connection!" << std::endl;

    // Java wrapped deleteTable in a try/catch that ignored the error (the table
    // might not exist yet). In C we just run it and ignore any error code.
    deleteTable(db);   // table must already exist; ignore failure if it doesn't

    createTable(db);

    std::cout << std::endl;
    std::cout << "Inserting data" << std::endl;
    insertMovie(db, "Aliens", "James Cameron", 1986, "R");
    insertMovie(db, "Highlander", "Russell Mulcahy", 1986, "R");
    insertMovie(db, "Goodfellas", "Martin Scorsese", 1990, "R");
    insertMovie(db, "Inside Out", "Pete Docter", 2015, "PG");
    insertMovie(db, "Guardians of the Galaxy", "James Gunn", 2014, "PG-13");
    insertMovie(db, "Dick Tracy", "Warren Beatty", 1990, "PG");
    insertMovie(db, "Toy Story", "John Lasseter", 1995, "G");
    insertMovie(db, "Twelve Monkeys", "Terry Gilliam", 1995, "R");
    insertMovie(db, "The Dark Knight", "Christopher Nolan", 2008, "PG-13");
    insertMovie(db, "The Hurt Locker", "Kathryn Bigelow", 2008, "R");

    std::cout << std::endl;
    std::cout << "Displaying database" << std::endl;
    displayDatabase(db, "Movies");

    // C++ has no "finally" block, so we close the connection here at the end.
    // conn.close()  ->  sqlite3_close(db)
    sqlite3_close(db);

    return 0;
}

// displayDatabase: SELECT * from <tableName> and print every row.
// Java used Statement + ResultSet; here we use a prepared statement and step
// through the rows. ResultSet.next() == SQLITE_ROW from sqlite3_step.
void displayDatabase(sqlite3* db, const std::string& tableName) {
    std::string selectSQL = "SELECT * from " + tableName;

    // conn.createStatement() / prepareStatement  ->  sqlite3_prepare_v2
    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db, selectSQL.c_str(), -1, &stmt, nullptr) != SQLITE_OK) {
        std::cout << "Error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    std::cout << "------- " << tableName << " -------" << std::endl;

    // while (rs.next()) { ... }  ->  while (sqlite3_step(stmt) == SQLITE_ROW)
    // Columns are 0-based here. The table was created as
    // (title, director, year, rating), so 0=title, 1=director, 2=year, 3=rating.
    // SQLite returns the rows in insertion order here, just like the Java run.
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        // sqlite3_column_text returns "const unsigned char*"; cast to const char*
        // so std::cout treats it as a string instead of a number.
        std::cout << "Movie: "
                  << reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)) << ", ";
        std::cout << reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)) << ", ";
        std::cout << sqlite3_column_int(stmt, 2) << ", ";
        std::cout << reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)) << std::endl;
    }

    std::cout << "------------------------------" << std::endl;

    // Always release the prepared statement (no JDBC equivalent line needed -
    // Java's garbage collector handled this for us).
    sqlite3_finalize(stmt);
}

// insertMovie: mirrors Java's PreparedStatement usage exactly.
void insertMovie(sqlite3* db, const std::string& title,
                 const std::string& director, int year,
                 const std::string& rating) {
    std::string insertSQL =
        "INSERT INTO Movies(title, director, year, rating) VALUES(?,?,?,?)";

    // conn.prepareStatement(insertSQL)  ->  sqlite3_prepare_v2
    sqlite3_stmt* pstmt = nullptr;
    if (sqlite3_prepare_v2(db, insertSQL.c_str(), -1, &pstmt, nullptr) != SQLITE_OK) {
        std::cout << "Error: " << sqlite3_errmsg(db) << std::endl;
        return;
    }

    // Bind the four "?" placeholders. Like JDBC, the indices are 1-based.
    // pstmt.setString(1, title)  ->  sqlite3_bind_text(pstmt, 1, ...)
    // pstmt.setInt(3, year)      ->  sqlite3_bind_int(pstmt, 3, year)
    // SQLITE_TRANSIENT tells SQLite to make its own copy of each string.
    sqlite3_bind_text(pstmt, 1, title.c_str(),    -1, SQLITE_TRANSIENT);
    sqlite3_bind_text(pstmt, 2, director.c_str(), -1, SQLITE_TRANSIENT);
    sqlite3_bind_int (pstmt, 3, year);
    sqlite3_bind_text(pstmt, 4, rating.c_str(),   -1, SQLITE_TRANSIENT);

    // pstmt.executeUpdate()  ->  sqlite3_step (for INSERT it runs to completion)
    sqlite3_step(pstmt);

    // Release the prepared statement.
    sqlite3_finalize(pstmt);
}

// createTable: same SQL as the Java version.
void createTable(sqlite3* db) {
    std::string createTableSQL =
        "CREATE TABLE  Movies "
        "( "
        "title varchar(255), "
        "director varchar(255), "
        "year integer, "
        "rating varchar(5) "
        "); ";

    // Statement.execute(sql) with no result  ->  sqlite3_exec
    sqlite3_exec(db, createTableSQL.c_str(), nullptr, nullptr, nullptr);
}

// deleteTable: DROP TABLE Movies. Any error (e.g. table does not exist) is
// ignored on purpose, matching Java's try/catch(ignored) around this call.
void deleteTable(sqlite3* db) {
    std::string deleteTableSQL = "DROP TABLE Movies";
    sqlite3_exec(db, deleteTableSQL.c_str(), nullptr, nullptr, nullptr);
}
