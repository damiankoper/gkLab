#pragma once
#include "ViewEngine/IView.hpp"
#include "models/TexModel.hpp"
#include "Texture.hpp"
class TexModelView : public IView
{
public:
    TexModelView();
    ~TexModelView();
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
    TexModel texModel;
    Texture texture = Texture("src/textures/paput.tga");
    float eggRotation = 0;
};