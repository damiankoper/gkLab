#pragma once
#include <string>
class IView
{
public:
    virtual std::string getName() = 0;
    virtual void init() = 0;

    virtual void onEnter() = 0;
    virtual void render() = 0;
    virtual void idle() = 0;
    virtual void timer() = 0;
    virtual void onLeave() = 0;

    virtual ~IView(){};
};