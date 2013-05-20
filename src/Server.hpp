#pragma once

#include <QtCore>
class QTcpServer;
class QTcpSocket;
class Server : public QObject
{
    Q_OBJECT
public:
    Server();
private slots:
    void getConnection();
private:
    QTcpSocket *clientConnection;
    QTcpServer *tcpServer;
};
