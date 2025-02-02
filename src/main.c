#include<stdio.h>
#include<wchar.h>
#include"../include/sqlite3.h"
#include<stdlib.h>
#include<locale.h>
#include<string.h>
#include<iconv.h>
#include"../include/other.h"
#include<getopt.h>
#include<time.h>
//这个程序是该项目的主程序
int main(int argc,char *argv[]) {
    sqlite3 *db;
    sqlite3_stmt* stmt;
    int rc = sqlite3_open("student.db",&db);
    if (rc != SQLITE_OK) {
        fprintf(stderr,"Cannot open this database.");
    }
    static struct option options[] = {
        {"add",no_argument,NULL,'a'},
        {"change",no_argument,NULL,'c'},
        {"help",no_argument,NULL,'h'},
        {"list",no_argument,NULL,'l'},
        {NULL,0,NULL,0}
    };
    int opt_index;
    char c = getopt_long(argc,argv,"achln",options,&opt_index);
    switch (c) {
        case 'a':
            create_message(db,stmt);
            break;
        case 'c':
            change_information(db,stmt);
            break;
        case '?':
        case 'h':
            do_help();
            break;
        case 'l':
            list(db,stmt);
            break;
        case -1:
        case 'n':
            count_the_students(db,stmt);
            break;
        default:
            break;
    }
    system("pause");
    return 0;
}