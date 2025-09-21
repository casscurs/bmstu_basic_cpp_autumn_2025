#ifndef ALGORITHM_H
#define ALGORITHM_H

#include <cassert>
#include <cctype>
#include <cstring>
#include <iostream>
#include <string>

std::string clear_number(const std::string& str);
std::string trim(const std::string& str);
std::string convertTextToSound(std::string text);
bool isEqual(std::string text1, std::string text2);

#endif  // ALGORITHM_H