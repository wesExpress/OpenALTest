#include "ALWaveSample.h"

#include <iostream>
#include <fstream>

Audio::WavSample::WavSample()
	:
	channels(0),
	sampleRate(0),
	duration(0.0f),
	sizeStream(0.0f)
{
	//std::cout << "Constructed ALWaveSample" << std::endl;
}

Audio::WavSample::WavSample(const std::string & filePath)
{
	WavHeader header;

	const size_t WAV_BIT_DEPTH = 16;
	std::ifstream file(filePath, std::ifstream::binary | std::ifstream::in);
	if (!file.is_open())
	{
		std::cout << "ERROR: Cannot open audio file " << filePath << std::endl;
	}
	file.read(reinterpret_cast<char*>(&header), sizeof(header));

	bool success = true;
	// check the header
	if (memcmp(header.id, "RIFF", 4) != 0)
	{
		std::cout << "ERROR: Problem with WAV file header: Bad RIFF header." << std::endl;
		success = false;
	}
	// check the format
	if (memcmp(header.waveFmt, "WAVfmt ", 8) != 0 && memcmp(header.data, "data", 4) != 0)
	{
		std::cout << "ERROR: This file is not WAV format!" << std::endl;
		success = false;
	}
	// check bit depth
	if (header.format != WAV_BIT_DEPTH)
	{
		std::cout << "ERROR: This file is not 16 bit wav format!" << std::endl;
		success = false;
	}

	if (success)
	{
		channels = header.channels;
		sampleRate = header.sampleRate;

		wave.resize(static_cast<unsigned int>(header.bytesInData));
		file.read(wave.data(), static_cast<long>(wave.size()));
		sizeStream = (float)wave.size();

		//duration = header.totalLength / (header.channels * header.sampleRate * (header.bitsPerSample / 8.0f))*1.0f;
		//std::cout << "---WAV Audio Info---" << std::endl;
		//std::cout << "Sampling rate : " << sampleRate / 1000.0f << " kHz" << std::endl;
		//std::cout << "Channel       : " << channels << " Channel(s)." << std::endl;
		//std::cout << "Size Stream   : " << sizeStream / (1024 * 1024) << " MB." << std::endl;
		//std::cout << "Duration      : " << duration << " ms." << std::endl;
		//std::cout << "Bit depth     : " << header.format << std::endl;
		//std::cout << "File is       : " << (header.pcm == 1 ? "Uncompressed" : "Compressed") << std::endl;

		ALuint channelFormat = GetFormatNumChannels(static_cast<ALuint>(channels));

		alBufferData(buffer.GetBuffer(), static_cast<ALenum>(channelFormat), wave.data(), 
			static_cast<ALsizei>(wave.size()), sampleRate);

		if (AL_NO_ERROR != alGetError)
		{
			//std::cout << "OpenAL error in wave sample." << std::endl;
		}
	}
}

Audio::WavSample::~WavSample()
{
	//std::cout << "Destroyed WAV sample." << std::endl;
}
