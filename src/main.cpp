
#include "consts.h"
#include "image.h"
#include "renderer.h"
#include "ray.h"
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <glm/geometric.hpp>

SignedDistanceData basic_sphere(glm::vec3 position) {

    float distance = glm::length(position) - 1.0;
    
    SignedDistanceData result;
    result.distance = distance;

    return result;
}

int main() {

    Image result;
    result.width = 256;
    result.height = 256;
    result.data = (glm::vec3*)malloc(sizeof(glm::vec3) * result.width * result.height);

    Renderer renderer;
    renderer.max_distance = 10.0f;
    renderer.fov = PI / 2.0f;
    renderer.signed_distance_function = basic_sphere;
    renderer.view_matrix = glm::mat4(1.0);
    renderer.view_matrix[3] = glm::vec4(-2.0, 0.0, 0.0, 1.0);
    
    RayData data;
    march_ray(basic_sphere, glm::vec3(-3.0, 0.0, 0.0), glm::vec3(3.0, 0.0, 0.0), &data);

    printf("EPSILON: %f\n", float(EPSILON));
    printf("Ray Distance: %f\n", data.t);

    render_scene(renderer, result);

    write_image(result, "./result.png");
}
