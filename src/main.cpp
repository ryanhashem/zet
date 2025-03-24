#include <iostream>
#include "new.hpp"

using std::cout, std::endl;

//allows CLI inputs
//argc stores the number of parameters, argv is an array of c-strings
int main(int argc, char* argv[]) {

    //prints out number of CLI arguments inputted (including the executable)
    cout << "number of arguments: " << argc << endl;

    //prints out each argument
    for (int i = 0; i < argc; i++) {
        cout << "argument " << (i + 1) << ": " << argv[i] << endl; 
    }

    return 0;
}