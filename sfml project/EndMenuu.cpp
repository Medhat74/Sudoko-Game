#include "EndMenuu.h"


EndMenuu::EndMenuu(float width, float height)
{
	if (!font.loadFromFile("ArialCE.ttf")) {}


	EndMenu[0].setFont(font);
	EndMenu[0].setFillColor(sf::Color::Blue);
	EndMenu[0].setString("Play");
	EndMenu[0].setCharacterSize(100);
	EndMenu[0].setPosition(sf::Vector2f(width / 2 - 100, height / (max_end_menu + 1) * 1.75));



	EndMenu[1].setFont(font);
	EndMenu[1].setFillColor(sf::Color::White);
	EndMenu[1].setString("Exit");
	EndMenu[1].setCharacterSize(100);
	EndMenu[1].setPosition(sf::Vector2f(width / 2 - 100, height / (max_end_menu + 1) * 2.5));


	/*EndMenu[2].setFont(font);
	EndMenu[2].setOutlineColor(sf::Color::Yellow);
	EndMenu[2].setString("Exit");
	EndMenu[2].setCharacterSize(100);
	EndMenu[2].setPosition(sf::Vector2f(width / 2 - 100, height / (max_end_menu + 1) * 3.25));*/

	EndMenuselected = 0;
}




EndMenuu::~EndMenuu()
{

}

void EndMenuu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 2; i++)
	{
		window.draw(EndMenu[i]);
	}
}

void EndMenuu::moveDown()
{
	if (EndMenuselected + 1 <= max_end_menu)
	{
		EndMenu[EndMenuselected].setFillColor(sf::Color::White);
		EndMenuselected++;
		if (EndMenuselected == 1)
		{
			EndMenuselected = 0;
		}
		EndMenu[EndMenuselected].setFillColor(sf::Color::Blue);
	}

}

void EndMenuu::moveUp()
{
	if (EndMenuselected - 1 >= -1)
	{
		EndMenu[EndMenuselected].setFillColor(sf::Color::White);
		EndMenuselected--;
		if (EndMenuselected == -1)
		{
			EndMenuselected = 1;
		}
		EndMenu[EndMenuselected].setFillColor(sf::Color::Blue);
	}
}