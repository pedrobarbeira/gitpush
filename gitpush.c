#ifdef _WIN32
#define LINUX 0
#endif

#ifdef linux
#define LINUX 1
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define BUFFERSIZE 80

char buffer[BUFFERSIZE];

int main(int argc, char* argv[]){
    if(argc > 2){
        fprintf(stderr, "usage: gitpush <optional_message>\n");
        exit(EXIT_FAILURE);
    }
    system("git add .");
    char cmd[256];
    strcpy(cmd, "git commit -m \"");
    if(argc == 1){
        char* CMD;
        if(LINUX) CMD = "date";
        else CMD = "date /t";
        
        FILE* date_cmd = popen(CMD, "r");
        if(date_cmd == NULL){
            fprintf(stderr, "pipe(3) error\n");
            exit(EXIT_FAILURE);
        }
        if(fread(buffer, sizeof(char), BUFFERSIZE, date_cmd)==0){
            fprintf(stderr, "error reading buffer\n");
            exit(EXIT_FAILURE);
        }
        pclose(date_cmd);
        strcat(cmd, buffer);
    }
    else strcat(cmd, argv[1]);
    strcat(cmd, "\"");
    system(cmd);
    system("git push --recurse-submodules=on-demand origin master");

    exit(EXIT_SUCCESS);
}