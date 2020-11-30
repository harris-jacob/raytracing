#ifndef RAYTRACING_HITTABLE_H
#define RAY_TRACING_HITTABLE_H

#include "ray.hpp"

struct hit_record {
    point3 p;
    vec3 normal;
    double t;
};

class hittable {
  public:
    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const = 0;
};

#endif