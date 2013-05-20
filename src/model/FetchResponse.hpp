#pragma once

#include <QJsonObject>
#include <QNetworkRequest>
#include <QNetworkReply>

class FetchResponse
{
private:
    QNetworkReply::NetworkError _error;
    QUrl _url;
    QMap<QNetworkRequest::Attribute, QVariant> attributes;
public:
    FetchResponse(const QJsonObject &o);
    QJsonObject toJsonObject() const;

    QNetworkReply::NetworkError error() const;
    const QUrl& url() const;
};
