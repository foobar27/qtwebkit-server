#pragma once

#include <QJsonObject>
#include <QNetworkReply>

class FetchRequest
{
public:
    FetchRequest(const QJsonObject& o);
    QJsonObject toJsonObject() const;

private:
    int _fetchId;
    // TODO http request

};
