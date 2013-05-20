#pragma once

#include "model/FetchRequest.hpp"
#include "model/FetchResponse.hpp"
#include "model/ServerConfig.hpp"

#include <QJsonValue>
#include <QJsonObject>
#include <QList>
#include <QPair>

class RequestPacket
{
public:
    RequestPacket(const QJsonObject &object);

    int protocolVersion() const;
    const ServerConfig & serverConfig() const;
    const QString& requestType() const;
    const QJsonValue& requestParameters() const;
    const QList<QPair<FetchRequest, FetchResponse>>& initialFetches() const;

    QJsonObject toJsonObject() const;

private:
    int _protocolVersion;
    ServerConfig _serverConfig;
    QString _requestType;
    QJsonValue _requestParameters;
    QList<QPair<FetchRequest, FetchResponse>> _initialFetches;

};
