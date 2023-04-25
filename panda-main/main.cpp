#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <iostream>
#include <list>
#include "MainMenu.h"
#include <math.h>
#include <cstdlib>
#include"SFML\System.hpp"
#include<stdio.h>
#include<utility>
#include<algorithm>
#include<string>
#include<vector>
using namespace std;
using namespace sf;

void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font);
void updatascore(string a, int b);
void Showscoreboard(sf::RenderWindow& window);
int page_number;
int gameover = 1;




int main()
{
	

	while (true)
	{
		srand(time(NULL));
		sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
		sf::RenderWindow window(desktop, "Ma pan dee", sf::Style::None);
	
		MainMenu menu(1920, 1080);

		Font font;
		if (!font.loadFromFile("font/SEASRN__.ttf"))
			throw("COULD NOT LOAD FONT!");
		

		Font fontfat;
		if (!fontfat.loadFromFile("font/PORKYS_.ttf"))
			throw("COULD NOT LOAD FONT!");



		//text
		Text text;
		text.setFont(font);
		text.setCharacterSize(60);
		text.setFillColor(Color::Red);
		text.setStyle(Text::Bold);
		text.setString("Bantita Wongwan 64010454");
		text.setPosition(5.f, window.getSize().y / 5);


		Text text2;
		text2.setFont(font);
		text2.setCharacterSize(60);
		text2.setFillColor(Color::Red);
		text2.setStyle(Text::Bold);
		text2.setString("WE ARE WINNING");
		text2.setPosition(600.f, 500.f);


		Text text3;
		text3.setFont(font);
		text3.setCharacterSize(40);
		text3.setFillColor(Color::Red);
		text3.setStyle(Text::Bold);
		text3.setString("Y'all suck Press ESC to get out");
		text3.setPosition(500.f, 800.f);
		Text text4;
		text4.setFont(font);
		text4.setCharacterSize(40);
		text4.setFillColor(Color::Red);
		text4.setStyle(Text::Bold);
		text4.setString("purpul Panda sucks Press ESC to get out");
		text4.setPosition(500.f, 800.f);
		
		

		sf::Texture textureBlueZone;
		textureBlueZone.loadFromFile("img/background1.png");
		sf::Sprite spriteBG;
		spriteBG.setTexture(textureBlueZone);
		spriteBG.setPosition(0, 0);

		sf::Texture cryingpandatext;
		cryingpandatext.loadFromFile("img/cryingpanda.png");
		sf::Sprite cryingpanda;
		cryingpanda.setTexture(cryingpandatext);
		cryingpanda.setPosition(0, 0);
		cryingpanda.scale(sf::Vector2f(1.7f, 1.7f));

		sf::Texture MainBG;
		MainBG.loadFromFile("img/pandaBG.png");
		sf::Sprite spritemainBG;
		spritemainBG.setTexture(MainBG);
		spritemainBG.setPosition(0, 0);
		spritemainBG.scale(sf::Vector2f(1.7f, 1.7f));

		sf::Texture winnertext;
		winnertext.loadFromFile("img/winner.png");
		sf::Sprite winner;
		winner.setTexture(winnertext);
		winner.setPosition(0, 0);
		winner.scale(sf::Vector2f(1.7f, 1.7f));

		sf::Texture lalalatext;
		lalalatext.loadFromFile("img/lalala.png");
		sf::Sprite lalala;
		lalala.setTexture(lalalatext);
		lalala.setPosition(0, 0);
		lalala.scale(sf::Vector2f(0.95f, 0.99f));


		sf::Texture collision;
		if (!collision.loadFromFile("img/door.png"))
		{
			std::cout << "Load failed" << std::endl;
		}

		sf::Sprite door;
		door.setTexture(collision);
		door.setPosition({ 1700,770 });


		sf::Texture panda1;
		if (!panda1.loadFromFile("img/panda2.png"))
		{
			std::cout << "Load failed" << std::endl;
		}

		sf::Texture bullettex;
		if (!bullettex.loadFromFile("img/panda1fire.png"))
		{
			std::cout << "Load failed" << std::endl;
		}

		sf::Texture bullettex2;
		if (!bullettex2.loadFromFile("img/panda2fire.png"))
		{
			std::cout << "Load failed" << std::endl;
		}


		sf::Texture enemytexture;
		if (!enemytexture.loadFromFile("img/flies.png"))
		{
			std::cout << "Load failed" << std::endl;
		}

		sf::Texture fireskill;
		if (!fireskill.loadFromFile("img/fireball1.png"))
		{
			std::cout << "Load failed" << std::endl;
		}


		sf::Texture panda2;
		if (!panda2.loadFromFile("img/panda3.png"))
		{
			std::cout << "Load failed" << std::endl;

		}

		//name
		sf::Event event;
		
		std::string playerInput;
		sf::Text playerText("",fontfat,70);
		playerText.setPosition(940, 270);
		playerText.setFillColor(sf::Color::White);

		Text putname;
		putname.setFont(fontfat);
		putname.setCharacterSize(70);
		putname.setFillColor(Color::White);
		putname.setStyle(Text::Bold);
		putname.setString("Name:");
		putname.setPosition(playerText.getPosition().x- 230, playerText.getPosition().y);
		
		Text returns;
		returns.setFont(font);
		returns.setCharacterSize(60);
		returns.setFillColor(Color::Red);
		returns.setStyle(Text::Bold);
		returns.setString("Click here to Return");
		returns.setPosition(playerText.getPosition().x - 450, 600);
		//finish

		sf::Text finish("Click", fontfat, 80);
		finish.setPosition(945, 425);
		




		//score1
		Text scoreText1;
			scoreText1.setFont(font);
			scoreText1.setCharacterSize(40);
			scoreText1.setFillColor(Color::White);
			scoreText1.setPosition(1400.f, 10.f);
			int score1 = 0;

			//score2
			Text scoreText2;
			scoreText2.setFont(font);
			scoreText2.setCharacterSize(40);
			scoreText2.setFillColor(Color::Magenta);
			scoreText2.setPosition(1400.f, 50.f);
			int score2 = 0;
			//score3
			Text scoreText3;
			scoreText3.setFont(font);
			scoreText3.setCharacterSize(40);
			scoreText3.setFillColor(Color::Black);
			scoreText3.setPosition(900.f, 30.f);
			int score3 = score1 + score2;
			int scoreMax = score3;

			//highscore
			FILE* fp;
			char temp[255];
			int score[6];
			string name[6];
			vector <pair<int, string>> userScore;
			fp = fopen("Score.txt", "r");
			
	



		//HP1
		RectangleShape hpBar1;
		int hp1 = 10;
			hpBar1.setFillColor(Color::Red);
			hpBar1.setSize(Vector2f((float)hp1 * 100.f, 100.f));
			

			//HP2
			RectangleShape hpBar2;
			int hp2 = 10;
			hpBar2.setFillColor(Color::Red);
			hpBar2.setSize(Vector2f((float)hp2 * 100.f, 100.f));
			hpBar2.setPosition(900.f, 80.f);

			//HPbamboo1
			RectangleShape hpBar3;
			int hp3 = 15;
			hpBar3.setFillColor(Color::Green);
			hpBar3.setSize(Vector2f((float)hp3 * 100.f, 100.f));
			hpBar3.setPosition(900.f, 80.f);
			//HPbamboo2
			RectangleShape hpBar4;
			int hp4 = 15;
			hpBar4.setFillColor(Color::Green);
			hpBar4.setSize(Vector2f((float)hp4 * 100.f, 100.f));
			hpBar4.setPosition(900.f, 80.f);
			//HPbamboo3
			RectangleShape hpBar5;
			int hp5 = 15;
			hpBar5.setFillColor(Color::Green);
			hpBar5.setSize(Vector2f((float)hp5 * 100.f, 100.f));
			hpBar5.setPosition(900.f, 80.f);
			//HPbamboo4
			RectangleShape hpBar6;
			int hp6 = 15;
			hpBar6.setFillColor(Color::Green);
			hpBar6.setSize(Vector2f((float)hp6 * 100.f, 100.f));
			hpBar6.setPosition(900.f, 80.f);

			//HP fire
			RectangleShape hpBarfire;
			int hpfire = 150;
			hpBarfire.setFillColor(Color::Magenta);
			hpBarfire.setSize(Vector2f((float)hpfire * 100.f, 100.f));

		//panda1

		sf::Sprite shapepanda1;
		shapepanda1.setTexture(panda1);
		shapepanda1.scale(sf::Vector2f(2, 2));

		int sprite1SizeX = panda1.getSize().x / 3;
		int sprite1SizeY = panda1.getSize().y / 4;

		shapepanda1.setTextureRect(sf::IntRect(0, 0, sprite1SizeX, sprite1SizeY));
		sf::Vector2f spawnPoint1 = { 200.f, 500.f };
		shapepanda1.setPosition(spawnPoint1);
		shapepanda1.setTextureRect(sf::IntRect(0, 0, sprite1SizeX, sprite1SizeY));

		//panda2
		sf::Sprite shapepanda2;
		shapepanda2.setTexture(panda2);
		shapepanda2.scale(sf::Vector2f(2, 2));

		int spriteSizeX = panda2.getSize().x / 3;
		int spriteSizeY = panda2.getSize().y / 4;

		shapepanda2.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

		sf::Vector2f spawnPoint2 = { 200.f, 700.f };
		shapepanda2.setPosition(spawnPoint2);
		shapepanda2.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));



		//tree
		sf::Texture treetext;
		if (!treetext.loadFromFile("img/flower.png"))
		{
			std::cout << "Load failed" << std::endl;

		}
		sf::Sprite tree;
		tree.setTexture(treetext);
		tree.scale(sf::Vector2f(0.2f, 0.2f));
		tree.setPosition(0.f, 0.f);
		//bamboo
		sf::Texture bambootext;
		if (!bambootext.loadFromFile("img/bamboo1.png"))
		{
			std::cout << "Load failed" << std::endl;

		}
		sf::Sprite bamboo;
		bamboo.setTexture(bambootext);
		bamboo.scale(sf::Vector2f(0.7f, 1.7f));
		bamboo.setPosition(0.f, 5.f);

		sf::Sprite bamboo2;
		bamboo2.setTexture(bambootext);
		bamboo2.scale(sf::Vector2f(0.7f, 1.7f));
		bamboo2.setPosition(0.f, 280.f);

		sf::Sprite bamboo3;
		bamboo3.setTexture(bambootext);
		bamboo3.scale(sf::Vector2f(0.7f, 1.7f));
		bamboo3.setPosition(0.f, 550.f);

		sf::Sprite bamboo4;
		bamboo4.setTexture(bambootext);
		bamboo4.scale(sf::Vector2f(0.7f, 1.7f));
		bamboo4.setPosition(0.f, 800.f);

		//fireman
		sf::Texture firetext;
		if (!firetext.loadFromFile("img/fireman.png"))
		{
			std::cout << "Load failed" << std::endl;

		}
		sf::Sprite fireman;
		fireman.setTexture(firetext);
		fireman.scale(sf::Vector2f(0.6f, 0.6f));
		fireman.setPosition(1300.f, 500.f);
		

		
		//bullet1
		sf::Sprite bullet;
		bullet.setTexture(bullettex);
		bullet.scale(sf::Vector2f(0.3f, 0.3f));
		int shootTimer = 0;
		Vector2f playerCenter;
		std::vector<Sprite> bullets;
		bullets.push_back(Sprite(bullet));

		//bullet2
		sf::Sprite bullet1;
		bullet1.setTexture(bullettex2);
		bullet1.scale(sf::Vector2f(0.3f, 0.3f));
		int shootTimer2 = 0;
		Vector2f playerCenter2;
		std::vector<Sprite> bullets1;
		bullets1.push_back(Sprite(bullet1));


		

		//enemy
		sf::Sprite enemy;
		enemy.setTexture(enemytexture);
		enemy.scale(sf::Vector2f(2, 2));
		int enemySizeX = enemytexture.getSize().x / 3;
		int enemySizeY = enemytexture.getSize().y / 4;

		enemy.setTextureRect(sf::IntRect(0, 0, enemySizeX, enemySizeY));

		std::vector<Sprite> enemies;
	
		enemies.push_back(Sprite(enemy));
		
		int enemySpawnTimer = 0;
		
		//fire skill
		sf::Sprite fireboss;
		fireboss.setTexture(fireskill);
		fireboss.scale(sf::Vector2f(0.3f, 0.3f));
	

		std::vector<Sprite> firebosses;

		firebosses.push_back(Sprite(fireboss));

		int firebossSpawnTimer = 0;



		int animationFrame1 = 0;
		int animationFrame2 = 0;
		int windowmenu =0 ;
		
		//music
		sf::Music music;
		if (!music.openFromFile("song/Loituma - Ievan Polkka.ogg"))
			return EXIT_FAILURE;

		sf::SoundBuffer buffer;
		if (!buffer.loadFromFile("song/Fire Sound Effect.ogg"))
			return -1;

			sf::SoundBuffer buffer2;
		if (!buffer2.loadFromFile("song/WOW Sound.ogg"))
			return -1;

		sf::SoundBuffer pandahurt2;
		if (!pandahurt2.loadFromFile("song/panda2hurt.ogg"))
			return -1;
		sf::SoundBuffer pandahurt1;
		if (!pandahurt1.loadFromFile("song/panda1hurt.ogg"))
			return -1;
		sf::Sound sound;
		sound.setBuffer(buffer);

		sf::Sound panda1hurt;
		panda1hurt.setBuffer(pandahurt1);
		sf::Sound panda2hurt;
		panda2hurt.setBuffer(pandahurt2);

		
		sf::Sound sound2;
		sound2.setBuffer(buffer2);
		
		music.play();
		
			while (window.isOpen())
			{


				sf::Event event;
				while (window.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window.close();

					if (event.type == sf::Event::KeyReleased)
					{
						if (event.key.code == sf::Keyboard::Up)
						{
							menu.moveUp();
							break;
						}
						if (event.key.code == sf::Keyboard::Down)
						{
							menu.moveDown();
							break;
						}

						if (event.key.code == sf::Keyboard::Return)
						{

							if (menu.mainMenuPressed() == 0) {
								window.close();
								page_number = 0;

							}

							if (menu.mainMenuPressed() == 1) {
								window.close();
								page_number = 2;
							}
							if (menu.mainMenuPressed() == 2) {
								
							
								gameover = 6;
								windowmenu = 1;
								

							}
						}

					}

				}
				if (windowmenu == 0) {
				window.clear();
				window.draw(spritemainBG);
				menu.draw(window);
				window.draw(text);
				if (text.getPosition().x > window.getSize().x)
					text.setPosition(0.f, text.getPosition().y);

				text.move(4.f, 0.f);


				window.display();
						
				


			}
			if (gameover == 6) {
				window.clear();

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				{

					windowmenu = 0;
					gameover = 16;
				}

				window.draw(lalala);
				Showscoreboard(window);
				window.display();
			}
	
		}

		
		if (page_number == 0 )
		{
			
			sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
			sf::RenderWindow window_play(desktop, "Ma pandee", sf::Style::None);
				

			while (window_play.isOpen())
			{
				if (gameover == 6)
					window_play.close();

				sf::Event event;
				while (window_play.pollEvent(event))
				{
					if (event.type == sf::Event::Closed)
						window_play.close();
				}
				
				playerCenter = Vector2f(shapepanda1.getPosition().x +70 , shapepanda1.getPosition().y + 10);
				playerCenter2 = Vector2f(shapepanda2.getPosition().x +70, shapepanda2.getPosition().y + 10);

				if (hp1 > 0 && hp2 > 0 ) {

					hpBar1.setPosition(shapepanda1.getPosition().x, shapepanda1.getPosition().y);
					hpBar2.setPosition(shapepanda2.getPosition().x, shapepanda2.getPosition().y);
					hpBar3.setPosition(bamboo.getPosition().x+ 20, bamboo.getPosition().y + 50);
					hpBar4.setPosition(bamboo2.getPosition().x + 20, bamboo2.getPosition().y + 50);
					hpBar5.setPosition(bamboo3.getPosition().x + 20, bamboo3.getPosition().y + 50);
					hpBar6.setPosition(bamboo4.getPosition().x + 20, bamboo4.getPosition().y + 50);
					hpBarfire.setPosition(fireman.getPosition().x + 50, fireman.getPosition().y);
					//enemy
					for (size_t i = 0; i < enemies.size(); i++)
					{
						enemies[i].move(-2.f, 0.f);
						enemy.setTextureRect(sf::IntRect(enemySizeX * animationFrame1, enemySizeY * 1, enemySizeX, enemySizeY));

						if (enemies[i].getPosition().x < 0 - enemy.getGlobalBounds().width){
							enemies.erase(enemies.begin() + i);
							}

					}
					
					if (enemySpawnTimer < 30)
						enemySpawnTimer++;

					if (enemySpawnTimer >= 30)
					{
						enemy.setPosition(window.getSize().x, rand() % int(window.getSize().y - enemy.getGlobalBounds().height));
						enemies.push_back(Sprite(enemy));
						
						enemySpawnTimer = 0;
					}

					score3 = score1 + score2;
					
					scoreText1.setString("Score white panda: " + std::to_string(score1));
					scoreText2.setString("Score purple panda: " + std::to_string(score2));
					scoreText3.setString("Score: " + std::to_string(score3));

					//collision enemy and player
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (shapepanda1.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp1--;
							panda1hurt.play();
							
							enemies.erase(enemies.begin() + i);
						}
						

					}
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (bamboo.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp3--;

							enemies.erase(enemies.begin() + i);
						}




					}
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (bamboo2.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp4--;

							enemies.erase(enemies.begin() + i);
						}




					}

					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (bamboo3.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp5--;

							enemies.erase(enemies.begin() + i);
						}

					}
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (bamboo4.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp6--;

							enemies.erase(enemies.begin() + i);



						}						
					}

					if (hp3 < 0)
						hp3 = 0;
					if (hp4 < 0)
						hp4 = 0;
					if (hp5 < 0)
						hp5 = 0;
					if (hp6 < 0)
						hp6 = 0;


					//panda collision
					for (size_t i = 0; i < enemies.size(); i++)
					{
						if (shapepanda2.getGlobalBounds().intersects(enemies[i].getGlobalBounds()))
						{
							hp2--;
							panda2hurt.play();
							enemies.erase(enemies.begin() + i);
						}
					}
					  //bullet1
					if (shootTimer < 20)
							shootTimer++;
						
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && shootTimer >= 20) {
						sound.play();
						bullet.setPosition(playerCenter);
						bullets.push_back(Sprite(bullet));

						shootTimer = 0;
						
					}
					for (size_t i = 0; i < bullets.size(); i++)
							{
								bullets[i].move(10.f, 0.f);
						
								if (bullets[i].getPosition().y > window.getSize().y)
									bullets.erase(bullets.begin() + i);
							}
					if (!enemies.empty() && !bullets.empty())
							{
									for (size_t i = 0; i < bullets.size(); i++)
									{
										for (size_t k = 0; k < enemies.size(); k++)
											{
											if (bullets[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
												{
												bullets.erase(bullets.begin() + i);
												enemies.erase(enemies.begin() + k);
												score1++;
											break;
												}
											}
									}												
							}

					//tree
					for (size_t i = 0; i < bullets1.size(); i++)
					{
						if (tree.getGlobalBounds().intersects(bullets1[i].getGlobalBounds()))
						{
							

							bullets1.erase(bullets1.begin() + i);
						}

					}
					for (size_t i = 0; i < bullets.size(); i++)
					{
						if (tree.getGlobalBounds().intersects(bullets[i].getGlobalBounds()))
						{


							bullets.erase(bullets.begin() + i);
						}

					}
					for (size_t i = 0; i < firebosses.size(); i++)
					{
						if (tree.getGlobalBounds().intersects(firebosses[i].getGlobalBounds()))
						{
							firebosses.erase(firebosses.begin() + i);
						}

					}

					if (shootTimer2 < 20)
						shootTimer2++;
					//bullet2
					

					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && shootTimer2 >= 20) {
						sound2.play();
						bullet1.setPosition(playerCenter2);
						bullets1.push_back(Sprite(bullet1));

						shootTimer2 = 0;

					}
					for (size_t i = 0; i < bullets1.size(); i++)
					{
						bullets1[i].move(10.f, 0.f);

						if (bullets1[i].getPosition().y > window.getSize().y)
							bullets1.erase(bullets1.begin() + i);
					}
					if (!enemies.empty() && !bullets1.empty())
					{
						for (size_t i = 0; i < bullets1.size(); i++)
						{
							for (size_t k = 0; k < enemies.size(); k++)
							{
								if (bullets1[i].getGlobalBounds().intersects(enemies[k].getGlobalBounds()))
								{
									bullets1.erase(bullets1.begin() + i);
									enemies.erase(enemies.begin() + k);
									score2++;
									break;
								}
							}
						}


					}

					if (hpfire < 0)
						hpfire = 0;
					

					//HP
					hpBar1.setSize(Vector2f((float)hp1 * 10.f, 5.f));
					hpBar2.setSize(Vector2f((float)hp2 * 10.f, 5.f));
					hpBar3.setSize(Vector2f((float)hp3 * 5.f, 5.f));
					hpBar4.setSize(Vector2f((float)hp4 * 5.f, 5.f));
					hpBar5.setSize(Vector2f((float)hp5 * 5.f, 5.f));
					hpBar6.setSize(Vector2f((float)hp6 * 5.f, 5.f));
					hpBarfire.setSize(Vector2f((float)hpfire * 1.5f, 5.f));


					
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
					{
						shapepanda1.move(.7f, 0.f);
						shapepanda1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 2, sprite1SizeX, sprite1SizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
					{
						shapepanda1.move(-.7f, 0.f);
						shapepanda1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 1, sprite1SizeX, sprite1SizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
					{
						shapepanda1.move(0.f, -.7f);
						shapepanda1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, sprite1SizeY * 3, sprite1SizeX, sprite1SizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
					{
						shapepanda1.move(0.f, .7f);
						shapepanda1.setTextureRect(sf::IntRect(sprite1SizeX * animationFrame1, 0, sprite1SizeX, sprite1SizeY));
					}
					animationFrame1++;

					if (animationFrame1 >= 2) {
						animationFrame1 = 0;
					}
					if (shapepanda1.getPosition().y > window.getSize().y - shapepanda1.getGlobalBounds().height)
						shapepanda1.setPosition(shapepanda1.getPosition().x, window.getSize().y - shapepanda1.getGlobalBounds().height);
						
								if (shapepanda1.getPosition().y < 0)
									shapepanda1.setPosition(shapepanda1.getPosition().x, 0);
					//panda2
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					{
						shapepanda2.move(.7f, 0.f);
						shapepanda2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame2, spriteSizeY * 2, spriteSizeX, spriteSizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					{
						shapepanda2.move(-.7f, 0.f);
						shapepanda2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame2, spriteSizeY * 1, spriteSizeX, spriteSizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					{
						shapepanda2.move(0.f, -.7f);
						shapepanda2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame2, spriteSizeY * 3, spriteSizeX, spriteSizeY));
					}
					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					{
						shapepanda2.move(0.f, .7f);
						shapepanda2.setTextureRect(sf::IntRect(spriteSizeX * animationFrame2, 0, spriteSizeX, spriteSizeY));
					}
					if (shapepanda2.getPosition().y > window.getSize().y - shapepanda2.getGlobalBounds().height)
						shapepanda2.setPosition(shapepanda2.getPosition().x, window.getSize().y - shapepanda2.getGlobalBounds().height);

					if (shapepanda2.getPosition().y < 0)
						shapepanda2.setPosition(shapepanda2.getPosition().x, 0);
					animationFrame2++;

					if (animationFrame2 >= 2) {
						animationFrame2 = 0;
					}


					if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
					{
						window_play.close();
					}



					if (door.getGlobalBounds().intersects(shapepanda1.getGlobalBounds())) {
						shapepanda1.setPosition(spawnPoint1);
					}
					window_play.clear();

					window_play.draw(spriteBG);
					window_play.draw(shapepanda1);
					window_play.draw(shapepanda2);
					
					for (size_t i = 0; i < enemies.size(); i++)
					{
						window_play.draw(enemies[i]);
					}
					for (size_t i = 0; i < bullets.size(); i++)
					{
						window_play.draw(bullets[i]);
					}
					for (size_t i = 0; i < bullets1.size(); i++)
					{
						window_play.draw(bullets1[i]);
					}
					//fireboss
					if (score1 >= 100 || score2 >= 100) {
						

						for (size_t i = 0; i < firebosses.size(); i++)
						{
							firebosses[i].move(-4.f, 0.f);
							if (firebosses[i].getPosition().x < 0 - fireboss.getGlobalBounds().width) {
								firebosses.erase(firebosses.begin() + i);
							}
						}

						if (firebossSpawnTimer < 70)
							firebossSpawnTimer++;

						if (firebossSpawnTimer >= 70)
						{
							fireboss.setPosition(window.getSize().x, rand() % int(window.getSize().y - fireboss.getGlobalBounds().height));
							firebosses.push_back(Sprite(fireboss));

							firebossSpawnTimer = 0;
						}
						for (size_t i = 0; i < firebosses.size(); i++)
						{
							if (shapepanda1.getGlobalBounds().intersects(firebosses[i].getGlobalBounds()))
							{
								hp1--;

								firebosses.erase(firebosses.begin() + i);
							}

						}
						for (size_t i = 0; i < firebosses.size(); i++)
						{
							if (shapepanda2.getGlobalBounds().intersects(firebosses[i].getGlobalBounds()))
							{
								hp2--;
								firebosses.erase(firebosses.begin() + i);
							}
						}

						for (size_t i = 0; i < firebosses.size(); i++)
						{
							window_play.draw(firebosses[i]);
						}
						window_play.draw(hpBarfire);
						window_play.draw(fireman);

						for (size_t i = 0; i < bullets.size(); i++)
						{
							if (fireman.getGlobalBounds().intersects(bullets[i].getGlobalBounds()))
							{
								hpfire--;
								score1++;
								bullets.erase(bullets.begin() + i);
							}
						}
						for (size_t i = 0; i < bullets1.size(); i++)
						{
							if (fireman.getGlobalBounds().intersects(bullets1[i].getGlobalBounds()))
							{
								hpfire--;
								score2++;
								bullets1.erase(bullets1.begin() + i);
							}
						}
					


					}

					
					
					window_play.draw(door);
					if (hpfire <= 0) {
						gameover = 2;
						break;
					}

					if (hp1 <= 0 || hp2 <= 0 ){
						
						window_play.draw(text3);
					}
					if (hp3 <= 0 && hp4 <= 0 && hp5 <= 0 && hp6 <= 0) {
						
						gameover = 0;
						
						
					}
					if (hp3 <= 0 && hp4 <= 0 && hp5 <= 0 && hp6 <= 0) {

						window_play.close();


					}
					
					
					
				
					
				
					
					window_play.draw(tree);
					window_play.draw(bamboo4);
					window_play.draw(bamboo3);
					window_play.draw(bamboo2);
					window_play.draw(bamboo);
					window_play.draw(scoreText1);
					window_play.draw(scoreText2);
				
					window_play.draw(hpBar1);
					window_play.draw(hpBar2);
					window_play.draw(hpBar3);
					window_play.draw(hpBar4);
					window_play.draw(hpBar5);
					window_play.draw(hpBar6);


					
					
					window_play.display();

				
				
				

				}//hp>0

			

						if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							{
								window_play.close();
							}

				
				}//while is end
			
				}//page == 0


					if (page_number == 2)
						{
							break;
						}

					if (gameover == 0)
					{

						sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
						sf::RenderWindow window_gameover(desktop, "game over", sf::Style::None);


						while (window_gameover.isOpen())
						{

							sf::Event event;
							while (window_gameover.pollEvent(event))
							{
								if (event.type == sf::Event::Closed)
									window_gameover.close();
							}
							window_gameover.draw(cryingpanda);
							
							
							window_gameover.display();
							

							if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
							{
								window_gameover.close();
							}
						}

					}

					if (gameover == 2) {

						sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
						sf::RenderWindow window_winner(desktop, "window_winner", sf::Style::None);

						while (window_winner.isOpen())
						{

							sf::Event event;
							while (window_winner.pollEvent(event))
							{
								if (event.type == sf::Event::TextEntered)
								{
									if (event.text.unicode < 128)
									{
										playerInput.push_back(event.text.unicode);

									}
									if (event.text.unicode == '\b')
									{
										playerInput.pop_back();
										playerInput.pop_back();

									}

								}
							}
							if (finish.getGlobalBounds().contains(sf::Mouse::getPosition(window_winner).x, sf::Mouse::getPosition(window_winner).y))
							{
								finish.setFillColor(sf::Color::Magenta);
								finish.setStyle(sf::Text::Underlined);
							}
							else
							{		
								finish.setFillColor(sf::Color::Red);
								finish.setStyle(0);
							}
							

									window_winner.draw(winner);

								window_winner.draw(finish);
								window_winner.draw(scoreText1);
								window_winner.draw(scoreText2);
								window_winner.draw(putname);
								playerText.setString(playerInput);
								window_winner.draw(playerText);
								window_winner.display();
								window_winner.clear();
								
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									window_winner.close();
								}
							
								if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
								{
									if (finish.getGlobalBounds().contains(sf::Mouse::getPosition(window_winner).x, sf::Mouse::getPosition(window_winner).y))
									{
										window_winner.close();
										updatascore(playerInput, score3);
										
										gameover = 7;
									}

								}
								
								
							
						}
					}
					

				 if (gameover == 7) {
						sf::VideoMode desktop = sf::VideoMode().getDesktopMode();
						sf::RenderWindow window_winner2(desktop, "window_winner", sf::Style::None);

						while (window_winner2.isOpen())
						{

						
								sf::Event event;
								while (window_winner2.pollEvent(event))
								{
									if (event.type == sf::Event::Closed)
										window_winner2.close();
								}
								
								if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
								{
									window_winner2.close();
								}

								window_winner2.draw(lalala);
								Showscoreboard(window_winner2);
								
								window_winner2.display();
							}
						
						}
					
					
				


		return 0;
	}
}

void Showtexet(int x, int y, string word, int size, sf::RenderWindow& window, sf::Font* font)
{
	sf::Text text;
	text.setFont(*font);
	text.setPosition(x, y);
	text.setString(word);
	text.setCharacterSize(size);
	window.draw(text);
}

void updatascore(string a, int b)
{
	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	vector <pair<int, string>> userScore;
	fp = fopen("./Score.txt", "r");
	if (fp == NULL)
		printf("File not found\n");
		
	for (int i = 0; i < 5; i++)
	{
		fscanf(fp, "%s", &temp);
		name[i] = temp;
		fscanf(fp, "%d", &score[i]);
		userScore.push_back(make_pair(score[i], name[i]));
	}
	
	name[5] = a;
	score[5] = b;
	userScore.push_back(make_pair(score[5], name[5]));
	sort(userScore.begin(), userScore.end());
	fclose(fp);
	fopen("Score.txt", "w");
	for (int i = 5; i >= 1; i--)
	{
		strcpy(temp, userScore[i].second.c_str());
		fprintf(fp, "%s %d\n", temp, userScore[i].first);
	}
	fclose(fp);
}

void Showscoreboard(sf::RenderWindow& window)
{
	sf::Font font;
	font.loadFromFile("font/bubbleboddy Fat.ttf");
	
	FILE* fp;
	char temp[255];
	int score[6];
	string name[6];
	fp = fopen("./Score.txt", "r");
	for (int i = 0; i < 5; i++)
	{
		char no[3] = { '1' + i };
		no[1] = '.';
		no[2] = '\0';
		Showtexet(700, 350 + 100 * i, no, 50, window, &font);
		fscanf(fp, "%s", &temp);
		Showtexet(750, 350 + 100 * i, temp, 50, window, &font);
		fscanf(fp, "%d", &score[i]);
		char sc[10];
		int k = 0, j;
		if (score[i] == 0)
			sc[k++] = 48;
		while (score[i] > 0)
		{
			sc[k++] = score[i] % 10 + 48;
			score[i] /= 10;
		}
		sc[k] = '\0';
		char show[10];
		for (j = 0; j < strlen(sc); j++)
		{
			show[j] = sc[strlen(sc) - 1 - j];
		}
		show[j] = '\0';
		Showtexet(1100, 350 + 100 * i, show, 50, window, &font);
	}
	fclose(fp);

}