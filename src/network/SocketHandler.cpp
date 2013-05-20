#include "sockethandler.hpp"

#include <QtNetwork>
#include <iostream>

socketHandler::socketHandler(QTcpSocket *sock)
{
    clientSocket = sock;
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(echo()));
    connect(clientSocket, SIGNAL(disconnected()),clientSocket, SLOT(deleteLater()));
    connect(clientSocket, SIGNAL(disconnected()),this, SLOT(killMe()));
}
void socketHandler::echo()
{
    QDataStream ds(clientSocket);
    QString text;
    ds >> text;
    if (text == "Quit") {
        text = "From Server: Bye-Bye!";
        ds << text;
        clientSocket->waitForBytesWritten(1000);
        clientSocket->disconnectFromHost();
    }
    else{
        text = "From Server: " + text;
        ds << text;
    }
}
void socketHandler::killMe(){
    if (this != NULL){
        std::cout << "Killing the clientHandler!" << std::endl;
        delete this;
    }
}
