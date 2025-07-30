#pragma once

#include <string>
#include <functional>
#include "iris_graphics.h"

typedef std::function<void(void)> InitFunc;
typedef std::function<void(float)> UpdateFunc;
typedef std::function<void(void)> DrawFunc;
typedef std::function<void(void)> UnloadFunc;


class PreinitConfig {
    private:
    bool vsync;
    bool antiAlias;
    bool fullscreen;
    bool minimized;
    bool maximized;
    bool decorationless;

public:
    
    PreinitConfig(): vsync(true), antiAlias(true), fullscreen(false), maximized(false),
    decorationless(false), minimized(false){}

    bool getVsync() const { return vsync; }
    void setVsync(bool vsync_) { vsync = vsync_; }

    bool getAntiAlias() const { return antiAlias; }
    void setAntiAlias(bool antiAlias_) { antiAlias = antiAlias_; }

    bool getFullscreen() const { return fullscreen; }
    void setFullscreen(bool fullscreen_) { fullscreen = fullscreen_; }

    bool getMinimized() const { return minimized; }
    void setMinimized(bool minimized_) { minimized = minimized_; }

    bool getMaximized() const { return maximized; }
    void setMaximized(bool maximized_) { maximized = maximized_; }

    bool getDecorationless() const { return decorationless; }
    void setDecorationless(bool decorationless_) { decorationless = decorationless_; }
};



class Game {
    private:
    std::string title;
    int width;
    int height;
    int fps;
    RGBAColor backgroundColor;

    public:

    Game(): Game("Game", 640, 480){}
    Game(std::string title): Game(title, 640, 480){}
    Game(std::string title, int width, int height): Game(title, Vec2(width, height), PreinitConfig()){}

    Game(std::string title, Vec2 size, PreinitConfig config):
    title(title), width(size.x), height(size.y), fps(60), backgroundColor(RAYWHITE){
        if (config.getAntiAlias()) SetConfigFlags(FLAG_MSAA_4X_HINT);
        if (config.getDecorationless()) SetConfigFlags(FLAG_WINDOW_UNDECORATED);
        if (config.getVsync()) SetConfigFlags(FLAG_VSYNC_HINT);

        SetTraceLogLevel(LOG_NONE);

        InitWindow(width, height, title.c_str());
        InitAudioDevice();
        SetTargetFPS(fps);

        LogService::info("Created window.",
            "\n  :: Size: ", width, "x", height,
            "\n  :: Title: ", title);
        
        LogService::info("Set FPS to ", fps, ".");
        LogService::info("Created audio device");

        if (config.getFullscreen()) ToggleFullscreen();
        if (config.getMaximized()) MaximizeWindow();
        if (config.getMinimized()) MinimizeWindow();
    }

    std::string getTitle() const { return title; }

    int getWidth() const { return width; }

    int getHeight() const { return height; }

    int getFps() const { return fps; }
    void setFps(int fps_) { fps = fps_; SetTargetFPS(fps); }


    template <typename InitF, typename DrawF, typename UpdateF, typename UnloadF>
    void start(InitF&& initFunc = InitFunc(), DrawF &&drawFunc = DrawFunc(), UpdateF&& updateFunc = UpdateFunc(), UnloadF&& unloadFunc = UnloadFunc()){
        if (initFunc) initFunc();

        while (!WindowShouldClose()){
            if (updateFunc) updateFunc(GetFrameTime());

            BeginDrawing();
            ClearBackground(backgroundColor);
            if (drawFunc) drawFunc();
            EndDrawing();
        }

        if (unloadFunc) unloadFunc();

        LogService::info("Unloading...");
        
        TextureService::unloadEverything();

        CloseAudioDevice();
        LogService::info("Closed audio device.");
        CloseWindow();
        LogService::info("Closed window.");
    }


    void start(){
        start([](){}, [](){}, [](float dt){}, [](){});
    }

    RGBAColor getBackgroundColor() const { return backgroundColor; }
    void setBackgroundColor(const RGBAColor &backgroundColor_) { backgroundColor = backgroundColor_; }
};