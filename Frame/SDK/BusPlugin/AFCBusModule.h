﻿/*
* This source file is part of ArkGameFrame
* For the latest info, see https://github.com/ArkGame
*
* Copyright (c) 2013-2018 ArkGame authors.
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*
*/

#pragma once

#include "SDK/Interface/AFIBusModule.h"

namespace ark
{

    class AFCBusModule final : public AFIBusModule
    {
    public:
        explicit AFCBusModule() = default;
        bool Init() override;

        const std::string& GetAppName(const uint8_t& app_type) override;
        const uint8_t GetAppType(const std::string& name) override;

        const AFServerConfig* GetAppServerInfo() override;
        const std::string GetAppHost(const int bus_id) override;

        bool GetDirectBusRelations(std::vector<AFServerConfig>& target_list) override;
        bool IsUndirectBusRelation(const int bus_id) override;

        const uint8_t GetSelfAppType() override;
        const int GetSelfBusID() override;
        const std::string GetSelfBusName() override;

        const int CombineBusID(const uint8_t& app_type, const uint8_t& inst_id) override;

    protected:
        bool LoadProcConfig();
        bool LoadBusRelation();
        uint16_t CalcProcPort(const AFBusAddr& bus_addr);

        const AFServerConfig* GetAppServerInfo(const AFBusAddr& bus_addr);
        const std::string& GetHost(const std::string& host);
    private:
        AFProcConfig mxProcConfig;
        std::map<uint8_t, std::map<uint8_t, bool>> mxBusRelations;
    };

}