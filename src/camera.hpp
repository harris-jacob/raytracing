#ifndef RAYTRACING_CAMERA_H
#define RAYTRACING_CAMERA_H

#include "ray.hpp"
#include "vec3.hpp"

class camera {
  public:
    camera(point3 lookfrom, point3 lookat, vec3 vup,
           double vfov, // vertical fov in degrees
           double aspect_ratio, double aperture, double focus_dist) {
        auto theta = degrees_to_radians(vfov);
        auto h = tan(theta / 2);
        auto viewport_height = 2.0 * h;
        auto viewport_width = aspect_ratio * viewport_height;
        auto focal_length = 1.0;

        w = unit_vector(lookfrom - lookat);
        u = unit_vector(cross(vup, w));
        v = cross(w, u);

        origin = lookfrom;
        horiz = focus_dist * viewport_width * u;
        vert = focus_dist * viewport_height * v;
        lower_left_corner = origin - horiz / 2 - vert / 2 - focus_dist * w;

        lens_radius = aperture / 2;
    }

    ray get_ray(double s, double t) const {
        vec3 rd = lens_radius * random_in_unit_disk();
        vec3 offset = u * rd.x() + v * rd.y();

        return ray(origin + offset,
                   lower_left_corner + s * horiz + t * vert - origin - offset);
    }

  private:
    point3 origin;
    point3 lower_left_corner;
    vec3 horiz;
    vec3 vert;
    vec3 u, v, w;
    double lens_radius;
};

#endif