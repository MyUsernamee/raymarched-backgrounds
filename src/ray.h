#pragma once

#include <glm/glm.hpp>


struct SignedDistanceData {
    double specular=1.0;
    double roughness=1.0;
    double transmittance=0.0;
    double distance;

    glm::vec3 albedo=glm::vec3(1.0);
    glm::vec3 emmitance=glm::vec3(0.0);
    glm::vec3 scattering=glm::vec3(0.0);
};

struct RayData {
    double t;

    glm::vec3 start;
    glm::vec3 end;
    glm::vec3 intersection_normal;

    SignedDistanceData sdf_data;
};

typedef SignedDistanceData (*sdf_func)(glm::vec3);

/// Approximates the gradient of the sdf using finite difference approximations.
glm::vec3 approximate_gradient(sdf_func sdf, glm::vec3 position);

/// Approximates the normal of a sdf surface at a point using finite difference approximations.
/// Internally just normalizes the gradient produces from `approximate_gradient`
glm::vec3 approximate_normal(sdf_func sdf, glm::vec3 position);

/// Use a stanard ray marching algorithm to calculate a ray intersection with the signed distance function `sdf`.
/// The function returns whether or not this ray intersects with the sdf's implicit surface.
/// `data` is the result of the intersection if there is one.
/// NOTE: There is no guarentee on the data returned in `data` if they ray doesn't intersect anything.
/// For example, t>|end - start|, if the ray doesn't intersect anything.
bool march_ray(sdf_func sdf, glm::vec3 start, glm::vec3 end, RayData* data); 


