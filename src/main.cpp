#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <tuple>
#include "newNote.hpp"
#include "parse.hpp"

using std::cout, std::endl, std::string, std::vector, std::tuple;

//allows CLI inputs
//argc stores the number of parameters, argv is an array of c-strings
int main(int argc, char* argv[]) {

    //stores parsed input in a vector of tuples
    vector<tuple<string, string>> parsedInput;

    //tries to parse input
    try{
        parsedInput = parse(argc, argv);
    } catch (const std::runtime_error & e) {
        cout << e.what() << endl;
    }

    /*
    //test
    for (int i = 0; i < parsedInput.size(); i++) {
        cout << "(" << std::get<0>(parsedInput.at(i)) << ", " << std::get<1>(parsedInput.at(i)) << ")" << endl;
    }
    */

    return 0;
}