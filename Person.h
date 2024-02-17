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

public:
    Person(const std::string& title, const std::string& firstName, const std::string& surname, const std::string& address, const std::string& email)
        : title(title), firstName(firstName), surname(surname), address(address), email(email) {}

    void setTitle(const std::string& t);
    void setFirstName(const std::string& fn);
    void setSurname(const std::string& sn);
    void setAddress(const std::string& a);
    void setEmail(const std::string& e);

    std::string getTitle() const;
    std::string getFirstName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getEmail() const;
};

#endif // PERSON_H
