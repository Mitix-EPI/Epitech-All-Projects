/*
** EPITECH PROJECT, 2021
** B-CNA-410-MPL-4-1-groundhog-alexandre.juan
** File description:
** groundhog
*/

#include "../include/groundhog.hpp"

bool isFloat(std::string myString)
{
    std::istringstream iss(myString);
    float f;
    iss >> std::noskipws >> f; // noskipws considers leading whitespace invalid
    // Check the entire string was consumed and if either failbit or badbit is set
    return iss.eof() && !iss.fail();
}

float takeInput(Groundhog groundhog)
{
    std::string str;
    float res;

    std::cin >> str;
    if (str.find("STOP") != std::string::npos) {
        groundhog.calc_weirdest_values();
        if (groundhog.values.size() < groundhog.period) {
            exit(84);
        }
        groundhog.displayEnding();
        exit(0);
    }
    while (!isFloat(str)) {
        if (str == "") {
            exit(84);
        }
        displayError("Not good arg.");
        exit(84);
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cin >> str;
    }
    res = stof(str);
    return res;
}

Groundhog::Groundhog(std::size_t period)
{
    this->period = period;
    this->average = 0;
    this->evolution = 0;
    this->deviation = 0;
    this->isSwitch = false;
    this->countSwitched = 0;
}

void Groundhog::displayEnding(void)
{
    std::cout << "Global tendency switched " << this->countSwitched << " times" << std::endl;
    std:: cout << "5 weirdest values are [";
    std::cout << std::setprecision(1) << std::fixed;
    for (std::vector<std::pair<float, float>>::iterator it = this->weirdest.end() - 1; it != this->weirdest.end() - 6; it--) {
        std::cout << it->second;
        if (it != this->weirdest.end() - 5)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

void Groundhog::calcAverage()
{
    float sum = 0.0;

    for (std::vector<float>::iterator it = (std::end(values) - this->period); it != std::end(values); ++it)
        if ((*it - *(it - 1)) >= 0)
            sum += *it - *(it - 1);

    this->average = roundf((sum / this->period) * 100) / 100;
}

void Groundhog::calcEvolution()
{
    const float startingValue = this->values.at(this->values.size() - 1 - this->period);
    const float endingValue = this->values.back();
    float lastEvolution = this->evolution;

    this->evolution = (((endingValue - startingValue) / abs(startingValue)) * 100);
    this->evolution = roundf(this->evolution);
    if (this->values.size() != this->period + 1) {
        if ((lastEvolution < 0) != (this->evolution < 0))
            this->isSwitch = true;
    }
}

void Groundhog::calcDeviation()
{
    float sum = 0.0;
    float sum4Deviation = 0.0;
    float average4Deviation = 0.0;

    for (std::vector<float>::iterator it = (std::end(values) - this->period); it != std::end(values); ++it)
        sum4Deviation += *it;
    average4Deviation = roundf((sum4Deviation / this->period) * 100) / 100;

    for (std::vector<float>::iterator it = (std::end(values) - this->period); it != std::end(values); ++it)
        sum += pow(*it - average4Deviation, 2);

    this->deviation = roundf(sqrt(sum / this->period) * 100) / 100;
}

bool compareTemp (std::pair<float, float> i, std::pair<float, float> j) { return (i.first < j.first); }

void Groundhog::calc_weirdest_values(void)
{
    for (std::vector<float>::iterator it = this->values.begin() + 1; it != this->values.end() - 1; it++)
        this->weirdest.push_back(std::make_pair(abs(2 * (*it) - (*(it + 1)) - (*(it - 1))), *it));
    std::sort(this->weirdest.begin(), this->weirdest.end(), compareTemp);
}

void Groundhog::handlingValues(void)
{
    // CHECK SI VALUES SIZE > PERIOD
        // -> MOYENNE
    if (this->values.size() > this->period) {
        this->calcAverage();
        this->calcEvolution();
    }
    if (this->values.size() >= this->period) {
        this->calcDeviation();
    }
}

void Groundhog::displayValues(void)
{
    std::cout << std::setprecision(2) << std::fixed;
    // DISPLAY TEMPERATURE INCREASE AVERAGE
    std::cout << "g=";
    if (this->values.size() <= this->period) {
        std::cout << "nan";
    } else {
        std::cout << this->average;
    }

    std::cout << std::setprecision(0) << std::fixed;
    // DISPLAY RELATIVE TEMPERATURE EVOLUTION
    std::cout << "\tr=";
    if (this->values.size() <= this->period) {
        std::cout << "nan%";
    } else {
        float inf = std::numeric_limits<float>::infinity();
        if (this->evolution == inf) {
            if (this->evolution > 0) {
                std::cout << "+Inf" << "%";
            } else {
                std::cout << "-Inf" << "%";
            }
        } else {
            std::cout << this->evolution << "%";
        }
    }

    std::cout << std::setprecision(2) << std::fixed;
    // DISPLAY STANDARD DEVIATION
    std::cout << "\ts=";
    if (this->values.size() < this->period) {
        std::cout << "nan";
    } else {
        std::cout << this->deviation;
    }

    // DISPLAY IF SWITCH OCCURS
    if (this->isSwitch) {
        std::cout << "\ta switch occurs";
        this->isSwitch = false;
        this->countSwitched += 1;
    }
    std::cout << std::endl;
}

void shellGroundhog(int period)
{
    Groundhog groundhog(period);
    float res;
    while (1) {
        res = takeInput(groundhog);
        groundhog.values.push_back(res);
        groundhog.handlingValues();
        groundhog.displayValues();
    }
}
