#pragma once

#include <glm/glm.hpp>

struct SignedDistanceData {
    double specular=1.0;
    double roughness=1.0;
    double transmittance=0.0;
    double distance;

    glm::dvec3 albedo=glm::dvec3(1.0);
    glm::dvec3 emmitance=glm::dvec3(0.0);
    glm::dvec3 scattering=glm::dvec3(0.0);
};

struct RayData {
    double t;

    glm::dvec3 start;
    glm::dvec3 end;
    glm::dvec3 intersection_normal;

    SignedDistanceData sdf_data;
};

typedef SignedDistanceData (*sdf_func)(glm::dvec3);

/// Approximates the gradient of the sdf using finite difference approximations.
glm::dvec3 approximate_gradient(sdf_func sdf, glm::dvec3 position);

/// Approximates the normal of a sdf surface at a point using finite difference approximations.
/// Internally just normalizes the gradient produces from `approximate_gradient`
glm::dvec3 approximate_normal(sdf_func sdf, glm::dvec3 position);

/// Use a stanard ray marching algorithm to calculate a ray intersection with the signed distance function `sdf`.
/// The function returns whether or not this ray intersects with the sdf's implicit surface.
/// `data` is the result of the intersection if there is one.
/// NOTE: There is no guarentee on the data returned in `data` if they ray doesn't intersect anything.
/// For example, t>|end - start|, if the ray doesn't intersect anything.
bool march_ray(sdf_func sdf, glm::dvec3 start, glm::dvec3 end, RayData* data); 


