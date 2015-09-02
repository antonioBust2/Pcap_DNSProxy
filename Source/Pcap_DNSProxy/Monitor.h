﻿// This code is part of Pcap_DNSProxy
// A local DNS server based on WinPcap and LibPcap
// Copyright (C) 2012-2015 Chengr28
// 
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU General Public License
// as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.


#include "Base.h"

//Global variables
extern CONFIGURATION_TABLE Parameter;
extern ALTERNATE_SWAP_TABLE AlternateSwapList;
#if defined(ENABLE_LIBSODIUM)
	extern DNSCURVE_CONFIGURATION_TABLE DNSCurveParameter;
#endif
extern std::mutex LocalAddressLock[NETWORK_LAYER_PARTNUM];

//Functions
bool __fastcall UDPMonitor(const SOCKET_DATA LocalSocketData);
bool __fastcall TCPMonitor(const SOCKET_DATA LocalSocketData);
bool __fastcall TCPReceiveProcess(const SOCKET_DATA LocalSocketData);
void __fastcall AlternateServerMonitor(void);
#if defined(PLATFORM_WIN)
	PADDRINFOA __fastcall GetLocalAddressList(const uint16_t Protocol, PSTR HostName);
#elif (defined(PLATFORM_LINUX) || defined(PLATFORM_MACX))
	bool GetBestInterfaceAddress(const uint16_t Protocol, const sockaddr_storage *OriginalSockAddr);
#endif
void __fastcall GetGatewayInformation(const uint16_t Protocol);
