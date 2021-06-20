/*
** EPITECH PROJECT, 2021
** B-CPP-300-MPL-3-1-CPPD13-clement.bolin
** File description:
** test_picture
*/

#include <ostream>
#include <iostream>
#include <criterion/criterion.h>
#include "Picture.hpp"

class OSRedirector {
    private:
        std::ostringstream _oss;
        std::streambuf *_backup;
        std::ostream &_c;

    public:
        OSRedirector(std::ostream &c) : _c(c) {
            _backup = _c.rdbuf();
            _c.rdbuf(_oss.rdbuf());
        }

        ~OSRedirector() {
            _c.rdbuf(_backup);
        }

        const std::string getContent() {
            _oss << std::flush;
            return _oss.str();
        }
};

Test(test_picture, test_picture_construct) {
    Picture obj("./tests/file.txt");

    cr_assert_eq(obj.data, "hello world");
}

Test(test_picture, test_picture_getFromFile) {
    Picture obj("./tests/file.txt");

    std::cout << "TEST" << obj.data << std::endl;
    cr_assert_eq(obj.getPictureFromFile("./tests/file.txt"), true);
    cr_assert_eq(obj.data, "hello world");
}

Test(test_picture, test_picture_getFromFile_failed) {
    Picture obj("file.txt");

    cr_assert_eq(obj.getPictureFromFile("file.tx"), false);
    cr_assert_eq(obj.data, "ERROR");
}