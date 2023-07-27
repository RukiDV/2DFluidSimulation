#include <iostream>
#include <vector>
#include <cstdint>

#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_WRITE_IMPLEMENTATION

#include <stb/stb_image.h>
#include <stb/stb_image_write.h>
#include <glm/glm.hpp>

constexpr uint32_t width = 1000;
constexpr uint32_t height = 800;
constexpr uint32_t channel = 3;

uint32_t get_pixel_idx(uint32_t x, uint32_t y)
{
    return (y * width * channel + x * channel);
}

void set_pixel(uint32_t x, uint32_t y, uint8_t r, uint8_t g, uint8_t b, std::vector<uint8_t>& image_data)
{
    image_data[get_pixel_idx(x, y)] = r;
    image_data[get_pixel_idx(x, y) + 1] = g;
    image_data[get_pixel_idx(x, y) + 2] = b;
}

void set_pixel(uint32_t x, uint32_t y, glm::vec3 rgb, std::vector<uint8_t>& image_data)
{
    rgb = glm::clamp(rgb, glm::vec3(0.0), glm::vec3(1.0));
    set_pixel(x, y, rgb.r * 255, rgb.g * 255, rgb.b * 255, image_data);
}

int main(int argc, char* argv[])
{
    std::string filename("test.png");
    std::vector<uint8_t> image_data(width * height * channel);

    set_pixel(500, 400, 255, 255, 255, image_data);
    set_pixel(500, 401, glm::vec3(3.0, 0.5, -2.0), image_data);

    stbi_write_png(filename.c_str(), width, height, channel, (void**)image_data.data(), width * channel);
    return 0;
}