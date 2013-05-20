#include "model/RequestPacket.hpp"
#include <model/InvalidFieldException.hpp>

#include <QJsonValue>
#include <QJsonArray>
#include <sstream>

#define ENTITY_NAME "RequestPacket"
#define FIELD_SERVER_CONFIG "serverConfig"
#define FIELD_REQUEST_PARAMETERS "requestParameters"
#define FIELD_PROTOCOL_VERSION "protocolVersion"
#define FIELD_REQUEST_TYPE "requestType"
#define FIELD_INITIAL_FETCHES "initialFetches"
#define FIELD_REQUEST "request"
#define FIELD_RESPONSE "response"

RequestPacket::RequestPacket(const QJsonObject &object)
    : _serverConfig(object[FIELD_SERVER_CONFIG])
    , _requestParameters(object[FIELD_REQUEST_PARAMETERS])
{
    QJsonValue protocolVersion = object[FIELD_PROTOCOL_VERSION];
    if (!protocolVersion.isDouble())
        throw InvalidFieldException(ENTITY_NAME, FIELD_PROTOCOL_VERSION);
    _protocolVersion = protocolVersion.toDouble();

    QJsonValue requestType = object[FIELD_REQUEST_TYPE];
    if (!requestType.isString())
        throw InvalidFieldException(ENTITY_NAME, FIELD_REQUEST_TYPE);
    _requestType = requestType.toString();

    QJsonValue initialFetches = object[FIELD_INITIAL_FETCHES];
    if (!initialFetches.isUndefined()) // optional field
    {
        if (!initialFetches.isArray())
            throw InvalidFieldException(ENTITY_NAME, FIELD_INITIAL_FETCHES);
        int fetchNumber=0;
        for (auto f : initialFetches.toArray())
        {
            std::ostringstream os;
            os << ENTITY_NAME << "." << FIELD_INITIAL_FETCHES << "[" << fetchNumber << "]";
            std::string entityName = os.str();
            if (!f.isObject())
                throw InvalidFieldException(entityName, "");
            auto fo = f.toObject();
            QJsonValue request = fo[FIELD_REQUEST];
            if (!request.isObject())
                throw InvalidFieldException(entityName, FIELD_REQUEST);
            QJsonValue response = fo[FIELD_RESPONSE];
            if (!response.isObject())
                throw InvalidFieldException(entityName, FIELD_RESPONSE);
            _initialFetches.push_back(QPair<FetchRequest, FetchResponse>(FetchRequest(request.toObject()), FetchResponse(response.toObject())));
            ++fetchNumber;
        }
    }
}

QJsonObject RequestPacket::toJsonObject() const
{
    QJsonObject result;
    result[FIELD_PROTOCOL_VERSION] = QJsonValue(double(_protocolVersion));
    result[FIELD_SERVER_CONFIG] = _serverConfig.toJsonValue();
    result[FIELD_REQUEST_TYPE] = QJsonValue(_requestType);
    result[FIELD_REQUEST_PARAMETERS] = _requestParameters;
    QJsonArray initialFetches;
    for (auto f : _initialFetches)
    {
        QJsonObject fo;
        fo[FIELD_REQUEST] = f.first.toJsonObject();
        fo[FIELD_RESPONSE] = f.second.toJsonObject();
        initialFetches.push_back(fo);
    }
    result[FIELD_INITIAL_FETCHES] = initialFetches;
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
