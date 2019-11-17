#pragma once
#include "ViewEngine/IView.hpp"
#include "models/Egg.hpp"
class DotEggView : public IView
{
public:
    DotEggView();
    ~DotEggView();
    std::string getName();
    void init();
    void onEnter();
    void render();
    void idle();
    void timer();
    void onLeave();

private:
    Egg egg;
    float eggRotation = 0;
};