#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "ray.hpp"
#include "vec3.hpp"

class camera {
  public:
    camera() {
        auto aspect_ratio = 16.0 / 9.0;
        auto viewport_height = 2.0;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;

        origin = point3(0, 0, 0);
        horiz = vec3(viewport_width, 0.0, 0.0);
        vert = vec3(0.0, viewport_height, 0.0);
        lower_left_corner =
            origin - horiz / 2 - vert / 2 - vec3(0, 0, focal_length);
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