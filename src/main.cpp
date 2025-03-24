#include <iostream>
#include <string>
#include <vector>
#include "newNote.hpp"

using std::cout, std::endl, std::string;

//allows CLI inputs
//argc stores the number of parameters, argv is an array of c-strings
int main(int argc, char* argv[]) {

    //must have at least two arguments
    if (argc <= 1) {
        return -1;
    }

    //name of exectuable
    string exe = argv[0];

    //executable must be named zettal
    if (exe != "./zettal") {
        return -1;
    }

    //name of function
    string func = argv[1];

    //must be a valid function
    if (func != "file" && func != "folder" && func != "link") {
        return -1;
    }

    //if it reaches here:
    //there are at least 2 arguments, the executable is named zettal, and it is a valid function call.

    //have a for loop iterate through the flags
    /*
    for (int i = 2; i < argc; i++) {

    }*/

    return 0;
}