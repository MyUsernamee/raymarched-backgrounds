#include "sdf.h"
#include <cmath>

SignedDistanceData sphere(glm::dvec3 position) {
    double distance = glm::length(position) - 0.5;
    
    SignedDistanceData result;
    result.distance = distance;

    return result;
}

SignedDistanceData cube(glm::dvec3 position) {
    double x_distance = fabs(position.x) - 0.5;
    double y_distance = fabs(position.y) - 0.5;
    double z_distance = fabs(position.z) - 0.5;

    SignedDistanceData data;
    data.distance = fmax(fmax(x_distance, y_distance), z_distance);

    return data;
}

SignedDistanceData cylinder(glm::dvec3 position) {
    double radial_distance = sqrt(position.x * position.x + position.y * position.y) - 0.5;
    double axial_distance = fabs(position.z) - 0.5;

    SignedDistanceData data;
    data.distance = fmax(radial_distance, axial_distance);

    return data;
}

SignedDistanceData union_sdf(sdf_func a, sdf_func b, glm::dvec3 position);
SignedDistanceData intersect_sdf(sdf_func a, sdf_func b, glm::dvec3 position);
SignedDistanceData transform_sdf(sdf_func sdf, glm::dmat4 transform, glm::dvec3 position);
SignedDistanceData fold_x(sdf_func sdf, glm::dvec3 position);
SignedDistanceData mirror_x(sdf_func sdf, glm::dvec3 position);
