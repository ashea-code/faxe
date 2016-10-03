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

#include <hxcpp.h>
#include <fmod.hpp>
#include "linc_faxe.h"

namespace linc 
{
	namespace faxe
	{
		FMOD::System *fmodSoundSystem;

		void faxe_init(int numChannels)
		{
			// Create our new fmod system
			if (FMOD::System_Create(&fmodSoundSystem) != FMOD_OK)
			{
				printf("Failure starting FMOD sound system!");
				return;
			}

			int numDrivers = 0;
			fmodSoundSystem->getNumDrivers(&numDrivers);

			if (numDrivers == 0)
			{
				printf("Failure starting FMOD sound system!");
				printf("FMOD could not find any sound drivers!");
				return;
			}

			// All OK - Setup some channels to work with!
			fmodSoundSystem->init(numChannels, FMOD_INIT_NORMAL, NULL);
			printf("FMOD Sound System Started with %d channels", numChannels);
		}
	} // faxe + fmod namespace
} // linc namespace