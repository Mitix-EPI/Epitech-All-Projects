/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** Parser
*/

#include "Parser.hpp"

int recursiveFactor();
int recursiveSum();
int recursiveProduct();

static char const *x;

Parser::Parser()
{
    this->_res = 0;
}

Parser::~Parser()
{
}

int my_atoi(void)
{
    int nbr = 0;

    while (*x >= '0' && *x <= '9') {
        nbr = nbr * 10 + (*x - '0');
        x++;
    }
    return (nbr);
}

int recursiveSum()
{
    int choice = 0;
    int pro2 = 0;
    int pro1 = recursiveProduct();

    while (*x == '+' || *x == '-') {
        if (*x == '-')
            choice = 1;
        ++x;
        pro2 = recursiveProduct();
        if (choice == 0)
            pro1 += pro2;
        if (choice == 1)
            pro1 -= pro2;
    }
    return pro1;
}

int recursiveProduct()
{
    int choice = 0;
    int fac1 = recursiveFactor();
    int fac2 = 0;

    while(*x == '*' || *x == '/' || *x == '%') {
        if (*x == '/')
            choice = 1;
        if (*x == '%')
            choice = 2;
        ++x;
        fac2 = recursiveFactor();
        if (choice == 0)
            fac1 *= fac2;
        if (choice == 1)
            fac1 /= fac2;
        if (choice == 2)
            fac1 %= fac2;
    }
    return fac1;
}

int recursiveFactor()
{
    int nb = 0;
    int sum = 0;
    int signe = 1;

    if ((*x >= '0' && *x <= '9') || *x == '-') {
        if (*x == '-') {
            signe = -1;
            ++x;
        }
        nb = signe * my_atoi();
        return nb;
    } else if (*x == '(') {
        ++x;
        sum = recursiveSum();
        ++x;
        return (sum);
    }
    return sum;
}

std::string removeSpaces(std::string word) {
    std::string newWord;
    for (size_t i = 0; i < word.size(); i++) {
        if (word[i] != ' ') {
            newWord += word[i];
        }
    }

    return newWord;
}

int recursiveEvalExpr(std::string str)
{
    str = removeSpaces(str);
    if (str[0] == '(' && str[str.length() - 1] == ')') {
        str.pop_back();
        str.erase(str.begin());
    }
    x = const_cast<char *>(str.c_str());
    return recursiveSum();
}

void Parser::feed(const std::string &str)
{
    this->_res += recursiveEvalExpr(str);
}
