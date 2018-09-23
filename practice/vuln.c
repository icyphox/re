/* bof in the presence of stack canary and ASLR */

#include <stdio.h>
#include <string.h>

#define STDIN 0

void memLeak() {
    char buf[512];
    scanf("%s", buf);
    printf(buf);
}

void vulnFunc() {
    char buf[1024];
    read(STDIN, buf, 2048);
}

int main(int argc, char* argv[]) {

    setbuf(stdout, NULL);
    printf("echo> ");
    memLeak();
    printf("\n");
    printf("read> ");
    vulnFunc();

    printf("\ndone.\n");

    return 0;

}


