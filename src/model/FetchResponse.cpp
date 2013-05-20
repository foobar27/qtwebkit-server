#include "model/FetchResponse.hpp"
#include <model/InvalidFieldException.hpp>

#include <QNetworkReply>

static const QString unknown_error_prefix = "unknown error: ";
static const QString entity_name = "FetchResponse";
static const QString network_error_field = "network_error";

QString serializeNetworkError(QNetworkReply::NetworkError error)
{
    switch (error) {
    case QNetworkReply::NetworkError::ConnectionRefusedError:
        return "ConnectionRefusedError";
    case QNetworkReply::NetworkError::RemoteHostClosedError:
        return "RemoteHostClosedError";
    case QNetworkReply::NetworkError::HostNotFoundError:
        return "HostNotFoundError";
    case QNetworkReply::NetworkError::TimeoutError:
        return "TimeoutError";
    case QNetworkReply::NetworkError::OperationCanceledError:
        return "OperationCanceledError";
    case QNetworkReply::NetworkError::SslHandshakeFailedError:
        return "SslHandshakeFailedError";
    case QNetworkReply::NetworkError::TemporaryNetworkFailureError:
        return "TemporaryNetworkFailureError";
    case QNetworkReply::NetworkError::NetworkSessionFailedError:
        return "NetworkSessionFailedError";
    case QNetworkReply::NetworkError::BackgroundRequestNotAllowedError:
        return "BackgroundRequestNotAllowedError";
    case QNetworkReply::NetworkError::ProxyConnectionRefusedError:
        return "ProxyConnectionRefusedError";
    case QNetworkReply::NetworkError::ProxyConnectionClosedError:
        return "ProxyConnectionClosedError";
    case QNetworkReply::NetworkError::ProxyNotFoundError:
        return "ProxyNotFoundError";
    case QNetworkReply::NetworkError::ProxyTimeoutError:
        return "ProxyTimeoutError";
    case QNetworkReply::NetworkError::ProxyAuthenticationRequiredError:
        return "ProxyAuthenticationRequiredError";
    case QNetworkReply::NetworkError::ContentAccessDenied:
        return "ContentAccessDenied";
    case QNetworkReply::NetworkError::ContentOperationNotPermittedError:
        return "ContentOperationNotPermittedError";
    case QNetworkReply::NetworkError::ContentNotFoundError:
        return "ContentNotFoundError";
    case QNetworkReply::NetworkError::AuthenticationRequiredError:
        return "AuthenticationRequiredError";
    case QNetworkReply::NetworkError::ContentReSendError:
        return "ContentReSendError";
    case QNetworkReply::NetworkError::ProtocolUnknownError:
        return "ProtocolUnknownError";
    case QNetworkReply::NetworkError::ProtocolInvalidOperationError:
        return "ProtocolInvalidOperationError";
    case QNetworkReply::NetworkError::UnknownNetworkError:
        return "UnknownNetworkError";
    case QNetworkReply::NetworkError::UnknownProxyError:
        return "UnknownProxyError";
    case QNetworkReply::NetworkError::UnknownContentError:
        return "UnknownContentError";
    case QNetworkReply::NetworkError::ProtocolFailure:
        return "ProtocolFailure";
    default:
        return QString("%s%d").arg(unknown_error_prefix).arg(error);
    }
}

QNetworkReply::NetworkError deserializeNetworkError(const QString& s)
{
    if (s == "ConnectionRefusedError") return QNetworkReply::NetworkError::ConnectionRefusedError;
    if (s == "RemoteHostClosedError") return QNetworkReply::NetworkError::RemoteHostClosedError;
    if (s == "HostNotFoundError") return QNetworkReply::NetworkError::HostNotFoundError;
    if (s == "TimeoutError") return QNetworkReply::NetworkError::TimeoutError;
    if (s == "OperationCanceledError") return QNetworkReply::NetworkError::OperationCanceledError;
    if (s == "SslHandshakeFailedError") return QNetworkReply::NetworkError::SslHandshakeFailedError;
    if (s == "TemporaryNetworkFailureError") return QNetworkReply::NetworkError::TemporaryNetworkFailureError;
    if (s == "NetworkSessionFailedError") return QNetworkReply::NetworkError::NetworkSessionFailedError;
    if (s == "BackgroundRequestNotAllowedError") return QNetworkReply::NetworkError::BackgroundRequestNotAllowedError;
    if (s == "ProxyConnectionRefusedError") return QNetworkReply::NetworkError::ProxyConnectionRefusedError;
    if (s == "ProxyConnectionClosedError") return QNetworkReply::NetworkError::ProxyConnectionClosedError;
    if (s == "ProxyNotFoundError") return QNetworkReply::NetworkError::ProxyNotFoundError;
    if (s == "ProxyTimeoutError") return QNetworkReply::NetworkError::ProxyTimeoutError;
    if (s == "ProxyAuthenticationRequiredError") return QNetworkReply::NetworkError::ProxyAuthenticationRequiredError;
    if (s == "ContentAccessDenied") return QNetworkReply::NetworkError::ContentAccessDenied;
    if (s == "ContentOperationNotPermittedError") return QNetworkReply::NetworkError::ContentOperationNotPermittedError;
    if (s == "ContentNotFoundError") return QNetworkReply::NetworkError::ContentNotFoundError;
    if (s == "AuthenticationRequiredError") return QNetworkReply::NetworkError::AuthenticationRequiredError;
    if (s == "ContentReSendError") return QNetworkReply::NetworkError::ContentReSendError;
    if (s == "ProtocolUnknownError") return QNetworkReply::NetworkError::ProtocolUnknownError;
    if (s == "ProtocolInvalidOperationError") return QNetworkReply::NetworkError::ProtocolInvalidOperationError;
    if (s == "UnkownNetworkError") return QNetworkReply::NetworkError::UnknownNetworkError;
    if (s == "UnknownProxyError") return QNetworkReply::NetworkError::UnknownProxyError;
    if (s == "UnknownContentError") return QNetworkReply::NetworkError::UnknownContentError;
    if (s == "ProtocolFailure") return QNetworkReply::NetworkError::ProtocolFailure;
    if (s.startsWith(unknown_error_prefix))
    {
        return static_cast<QNetworkReply::NetworkError>(s.mid(sizeof(unknown_error_prefix)).toInt());
    }
    throw InvalidFieldException(entity_name, network_error_field);
}

QJsonObject serializeAttributes(const QMap<QNetworkRequest::Attribute, QVariant>& attributes)
{
    // see http://qt-project.org/doc/qt-5.0/qtnetwork/qnetworkrequest.html#Attribute-enum
    QVariantMap result;
    result["HttpStatusCodeAttribute"] = attributes[QNetworkRequest::HttpStatusCodeAttribute]; // type: QMetaType::Int (no default)
    result["HttpReasonPhraseAttribute"] = attributes[QNetworkRequest::HttpReasonPhraseAttribute]; // type: QMetaType::QByteArray (no default)
    result["RedirectionTargetAttribute"] = attributes[QNetworkRequest::RedirectionTargetAttribute]; // type: QMetaType::QUrl (no default)
    result["ConnectionEncryptedAttribute"] = attributes[QNetworkRequest::ConnectionEncryptedAttribute]; // type: QMetaType::Bool (default: false)
    result["SourceIsFromCacheAttribute"] = attributes[QNetworkRequest::SourceIsFromCacheAttribute]; // type: QMetaType::Bool (default: false)
    result["HttpPipeliningWasUsedAttribute"] = attributes[QNetworkRequest::HttpPipeliningWasUsedAttribute]; // type: QMetaType::Bool
    result["BackgroundRequestAttribute"] = attributes[QNetworkRequest::BackgroundRequestAttribute]; // type: QMetaType::Bool (default: false)
    // no support for user-attributes yet
    return QJsonObject::fromVariantMap(result);
}

QMap<QNetworkRequest::Attribute, QVariant> serializeAttributes(QJsonObject object)
{
    QVariantMap input = object.toVariantMap();
    QMap<QNetworkRequest::Attribute, QVariant> result;
    result[QNetworkRequest::HttpStatusCodeAttribute] = input["HttpStatusCodeAttribute"];
    result[QNetworkRequest::HttpReasonPhraseAttribute] = input["HttpReasonPhraseAttribute"];
    result[QNetworkRequest::RedirectionTargetAttribute] = input["RedirectionTargetAttribute"];
    result[QNetworkRequest::ConnectionEncryptedAttribute] = input["ConnectionEncryptedAttribute"];
    result[QNetworkRequest::SourceIsFromCacheAttribute] = input["SourceIsFromCacheAttribute"];
    result[QNetworkRequest::HttpPipeliningWasUsedAttribute] = input["HttpPipeliningWasUsedAttribute"];
    result[QNetworkRequest::BackgroundRequestAttribute] = input["BackgroundRequestAttribute"];
    return result;
}

QMap<QNetworkRequest::Attribute, QVariant> getAttributes(const QNetworkReply & reply)
{
    // see http://qt-project.org/doc/qt-5.0/qtnetwork/qnetworkrequest.html#Attribute-enum
    QMap<QNetworkRequest::Attribute, QVariant> result;
    result[QNetworkRequest::HttpStatusCodeAttribute] = reply.attribute(QNetworkRequest::HttpStatusCodeAttribute);
    result[QNetworkRequest::HttpReasonPhraseAttribute] = reply.attribute(QNetworkRequest::HttpReasonPhraseAttribute);
    result[QNetworkRequest::RedirectionTargetAttribute] = reply.attribute(QNetworkRequest::RedirectionTargetAttribute);
    result[QNetworkRequest::ConnectionEncryptedAttribute] = reply.attribute(QNetworkRequest::ConnectionEncryptedAttribute);
    result[QNetworkRequest::SourceIsFromCacheAttribute] = reply.attribute(QNetworkRequest::SourceIsFromCacheAttribute);
    result[QNetworkRequest::HttpPipeliningWasUsedAttribute] = reply.attribute(QNetworkRequest::HttpPipeliningWasUsedAttribute);
    result[QNetworkRequest::BackgroundRequestAttribute] = reply.attribute(QNetworkRequest::BackgroundRequestAttribute);
    // no support for user-attributes yet
    return result;
}

FetchResponse::FetchResponse(const QJsonObject &o)
{
    // TODO
}

QJsonObject FetchResponse::toJsonObject() const
{
    QJsonObject result;
    // TODO
    return result;
}

QNetworkReply::NetworkError FetchResponse::error() const
{
    return _error;
}

const QUrl& FetchResponse::url() const
{
    return _url;
}

