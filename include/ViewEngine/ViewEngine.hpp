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

private:
    ViewEngine();
    ViewEngine(const ViewEngine &);

    std::map<std::string, IView *> views;
    IView *currentView;
};