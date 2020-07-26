#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "util.h"

// gcc form_post.c util.c -o form_get.cgi
int main(int argc, char* argv) {
    printf("Content-type: text/html\n\n");
    printf("<h1>POST</h1>\n");

    char buffer[1024];
    int len = 0;
    do {
        len = fread(buffer, sizeof(char),1023, stdin);
        buffer[1023] =  '\n';
        buffer[len] = '\n';
        printf("%s", buffer);
    }while(len > 0);

    return 0;
}
