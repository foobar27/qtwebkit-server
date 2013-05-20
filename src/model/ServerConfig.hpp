#pragma once

#include <QJsonValue>

class ServerConfig
{
public:
    enum class NetworkType { disabled, tunneled, enabled };
public:
    ServerConfig(const QJsonValue& value);
    QJsonValue toJsonValue() const;

    NetworkType networkType() const;
private:
    NetworkType _networkType;
};
