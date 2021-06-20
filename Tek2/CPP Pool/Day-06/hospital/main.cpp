#include <iostream>
#include <string>
#include <cstdlib>
#include "SickKoala.hpp"
#include "KoalaNurse.hpp"
#include "KoalaDoctor.hpp"
#include "SickKoalaList.hpp"
#include "KoalaNurseList.hpp"
#include "KoalaDoctorList.hpp"
#include "Hospital.hpp"

// int main(void)
// {
//     SickKoala kevin("Kevin");
//     SickKoala belga("Belga");
//     SickKoala tipiak("Tipiak");
//     SickKoala nau("Nau");
//     SickKoalaList sick1(&kevin);
//     SickKoalaList sick2(&belga);
//     SickKoalaList sick3(nullptr);
//     SickKoalaList sick4(&tipiak);
//     SickKoalaList sick5(&nau);
//     sick1.append(&sick1);
//     sick1.append(&sick2);
//     sick1.append(&sick3);
//     sick1.append(&sick4);
//     sick1.dump();
//     sick4.append(&sick5);
//     sick1.dump();
//     sick1.removeFromName("Salut");
//     sick1.removeFromName("Kevin");
//     sick1.getFromName("Tipiak");
//     sick1.dump();
//     sick1.removeFromName("Nau");
//     sick1.getFromName("Nau");
//     sick1.dump();
// }

int main(void)
{
    srandom(42);
    KoalaDoctor cox("Cox");
    KoalaDoctor house("House");
    KoalaDoctor tired("Boudur-Oulot");
    KoalaDoctorList doc1(&cox);
    KoalaDoctorList doc2(&house);
    KoalaDoctorList doc3(&tired);
    KoalaNurse ratched(1);
    KoalaNurse betty(2);
    KoalaNurseList nurse1(&ratched);
    KoalaNurseList nurse2(&betty);
    SickKoala cancer("Ganepar");
    SickKoala gangrene("Scarface");
    SickKoala measles("RedFace");
    SickKoala smallpox("Varia");
    SickKoala fracture("Falter");
    SickKoalaList sick1(&cancer);
    SickKoalaList sick4(&gangrene);
    SickKoalaList sick3(&measles);
    SickKoalaList sick2(&smallpox);
    SickKoalaList sick5(&fracture);
    {
        Hospital bellevue;
        bellevue.addDoctor(&doc1);
        bellevue.addDoctor(&doc2);
        bellevue.addDoctor(&doc3);
        bellevue.addSick(&sick1);
        bellevue.addSick(&sick2);
        bellevue.addSick(&sick3);
        bellevue.addSick(&sick4);
        bellevue.addSick(&sick5);
        bellevue.addNurse(&nurse1);
        bellevue.addNurse(&nurse2);
        bellevue.addSick(&sick4);
        bellevue.run();
    }
    if (nurse1.isEnd() && sick1.isEnd() && doc1.isEnd())
        std ::cout << "Lists cleaned up." << std ::endl;
    else
        std ::cerr << "You fail ! Boo !" << std ::endl;
    return (0);
}