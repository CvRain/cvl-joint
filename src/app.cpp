#include "component.hpp"
#include "controller/hello_controller.hpp"

#include <oatpp/network/Server.hpp>
#include <oatpp/core/macro/codegen.hpp>

void run() {

    //注册一个应用服务组件
    AppComponent::Component components;

    //获得路由组建
    OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

    auto hello_controller = std::make_shared<Controller::HelloController>();
    router->addController(hello_controller);

    //获得连接组建
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

    //服务连接组建
    OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

    //创建一个Tcp服务
    oatpp::network::Server server(connectionProvider, connectionHandler);

    //打印服务器初始化信息
    OATPP_LOGI("CvlJoint", "Listening on port %s", connectionProvider->getProperty("port").getData());

    /* Run server */
    server.run();
}

int main() {
    oatpp::base::Environment::init();

    /* Run App */
    run();

    /* Destroy oatpp Environment */
    oatpp::base::Environment::destroy();}