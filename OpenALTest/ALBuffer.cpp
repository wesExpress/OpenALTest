#include "ALBuffer.h"

#include <iostream>

WEngine::ALBuffer::ALBuffer()
	:
	buffer(0)
{
	alGenBuffers(1, &buffer);
	std::cout << "Generated buffer." << std::endl;
}

WEngine::ALBuffer::~ALBuffer()
{
	alDeleteBuffers(1, &buffer);
	std::cout << "Deleted buffer." << std::endl;
}

ALuint WEngine::ALBuffer::GetBuffer() const
{
	return buffer;
}
