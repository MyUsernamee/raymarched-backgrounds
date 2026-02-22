#include "ray.h"
#include "consts.h"
#include <cstdio>
#include <glm/geometric.hpp>

glm::vec3 approximate_gradient(sdf_func sdf, glm::vec3 position) {
    // TODO: It would probably be better to use a bi-direction apporoximation.
    float delta_x = sdf(position + glm::vec3(EPSILON, 0.0, 0.0)).distance - sdf(position).distance;
    float delta_y = sdf(position + glm::vec3(0.0, EPSILON, 0.0)).distance - sdf(position).distance;
    float delta_z = sdf(position + glm::vec3(0.0, 0.0, EPSILON)).distance - sdf(position).distance;

    return (float)(1.0 / EPSILON) * glm::vec3(delta_x, delta_y, delta_z);
}

glm::vec3 approximate_normal(sdf_func sdf, glm::vec3 position) {
    return glm::normalize(approximate_gradient(sdf, position));
}

bool march_ray(sdf_func sdf, glm::vec3 start, glm::vec3 end, RayData* data) {
    glm::vec3 current_intersection = start;
    glm::vec3 direction = glm::normalize(end - start);
    float max_t = glm::length(end - start);
    float t = 0.0f;

    SignedDistanceData last_sdf_data = sdf(start);

    while (last_sdf_data.distance > EPSILON && t < max_t) {
        t += last_sdf_data.distance;
        current_intersection = start + t * direction; // TODO: Glm uses floats, so there is no readon to use doubles for t, or any values, as they will all be limited to the percision of a float.

        last_sdf_data = sdf(current_intersection);
    }

    data->start = start;
    data->end = current_intersection;
    data->t = t;
    data->sdf_data = last_sdf_data;

    if (t >= max_t) 
        return false; // No hit

    // Normal approximation can actually be quite expensive, so it is only done if the ray intersects a surface.
    data->intersection_normal = approximate_normal(sdf, current_intersection);
    return true;
}
