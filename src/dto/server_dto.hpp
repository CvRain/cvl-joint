//
// Created by cvrain on 23-5-25.
//

#ifndef CVL_JOINT_SERVER_DTO_HPP
#define CVL_JOINT_SERVER_DTO_HPP

#include <oatpp/core/data/mapping/type/Object.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

namespace Dto {

#include OATPP_CODEGEN_BEGIN(DTO)

class SystemInfoDto : public oatpp::DTO {
    DTO_INIT(SystemInfoDto, DTO)

    DTO_FIELD(String, cpu);

    DTO_FIELD(String, memory);

    DTO_FIELD(String, disk);

    DTO_FIELD(String, local_time);

    DTO_FIELD(String, upload_speed);

    DTO_FIELD(String, download_speed);
};

class SystemDateDto : public oatpp::DTO {
    DTO_INIT(SystemDateDto, DTO)

    DTO_FIELD(String, year);

    DTO_FIELD(String, month);

    DTO_FIELD(String, day);

    DTO_FIELD(String, hour);

    DTO_FIELD(String, minute);

    DTO_FIELD(String, second);

    DTO_FIELD(String, millisecond);
};

#include OATPP_CODEGEN_END(DTO)

}


#endif //CVL_JOINT_SERVER_DTO_HPP
