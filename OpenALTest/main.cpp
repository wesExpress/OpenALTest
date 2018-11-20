#include <iostream>

#include "AudioSystem.h"

int main()
{
	std::unique_ptr<Audio::AudioSystem> audioSystem = std::make_unique<Audio::AudioSystem>();
	std::unique_ptr<Audio::AudioListener> audioListener = std::make_unique<Audio::AudioListener>();
	audioSystem->LoadFromFile("pistol", "Sounds/pistol.wav");
	audioSystem->LoadFromFile("spell", "Sounds/foom_0_mono.wav");
	audioSystem->LoadFromFile("XYZ", "Sounds/XYZ.ogg");
	audioSystem->LoadFromFile("bounce", "Sounds/bounce.wav");

	Audio::SetDistanceModel(AL_INVERSE_DISTANCE_CLAMPED);

	std::shared_ptr<Audio::AudioEmitter> pistolEmitter = audioSystem->GetEmitter("pistol");
	pistolEmitter->EnableRelativelistener(true);
	pistolEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	pistolEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	pistolEmitter->SetMinMaxDistance(1.0f, 100.0f);
	pistolEmitter->SetGain(1.0f);
	pistolEmitter->SetLoop(false);

	std::shared_ptr<Audio::AudioEmitter> spellEmitter = audioSystem->GetEmitter("spell");
	spellEmitter->EnableRelativelistener(true);
	spellEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	spellEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	spellEmitter->SetMinMaxDistance(1.0f, 200.0f);
	spellEmitter->SetRollOffFactor(2.0f);
	spellEmitter->SetReferenceDistance(25.0f);
	spellEmitter->SetGain(1.0f);
	spellEmitter->SetLoop(false);

	std::shared_ptr<Audio::AudioEmitter> musicEmitter = audioSystem->GetEmitter("XYZ");
	musicEmitter->EnableRelativelistener(false);
	musicEmitter->SetPosition(0.0f, 0.0f, 0.0f);
	musicEmitter->SetDirection(0.0f, 0.0f, 0.0f);
	musicEmitter->SetMinMaxDistance(0.0f, 0.0f);
	musicEmitter->SetGain(1.0f);
	musicEmitter->SetLoop(false);

	audioListener->SetPosition(0.0f, 0.0f, 0.0f);

	///////////////////////////////////////
	bool testing = true;
	int tmp;
	while (testing)
	{
		std::cin >> tmp;
		switch (tmp)
		{
		case 1:
			pistolEmitter->Play();
			break;
		case 2:
			pistolEmitter->SetPosition(0.0f, pistolEmitter->GetPostion().y + 10.0f, 0.0f);
			break;
		case 4:
			spellEmitter->Play();
			break;
		case 5:
			spellEmitter->SetPosition(0.0f, spellEmitter->GetPostion().y + 10.0f, 0.0f);
			break;
		case 8:
			musicEmitter->Play();
			break;
		case 9:
			testing = false;
			break;
		}
	}

	return 0;
}