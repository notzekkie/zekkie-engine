#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <string.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 50

// Function to create a button texture
SDL_Texture* createButtonTexture(SDL_Renderer* renderer, TTF_Font* font, const char* text, SDL_Color color, SDL_Rect* buttonRect) {
    SDL_Surface* textSurface = TTF_RenderText_Solid(font, text, color);
    if (textSurface == NULL) {
        printf("Unable to render text surface! SDL_ttf Error: %s\n", TTF_GetError());
        return NULL;
    }
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
    SDL_FreeSurface(textSurface);
    return texture;
}

int main(int argc, char* args[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 1;
    }

    // Initialize SDL_image
    if (!(IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG) & (IMG_INIT_PNG | IMG_INIT_JPG))) {
        printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
        SDL_Quit();
        return 1;
    }

    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Create the window
    SDL_Window* window = SDL_CreateWindow("zekkie Engine (Development Build)", 
                                          SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
                                          SCREEN_WIDTH, SCREEN_HEIGHT, 
                                          SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Load the icon
    SDL_Surface* icon = SDL_LoadBMP("assets/zekkie-engine/main/default.bmp");
    if (icon == NULL) {
        printf("Failed to load icon! SDL_Error: %s\n", SDL_GetError());
    } else {
        SDL_SetWindowIcon(window, icon);
        SDL_FreeSurface(icon);
    }

    // Create renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Load font
    TTF_Font* font = TTF_OpenFont("assets/zekkie-engine/main/arial.ttf", 24); // Adjust the font path and size as needed
    if (font == NULL) {
        printf("Failed to load font! SDL_ttf Error: %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Set button colors
    SDL_Color buttonColor = {0x00, 0x00, 0xFF, 0xFF}; // Blue

    // Create button textures
    SDL_Rect playButton = {SCREEN_WIDTH - BUTTON_WIDTH - 20, 20, BUTTON_WIDTH, BUTTON_HEIGHT};
    SDL_Rect question1Button = {20, 20, BUTTON_WIDTH, BUTTON_HEIGHT};
    SDL_Rect editorButton = {SCREEN_WIDTH - BUTTON_WIDTH - 20, SCREEN_HEIGHT - BUTTON_HEIGHT - 20, BUTTON_WIDTH, BUTTON_HEIGHT};
    SDL_Rect question2Button = {20, SCREEN_HEIGHT - BUTTON_HEIGHT - 20, BUTTON_WIDTH, BUTTON_HEIGHT};

    SDL_Texture* playTexture = createButtonTexture(renderer, font, "Play", buttonColor, &playButton);
    SDL_Texture* question1Texture = createButtonTexture(renderer, font, "???", buttonColor, &question1Button);
    SDL_Texture* editorTexture = createButtonTexture(renderer, font, "Editor", buttonColor, &editorButton);
    SDL_Texture* question2Texture = createButtonTexture(renderer, font, "???", buttonColor, &question2Button);

    if (!playTexture || !question1Texture || !editorTexture || !question2Texture) {
        printf("Failed to create button textures!\n");
        if (playTexture) SDL_DestroyTexture(playTexture);
        if (question1Texture) SDL_DestroyTexture(question1Texture);
        if (editorTexture) SDL_DestroyTexture(editorTexture);
        if (question2Texture) SDL_DestroyTexture(question2Texture);
        TTF_CloseFont(font);
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
        return 1;
    }

    // Main loop
    SDL_Event e;
    int quit = 0;
    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = 1;
            }
        }

        // Clear screen to black
        SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF); // Black
        SDL_RenderClear(renderer);

        // Render buttons
        SDL_RenderCopy(renderer, playTexture, NULL, &playButton);
        SDL_RenderCopy(renderer, question1Texture, NULL, &question1Button);
        SDL_RenderCopy(renderer, editorTexture, NULL, &editorButton);
        SDL_RenderCopy(renderer, question2Texture, NULL, &question2Button);

        // Present renderer
        SDL_RenderPresent(renderer);
    }

    // Clean up
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(question1Texture);
    SDL_DestroyTexture(editorTexture);
    SDL_DestroyTexture(question2Texture);
    TTF_CloseFont(font);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    TTF_Quit();
    IMG_Quit();
    SDL_Quit();

    return 0;
}
