#include "Game.h"


//The constructor for a game object. Sets window and player attributes.
Game::Game()
	: mWindow(sf::VideoMode(1366, 768), "SFML GAME")
	, mTexture()
	, mPlayer()
{
	//Give file path parameter for the texture to load in as the player sprite.
	if (!mTexture.loadFromFile("/res/playerSprite.png"))
	{
		//Throw an exception.
	}
	mPlayer.setTexture(mTexture);
	mPlayer.setPosition(100.0f, 100.0f);
}

//Main run function for the game object, calls several functions within game to carry out game loop.
void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	sf::Time TimePerFrame = sf::seconds(1.0f/ 60.0f);

	//This loop makes sure the time step is stable.
	while (mWindow.isOpen())
	{
		processEvents();
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;
			processEvents();
			update(TimePerFrame);
		}
		render();
	}
}

//Handles player input, such as the W A S D keys for movement.
void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::W)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::A)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::S)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::D)
		mIsMovingRight = isPressed;

}

/*
Handles user input, polls application window for any input events and closes the window if a close
occurs.
*/
void Game::processEvents()
{
	//Create an event object called event.
	sf::Event event;

	//If the close event is selected whilst the window is open, close the window.
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;
		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;
		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}

}

//Updates the game logic - everything that happens in the game.
void Game::update(sf::Time deltaTime)
{
	sf::Vector2f movement(0.0f, 0.0f);
	if (mIsMovingUp == true)
		movement.y -= playerSpeed;
	if (mIsMovingDown == true)
		movement.y += playerSpeed;
	if (mIsMovingLeft == true)
		movement.x -= playerSpeed;
	if (mIsMovingRight == true)
		movement.x += playerSpeed;

	mPlayer.move(movement * deltaTime.asSeconds());
}

/*
	Renders the game to the screen, this is done in 3 parts. 
	Clear the window with a colour, usually black which overwrites the last render.
	Draw objects currently in the frame.
	Display everything drawn to the screen.
*/
void Game::render()
{
	mWindow.clear();
	mWindow.draw(mPlayer);
	mWindow.display();
}