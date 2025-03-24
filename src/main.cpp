#include <iostream>
#include <string>
#include <vector>
#include <tuple>
#include "newNote.hpp"

using std::cout, std::endl, std::string, std::vector, std::tuple;

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

    //vector of tuples to hold each flag and it's input
    vector<tuple<string, string>> flags;

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

    //test
    for (int i = 0; i < flags.size(); i++) {
        cout << "(" << std::get<0>(flags.at(i)) << ", " << std::get<1>(flags.at(i)) << ")" << endl;
    }

    return 0;
}