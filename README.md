# OpenALTest
Learning how to use OpenAL

Simple audio engine that uses OpenAL. Sounds can be loaded as either WAV or OGG. Currently have an AudioSystem class that contains all the sounds, and other objects contain references to each of the sounds. 

Emitters are able to have distance attenuation relative to the listener, **BUT THE FILE MUST BE IN MONO**. Simply use Audacity to save any stereo file you have as mono.

Currently sounds are simply loaded in as-is, but this is terrible memory wise. Will need to read in files into multiple buffers to prevent memory getting out of hand with large audio files.

## TO DO
-need to have a better way of playing sounds repeatedly. Currently only plays when a sound stops, but this is not the solution.</br>
-need to be able to take care of large sound files and play multiple buffers instead of loading into one buffer
