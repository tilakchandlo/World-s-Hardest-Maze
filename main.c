//Tilak Patel

//#include <stdio.h>
#include "game.c"

enum {SPLASH, GAME, LOSE, WIN};
int main(void)
{
	int state = SPLASH;
	int response = 1;
	while(1)
	{
		switch(state)
		{
			case SPLASH:
				lives = 30;
                response = splash();
                if(response == 1)
                {
                	state = SPLASH;
                }
                else
                	state = GAME;
                break;

            case GAME:
                response = game();
                if(response == 1)
                	state = SPLASH;
                else if(response == 2)   //restart game
                {
                	state = GAME;
                	lives--;
                }
                else if (response == 3)   //win
                {
                	state = WIN;
                }
                if(lives == 0)
                {
                	state = LOSE;
                }
                break;

            case WIN:
            	response = win();
            	if(response == 1)
            		state = SPLASH;
            	break;
            case LOSE:
            	response = lose();
            	if(response == 1)
            		state = SPLASH;
            default: break;
		}
	}
}

