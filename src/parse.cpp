#include <iostream>
#include "parse.hpp"
using std::cout, std::endl;

vector<tuple<string, string>> parse(int argc, char* argv[]) {

    //vector of tuples to hold each flag and it's input
    vector<tuple<string, string>> flags;

    //must have at least two arguments
    if (argc <= 1) {
        throw std::runtime_error("No function called.");
    }

    //name of exectuable
    string exe = argv[0];

    //executable must be named zettal
    if (exe != "./zettal") {
        throw std::runtime_error("Executable must be named zettal");
    }

    //name of function
    string func = argv[1];

    //must be a valid function
    if (func != "file" && func != "folder" && func != "link") {
        throw std::runtime_error("Invalid function called.");
    }

    //loops through the flags
    for (int i = 2; i < argc; i++) {
        //inserts flag
        if ((i % 2) == 0) {

            string flag = argv[i];
            string flag_input = argv[i + 1];

            //adds new flag to list
            flags.push_back({flag, flag_input});
        }
    }

    return flags;
}