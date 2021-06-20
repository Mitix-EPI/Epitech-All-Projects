/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD16-alexandre.juan
** File description:
** BF_Translator
*/

#include "BF_Translator.hpp"

BF_Translator::BF_Translator()
{
    this->_map['+'] = "++*ptr;\n";
    this->_map['-'] = "--*ptr;\n";
    this->_map['>'] = "++ptr;\n";
    this->_map['<'] = "--ptr;\n";
    this->_map['.'] = "putchar(*ptr);\n";
    this->_map[','] = "*ptr=getchar();\n";
    this->_map['['] = "while (*ptr) {\n";
    this->_map[']'] = "}\n";
}

BF_Translator::~BF_Translator()
{
}

int BF_Translator::translate(const std::string &in, const std::string &out)
{
    std::ifstream f_in(in);
    std::ofstream f_out(out, std::ofstream::out);

    f_out << "#include <stdio.h>\n";
    f_out << "#include <stdlib.h>\n";
    f_out << "int main() {\n";
    f_out << "char *ptr = calloc(60000, 1);\n";
    char content = f_in.get();
    while (f_in.good()) {
        if (this->_map[content] == "" && !isspace(content))
            return 1;
        f_out << this->_map[content];
        content = f_in.get();
    }
    f_out << "}";
    f_out.close();
    f_in.close();
    return 0;
}
