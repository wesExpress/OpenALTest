#pragma once

#include "ALBackend.h"
#include "ALSoundBase.h"

namespace Audio
{
	extern ALint GetFormatNumChannels(ALuint channels);
	extern void SetDistanceModel(ALenum model);
}