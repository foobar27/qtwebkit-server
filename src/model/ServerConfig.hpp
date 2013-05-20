#pragma once

#include <QJsonValue>

class ServerConfig
{
public:
    enum class NetworkType { disabled, tunneled, enabled };
private:
    NetworkType _networkType;
public:
    ServerConfig(const QJsonValue& value);
    QJsonValue toJsonValue() const;

    NetworkType networkType() const;
};
