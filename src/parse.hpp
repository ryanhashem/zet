#ifndef PARSE_HPP
#define PARSE_HPP

#include <string>
#include <vector>
#include <tuple>

using std::string, std::vector, std::tuple;

vector<tuple<string, string>> parse(int argc, char* argv[]);

bool validFlags(int argc, char* argv[]);

bool validLinkFlags(int argc, char* argv[]);

bool validViewFlags(int argc, char* argv[]);


#endif