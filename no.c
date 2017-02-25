#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    int args = argc - 1;
    if (args && !strcmp(argv[1], "--help")) help();
    if (args && !strcmp(argv[1], "--version")) version();
    if (args && args > 1) {
        char myString[30];
        for (int i = 1; i < argc; i++) {
			append(myString, argv[i]);
			append(myString, " ");
        }
        print(myString);
    } else if (args) {
        print(argv[1]);
    } else {
        print("n");
    }
    return 1;
}

void print(char *string) {
while(1) {
    printf("%s\n", string);
}
}

void help() {
printf("Usage: no [STRING]...\n");
printf("  or:  no OPTION\n");
printf("Repeatedly output a line with all specified STRING(s), or 'n'.\n");
printf("\n");
printf("      --help     display this help and exit\n");
printf("      --version  output version information and exit\n");
printf("\n");
printf("Who the frick needs this program? Anyway, you can report bugs to <felix@emilnaumann.de>.\n");
exit(1);
}

void version() {
printf("no 1.3 inspired by yes GNU coreutils\n");
printf("Copyright (C) 2017 Felix Naumann.\n");
printf("This is free software.  You may redistribute copies of it under the terms of\n");
printf("the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.\n");
printf("There is NO WARRANTY, to the extent permitted by law.\n");
printf("\n");
printf("Written by Felix Naumann.\n");

exit(1);
}

void append(char *string, char *append) {
	strcat(string, append);
}
