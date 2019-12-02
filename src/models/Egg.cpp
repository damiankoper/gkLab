#include "models/Egg.hpp"
#include <math.h>
#include "Color.hpp"
#include "NumericUtils.hpp"
Egg::Egg(int n)
{
    if (n % 2 == 1)
        n++;
    this->n = n;
    points.erase(points.begin(), points.end());
    float step = 1. / n;
    for (size_t u = 0; u <= n; u++)
    {
        std::vector<Point> vec;
        for (size_t v = 0; v <= n; v++)
        {
            Point p = Point(
                calcX(u * step, v * step),
                calcY(u * step, v * step),
                calcZ(u * step, v * step),
                NumericUtils::randByte(),
                NumericUtils::randByte(),
                NumericUtils::randByte());
            float nx = calcNX(u * step, v * step);
            float ny = calcNY(u * step, v * step);
            float nz = calcNZ(u * step, v * step);
            float length = sqrt(nx * nx + ny * ny + nz * nz);
            if (u >= n / 2)
                length *= -1;
            nx /= length;
            ny /= length;
            nz /= length;
            p.nx = nx;
            p.ny = ny;
            p.nz = nz;
            vec.push_back(p);
        }
        points.push_back(vec);
    }
    for (size_t u = 0; u <= n / 2; u++)
    {
        for (size_t v = 0; v <= n; v++)
        {
            points[u][0].color = points[u][n].color = points[n - u][0].color = points[n - u][n].color;
        }
    }
    if (n > 2)
    {
        Color color = points[0][0].color;
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

float Egg::calcNX(float u, float v)
{
    return calcNYu(u, v) * calcNZv(u, v) - calcNZu(u, v) * calcNYv(u, v);
}
float Egg::calcNY(float u, float v)
{
    return calcNZu(u, v) * calcNXv(u, v) - calcNXu(u, v) * calcNZv(u, v);
}
float Egg::calcNZ(float u, float v)
{
    return calcNXu(u, v) * calcNYv(u, v) - calcNYu(u, v) * calcNXv(u, v);
}
float Egg::calcNXu(float u, float v)
{
    float PIV = M_PI * v;
    return (-450 * pow(u, 4) + 900 * pow(u, 3) - 810 * pow(u, 2) + 360 * u - 45) * cos(PIV);
}
float Egg::calcNYu(float u, float v)
{
    return 640 * pow(u, 3), -960 * pow(u, 2) + 320 * u;
}
float Egg::calcNZu(float u, float v)
{
    float PIV = M_PI * v;
    return (-450 * pow(u, 4) + 900 * pow(u, 3) - 810 * pow(u, 2) + 360 * u - 45) * sin(PIV);
}
float Egg::calcNXv(float u, float v)
{
    float PIV = M_PI * v;
    return M_PI * (90 * pow(u, 5) - 225 * pow(u, 4) + 270 * pow(u, 3) - 180 * pow(u, 2) + 45 * u) * sin(PIV);
}
float Egg::calcNYv(float u, float v)
{
    return 0;
}
float Egg::calcNZv(float u, float v)
{
    float PIV = M_PI * v;
    return -M_PI * (90 * pow(u, 5) - 225 * pow(u, 4) + 270 * pow(u, 3) - 180 * pow(u, 2) + 45 * u) * cos(PIV);
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

    for (size_t i = n / 2; i < n; i++)
    {
        for (size_t j = 0; j < n - 1; j++)
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
    for (size_t i = 1; i < n / 2 + 1; i++)
    {
        for (size_t j = 0; j < n - 1; j++)
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

void Egg::renderTriangles()
{
    material.apply();
    glBegin(GL_TRIANGLES);
    for (size_t i = 1; i < n; i++)
    {
        for (size_t j = 1; j < n; j++)
        {
            points[i][j].drawWithColor();
            points[i][j - 1].drawWithColor();
            points[i - 1][j].drawWithColor();

            points[i - 1][j - 1].drawWithColor();
            points[i - 1][j].drawWithColor();
            points[i][j - 1].drawWithColor();
            if (j == 1)
            {
                points[n - i][0].drawWithColor();
                points[i][n - 1].drawWithColor();
                points[i - 1][n - 1].drawWithColor();

                if (n - i + 1 < n)
                {
                    points[n - i][0].drawWithColor();
                    points[n - i + 1][0].drawWithColor();
                    points[i - 1][n - 1].drawWithColor();
                }
            }
        }
    }
    for (size_t j = 1; j < n; j++)
    {
        points[n - 1][j].drawWithColor();
        points[n - 1][j - 1].drawWithColor();
        points[0][0].drawWithColor();
    }

    points[n - 1][n - 1].drawWithColor();
    points[1][0].drawWithColor();
    points[0][0].drawWithColor();

    glEnd();
}

void Egg::renderComplex()
{
    material.apply();
    for (size_t i = 0; i < n; i++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (size_t j = 0; j <= n; j++)
        {
            points[i][j].drawWithColor();
            points[i + 1][j].drawWithColor();
        }
        glEnd();
    }
}