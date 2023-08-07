//Ishita Chandra (30159580)
//Monmoy Maahdie (30149094)


#include "gpio.h"
#include "uart.h"
#include "controller.h"
#include "framebuffer.h"
#include "image.h"
#include "stdint.h"
#include "string.h"

//Defining Constants
#define GPIO_BASE 0xFE200000
#define CLO_REG 0xFE003004
#define GAMETIME 150

//Initializing structures to be used as game assets
struct Player {
	int x;
	int y;
};

struct Block {
	int x;
	int y;
};

struct Snake {
	int x;
	int y;
};

struct Flag {
	int x;
	int y;
};

struct Health {
	int x;
	int y;
};

struct WinStatement{
	int x;
	int y;
};

struct Clock{
	int x;
	int y;
};

struct Spikes{
	int x;
	int y;
};

struct Arrow{
	int x;
	int y;
};

struct Banana{
	int x;
	int y;
};


struct Flag flag1 = {0,0};
struct Snake snake1 = {0,0};
struct Snake snake2 = {0,0};
struct Snake snake3 = {0,0};
struct Snake snake4 = {0,0};
struct Health health1 = {0,0};
struct Health health2 = {0,0};
struct Clock clock1 = {0,0};
struct Spikes spikeL1 = {0,0};
struct Spikes spikeL2 = {0,0};
struct Spikes spikeL3 = {0,0};
struct Spikes spikeL4 = {0,0};
struct Spikes spikeR1 = {0,0};
struct Spikes spikeR2 = {0,0};
struct Spikes spikeR3 = {0,0};
struct Arrow arrow = {14,8};
struct Banana b1 = {0, 0};

void func(struct Block block);

//Defining Functions used

//Draws all Level 1 assets
void drawLevel1Assets(){
	drawImage(flag1.x*32, flag1.y*32, &tilemap.images[3]);
	drawImage(snake1.x*32, snake1.y*32, &tilemap.images[4]);
	drawImage(snake3.x*32, snake3.y*32, &tilemap.images[4]);
	drawImage(spikeL1.x*32, spikeL1.y*32, &tilemap.images[20]);
	drawImage(spikeL2.x*32, spikeL2.y*32, &tilemap.images[20]);
	drawImage(spikeL3.x*32, spikeL3.y*32, &tilemap.images[20]);
	drawImage(spikeL4.x*32, spikeL4.y*32, &tilemap.images[20]);
	drawImage(spikeR1.x*32, spikeR1.y*32, &tilemap.images[21]);
	drawImage(spikeR2.x*32, spikeR2.y*32, &tilemap.images[21]);
	drawImage(spikeR3.x*32, spikeR3.y*32, &tilemap.images[21]);
	drawImage(0, 21*32, &tilemap.images[19]);
	for (int i = 0; i <= 3; i++){
	drawImage((32+i)*32, 21*32, &tilemap.images[18]);

	drawImage(0, 14*32, &tilemap.images[0]);
	drawImage(3*32, 10*32, &tilemap.images[0]);
	drawImage(7*32, 8*32, &tilemap.images[0]);
	drawImage(7*32, 10*32, &tilemap.images[0]);
	drawImage(6*32, 13*32, &tilemap.images[0]);
	drawImage(14*32, 10*32, &tilemap.images[0]);
}


}
//Creates level 1 obstacles/maze
void createlevel1(unsigned int level[22][40], struct Block block, int *gameState){
	

	*gameState = 1;

	for (int i = 0; i < 40; i += 1){
		for(int j = 2; j<22; j=j+1){

			block.x = i;
			block.y = j;

			//leftmost line
			if(2<i && i<4){
				if (2<j && j<8){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//leftmost line
			if(2<i && i<4){
				if (12<j && j<19){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//bottom-most line
			if(2<i && i<38){
				if (18<j && j<20){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//topmost line
			if(2<i && i<39){
				if (1<j && j<3){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//second right line
			if(33<i && i<35){
				if (2<j && j<11){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//rightmost line
			if(37<i && i<39){
				if (2<j && j<20){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//second top line
			if(32<i && i<35){
				if (10<j && j<12){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//second top/right line
			if(27<i && i<30){
				if (10<j && j<12){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//third right line
			if(26<i && i<28){
				if (5<j && j<12){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//second top line
			if(8<i && i<28){
				if (4<j && j<6){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//4th right line
			if(17<i && i<19){
				if (5<j && j<11){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//2nd left line
			if(17<i && i<19){
				if (5<j && j<11){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//2nd bottom line
			if(20<i && i<33){
				if (14<j && j<16){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//3.5 right line
			if(20<i && i<22){
				if (8<j && j<15){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//3 bottom line
			if(11<i && i<21){
				if (12<j && j<14){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//4 bottom line
			if(5<i && i<11){
				if (10<j && j<12){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

			//2 left line
			if(10<i && i<12){
				if (8<j && j<17){
			drawImage(block.x*32, block.y*32, &tilemap.images[2]);
			level[i][j] = 2;
				}
			}

	}
	}

	
}


//Converts time to string put into array
void convertToString(unsigned int number, char *buffer) {
   int i = 2;
    do {
        buffer[i] = (char)(number % 10 + '0');
        number /= 10;
        i--;
    } while (i >= 0);
    buffer[3] = '\0';
}

//Creates the main menu of screen shown when game is booted
void createMainMenu(){
	fillScreen(0x00000000);//BLACKKK
	drawImage(9*32, 4*32, &tilemap.images[24]);
	
	//Draw selection arrow

	drawImage(arrow.x*32, arrow.y*32, &tilemap.images[25]);
	drawImage(arrow.x*32, (10)*32, &tilemap.images[26]);
	
}

//Creates in game pause menu
void createGameMenu(){
	drawImage(9*32, 4*32, &tilemap.images[27]);

	//Draw selection arrow

	drawImage(arrow.x*32, arrow.y*32, &tilemap.images[25]);
	drawImage(arrow.x*32, (10)*32, &tilemap.images[26]);
}
	



int main()
{

// Initializing counters and flags for various game logic and collision logic
	int gameOver = 0;
	int gameState = 0;
	int lifeCounter = 4;

	int clockColl=0;

	int h1Coll=0;
	int h2Coll=0;

	int s1Coll=0;
	int s3Coll=0;

	int sp1Coll=0;
	int sp2Coll=0;
	int sp3Coll=0;
	int sp4Coll=0;
	int sp5Coll=0;
	int sp6Coll=0;
	int sp7Coll=0;

	int b1Coll = 0;
	
	// For loop to draw the base of the game with grass tiles
	unsigned int base[22][40];

	for(int i=0; i<22; i=i+1){
		for(int j = 0; j<40; j=j+1){
			if (i%2 == 0){
				base[i][j] = 0;
			
			} else {
				base[i][j] = 0;
			}
		}
	}



	
int x_dir = 0;
int y_dir = 10;

// Creating player and block objects with their coordinates
struct Player donkeyKong = {x_dir,y_dir};
struct Block block = {0,0};

// Variables used for time calculation
unsigned int *gameStartTime = (unsigned*) CLO_REG;
unsigned int gameEndTime = *gameStartTime + (GAMETIME*1000000);
unsigned int previousTime = 0;




void printf(char *str){
	uart_puts(str);
}

// Initialize frame buffer and load main menu
init_framebuffer();
createMainMenu();


// CREATE LEVEL TILE MAP ARRAY
unsigned int level[22][40];



// Set coordinates of all game assets
flag1.x = 36;
flag1.y = 4;
level[36][4]=300;


snake1.x = 8;
snake1.y = 8;
level[8][8]=41;


snake3.x = 14;
snake3.y = 17;
level[14][17]=43;

health1.x = 32;
health1.y = 7;

health2.x = 32;
health2.y = 18;

clock1.x = 23;
clock1.y = 13;

spikeL1.x = 32;
spikeL1.y = 11;
level[32][11]=201;

spikeL2.x = 5;
spikeL2.y = 11;
level[5][11]=202;


spikeL3.x = 8;
spikeL3.y = 5;
level[8][5]=203;


spikeL4.x = 37;
spikeL4.y = 7;
level[37][7]=207;


spikeR1.x = 30;
spikeR1.y = 11;
level[30][11]=204;


spikeR2.x = 33;
spikeR2.y = 15;
level[33][15]=205;


spikeR3.x = 35;
spikeR3.y = 10;
level[35][10]=206;

b1.x = 17;
b1.y = 4;


	printf("Created by Monmoy Maahdie and Ishita Chandra\n");

	int current_output = 0;
	int prev_output = 0;
	int score = 0;

	

	// init snes controller
	init_snes_lines();

	
	printf("Please press a button. Press start to quit:\n ");

	int s2mov = 5;
	int s4mov = 23;
	int speed = 1;
	int bPoints = 0;

	unsigned int timeLeftSeconds = 0;

	// Main game loop
	while(1){

		//Reads current SNES output
		current_output = read_snes();

		// Calculation of time only when game is running
		unsigned int *currentTime = (unsigned*) CLO_REG;
		if (gameOver == 0) {
			timeLeftSeconds = (gameEndTime - *currentTime)/1000000;
		}else{
			timeLeftSeconds = 0;
		}
		
		char timeString[4];

		// Calculating Game score
		if(gameOver==0){
		score = timeLeftSeconds + (lifeCounter*5) + bPoints;
		}

		int displayScore = score;
		
		// SNES controller Driver logic
		for (int button_pos = 0; button_pos < 12; button_pos++){
			int mask = 1 << button_pos;
			int button_ON_now = current_output & mask;
			int button_ON_prev = prev_output & mask;
			

			if (button_ON_now && !button_ON_prev){
				if (button_pos == 11){
				printf("You have pressed the Right Key!\n");
				}else if (button_pos == 10){
					printf("You have pressed the Left Key!\n");
				}else if (button_pos == 9){
					printf("You have pressed the X Key!\n");
				}else if (button_pos == 8){
					printf("You have pressed the A Key!\n");

					// When game state is zero, game is on main menu, draws level 1 when start game is selected on screen
					if (gameState == 0 && arrow.y==8) {
						//Reset game state and game over 
						gameState = 1;
						gameOver = 0;
						drawLevel(base);
						createlevel1(level, block, &gameState);
						drawLevel1Assets();

						// Reset time
						timeLeftSeconds = 150;
					}

					// Closes game from main menu
					if(gameState==0 && arrow.y==10){
						fillScreen(0x00000000);
						printf("Program is terminating");
    					return 0;
					}

					// Return to main menu from game pause menu when quit is selected
					if (gameState == 3 && arrow.y==10){
						gameState = 0;
						gameOver = 0;
						createMainMenu();
					}

					// Redraw level 1 assets when restart is selected from game pause menu
					if (gameState == 3 && arrow.y==8) {
						gameState = 1;
						gameOver = 0;
						drawLevel(base);
						createlevel1(level, block, &gameState);
						
						drawLevel1Assets();
						timeLeftSeconds = 105;
					}

				}else if (button_pos == 7){
					printf("You have pressed the Joy-pad RIGHT Key!\n");

					// Game is in level 1 when gamestate == 1
					if(gameState==1){
					if(gameOver==0){

						// Movement logic for player character towards right
						if (level[donkeyKong.x+1][donkeyKong.y] != 2){
							drawImage(donkeyKong.x*32,donkeyKong.y*32, &tilemap.images[0]);
							donkeyKong.x += 1;
							
							}
					}
					}
				}else if (button_pos == 6){
					printf("You have pressed the Joy-pad LEFT Key!\n");

					if(gameState==1){
					if(gameOver==0){

						// Movement logic for player character towards left
						if (level[donkeyKong.x-1][donkeyKong.y] != 2){
							drawImage(donkeyKong.x*32,donkeyKong.y*32, &tilemap.images[0]);
							donkeyKong.x -= 1;
						}
					}
					}
					
				}else if (button_pos == 5){
					printf("You have pressed the Joy-pad DOWN Key!\n");
					
					// Arrow control for main menus to go down
					if (gameState == 0 || gameState == 3){
						
						if (arrow.y == 8){
							arrow.y += 2;
							drawImage(arrow.x*32, arrow.y*32, &tilemap.images[25]);
							drawImage(arrow.x*32, (arrow.y-2)*32, &tilemap.images[26]);

						}
						
					
					}else if (gameState == 1) {
					if(gameOver==0){
						// Movement logic for player character towards down
						if (level[donkeyKong.x][donkeyKong.y+1] != 2){
							drawImage(donkeyKong.x*32,donkeyKong.y*32, &tilemap.images[0]);
							donkeyKong.y += 1;
						}
					}
					}
					
				}else if (button_pos == 4){
					printf("You have pressed the Joy-pad UP Key!\n");

					// Arrow control for main menus to go up
					if (gameState == 0 || gameState == 3){
						if (arrow.y == 10) {
							arrow.y -= 2;
							drawImage(arrow.x*32, arrow.y*32, &tilemap.images[25]);
							drawImage(arrow.x*32, (arrow.y+2)*32, &tilemap.images[26]);
						}
						
					// Movement logic for player character towards up
					}else if (gameState == 1){
						if(gameOver==0){
						if (level[donkeyKong.x][donkeyKong.y-1] != 2){
						drawImage(donkeyKong.x*32,donkeyKong.y*32, &tilemap.images[0]);
						donkeyKong.y -= 1;
						}
						}
					}
					
					

				}else if (button_pos == 3){
					printf("You have pressed the Start Key!\n");
					//Open main menu screen
					if (gameState == 1) {
						gameState = 3;
						createGameMenu();

					}

					
				
				}else if (button_pos == 2){
					printf("You have pressed the Select Key!\n");
				}else if (button_pos == 1){
					printf("You have pressed the Y Key!\n");
				}else if (button_pos == 0){
					printf("You have pressed the B Key!\n");
			
				}
				

			}
		}
		
		prev_output = current_output;
		
		// If not in one of the menus, carry out level 1 collision logic	
	if (gameState != 0 && gameState != 3) {


		speed++;

		//increase to reduce speed
		if(speed==15){
			speed = 1;
		}

		//make snake2 move
		if(gameOver==0){
		if(speed==5){
			if(s2mov<18){
				snake2.x = s2mov;
				snake2.y = 4;
				drawImage(snake2.x*32, snake2.y*32, &tilemap.images[4]);
				drawImage((snake2.x-1)*32, snake2.y*32, &tilemap.images[0]);
				level[s2mov][4]=42;
				level[s2mov-1][4]=0;
				
				if (s2mov==17){
					drawImage((snake2.x)*32, snake2.y*32, &tilemap.images[0]);
					s2mov=5;
				}

				s2mov++;
			}
		}
		
		

		//make snake4 move
		if(speed==5){
			if(s4mov<35){
				snake4.x = s4mov;
				snake4.y = 12;
				drawImage(snake4.x*32, snake4.y*32, &tilemap.images[4]);
				drawImage((snake4.x-1)*32, snake4.y*32, &tilemap.images[0]);
				level[s4mov][17]=44;
				level[s4mov-1][17]=0;

				if(s4mov==34){
					drawImage((snake4.x)*32, snake4.y*32, &tilemap.images[0]);
					s4mov=23;
				}
				s4mov++;
			}
		}
		}
			

	
		// Game over when timer or lives reaches zero
		if(gameOver==0){
		if(timeLeftSeconds==0 || lifeCounter==0){
			drawImage(13*32, 6*32, &tilemap.images[23]);
			timeLeftSeconds=0;
			gameOver=1;
		}
		}

		//end flag collision
		if (level[flag1.x][flag1.y] == level[donkeyKong.x][donkeyKong.y]){
			if(flag1.x==36 && flag1.y==4){
			drawImage(13*32, 6*32, &tilemap.images[22]);
			//timeLeftSeconds = 1;
			gameOver=1;
			}
		}
	

		//Clock collision increases time
		if (clockColl == 0 && timeLeftSeconds<110) {
			drawImage(clock1.x*32, clock1.y*32, &tilemap.images[16]);
	
			level[23][13]=16;
			if (level[clock1.x][clock1.y] == level[donkeyKong.x][donkeyKong.y]) {
				gameEndTime += (20*1000000);
				clockColl = 1;

	
			}
		}

		//banana collision increases score
		if (b1Coll == 0 && timeLeftSeconds<105) {
			drawImage(b1.x*32, b1.y*32, &tilemap.images[28]);
	
			level[b1.x][b1.y]=28;
			if (level[b1.x][b1.y] == level[donkeyKong.x][donkeyKong.y]) {
				b1Coll = 1;
				bPoints =+ 20;


	
			}
		}

		// Snake collision decreases health

		//snake1
		if(s1Coll==0){
		if (level[snake1.x][snake1.y] == level[donkeyKong.x][donkeyKong.y]){
			lifeCounter--;
			s1Coll=1;
			if (lifeCounter == 5){
				drawImage(30*32, 21*32, &tilemap.images[0]);
			}
			else if (lifeCounter == 4){
				drawImage(31*32, 21*32, &tilemap.images[0]);
			}
			else if (lifeCounter == 3){
				drawImage(32*32, 21*32, &tilemap.images[0]);

			}else if(lifeCounter == 2){
				drawImage(33*32, 21*32, &tilemap.images[0]);

			}else if (lifeCounter == 1){
				drawImage(34*32, 21*32, &tilemap.images[0]);

			}else if (lifeCounter == 0){
				drawImage(35*32, 21*32, &tilemap.images[0]);
						
		}
			
		}
		}

		
	
		//snake3
		if(s3Coll==0){
		if (level[snake3.x][snake3.y] == level[donkeyKong.x][donkeyKong.y]){
			s3Coll=1;
			lifeCounter--;
			if (lifeCounter == 5){
				drawImage(30*32, 21*32, &tilemap.images[0]);
			}
			else if (lifeCounter == 4){
				drawImage(31*32, 21*32, &tilemap.images[0]);
			}
			else if (lifeCounter == 3){
				drawImage(32*32, 21*32, &tilemap.images[0]);

			}else if(lifeCounter == 2){
				drawImage(33*32, 21*32, &tilemap.images[0]);

			}else if (lifeCounter == 1){
				drawImage(34*32, 21*32, &tilemap.images[0]);

			}else if (lifeCounter == 0){
				drawImage(35*32, 21*32, &tilemap.images[0]);
						
		}
		}
		}
	
		//health collision increases health

		//health1
		if (h1Coll == 0 && timeLeftSeconds<100) {
			drawImage(health1.x*32, health1.y*32, &tilemap.images[5]);
	
			level[32][7]=51;
			if (level[health1.x][health1.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter++;
				h1Coll = 1;

				// Using a loop to draw images
				for (int i = 1; i <= 6; i++) {
					if (lifeCounter == i) {
						drawImage((30 + (6 - i)) * 32, 21 * 32, &tilemap.images[18]);
						break;
					}
				}
			}
		}

		//health2
		if (h2Coll==0 && timeLeftSeconds<105){
			level[32][18]=52;
			drawImage(health2.x*32, health2.y*32, &tilemap.images[5]);
		if (level[health2.x][health2.y] == level[donkeyKong.x][donkeyKong.y]){
			lifeCounter++;
			h2Coll=1;
			for (int i = 1; i <= 6; i++) {
					if (lifeCounter == i) {
						drawImage((30 + (6 - i)) * 32, 21 * 32, &tilemap.images[18]);
						break;
					}
				}
		}
		}

		//	spike collision reduces health

		//spike1
		if (sp1Coll == 0) {
			if (level[spikeL1.x][spikeL1.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp1Coll = 1;

				 for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike 2
		if (sp2Coll == 0) {
			if (level[spikeL2.x][spikeL2.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp2Coll = 1;

				// Using a loop to draw images
				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike3
		if (sp3Coll == 0) {
			if (level[spikeL3.x][spikeL3.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp3Coll = 1;

				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike4
		if (sp4Coll == 0) {
			if (level[spikeL4.x][spikeL4.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp4Coll = 1;

				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike5
		if (sp5Coll == 0) {
			if (level[spikeR1.x][spikeR1.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp5Coll = 1;

				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike6
		if (sp6Coll == 0) {
			if (level[spikeR2.x][spikeR2.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp6Coll = 1;

				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}

		//spike7
		if (sp7Coll == 0) {
			if (level[spikeR3.x][spikeR3.y] == level[donkeyKong.x][donkeyKong.y]) {
				lifeCounter--;
				sp7Coll = 1;

				for (int i = 5; i >= 0; i--) {
            if (lifeCounter == i) {
                drawImage((30 + (5 - i)) * 32, 21 * 32, &tilemap.images[0]);
                break;
            }
        }
			}
		}



		// Converts time to string to be used in calculations
		if (timeLeftSeconds != previousTime){
			
            convertToString(timeLeftSeconds,timeString);

			previousTime = timeLeftSeconds;
		}


		//displaying time for each position
		for (int i = 0; i <= 9; i++) {
			if (timeString[2] == '0' + i) {
				drawImage(39*32, 21*32, &tilemap.images[6 + i]);
			}
			
		}
			
		for (int i = 0; i <= 9; i++) {
			if (timeString[1] == '0' + i) {
				drawImage(38*32, 21*32, &tilemap.images[6 + i]);
			}
		}

		for (int i = 0; i <= 9; i++) {
			if (timeString[0] == '0' + i) {
				drawImage(37*32, 21*32, &tilemap.images[6 + i]);
				
			}
		}


		//display score
		for (int i = 0; i <= 9; i++) {
			if ((displayScore % 10) == i) {
				drawImage(4*32, 21*32, &tilemap.images[6 + i]);
			}
			
		}
		for (int i = 0; i <= 9; i++) {
			if (((displayScore % 100)/10) == i) {
				drawImage(3*32, 21*32, &tilemap.images[6 + i]);
			}
			
		}
		for (int i = 0; i <= 9; i++) {
			if (((displayScore % 1000)/100) == i) {
				drawImage(2*32, 21*32, &tilemap.images[6 + i]);
			}
			
		}

		
		// screen bounds for player character
		if (donkeyKong.x < 1) {
			donkeyKong.x = 1;
		}else if (donkeyKong.x > 39){
			donkeyKong.x = 39;
		}

		if (donkeyKong.y < 0){
			donkeyKong.y = 0;

		}else if (donkeyKong.y > 21){
			donkeyKong.y = 21;
		}

		//Drawing the player character
		drawImage(donkeyKong.x*32,donkeyKong.y*32, &tilemap.images[1]);

	
	}

	};

	

	sleep_microseconds(200);

    printf("Program is terminating");
    return 0;

}
