#include "InvalidFieldException.hpp"

InvalidFieldException::InvalidFieldException(const std::string& entityName, const std::string& fieldName)
    : std::invalid_argument("invalid field: " + entityName + "." + fieldName)
    ,_entityName(entityName)
    , _fieldName(fieldName)
{}

const std::string& InvalidFieldException::entityName() const
{
    return _entityName;
}

const std::string& InvalidFieldException::fieldName() const
{
    return _fieldName;
}
