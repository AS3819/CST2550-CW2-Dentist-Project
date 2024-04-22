#ifndef DENTIST_MANAGER_H
#define DENTIST_MANAGER_H

#include "Dentist.h"
#include "Input_Validation.h"
#include "Data.h"
#include <vector>
#include <string>

class DentistManager {
    std::vector<Dentist*> dentists;
private:
    Data* data;
public:
    DentistManager(Data* data) : data(data) {}
    Dentist* findOrCreateDentist(const std::string& name);
    ~DentistManager();
    void addNewDentist();
    void saveDentistsToCSV();
};

#endif
