#pragma once
#include "ViewEngine/IView.hpp"
#include "models/Egg.hpp"
#include "Light.hpp"
#include "Texture.hpp"
class ComplexEggView : public IView
{
public:
    ComplexEggView();
    ~ComplexEggView();
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
    Egg egg;
    float eggRotation = 0;
    Texture texture = Texture("src/textures/D5_t.tga");

    Light light1 = Light();
    Light light2 = Light();
};