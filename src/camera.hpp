#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "ray.hpp"
#include "vec3.hpp"

class camera {
  public:
    camera(point3 lookfrom, point3 lookat, vec3 vup,
           double vfov, // vertical fov in degrees
           double aspect_ratio) {
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta / 2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;

        auto w = unit_vector(lookfrom - lookat);
        auto u = unit_vector(cross(vup, w));
        auto v = cross(w, u);

        origin = lookfrom;
        horiz = viewport_width * u;
        vert = viewport_height * v;
        vert = vec3(0.0, viewport_height, 0.0);
        lower_left_corner = origin - horiz / 2 - vert / 2 - w;
    }

    ray get_ray(double u, double v) const {
        return ray(origin, lower_left_corner + u * horiz + v * vert - origin);
    }

  private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horiz;
    vec3 vert;
};

#endif