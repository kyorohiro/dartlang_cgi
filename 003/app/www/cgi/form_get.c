#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "util.h"

// gcc form_get.c util.c -o form_get.cgi
int main(int argc, char* argv) {
    printf("Content-type: text/html\n\n");
    printf("<h1>QUERY_STRING!!</h1>\n");

    char* queryString = getenv("QUERY_STRING");
    if(queryString == NULL) {
        return 0;
    }
    printf("(1)%s<br><hr><br>\n", queryString);

    char fname[256];
    getQueryParam("fname", fname, 256);
    printf("(2)fname: %s<br>\n\n", fname);
    return 0;
}