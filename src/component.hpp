//
// Created by cvrain on 23-5-23.
//

#ifndef CVL_JOINT_COMPONENT_HPP
#define CVL_JOINT_COMPONENT_HPP

#include <iostream>
#include <string>
#include <oatpp/parser/json/mapping/ObjectMapper.hpp>
#include <oatpp/web/server/HttpConnectionHandler.hpp>
#include <oatpp/network/tcp/server/ConnectionProvider.hpp>
#include <oatpp/core/macro/component.hpp>

namespace AppComponent {
    using oatpp::network::ServerConnectionProvider;
    using oatpp::network::tcp::server::ConnectionProvider;
    using oatpp::web::server::HttpRouter;
    using oatpp::network::ConnectionHandler;
    using oatpp::web::server::HttpConnectionHandler;
    using oatpp::data::mapping::ObjectMapper;
    using oatpp::base::Environment;

    class Component {
    public:
        explicit Component(const std::string &server_host, const uint16_t server_port)
                : serverConnectionProvider(
                Environment::Component<std::shared_ptr<ServerConnectionProvider>>{   //创建服务连接组件，用来监听端口
                        ConnectionProvider::createShared({server_host, server_port, oatpp::network::Address::IP_4})
                }) {
            OATPP_LOGI("CvlJoint", "Component::Initialize");
        }

        //创建路由组建
        OATPP_CREATE_COMPONENT(std::shared_ptr<HttpRouter>, httpRouter)([]() {
            return HttpRouter::createShared();
        }());

        //创建用于路由组建连接请求的连接管理器组建
        OATPP_CREATE_COMPONENT(std::shared_ptr<ConnectionHandler>, serverConnectionHandler)([]() {
            OATPP_COMPONENT(std::shared_ptr<HttpRouter>, router);
            return HttpConnectionHandler::createShared(router);
        }());

        //创建Dto对象管理组件用于序列化和返序列化类
        OATPP_CREATE_COMPONENT(std::shared_ptr<ObjectMapper>, apiObjectMapper)([]() {
            return oatpp::parser::json::mapping::ObjectMapper::createShared();
        }());

    public:
        Environment::Component<std::shared_ptr<ServerConnectionProvider>> serverConnectionProvider;
    };

}

#endif //CVL_JOINT_COMPONENT_HPP
