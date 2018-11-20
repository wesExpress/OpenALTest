#include "ALSoundEmitter.h"

#include <iostream>

WEngine::AudioEmitter::AudioEmitter(const std::string & filePath)
	:
	position(0.0f, 0.0f, 0.0f),
	velocity(0.0f, 0.0f, 0.0f),
	direction(0.0f, 0.0f, 0.0f),
	minGain(0.0f),
	maxGain(0.0f),
	minDistance(0.0f),
	maxDistance(0.3f),
	idBuffer(0),
	idSource(0)
{
	std::cout << "Constructing Audio Emitter." << std::endl;

	sample = SampleFactory::CreateSample(filePath);
	idBuffer = sample->GetBuffer();
	idSource = source.GetSource();

	alSourcei(idSource, AL_BUFFER, static_cast<ALint>(idBuffer));

	if (AL_NO_ERROR != alGetError())
	{
		std::cout << "OpenAL error in alSourcei." << std::endl;
	}
}

WEngine::AudioEmitter::~AudioEmitter()
{
	std::cout << "Destroying audio emitter." << std::endl;
}

void WEngine::AudioEmitter::SetPosition(const glm::vec3& position)
{
	this->position = position;
	alSource3f(idSource, AL_POSITION, this->position.x, this->position.y, this->position.z);
}

void WEngine::AudioEmitter::SetPosition(const float x, const float y, const float z)
{
	position = glm::vec3(x, y, z);
	alSource3f(idSource, AL_POSITION, position.x, position.y, position.z);
}

void WEngine::AudioEmitter::SetVelocity(const glm::vec3& velocity)
{
	this->velocity = velocity;
	alSource3f(idSource, AL_VELOCITY, this->velocity.x, this->velocity.y, this->velocity.z);
}

void WEngine::AudioEmitter::SetVelocity(const float x, const float y, const float z)
{
	velocity = glm::vec3(x, y, z);
	alSource3f(idSource, AL_VELOCITY, velocity.x, velocity.y, velocity.z);
}

void WEngine::AudioEmitter::SetDirection(const glm::vec3& direction)
{
	this->direction = direction;
	alSource3f(idSource, AL_DIRECTION, this->direction.x, this->direction.y, this->direction.z);
}

void WEngine::AudioEmitter::SetDirection(const float x, const float y, const float z)
{
	direction = glm::vec3(x, y, z);
	alSource3f(idSource, AL_DIRECTION, direction.x, direction.y, direction.z);
}

void WEngine::AudioEmitter::SetReferenceDistance(const float d)
{
	alSourcef(idSource, AL_REFERENCE_DISTANCE, d);
}

void WEngine::AudioEmitter::SetRollOffFactor(const float d)
{
	alSourcef(idSource, AL_ROLLOFF_FACTOR, d);
}

void WEngine::AudioEmitter::SetVolume(float volume)
{
	this->volume = volume;
	alSourcef(idSource, AL_GAIN, this->volume);
}

void WEngine::AudioEmitter::SetGain(float gain)
{
	if (gain < 0.0f)
	{
		std::cout << "Warning: the gain must be set greater than 0.0f." << std::endl;
		return;
	}
	this->gain = gain;
	alSourcef(idSource, AL_GAIN, gain);
}

void WEngine::AudioEmitter::SetLoop(const bool loop)
{
	this->loop = loop;
	alSourcei(idSource, AL_LOOPING, loop);
}

void WEngine::AudioEmitter::SetPitch(const float pitch)
{
	this->pitch = pitch;
	alSourcef(idSource, AL_PITCH, pitch);
}

void WEngine::AudioEmitter::SetMinMaxDistance(const float min, const float max)
{
	minDistance = min;
	maxDistance = max;

	alSourcef(idSource, AL_REFERENCE_DISTANCE, minDistance);
	alSourcef(idSource, AL_REFERENCE_DISTANCE, maxDistance);
}

void WEngine::AudioEmitter::SetMinMaxGain(const float min, const float max)
{
	if (min < 0.0f || max > 1.0f)
	{
		std::cout << "Warning gain must be in range [0.0 - 1.0]" << std::endl;
		return;
	}

	minGain = min;
	maxGain = max;

	alSourcef(idSource, AL_MIN_GAIN, minGain);
	alSourcef(idSource, AL_MAX_GAIN, maxGain);
}

void WEngine::AudioEmitter::SetDopplerFactor(const float strength)
{
	alSourcef(idSource, AL_DOPPLER_FACTOR, strength);
}

void WEngine::AudioEmitter::SetSpeedOfSound(const float speed)
{
	alSpeedOfSound(speed);
}

void WEngine::AudioEmitter::EnableRelativelistener(bool relative)
{
	alSourcei(idSource, AL_SOURCE_RELATIVE, relative);
}

void WEngine::AudioEmitter::Play()
{
	alSourcePlay(idSource);
	if (AL_NO_ERROR != alGetError())
	{
		std::cout << "OpenAL error in Play()." << std::endl;
	}
}

void WEngine::AudioEmitter::Pause()
{
	alSourcePause(idSource);
	if (AL_NO_ERROR != alGetError())
	{
		std::cout << "OpenAL error in Pause()." << std::endl;
	}
}

void WEngine::AudioEmitter::Stop()
{
	alSourceStop(idSource);
	if (AL_NO_ERROR != alGetError())
	{
		std::cout << "OpenAL error in Stop()." << std::endl;
	}
}

ALuint WEngine::AudioEmitter::GetState()
{
	ALint sourceState;
	ALuint state = 0;
	alGetSourceiv(idSource, AL_SOURCE_STATE, &sourceState);

	switch (sourceState)
	{
	case AL_INITIAL:
		state = AL_INITIAL;
		break;
	case AL_PLAYING:
		state = AL_PLAYING;
		break;
	case AL_PAUSED:
		state = AL_PAUSED;
		break;
	case AL_STOPPED:
		state = AL_STOPPED;
		break;
	default:
		std::cout << "Unknown state of sound!" << std::endl;
		break;
	}
	return state;
}
