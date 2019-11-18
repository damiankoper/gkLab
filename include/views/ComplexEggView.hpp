#pragma once
#include "ViewEngine/IView.hpp"
#include "models/Egg.hpp"
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
    void onLeave();

private:
    Egg egg;
    float eggRotation = 0;
};