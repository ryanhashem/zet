#include <iostream>
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
    parsedInput = parse(argc, argv);

    //test
    for (int i = 0; i < parsedInput.size(); i++) {
        cout << "(" << std::get<0>(parsedInput.at(i)) << ", " << std::get<1>(parsedInput.at(i)) << ")" << endl;
    }

    return 0;
}