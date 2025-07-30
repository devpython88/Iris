#include "iris_audio.h"


void MusicAudio::update(){
    music.looping = loop;
    UpdateMusicStream(music);
}

void SoundAudio::update(){
    if (played && !IsSoundPlaying(sound) && loop){
        play();
    }
}

void SoundAudio::play()
{
    PlaySound(sound);
    played = true;
}

bool SoundAudio::isPlaying()
{
    return IsSoundPlaying(sound);
}

void SoundAudio::unload()
{
    if (IsSoundValid(sound)) UnloadSound(sound);
}

void MusicAudio::play()
{
    PlayMusicStream(music);
}

bool MusicAudio::isPlaying()
{
    return IsMusicStreamPlaying(music);
}

void MusicAudio::unload()
{
    if (IsMusicValid(music)) UnloadMusicStream(music);
}

void MusicAudio::stop()
{
    StopMusicStream(music);
}

void SoundAudio::stop()
{
    StopSound(sound);
}
