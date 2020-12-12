#ifndef RAY_TRACING_HITTABLE_H
#define RAY_TRACING_HITTABLE_H

#include "ray.hpp"

// Storage for data relating to points our ray collides with
struct hit_record {
    point3 p;
    vec3 normal;
    double t;
    bool front_face; // have we hit from the outside or inside of the surface.

    inline void set_face_normal(const ray& ray, const vec3& outward_normal) {
        front_face = dot(ray.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};

class hittable {
  public:
    virtual bool hit(const ray& r, double t_min, double t_max,
                     hit_record& rec) const = 0;
};

#endif