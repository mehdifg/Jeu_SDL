/**
* @file map.c
* @brief Testing Program.
* @author C Team
* @version 0.1
* @date Apr 01, 2015
*
* Testing program for minimap
*
*/

/**
* @brief To initialize the minimap m .
* @param m the minimap 
* @param the screen 
* @param p the personne 
* @return Nothing
*/

void initialiser_map (map *m,SDL_Surface *screen,personne *p)
{
	m->map=IMG_Load("/home/nerone/Desktop/sdl/ressources/mini_backgg1.jpg"); // thot taswira fel variable // 
	m->pos_map.x = 1050; // position lezem f west el repere // 
	m->pos_map.y = 50;

	m->mini_personne=SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_DOUBLEBUF,10,10,32,0,0,0,0);//hedhy taaml mouraba fil mini map ali houwa l personne 
	SDL_FillRect(m->mini_personne,NULL,SDL_MapRGB(screen->format,255,0,0));// lel couleur 
	m->personne_pos_map.x=1050; 
	m->personne_pos_map.y=127;

}
/**
* @brief To postion the pres .
* @param the map m 
* @param the personne p 
* @return Nothing
*/


void personne_map(map *m,personne *p)
{
	m->personne_pos_map.x=p->spritePos.x/10+m->pos_map.x;
	//m->personne_pos_map.y=p->spritePos.y/m->pos_map.y;// besh l position ta" l mini personne iji kad kad maa l personne lekbir 3al axe y 
}

/**
* @brief To show the minimap m .
* @param the map m 
* @param the screen 
* @param the personne p 
* @return Nothing
*/

void affiche_map(map *m , SDL_Surface *screen,personne *p)
{
	SDL_BlitSurface(m->map, NULL, screen,&m->pos_map); // affichi el minimap marra barka fel postion li kotlek aliha mellowel // 
	SDL_BlitSurface(m->mini_personne, NULL, screen,&m->personne_pos_map); // nafs lahkeya // 
}





