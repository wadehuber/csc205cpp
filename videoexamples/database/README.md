# Databases (C++ version)

These examples use [SQLite](https://www.sqlite.org/index.html), though the specific database isn't that critical - you can use SQL Server, Oracle, MySQL, or any other database.  The video below gives an example of how databases work.  You do not need to install Ubuntu for the project.

- [Video: Using SQL & the SQLite Console](https://youtu.be/XZyY3yweTas) (5:43)

## C++ has no built-in database API

This is the biggest difference from the Java version. Java ships with a standard
database API in the `java.sql` package (JDBC). C++ has **no built-in or standard
database library at all**. Instead, you pick a database and call *its* C library
directly.

Here we use the **SQLite C API** (`#include <sqlite3.h>`, link with `-lsqlite3`).
This is a real, working database - the same engine the Java examples use through
the JDBC driver - we are just calling it directly instead of through a driver
layer.

### How JDBC concepts map to the SQLite C API

| Java / JDBC | SQLite C API |
|-------------|--------------|
| `Connection conn` | `sqlite3* db` |
| `Class.forName("org.sqlite.JDBC")` (load driver) | *(none - library is linked directly)* |
| `DriverManager.getConnection("jdbc:sqlite:csc205.db")` | `sqlite3_open("csc205.db", &db)` |
| `catch (SQLException e)` / `e.getMessage()` | check the return code / `sqlite3_errmsg(db)` |
| `Statement` + `stmt.execute(sql)` | `sqlite3_exec(db, sql, ...)` |
| `PreparedStatement` (`prepareStatement`) | `sqlite3_stmt*` via `sqlite3_prepare_v2` |
| `pstmt.setString(1, ...)` / `pstmt.setInt(3, ...)` (1-based) | `sqlite3_bind_text(stmt, 1, ...)` / `sqlite3_bind_int(stmt, 3, ...)` (1-based) |
| `pstmt.executeUpdate()` | `sqlite3_step(stmt)` |
| `ResultSet rs` / `while (rs.next())` | `while (sqlite3_step(stmt) == SQLITE_ROW)` |
| `rs.getString(...)` / `rs.getInt(...)` | `sqlite3_column_text(stmt, i)` / `sqlite3_column_int(stmt, i)` (0-based columns) |
| `conn.close()` | `sqlite3_close(db)` |

A couple of notes for Java programmers:

- C++ has no `finally` block, so we just run the cleanup (`sqlite3_close`,
  `sqlite3_finalize`) on every path through the code.
- `sqlite3_column_text` returns a `const unsigned char*`, so we cast it to
  `const char*` before printing.
- Bind parameters are **1-based** (like JDBC), but result columns read with
  `sqlite3_column_*` are **0-based**.

## Installing the dependency

You need the SQLite development library (header + lib) to build these.

- **Debian / Ubuntu / WSL:** `sudo apt-get install libsqlite3-dev`
- **Windows (MSYS2):** `pacman -S mingw-w64-x86_64-sqlite3`

## The programs

- **SQLiteTest.cpp** - provided as a test to ensure SQLite is installed correctly. Opens a connection to `csc205.db`, prints a message, and closes it.
- **DatabaseExample.cpp** [Video](https://youtu.be/0beocykXUag) (7:02) - example of using a database. Creates a `Movies` table, inserts 10 movies with a prepared statement, then selects and prints them. (The video walks through setting up SQLite for the original Java version in Eclipse.)

## Building and running

```
make        # build both programs
make run    # build and run them
make clean  # delete the built programs and the generated csc205.db
```
