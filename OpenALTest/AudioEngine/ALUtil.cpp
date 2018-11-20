#include "ALUtil.h"

#include <iostream>

ALint Audio::GetFormatNumChannels(ALuint channels)
{
	ALint format = 0;
	switch (channels)
	{
	case 1:
		format = AL_FORMAT_MONO16;
		break;
	case 2:
		format = AL_FORMAT_STEREO16;
		break;
	default:
		format = 0;
		break;
	}
	if (format == -1)
	{
		format = 0;
	}
	return format;
}

void Audio::SetDistanceModel(ALenum model)
{
	switch (model)
	{
	case AL_NONE:
		alDistanceModel(AL_NONE);
		break;
	case AL_EXPONENT_DISTANCE:
		alDistanceModel(AL_EXPONENT_DISTANCE);
		break;
	case AL_EXPONENT_DISTANCE_CLAMPED:
		alDistanceModel(AL_EXPONENT_DISTANCE_CLAMPED);
		break;
	case AL_INVERSE_DISTANCE:
		alDistanceModel(AL_INVERSE_DISTANCE);
		break;
	case AL_INVERSE_DISTANCE_CLAMPED:
		alDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);
		break;
	case AL_LINEAR_DISTANCE:
		alDistanceModel(AL_LINEAR_DISTANCE);
		break;
	case AL_LINEAR_DISTANCE_CLAMPED:
		alDistanceModel(AL_LINEAR_DISTANCE_CLAMPED);
		break;
	default:
		std::cout << "WARNING: unknwon distance model!" << std::endl;
		break;
	}
}
