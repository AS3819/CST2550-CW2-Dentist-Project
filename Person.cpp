#include "Person.h"

void setTitle(std::string t) {
  title = t;
}

void setFirstName(std::string fn) {
  firstName = fn;
}

void setSurname(std::string sn) {
  surname = sn;
}

void setAddress(std::string a) {
  address = a;
}

void setEmail(std::string e) {
  email = e;
}

std::string getTitle() {
  return title;
}

std::string getFirstName() {
  return firstName;
}

std::string getSurname() {
  return surname;
}

std::string getAddress() {
  return address;
}

std::string getEmail() {
  return email;
}
