#include <iostream>

#include <SDL2/SDL.h>

#include "AudioSystem.h"

int main(int argc, char** argv)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		//std::cout << "SDL initialized." << std::endl;
	}

	SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, 0);

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
	SDL_Event e;
	while (testing)
	{
		while (SDL_PollEvent(&e))
		{
			switch (e.type)
			{
			case SDL_QUIT:
				testing = false;
				break;
			case SDL_KEYDOWN:
				switch (e.key.keysym.sym)
				{
				case SDLK_1:
					pistolEmitter->Play();
					break;
				case SDLK_2:
					spellEmitter->Play();
					break;
				case SDLK_3:
					musicEmitter->Play();
					break;
				case SDLK_RIGHT:
					spellEmitter->SetPosition(
						spellEmitter->GetPostion().x, 
						spellEmitter->GetPostion().y + 5.0f, 
						spellEmitter->GetPostion().z);
					break;
				case SDLK_LEFT:
					spellEmitter->SetPosition(
						spellEmitter->GetPostion().x,
						spellEmitter->GetPostion().y - 5.0f,
						spellEmitter->GetPostion().z);
					break;
				}
				break;
			}
		}
	}
	
	SDL_Quit();

	return 0;
}