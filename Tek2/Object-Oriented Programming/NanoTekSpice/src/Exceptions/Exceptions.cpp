/*
** EPITECH PROJECT, 2021
** nanoTekSpice
** File description:
** Exceptions
*/

#include "Exceptions.hpp"

NanoTekSpiceError::NanoTekSpiceError(std::string const &message, int code, std::string const &context)
{
    this->_message = message;
    this->_code = code;
    this->_context = context;
}

const char *NanoTekSpiceError::what(void) const noexcept
{
    return (this->_message.data());
}

int NanoTekSpiceError::getCode(void) const noexcept
{
    return (this->_code);
}

std::string NanoTekSpiceError::getContext(void) const noexcept
{
    return (this->_context);
}

InvalidFilepath::InvalidFilepath(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

EmptyContent::EmptyContent(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

NoChipsets::NoChipsets(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

UndefinedContentType::UndefinedContentType(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

UnknownFileExtension::UnknownFileExtension(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidChipset::InvalidChipset(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidComponent::InvalidComponent(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidName::InvalidName(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidLink::InvalidLink(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidPin::InvalidPin(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

InvalidValue::InvalidValue(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

VSSSet::VSSSet(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

VDDSet::VDDSet(std::string const &message, int code, std::string const &context):
NanoTekSpiceError(message, code, context)
{
}

void readException(NanoTekSpiceError e)
{
    std::cout << e.what() << std::endl;
    if (!e.getContext().empty()) {
        std::cout << "at " << e.getContext() << std::endl;
    }
    std::cout << std::endl << "Error code: " << e.getCode() << std::endl;
}