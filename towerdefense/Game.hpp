#include "GameState.hpp"

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

class Game {
public:
	//constructeurs
	Game();
	~Game();
	//m�thodes
	void init(sf::RenderWindow*);
	void clicksouris(sf::RenderWindow*);
	//cr�er une tourelle a la position pass� en param�tre
	void createTower(sf::Vector2i cible, int id);
	void gameLoop(sf::RenderWindow * window);
	void updateRenderGame(sf::RenderWindow * window);
	//accesseurs
	void setPositionSouris(sf::Vector2i newPos);
	sf::Vector2i& getPositionSouris();
	GameState& getGamestate();
private:
	bool click = false;
	sf::Vector2i positionSouris;
	GameState g;
};


