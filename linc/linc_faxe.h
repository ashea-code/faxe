/**
* Faxe - FMOD bindings for Haxe
*
* The MIT License (MIT)
*
* Copyright (c) 2016 Aaron M. Shea
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

#if (defined __MWERKS__)
	#include <SIOUX.h>
#endif

namespace linc
{
	namespace faxe
	{
		//// Baisc FMOD operations

		/**
		 * Initialization of FMOD sound system
		 * \param[numChannels] number of channels to allocate for this sound system
		 */
		extern void faxe_init(int numChannels = 32);

		/**
		 * Clean up allocated objects from the FMOD sound system
		 */
		extern void faxe_shutdown();

		//// Sound + Bank operations

		/**
		 * Load a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to load
		 */
		extern void faxe_load_bank(const ::String& bankName);

		/**
		 * Unload a FMOD sound bank file
		 * \param[bankName] ::String the file path of the sound bank to unload
		 */
		extern void faxe_unload_bank(const ::String& bankName);

		/**
		 * Load an arbitrary sound into FMOD
		 * \param[sndName] ::String the file path of the sound to load
		 */
		extern void faxe_load_sound(const ::String& sndName, bool looping = false, bool streaming = false);

		/**
		 * Unload a sound from FMOD
		 * \param[sndName] ::String the file path of the sound to unload
		 */
		extern void faxe_unload_sound(const ::String& sndName);

		//// Event operations

		/**
		 * Load an event from a loaded bank
		 * \param[sndName] ::String the name of the event to load into memory
		 */
		extern void faxe_load_event(const ::String& eventName);

		extern void faxe_play_event(const ::String& eventName);
		extern void faxe_stop_event(const ::String& eventName, bool forceStop = false);
		extern bool faxe_event_playing(const ::String& eventName);
		extern float faxe_get_event_param(const ::String& eventName, const ::String& paramName);
		extern void faxe_set_event_param(const ::String& eventName, const ::String& paramName, float sValue);

		//// Channel operations
		extern void faxe_stop_all_channels();
		extern void faxe_stop_channel(int channelID);
		extern void faxe_set_channel_gain(int channelID, float gainDb);
		extern void faxe_set_channel_position(int channelID, float x, float y, float z);
		extern bool faxe_channel_playing(int channelID);

	} // faxe + fmod namespace
} // linc namespace
