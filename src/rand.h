#pragma once

#include <glm/glm.hpp>

void init_random();
double random(double min, double max);
glm::vec3 random(glm::vec3 min, glm::vec3 max);

/// Generates a random unit vector on a hemisphere
/// Where the hemisphere is oriented with the normal.
/// i.e. v dot n > 0. Where n is the normal and v is the 
/// generated unit vector.
glm::dvec3 sample_hemisphere(glm::dvec3 normal);

