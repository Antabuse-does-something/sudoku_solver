#include <SDL_image.h>
#include <math.h>

void putPixel(SDL_Surface *surface, int x, int y, uint32_t pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;

    switch(bpp) {
    case 1:
        *p = pixel;
        break;

    case 2:
        *(uint16_t *)p = pixel;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;

    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}

uint32_t getPixel(SDL_Surface *surface, int x, int y)
{
    if (x < 0 || x >= surface->w || y < 0 || y >= surface->h) {
        printf("Bruh moment at x = %d, y = %d\n", x, y);    
    }

    /* Here p is the address to the pixel we want to retrieve */

    //SDL_LockSurface(surface);
    uint32_t result =
        *(uint32_t *) ((uint8_t *)
            surface->pixels
                + y * surface->pitch
                + x * surface->format->BytesPerPixel);
    //SDL_UnlockSurface(surface);

    return result;
}