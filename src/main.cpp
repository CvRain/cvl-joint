#include "server.h"

int main(int argc, char *argv[]) {
    Server cvlServer(argc,argv);
    cvlServer.Listen("localhost",5281);

    return QCoreApplication::exec();
}
