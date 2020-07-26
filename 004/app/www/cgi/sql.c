// gcc main.c  -lmysqlclient -omain.cgi
#include<stdio.h>
#include<mysql/mysql.h>

#define HOST "mysqld"
#define USER "root"
#define PASS "passwd"
#define DB "myapp"

#define TABLE_APPS  "apps"

int main(int argc, char* argv[]) {
    printf("Content-type: text/html\n\n");
    printf("Hello,World!!\n");
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);
    if (!mysql_real_connect(conn, HOST, USER, PASS, DB, 3306, NULL, 0)) {
        //fprintf(stderr, "%s\n", mysql_error(conn));
        // exit(1);
        printf("%s\n", mysql_error(conn));
        return 0;
    }
    
    //
    // Show クエリ発行
    if (mysql_query(conn, "show tables")) {
        fprintf(stderr, "err(1):%s\n", mysql_error(conn));
        exit(1);
    }
    res = mysql_use_result(conn);

    // 結果表示
    printf("[q] show tables\n");
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("  %s\n", row[0]);
    }
    mysql_free_result(res);


    //
    // Select クエリ発行
    printf("[q] select * from apps\n");
    if(mysql_query(conn, "select * from apps")){
        fprintf(stderr, "err(2):%s\n", mysql_error(conn));
        exit(1);
    }
    
    res = mysql_store_result(conn);
    while ((row = mysql_fetch_row(res)) != NULL) {
        printf("  %s, %s\n", row[0], row[1]);
    }
    mysql_free_result(res);

    // Insert
    printf("[q] insert into apps(id,name)...\n");
    int resp = mysql_query(conn, "insert into apps(id,name) VALUES (2, 'dango') ");
    if(resp){
        fprintf(stderr, "err(2):%s\n", mysql_error(conn));
        exit(1);
    }

    // Delete
    printf("[q] delete drom apps where id=2\n");
    resp = mysql_query(conn, "delete from apps where id=2 ");
    if(resp){
        fprintf(stderr, "err(2):%s\n", mysql_error(conn));
        exit(1);
    }
    mysql_close(conn);
    return 0;
}