#pragma once

#include <QJsonObject>
#include <QNetworkReply>

class FetchRequest
{
private:
    int _fetchId;
    // TODO http request
public:
    FetchRequest(const QJsonObject& o);
    QJsonObject toJsonObject() const;



};
