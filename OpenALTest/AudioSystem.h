#pragma once

#include <map>
#include <memory>
#include <iostream>

#include "AudioEngine/ALBackend.h"
#include "AudioEngine/ALSoundEmitter.h"
#include "AudioEngine/ALListener.h"

class AudioSystem : public Audio::OpenALBackend
{
public:
	explicit AudioSystem();
	virtual ~AudioSystem();
public:
	void LoadFromFile(const std::string& name, const std::string& filePath);
	std::shared_ptr<Audio::AudioEmitter> GetEmitter(const std::string& name);
protected:
	std::map<std::string, std::shared_ptr<Audio::AudioEmitter>> emitters;
};