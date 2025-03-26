#include <iostream>
#include "parse.hpp"
using std::cout, std::endl;

//parses the input
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

    //checks to make sure flags are valid
    if (!validFlags(argc, argv)) {
        throw std::runtime_error("Invalid flags.");
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

//checks if the flags are valid for the given function
bool validFlags(int argc, char* argv[]) {

    //stores the function name
    string func = argv[1];

    //checks the flag depending on the name of the function 
    if (func == "file") {
        return validFileFlags(argc, argv);
    } else if (func == "folder") {
        return validFolderFlags(argc, argv);
    } else if (func == "link"){
        return validLinkFlags(argc, argv);
    } else {
        return false;
    }
}

//checks if flags are valid for the file function
bool validFileFlags(int argc, char* argv[]) {

    //TODO add logic to check for validity
    cout << "File function called" << endl;

    if ((argc % 2) == 0) {
        return true;
    } else {
        return false;
    }
}

//checks if flags are valid for the folder function
bool validFolderFlags(int argc, char* argv[]) {

    //TODO add logic to check for validity
    cout << "Folder function called" << endl;

    if ((argc % 2) == 0) {
        return true;
    } else {
        return false;
    }
}

//checks if flags are valid for the link function
bool validLinkFlags(int argc, char* argv[]) {

    //TODO add logic to check for validity
    cout << "Link function called" << endl;

    if ((argc % 2) == 0) {
        return true;
    } else {
        return false;
    }
}