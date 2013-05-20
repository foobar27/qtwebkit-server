#pragma once

#include <string>
#include <stdexcept>

#include <QString>

class InvalidFieldException : public std::invalid_argument {
public:
    explicit InvalidFieldException(const std::string& entityName, const std::string& fieldName);
    explicit InvalidFieldException(const QString& entityName, const QString& fieldName);

    const std::string& entityName() const;
    const std::string& fieldName() const;
private:
    std::string _entityName, _fieldName;

};
