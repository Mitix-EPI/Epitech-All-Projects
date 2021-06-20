/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD06-alexandre.juan
** File description:
** KoalaDoctor
*/

#include "KoalaDoctor.hpp"

KoalaDoctor::KoalaDoctor(std::string name) : name(name), workTime(0)
{
    std::cout << "Dr." << name << ": I'm Dr." << name << "! How do you kreog?" << std::endl;
}

KoalaDoctor::~KoalaDoctor()
{
}

void KoalaDoctor::diagnose(SickKoala *patient)
{
    std::ofstream file;
    std::cout << "Dr." << name << ": So what's goerking you Mr." << patient->getName() << "?" << std::endl;
    patient->poke();
    file.open(patient->getName() + ".report");
    int rand = random() % 5;
    if (rand == 0)
        file << "Mars" << std::endl;
    if (rand == 1)
        file << "Kinder" << std::endl;
    if (rand == 2)
        file << "Crunch" << std::endl;
    if (rand == 3)
        file << "Maroilles" << std::endl;
    if (rand == 4)
        file << "Eucalyptus leaf" << std::endl;
    file.close();
}

void KoalaDoctor::timeCheck(void)
{
    if (workTime) {
        workTime = 0;
        std::cout << "Dr." << name << ": Time to go home to my eucalyptus forest!" << std::endl;
    } else {
        workTime = 1;
        std::cout << "Dr." << name << ": Time to get to work!" << std::endl;
    }
}

std::string KoalaDoctor::getName(void)
{
    return name;
}
