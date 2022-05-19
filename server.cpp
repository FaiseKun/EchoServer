#include "server.h"
#include <QDebug>

server::server(QObject *parent) : QObject(parent)
{
    m_server = new QTcpServer(this);
    connect(m_server, &QTcpServer::newConnection, this, &server::mynewConnection);
}

void server::start()
{
    if (!m_server->listen(QHostAddress::Any, PORT))
        throw m_server->errorString(); // happens when PORT already in use or privileged
}

// when connected from client
void server::mynewConnection()
{
    m_socket = m_server->nextPendingConnection();
    qDebug()<<"Hi";
    ledstrip.set(15);
    connect(m_socket, &QTcpSocket::disconnected, this, &server::myclientDisconnect);
    connect(m_socket, &QTcpSocket::readyRead, this, &server::myserverRead);
}

// connection is closed by client
void server::myclientDisconnect()
{
    ledstrip.set(0);
    qDebug()<<"Bye";
    m_socket->close();
}

void server::myserverRead()
{
    qDebug() << "serverRead";

    while (m_socket->bytesAvailable()) {
        QByteArray msg = m_socket->readAll();
        qDebug() << msg;
        std::reverse(msg.begin(), msg.end());
        m_socket->write(msg + "\n");
    }

    /*for(int i = 0; i < 16;i++)
    {
        ledstrip.set(i);

    }*/
}
