#include "imageloader.h"


GLuint LoadImage(char* img_path) {
    GLuint textureID = 0;
    int mode = GL_RGB;

    SDL_RWops *rwop = SDL_RWFromFile(img_path, "rb");
    if(IMG_isBMP(rwop))
        mode = GL_BGR;

    SDL_Surface * Surface = IMG_Load(img_path);
    glGenTextures(1, &textureID);
    glBindTexture(GL_TEXTURE_2D, textureID);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, Surface->w, Surface->h, 0, mode, GL_UNSIGNED_BYTE, Surface->pixels);
    return textureID;
}


