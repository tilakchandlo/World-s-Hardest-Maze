//Tilak Patel
#include <stdio.h>
#include <stdlib.h>

// typedef
typedef unsigned short u16;
typedef unsigned int u32;
typedef volatile unsigned int vu32;
typedef volatile unsigned short vu16;

// display definitions
#define REG_DISPCTL *(u16 *)0x4000000
#define MODE3 (3)
#define BG2_ENABLE (1<<10)
#define RGB(r, g, b) ((r) | (g)<<5 | (b)<<10)

#define OFFSET(x, y, width) ((y)*(width)+(x))

#define WHITE RGB(31,31,31)
#define RED RGB(31,0,0)
#define ORANGE RGB(31,15,0)
#define GREEN RGB(12,25,21)
#define OGREEN RGB(19, 6, 10)
#define BLUE RGB(0,0,31)
#define CYAN RGB(0, 31,31)
#define MAGENTA RGB(31,0,31)
#define YELLOW RGB(31, 31, 0)
#define BLACK RGB(0, 0, 0)
#define PINK RGB(31, 19, 20)
#define PURPLE RGB(0, 12, 11)

// input buttons
#define BUTTON_A            (1<<0)
#define BUTTON_B            (1<<1)
#define BUTTON_SELECT       (1<<2)
#define BUTTON_START        (1<<3)
#define BUTTON_RIGHT        (1<<4)
#define BUTTON_LEFT         (1<<5)
#define BUTTON_UP           (1<<6)
#define BUTTON_DOWN         (1<<7)
#define BUTTON_R            (1<<8)
#define BUTTON_L            (1<<9)

#define KEY_DOWN_NOW(key)   (~(BUTTONS) & key)
#define BUTTONS *(vu32 *)0x4000130


#define SCANLINECOUNTER *(vu16 *)0x4000006

// struct
typedef struct
{
	int x;
	int y;
	int oldx;
	int oldy;

	int direction; // 0 - up; 1 - down; 2 - right; 3 - left
} Enemy;


typedef struct
{
	int x;
	int y;
	int oldx;
	int oldy;
} Player;


typedef struct
{
	 const volatile void *src;
	 volatile void *dst;
	 volatile u32 cnt;

} DMAREC;

// DMA
#define DMA ((volatile DMAREC *)0x040000B0)

#define DMA_DESTINATION_INCREMENT (0 << 21)
#define DMA_DESTINATION_DECREMENT (1 << 21)
#define DMA_DESTINATION_FIXED (2 << 21)
#define DMA_DESTINATION_RESET (3 << 21)

#define DMA_SOURCE_INCREMENT (0 << 23)
#define DMA_SOURCE_DECREMENT (1 << 23)
#define DMA_SOURCE_FIXED (2 << 23)

#define DMA_REPEAT (1 << 25)

#define DMA_16 (0 << 26)
#define DMA_32 (1 << 26)

#define DMA_NOW (0 << 28)
#define DMA_AT_VBLANK (1 << 28)
#define DMA_AT_HBLANK (2 << 28)
#define DMA_AT_REFRESH (3 << 28)

#define DMA_IRQ (1 << 30)
#define DMA_ON (1 << 31)

#define START_ON_FIFO_EMPTY 0x30000000

// function prototypes
void setPixel(int x, int y, u16 color);
void drawRect(int x, int y, int width, int height, u16 color);
void drawHollowRect(int x, int y, int width, int height, u16 color);
void drawCharacter(int x, int y, unsigned char ch, u16 color);
void drawString(int x, int y, char *str, u16 color);
void drawImage3(int x, int y, int width, int height, const u16 *image);
void waitForVblank();
int splash();
int game();
int win();
int lose();
int lives;
int isValidMove();
void moveEnemy();
int isColliding();
int next();

// extern
extern u16 *videoBuffer;
extern const unsigned char fontdata_6x8[12288];
