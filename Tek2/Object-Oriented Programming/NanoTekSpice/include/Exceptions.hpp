/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Exceptions
*/

#ifndef EXCEPTIONS_HPP_
#define EXCEPTIONS_HPP_

#include <string>
#include <iostream>

class NanoTekSpiceError : public std::exception {
    public:
        NanoTekSpiceError(std::string const &message, int code, std::string const &context = "");
        const char *what() const noexcept;
        int getCode() const noexcept;
        std::string getContext() const noexcept;

    private:
        std::string _message;
        int _code;
        std::string _context;
};

class InvalidFilepath : public NanoTekSpiceError {
    public:
        InvalidFilepath(std::string const &message, int code, std::string const &context = "");
};

class EmptyContent : public NanoTekSpiceError {
    public:
        EmptyContent(std::string const &message, int code, std::string const &context = "");
};

class NoChipsets : public NanoTekSpiceError {
    public:
        NoChipsets(std::string const &message, int code, std::string const &context = "");
};

class UndefinedContentType : public NanoTekSpiceError {
    public:
        UndefinedContentType(std::string const &message, int code, std::string const &context = "");
};

class UnknownFileExtension : public NanoTekSpiceError {
    public:
        UnknownFileExtension(std::string const &message, int code, std::string const &context = "");
};

class InvalidChipset : public NanoTekSpiceError {
    public:
        InvalidChipset(std::string const &message, int code, std::string const &context = "");
};

class InvalidComponent : public NanoTekSpiceError {
    public:
        InvalidComponent(std::string const &message, int code, std::string const &context = "");
};

class InvalidName : public NanoTekSpiceError {
    public:
        InvalidName(std::string const &message, int code, std::string const &context = "");
};

class InvalidLink : public NanoTekSpiceError {
    public:
        InvalidLink(std::string const &message, int code, std::string const &context = "");
};

class InvalidPin : public NanoTekSpiceError {
    public:
        InvalidPin(std::string const &message, int code, std::string const &context = "");
};

class InvalidValue : public NanoTekSpiceError {
    public:
        InvalidValue(std::string const &message, int code, std::string const &context = "");
};

class VDDSet : public NanoTekSpiceError {
    public:
        VDDSet(std::string const &message, int code, std::string const &context = "");
};

class VSSSet : public NanoTekSpiceError {
    public:
        VSSSet(std::string const &message, int code, std::string const &context = "");
};

void readException(NanoTekSpiceError e);

#endif /* !EXCEPTIONS_HPP_ */
