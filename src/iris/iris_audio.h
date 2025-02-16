#pragma once
#include <raylib.h>
#include <string>


class MusicAudio {
    private:
    Music music;
    bool loop;
    float volume;

    public:
    MusicAudio() = default;
    MusicAudio(std::string path): music(LoadMusicStream(path.c_str())),
    loop(true), volume(1.0f){}

    void play();
    bool isPlaying();
    void unload();
    void stop();
    void setVolume(int vol) { SetMusicVolume(music, vol); volume = vol; }
    int getVolume() const { return volume; }

    Music getRMusic() const { return music; }

    bool doesLoop() const { return loop; }
    void setLoop(bool loop_) { loop = loop_; }

    void update();
};

class SoundAudio {
    private:
    Sound sound;
    bool loop;
    float volume;
    bool played;

    public:
    SoundAudio() = default;
    SoundAudio(std::string path): sound(LoadSound(path.c_str())),
    loop(true), played(false), volume(1.0f){}

    void play();
    void stop();
    bool isPlaying();
    void unload();
    void setVolume(float vol) {
        SetSoundVolume(sound, vol);
        volume = vol;
    }

    int getVolume() const { return volume; }

    Sound getRSound() const { return sound; }

    bool doesLoop() const { return loop; }
    void setLoop(bool loop_) { loop = loop_; }

    void update();
};
