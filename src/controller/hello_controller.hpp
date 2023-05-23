//
// Created by cvrain on 23-5-23.
//

#ifndef CVL_JOINT_HELLO_CONTROLLER_HPP
#define CVL_JOINT_HELLO_CONTROLLER_HPP

#include "dto/any_dto.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

namespace Controller {
    using oatpp::web::server::api::ApiController;

#include OATPP_CODEGEN_BEGIN(ApiController)
class HelloController : public ApiController {
public:
    explicit HelloController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : ApiController(objectMapper) {}

public:
    ENDPOINT("GET", "/hello", root) {
        auto hello_dto = Dto::MessageDto::createShared();
        hello_dto->status = "Nice";
        hello_dto->description = "say hello";
        hello_dto->action = "Hello::Say";
        return createDtoResponse(Status::CODE_200, hello_dto);
    }
};
#include OATPP_CODEGEN_END(ApiController)

}

#endif //CVL_JOINT_HELLO_CONTROLLER_HPP
