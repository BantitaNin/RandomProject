
#include "MainMenu.h"

MainMenu::MainMenu(float width, float hight)
{	
	
	if (!font.loadFromFile("font/Chunk Five Print.otf")) 
	{}

	mainMenu[0].setFont(font);
	mainMenu[0].setFillColor(sf::Color::Red);
	mainMenu[0].setString("Play");
	mainMenu[0].setCharacterSize(100);
	mainMenu[0].setPosition(sf::Vector2f(width / 2.3, hight/(Max_main_menu+1)));
	
	
	
	mainMenu[1].setFont(font);
	mainMenu[1].setFillColor(sf::Color::White);
	mainMenu[1].setString("Exit");
	mainMenu[1].setCharacterSize(80);
	mainMenu[1].setPosition(sf::Vector2f(width / 2.3, hight / (Max_main_menu + 1) * 2));

	mainMenu[2].setFont(font);
	mainMenu[2].setFillColor(sf::Color::White);
	mainMenu[2].setString("Rank");
	mainMenu[2].setCharacterSize(80);
	mainMenu[2].setPosition(sf::Vector2f(width / 2.3, hight / (Max_main_menu + 1) * 3));

	mainMenuSelected = 0;
}



MainMenu::~MainMenu()
{

}

void MainMenu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(mainMenu[i]);
	}
	
}

void MainMenu::moveDown()
{	
	if (mainMenuSelected + 1 <= Max_main_menu)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected++;
		if (mainMenuSelected == 3)
		{
			mainMenuSelected = 0;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);

	}
}

void MainMenu::moveUp()
{
	if (mainMenuSelected - 1 >= -1)
	{
		mainMenu[mainMenuSelected].setFillColor(sf::Color::White);
		mainMenuSelected--;
		if (mainMenuSelected == -1)
		{
			mainMenuSelected = 2;
		}
		mainMenu[mainMenuSelected].setFillColor(sf::Color::Red);

	}
}