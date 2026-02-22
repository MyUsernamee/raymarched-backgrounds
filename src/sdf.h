/// Basic sdf utilities used for making more complex scenes.
#pragma once

#include "ray.h"

SignedDistanceData sphere(glm::dvec3 position);
SignedDistanceData cube(glm::dvec3 position);
SignedDistanceData cylinder(glm::dvec3 position);
SignedDistanceData union_sdf(sdf_func a, sdf_func b, glm::dvec3 position);
SignedDistanceData intersect_sdf(sdf_func a, sdf_func b, glm::dvec3 position);
SignedDistanceData transform_sdf(sdf_func sdf, glm::dmat4 transform, glm::dvec3 position);
SignedDistanceData fold_x(sdf_func sdf, glm::dvec3 position);
SignedDistanceData mirror_x(sdf_func sdf, glm::dvec3 position);
