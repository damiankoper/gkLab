#include "ViewEngine/ViewEngine.hpp"
#include <GL/glut.h>

ViewEngine::ViewEngine()
{
    timer();
}

ViewEngine::~ViewEngine()
{
}

void ViewEngine::add(IView *view)
{
    views[view->getName()] = view;
    view->init();
    if (currentView == nullptr)
        setCurrent(view->getName());
}

void ViewEngine::setCurrent(std::string name)
{
    if (currentView != nullptr)
        currentView->onLeave();

    currentView = views[name];

    glutDisplayFunc([]() { ViewEngine::g().render(); });
    //glutIdleFunc([]() { ViewEngine::g().currentView->idle(); });

    currentView->onEnter();
}

void ViewEngine::render()
{
    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    currentView->render();

    glFlush();
}

void ViewEngine::timer()
{
    glutTimerFunc(1000 / 60,
                  [](int time) {
                      ViewEngine::g().currentView->timer();
                      ViewEngine::g().timer();
                  },
                  0);
}