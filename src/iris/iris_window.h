#pragma once

#include <string>
#include <functional>
#include "iris_graphics.h"

typedef std::function<void(void)> InitFunc;
typedef std::function<void(float)> UpdateFunc;
typedef std::function<void(void)> DrawFunc;
typedef std::function<void(void)> UnloadFunc;

class ViewCamera;

constexpr int FlagVsynchronous = 1 << 0;
constexpr int FlagAntiAliased  = 1 << 1;
constexpr int FlagFullscreen   = 1 << 2;
constexpr int FlagMinimized    = 1 << 3;
constexpr int FlagMaximized    = 1 << 4;
constexpr int FlagNoDecoration = 1 << 5;

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
    Game(std::string title, int w, int h):
    Game(title, Vec2(w, h), FlagVsynchronous | FlagAntiAliased){}

    Game(std::string title, Vec2 size, int flags):
    title(title), width(size.x), height(size.y), fps(60), backgroundColor(RAYWHITE){
        if (flags & FlagAntiAliased) SetConfigFlags(FLAG_MSAA_4X_HINT);
        if (flags & FlagNoDecoration) SetConfigFlags(FLAG_WINDOW_UNDECORATED);
        if (flags & FlagVsynchronous) SetConfigFlags(FLAG_VSYNC_HINT);

        SetTraceLogLevel(LOG_NONE);

        InitWindow(width, height, title.c_str());
        InitAudioDevice();
        SetTargetFPS(fps);

        LogService::info("Created window.",
            "\n  :: Size: ", width, "x", height,
            "\n  :: Title: ", title);
        
        LogService::info("Set FPS to ", fps, ".");
        LogService::info("Created audio device");

        if (flags & FlagFullscreen) ToggleFullscreen();
        if (flags & FlagMaximized) MaximizeWindow();
        if (flags & FlagMinimized) MinimizeWindow();
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



class ViewCamera {
    private:
    Camera2D camera;
    friend class Game;

    float rotation;
    float zoom;
    Vec2 target;
    Vec2 offset;

    public:

    ViewCamera(): ViewCamera(Vec2(0, 0)){}
    ViewCamera(Vec2 target, float zoom = 1.0f, float rot = 0.0f, Vec2 offset = Vec2(0.0f, 0.0f)):
    target(target), offset(offset), rotation(rot), zoom(zoom), camera{0}{
        camera.target = target;
        camera.offset = offset;
        camera.rotation = rotation;
        camera.zoom = zoom;
    }

    float getRotation() const { return rotation; }
    void setRotation(float rotation_) { rotation = rotation_; camera.rotation = rotation; }

    float getZoom() const { return zoom; }
    void setZoom(float zoom_) { zoom = zoom_; camera.zoom = zoom; }

    Vec2 getTarget() const { return target; }
    void setTarget(const Vec2 &target_) { target = target_; camera.target = target; }

    Vec2 getOffset() const { return offset; }
    void setOffset(const Vec2 &offset_) { offset = offset_; camera.offset = offset; }

    void enterCameraMode();
    void exitCameraMode();
};