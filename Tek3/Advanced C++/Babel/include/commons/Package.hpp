/*
** EPITECH PROJECT, 2021
** B-CPP-500-MPL-5-1-babel-gabriel.knies
** File description:
** Message
*/

#ifndef MESSAGE_HPP_
#define MESSAGE_HPP_

#include "common.h"
#include "exceptions.hpp"

struct package_header
{
    MsgTypes id{};
    std::size_t size = 0;
};

struct package
{
    package_header header{};
    std::vector<char> body;

    std::size_t size() const
    {
        return sizeof(*this) + body.size();
    }
    friend std::ostream &operator<<(std::ostream &os, const package &msg)
    {
        os << "ID:" << int(msg.header.id) << "Size:" << msg.header.size;
        return os;
    }
    template <typename DType>
    friend package &operator<<(package &msg, const DType &data)
    {
        if (!std::is_standard_layout<DType>::value)
            throw Errors("Data too complex to be pushed");
        std::size_t i = msg.body.size();
        msg.body.resize(msg.body.size() + sizeof(DType));
        std::memcpy(msg.body.data() + i, &data, sizeof(DType));
        msg.header.size = msg.body.size();
        return msg;
    }
    template <typename DType>
    friend package &operator>>(package &msg, DType &data)
    {
        if (!std::is_standard_layout<DType>::value)
            throw Errors("Data too complex to be extracted");
        std::size_t i = msg.body.size() - sizeof(DType);
        std::memcpy(&data, msg.body.data(), sizeof(DType));
        msg.body.resize(i);
        msg.header.size = msg.body.size();
        return msg;
    }
};

#endif /* !MESSAGE_HPP_ */
