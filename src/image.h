#pragma once

#include <cstdint>
#include <glm/glm.hpp>

struct Image {
    uint16_t width;
    uint16_t height;
    glm::vec3* data;
};

void set_pixel(Image image, uint16_t x, uint16_t y, glm::vec3 color);
void write_image(Image image, char* path);
