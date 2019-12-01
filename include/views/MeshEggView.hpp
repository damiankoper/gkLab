#pragma once
#include "ViewEngine/IView.hpp"
#include "models/Egg.hpp"
class MeshEggView : public IView
{
public:
    MeshEggView();
    ~MeshEggView();
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
};