#pragma once

#include <cstdint>
#include <string>
#include <vector>

#include "ALBuffer.h"
#include "ALSoundBase.h"
#include "ALUtil.h"

namespace Audio
{
	struct WavHeader
	{
		WavHeader() {}

		char id[4];              // Should ALWAYS contain "RIFF"
		int32_t totalLength;     // Total file length - 8
		char waveFmt[8];         // Should be "WAVfmt "
		int32_t format;          // 16 for PCM format
		int16_t pcm;             // 1 for PCM format
		int16_t channels;        // number of channels
		int32_t sampleRate;      // sampling frequency
		int32_t bytesPerSecond;  // Estimating RAM allocation
		int16_t bytesBycapture;
		int16_t bitsPerSample;   // Byte depth: 8 bits = 8, e.g.
		char data[4];            // Should ALWAYS contain "data"
		int32_t bytesInData;
	};

	class WavSample : public SampleBase
	{
	public:
		WavSample();
		WavSample(const std::string& filePath);
		virtual ~WavSample();
	public:
		float GetDuration() const { return duration; }
		int NumberOfChannels() const { return channels; }
		ALuint GetBuffer() const { return buffer.GetBuffer(); }
	private:
		std::string file;
		int16_t channels;
		int32_t sampleRate;
		float duration;
		float sizeStream;
	protected:
		std::vector<char> wave;
		ALBuffer buffer;
	};
}
