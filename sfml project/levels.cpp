#include"levels.h"  
levels::levels(float width, float height)

{
	if (!font1.loadFromFile("ShineBright-Demo.ttf")) {}
	if (!font2.loadFromFile("minya-nouvelle-bd-it.ttf")) {}
	if (!font3.loadFromFile("Zombie-Slayer.ttf")) {}
	if (!font4.loadFromFile("BebasNeue.otf")) {}
	if (!font5.loadFromFile("aldhabi.ttf")) {}
	if (!font6.loadFromFile("Italic.ttf")) {}
	



	LevelsMenu[0].setFont(font1);
	LevelsMenu[0].setFillColor(sf::Color::Blue);
	LevelsMenu[0].setString("Fast");
	LevelsMenu[0].setCharacterSize(100);
	LevelsMenu[0].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1)));

	LevelsMenu[1].setFont(font1);
	LevelsMenu[1].setFillColor(sf::Color::Yellow);
	LevelsMenu[1].setString("Easy");
	LevelsMenu[1].setCharacterSize(100);
	LevelsMenu[1].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1) * 2));

	LevelsMenu[2].setFont(font1);
	LevelsMenu[2].setFillColor(sf::Color::White);
	LevelsMenu[2].setString("Medium");
	LevelsMenu[2].setCharacterSize(100);
	LevelsMenu[2].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1) * 3));

	LevelsMenu[3].setFont(font1);
	LevelsMenu[3].setFillColor(sf::Color::White);
	LevelsMenu[3].setString("Hard");
	LevelsMenu[3].setCharacterSize(100);
	LevelsMenu[3].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1) * 4));

	LevelsMenu[4].setFont(font1);
	LevelsMenu[4].setFillColor(sf::Color::White);
	LevelsMenu[4].setString("Giant");
	LevelsMenu[4].setCharacterSize(100);
	LevelsMenu[4].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1) * 5));
	
	
	/*LevelsMenu[5].setFont(font6);
	LevelsMenu[5].setFillColor(sf::Color::White);
	LevelsMenu[5].setString("Giant");
	LevelsMenu[5].setCharacterSize(100);
	LevelsMenu[5].setPosition(sf::Vector2f(width / 2 - 50, height / (max_level_menu + 1) * 6));*/

	LevelMenuselected = 0;
}

levels::~levels()
{

}

void levels::draw(sf::RenderWindow& window)
{
	for (int i = 0; i <5; i++)
	{
		window.draw(LevelsMenu[i]);
	}
}

void levels::moveDown()
{
	if (LevelMenuselected + 1 <= max_level_menu)
	{
		LevelsMenu[LevelMenuselected].setFillColor(sf::Color::Yellow);
		LevelMenuselected++;
		if (LevelMenuselected == 5)
		{
			LevelMenuselected = 0;
		}
		LevelsMenu[LevelMenuselected].setFillColor(sf::Color::Blue);
	}

}

void levels::moveUp()
{
	if (LevelMenuselected - 1 >= -1)
	{
		LevelsMenu[LevelMenuselected].setFillColor(sf::Color::White);
		LevelMenuselected--;
		if (LevelMenuselected == -1)
		{
			LevelMenuselected = 4;
		}
		LevelsMenu[LevelMenuselected].setFillColor(sf::Color::Blue);
	}
}
