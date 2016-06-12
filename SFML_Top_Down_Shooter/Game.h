#pragma once
#include <SFML\Graphics.hpp>

class Game
{
public:
	Game();
	void run();
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void processEvents();
	void update(sf::Time deltaTime);
	void render();
	
private:
	sf::RenderWindow mWindow;

	sf::Texture mTexture;
	sf::Sprite mPlayer;

	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingLeft;
	bool mIsMovingRight;

	float playerSpeed = 100.0f;
};

