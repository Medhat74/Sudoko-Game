#pragma once
#include <SFML/Graphics.hpp>
#define max_main_menu 4
class MainMenuu 
{
public:
	MainMenuu(float width, float height);
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int MainMenuPressed()
	{
		return MainMenuselected;
	}
	~MainMenuu();
private:
	int MainMenuselected;
	sf::Font font;
	sf::Text MainMenu[max_main_menu];


};