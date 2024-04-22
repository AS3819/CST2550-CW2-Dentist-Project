#include "Input_Validation.h"
#include "Print_Functions.h"
#include <limits>

bool isEmpty(const std::string& input) {
  if (input == "") {
    return true;
  } else {
    return false;
  }
}

bool getInput(const std::string& prompt, std::string& input) {
    print(prompt);
    if (std::cin.peek() == '\n') {
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    std::getline(std::cin, input);
    if (input == "0") {
        println("Operation cancelled by user.");
        return false;
    }
    return true;
}

bool isIntegerString(const std::string& input) {
  
  bool result = true;
  
  if (input[0] == '-' && input.length() > 1) {
    for (unsigned short int i = 1; i < input.length(); i++) {
      if (!isdigit(input[i])) {
	result = false;
      }
    }
  } else {
    for (unsigned short int i = 0; i < input.length(); i++) {
      if (!isdigit(input[i])) {
	result = false;
      }
    }
  }
  
  return result;
  
}
