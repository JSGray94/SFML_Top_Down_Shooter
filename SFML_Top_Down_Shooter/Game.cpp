#include "Game.h"


//The constructor for a game object. Sets window and player attributes.
Game::Game()
	: mWindow(sf::VideoMode(640, 480), "SFML GAME")
	, mPlayer()
{
	mPlayer.setRadius(40.0f);
	mPlayer.setPosition(100.0f, 100.0f);
	mPlayer.setFillColor(sf::Color::Cyan);
}

//Main run function for the game object, calls several functions within game to carry out game loop.
void Game::run()
{
	while (mWindow.isOpen())
	{
		processEvents();
		update();
		render();
	}
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
		if (event.type == sf::Event::Closed)
		{
			mWindow.close();
		}
	}

}

//Updates the game logic - everything that happens in the game.
void Game::update()
{

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