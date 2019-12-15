#pragma once
#include <vector>
#include "Point.hpp"
#include "Material.hpp"
class TexModel
{

public:
    TexModel();
    ~TexModel();

    std::vector<std::vector<Point>> getPoints();
    void renderTriangles();

private:
    std::vector<std::vector<Point>> points;
};