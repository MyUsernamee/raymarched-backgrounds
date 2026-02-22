/// Basic sdf utilities used for making more complex scenes.
#pragma once

#include "ray.h"

SignedDistanceData sphere(glm::vec3 position);
SignedDistanceData cube(glm::vec3 position);
SignedDistanceData cylinder(glm::vec3 position);
SignedDistanceData union_sdf(sdf_func a, sdf_func b, glm::vec3 position);
SignedDistanceData intersect_sdf(sdf_func a, sdf_func b, glm::vec3 position);
SignedDistanceData transform_sdf(sdf_func sdf, glm::mat4 transform, glm::vec3 position);
SignedDistanceData fold_x(sdf_func sdf, glm::vec3 position);
SignedDistanceData mirror_x(sdf_func sdf, glm::vec3 position);
