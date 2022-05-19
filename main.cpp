#include <QCoreApplication>
#include <QDebug>
#include "server.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    server server;
    try {
        server.start();
        qDebug() << "server started";
    } catch(QString& str) {
        qDebug() << str;
        return 1;
    }
    return a.exec();
}
