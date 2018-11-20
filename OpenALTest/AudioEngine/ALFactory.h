#pragma once

#include <memory>
#include <iostream>

#include "ALUtil.h"
#include "ALWaveSample.h"
#include "ALOggSample.h"

namespace WEngine
{
	class SampleFactory
	{
	public:
		static std::unique_ptr<SampleBase> CreateSample(const std::string& filePath)
		{
			if (filePath.rfind(".wav") == filePath.size() - 4)
			{
				return std::make_unique<WavSample>(filePath);
			}
			else if (filePath.rfind(".ogg") == filePath.size() - 4)
			{
				return std::make_unique<OggSample>(filePath);
			}
			std::cout << "File must be either wav or ogg. Exiting." << std::endl;
			exit(1);
		}
	};
}
