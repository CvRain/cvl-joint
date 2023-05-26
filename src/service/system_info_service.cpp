//
// Created by cvrain on 23-5-26.
//

#include "system_info_service.hpp"

namespace Service {
    auto SystemInfoService::GetSystemDate() -> decltype(Dto::SystemDateDto::createShared()) {
        const auto date_now = std::chrono::system_clock::now();
        const auto data_now_c = std::chrono::system_clock::to_time_t(date_now);
        const auto local_time = std::localtime(&data_now_c);
        auto time_struct = Dto::SystemDateDto::createShared();

        time_struct->year = std::to_string(local_time->tm_year + 1900);
        time_struct->month = std::to_string(local_time->tm_mon + 1);
        time_struct->day = std::to_string(local_time->tm_mday + 1);
        time_struct->hour = std::to_string(local_time->tm_hour);
        time_struct->minute = std::to_string(local_time->tm_min);
        time_struct->second = std::to_string(local_time->tm_sec);

        const auto time_ms = std::chrono::time_point_cast<std::chrono::milliseconds>(date_now);
        const auto millisecond_value = time_ms.time_since_epoch().count();
        time_struct->timestramp = std::to_string(millisecond_value);
        return time_struct;
    }
}