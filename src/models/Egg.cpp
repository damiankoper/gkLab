#include "models/Egg.hpp"
#include <math.h>
#include "NumericUtils.hpp"
Egg::Egg(int n)
{
    if (n % 2 == 1)
        n++;
    this->n = n;
    points.erase(points.begin(), points.end());
    float step = 1. / n;
    for (size_t u = 0; u < n; u++)
    {
        std::vector<Point> vec;
        for (size_t v = 0; v < n; v++)
        {
            Point p = Point(
                calcX(u * step, v * step),
                calcY(u * step, v * step),
                calcZ(u * step, v * step),
                NumericUtils::randByte(),
                NumericUtils::randByte(),
                NumericUtils::randByte());
            vec.push_back(p);
        }
        points.push_back(vec);
    }
    if (n > 2)
    {
        Point::Color color = points[0][0].color;
        for (auto &&point : points[0])
        {
            point.color = color;
        }
        color = points[points.size() / 2 - 1][0].color;

        for (auto &&point : points[points.size() / 2])
        {
            point.color = color;
        }
    }
}

Egg::~Egg()
{
}

float Egg::calcX(float u, float v)
{
    float PIV = M_PI * v;
    return ((-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * cos(PIV));
}
float Egg::calcY(float u, float v)
{
    return (160 * pow(u, 4) - 320 * pow(u, 3) + 160 * pow(u, 2));
}
float Egg::calcZ(float u, float v)
{
    float PIV = M_PI * v;
    return ((-90 * pow(u, 5) + 225 * pow(u, 4) - 270 * pow(u, 3) + 180 * pow(u, 2) - 45 * u) * sin(PIV));
}

std::vector<std::vector<Point>> Egg::getPoints()
{
    return points;
}

void Egg::renderPoints()
{
    glBegin(GL_POINTS);
    for (auto &&row : points)
    {
        for (auto &&point : row)
        {
            point.drawWithColor();
        }
    }
    glEnd();
}

void Egg::renderMesh()
{
    glBegin(GL_LINES);
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n - 1; j++)
        {
            points[i][j].drawWithColor();
            points[i][j + 1].drawWithColor();
        }
        if (n - i != n)
        {
            points[i][0].drawWithColor();
            points[n - i][n - 1].drawWithColor();
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (i == n - 1)
            {
                points[i][j].drawWithColor();
                points[0][0].drawWithColor();
            }
            else
            {
                points[i][j].drawWithColor();
                points[i + 1][j].drawWithColor();
            }
        }
    }

    for (int i = n / 2; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (i == n - 1)
            {
                points[i][j].drawWithColor();
                points[0][0].drawWithColor();
            }
            else
            {
                points[i][j].drawWithColor();
                points[i + 1][j + 1].drawWithColor();
            }
            if (n - i != n)
            {
                points[i][0].drawWithColor();
                points[n - i + 1][n - 1].drawWithColor();
            }
        }
    }
    points[0][0].drawWithColor();
    points[1][n - 1].drawWithColor();

    points[0][0].drawWithColor();
    points[n - 1][n - 1].drawWithColor();
    for (int i = 1; i < n / 2 + 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            points[i][j].drawWithColor();
            points[i - 1][j + 1].drawWithColor();
            if (n - i != n)
            {
                points[i][0].drawWithColor();
                points[n - i - 1][n - 1].drawWithColor();
            }
        }
    }

    glEnd();
}