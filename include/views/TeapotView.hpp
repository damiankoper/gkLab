#pragma once
#include <Point.hpp>
#include <Light.hpp>
#include <Material.hpp>
#include "ViewEngine/IView.hpp"
class TeapotView : public IView
{
public:
    TeapotView();
    ~TeapotView();
    std::string getName();
    void init();
    void onEnter();
    void render();
    void idle();
    void timer();
    void onKey(unsigned char key, int x, int y);
    void onMouse(int btn, int state, int x, int y);
    void onMotion(GLsizei x, GLsizei y);
    void onLeave();

private:
    bool leftPressed = false;
    bool rightPressed = false;
    float lastLeftPos[2] = {0, 0};
    float lastRightPos[2] = {0, 0};
    float scale = 1.0;
    float xRotate = 0;
    float zRotate = 0;
    bool camMode = false;
    bool lightMode = false;
    Point eye = Point(10, 0, 0, 255, 255, 255);
    Point center = Point(0, 0, 0, 255, 255, 255);
    float rDistance = 10.;
    float azimuth = 0;
    float elevation = 0;
    enum Mode
    {
        model = 1,
        cam,
        light
    };
    Mode mode = Mode::model;
    Light light1 = Light();
    Light light2 = Light();
    Material teapotMaterial = Material();
};