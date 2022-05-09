#ifndef HEADER_H_
#define HEADER_H_


#include <stdlib.h>
#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_mixer.h"
#include "SDL/SDL_ttf.h"

#define screen_w 1280
#define screen_h 720
#define LEFT 0
#define RIGHT 1

#define IDLE 0
#define WALKING 1
#define RUNNING 2
#define JUMPING 3
#define FALLING 4
#define ATTACKING 5
#define HURT 6

#define FLOOR 500
SDL_TimerID startTimer;
SDL_TimerID animateMC;
int collision[8];
//collision[7]=0;
//SDL_TimerID animatepersonne;
int mouseX,mouseY;
typedef struct Button {
    SDL_Surface* btn[2];
    SDL_Rect posBtn;
    int state;
} Button;

typedef struct MainMenu {
    SDL_Surface* bg[3];
    SDL_Rect posBg;
    Button btn[3];

    int currentBg;
} MainMenu;
typedef struct sliders{
    SDL_Surface* slider[5];
    SDL_Rect posSlider;
    int niveau;
}sliders;
typedef struct SettingMenu{
    SDL_Surface* SettingBg;
    SDL_Rect posSettingBg;
    sliders sliders;
    Button btn[2];
}SettingMenu;
typedef struct levelMenu{
    SDL_Surface* levelBg;
    SDL_Rect poslevelBg;
    Button btn[3];
}levelMenu;
typedef struct PauseMenu{
    SDL_Surface* pausemenuBg;
    SDL_Rect posPausemenuBg;
    Button btn[3];
}PauseMenu;

typedef struct Game {
    int done;
    int currentMenu;
    Mix_Music* bgMusic;
    SDL_Surface* fenetre;
    Mix_Chunk *son_click;
    MainMenu mainMenu;
    SettingMenu settingmenu;
    levelMenu levelmenu;
    PauseMenu pauseMenu;
    int bgvolume;
    int musicPlaying;
} Game;
/**
* @struct entite
* @brief struct for entity animation
*/
typedef struct{
    SDL_Surface* imgBus[2];
    SDL_Rect posBus;
    int num;
}portal;
typedef struct{
	SDL_Surface* imgBird[3];/*!< entity images"bird"*/
	SDL_Rect posBird;/*!< entity position*/
	int num;/*!< entity image number 1,2 or 3*/
}entite;
/**
* @struct background
* @brief struct for background
*/
typedef struct{
	SDL_Surface* gameBg;/*!< main background image*/
	SDL_Rect posGameBg;/*!< main background position*/
	SDL_Surface* gameBgMasque;/*!< background mask image used for collision perfect pixel*/
	SDL_Rect posgameBgMasque;/*!< background mask position*/
	SDL_Surface* Camera;/*!< moving camera for scrolling*/
	SDL_Rect posCamera;/*!< moving camera position*/
	entite bird;/*!< entite we want to animate*/
    portal bus;
	Mix_Music* son;/*!< background music*/
	int currentSprite;
	
}background;
/**
* @struct Personne
* @brief struct for personne
*/
typedef struct personne {
  int id; 
  int state;
  int currentSprite;
  int direction;
  SDL_Surface* spriteSheet[2][100][100];
  SDL_Rect spritePos;
  Uint8* keystate;
} personne;
struct text {
    SDL_Surface* textSurface; // reservit leblasa ta text  // 
    SDL_Rect positionText; // position ta text // 
    char txt[20]; 
    SDL_Color couleurTxt;
    TTF_Font* police;
};
typedef struct text Text;// structure text besh tekteb l temps 

typedef struct 
{
    int tempsdebut;
    int mm; 
    int ss;
    Text temps;
    
} Time;
typedef struct 
{
	SDL_Surface *map ;   /*!< Surface. */
	SDL_Rect pos_map;  /*!< Rectangle*/
	SDL_Surface *mini_personne; // nreservi lel sghira // 
	SDL_Rect personne_pos_map; // personneo // 
}map ;

#endif