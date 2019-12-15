#include "Texture.hpp"

Texture::Texture(std::string filename)
{
#pragma pack(1)
    typedef struct
    {
        GLbyte idlength;
        GLbyte colormaptype;
        GLbyte datatypecode;
        unsigned short colormapstart;
        unsigned short colormaplength;
        unsigned char colormapdepth;
        unsigned short x_orgin;
        unsigned short y_orgin;
        unsigned short width;
        unsigned short height;
        GLbyte bitsperpixel;
        GLbyte descriptor;
    } TGAHEADER;
#pragma pack(8)

    FILE *pFile;
    TGAHEADER tgaHeader;
    unsigned long lImageSize;
    short sDepth;
    GLbyte *pbitsperpixel = NULL;

    pFile = fopen(filename.c_str(), "rb");
    if (pFile == NULL)
        return;

    fread(&tgaHeader, sizeof(TGAHEADER), 1, pFile);

    width = tgaHeader.width;
    height = tgaHeader.height;
    sDepth = tgaHeader.bitsperpixel / 8;

    if (tgaHeader.bitsperpixel != 8 && tgaHeader.bitsperpixel != 24 && tgaHeader.bitsperpixel != 32)
        return;

    lImageSize = tgaHeader.width * tgaHeader.height * sDepth;

    pBytes = (GLbyte *)malloc(lImageSize * sizeof(GLbyte));

    if (pBytes == NULL)
        return;

    if (fread(pBytes, lImageSize, 1, pFile) != 1)
    {
        return;
    }

    switch (sDepth)
    {
    case 3:
        format = GL_BGR_EXT;
        components = GL_RGB8;
        break;
    case 4:
        format = GL_BGRA_EXT;
        components = GL_RGBA8;
        break;
    case 1:
        format = GL_LUMINANCE;
        components = GL_LUMINANCE8;
        break;
    };

    fclose(pFile);
}

Texture::~Texture()
{
    delete pBytes;
}

void Texture::apply()
{
    glTexImage2D(GL_TEXTURE_2D, 0, components, width, height, 0, format, GL_UNSIGNED_BYTE, pBytes);
}