/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-alexandre.juan
** File description:
** Toy
*/

#ifndef TOY_HPP_
#define TOY_HPP_

#include "Picture.hpp"

class Toy {
    public:
        class Error {
            public:
                Error() : type(UNKNOWN), _what(""), _where("") {}
                enum ErrorType {
                    UNKNOWN,
                    PICTURE,
                    SPEAK
                };

                std::string what(void) const { return this->_what; }
                std::string where(void) const { return this->_where; }

                void setWhat(std::string what) { this->_what = what; }
                void setWhere(std::string where) { this->_where = where; }
                void setType(const ErrorType &type) { this->type = type; }

                ErrorType type;
                std::string _what;
                std::string _where;
        };

    public:
        enum ToyType {
            ALIEN,
            BASIC_TOY,
            BUZZ,
            WOODY
        };

        Toy();
        Toy(const ToyType &toyType, const std::string name, const std::string filename);
        Toy(const Toy &oldToy);
        ~Toy();

        Toy &operator=(const Toy &oldToy);
        Error getLastError(void) { return this->error; }

        ToyType getType(void) const { return this->type; }
        std::string getName(void) const { return this->name; }
        std::string getAscii(void) const { return this->picture->data; }
        Picture *getPicture(void) const { return this->picture; }

        void setName(const std::string &name) { this->name = name; }
        bool setAscii(const std::string &filename);
        void setData(const std::string &str) { this->picture->data = str; }

        virtual bool speak(const std::string statement);
        virtual bool speak_es(const std::string statement);


    protected:
        Picture *picture;
        ToyType type;
        std::string name;
        Error error;
    private:
};

std::ostream &operator<<(std::ostream &s, const Toy &toy);
Toy &operator<<(Toy &toy, const std::string &str);

#endif /* !TOY_HPP_ */
