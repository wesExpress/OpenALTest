#pragma once

#include <string>

#include "ALBuffer.h"
#include "ALSoundBase.h"
#include "ALUtil.h"

namespace WEngine
{
	class OggSample : public SampleBase
	{
	public:
		OggSample();
		OggSample(const std::string& filePath);
		virtual ~OggSample();
	public:
		float GetDuration() const { return duration; }
		int NumberOfChannels() const { return channels; }
		ALuint GetBuffer() const { return buffer.GetBuffer(); }
	private:
		int channels;
		unsigned int sampleRate;
		float duration;
		int error;
	protected:
		ALBuffer buffer;
	};
}