#include "NetworkClient.hpp"



int main()
{
	//initialisation des variables r�seau
	initData();
	initClient();
	Game game;
	//variable de gestion du jeu
	sf::RenderWindow window;
	game.init(&window);
	game.getGamestate().setIdClient(client.id);

	//lance l'�coute du serveur
	std::thread t1(receive);

	//on lance la premiere game loop et le premier envoie de donn�e
	game.setPositionSouris(sf::Vector2i(0, 0));
	game.gameLoop(&window);
	isAllMessagesReceived = true;
	
	//boucle de jeu compl�te
	while (window.isOpen()) {
		if (isAllMessagesReceived) {
			//cr�ation du message � envoyer au serveur
			client.posTower = game.getPositionSouris();
			send();
			//r�init l'action du joueur
			game.setPositionSouris(sf::Vector2i(0, 0));
			//on met a jour le bool�en qui d�tecte la reception de message
			isAllMessagesReceived = false;
			std::vector<sf::Vector3i> temp = listAction;
			initData();
			//on r�cup�re les donn�es envoy�es par les autres joueurs pour mettre r�ellement le jeu � jour
			for (int nbTower = 0; nbTower < temp.size(); nbTower++) {
				if (temp[nbTower].x != 0 || temp[nbTower].y != 0) {
					game.createTower(sf::Vector2i(temp[nbTower].x, temp[nbTower].y), temp[nbTower].z);
				}
			}
			//affiche 20 frame de facon autonome
			game.gameLoop(&window);
		}
		else 
		{
			//cr�ation du message � envoyer au serveur
			client.posTower = game.getPositionSouris();
			send();
		}
	}
	return 0;
}