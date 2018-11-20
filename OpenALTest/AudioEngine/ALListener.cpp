#include "ALListener.h"

#include <iostream>

Audio::AudioListener::AudioListener()
	:
	position(0.0f, 0.0f, 0.0f),
	velocity(0.0f, 0.0f, 0.0f),
	direction(0.0f, 0.0f, 0.0f),
	upVector(0.0f, 0.0f, 0.0f)
{
}

Audio::AudioListener::AudioListener(AudioListenerSettings & audioSettings)
	:
	audioSettings(audioSettings)
{
	position = audioSettings.defaultPosition;
	velocity = audioSettings.defaultVelocity;
	direction = audioSettings.defaultDirection;
	upVector = audioSettings.defaultUpVector;

	std::cout << "Constructing listener." << std::endl;
}

Audio::AudioListener::~AudioListener()
{
	std::cout << "Destroying listener." << std::endl;
}

void Audio::AudioListener::SetPosition(glm::vec3 & position)
{
	this->position = position;
	alListener3f(AL_POSITION, this->position.x, this->position.y, this->position.y);
}

void Audio::AudioListener::SetPosition(const float & x, const float & y, const float & z)
{
	position = glm::vec3(x, y, z);
	alListener3f(AL_POSITION, position.x, position.y, position.z);
}

void Audio::AudioListener::SetVelocity(glm::vec3 & velocity)
{
	this->velocity = velocity;
	alListener3f(AL_VELOCITY, this->velocity.x, this->velocity.y, this->velocity.y);
}

void Audio::AudioListener::SetVelocity(const float & x, const float & y, const float & z)
{
	velocity = glm::vec3(x, y, z);
	alListener3f(AL_VELOCITY, velocity.x, velocity.y, velocity.z);
}

void Audio::AudioListener::SetDirection(glm::vec3 & direction)
{
	this->direction = direction;
	float orientation[6] =
	{
		this->direction.x, this->direction.y, this->direction.z,
		upVector.x, upVector.y, upVector.z
	};
	alListenerfv(AL_ORIENTATION, orientation);
}

void Audio::AudioListener::SetDirection(const float & x, const float & y, const float & z)
{
	this->direction = glm::vec3(x, y, z);
	float orientation[6] =
	{
		direction.x, direction.y, direction.z,
		upVector.x, upVector.y, upVector.z
	};
	alListenerfv(AL_ORIENTATION, orientation);
}

glm::vec3 Audio::AudioListener::GetPosition() const
{
	return position;
}

glm::vec3 Audio::AudioListener::GetVelocity() const
{
	return velocity;
}

void Audio::AudioListener::UpdateListener(const glm::vec3 & position, const glm::vec3 & direction)
{
	this->position = position;
	this->velocity = velocity;

	float orientation[6] =
	{
		direction.x, direction.y, direction.z,
		upVector.x, upVector.y, upVector.z
	};

	alListener3f(AL_POSITION, this->position.x, this->position.y, this->position.z);
	alListenerfv(AL_ORIENTATION, orientation);
}
