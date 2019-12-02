#pragma once
#include <vector>
#include "Point.hpp"
#include "Material.hpp"
class Egg
{

public:
    Egg(int n = 256);
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

    float calcNX(float u, float v);
    float calcNY(float u, float v);
    float calcNZ(float u, float v);

    float calcNXu(float u, float v);
    float calcNYu(float u, float v);
    float calcNZu(float u, float v);
    float calcNXv(float u, float v);
    float calcNYv(float u, float v);
    float calcNZv(float u, float v);

    Material material;
};