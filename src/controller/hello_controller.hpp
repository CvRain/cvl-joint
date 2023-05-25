//
// Created by cvrain on 23-5-23.
//

#ifndef CVL_JOINT_HELLO_CONTROLLER_HPP
#define CVL_JOINT_HELLO_CONTROLLER_HPP

#include <memory>

#include "dto/any_dto.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

namespace Controller {
    using oatpp::web::server::api::ApiController;

#include OATPP_CODEGEN_BEGIN(ApiController)

class HelloController : public ApiController {
public:
    //typedef HelloController __ControllerType;

    explicit HelloController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : ApiController(objectMapper) {}

    static std::shared_ptr<HelloController> createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<HelloController>(objectMapper);
    }

public:
    ENDPOINT_ASYNC("GET", "/", Root) {
    ENDPOINT_ASYNC_INIT(Root)

        Action act() override {
            auto dto = Dto::HelloDto::createShared();
            dto->message = "Hello Async!";
            dto->server = Header::Value::SERVER;
            dto->userAgent = request->getHeader(Header::USER_AGENT);
            return _return(controller->createDtoResponse(Status::CODE_200, dto));
        }

    };

};

#include OATPP_CODEGEN_END(ApiController)

}

#endif //CVL_JOINT_HELLO_CONTROLLER_HPP
