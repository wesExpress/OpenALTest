#pragma once

#include <glm/glm.hpp>

#include "ALSoundBase.h"
#include "ALFactory.h"
#include "ALSource.h"

namespace WEngine
{
	class AudioEmitter : public AudioEmitterBase
	{
	public:
		AudioEmitter(const std::string& filePath);
		virtual ~AudioEmitter();
	public:
		// position of the emitter
		void SetPosition(const glm::vec3& position);
		void SetPosition(const float x, const float y, const float z);
		// velocity of the emitter
		void SetVelocity(const glm::vec3& velocity);
		void SetVelocity(const float x, const float y, const float z);
		// direction of the emitter
		void SetDirection(const glm::vec3& direction);
		void SetDirection(const float x, const float y, const float z);
		// reference distance
		void SetReferenceDistance(const float d);
		void SetRollOffFactor(const float d);

		void SetVolume(float volume);
		void SetGain(float gain);

		void SetLoop(const bool loop);
		void SetPitch(const float pitch);

		void SetMinMaxDistance(const float min, const float max);
		void SetMinMaxGain(const float min, const float max);

		void SetDopplerFactor(const float strength);
		void SetSpeedOfSound(const float speed);

		void EnableRelativelistener(bool relative);

		glm::vec3& GetPostion() { return position; }

		void Play();
		void Pause();
		void Stop();

		ALuint GetState();
	private:
		std::unique_ptr<SampleBase> sample;
		ALSource source;
		glm::vec3 position;
		glm::vec3 velocity;
		glm::vec3 direction;

		bool loop;

		float volume;
		float gain;
		float minGain;
		float maxGain;
		float minDistance;
		float maxDistance;
		float pitch;

		ALuint idBuffer;
		ALuint idSource;
	};
}