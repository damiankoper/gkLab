#pragma once
#include <vector>
#include "Point.hpp"
class Egg
{

public:
    Egg(int n = 32);
    ~Egg();

    std::vector<std::vector<Point>> getPoints();
    void renderPoints();
    void renderMesh();
    void renderTriangles();
    void renderComplex();

private:
    int n;
    std::vector<std::vector<Point>> points;

    float calcX(float u, float v);
    float calcY(float u, float v);
    float calcZ(float u, float v);
};