#pragma once

#include <QNetworkAccessManager>

class TunnelNetworkAccessManager : public QNetworkAccessManager
{
    Q_OBJECT

public:
    TunnelNetworkAccessManager(QObject *parent = nullptr);
    QNetworkReply * deleteResource(const QNetworkRequest & request);
    QNetworkReply * get(const QNetworkRequest & request);
    QNetworkReply * head(const QNetworkRequest & request);
    QNetworkReply * post(const QNetworkRequest & request, QIODevice * data);
    QNetworkReply * post(const QNetworkRequest & request, const QByteArray & data);
    QNetworkReply * post(const QNetworkRequest & request, QHttpMultiPart * multiPart);
    QNetworkReply * put(const QNetworkRequest & request, QIODevice * data);
    QNetworkReply * put(const QNetworkRequest & request, QHttpMultiPart * multiPart);
    QNetworkReply * put(const QNetworkRequest & request, const QByteArray & data);
    QNetworkReply * sendCustomRequest(const QNetworkRequest & request, const QByteArray & verb, QIODevice * data = 0);
};
