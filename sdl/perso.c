

int f = 10; // chanawa hedhy ??
void initPerso(personne *p) {
  p->id = 0;
  SDL_Surface* idle[1] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/idle1.png"),
  };

  SDL_Surface* walking[3] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/idle1.png"),
    //IMG_Load("mc/walk1.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk2.png"),
  };

  SDL_Surface* running[2] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk1.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk2.png"),
  };

  SDL_Surface* jumping[2]= {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump1.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump2.png"),
  }; 
  SDL_Surface* falling[2] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump1.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump2.png"),
  };

  SDL_Surface* attacking[1] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/hit1.png"),
  };

  SDL_Surface* idle1[1] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/idle2.png"),
  };

  SDL_Surface* walking1[2] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/idle2.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk4.png"),
  };

  SDL_Surface* running1[2] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk3.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/walk4.png"),
  };

  SDL_Surface* jumping1[2]= {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump3.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump4.png"),
  };

  SDL_Surface* falling1[2] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump3.png"),
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/jump4.png"),
  };

  SDL_Surface* attacking1[1] = {
    IMG_Load("/home/nerone/Desktop/integration/ressources/perso/hit2.png"),
  };

  for(int i=0; i<4; i++) {
    p->spriteSheet[RIGHT][IDLE][i] = idle[i];
    p->spriteSheet[LEFT][IDLE][i] = idle1[i];
  }

  for(int i=0; i<6; i++) { // a3lech 6 ?
    p->spriteSheet[RIGHT][WALKING][i] = walking[i];
    p->spriteSheet[LEFT][WALKING][i] = walking1[i];
  }

  for(int i=0; i<6; i++) {
    p->spriteSheet[RIGHT][RUNNING][i] = running[i];
    p->spriteSheet[LEFT][RUNNING][i] = running1[i];
  }
  for(int i=0; i<4; i++) {
    p->spriteSheet[RIGHT][JUMPING][i] = jumping[i];
    p->spriteSheet[LEFT][JUMPING][i] = jumping1[i];
  }

  for(int i=0; i<2; i++) {
    p->spriteSheet[RIGHT][FALLING][i] = falling[i];
    p->spriteSheet[LEFT][FALLING][i] = falling1[i];
  }

  for(int i=0; i<6; i++) {
    p->spriteSheet[RIGHT][ATTACKING][i] = attacking[i];
    p->spriteSheet[LEFT][ATTACKING][i] = attacking1[i];
  }

  p->state = FALLING;
  p->currentSprite = 0;
  p->direction = RIGHT;
  p->spritePos.x = 10; // hedy ?
  p->spritePos.y = FLOOR;//kenet -500
  p->spritePos.w = idle[1]->w;
  p->spritePos.h = idle[1]->h;
}


void manageState(personne* p) {

  int run = SDLK_LSHIFT;
  int right = SDLK_d;
  int left = SDLK_q;
  int attack = SDLK_x;
  int jumping = SDLK_SPACE;
  if(p->state == ATTACKING || p->state == JUMPING || p->state == FALLING) {

  } else if(p->keystate[run] && p->keystate[right]){
    p->direction = RIGHT;
    p->state = RUNNING;
  } else if(p->keystate[run] && p->keystate[left]) {
    p->direction = LEFT;
    p->state = RUNNING;
  } else if(p->keystate[run]) {
    p->direction = RIGHT;
    p->state = RUNNING;
  } else if(p->keystate[right]) {
    p->direction = RIGHT;
    p->state = WALKING;
    if(p->currentSprite >= 6)
      p->currentSprite = 0;
  } else if(p->keystate[left]) {
    p->direction = LEFT;
    p->state = WALKING;
    if(p->currentSprite >= 6)
      p->currentSprite = 0;
  }
   else if(p->keystate[attack]){
      p->currentSprite = 0;
      p->state = ATTACKING;
   }
   else if(p->keystate[jumping]){
      p->currentSprite = 0;
      p->state = JUMPING;
   }
   else {
    p->state = IDLE;
    if(p->currentSprite >= 4)
      p->currentSprite = 0;
  }
}
void saut(personne *p)
{
    p->spritePos.y-=50;
    if(p->spritePos.y <= FLOOR - 100) {
      p->currentSprite = 0;
      //p->spritePos.y = FLOOR;
      p->state = FALLING;
    }
}
void manageJump(personne* p){
  if(p->state == JUMPING) {
                saut(p);
            }

  if(p->state == FALLING) {
    if(collision[5]!=1){
      p->spritePos.y += 4;
      if(p->spritePos.y >= FLOOR) {
        p->spritePos.y = FLOOR;
        p->state = IDLE;
      }
    }
    else{
      p->state = IDLE;
      /*p->spritePos.y += 1;
      if(p->spritePos.y >= currentFloor) {
        p->spritePos.y = currentFloor;
        p->state = IDLE;*/
      }
    }
  if( p->spritePos.y<FLOOR){
    if(collision[5]==0&&p->state==WALKING){
      p->state = FALLING;
    }
  }
}

void deplacerPerso(personne *p) {
  int run = SDLK_LSHIFT;
  int right = SDLK_d;
  int left = SDLK_q;
  int attack = SDLK_x;
  int jump = SDLK_z;
  if(p->keystate[run]) {
    p->spritePos.x += p->keystate[left] ? -5 : 5; // hedhy chnyea ?
  } else if(p->keystate[left])
      p->spritePos.x -= 1;
  else if(p->keystate[right])
      p->spritePos.x += 1;

  if(p->state == JUMPING) {
    saut(p);
  }

  if(p->state == FALLING) {
    if(collision[5]!=1){
      p->spritePos.y += 1;
      if(p->spritePos.y >= FLOOR) {
        p->spritePos.y = FLOOR;
        p->state = IDLE;
      }
    }
    else{
      int currentFloor = p->spritePos.y+p->spritePos.h;
      p->spritePos.y += 1;
      if(p->spritePos.y >= currentFloor) {
        p->spritePos.y = currentFloor;
        p->state = IDLE;
      }
    }
  }
}


void afficherPerso(personne p,SDL_Surface* screen) {
  SDL_BlitSurface(p.spriteSheet[p.direction][p.state][p.currentSprite], 0, screen, &p.spritePos);
}
Uint32 animatepersonne(Uint32 interval, void* param) {
  personne* p = param;
  int limit = p->state == IDLE || p->state == JUMPING ? 1 : 2; // hedhy ??

  if(p->state == FALLING)
    limit = 2;
  p->currentSprite++;
  if(p->currentSprite >= limit) {
    if(p->state == ATTACKING)
      p->state = IDLE;
    if(p->state == FALLING && p->spritePos.y >= FLOOR)//?
      p->state = IDLE;
      
    p->currentSprite = 0;
  }
  return interval;
}

void animerPerso(personne*p)
{
  startTimer = SDL_AddTimer(100, animatepersonne, p);
}
