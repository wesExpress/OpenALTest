#pragma once

#include "ALSoundBase.h"

namespace Audio
{
	class AudioListenerSettings
	{
	public:
		const glm::vec3 defaultPosition = glm::vec3(0.0f, 0.0f, 0.0f);
		const glm::vec3 defaultVelocity = glm::vec3(0.0f, 0.0f, 0.0f);
		const glm::vec3 defaultDirection = glm::vec3(0.0f, 0.0f, 0.0f);
		const glm::vec3 defaultUpVector = glm::vec3(0.0f, 1.0f, 0.0f);
	};

	class AudioListener
	{
	public:
		explicit AudioListener();
		explicit AudioListener(AudioListenerSettings& audioSettings);
		virtual ~AudioListener();
	public:
		void SetPosition(glm::vec3& position);
		void SetPosition(const float& x, const float& y, const float& z);

		void SetVelocity(glm::vec3& velocity);
		void SetVelocity(const float& x, const float& y, const float& z);

		void SetDirection(glm::vec3& direction);
		void SetDirection(const float& x, const float& y, const float& z);

		glm::vec3 GetPosition() const;
		glm::vec3 GetVelocity() const;

		void UpdateListener(const glm::vec3& position, const glm::vec3& direction);
	private:
		glm::vec3 position;
		glm::vec3 velocity;
		glm::vec3 direction;
		glm::vec3 upVector;
		AudioListenerSettings audioSettings;
	};
}
