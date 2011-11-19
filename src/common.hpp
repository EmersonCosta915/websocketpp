/*
 * Copyright (c) 2011, Peter Thorson. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the WebSocket++ Project nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" 
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE 
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE 
 * ARE DISCLAIMED. IN NO EVENT SHALL PETER THORSON BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 * 
 */

#ifndef WEBSOCKET_CONSTANTS_HPP
#define WEBSOCKET_CONSTANTS_HPP

#include <stdint.h>

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

// Defaults
namespace websocketpp {
	typedef std::vector<unsigned char> binary_string;
	typedef boost::shared_ptr<binary_string> binary_string_ptr;
	
	typedef std::string utf8_string;
	typedef boost::shared_ptr<utf8_string> utf8_string_ptr;
	
	const uint64_t DEFAULT_MAX_MESSAGE_SIZE = 0xFFFFFF; // ~16MB
	
	const uint16_t DEFAULT_PORT = 80;
	const uint16_t DEFAULT_SECURE_PORT = 443;
	
	inline uint16_t default_port(bool secure) {
		return (secure ? DEFAULT_SECURE_PORT : DEFAULT_PORT);
	}	
	
	namespace session {
		namespace state {
			enum value {
				CONNECTING = 0,
				OPEN = 1,
				CLOSING = 2,
				CLOSED = 3
			};
		}
	}
	
	namespace close {
	namespace status {
		enum value {
			INVALID_END = 999,
			NORMAL = 1000,
			GOING_AWAY = 1001,
			PROTOCOL_ERROR = 1002,
			UNSUPPORTED_DATA = 1003,
			RSV_ADHOC_1 = 1004,
			NO_STATUS = 1005,
			ABNORMAL_CLOSE = 1006,
			INVALID_PAYLOAD = 1007,
			POLICY_VIOLATION = 1008,
			MESSAGE_TOO_BIG = 1009,
			EXTENSION_REQUIRE = 1010,
			RSV_START = 1011,
			RSV_END = 2999,
			INVALID_START = 5000
		};
		
		inline bool reserved(value s) {
			return ((s >= RSV_START && s <= RSV_END) || 
					s == RSV_ADHOC_1);
		}
		
		inline bool invalid(value s) {
			return ((s <= INVALID_END || s >= INVALID_START) || 
					s == NO_STATUS || 
					s == ABNORMAL_CLOSE);
		}
		
		// TODO functions for application ranges?
	}
	}
	
}

#endif // WEBSOCKET_CONSTANTS_HPP