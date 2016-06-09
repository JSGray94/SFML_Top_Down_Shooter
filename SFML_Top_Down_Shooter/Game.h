#pragma once
#include <SFML\Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	void processEvents();
	void update();
	void render();
	
private:
	sf::RenderWindow mWindow;
	sf::CircleShape mPlayer;
};

