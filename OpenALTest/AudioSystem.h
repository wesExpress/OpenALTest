#pragma once

#include <map>
#include <memory>
#include <iostream>

#include "AudioEngine/ALBackend.h"
#include "AudioEngine/ALSoundEmitter.h"
#include "AudioEngine/ALListener.h"

namespace WEngine
{
	class AudioSystem : public OpenALBackend
	{
	public:
		explicit AudioSystem();
		virtual ~AudioSystem();
	public:
		void LoadFromFile(const std::string& name, const std::string& filePath);
		std::shared_ptr<AudioEmitter> GetEmitter(const std::string& name);
	protected:
		std::map<std::string, std::shared_ptr<AudioEmitter>> emitters;
	};
}