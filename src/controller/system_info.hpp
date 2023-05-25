//
// Created by cvrain on 23-5-25.
//

#ifndef CVL_JOINT_SYSTEM_INFO_HPP
#define CVL_JOINT_SYSTEM_INFO_HPP

#endif //CVL_JOINT_SYSTEM_INFO_HPP

#include "dto/any_dto.hpp"
#include "dto/server_dto.hpp"
#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include <memory>
#include <chrono>
#include <ctime>

namespace Controller {
    using oatpp::web::server::api::ApiController;

#include OATPP_CODEGEN_BEGIN(ApiController)

class SystemInfoController : public ApiController {
public:
    explicit SystemInfoController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper))
            : ApiController(objectMapper) {}

    static std::shared_ptr<SystemInfoController>
    createShared(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) {
        return std::make_shared<SystemInfoController>(objectMapper);
    }

public:
    ENDPOINT_ASYNC("GET", "/hello", Hello) {
    ENDPOINT_ASYNC_INIT(Hello)

        Action act() override {
            auto dto = Dto::MessageDto::createShared();
            dto->description = "Hello async";
            dto->action = "Hello";
            dto->status = "OK";
            return _return(controller->createDtoResponse(Status::CODE_200, dto));
        }
    };


    ENDPOINT_ASYNC("GET", "/api/sys_date", SysDate) {
    ENDPOINT_ASYNC_INIT(SysDate)

        Action act() override {
            const auto date_now = std::chrono::system_clock::now();
            const auto data_now_c = std::chrono::system_clock::to_time_t(date_now);
            const auto local_time = std::localtime(&data_now_c);
            auto time_struct = Dto::SystemDateDto::createShared();

            time_struct->year = std::to_string(local_time->tm_year + 1900);
            time_struct->month = std::to_string(local_time->tm_mon + 1);
            time_struct->day = std::to_string(local_time->tm_mday + 1);
            time_struct->hour = std::to_string(local_time->tm_hour + 1);
            time_struct->minute = std::to_string(local_time->tm_min + 1);
            time_struct->second = std::to_string(local_time->tm_sec + 1);
            time_struct->millisecond = std::to_string(std::chrono::duration_cast<std::chrono::milliseconds>(date_now.time_since_epoch()).count());
            return _return(controller->createDtoResponse(Status::CODE_200, time_struct));
        }
    };

};

#include OATPP_CODEGEN_END(ApiController)

}