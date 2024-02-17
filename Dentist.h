#ifndef DENTIST_H
#define DENTIST_H

#include "Person.h"

class Dentist : public Person {
private:
    int dentistID;
    int salary;

public:
    Dentist(const std::string& title, const std::string& firstName, const std::string& surname, const std::string& address, const std::string& email, int dentistID, int salary)
            : Person(title, firstName, surname, address, email), dentistID(dentistID), salary(salary) {}
            
    void setDentistID(int ID);
    void setSalary(int s);
    int getDentistID() const;
    int getSalary() const;
};

#endif
