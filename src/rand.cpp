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
