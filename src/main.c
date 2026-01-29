#include <gb/gb.h>
#include "graphics/BallSprite.h"

uint8_t spriteX, spriteY;
int8_t velocityX, velocityY;

void main(void)
{
    DISPLAY_ON;
    SHOW_SPRITES;

    set_sprite_data(0, 1, BallSprite_tiles);
    set_sprite_tile(0, 0);
    move_sprite(0, 84, 88);

    // Set default position
    spriteX = 80;
    spriteY = 72;

    // Set default velocity
    velocityX = 1;
    velocityY = 1;

    // Loop forever
    while(1){
        // Apply velocity
        spriteX += velocityX;
        spriteY += velocityY;

        // Check if sprite is at right screen edge
        if((spriteX > 156) && (velocityX > 0)){

            // Switch movement direction
            velocityX = -velocityX;

            // Clamp X position within screen edge
            spriteX = 156;
        }

        // Check if sprite is at bottom screen edge
        if((spriteY > 140) && (velocityY > 0)){

            // Switch movement direction
            velocityY = -velocityY;

            // Clamp Y position within screen edge
            spriteY = 140;
        }

        // Check if sprite is at left screen edge
        if((spriteX < 4) && (velocityX < 0)){

            // Switch movement direction
            velocityX = -velocityX;

            // Clamp X position within screen edge
            spriteX = 4;
        }

        // Check if sprite is at top screen edge
        if((spriteY < 4) && (velocityY < 0)){

            // Switch movement direction
            velocityY = -velocityY;

            // Clamp Y position within screen edge
            spriteY = 4;
        }

        // Position the first sprite at our spriteX and spriteY
        // All sprites are render 8 pixels to the left of their x position and 16 pixels ABOVE their actual y position
        // This means an object rendered at 0,0 will not be visible
        // x+5 and y+12 will center the 8x8 tile at our x and y position
        move_sprite(0, spriteX + 4, spriteY + 12);

        // Done processing, yield CPU and wait for start of next frame
        wait_vbl_done();
    }
}
