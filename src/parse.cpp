#include <iostream>
#include "parse.hpp"
using std::cout, std::endl;

//parses the input
vector<tuple<string, string>> parse(int argc, char* argv[]) {

    //PROBLEM: the tuple should contain a string and a list of strings, instead of a string and a string. this is so that flags with multiple arguments can be stored

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
    if (func != "link" && func != "view") {
        throw std::runtime_error("Invalid function called.");
    }

    //checks to make sure flags are valid
    if (!validFlags(argc, argv)) {
        throw std::runtime_error("Invalid flags.");
    }

    /*
    //loops through the flags
    for (int i = 2; i < argc; i++) {
        //inserts flag
        if ((i % 2) == 0) {

            string flag = argv[i];
            string flag_input = argv[i + 1];

            //adds new flag to list
            flags.push_back({flag, flag_input});
        }
    }*/

    return flags;
}

//checks if the flags are valid for the given function
bool validFlags(int argc, char* argv[]) {

    //stores the function name
    string func = argv[1];

    //checks the flag depending on the name of the function 
    if (func == "link") {
        return validLinkFlags(argc, argv);
    } else if (func == "view") {
        return validViewFlags(argc, argv);
    } else {
        return false;
    }
}

//checks if flags are valid for the link function
bool validLinkFlags(int argc, char* argv[]) {


    /*
    MUST HAVE -f: name of the current file to link

    MUST HAVE -d: the name of the file you want to link the current file to. Can take in multiple inputs.
    
    -s means to link the file in one direction only. This means to link the desired file to the current file, but don't link the current file to the desired file. Essentially, the current file will point to the desired file, but the desired file won't point back to the current file. If -s isn't included, it will link the file both ways as default
    */

    //files cannot start with '-'

    //stores the valid flags only (not their inputs)
    vector<string> flags;

    for (int i = 2; i < argc; i++) {
        
        //stores the current argument
        string currArg = argv[i];

        //checks if it is a flag
        if (currArg[0] == '-') {

            //returns false if the flag is invalid
            if (currArg != "-f" && currArg != "-d" && currArg != "-s") {
                return false;

            //adds the valid flag to the list of flags
            } else {
                flags.push_back(currArg);
            }
        }
    }

    //TODO: figure out how to make sure inputs are valid for each flag

    //test
    cout << "[";
    for (int i = 0; i < flags.size(); i++) {

        if (i == (flags.size() - 1)) {
            cout << flags[i];
        } else {
            cout << flags[i] << ", ";
        }
    }
    cout << "]" << endl;

    return true;
}

//checks if flags are valid for the view function
bool validViewFlags(int argc, char* argv[]) {

    /*
    no flags: show the files that are linked both ways to the current file

    -t: show the files that the current file "points to"

    -f: show the files "pointing to" the current file

    -tf: show the files the current file is pointing to and the files 
    */

    //TODO add logic to check for validity
    cout << "View function called" << endl;

    if ((argc % 2) == 0) {
        return true;
    } else {
        return false;
    }
}