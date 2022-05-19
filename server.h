#ifndef SERVER_H
#define SERVER_H


#include <QObject>
#include <QTcpSocket>
#include <QTcpServer>
#include "gpio.h"

const int PORT = 5000;
class server : public QObject
{
    Q_OBJECT
public:
    explicit server(QObject *parent = nullptr);
    void start();

signals:

public slots:
    void mynewConnection();
    void myclientDisconnect();
    void myserverRead();

private:
    QTcpServer* m_server;
    QTcpSocket* m_socket;
    gpio ledstrip;
};

#endif // SERVER_H
