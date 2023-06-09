#include "component.hpp"
#include "controller/hello_controller.hpp"
#include "controller/system_info.hpp"

#include <oatpp/network/Server.hpp>
#include <oatpp/core/macro/codegen.hpp>

#include <filesystem>
#include <fstream>
#include <sstream>
#include <toml++/toml.h>
#include <optional>

void run(const std::string &host = "localhost", uint16_t port = 5281);
void create_setting();
std::optional<std::string> reading_setting(const std::filesystem::path& path);

int main() {
    oatpp::base::Environment::init();

    //初始化服务器信息，读取settings.toml
    std::filesystem::path setting_path{"./settings.toml"};
    //检查文件是否存在，不存在就创建
    if(!std::filesystem::exists(setting_path)){
        //create default file
        create_setting();
    }
    //读取文件并且尝试反序列化，失败则使用默认配置
    std::string host;
    int port;
    if(auto result = reading_setting(setting_path); !result.has_value()){
        OATPP_LOGI("Setting","Loading::Invalid");
        return -1;
    }else{
        auto table = toml::parse(result.value());
        OATPP_LOGI("Setting","Loading file");
        const auto result_host = table["host"].value<std::string>();
        const auto result_port = table["port"].value<int>();
        if(result_host.has_value() && result.has_value()){
            host = result_host.value();
            port = result_port.value();
        }
        OATPP_LOGI("Setting","Host: %s", host.data());
        OATPP_LOGI("Setting","Port: %d", port);
    }

    run(host,port);
    std::cout << "\nEnvironment:\n";
    std::cout << "objectsCount = " << oatpp::base::Environment::getObjectsCount() << "\n";
    std::cout << "objectsCreated = " << oatpp::base::Environment::getObjectsCreated() << "\n\n";


    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();
}


void run(const std::string &host, const uint16_t port) {

    //注册一个应用服务组件
    AppComponent::Component components{host,port};

    auto router = components.httpRouter.getObject();
    router->addController(Controller::HelloController::createShared());
    router->addController(Controller::SystemInfoController::createShared());

    oatpp::network::Server server(components.serverConnectionProvider.getObject(),
                                  components.serverConnectionHandler.getObject());

    OATPP_LOGD("Server", "Running on port %s...", components.serverConnectionProvider.getObject()->getProperty("port").toString()->c_str());

    /* Run server */
    server.run();
}

void create_setting()
{
    auto default_table = toml::table{
            {"host","localhost"},
            {"port",9280}
    };
    OATPP_LOGI("Setting","Create::Default");
    std::stringstream ss{};
    ss << default_table;

    std::ofstream file("./settings.toml");
    file << ss.str();
    file.close();
}

std::optional<std::string> reading_setting(const std::filesystem::path &path) {
    std::ifstream setting_file(path);
    std::stringstream ss;
    ss << setting_file.rdbuf();
    setting_file.close();
    return ss.str();
}
