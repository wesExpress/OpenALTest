#include "ALBuffer.h"

#include <iostream>

Audio::ALBuffer::ALBuffer()
	:
	buffer(0)
{
	alGenBuffers(1, &buffer);
	//std::cout << "Generated buffer." << std::endl;
}

Audio::ALBuffer::~ALBuffer()
{
	alDeleteBuffers(1, &buffer);
	//std::cout << "Deleted buffer." << std::endl;
}

ALuint Audio::ALBuffer::GetBuffer() const
{
	return buffer;
}
