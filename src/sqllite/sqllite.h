/*
 * sqllite.h
 *
 *  Created on: Aug 21, 2015
 *      Author: andy
 */

#ifndef SRC_SQLLITE_SQLLITE_H_
#define SRC_SQLLITE_SQLLITE_H_

#ifdef __linux__
#include <sqlite3.h>
#endif

namespace sqllite {

#ifdef __linux__
static int callback(void *NotUsed, int argc, char **argv, char **azColName) {
  int i;
  for (i = 0; i < argc; i++) {
    printf("%s = %s\n", azColName[i], argv[i] ? argv[i] : "NULL");
  }
  printf("\n");
  return 0;
}
#endif

TEST_RESULT test() {
  LOG(INFO) << __PRETTY_FUNCTION__;
#ifdef __linux__
  sqlite3 *db;
  char *zErrMsg = 0;
  int rc;

  LOG(INFO) << "open database";
  rc = sqlite3_open("test.db", &db);

  LOG(INFO) << "rc=" << rc;

  if (rc) {
    fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
    sqlite3_close(db);
    return (1);
  }

  /* Create SQL statement */
  const char* sql = "CREATE TABLE COMPANY("
  "ID INT PRIMARY KEY     NOT NULL,"
  "NAME           TEXT    NOT NULL,"
  "AGE            INT     NOT NULL,"
  "ADDRESS        CHAR(50),"
  "SALARY         REAL );";
  /* Execute SQL statement */
  rc = sqlite3_exec(db, sql, callback, 0, &zErrMsg);
  if (rc != SQLITE_OK) {
    fprintf(stderr, "SQL error: %s\n", zErrMsg);
    sqlite3_free(zErrMsg);
  } else {
    fprintf(stdout, "Table created successfully\n");
  }
  sqlite3_close(db);

#else
  LOG(INFO) << "NOT IMPLEMENTED";

#endif
  RETURN_OK();
}

}  // namespace sqllite

#endif /* SRC_SQLLITE_SQLLITE_H_ */
