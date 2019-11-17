#pragma once
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
    void onLeave();
};