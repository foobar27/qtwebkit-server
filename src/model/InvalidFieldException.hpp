#pragma once

#include <string>
#include <stdexcept>

class InvalidFieldException : public std::invalid_argument {
private:
    std::string _entityName, _fieldName;
public:
    explicit InvalidFieldException(const std::string& entityName, const std::string& fieldName);

    const std::string& entityName() const;
    const std::string& fieldName() const;

};
