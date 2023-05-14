#include "server.h"
#include <QFile>
#include <QString>
#include <iostream>
#include <toml++/toml.h>

void createDefaultSettings();

toml::table backDefaultSettings();

int main(int argc, char *argv[]) {
    // load settings.toml if not exist create it and terminate program
    QString settingsFilePath("./settings.toml");
    QFile settingsFile(settingsFilePath);
    // create settings file if it doesn't exist
    if (!settingsFile.exists()) {
        std::cerr << "Settings file does not exist, will load default" << std::endl;
        // create default settings file
        createDefaultSettings();
        return 0;
    }
    // load settings from settings.toml
    QString host{"localhost"};
    int port{5281};
    if (settingsFile.open(QFile::ReadOnly)) {
        const auto settingSource = settingsFile.readAll();
        toml::table settings;
        try {
            settings = toml::parse(settingSource.toStdString());
        } catch (const toml::parse_error &err) {
            std::cerr << "Parsing failed:\n" << err << "\n";
            return 1;
        }
    } else {
        std::cerr << "Could not open settings file, will load default" << std::endl;
    }

    settingsFile.close();

    Server cvlServer(argc, argv);
    cvlServer.Listen(host, port);

    return QCoreApplication::exec();
}

void createDefaultSettings() {
    const auto defaultTable = backDefaultSettings();

}

toml::table backDefaultSettings() {
    toml::table config{
            {"host", "localhost"},
            {"port", 5281}
    };
    return config;
}