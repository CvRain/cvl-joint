#ifndef CVL_JOINT_SYSTEM_INFO_SERVICE_HPP
#define CVL_JOINT_SYSTEM_INFO_SERVICE_HPP

#include "dto/server_dto.hpp"

namespace Service {
    class SystemInfoService {
    public:
        static auto GetSystemDate() -> decltype(Dto::SystemDateDto::createShared());
    };
}

#endif //CVL_JOINT_SYSTEM_INFO_SERVICE_HPP
