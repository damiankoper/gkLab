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
    glutKeyboardFunc([](unsigned char key, int x, int y) { ViewEngine::g().currentView->onKey(key, x, y); });
    //glutIdleFunc([]() { ViewEngine::g().currentView->idle(); });

    currentView->onEnter();
}

void ViewEngine::render()
{
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

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