#include "consts.h"
#include "image.h"
#include "renderer.h"
#include "ray.h"
#include "sdf.h"
#include <cstdio>
#include <cstdlib>
#include <glm/ext/matrix_transform.hpp>
#include <glm/geometric.hpp>
#include <glm/ext.hpp>
#define FNL_IMPL
#include <FastNoiseLite.h>

static fnl_state noise = fnlCreateState();

SignedDistanceData scene(glm::dvec3 position) {

    SignedDistanceData data;

    data = sphere(position / 1000.0 + glm::dvec3(0.0, 0.0, 0.5001));
    data.distance *= 1000.0;
    glm::dvec3 noise_position = position * 10000.0;
    data.distance += fnlGetNoise3D(&noise, noise_position.x, noise_position.y, noise_position.z) * 0.005;

    return data;
}

int main() {

    noise.noise_type = FNL_NOISE_OPENSIMPLEX2;

    Image result;
    result.width = 256;
    result.height = 256;
    result.data = (glm::dvec3*)malloc(sizeof(glm::dvec3) * result.width * result.height);

    Renderer renderer;
    renderer.max_distance = 100.0;
    renderer.fov = PI / 2.0f;
    renderer.signed_distance_function = scene;
    renderer.view_matrix = glm::dmat4(1.0);
    renderer.view_matrix[3] = glm::dvec4(-2.0, 0.0, 0.0, 1.0);
    
    RayData data;
    march_ray(scene, glm::dvec3(-3.0, 0.0, 0.0), glm::dvec3(3.0, 0.0, 0.0), &data);

    printf("EPSILON: %f\n", float(EPSILON));
    printf("Ray Distance: %f\n", data.t);

    render_scene(renderer, result);

    write_image(result, "./result.png");
}
