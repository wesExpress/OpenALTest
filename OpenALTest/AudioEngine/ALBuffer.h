#pragma once

#include "ALBackend.h"

namespace Audio
{
	class ALBuffer
	{
	public:
		ALBuffer();
		virtual ~ALBuffer();
	public:
		ALuint GetBuffer() const;
	public:
		ALuint buffer;
	};
}