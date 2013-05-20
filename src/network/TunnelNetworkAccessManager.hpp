#pragma once

#include <QNetworkAccessManager>

class TunnelNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    TunnelNetworkAccessManager(QObject *parent = nullptr);
protected:
    virtual QNetworkReply * sendCustomRequest(const QNetworkRequest & request, const QByteArray & verb, QIODevice * data = 0);
};
