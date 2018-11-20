#include <iostream>

#include <SDL2/SDL.h>

#include "AudioSystem.h"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//std::cout << "SDL initialized." << std::endl;
	}

	std::unique_ptr<AudioSystem> audioSystem = std::make_unique<AudioSystem>();
	std::unique_ptr<Audio::AudioListener> audioListener = std::make_unique<Audio::AudioListener>();
	audioSystem->LoadFromFile("pistol", "Sounds/pistol.wav");
	audioSystem->LoadFromFile("spell", "Sounds/foom_0_mono.wav");
	audioSystem->LoadFromFile("XYZ", "Sounds/XYZ.ogg");
	audioSystem->LoadFromFile("bounce", "Sounds/bounce.wav");

	Audio::SetDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);

	// a stereo track that does not change its volume
	// depending on distance to listener
	// tracks must be in mono for this to work, even though
	// the function calls are correct.
	std::shared_ptr<Audio::AudioEmitter> pistolEmitter = audioSystem->GetEmitter("pistol");
	pistolEmitter->EnableRelativelistener(true);
	pistolEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	pistolEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	pistolEmitter->SetMinMaxDistance(1.0f, 100.0f);
	pistolEmitter->SetGain(1.0f);
	pistolEmitter->SetLoop(false);

	// a mono track that showcases the distance attenuation
	// based on the distance model used above
	// roll off factor and reference distance determine the functional
	// form of the distance attenuation; change these values to get
	// different results
	std::shared_ptr<Audio::AudioEmitter> spellEmitter = audioSystem->GetEmitter("spell");
	spellEmitter->EnableRelativelistener(true);
	spellEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	spellEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	spellEmitter->SetMinMaxDistance(1.0f, 200.0f);
	spellEmitter->SetRollOffFactor(2.0f);
	spellEmitter->SetReferenceDistance(25.0f);
	spellEmitter->SetGain(1.0f);
	spellEmitter->SetLoop(false);

	// a stereo track of music that plays at a constant volume
	// regardless of position
	std::shared_ptr<Audio::AudioEmitter> musicEmitter = audioSystem->GetEmitter("XYZ");
	musicEmitter->EnableRelativelistener(false);
	musicEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	musicEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	musicEmitter->SetMinMaxDistance(0.0f, 0.0f);
	musicEmitter->SetGain(1.0f);
	musicEmitter->SetLoop(false);

	// for simplicity, the listener is at the origin
	audioListener->SetPosition(0.0f, 0.0f, 0.0f);

	///////////////////////////////////////
	bool testing = true;
	while (testing)
	{
		SDL_Event e;
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_q:
					std::cout << "q" << std::endl;
					//testing = false;
					break;
				case SDLK_w:
					std::cout << "w" << std::endl;
					//testing = false;
					break;
				case SDLK_e:
					std::cout << "e" << std::endl;
					//testing = false;
					break;
				}
				break;
			}
		}
	}
	
	SDL_Quit();

	return 0;
}