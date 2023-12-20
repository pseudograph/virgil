//
// Created by signal on 12/2/23.
//

#pragma once

#define BASE_WIDTH 1920
#define BASE_HEIGHT 1080
#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480
#define FPS 60
#define TITLE "VIRGIL"

/**
 * \brief Screen definitions
 */
#define MAX_LAYERS 5
enum LAYER {
    BACKGROUND,
    SPRITES,
    GUI,
    TEXT
};

/**
 * \brief Sprite definitions
 */
#define LEFT (0 - BASE_WIDTH / 3)
#define CENTRE 0
#define RIGHT (0 + BASE_WIDTH / 3)