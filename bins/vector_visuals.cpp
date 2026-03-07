#include <raylib.h>
#include <cmath>
#include <glm/glm.hpp>
#include "rand.h"


#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480
#define GRID_SLICES 8
#define GRID_SPACING 0.25
#define NUM_SAMPLES 16
#define CAMERA_SPEED 1.0
#define CAMERA_DISTANCE 3.0

static Camera3D camera;

int main () {
    
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, "Random hemi-sphere sampling test");
        
    camera.up = {0.0, 0.0, 1.0};
    camera.fovy = M_PI / 2.0f;
    camera.projection = CAMERA_PERSPECTIVE;
    camera.target = {.0, .0, .0};

    while (!WindowShouldClose())
    {
        ClearBackground(BLACK);
        BeginMode3D(camera);
            float cam_x, cam_y, cam_z;
            cam_x = sin(GetTime() * CAMERA_SPEED) * CAMERA_DISTANCE;
            cam_y = cos(GetTime() * CAMERA_SPEED) * CAMERA_DISTANCE;
            cam_z = CAMERA_DISTANCE;
            camera.position = {cam_x, cam_y, cam_z}; 
            
            DrawGrid(GRID_SLICES, GRID_SPACING);

            for (int i = 0; i < NUM_SAMPLES; i++) {
                glm::vec3 sample_direction = sample_hemisphere(glm::dvec3(0.0, 0.0, 1.0));
                DrawLine3D({.0, .0, .0}, {sample_direction.x, sample_direction.y, sample_direction.z}, GREEN);
            }
        EndMode3D();
    }

}
