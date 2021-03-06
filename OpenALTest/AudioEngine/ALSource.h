#pragma once

#include <memory>

#include "ALUtil.h"
#include "ALFactory.h"

namespace Audio
{
	class ALSource
	{
	public:
		ALSource();
		virtual ~ALSource();
	public:
		ALuint GetSource();
	private:
		ALuint source;
	};
}
