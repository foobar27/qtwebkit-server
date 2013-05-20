#include "model/ServerConfig.hpp"
#include <model/InvalidFieldException.hpp>

#include <QJsonValue>
#include <QJsonObject>

#include <stdexcept>

#define ENTITY_NAME "ServerConfig"
#define FIELD_NETWORK_TYPE "networkType"

ServerConfig::NetworkType deserializeNetworkType(const QString& name)
{
    if (name == "disabled") return ServerConfig::NetworkType::disabled;
    if (name == "tunneled") return ServerConfig::NetworkType::tunneled;
    if (name == "enabled") return ServerConfig::NetworkType::enabled;
    throw InvalidFieldException(ENTITY_NAME, FIELD_NETWORK_TYPE);
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
            throw new InvalidFieldException(ENTITY_NAME, "");
        QJsonObject o = value.toObject();
        QJsonValue networkType = o[FIELD_NETWORK_TYPE];
        if (networkType.isString())
            _networkType = deserializeNetworkType(networkType.toString());
        else
            throw InvalidFieldException(ENTITY_NAME, FIELD_NETWORK_TYPE);
    }
}

QJsonValue ServerConfig::toJsonValue() const
{
    QJsonObject result;
    result[FIELD_NETWORK_TYPE] = QJsonValue(serializeNetworkType(_networkType));
    return result;
}

ServerConfig::NetworkType ServerConfig::networkType() const
{
    return _networkType;
}
