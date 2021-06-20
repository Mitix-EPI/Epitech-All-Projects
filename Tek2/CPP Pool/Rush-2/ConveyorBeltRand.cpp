/*
** EPITECH PROJECT, 2021
** Visual Studio Live Share (Workspace)
** File description:
** ConveyorBeltRand
*/

#include "ConveyorBeltRand.hpp"

ConveyorBeltRand::ConveyorBeltRand()
{
    this->_object = nullptr;
    this->_box = true;
    std::ofstream outfile("gifts.xml");
    outfile << "<?xml version=\"1.0\"?>" << std::endl;
    outfile << "<gift class_id=\"0\" tracking_level=\"0\" version=\"1\">" << std::endl;
    outfile.close();
}

ConveyorBeltRand::~ConveyorBeltRand()
{
    if (this->_object != nullptr)
        delete this->_object;
    std::ofstream outfile("gifts.xml", std::ios_base::app);
    outfile << "</gift>" << std::endl;
    outfile.close();
}

void recursiveDtor(Object *obj)
{
    if (obj != nullptr && obj->getObject() != nullptr)
        recursiveDtor(obj->getObject());
    if (obj != nullptr)
        delete obj;
}

void ConveyorBeltRand::out()
{
    std::cout << "e speex'n'XML" << std::endl;
    if (this->getObject() == nullptr) {
        raise("Error: You can't give a null Object to Santa !!");
        return;
    }
    std::string type = this->_object->getObject()->getObject()->getType();
    this->fillXml(type);
    recursiveDtor(this->_object);
    this->_object = nullptr;
}

void ConveyorBeltRand::fillXml(std::string name) const
{
    static int i = 0;
    std::ofstream outfile("gifts.xml", std::ios_base::app);

    if (i == 0) {
        outfile << "\t<item class_id=\"1\" tracking_level=\"0\" version=\"1\">";
    } else {
        outfile << "\t<item>";
    }
    outfile << std::endl;
    i++;
    outfile << "\t\t<gifts.name>" << name << "</gifts.name>" << std::endl;
    outfile << "\t</item>" << std::endl;
    outfile.close();
}
