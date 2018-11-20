#include "ALOggSample.h"

#include <iostream>
#include <stb_vorbis.h>

Audio::OggSample::OggSample()
	:
	channels(0),
	sampleRate(0),
	error(0)
{
}

Audio::OggSample::OggSample(const std::string & filePath)
	:
	channels(0),
	sampleRate(0),
	error(0)
{
	stb_vorbis *vorbis = stb_vorbis_open_filename(filePath.c_str(), &error, nullptr);
	if (!vorbis)
	{
		std::cout << "Bad initialization of stb_vorbis!" << std::endl;
	}

	stb_vorbis_info info = stb_vorbis_get_info(vorbis);
	sampleRate = info.sample_rate;
	duration = stb_vorbis_stream_length_in_seconds(vorbis);
	stb_vorbis_close(vorbis);

	short* data = nullptr;
	int samples = 0;
	int sample_rate = 0;
	samples = stb_vorbis_decode_filename(filePath.c_str(), &channels, &sample_rate, &data);

	ALuint format = GetFormatNumChannels(static_cast<ALuint>(channels));

	std::cout << "---Ogg Audio Info---" << std::endl;
	std::cout << "Sampling Rate : " << sample_rate / 1000.0 << " kHz." << std::endl;
	std::cout << "Channel       : " << channels << " Channel(s)." << std::endl;
	std::cout << "Duration      : " << duration << " ms." << std::endl;

	alBufferData(buffer.GetBuffer(), static_cast<ALenum>(format), data, 
		static_cast<ALsizei>(sizeof(short)*samples*channels), static_cast<ALsizei>(sampleRate));
	free(data);

	if (AL_NO_ERROR != alGetError)
	{
		std::cout << "OpenAL error in ogg sample." << std::endl;
	}
}

Audio::OggSample::~OggSample()
{
	std::cout << "Destroyed Ogg sample." << std::endl;
}
