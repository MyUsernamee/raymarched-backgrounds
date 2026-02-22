#include "renderer.h"
#include "image.h"
#include <cmath>
#include <cstdio>
#include <cstdlib>

void render_scene(Renderer renderer, Image result) {

    uint16_t width = result.width;
    uint16_t height = result.height;

    RayData ray_data;

    glm::vec4 ray_origin = renderer.view_matrix[3]; // Last-column is position

    for (int x = 0; x < width; x++)
        for (int y = 0; y < height; y++){

            float u = (x / (float)width) * 2.0 - 1.0;
            float v = -(y / (float)width) * 2.0 + 1.0; // Inverted because y on image goes from top to bottom.

            glm::vec3 local_ray_direction = glm::normalize(glm::vec3(1.0 / tan(renderer.fov / 2.0), u, v));
            glm::vec3 ray_end = renderer.view_matrix * glm::vec4(local_ray_direction * renderer.max_distance, 1.0);

            bool ray_hit = march_ray(renderer.signed_distance_function, ray_origin, ray_end, &ray_data);

            if (!ray_hit) {
                set_pixel(result, x, y, glm::vec3(ray_end.y / renderer.max_distance, ray_end.z / renderer.max_distance, ray_end.x / renderer.max_distance)); // TODO: Replace this with something more interesting.
                continue;
            }

            set_pixel(result, x, y, glm::vec3(glm::dot(ray_data.intersection_normal, glm::vec3(0.0, 0.0, 1.0))));
        }

}
