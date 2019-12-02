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
    glutKeyboardFunc([](unsigned char key, int x, int y) {
        if (!ViewEngine::g().keyboardRouter(key))
            ViewEngine::g().currentView->onKey(key, x, y);
    });
    glutMouseFunc([](int btn, int state, int x, int y) {
        ViewEngine::g().currentView->onMouse(btn, state, x, y);
    });
    glutMotionFunc([](GLsizei x, GLsizei y) {
        ViewEngine::g().currentView->onMotion(x, y);
    });

    currentView->onEnter();
}

void ViewEngine::render()
{
    glEnable(GL_DEPTH_TEST);
    glDepthMask(GL_TRUE);
    glDepthFunc(GL_LEQUAL);
    glDepthRange(0.0f, 2.0f);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_LIGHTING);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClearDepth(1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    currentView->render();

    glFlush();
    glutSwapBuffers();
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

void ViewEngine::setKeyboardRouter(std::function<bool(unsigned char key)> fn)
{
    keyboardRouter = fn;
}