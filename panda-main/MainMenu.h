#pragma once
#include <SFML/Graphics.hpp>
#define Max_main_menu 3
class MainMenu
{
public:
	MainMenu(float width, float hight);
	void draw(sf::RenderWindow &window);
	void moveUp();
	void moveDown();

	int mainMenuPressed()
	{

		return mainMenuSelected;
		}

		~MainMenu();
private:
	int mainMenuSelected;
	sf::Font font;
	sf::Text mainMenu[Max_main_menu];

		
};


