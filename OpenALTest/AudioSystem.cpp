#include "AudioSystem.h"

Audio::AudioSystem::AudioSystem()
{
}

Audio::AudioSystem::~AudioSystem()
{
}

void Audio::AudioSystem::LoadFromFile(const std::string & name, const std::string & filePath)
{
	if (filePath.empty())
	{
		std::cout << "File path is empty!" << std::endl;
		return;
	}

	std::shared_ptr<AudioEmitter> emitter = std::make_shared<AudioEmitter>(filePath);
	emitters.emplace(name, emitter);
}

std::shared_ptr<Audio::AudioEmitter> Audio::AudioSystem::GetEmitter(const std::string & name)
{
	if (emitters.count(name) > 0)
	{
		auto s = emitters.find(name);
		return s->second;
	}
	std::cout << "Cannot find audio emitters according to key (name) " << name << std::endl;
}
