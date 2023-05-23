//
// Created by cvrain on 23-5-23.
//

#ifndef CVL_JOINT_ANY_DTO_HPP
#define CVL_JOINT_ANY_DTO_HPP

#include <oatpp/core/data/mapping/type/Object.hpp>
#include <oatpp/core/macro/codegen.hpp>
#include <oatpp/core/Types.hpp>

namespace Dto {

#include OATPP_CODEGEN_BEGIN(DTO)
class MessageDto : public oatpp::DTO {
    DTO_INIT(MessageDto, DTO);

    DTO_FIELD(String, status);

    DTO_FIELD(String, description);

    DTO_FIELD(String, action);

};
#include OATPP_CODEGEN_END(DTO)

}


#endif //CVL_JOINT_ANY_DTO_HPP
