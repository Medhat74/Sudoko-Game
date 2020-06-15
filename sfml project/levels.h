#pragma once
#include <SFML/Graphics.hpp>
#define max_level_menu 5
class levels
{
public:
	levels(float width, float height);
	void draw(sf::RenderWindow& window);
	void moveUp();
	void moveDown();
	int LevelsMenuPressed()
	{
		return LevelMenuselected;
	}
	~levels();
private:
	int LevelMenuselected;
	sf::Font font1;
	sf::Font font2;
	sf::Font font3;
	sf::Font font4;
	sf::Font font5;
	sf::Font font6;
	

	sf::Text LevelsMenu[max_level_menu];
};

