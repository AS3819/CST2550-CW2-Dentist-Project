#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H

#include <string>

bool isEmpty(const std::string& input);
bool isIntegerString(const std::string& input);
bool getInput(const std::string& prompt, std::string& input);
#endif
