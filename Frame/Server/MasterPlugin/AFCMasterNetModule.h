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

#include "Common/AFProtoCPP.hpp"
#include "SDK/Core/AFMap.hpp"
#include "SDK/Interface/AFILogModule.h"
#include "SDK/Interface/AFIMsgModule.h"
#include "SDK/Interface/AFIBusModule.h"
#include "SDK/Interface/AFINetServiceManagerModule.h"
#include "SDK/Interface/AFIPluginManager.h"
#include "SDK/Interface/AFITimerModule.h"
#include "SDK/Interface/AFIMsgModule.h"
#include "Server/Interface/AFIMasterNetModule.h"

namespace ark
{

    class AFCMasterNetModule : public AFIMasterNetModule
    {
    public:
        explicit AFCMasterNetModule() = default;

        bool Init() override;
        bool PostInit() override;

    protected:
        int StartServer();
        //void OnSocketEvent(const NetEventType event, const AFGUID& conn_id, const std::string& ip, const int bus_id);

        //void OnClientConnected(const AFGUID& xClientID);
        //void OnClientDisconnect(int bus_id, const AFGUID& xClientID);

        //////////////////////////////////////////////////////////////////////////
        //void OnTimerLogServer(const std::string& name, const AFGUID& id);

        //void OnServerReport(const ARK_PKG_BASE_HEAD& head, const int msg_id, const char* msg, const uint32_t msg_len, const AFGUID& conn_id);
        //void SyncAllProxyToDir(int bus_id, const AFGUID& conn_id);
        //////////////////////////////////////////////////////////////////////////

        ////世界服务器注册，刷新信息
        //void OnWorldRegisteredProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
        //void OnWorldUnRegisteredProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
        //void OnRefreshWorldInfoProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);

        //////////////////////////////////////////////////////////////////////////
        ////登录服务器注册，刷新信息
        //void OnLoginRegisteredProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
        //void OnLoginUnRegisteredProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
        //void OnRefreshLoginInfoProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);

        ////选择世界服务器消息
        //void OnSelectWorldProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);
        //void OnSelectServerResultProcess(const ARK_PKG_BASE_HEAD& xHead, const int nMsgID, const char* msg, const uint32_t nLen, const AFGUID& xClientID);

        //////////////////////////////////////////////////////////////////////////

        //void SynWorldToLogin();

        //void OnHeartBeat(const ARK_PKG_BASE_HEAD& head, const int msg_id, const char* msg, const uint32_t msg_len, const AFGUID& conn_id);
        //void InvalidMessage(const ARK_PKG_BASE_HEAD& head, const int msg_id, const char* msg, const uint32_t msg_len, const AFGUID& conn_id);

    private:
        //AFMapEx<int, AFServerData> reg_servers_;

        AFILogModule* m_pLogModule;
        AFIBusModule* m_pBusModule;
        AFINetServiceManagerModule* m_pNetServiceManagerModule;
        AFITimerModule* m_pTimerModule;
        AFIMsgModule* m_pMsgModule;

        AFINetServerService* m_pNetServer{ nullptr };
    };

}