#include "server.h"

Server::Server(int argc, char **argv) : QCoreApplication(argc, argv){
    httpServer.route("/", []() {
        return "CvlJoint::Hello World";
    });

    QJsonObject insertObject;
    insertObject.insert("msg","Hello");
    httpServer.route("/myApi", QHttpServerRequest::Method::Get,
                     [&insertObject](const QHttpServerRequest &request) {
                         return QHttpServerResponse(insertObject);
                     }
    );

    httpServer.afterRequest([](QHttpServerResponse &&resp) {
        resp.setHeader("Server", "Qt HTTP Server");
        return std::move(resp);
    });
}

void Server::Listen(const QString& address, const int port) {
    const QHostAddress host(address);
    const auto started = httpServer.listen(host,port);
    if (!started) {
        qDebug() << QCoreApplication::translate("CvlJoint::Server::Listen",
                                                "Server failed to listen on a port.");
        return ;
    }
    qDebug() << "Listen on: " << started;
}
