#include <QtNetwork>
#include <iostream>

#include "sockethandler.hpp"
#include "server.hpp"

Server::Server() {
    tcpServer = new QTcpServer(this);
    if (!tcpServer->listen(QHostAddress::Any,6666))
        std::cout << "Unable to start the server." <<endl;
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(getConnection()));
}

void Server::getConnection() {
    clientConnection = tcpServer->nextPendingConnection();
    new socketHandler(clientConnection);                  //create one socketHandler to handle each client connection
}
