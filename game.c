//Tilak Patel
#include "mylib.h"
#include "start.h"
#include "youwin.h"
#include "youlose.h"

int win()
{
    drawImage3(0, 0, 240, 160, youwin);
    if(KEY_DOWN_NOW(BUTTON_SELECT))
            return 1;
    return 0;

}

int lose()
{
    drawImage3(0, 0, 240, 160, youlose);
    if(KEY_DOWN_NOW(BUTTON_SELECT))
            return 1;
    return 0;
}

int splash()
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;
    drawImage3(0, 0, 240, 160, start);
    drawString(60, 90, "Press <START> to BEGIN", BLUE);
    drawString(80, 110, "By: TILAK PATEL", RED);
    while(!KEY_DOWN_NOW(BUTTON_START))
    {
        if(KEY_DOWN_NOW(BUTTON_START))
            return 0;
        if(KEY_DOWN_NOW(BUTTON_SELECT))
            return 1;
    }
    return 0;

}

int game()
{
    REG_DISPCTL = MODE3 | BG2_ENABLE;
    drawRect(0, 0, 240, 160, YELLOW);
    drawRect(20, 20, 200, 121, WHITE);
    drawRect(0, 70, 20, 20, GREEN);
    drawRect(220, 70, 20, 20, OGREEN);
    int speed = 3;
    int upperBoundary = 20;
    int downBoundary= 130;
    int playerSpeed = 2;
    Enemy enemy1 = {.x = 20, .y = 50, .direction = 2, .oldx = 20, .oldy = 50}; //circle left
    Enemy enemy2 = {.x = 55, .y = 20, .direction = 1, .oldx = 70, .oldy = 20}; //left fast
    Enemy enemy3 = {.x = 85, .y = 20, .direction = 1, .oldx = 85, .oldy = 20}; //first slow
    Enemy enemy4 = {.x = 100, .y = 130 , .direction = 0, .oldx = 100, .oldy = 100}; //second alt
    Enemy enemy5 = {.x = 120, .y = 20, .direction = 1, .oldx = 120, .oldy = 20}; //third slow
    Enemy enemy6 = {.x = 140, .y = 130, .direction = 0, .oldx = 140, .oldy = 130}; //fourth alt
    Enemy enemy7 = {.x = 155, .y = 20, .direction = 1, .oldx = 155, .oldy = 20}; //fifth slow
    Enemy enemy8 = {.x = 180, .y = 75, .direction = 1, .oldx = 180, .oldy = 20}; //horizontal top
    Enemy enemy9 = {.x = 180, .y = 20, .direction = 1, .oldx = 180, .oldy = 20}; //right fast
    Enemy enemy10 = {.x = 192, .y = 50, .direction = 2, .oldx = 192, .oldy = 50}; //right circle


    Player player= {.x = 0, .y = 70, .oldx = 0, .oldy = 70};


    drawRect(enemy1.x, enemy1.y, 10, 10, BLACK);
    drawRect(enemy2.x, enemy2.y, 10, 10, BLACK);
    drawRect(enemy3.x, enemy3.y, 10, 10, BLACK);
    drawRect(enemy4.x, enemy4.y, 10, 10, BLACK);
    drawRect(enemy5.x, enemy5.y, 10, 10, BLACK);
    drawRect(enemy6.x, enemy6.y, 10, 10, BLACK);
    drawRect(enemy7.x, enemy7.y, 10, 10, BLACK);
    drawRect(enemy8.x, enemy8.y, 10, 10, BLACK);
    drawRect(enemy9.x, enemy9.y, 10, 10, BLACK);
    drawRect(enemy10.x, enemy10.y, 10, 10, BLACK);
    drawRect(player.x, player.y, 10, 10, RED);
    drawString(20, 150, "IN PROGRESS...", MAGENTA);
    while(1){
        waitForVblank();
        enemy1.oldy = enemy1.y;
        enemy1.oldx = enemy1.x;
        enemy2.oldx = enemy2.x;
        enemy2.oldy = enemy2.y;
        enemy3.oldy = enemy3.y;
        enemy4.oldy = enemy4.y;
        enemy5.oldy = enemy5.y;
        enemy6.oldy = enemy6.y;
        enemy7.oldy = enemy7.y;
        enemy8.oldx = enemy8.x;
        enemy8.oldy = enemy8.y;
        enemy9.oldx = enemy9.x;
        enemy9.oldy = enemy9.y;
        enemy10.oldy = enemy10.y;
        enemy10.oldx = enemy10.x;
        player.oldy = player.y;
        player.oldx = player.x;

        if(KEY_DOWN_NOW(BUTTON_SELECT))
            return 1;


        // move enemy 3
        if((enemy3.y >= downBoundary) && (enemy3.direction == 1))
            enemy3.direction = 0;

        if((enemy3.y <= upperBoundary) && (enemy3.direction == 0))
            enemy3.direction = 1;

        if(enemy3.direction == 1)
        {
            enemy3.y = enemy3.y + speed;
        }

        if(enemy3.direction == 0)
        {
            enemy3.y = enemy3.y - speed;
        }



        // move enemy 4
        if((enemy4.y >= downBoundary) && (enemy4.direction == 1))
            enemy4.direction = 0;

        if((enemy4.y <= 22) && (enemy4.direction == 0))
            enemy4.direction = 1;

        if(enemy4.direction == 1)
        {
            enemy4.y = enemy4.y + 4;
        }

        if(enemy4.direction == 0)
        {
            enemy4.y = enemy4.y - 4;
        }

        // move enemy 5
        if((enemy5.y >= downBoundary) && (enemy5.direction == 1))
            enemy5.direction = 0;

        if((enemy5.y <= upperBoundary) && (enemy5.direction == 0))
            enemy5.direction = 1;

        if(enemy5.direction == 1)
        {
            enemy5.y = enemy5.y + speed;
        }

        if(enemy5.direction == 0)
        {
            enemy5.y = enemy5.y - speed;
        }

        // move enemy 6
        if((enemy6.y >= downBoundary) && (enemy6.direction == 1))
            enemy6.direction = 0;

        if((enemy6.y <= 22) && (enemy6.direction == 0))
            enemy6.direction = 1;

        if(enemy6.direction == 1)
        {
            enemy6.y = enemy6.y + 4;
        }

        if(enemy6.direction == 0)
        {
            enemy6.y = enemy6.y - 4;
        }

        // move enemy 7

        if((enemy7.y >= downBoundary) && (enemy7.direction == 1))
            enemy7.direction = 0;

        if((enemy7.y <= upperBoundary) && (enemy7.direction == 0))
            enemy7.direction = 1;

        if(enemy7.direction == 1)
        {
            enemy7.y = enemy7.y + speed;
        }

        if(enemy7.direction == 0)
        {
            enemy7.y = enemy7.y -speed;
        }

        // move enemy 1
        if((enemy1.x >= 40) && (enemy1.direction == 2))
            enemy1.direction = 1;
        if((enemy1.y >= 110) && (enemy1.direction == 1 ))
            enemy1.direction = 3;
        if(enemy1.x <= 20 && enemy1.direction == 3)
            enemy1.direction = 0;
        if((enemy1.y < 50) && (enemy1.direction == 0))
            enemy1.direction = 2;
        if(enemy1.direction == 1)
            enemy1.y = enemy1.y + 1;
        if(enemy1.direction == 2)
            enemy1.x = enemy1.x + 1;
        if(enemy1.direction == 3)
            enemy1.x = enemy1.x - 1;
        if(enemy1.direction == 0)
            enemy1.y = enemy1.y - 1;



        // move enemy 2
        if((enemy2.y >= 130) && (enemy2.direction == 1))
            enemy2.direction = 0;

        if((enemy2.y <= 20) && (enemy2.direction == 0))
            enemy2.direction = 1;

        if(enemy2.direction == 1)
        {
            enemy2.y = enemy2.y + 5;
        }

        if(enemy2.direction == 0)
        {
            enemy2.y = enemy2.y - 5;
        }
        drawRect(enemy2.oldx, enemy2.oldy, 10, 10, WHITE);
        drawRect(enemy2.x, enemy2.y, 10, 10, BLACK);

        // move enemy 8
        if((enemy8.x >= 180) && (enemy8.direction == 1))
            enemy8.direction = 0;

        if((enemy8.x <= 40) && (enemy8.direction == 0))
            enemy8.direction = 1;

        if(enemy8.direction == 1)
        {
            enemy8.x = enemy8.x + 2;
        }

        if(enemy8.direction == 0)
        {
            enemy8.x = enemy8.x - 2;
        }

        drawRect(enemy8.oldx, enemy8.oldy, 10, 10, WHITE);
        drawRect(enemy8.x, enemy8.y, 10, 10, BLACK);

        //move of enemy 10
        if((enemy10.x >= 210) && (enemy10.direction == 2))
            enemy10.direction = 1;

        if((enemy10.y >= 110) && (enemy10.direction == 1 ))
            enemy10.direction = 3;
        if(enemy10.x <= 192 && enemy10.direction == 3)
            enemy10.direction = 0;
        if((enemy10.y < 50) && (enemy10.direction == 0))
            enemy10.direction = 2;
        if(enemy10.direction == 1)
            enemy10.y = enemy10.y + 2;
        if(enemy10.direction == 2)
            enemy10.x = enemy10.x + 2;
        if(enemy10.direction == 3)
            enemy10.x = enemy10.x - 2;
        if(enemy10.direction == 0)
            enemy10.y = enemy10.y - 2;

        drawRect(enemy10.oldx, enemy10.oldy, 10, 10, WHITE);
        drawRect(enemy10.x, enemy10.y, 10, 10, BLACK);

        // move enemy 9
        if((enemy9.y >= 130) && (enemy9.direction == 1))
            enemy9.direction = 0;

        if((enemy9.y <= 20) && (enemy9.direction == 0))
            enemy9.direction = 1;

        if(enemy9.direction == 1)
        {
            enemy9.y = enemy9.y + 5;
        }

        if(enemy9.direction == 0)
        {
            enemy9.y = enemy9.y - 5;
        }

        drawRect(enemy9.oldx, enemy9.oldy, 10, 10, WHITE);
        drawRect(enemy9.x, enemy9.y, 10, 10, BLACK);


        //////Player Movements
        if(KEY_DOWN_NOW(BUTTON_RIGHT)) {
            player.x = player.x + playerSpeed;
            int isvalid = 0;
            isvalid = isValidMove(player.x, player.y);
            if(isvalid == 0)
                player.x = player.x - playerSpeed;

        }

        if(KEY_DOWN_NOW(BUTTON_UP)) {
            player.y = player.y - playerSpeed;
            int isvalid = 0;
            isvalid = isValidMove(player.x, player.y);
            if(isvalid == 0)
                player.y = player.y + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_LEFT)) {
            player.x = player.x - playerSpeed;
            int isvalid = 0;
            isvalid = isValidMove(player.x, player.y);
            if(isvalid == 0)
                player.x = player.x + playerSpeed;
        }

        if(KEY_DOWN_NOW(BUTTON_DOWN)) {
            player.y = player.y + playerSpeed;
            int isvalid = 0;
            isvalid = isValidMove(player.x, player.y);
            if(isvalid == 0)
                player.y = player.y - playerSpeed;

        }

        if(KEY_DOWN_NOW(BUTTON_L))
        {
            if(playerSpeed <=3)
                playerSpeed = playerSpeed +1;
        }


        if(player.x + 9 >= 220 && player.y >= 70 && player.y <= 210)
            return 3;

        int collide;
        collide = isColliding(player, enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8, enemy9, enemy10);
        if(collide)
            return 2;


        char str[15];
        sprintf(str, "%d", lives);
        drawRect(enemy3.oldx, enemy3.oldy, 10, 10, WHITE);
        drawRect(enemy3.x, enemy3.y, 10, 10, BLACK);
        drawRect(enemy4.oldx, enemy4.oldy, 10, 10, WHITE);
        drawRect(enemy4.x, enemy4.y, 10, 10, BLACK);
        drawRect(enemy5.oldx, enemy5.oldy, 10, 10, WHITE);
        drawRect(enemy5.x, enemy5.y, 10, 10, BLACK);
        drawRect(enemy6.oldx, enemy6.oldy, 10, 10, WHITE);
        drawRect(enemy6.x, enemy6.y, 10, 10, BLACK);
        drawRect(enemy7.oldx, enemy7.oldy, 10, 10, WHITE);
        drawRect(enemy7.x, enemy7.y, 10, 10, BLACK);
        if (player.oldx < 20) {
            drawRect(player.oldx, player.oldy, 10, 10, GREEN);
            //drawRect(player.x, player.y, 10, 10, RED);
        } else {
            drawRect(player.oldx, player.oldy, 10, 10, WHITE);
        }
        drawRect(0, 70, 20, 20, GREEN);
        drawRect(20, 70, 10, 20, WHITE);
        drawRect(enemy1.oldx, enemy1.oldy, 10, 10, WHITE);
        drawRect(enemy1.x, enemy1.y, 10, 10, BLACK);
        drawRect(player.x, player.y, 10, 10, RED);
        drawString(160, 150, "Lives:", MAGENTA);
        drawString(200, 150, str, MAGENTA);



    }
    return 0;
}


int isValidMove(int x, int y)
{
    if(x >= 20 && x <= 210 && y >= 20 && y <= 130)
        return 1;
    if(x >= 0 && x <= 230 && y >= 70 && y <= 80)
        return 1;
    if(x >= 0 && x <= 230 && y >= 70 && y <= 80)
        return 1;
    else return 0;
}


int isColliding(Player player, Enemy enemy1, Enemy enemy2, Enemy enemy3, Enemy enemy4, Enemy enemy5, Enemy enemy6, Enemy enemy7, Enemy enemy8, Enemy enemy9, Enemy enemy10)
{
        if(((player.x + 9 >= enemy1.x) && (player.x <= enemy1.x + 10) && (player.y + 9 >= enemy1.y) && (player.y <= enemy1.y + 10)) ||
           ((player.x + 9 >= enemy2.x) && (player.x <= enemy2.x + 10) && (player.y + 9 >= enemy2.y) && (player.y <= enemy2.y + 10)) ||
           ((player.x + 9 >= enemy3.x) && (player.x <= enemy3.x + 10) && (player.y + 9 >= enemy3.y) && (player.y <= enemy3.y + 10)) ||
           ((player.x + 9 >= enemy4.x) && (player.x <= enemy4.x + 10) && (player.y + 9 >= enemy4.y) && (player.y <= enemy4.y + 10)) ||
           ((player.x + 9 >= enemy5.x) && (player.x <= enemy5.x + 10) && (player.y + 9 >= enemy5.y) && (player.y <= enemy5.y + 10)) ||
           ((player.x + 9 >= enemy6.x) && (player.x <= enemy6.x + 10) && (player.y + 9 >= enemy6.y) && (player.y <= enemy6.y + 10)) ||
           ((player.x + 9 >= enemy7.x) && (player.x <= enemy7.x + 10) && (player.y + 9 >= enemy7.y) && (player.y <= enemy7.y + 10)) ||
           ((player.x + 9 >= enemy8.x) && (player.x <= enemy8.x + 10) && (player.y + 9 >= enemy8.y) && (player.y <= enemy8.y + 10)) ||
           ((player.x + 9 >= enemy9.x) && (player.x <= enemy9.x + 10) && (player.y + 9 >= enemy9.y) && (player.y <= enemy9.y + 10)) ||
           ((player.x + 9 >= enemy10.x) && (player.x <= enemy10.x + 10) && (player.y + 9 >= enemy10.y) && (player.y <= enemy10.y + 10)))
            return 1;
        return 0;

}