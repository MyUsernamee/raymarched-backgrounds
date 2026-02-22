#pragma once

#include <glm/glm.hpp>
#include "image.h"
#include "ray.h"

struct Renderer {
    float fov;
    float max_distance;
    sdf_func signed_distance_function;
    glm::mat4 view_matrix;
    // glm::mat4 projection_matrix; TODO: Use this?
};

void render_scene(Renderer renderer, Image image);
