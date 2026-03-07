#include "renderer.h"
#include "image.h"
#include "ray.h"
#include "rand.h"
#define _USE_MATH_DEFINES
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <glm/ext/vector_double3.hpp>
#include <glm/geometric.hpp>

glm::dvec3 calculate_atmosphereic_contribution(Renderer renderer, glm::dvec3 ray_origin, glm::dvec3 ray_end) {
    return glm::dvec3(1.0);
}

glm::dvec3 calculate_reflectance(glm::vec3 position, RayData ray_data, int depth) {
    // Attempts to approximate a solution to the rendering equation using a stocahstic monte carlo method.
    // i.e. Averaging a bunch of noise.
    return glm::dvec3(0.0);
}

void render_scene(Renderer renderer, Image result) {

    uint16_t width = result.width;
    uint16_t height = result.height;

    RayData ray_data;

    glm::dvec4 ray_origin = renderer.view_matrix[3]; // Last-column is position

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++){

            double u = (x / (double)width) * 2.0 - 1.0;
            double v = -(y / (double)width) * 2.0 + 1.0; // Inverted because y on image goes from top to bottom.

            glm::dvec3 local_ray_direction = glm::normalize(glm::dvec3(1.0 / tan(renderer.fov / 2.0), u, v));
            glm::dvec3 ray_end = renderer.view_matrix * glm::dvec4(local_ray_direction * renderer.max_distance, 1.0);

            bool ray_hit = march_ray(renderer.signed_distance_function, ray_origin, ray_end, &ray_data);

            if (!ray_hit) {
                glm::vec3 sky_color = calculate_atmosphereic_contribution(renderer, ray_origin, ray_end);
                set_pixel(result, x, y, sky_color);
                continue;
            }

            set_pixel(result, x, y, glm::dvec3(glm::dot(ray_data.intersection_normal, -glm::normalize(ray_end - glm::dvec3(ray_origin)))));
        }

}
