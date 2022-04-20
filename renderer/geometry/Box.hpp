#ifndef RENDERER_GEOMETRY_BOX_H_
#define RENDERER_GEOMETRY_BOX_H_

#include <vector>

#include "Shape.hpp"
#include "Triangle.hpp"
#include "Vector3.hpp"

class Box : public Shape
{
public:
    Box();
    Box(const Vec3d &min, const Vec3d &max);
    virtual ~Box() {}

    virtual bool closestHit(const Ray &r, HitStruct &hit) const;

private:
    Vec3d m_min, m_max;
    std::vector<Triangle> tris;
};

#endif