#include <SDL.h>
#include <SDL_image.h>
#include <err.h>
#include<stdio.h>
#include<unistd.h> 
#include<stdlib.h>
#include "Pixels.h"

// Function: Result_construct
// Description: Constructs a the png with the grid solved
// Inputs: char *grid - the solved grid
// Returns: SDL_Surface * - the solved grid

SDL_Surface *Result_construct(char *grid, char *basegrid)
{
    
    SDL_Surface *result = IMG_Load("/tmp/resultGrid.jpg");
    if (result == NULL)
        errx(1,"IMG_Load: %s", IMG_GetError());
    
    int x = 20;
    int y = 10;
    for(int i = 0; i < 81; i++)
    {
        if(grid[i] != '.' && grid[i] != '0')
        {
            SDL_Rect rect = {x, y, 0, 0};
            char *text = malloc(2 * sizeof(char));
            text[0] = grid[i];
            text[1] = '\0';
            char *path = malloc(50 * sizeof(char));
            strcpy(path, "/tmp/Numbers/5-");
            strcat(path, text);
            strcat(path, ".png");
            SDL_Surface *number = IMG_Load(path);
            free(path);
            free(text);
            if (number == NULL)
                errx(1,"IMG_Load: %s", IMG_GetError());

            if(basegrid[i] == '.'){
                //chages the color of number to red
                for(int j = 0; j < number->w; j++){
                    for(int k = 0; k < number->h; k++){
                        Uint32 pixel = getPixel(number, j, k);
                        if(pixel == 0x00000000){
                            // changes the color to RGB : 128,237,153 
                            uint8_t r = pixel >> 16 & 0xFF;
                            uint8_t g = pixel >> 8 & 0xFF;
                            uint8_t b = pixel & 0xFF;
                            r = 128;
                            g = 237;
                            b = 153;
                            pixel = (r << 16) | (g << 8) | b;
                            putPixel(number, j, k, pixel);
                        }
                        else{
                            putPixel(number, j, k, 0xFFFFFFFF);
                        }
                    }
                }
            }
            SDL_BlitSurface(number, NULL, result, &rect);
            SDL_FreeSurface(number);
        }
        x += 100;
        if(x == 920)
        {
            x = 20;
            y += 100;
        }
    }
    return result;
}