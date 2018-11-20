#include "ALBackend.h"
#include <iostream>

Audio::OpenALBackend::OpenALBackend()
	:
	isInitialized(false)
{
	if (!isInitialized)
	{
		// open and create a device
		device = alcOpenDevice(nullptr);
		if (!device)
		{
			isInitialized = false;
			std::cout << "Could not open a device." << std::endl;
			int tmp;
			std::cin >> tmp;
			exit(1);
		}
		else
		{
			//std::cout << "OpenALdevice: " << std::string(alcGetString(device, ALC_DEVICE_SPECIFIER)).c_str() 
			//	<< std::endl;
		}

		// create a context
		context = alcCreateContext(device, nullptr);
		if (context == nullptr || alcMakeContextCurrent(context) == ALC_FALSE)
		{
			if (context != nullptr)
			{
				alcDestroyContext(context);
			}
			alcCloseDevice(device);
			std::cout << "Cannot set a context! Closing device." << std::endl;
			isInitialized = false;
			exit(1);
		}
		else
		{
			//std::cout << "OpenAL version: " << std::string(alGetString(AL_VERSION)).c_str() << std::endl;
			//std::cout << "OpenAL renderer: " << std::string(alGetString(AL_RENDERER)).c_str() << std::endl;
			//std::cout << "OpenAL vendor: " << std::string(alGetString(AL_VENDOR)).c_str() << std::endl;
			//std::cout << "OpenAL extension: " << std::string(alGetString(AL_EXTENSIONS)).c_str() << std::endl;
			//std::cout << "OpenAL init done." << std::endl;
		}
		isInitialized = true;
	}
}

Audio::OpenALBackend::~OpenALBackend()
{
	if (context)
	{
		alcMakeContextCurrent(nullptr);
		alcDestroyContext(context);
		context = nullptr;
		std::cout << "Destroyed OpenAL context." << std::endl;
	}
	if (device)
	{
		alcCloseDevice(device);
		device = nullptr;
		std::cout << "Closed OpenAL device." << std::endl;
	}
}

bool Audio::OpenALBackend::IsInitialized()
{
	return isInitialized;
}
