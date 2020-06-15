#pragma once
#include <SFML/Graphics.hpp>
#define max_end_menu 2
class EndMenuu
{
public:
	EndMenuu(float width, float height);
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();
	int EndMenuPressed()
	{
		return EndMenuselected;
	}
	~EndMenuu();
private:
	int EndMenuselected;
	sf::Font font;
	sf::Text EndMenu[max_end_menu];


};

