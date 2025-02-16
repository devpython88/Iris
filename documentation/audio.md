All of this is in `iris/iris_audio.h`


# Normal sounds

To load a sound, you can use `SoundAudio`

Constructor: `SoundAudio(std::string path)`

It has properties for `loop`, and `volume`

Functions:
- `void play();`: Plays the sound
- `void stop();`: Stops the sound
- `bool isPlaying();`: Tells if the sound is playing
- `void unload();`: Unloads the sound
- `void setVolume(float vol);`: Sets the volume
- `int getVolume();`: Gets the volume
- `bool getLoop();`: Gets if it loops
- `void setLoop(bool loop_);`: Sets if it should loop
- `void update();`: Updates the sound

# Music

The `MusicAudio` class has the same methods and constructor as `SoundAudio` the difference is that `MusicAudio` accepts `ogg` and `mp3`
