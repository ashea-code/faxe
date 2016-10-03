/**
* Faxe - FMOD bindings for Haxe
*
* The MIT License (MIT)
*
* Copyright (c) 2015 Aaron M. Shea
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in
* all copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
* THE SOFTWARE.
*/
#pragma once

#define IMPLEMENT_API

#include <hxcpp.h>
#include <fmod.hpp>

#if (defined __MWERKS__)
	#include <SIOUX.h>
#endif

namespace linc
{
	namespace faxe
	{
		FMOD::System *fmodSoundSystem;
		
		//// Baisc FMOD operations
		extern void faxe_init(int numChannels);
		extern void faxe_update();
		extern void faxe_shutdown();

		//// Sound + Bank operations
		extern void faxe_load_bank(const std::string& bankName);
		extern void faxe_load_sound(const std::string& sndName, bool looping = false, bool streaming = false);
		extern void faxe_unload_sound(const std::string& sndName);

		// Event operations
		extern void faxe_load_event(const std::string& eventName);
		extern void faxe_play_event(const std::string& eventName);
		extern void faxe_stop_event(const std::string& eventName, bool forceStop = false);
		extern bool faxe_event_playing(const std::string& eventName);
		extern float faxe_get_event_param(const std::string& eventName, const std::string& paramName);
		extern void faxe_set_event_param(const std::string& eventName, const std::string& paramName, float sValue);

		// Channel operations
		extern void faxe_stop_all_channels();
		extern void faxe_stop_channel(int channelID);
		extern void faxe_set_channel_gain(int channelID, float gainDb);
		extern void faxe_set_channel_position(int channelID, float x, float y, float z);
		extern bool faxe_channel_playing(int channelID);

	} // faxe + fmod namespace
} // linc namespace