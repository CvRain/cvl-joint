#ifndef CVL_JOINT_SERVER_H
#define CVL_JOINT_SERVER_H

#include <QtHttpServer/QtHttpServer>
#include <QCoreApplication>
#include <QString>

class Server : public QCoreApplication{
public:
    explicit Server(int argc, char** argv);
    void Listen(const QString& address, const int port=5281);
private:
    QHttpServer httpServer;
};


#endif //CVL_JOINT_SERVER_H
