#include "AudioSystem.h"

WEngine::AudioSystem::AudioSystem()
{
}

WEngine::AudioSystem::~AudioSystem()
{
}

void WEngine::AudioSystem::LoadFromFile(const std::string & name, const std::string & filePath)
{
	if (filePath.empty())
	{
		std::cout << "File path is empty!" << std::endl;
		return;
	}

	std::shared_ptr<AudioEmitter> emitter = std::make_shared<AudioEmitter>(filePath);
	emitters.emplace(name, emitter);
}

std::shared_ptr<WEngine::AudioEmitter> WEngine::AudioSystem::GetEmitter(const std::string & name)
{
	if (emitters.count(name) > 0)
	{
		auto s = emitters.find(name);
		return s->second;
	}
	std::cout << "Cannot find audio emitters according to key (name) " << name << std::endl;
}
