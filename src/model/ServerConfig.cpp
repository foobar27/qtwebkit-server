#include "model/ServerConfig.hpp"
#include <model/InvalidFieldException.hpp>

#include <QJsonValue>
#include <QJsonObject>

#include <stdexcept>

static const QString entity_name = "ServerConfig";
static const QString network_type_field = "network_type";

ServerConfig::NetworkType deserializeNetworkType(const QString& name)
{
    if (name == "disabled") return ServerConfig::NetworkType::disabled;
    if (name == "tunneled") return ServerConfig::NetworkType::tunneled;
    if (name == "enabled") return ServerConfig::NetworkType::enabled;
    throw InvalidFieldException(entity_name, network_type_field);
}

QString serializeNetworkType(ServerConfig::NetworkType networkType)
{
    switch (networkType) {
    case ServerConfig::NetworkType::disabled:
        return "disabled";
        break;
    case ServerConfig::NetworkType::tunneled:
        return "tunneled";
    case ServerConfig::NetworkType::enabled:
        return "enabled";
    default:
        throw std::invalid_argument("the serializer doesn't know aboud this field!");
        break;
    }
}

ServerConfig::ServerConfig(const QJsonValue& value)
    : _networkType(ServerConfig::NetworkType::disabled)
{
    if (!value.isUndefined()) // else: take default values
    {
        if (!value.isObject())
            throw new InvalidFieldException(entity_name, "");
        QJsonObject o = value.toObject();
        QJsonValue networkType = o[network_type_field];
        if (networkType.isString())
            _networkType = deserializeNetworkType(networkType.toString());
        else
            throw InvalidFieldException(entity_name, network_type_field);
    }
}

QJsonValue ServerConfig::toJsonValue() const
{
    QJsonObject result;
    result[network_type_field] = QJsonValue(serializeNetworkType(_networkType));
    return result;
}

ServerConfig::NetworkType ServerConfig::networkType() const
{
    return _networkType;
}
