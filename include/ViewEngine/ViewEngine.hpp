#pragma once
#include "ViewEngine/IView.hpp"
#include <functional>
#include <map>
class ViewEngine
{
public:
    ~ViewEngine();
    static ViewEngine &g()
    {
        static ViewEngine singleton;
        return singleton;
    }

    void add(IView *view);
    void setCurrent(std::string name);
    void render();
    void timer();

    void setKeyboardRouter(std::function<bool(unsigned char key)> fn);
    std::function<bool(unsigned char key)> keyboardRouter;

private:
    ViewEngine();
    ViewEngine(const ViewEngine &);

    std::map<std::string, IView *> views;
    IView *currentView;
};