#include "ALSource.h"
#include <iostream>

Audio::ALSource::ALSource()
	:
	source(0)
{
	alGenSources(1, &source);
	//std::cout << "Generated source." << std::endl;
}

Audio::ALSource::~ALSource()
{
	alDeleteSources(1, &source);
	//std::cout << "Deleted source." << std::endl;
}

ALuint Audio::ALSource::GetSource()
{
	return source;
}
