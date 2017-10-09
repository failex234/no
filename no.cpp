#include <iostream>
#include <cstring>
#include <string>

using namespace std;

string firstletter = "";
const string AUTHOR = "Felix Naumann"

/*
* Remove the dot and slash from the program name
* maybe I will rework this method if anybody would
* want to compile this code under windows so that it
* works as intented on Windows
*/
string shortenName(char prgname[]) {
    char newName[strlen(prgname)];
    for (int i = 0; i < strlen(prgname) - 2; i++) {
        if (i == 0) {
            newName[0] = prgname[2];
            firstletter = prgname[2];
        } else if (i == 1) {
            newName[1] = prgname[3];
        } else {
            newName[i] = prgname[i+2];
        }
        
    }
    if (!strcmp(newName,"")) newName = "no";
    return newName;
}

void help(char prgname[]) {
    string shortenedName = shortenName(prgname);
    cout << "Usage: " << shortenedName << " [STRING]...\n";
    cout << "   or: " << shortenedName << " OPTION\n";
    cout << "\n";
    cout << "        --help    display this help and exit\n";
    cout << "        --version output version information and exit\n";
    cout << "\n";
    cout << "Who the frick needs this program? Anyway, you can report bugs to <felix@emilnaumann.de>.\n";
}

void version(char prgname[]) {
string shortenedName = shortenName(prgname);
    cout << shortenedName << " 1.4 C++ Edition inspired by yes GNU coreutils\n";
    cout << "Copyright (C) 2017 " << AUTHOR << ".\n";
    cout << "This is free software.  You may redistribute copies of it under the terms of\n";
    cout << "the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.\n";
    cout << "There is NO WARRANTY, to the extent permitted by law.\n";
    cout << "\n";
    cout << "Written by " << AUTHOR << ".\n";
}

void print(string text) {
    while(true) {
        cout << text << "\n";
    }
}

int main(int args, char* argv[]) {
    for (int i = 0; i < args; i++) {
        if (!strcmp(argv[i], "--help")) {
            help(argv[0]);
            return 1;
        }
        if (!strcmp(argv[i], "--version")) {
            version(argv[0]);
            return 1;
        }
    }
     if(args > 2) {
            string longstring;
            for (int i = 1; i < args; i++) {
                longstring += argv[i];
                longstring += " ";
            }
            print(longstring);
        } else if (args == 2) {
            print(argv[1]);
        } else {
            shortenName(argv[0]);
            print(firstletter);
        }
    return 1;
}

