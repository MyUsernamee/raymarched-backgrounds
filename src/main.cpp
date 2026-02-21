
#include "image.h"
#include <cstdint>
#include <cstdlib>

int main() {

    Image image;
    image.width = 256;
    image.height = 256;
    image.data = (glm::vec3*)malloc(sizeof(glm::vec3) * 256 * 256);

    for (int x = 0; x < image.width; x++)
        for(int y = 0; y < image.height; y++)
            set_pixel(&image, x, y, glm::vec3(x, y, 0.0) / glm::vec3(image.width));

    write_image(&image, "./test.png");

}
