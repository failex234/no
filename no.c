#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

const char *AUTHOR = "Felix Naumann";

void help(const char *prgname) {
    printf("Usage: %s [STRING]...\n", prgname);
    printf("   or: %s OPTION\n\n", prgname);
    printf("        --help    display this help then exit\n");
    printf("        --version output version information then exit\n\n");
    printf("If you want to you can report bugs to <felix@emilnaumann.de>\n");
}

void version(const char *prgname) {
	printf("%s 1.5 C Edition inspired by yes\n");
	printf("Copyright (C) 2018 %s.\n", AUTHOR);
    printf("This is free software.  You may redistribute copies of it under the terms of\n");
    printf("the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.\n");
    printf("There is NO WARRANTY, to the extent permitted by law.\n\n");
    printf("Written by %s.\n", AUTHOR);
}

void print(const char *text) {
    while(true) {
        printf("%s\n", text);
    }
}

int main(int args, char** argv) {
    for (int i = 0; i < args; i++) {
        if (!strcmp(argv[i], "--help")) {
            help(argv[0]);
            return EXIT_SUCCESS;
        }
        if (!strcmp(argv[i], "--version")) {
            version(argv[0]);
            return EXIT_SUCCESS;
        }
    }
     if(args > 2) {
            char buf[2048];
            for (int i = 1; i < args; i++) {
            	strcpy(buf, argv[i]);
            	strcpy(buf, " ");
            }
            print(buf);
        } else if (args == 2) {
            print(argv[1]);
        } else {
            print("n");
        }
    return EXIT_SUCCESS;
}

