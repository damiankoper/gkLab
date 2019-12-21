#include "models/TexModel.hpp"
#include <math.h>
#include "Color.hpp"
#include "NumericUtils.hpp"
TexModel::TexModel()
{
    points.push_back(std::vector<Point>({Point(1., 1., 0., 255, 255, 255, 1, 0),
                                         Point(5., 1., 0., 255, 255, 255, 0, 0),
                                         Point(3., 5., 0., 255, 255, 255, 0.5, 1)}));

    points.push_back(std::vector<Point>({Point(1., 1., 0., 255, 255, 255, 1, 0),
                                         Point(3., 2.5, 4., 255, 255, 255, 0.5, 1),
                                         Point(5., 1., 0., 255, 255, 255, 0, 0)}));

    points.push_back(std::vector<Point>({Point(3., 5., 0., 255, 255, 255, 1, 0),
                                         Point(5., 1., 0., 255, 255, 255, 0, 0),
                                         Point(3., 2.5, 4, 255, 255, 255, 0.5, 1)}));

    points.push_back(std::vector<Point>({Point(3., 2.5, 4, 255, 255, 255, 0.5, 1),
                                         Point(1., 1., 0., 255, 255, 255, 1, 0),
                                         Point(3., 5., 0., 255, 255, 255, 0, 0)}));
}

TexModel::~TexModel()
{
}

void TexModel::renderTriangles()
{
    glBegin(GL_TRIANGLES);
    for (auto &&triangle : points)
    {
        for (auto &&point : triangle)
        {
            point.drawWithColor();
        }
    }
    glEnd();
}
