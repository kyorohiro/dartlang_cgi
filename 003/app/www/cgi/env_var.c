#include<stdio.h>
#include<stdlib.h>

int main(int argc, char* argv[], char *envp[]) {
    printf("Content-type: text/html\n\n");
    printf("<h1>Environment variables !!</h1>\n");
    printf("<p>\n");
    char** env = envp;
    while(*env != 0) {
        printf("%s<br>\n", *env);
        env++;
    }
    printf("</p>\n");
    return 0;
}
