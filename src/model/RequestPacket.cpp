#include "model/RequestPacket.hpp"
#include <model/InvalidFieldException.hpp>

#include <QJsonValue>
#include <QJsonArray>

static const QString entity_name = "RequestPacket";
static const QString server_config_field = "serverConfig";
static const QString request_parameters_field = "requestParameters";
static const QString protocol_version_field = "protocolVersion";
static const QString request_type_field = "requestType";
static const QString initial_fetches_field = "initialFetches";
static const QString request_field = "request";
static const QString response_field = "response";

RequestPacket::RequestPacket(const QJsonObject &object)
    : _serverConfig(object[server_config_field])
    , _requestParameters(object[request_parameters_field])
{
    QJsonValue protocolVersion = object[protocol_version_field];
    if (!protocolVersion.isDouble())
        throw InvalidFieldException(entity_name, protocol_version_field);
    _protocolVersion = protocolVersion.toDouble();

    QJsonValue requestType = object[request_type_field];
    if (!requestType.isString())
        throw InvalidFieldException(entity_name, request_type_field);
    _requestType = requestType.toString();

    QJsonValue initialFetches = object[initial_fetches_field];
    if (!initialFetches.isUndefined()) // optional field
    {
        if (!initialFetches.isArray())
            throw InvalidFieldException(entity_name, initial_fetches_field);
        int fetchNumber=0;
        for (auto f : initialFetches.toArray())
        {
            QString entityName = QString("%s.%s[%d]").arg(entity_name).arg(initial_fetches_field).arg(fetchNumber);
            if (!f.isObject())
                throw InvalidFieldException(entityName, "");
            auto fo = f.toObject();
            QJsonValue request = fo[request_field];
            if (!request.isObject())
                throw InvalidFieldException(entityName, request_field);
            QJsonValue response = fo[response_field];
            if (!response.isObject())
                throw InvalidFieldException(entityName, response_field);
            _initialFetches.push_back(QPair<FetchRequest, FetchResponse>(FetchRequest(request.toObject()), FetchResponse(response.toObject())));
            ++fetchNumber;
        }
    }
}

QJsonObject RequestPacket::toJsonObject() const
{
    QJsonObject result;
    result[protocol_version_field] = QJsonValue(double(_protocolVersion));
    result[server_config_field] = _serverConfig.toJsonValue();
    result[request_type_field] = QJsonValue(_requestType);
    result[request_parameters_field] = _requestParameters;
    QJsonArray initialFetches;
    for (auto f : _initialFetches)
    {
        QJsonObject fo;
        fo[request_field] = f.first.toJsonObject();
        fo[response_field] = f.second.toJsonObject();
        initialFetches.push_back(fo);
    }
    result[initial_fetches_field] = initialFetches;
    return result;
}

int RequestPacket::protocolVersion() const
{
    return _protocolVersion;
}

const ServerConfig& RequestPacket::serverConfig() const
{
    return _serverConfig;
}

const QString& RequestPacket::requestType() const
{
    return _requestType;
}

const QJsonValue& RequestPacket::requestParameters() const
{
    return _requestParameters;
}

const QList<QPair<FetchRequest, FetchResponse>>& RequestPacket::initialFetches() const
{
    return _initialFetches;
}
