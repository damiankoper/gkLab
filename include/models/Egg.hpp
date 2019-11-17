#pragma once
#include <vector>
#include "Point.hpp"
class Egg
{

public:
    Egg(int n = 16);
    ~Egg();

    std::vector<std::vector<Point>> getPoints();
    void renderPoints();
    void renderMesh();
    void renderTriangles();

private:
    int n;
    std::vector<std::vector<Point>> points;

    float calcX(float u, float v);
    float calcY(float u, float v);
    float calcZ(float u, float v);
};