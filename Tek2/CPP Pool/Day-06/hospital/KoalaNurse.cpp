/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaNurse
*/

#include "KoalaNurse.hpp"

KoalaNurse::KoalaNurse(int id) : id(id), workTime(0)
{
}

KoalaNurse::~KoalaNurse()
{
    std::cout << "Nurse " << id << ": Finally some rest!" << std::endl;
}

void KoalaNurse::giveDrug(std::string drug, SickKoala *patient)
{
    patient->takeDrug(drug);
}

std::string KoalaNurse::readReport(std::string filename)
{
    std::ifstream file(filename, std::ios::in);
    std::string res;
    std::string koalaName;
    std::size_t pos;

    if (!file)
        return res;
    pos = filename.find(".report");
    if ((pos != std::string::npos) && pos == filename.length() - 7)
        koalaName = filename.substr(0, filename.find("."));
    else
        return res;
    if (!std::getline(file, res))
        return res;
    std::cout << "Nurse " << id << ": Kreog! Mr." << koalaName << " needs a " << res << "!" << std::endl;
    file.close();
    return res;
}

void KoalaNurse::timeCheck(void)
{
    if (workTime) {
        workTime = 0;
        std::cout << "Nurse " << id << ": Time to go home to my eucalyptus forest!" << std::endl;
    } else {
        workTime = 1;
        std::cout << "Nurse " << id << ": Time to get to work!" << std::endl;
    }
}

int KoalaNurse::getID(void)
{
    return id;
}
