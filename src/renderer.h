#pragma once

#include <glm/glm.hpp>
#include "image.h"
#include "ray.h"

struct Renderer {
    double fov;
    double max_distance;
    sdf_func signed_distance_function;
    glm::dmat4 view_matrix;
    // glm::dmat4 projection_matrix; TODO: Use this?
};

void render_scene(Renderer renderer, Image image);
