#include "ALSource.h"
#include <iostream>

WEngine::ALSource::ALSource()
	:
	source(0)
{
	alGenSources(1, &source);
	std::cout << "Generated source." << std::endl;
}

WEngine::ALSource::~ALSource()
{
	alDeleteSources(1, &source);
	std::cout << "Deleted source." << std::endl;
}

ALuint WEngine::ALSource::GetSource()
{
	return source;
}
