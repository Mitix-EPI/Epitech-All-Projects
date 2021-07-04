/*
** EPITECH PROJECT, 2021
** B-CNA-410-MPL-4-1-groundhog-alexandre.juan
** File description:
** groundhog
*/

#ifndef GROUNDHOG_HPP_
#define GROUNDHOG_HPP_

#include <string>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <algorithm>
#include <limits>
#include <vector>
#include <sstream>
#include <iomanip>
#include <map>

class Groundhog {
    public:
        Groundhog(std::size_t period);
        ~Groundhog() {};

        void displayValues(void);
        void handlingValues(void);
        void calcAverage(void);
        void calcEvolution(void);
        void calcDeviation(void);
        void calc_weirdest_values(void);
        void displayEnding(void);

        std::vector<float> values;
        std::vector<std::pair<float, float>> weirdest;
        float average;
        float evolution;
        float deviation;
        std::size_t period;
        bool isSwitch;
        int countSwitched;
};

void displayError(std::string errorMessage);
void shellGroundhog(int);

#endif /* !GROUNDHOG_HPP_ */
