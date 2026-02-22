#include "image.h"
#include <cstdint>
#include <glm/common.hpp>
#define cimg_display 0
#include <CImg.h>

#define COLOR_COUNT 3

using namespace cimg_library;


void set_pixel(Image image, uint16_t x, uint16_t y, glm::vec3 color) {
    if (x >= image.width || y >= image.height)
        return; // Out of bounds.
    image.data[x + y * image.width] = color;
}

void convert_uint8(Image image, uint8_t* data) {
    uint32_t stride = image.width * image.height;

    for (int x = 0; x < image.width; x++)
        for (int y = 0; y < image.height; y++) {
            auto idx = x + y * image.width;
            glm::vec3 clamped_color = glm::clamp(image.data[idx], glm::vec3(0.0), glm::vec3(1.0));
            data[x + y * image.height + stride * 0] = uint8_t(clamped_color.r * 255.0);
            data[x + y * image.height + stride * 1] = uint8_t(clamped_color.g * 255.0);
            data[x + y * image.height + stride * 2] = uint8_t(clamped_color.b * 255.0);
        }
}

void write_image(Image image, char* path) {
    uint8_t* data = (uint8_t*)malloc(sizeof(uint8_t) * image.width * image.height * COLOR_COUNT);

    convert_uint8(image, data);

    CImg<uint8_t> cimg(data, image.width, image.height, 1, 3);
    cimg.save(path);

    free(data);
}

