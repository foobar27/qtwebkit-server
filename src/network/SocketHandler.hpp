#pragma once

#include <QtCore>
class QTcpSocket;
class socketHandler : public QObject
{
    Q_OBJECT
public:
    socketHandler(QTcpSocket *);
private slots:
    void echo();
    void killMe();
private:
    QTcpSocket *clientSocket;
};
