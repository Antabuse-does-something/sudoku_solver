#ifndef PIXELS_H
#define PIXELS_H

uint32_t getPixel(SDL_Surface *surface, int x, int y);

void putPixel(SDL_Surface *surface, int x, int y, uint32_t pixel);

#endif