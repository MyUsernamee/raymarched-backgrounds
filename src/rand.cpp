#include "rand.h"
#include <cstdlib>
#include <glm/ext/vector_float3.hpp>
#include <time.h>

void init_random() {
    srand(time(NULL));
}

double random(double min, double max) {
    double range = (max - min);    
    double div = RAND_MAX / range;
    return min + (rand() / div);
}

glm::vec3 random(glm::vec3 min, glm::vec3 max) {
    double x = random(min.x, max.x);
    double y = random(min.y, max.y);
    double z = random(min.z, max.z);
    return glm::vec3(x, y, z);
}

glm::dvec3 sample_hemisphere(glm::dvec3 normal) {
    double theta = random(0, M_PI_2);
    double x = cos(theta);
    double y = sin(theta);
    double z = std::sqrt(1 - (x * x + y * y));
    
    glm::dvec3 result = glm::dvec3(x, y, z);

    if (glm::dot(result, normal) <= 0)
        result = -result;
    
    return result;
}

