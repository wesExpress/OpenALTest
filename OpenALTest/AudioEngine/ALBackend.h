#pragma once

#include <al.h>
#include <alc.h>

namespace Audio
{
	class OpenALBackend
	{
	public:
		explicit OpenALBackend();
		virtual ~OpenALBackend();
	public:
		bool IsInitialized();
	private:
		ALCdevice* device = nullptr;
		ALCcontext* context = nullptr;
		bool isInitialized;
	};
}
