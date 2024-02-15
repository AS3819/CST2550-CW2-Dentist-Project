#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
 private:
  std::string title;
  std::string firstName;
  std::string surname;
  std::string address;
  std::string email;
 Public:
  void setTitle(std::string t);
  void setFirstName(std::string fn);
  void setSurname(std::string sn);
  void setAddress(std::string a);
  void setEmail(std::string e);
  std::string getTitle();
  std::string getFirstName();
  std::string getSurname();
  std::string getAddress();
  std::string getEmail();
};

#endif
