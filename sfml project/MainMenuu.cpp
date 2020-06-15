#include "MainMenuu.h"


MainMenuu::MainMenuu(float width, float height)
{
	if (!font.loadFromFile("BebasNeue.otf")) {}

	MainMenu[0].setFont(font);
	MainMenu[0].setFillColor(sf::Color::Blue);
	MainMenu[0].setString("New Game");
	MainMenu[0].setCharacterSize(100);
	MainMenu[0].setPosition(sf::Vector2f(width / 2 - 130 , height / (max_main_menu + 1) * 1));



	MainMenu[1].setFont(font);
	MainMenu[1].setFillColor(sf::Color::Yellow);
	MainMenu[1].setString("Load");
	MainMenu[1].setCharacterSize(100);
	MainMenu[1].setPosition(sf::Vector2f(width / 2 - 50 , height / (max_main_menu + 1) * 2));


	MainMenu[2].setFont(font);
	MainMenu[2].setOutlineColor(sf::Color::Yellow);
	MainMenu[2].setString("Solve");
	MainMenu[2].setCharacterSize(100);
	MainMenu[2].setPosition(sf::Vector2f(width / 2 - 50 , height / (max_main_menu + 1) * 3));



	MainMenu[3].setFont(font);
	MainMenu[3].setOutlineColor(sf::Color::Yellow);
	MainMenu[3].setString("Exit");
	MainMenu[3].setCharacterSize(100);
	MainMenu[3].setPosition(sf::Vector2f(width / 2 - 50, height / (max_main_menu + 1) * 4));

	MainMenuselected = 0;
}




MainMenuu::~MainMenuu()
{

}

void MainMenuu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 4; i++)
	{
		window.draw(MainMenu[i]);
	}
}

void MainMenuu::moveDown()
{
	if (MainMenuselected + 1 <= max_main_menu)
	{
		MainMenu[MainMenuselected].setFillColor(sf::Color::Yellow);
		MainMenuselected++;
		if (MainMenuselected == 4)
		{
			MainMenuselected = 0;
		}
		MainMenu[MainMenuselected].setFillColor(sf::Color::Blue);
	}

}

void MainMenuu::moveUp()
{
	if (MainMenuselected - 1 >= -1)
	{
		MainMenu[MainMenuselected].setFillColor(sf::Color::White);
		MainMenuselected--;
		if (MainMenuselected == -1)
		{
			MainMenuselected = 3;
		}
		MainMenu[MainMenuselected].setFillColor(sf::Color::Blue);
	}
}
