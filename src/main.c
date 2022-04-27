#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"
#include <SDL.h>
#include <SDL_image.h>
#include "construct.h"

int main(int argc, char **argv)
{
    if(argc != 2)
    {
        printf("Usage: %s <input_file>\n", argv[0]);
        return 1;
    }
    FILE *input;
    input = fopen(argv[1], "r");
    if(input == NULL)
    {
        printf("Error: Could not open file %s\n", argv[1]);
        return 1;
    }
    //removing the space in the file
    char *grid = calloc(sizeof(char) * 81, sizeof(char));
    int i = 0;
    char c;
    while ((c = fgetc(input)) != EOF)
    {
        if(c == ' ' || c == '\n')
        {
            continue;
        }
        else
        {
            grid[i] = c;
            i++;
        }
    }
    fclose(input);
    //solving the grid
    char *solved_grid = calloc(sizeof(char) * 81, sizeof(char));
    strcpy(solved_grid, grid);
    int solved = Solve(solved_grid, 9, 9);
    if(solved == 0)
    {
        printf("Error: Could not solve the grid\n");
        return 1;
    }
    
    //saving the grid
    FILE *output;
    char *outputname = malloc(sizeof(char) * strlen(argv[1]) + strlen(".result"));
    if(outputname == NULL)
    {
        printf("Error: Could not allocate memory\n");
        return 1;
    }
    strcpy(outputname, argv[1]);
    strcat(outputname, ".result");
    output = fopen((outputname), "w");
    for (size_t i = 0; i < 81; i++)
    {
        if(i % 3 == 0 && i != 0){
            char *c = " ";
            fprintf(output,"%s" , c);
        }
        if (i % 9 == 0 && i !=0)
        {
            char *c = "\n";
            fprintf(output,"%s" , c);
        }
        if (i % 27 == 0 && i != 0)
        {
            char *c = "\n";
            fprintf(output,"%s" , c);
        }
        fprintf(output, "%c", solved_grid[i]);
    }
    fclose(output);
    //Create an image with the solved grid
    SDL_Surface *image = NULL;
    image = Result_construct(solved_grid,grid);
    //save the image
    SDL_SaveBMP(image, strcat(outputname, ".bmp"));
    free(grid);
    free(solved_grid);
    return 0;
}