#pragma once

#include "ALBackend.h"
#include "ALSoundBase.h"

namespace WEngine
{
	extern ALint GetFormatNumChannels(ALuint channels);
	extern void SetDistanceModel(ALenum model);
}