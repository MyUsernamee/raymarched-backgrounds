#include "sdf.h"
#include <cmath>

SignedDistanceData sphere(glm::vec3 position) {
    float distance = glm::length(position) - 0.5;
    
    SignedDistanceData result;
    result.distance = distance;

    return result;
}

SignedDistanceData cube(glm::vec3 position) {
    float x_distance = fabs(position.x) - 0.5;
    float y_distance = fabs(position.y) - 0.5;
    float z_distance = fabs(position.z) - 0.5;

    SignedDistanceData data;
    data.distance = fmax(fmax(x_distance, y_distance), z_distance);

    return data;
}

SignedDistanceData cylinder(glm::vec3 position) {
    float radial_distance = sqrt(position.x * position.x + position.y * position.y) - 0.5;
    float axial_distance = fabs(position.z) - 0.5;

    SignedDistanceData data;
    data.distance = fmax(radial_distance, axial_distance);

    return data;
}

SignedDistanceData union_sdf(sdf_func a, sdf_func b, glm::vec3 position);
SignedDistanceData intersect_sdf(sdf_func a, sdf_func b, glm::vec3 position);
SignedDistanceData transform_sdf(sdf_func sdf, glm::mat4 transform, glm::vec3 position);
SignedDistanceData fold_x(sdf_func sdf, glm::vec3 position);
SignedDistanceData mirror_x(sdf_func sdf, glm::vec3 position);
