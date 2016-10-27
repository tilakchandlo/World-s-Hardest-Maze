//Tilak Patel

#include "mylib.h"
#include "font.h"

u16 *videoBuffer = (u16 *)0x6000000;
void setPixel(int x, int y, u16 color)
{
    videoBuffer[OFFSET(x, y, 240)] = color;
}

void drawRect(int x, int y, int width, int height, u16 color)
{
    for(int i = 0; i < height; i++)
    {
        DMA[3].src = &color;
        DMA[3].dst = &videoBuffer[OFFSET(x, y + i, 240)];
        DMA[3].cnt = width | DMA_ON | DMA_SOURCE_FIXED;
    }
}




void drawCharacter(int x, int y, unsigned char ch, u16 color)
{
    int i, j;
    for(i = 0;i < 6; i++)
    {
        for(j = 0;j < 8; j++)
        {
            if(fontdata_6x8[OFFSET(i, j, 6) + ch*48])
            {
                setPixel(i + x, j + y, color);

            }

        }
    }
}

void drawString(int x, int y, char *str, u16 color)
{
    while(*str !='\0')
    {
        drawCharacter(x, y, *str, color);
        x = x + 6;
        str++;
    }
}

void drawImage3(int x, int y, int width, int height, const u16 *image)
{
    for (int r = 0; r < height; r++)
    {
        //DMA[3].src = image + r * width;
        DMA[3].src = &image[OFFSET(0, r, width)];
        //DMA[3].dst = videoBuffer + 240 * r + x;
        DMA[3].dst = &videoBuffer[OFFSET(x, y + r, 240)];
        DMA[3].cnt = width | DMA_ON;
    }
}


void waitForVblank()
{
    while(SCANLINECOUNTER > 160);
    while(SCANLINECOUNTER < 160);
}

