#pragma once

#include <memory>
#include <glm/glm.hpp>
#include <AL/al.h>

namespace Audio
{
	class SampleBase
	{
	public:
		virtual float GetDuration() const = 0;
		virtual int NumberOfChannels() const = 0;
		virtual ALuint GetBuffer() const = 0;
	};

	class AudioEmitterBase
	{
	public:
		AudioEmitterBase() {}
		virtual ~AudioEmitterBase() {}

		virtual void SetPosition(const glm::vec3& position) = 0;
		virtual void SetVelocity(const glm::vec3& velocity) = 0;
		virtual void SetDirection(const glm::vec3& direction) = 0;
		virtual void SetVolume(float volume) = 0;
		virtual void SetLoop(bool loop) = 0;
	};
}
