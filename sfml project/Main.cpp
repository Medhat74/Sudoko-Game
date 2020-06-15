#include <SFML/Graphics.hpp>
#include <SFML\Audio.hpp>
#include <iostream>
#include "MainMenuu.h"
#include "EndMenuu.h"
#include "levels.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <fstream> 
using namespace std;
using namespace sf;
int page_number;
int page_levels;
int end_page_number;
const int SizeOfSud = 9;
#define Unassigned 0


void draw1(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]); 
void draw1_solve(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]);

void draw2(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]);
void draw3(sf::RenderWindow &window, int i, int j);
void keyboardUsing_Right(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
void keyboardUsing_Right_solve(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
void keyboardUsing_Left(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
void keyboardUsing_Down(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
void keyboardUsing_Up(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
void DrawNumber(sf::RenderWindow &window, int arr[9][9], int arr2[9][9] , int &K);
void DrawNumberSolve(sf::RenderWindow &window, int arr[9][9]); 
void Lose(sf::RenderWindow &window, int K);
void DrawMistake(sf::RenderWindow &window, int M);
bool isSolved(int arr1[9][9], int arr2[9][9], int arr3[9][9]);
void Win(sf::RenderWindow &window);
void DrawHint(sf::RenderWindow &window, int H);
void draw_notes(sf::RenderWindow &window , bool notes);
void draw_arrofnotes(sf::RenderWindow &window, int x, int y, int arr[3][3]);
void draw_window_help(sf::RenderWindow &window);
void save_game(int grid[9][9] , int gridload [9][9] , int gridinput [9][9] , int &h , int &m);
void load_game(int grid[9][9], int gridload[9][9], int gridinput[9][9], int &h, int &m);
void game_pause(sf::RenderWindow &window, bool &p);
void draw_clock(sf::RenderWindow &window ,sf::Time &s , int m);
void game_controles(sf::RenderWindow &window);
//struct SaveGame(int grid[9][9] , int gridlevel[9][9], int arrsolve[9][9], int mistake, int hint);



bool FindUnassignedLocation(int grid[SizeOfSud][SizeOfSud], int &row, int &col);
bool UsedInRow(int grid[SizeOfSud][SizeOfSud], int row, int num);
bool UsedIncoloumn(int grid[SizeOfSud][SizeOfSud], int col, int num);
bool UsedInBox(int grid[SizeOfSud][SizeOfSud], int StartBoxRow, int StartBoxCol, int num);
bool IsSafe(int grid[SizeOfSud][SizeOfSud], int row, int col, int num);
bool IsSafe2(int grid[SizeOfSud][SizeOfSud], int row, int col, int num);
bool UsedInRow2(int grid[SizeOfSud][SizeOfSud], int row, int num);
bool UsedIncoloumn2(int grid[SizeOfSud][SizeOfSud], int col, int num);
bool UsedInBox2(int grid[SizeOfSud][SizeOfSud], int StartBoxRow, int StartBoxCol, int num);
bool SolveOfSud(int grid[SizeOfSud][SizeOfSud]);
int MakeGrid(int grid[SizeOfSud][SizeOfSud]);
void MakeArrPrintEasy(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);
void MakeArrPrintMedium(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);
void MakeArrPrintHard(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);


void DrawSpaceGiant(sf::RenderWindow &window, int i, int j);
void DrawNumberGiant(sf::RenderWindow &window, char arr[16][16], char arr2[16][16]);
bool isSolvedGaint(char arr1[16][16], char arr2[16][16], char arr3[16][16]);









int main()
{
	
	int Mistake = 0, Hint = 2;
	bool pause = false;
	sf::Clock time1;
	Time min , sec;



	
	while (true)
	{
		int x, y;
		while (true) {
			x = 1 + rand() % 9;
			y = 1 + rand() % 9;
			if (x != y)
				break;
		}
		int  GridDrawEasy[SizeOfSud][SizeOfSud] = { 0 }, GridDrawMedium[SizeOfSud][SizeOfSud] = { 0 }, GridDrawHard[SizeOfSud][SizeOfSud] = { 0 }, arr3[9][9] = { 0 }, GridDrawLoad[9][9] = {0};
		int min = 0;
		int Grid[9][9] = {
			{ x, y, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, x, y, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, x, y, 0 },
			{ 0, 0, 0, 0, 0, 0, y, 0, x },
			{ 0, 0, 0, y, 0, x, 0, 0, 0 },
			{ y, 0, x, 0, 0, 0, 0, 0, 0 },
			{ 0, x, y, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, x, y, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, x, y } };

		SolveOfSud(Grid);
		MakeArrPrintEasy(Grid, GridDrawEasy);
		MakeArrPrintMedium(Grid, GridDrawMedium);
		MakeArrPrintHard(Grid, GridDrawHard);

		
		
		
		
		
		sf::RenderWindow window(sf::VideoMode(1500, 1000), "Sudoko Game");

		MainMenuu menu(1500, 1000);
		sf::Texture Photo1;
		if (!Photo1.loadFromFile("Sudoko-Game.png"))
		{
			//error
		}
		
		
		sf::Sprite FirstPage;
		FirstPage.setTexture(Photo1);


		bool exit = false;

		while (window.isOpen())
		{
			sf::Event evnt;
			while (window.pollEvent(evnt))
			{
				
				if (evnt.type == sf::Event::Closed) {
					exit = true;
					window.close();
				}
				
				if (evnt.type == sf::Event::KeyReleased)
				{
					if (evnt.key.code == sf::Keyboard::Up)
					{
						menu.moveUp();
						break;

					}
					
					if (evnt.key.code == sf::Keyboard::Down)
					{
						menu.moveDown();
						break;
					}


					if (evnt.key.code == sf::Keyboard::Return)
					{

						if (menu.MainMenuPressed() == 0)
						{
							window.close();
							page_number = 0;

						}

						if (menu.MainMenuPressed() == 1)
						{
							window.close();
							page_number = 1;

						}

						if (menu.MainMenuPressed() == 2)
						{
							window.close();
							page_number = 2;

						}
						if (menu.MainMenuPressed() == 3)
						{
							window.close();
							page_number = 3;

						}

					}

				}








			}





			window.clear();
			window.draw(FirstPage);
			menu.draw(window);
			window.display();
		}
		
		
		if (exit) {
			break;
		}
		
		
		if (page_number == 0)
		{
			
			
			sf::RenderWindow levels_window(VideoMode(1500, 1000), "Levels");
			sf::Texture photo2;
			if (!photo2.loadFromFile("Sudoko-Game.png"))
			{
				//error
			}
			sf::Sprite Levels;
			Levels.setTexture(photo2);

			levels level_menu(1500 ,1000 );

			bool exitlevel = false;

			while (levels_window.isOpen())
			{
				sf::Event evnt;
				while (levels_window.pollEvent(evnt))
				{

					if (evnt.type == sf::Event::Closed) {
						levels_window.close();
						exitlevel = true;
						break;
					}

					if (evnt.type == sf::Event::KeyReleased)
					{
						if (evnt.key.code == sf::Keyboard::Up)
						{
							level_menu.moveUp();
							break;

						}

						if (evnt.key.code == sf::Keyboard::Down)
						{
							level_menu.moveDown();
							break;
						}


						if (evnt.key.code == sf::Keyboard::Return)
						{

							if (level_menu.LevelsMenuPressed() == 0)
							{
								levels_window.close();
								page_levels = 0;

							}

							if (level_menu.LevelsMenuPressed() == 1)
							{
								levels_window.close();
								page_levels = 1;

							}

							if (level_menu.LevelsMenuPressed() == 2)
							{
								levels_window.close();
								page_levels = 2;

							}

							if (level_menu.LevelsMenuPressed() == 3)
							{
								levels_window.close();
								page_levels = 3;

							}

							if (level_menu.LevelsMenuPressed() == 4)
							{
								levels_window.close();
								page_levels = 4;

							}

						}

					}








				}





				levels_window.clear();
				levels_window.draw(Levels);
				level_menu.draw(levels_window);
				levels_window.display();
			}







			if (exitlevel) {
				continue;
			}




			if (page_levels == 0) {

				sf::RenderWindow fast_window(VideoMode(1500, 1000), "easy");



				sf::Texture photo3;
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);


				while (fast_window.isOpen())
				{




					//min = time1.getElapsedTime();
					sec = time1.getElapsedTime();
					
					
					sf::Event evnt;
					while (fast_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							fast_window.close();

						}
					}




					fast_window.clear();
					fast_window.draw(SudokoGrid);
					fast_window.display();

				}



			}


			if (page_levels == 1) {

				time1.restart();

				sf::RenderWindow easy_window(VideoMode(1500, 1000), "easy");



				sf::Texture photo3;
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);

				sf::Texture photo4;
				if (!photo4.loadFromFile("Sudoko-Game.png"))
				{
					//error
				}
				sf::Sprite LosePhoto;
				LosePhoto.setTexture(photo4);


				int count1 = 0, count2 = 0;
				bool /*yeb = false,*/ notes = false ;
				int x, y, k = -1,  Mistake = 0, Hint = 2, arrnote[3][3] = {};
				/*std::pair <int , int  > position;
				vector <int> notes;
				pair < pair.position  , notes > value;
				*/

				EndMenuu end_menu (1500,1000);








				while (easy_window.isOpen())
				{




					//min = time1.getElapsedTime();
					sec = time1.getElapsedTime();






					easy_window.clear();
					easy_window.draw(SudokoGrid);
					draw1(easy_window, GridDrawEasy);
					DrawMistake(easy_window, Mistake);
					DrawHint(easy_window, Hint);
					draw_notes(easy_window, notes);
					draw_arrofnotes(easy_window, count1, count2, arrnote);
					draw_clock(easy_window, sec , min);
					game_controles(easy_window);


					if (GridDrawEasy[count1][count2] == 0) {

						draw3(easy_window, count2, count1);

					}
					DrawNumber(easy_window, arr3, Grid, Mistake);

					if (Mistake >= 3) {
						//Lose(easy_window, Mistake);
						easy_window.clear();
						easy_window.draw(LosePhoto);
						Lose(easy_window, Mistake);

					}

					if (isSolved(GridDrawEasy, arr3, Grid)) {
						Win(easy_window);
					}


					


					sf::Event evnt;
					while (easy_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							easy_window.close();
							save_game(Grid, GridDrawEasy , arr3 , Hint , Mistake);
							
						}


						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3) {
								easy_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								//std::cout << "right click" << std::endl;
								keyboardUsing_Right(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;
								

								x = count1; y = count2;

								if (notes) {
									arrnote[1][1] = 1;
									break;

								}
								arr3[x][y] = 1;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 2;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 3;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								k++;
								x = count1; y = count2;
								arr3[x][y] = 4;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 5;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								std::cout << "6 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 6;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								std::cout << "7 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 7;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 8;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 9;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "C click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								x = count1; y = count2;
								if (Hint > 0) {
									arr3[x][y] = Grid[x][y];
									Hint--;
								}
								
								break;

							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(easy_window , pause);
								

								break;




							case sf::Keyboard::N:
								std::cout << "N click" << std::endl;
								x = count1; y = count2;
								if (notes == false) {
									notes = true;
									break;
								}
								if (notes == true) {
									notes = false;
								}
								break;


							case sf::Keyboard::Num0:
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										cout << Grid[i][j] << " ";
									}
									cout << endl;
									break;


								}
								break;



							}

							break;
						}
					}














					easy_window.display();


				}
			}

			if (page_levels == 2) {

				sf::RenderWindow Medium_window(VideoMode(1500, 1000), "Medium");


				time1.restart();


				sf::Texture photo3;
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);
				int count1 = 0, count2 = 0;
				bool /*yeb = false,*/ notes = false ;
				int x, y, k = -1, arr3[9][9] = { 0 }, Mistake = 0, Hint = 2, arrnote[3][3] = {};
				/*std::pair <int , int  > position;
				vector <int> notes;
				pair < pair.position  , notes > value;
				*/










				while (Medium_window.isOpen())
				{







					sec = time1.getElapsedTime();







					Medium_window.clear();
					Medium_window.draw(SudokoGrid);
					draw1(Medium_window, GridDrawMedium);
					DrawMistake(Medium_window, Mistake);
					DrawHint(Medium_window, Hint);
					draw_notes(Medium_window, notes);
					draw_arrofnotes(Medium_window, count1, count2, arrnote);
					draw_clock(Medium_window, sec, min);




					if (GridDrawMedium[count1][count2] == 0) {

						draw3(Medium_window, count2, count1);

					}
					DrawNumber(Medium_window, arr3, Grid, Mistake);

					if (Mistake >= 3) {
						Lose(Medium_window, Mistake);
					}

					if (isSolved(GridDrawMedium, arr3, Grid)) {
						Win(Medium_window);
					}


					sf::Event evnt;
					while (Medium_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							

							save_game(Grid, GridDrawMedium, arr3, Hint, Mistake);





							Medium_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3) {
								Medium_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								//std::cout << "right click" << std::endl;
								keyboardUsing_Right(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;


								x = count1; y = count2;

								if (notes) {
									arrnote[1][1] = 1;
									break;

								}
								arr3[x][y] = 1;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 2;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 3;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								k++;
								x = count1; y = count2;
								arr3[x][y] = 4;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 5;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								std::cout << "6 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 6;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								std::cout << "7 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 7;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 8;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 9;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "C click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								x = count1; y = count2;
								if (Hint > 0) {
									arr3[x][y] = Grid[x][y];
									Hint--;
								}

								break;

							
							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(Medium_window, pause);


								break;
							
							case sf::Keyboard::N:
								std::cout << "N click" << std::endl;
								x = count1; y = count2;
								if (notes == false) {
									notes = true;
									break;
								}
								if (notes == true) {
									notes = false;
								}
								break;

							case sf::Keyboard::Num0:
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										cout << Grid[i][j] << " ";
									}
									cout << endl;
									break;


								}
								break;



							}

							break;
						}
					}














					Medium_window.display();


				}

			}

			if (page_levels == 3) {
				sf::RenderWindow hard_window(VideoMode(1500, 1000), "Hard");



				sf::Texture photo3;
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);
				int count1 = 0, count2 = 0;
				bool /*yeb = false,*/ notes = false;
				int x, y, k = -1, arr3[9][9] = { 0 }, Mistake = 0, Hint = 2, arrnote[3][3] = {};
				/*std::pair <int , int  > position;
				vector <int> notes;
				pair < pair.position  , notes > value;
				*/




				time1.restart();





				while (hard_window.isOpen())
				{






					sec = time1.getElapsedTime();







					hard_window.clear();
					hard_window.draw(SudokoGrid);
					draw1(hard_window, GridDrawHard);
					DrawMistake(hard_window, Mistake);
					DrawHint(hard_window, Hint);
					draw_notes(hard_window, notes);
					draw_arrofnotes(hard_window, count1, count2, arrnote);
					draw_clock(hard_window, sec, min);




					if (GridDrawHard[count1][count2] == 0) {

						draw3(hard_window, count2, count1);

					}
					DrawNumber(hard_window, arr3, Grid, Mistake);

					if (Mistake >= 3) {
						Lose(hard_window, Mistake);

					}

					if (isSolved(GridDrawHard, arr3, Grid)) {
						Win(hard_window);
					}


					sf::Event evnt;
					while (hard_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							save_game(Grid, GridDrawHard, arr3, Hint, Mistake);


							hard_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3) {
								hard_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								//std::cout << "right click" << std::endl;
								keyboardUsing_Right(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;


								x = count1; y = count2;

								if (notes) {
									arrnote[1][1] = 1;
									break;

								}
								arr3[x][y] = 1;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 2;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 3;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								k++;
								x = count1; y = count2;
								arr3[x][y] = 4;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 5;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								std::cout << "6 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 6;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								std::cout << "7 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 7;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 8;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 9;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "C click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								x = count1; y = count2;
								if (Hint > 0) {
									arr3[x][y] = Grid[x][y];
									Hint--;
								}

								break;

							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(hard_window, pause);


								break;
							
							case sf::Keyboard::N:
								std::cout << "N click" << std::endl;
								x = count1; y = count2;
								if (notes == false) {
									notes = true;
									break;
								}
								if (notes == true) {
									notes = false;
								}
								break;

							case sf::Keyboard::Num0:
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										cout << Grid[i][j] << " ";
									}
									cout << endl;
									break;


								}
								break;



							}

							break;
						}
					}














					hard_window.display();


				}
			}


			if (page_levels == 4) {

				sf::RenderWindow giant_window(VideoMode(1500, 1000), "Giant");

				int count1 = 0, count2 = 0;
				int x, y;
				char arr_user[16][16] = {}, Mistake = 0, Hint = 2;


				sf::Texture photo3;
				///this is not the photo
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);


				while (giant_window.isOpen())
				{


					giant_window.clear();
					giant_window.draw(SudokoGrid);
					//draw1(giant_window, GridDrawGiant);
					DrawMistake(giant_window, Mistake);
					DrawHint(giant_window, Hint);

					//error need grid giant
					DrawNumberGiant(giant_window, arr_user, );

					if (GridDrawHard[count1][count2] == 0) {
						///position :
						DrawSpaceGiant(giant_window, count2, count1);

					}

					
					if (Mistake >= 3) {
						Lose(giant_window, Mistake);

					}

					if (isSolvedGaint(, arr_user,)) {
						Win(giant_window);
					}


					sf::Event evnt;
					while (giant_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							giant_window.close();

						}
					}




					giant_window.clear();
					giant_window.draw(SudokoGrid);
					giant_window.display();

				}



			}




		}





		if (page_number == 1)
		{
			/*sf::RenderWindow Help_window(VideoMode(1800, 1000), "options");
			while (Help_window.isOpen())
			{
				sf::Event evnt;
				while (Help_window.pollEvent(evnt))
				{
					if (evnt.type == sf::Event::Closed)

						Help_window.close();
				}*/
				

				load_game(Grid , GridDrawLoad , arr3 , Hint , Mistake) ;

				sf::RenderWindow easy_window(VideoMode(1500, 1000), "easy");



				sf::Texture photo3;
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);

				sf::Texture photo4;
				if (!photo4.loadFromFile("Sudoko-Game.png"))
				{
					//error
				}
				sf::Sprite LosePhoto;
				LosePhoto.setTexture(photo4);


				int count1 = 0, count2 = 0;
				/*
				bool /*yeb = false, notes = false;
				int x, y, k = -1, Mistake = 0, Hint = 2, arrnote[3][3] = {};
				/*std::pair <int , int  > position;
				vector <int> notes;
				pair < pair.position  , notes > value;
				*//**/
				bool notes = false; 
				int k = 0, arrnote[3][3] = {};
				EndMenuu end_menu(1500, 1000);





				//Mistake /= 9;



				while (easy_window.isOpen())
				{














					easy_window.clear();
					easy_window.draw(SudokoGrid);
					draw1(easy_window, GridDrawLoad);
					DrawMistake(easy_window, Mistake);
					DrawHint(easy_window, Hint);
					//draw_notes(easy_window, notes);
					//draw_arrofnotes(easy_window, count1, count2, arrnote);




					if (GridDrawLoad[count1][count2] == 0) {

						draw3(easy_window, count2, count1);

					}
					DrawNumber(easy_window, arr3, Grid, Mistake);

					/*if (Mistake >= 3) {
						Lose(easy_window, Mistake);
						//easy_window.clear();
						//easy_window.draw(LosePhoto);
					}*/

					if (isSolved(GridDrawLoad, arr3, Grid)) {
						Win(easy_window);
					}


					sf::Event evnt;
					while (easy_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							easy_window.close();
							ofstream out("saved sudoku.txt"); //saving array
							for (int i = 0; i < 9; i++)
							{
								for (int j = 0; j < 9; j++)
								{
									out << Grid[i][j] << " ";
									out << GridDrawLoad[i][j] << " ";
									out << arr3[i][j] << " ";

								} //end for j
								cout << endl;

							} //end for i
							out << Mistake;
							out << Hint; ;

							out.close();



						}


						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3) {
								easy_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								//std::cout << "right click" << std::endl;
								keyboardUsing_Right(count2, count1, GridDrawLoad);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left(count2, count1, GridDrawLoad);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down(count2, count1, GridDrawLoad);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up(count2, count1, GridDrawLoad);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;


								x = count1; y = count2;

								if (notes) {
									arrnote[1][1] = 1;
									break;

								}
								arr3[x][y] = 1;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 2;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 3;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								k++;
								x = count1; y = count2;
								arr3[x][y] = 4;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 5;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								std::cout << "6 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 6;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								std::cout << "7 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 7;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 8;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 9;
								if (arr3[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "C click" << std::endl;
								x = count1; y = count2;
								arr3[x][y] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								x = count1; y = count2;
								if (Hint > 0) {
									arr3[x][y] = Grid[x][y];
									Hint--;
								}

								break;

							
							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(easy_window, pause);


								break;
							
							case sf::Keyboard::N:
								std::cout << "N click" << std::endl;
								x = count1; y = count2;
								if (notes == false) {
									notes = true;
									break;
								}
								if (notes == true) {
									notes = false;
								}
								break;

							case sf::Keyboard::Num0:
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										cout << Grid[i][j] << " ";
									}
									cout << endl;
									break;


								}
								break;



							}

							break;
						}
					}














					easy_window.display();


				}


				//Help_window.clear();
				//Draw;
				//Help_window.display();


			}
			//break;
		






		if (page_number == 2)
		{
			sf::RenderWindow solve_window(VideoMode(1500, 1000), "Medium");



			sf::Texture photo3;
			if (!photo3.loadFromFile("121212.png"))
			{
				//error
			}
			sf::Sprite SudokoGrid;
			SudokoGrid.setTexture(photo3);
			int count1 = 0, count2 = 0;
			bool n;
			int x, y, ArrToSolve[9][9] = { 0 }, Arr[9][9] = { 0 };
			










			while (solve_window.isOpen())
			{














				solve_window.clear();
				solve_window.draw(SudokoGrid);
				draw1_solve(solve_window, ArrToSolve);
				//DrawMistake(solve_window, Mistake);
				//DrawHint(solve_window, Hint);
				//draw_notes(solve_window, notes);
				//draw_arrofnotes(solve_window, count1, count2, arrnote);

				draw3(solve_window, count2, count1);

				DrawNumberSolve(solve_window, Arr);

				
				/*if (ArrToSolve[count1][count2] == 0) {

					draw3(solve_window, count2, count1);

				}*/
				//DrawNumber(solve_window, ArrToSolve, ArrToSolve, Mistake);

				


				sf::Event evnt;
				while (solve_window.pollEvent(evnt))
				{
					if (evnt.type == sf::Event::Closed)

						solve_window.close();



					switch (evnt.type)
					{
					case sf::Event::KeyPressed:
						std::cout << "key has been pressed" << std::endl;

						/*if (Mistake >= 3) {
							solve_window.close();
						}*/





						switch (evnt.key.code)
						{
						case sf::Keyboard::Right:
							//std::cout << "right click" << std::endl;
							keyboardUsing_Right(count2, count1, Arr);
							break;

						case sf::Keyboard::Left:
							std::cout << "left click" << std::endl;
							keyboardUsing_Left(count2, count1, Arr);
							break;

						case sf::Keyboard::Down:
							std::cout << "Down click" << std::endl;
							keyboardUsing_Down(count2, count1, Arr);
							break;

						case sf::Keyboard::Up:
							std::cout << "Up click" << std::endl;
							keyboardUsing_Up(count2, count1, Arr);
							break;

						case sf::Keyboard::Num1:
							std::cout << "1 click" << std::endl;


							x = count1; y = count2;
							ArrToSolve[x][y] = 1;
							break;

						case sf::Keyboard::Num2:
							std::cout << "2 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 2;
							break;

						case sf::Keyboard::Num3:
							std::cout << "3 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 3;
							
							break;

						case sf::Keyboard::Num4:
							std::cout << "4 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 4;
							
							break;

						case sf::Keyboard::Num5:
							std::cout << "5 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 5;
							
							break;

						case sf::Keyboard::Num6:
							std::cout << "6 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 6;
							
							break;

						case sf::Keyboard::Num7:
							std::cout << "7 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 7;
							
							break;

						case sf::Keyboard::Num8:
							std::cout << "8 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 8;
							break;

						case sf::Keyboard::Num9:
							std::cout << "9 click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 9;
							
							break;

						case sf::Keyboard::BackSpace:
							std::cout << "C click" << std::endl;
							x = count1; y = count2;
							ArrToSolve[x][y] = 0;
							break;
						
						case sf::Keyboard::H:
							std::cout << "h click" << std::endl;
							for (int i = 0; i < 9; i++) {
								for (int j = 0; j < 9; j++) {
									Arr[i][j] = 0;
								}
								cout << endl;
							}
							break;
						
						case sf::Keyboard::S:
							cout << "s" << endl;
							int arrsolve[9][9] = {0};
							for (int i = 0; i < 9; i++) {
								for (int j = 0; j < 9; j++) {
									arrsolve[i][j] = ArrToSolve[i][j];
								}
								cout << endl;
							}
							for (int i = 0; i < 9; i++) {
								for (int j = 0; j < 9; j++) {
									cout << arrsolve[i][j] << " ";
								}
								cout << endl;
							}
							if (SolveOfSud(arrsolve)) {
									for (int i = 0; i < 9; i++) {
										for (int j = 0; j < 9; j++) {
											Arr[j][i] = arrsolve[j][i] - ArrToSolve[j][i];
										}
									}
									break;
								}
							else {
								solve_window.close();
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										Arr[j][i] = 0;
										arrsolve[j][i] = 0;
									}
								}
								break;
							}
							

						
						/*case sf::Keyboard::H:
							std::cout << "h click" << std::endl;
							x = count1; y = count2;
							if (Hint > 0) {
								ArrToSolve[x][y] = Grid[x][y];
								Hint--;
							}*/


						}
						break; 
					}
					break;
				}
				solve_window.display();

			}
		}
		if (page_number == 3) {
			break;
		}

	}

	return 0;
}









void sudoko(float width, float hight, sf::RenderWindow &window) {
//void draw(sf::RenderWindow &window);

	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text[9][9];
	text[0][0].setFont(font);
	text[0][0].setFillColor(sf::Color::Blue);
	text[0][0].setString("1");
	text[0][0].setCharacterSize(30);
	text[0][0].setPosition(sf::Vector2f(32, 22));

	
		window.draw(text[0][0]);
	

	
}
/*void draw(sf::RenderWindow &window) {
	window.draw
}*/
/*void draw1(sf::RenderWindow &window,int arr) {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			string s1 = arr[i][j];
			text.setString(s1);
			text.setPosition(65 * j + 30, 65 * i + 1);
			windowgrid.draw(text);
		}
	}
	window.draw(s[i]);
}*/

void draw1(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;

	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			/*int x, y;
			x = rand() % 9;
			y = rand() % 9;*/


			if (arr[j][i]==0)
				continue;
			string s1;
			s1 = to_string(arr[j][i]);
			text.setFont(font);
			text.setString(s1);
			text.setCharacterSize(60);
			text.setFillColor(sf::Color::Black);
			text.setPosition(300 + i * 108.5, 22 + j * 110);
			window.draw(text);
		}
	}


}

void draw1_solve(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]) {

	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;


	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			/*int x, y;
			x = rand() % 9;
			y = rand() % 9;*/


			if (arr[j][i] == 0)
				continue;
			string s1;
			s1 = to_string(arr[j][i]);
			text.setFont(font);
			text.setString(s1);
			text.setCharacterSize(60);
			int num = arr[j][i];
			if (IsSafe2(arr,j,i,num))
				text.setFillColor(sf::Color::Black);
			else 
				text.setFillColor(sf::Color::Red);

			text.setPosition(300 + i * 108.5, 22 + j * 110);
			window.draw(text);
		}
	}

}

void draw2(sf::RenderWindow &window,int arr[SizeOfSud][SizeOfSud]) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	string s[9][9];

	int i = 0, j = 0;



	/*for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			/*int x, y;
			x = rand() % 9;
			y = rand() % 9;


			if (arr[i][j] == 0)
				continue;
			//string s[9][9];
			s[i][j]	= to_string(arr[i][j]);
			text.setFont(font);
			text.setString(s[i][j]);
			text.setCharacterSize(30);
			text.setFillColor(sf::Color::Black);
			text.setPosition(32 + i * 52.5, 22 + j * 52);
		}
	}*/
	while (window.isOpen()) {
		/*sf::Texture Photo3;
		if (!Photo3.loadFromFile("space.jpg"))
		{
			//error
		}


		sf::Sprite space;
		space.setTexture(Photo3);*/
		
		
		
		
		
		
		
		if (i == 9 && j == 9) {
			break;
		}
		for (i = 0; i < 9; i++) {
			for (j = 0; j < 9; j++) {

				int x, y;
				x = rand() % 9;
				y = rand() % 9;


				if (arr[i][j] == 0)
				{
					if (arr[i][j] == arr[x][y])
						continue;
					string s = "|";
					text.setFont(font);
					text.setString(s);
					text.setCharacterSize(30);
					text.setFillColor(sf::Color::Black);
					text.setPosition(34 + 1 * 52.5, 20 + 0 * 52);
					//window.draw(text);
				}
			}
		}
		

		
	}
	window.draw(text);

}

void game_controles(sf::RenderWindow &window) {
	Font fon;
	if (!fon.loadFromFile("aldhabi.ttf")) {}


	Text tex;
	tex.setFont(fon);
	tex.setString("controles");
	tex.setCharacterSize(100);
	tex.setFillColor(sf::Color::Blue);
	tex.setPosition(1250, 300 );

	window.draw(tex); 
}



void draw3(sf::RenderWindow &window, int i, int j) {
	string space = ":";

	Font fon;
	if (!fon.loadFromFile("ArialCE.ttf")) {}


	Text tex;
	tex.setFont(fon);
	tex.setString(space);
	tex.setCharacterSize(60);
	tex.setFillColor(sf::Color::Black);
	tex.setPosition(310 + i * 108.5, 25 + j * 110);
	

	int x;
		 x = rand() % 2;


	
	if (x == 1)
		window.draw(tex);


}

void keyboardUsing_Right(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
	while (true)
	{
		
		if (j > -1 && j < 9) 
		{
			if (i > -1 && i < 9) 
			{
				i++;
				if (arr[j][i] == 0) {
					break;
				}
				else continue;
			}
			else
			{
				
				j++;
				i = 0;
				if (arr[j][i] == 0)
					break;
				else continue;
			}
		}
		else
		{
			i = 0;
			j = 0;
			continue;
		}
	}

	

}

void keyboardUsing_Right_solve(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
	while (true)
	{

		if (j > -1 && j < 9)
		{
			if (i > -1 && i < 9)
			{
				i++;
				break;
			}
			else
			{

				j++;
				i = 0;
				break;
			}
		}
		else
		{
			i = 0;
			j = 0;
			continue;
		}
	}



}

void keyboardUsing_Left(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
	while (true)
	{

		if (j >= 0 && j <= 8)
		{
			if (i >= 0 && i <= 8)
			{
				i--;
				if (arr[j][i] == 0) {
					break;
				}
				else continue;
			}
			else
			{

				j--;
				i = 8;
				if (arr[j][i] == 0)
					break;
				else continue;
			}
		}
		else
		{
			i = 8;
			j = 8;
			continue;
		}
	}


}


void keyboardUsing_Down(int &i, int &j, int arr[SizeOfSud][SizeOfSud]){

	while (true)
	{

		
			if (j >= 0 && j < 9)
			{
				j++;
				if (arr[j][i] == 0) {
					break;
				}
				else continue;
			}
			else if ( j > 8)
			{

				
				j = 0;
				if (arr[j][i] == 0)
					break;
				else continue;
			}
		
		
	}



}


void keyboardUsing_Up(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {

	while (true)
	{


		if (j >= 0 && j < 9)
		{
			j--;
			if (arr[j][i] == 0) {
				break;
			}
			else continue;
		}
		else if (j < 0)
		{


			j = 8;
			if (arr[j][i] == 0)
				break;
			else continue;
		}


	}

}

void DrawNumber(sf::RenderWindow &window, int arr[9][9], int arr2[9][9], int &K) {
	Font fon;
	if (!fon.loadFromFile("ArialCE.ttf")) {}

	
	Text tex;
	bool found = false ; 
	for (int m = 0; m < 9; m++) {
		for (int n = 0; n < 9; n++) {
			if (arr[n][m] == 0)
				continue;
				
			string s = to_string(arr[n][m]);
				
				tex.setFont(fon);
				tex.setString(s);
				tex.setCharacterSize(60);
				tex.setPosition(300 + m * 108.5, 25 + n * 110);
				if (arr[n][m] == arr2[n][m] )
					tex.setFillColor(sf::Color::Blue);
				else if (arr[n][m] != arr2[n][m] && arr[n][m] != 0) {
					tex.setFillColor(sf::Color::Red);
					found = true;
				}
				

				window.draw(tex);


		}
	}

	//window.draw(tex );
}


void DrawNumberSolve(sf::RenderWindow &window, int arr[9][9]) {
	Font fon;
	if (!fon.loadFromFile("ArialCE.ttf")) {}


	Text tex;
	bool found = false;
	for (int m = 0; m < 9; m++) {
		for (int n = 0; n < 9; n++) {
			if (arr[n][m] == 0)
				continue;

			string s = to_string(arr[n][m]);

			tex.setFont(fon);
			tex.setString(s);
			tex.setCharacterSize(60);
			tex.setPosition(300 + m * 108.5, 25 + n * 110);
			tex.setFillColor(sf::Color::Blue);
			


			window.draw(tex);


		}
	}

	//window.draw(tex );
}

void Lose(sf::RenderWindow &window, int K) {
	//window.display();
	sf::Texture photo;
	if (!photo.loadFromFile("Sudoko-Game.png"))
	{
		//error
	}
	sf::Sprite lose;
	lose.setTexture(photo);
	
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;

	
			text.setFont(font);
			text.setString("Game over");
			text.setCharacterSize(100);
			text.setFillColor(sf::Color::White);
			text.setPosition(60, 100);


			text2.setFont(font);
			text2.setString("press any key to continu");
			text2.setCharacterSize(41);
			text2.setFillColor(sf::Color::Blue);
			text2.setPosition(10, 300);

			window.draw(lose);
			window.draw(text);
			window.draw(text2);
			
}

void DrawMistake(sf::RenderWindow &window, int M) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;

	//string s = to_string(a);


	/*text.setFont(font);
	text.setString("Mistake:   /3 ");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(10, 560);*/


	text2.setFont(font);
	text2.setString(to_string(M));
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::Red);
	text2.setPosition(190, 190);

	window.draw(text);
	window.draw(text2);

}

bool isSolved(int arr1[9][9], int arr2[9][9], int arr3[9][9]) {
	int arr4[9][9] = { 0 };
	bool Found = true;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr1[i][j] != 0)
				arr4[i][j] = arr1[i][j];
			if (arr2[i][j] != 0)
				arr4[i][j] = arr2[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr4[i][j] != arr3[i][j])
				Found = false;
		}
	}
	return Found;

}

void Win(sf::RenderWindow &window) {
	//window.display();
	window.clear(sf::Color::Black);

	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;
	sf::Text text3;


	text.setFont(font);
	text.setString("You Won");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	text.setPosition(60, 100);


	text2.setFont(font);
	text2.setString("press any key to continu");
	text2.setCharacterSize(41);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(10, 300);

	

	window.draw(text);
	window.draw(text2);

}

void draw_clock(sf::RenderWindow &window, sf::Time &s, int m) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;
	sf::Text text3;

	int n = s.asSeconds();
	while (true) {
		int i = 0;
		if (n / 60 == m) {
			m= m ;
			break;
		}
		m++;
		
	}
	text.setFont(font);
	text.setString(to_string(n%60));
	text.setCharacterSize(40);
	text.setFillColor(sf::Color::White);
	text.setPosition(1450, 50);


	text2.setFont(font);
	text2.setString(to_string(m));
	text2.setCharacterSize(40);
	text2.setFillColor(sf::Color::White);
	text2.setPosition(1400, 50);

	text3.setFont(font);
	text3.setString(":");
	text3.setCharacterSize(40);
	text3.setFillColor(sf::Color::White);
	text3.setPosition(1440, 48);


	window.draw(text);
	window.draw(text2);
	window.draw(text3);
}

void DrawHint(sf::RenderWindow &window, int H) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;

	//string s = to_string(a);


	/*text.setFont(font);
	text.setString("Hint:   /2 ");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(388, 560);
	*/

	text2.setFont(font);
	text2.setString(to_string(H));
	text2.setCharacterSize(70);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(150, 50);

	window.draw(text);
	window.draw(text2);
}

void draw_notes(sf::RenderWindow &window, bool notes) {
	/*sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;

	//string s = to_string(a);


	text.setFont(font);
	text.setString("Notes : ");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::White);
	text.setPosition(200, 560);


	text2.setFont(font);
	text2.setCharacterSize(30);
	text2.setPosition(300, 560);

	if (notes) {
		text2.setString("On");
		text2.setFillColor(sf::Color::Green);

	}

	else {
		text2.setString("Off");
		text2.setFillColor(sf::Color::Red);

	}
	window.draw(text);
	window.draw(text2);*/
}

void draw_arrofnotes(sf::RenderWindow &window, int x, int y, int arr[3][3]) {
	Font fon;
	if (!fon.loadFromFile("ArialCE.ttf")) {}
	Text tex;
	bool found = false;
	for (int m = 0; m < 3; m++) {
		for (int n = 0; n < 3; n++) {
			if (arr[n][m] == 0)
				continue;

			string s = to_string(arr[n][m]);

			tex.setFont(fon);
			tex.setString(s);
			tex.setCharacterSize(15);
			tex.setPosition((34 + x * 52.5) - 25 + m * 10 , (20 + y * 52) - 25 + n * 10 ) ;
			tex.setFillColor(sf::Color::Black);
			}


			window.draw(tex);


		}
}


void save_game(int grid[9][9], int gridload[9][9], int gridinput[9][9], int &h, int &m) {
	int GridLoad[9][9] = { 0 }, more[2] = { h , m };
	int mm = 0;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			GridLoad[i][j] = gridload[i][j];
		}
	}

	ofstream out("saved sudoku.txt"); //saving array
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			out << grid[i][j] << " ";
			out << GridLoad[i][j] << " ";
			out << gridinput[i][j] << " ";

		} //end for j
		cout << endl;

	} //end for i
	out << h;
	out << m;
	out.close();

}

void load_game(int grid[9][9], int gridload[9][9], int gridinput[9][9], int &h, int &m) {
	int GridLoad[9][9], more[2];
	int mm = 0;
	ifstream in("saved sudoku.txt"); //load from file
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			in >> grid[i][j];
			in >> GridLoad[i][j];
			in >> gridinput[i][j];
		}
		cout << endl;
	}
	in >> h;
	in >> m;
	in.close();

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gridload[i][j] = GridLoad[i][j];
		}
	}
	h /= 10;
	m %= 10;
	//m /= 2;

}


void game_pause(sf::RenderWindow &window , bool &p) {
	while (p) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;

	sf::Texture photo3;
	if (!photo3.loadFromFile("121212.png"))
	{
		//error
	}
	sf::Sprite SudokoGrid;
	SudokoGrid.setTexture(photo3);

	text.setFont(font);
	text.setString("||");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::Black);
	text.setPosition(715, 390);
	Event evnt;
	while (window.pollEvent(evnt))
	{



	switch (evnt.type)
	{
	case sf::Event::KeyPressed:
	std::cout << "key has been pressed" << std::endl;

	p = false;
	break;
	}
	}

	sf::CircleShape shape(70);
	shape.setFillColor(sf::Color::White);
	shape.setPosition(670, 400);
	// set a 10-pixel wide orange outline
	shape.setOutlineThickness(10);
	shape.setOutlineColor(sf::Color(250, 150, 100));




	window.draw(SudokoGrid);

	window.draw(shape);

	window.draw(text);

	window.display();


	}
}









void draw_window_help(sf::RenderWindow &window) {
	sf::Font font1;
	if (!font1.loadFromFile("aldhabi.ttf")) {}

	sf::Font font2;
	if (!font2.loadFromFile("BebasNeue.ttf")) {}

	sf::Font font3;
	if (!font3.loadFromFile("Italic.ttf")) {}

	sf::Font font4;
	if (!font4.loadFromFile("minya-nouvelle-bd-it.ttf")) {}

	sf::Font font5;
	if (!font5.loadFromFile("minya-nouvelle-bd-it.ttf")) {}

	sf::Font font6;
	if (!font6.loadFromFile("minya-nouvelle-bd-it.ttf")) {}

	sf::Font font7;
	if (!font7.loadFromFile("minya-nouvelle-bd-it.ttf")) {}
}








bool SolveOfSud(int grid[SizeOfSud][SizeOfSud])
{
	int row, col;
	if (!FindUnassignedLocation(grid, row, col))
		return true;
	for (int num = 1; num <= 9; num++)
	{
		if (IsSafe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (SolveOfSud(grid))
				return true;
			grid[row][col] = Unassigned;
		}
	}
	return false;
}
bool IsSafe(int grid[SizeOfSud][SizeOfSud], int row, int col, int num) {
	return !UsedInRow(grid, row, num)
		&& !UsedIncoloumn(grid, col, num)
		&& !UsedInBox(grid, row - row % 3, col - col % 3, num)
		&& grid[row][col] == Unassigned;
}
bool FindUnassignedLocation(int grid[SizeOfSud][SizeOfSud], int &row, int &col)
{
	for (row = 0; row < SizeOfSud; row++)
		for (col = 0; col < SizeOfSud; col++)
			if (grid[row][col] == Unassigned)
				return true;
	return false;
}
bool UsedInRow(int grid[SizeOfSud][SizeOfSud], int row, int num) {
	for (int col = 0; col < SizeOfSud; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}
bool UsedIncoloumn(int grid[SizeOfSud][SizeOfSud], int col, int num) {
	for (int row = 0; row < SizeOfSud; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}
bool UsedInBox(int grid[SizeOfSud][SizeOfSud], int StartBoxRow, int StartBoxCol, int num)
{
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + StartBoxRow][col + StartBoxCol] == num)
				return true;
	return false;

}

void PrintSolveOfSud(int grid[SizeOfSud][SizeOfSud]) {
	cout << "\nThe Solve of this Sudoko is : \n";
	for (int row = 0; row < SizeOfSud; row++)
	{
		for (int col = 0; col < SizeOfSud; col++)
			cout << grid[row][col] << "\t";
		cout << "\n";
	}
	cout << endl;
}
int MakeGrid(int grid[SizeOfSud][SizeOfSud]) {
	srand((unsigned int)time(NULL));
	int num;
	int g = 0;
	int f = 0;


	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			grid[i][j] = -1 + rand() % 2;
			if (grid[i][j] == -1)
				g++;
		}
	}


	/*for (int i = 0; i < 9; i++) {
	for (int j = 0; j < 9; j++) {
	cout << grid[i][j] << "\t";
	}
	cout << endl;
	}*/

	//cout << "****************************  " << "g is : " << g << "*******************" << endl;



	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{

			if (grid[i][j] == -1)

				//num = 1 + rand() % 9;
				//grid[i][j] = num;



			{


				num = 1 + rand() % 9;
				while (true)
				{
					if (IsSafe2(grid, i, j, num)) {
						grid[i][j] = num;
						//cout << grid[i][j] << " ";
						int f = 0;
						f++;
						break;
					}
					//srand((unsigned int)time(NULL));
					num = 1 + rand() % 9;
				}
			}
		}
	}
	//cout << "\n f is :" << f << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << "\t";
		}
		cout << endl;
	}


	return 0;
}
bool IsSafe2(int grid[SizeOfSud][SizeOfSud], int row, int col, int num) {
	return !UsedInRow2(grid, row, num)
		&& !UsedIncoloumn2(grid, col, num)
		&& !UsedInBox2(grid, row - row % 3, col - col % 3, num);

}
bool UsedInRow2(int grid[SizeOfSud][SizeOfSud], int row, int num) {
	int i = 0;
	for (int col = 0; col < SizeOfSud; col++)
		if (grid[row][col] == num)
			i++;
	if (i >= 2 )
		return true;
	else 
		return false;
}
bool UsedIncoloumn2(int grid[SizeOfSud][SizeOfSud], int col, int num) {
	int i = 0;
	for (int row = 0; row < SizeOfSud; row++)
		if (grid[row][col] == num)
			i++;

	if (i >= 2)
		return true;
	else
		return false;
	
}
bool UsedInBox2(int grid[SizeOfSud][SizeOfSud], int StartBoxRow, int StartBoxCol, int num)
{
	int i = 0;
	for (int row = 0; row < 3; row++)
		for (int col = 0; col < 3; col++)
			if (grid[row + StartBoxRow][col + StartBoxCol] == num)
				i++ ;

	if (i >= 2)
		return true;
	else
		return false;
}

void MakeArrPrintEasy(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arrprint[i][j] = arr[i][j];
		}
	}
	int k = 0;
	while (true) {
		int x = rand() % 9;
		int y = rand() % 9;

		if (arrprint[x][y] != 0) {
			arrprint[x][y] = 0;
			k++;
		}
		if (k == 14 + 15 ) {
			break;
		}

	}
}

void MakeArrPrintMedium(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arrprint[i][j] = arr[i][j];
		}
	}
	int k = 0;
	while (true) {
		int x = rand() % 9;
		int y = rand() % 9;

		if (arrprint[x][y] != 0) {
			arrprint[x][y] = 0;
			k++;
		}
		if (k == 14 + 18 + 5) {
			break;
		}

	}
}
void MakeArrPrintHard(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			arrprint[i][j] = arr[i][j];
		}
	}
	int k = 0;
	while (true) {
		int x = rand() % 9;
		int y = rand() % 9;

		if (arrprint[x][y] != 0) {
			arrprint[x][y] = 0;
			k++;
		}
		if (k == 14 + 18 + 20) {
			break;
		}

	}
}










void DrawSpaceGiant(sf::RenderWindow &window, int i, int j) {

	string space = ":";

	Font fon;
	if (!fon.loadFromFile("ArialCE.ttf")) {}


	Text tex;
	tex.setFont(fon);
	tex.setString(space);
	tex.setCharacterSize(60);
	tex.setFillColor(sf::Color::Black);
	//tex.setPosition(310 + i * 108.5, 25 + j * 110);


	int x;
	x = rand() % 2;



	if (x == 1)
		window.draw(tex);

}

void DrawNumberGiant(sf::RenderWindow &window, char arr[16][16], char arr2[16][16]) {

	Font fon;
	if (!fon.loadFromFile("Zombie-Slayer.ttf")) {}


	Text tex;
	for (int m = 0; m < 16; m++) {
		for (int n = 0; n < 16; n++) {
			if (arr[n][m] == 0 || arr[n][m] == '0')
				continue;


			tex.setFont(fon);
			tex.setString(arr[n][m]);
			tex.setCharacterSize(60);
			///tex.setPosition(300 + m * 108.5, 25 + n * 110);
			if (arr[n][m] == arr2[n][m])
				tex.setFillColor(sf::Color::Blue);
			else if (arr[n][m] != arr2[n][m] && arr[n][m] != 0) {
				tex.setFillColor(sf::Color::Red);
			}


			window.draw(tex);


		}
	}

}

bool isSolvedGaint(char arr1[16][16], char arr2[16][16], char arr3[16][16]) {
	char arr4[16][16] = { 0 };
	bool Found = true;
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (arr1[i][j] != 0)
				arr4[i][j] = arr1[i][j];
			if (arr2[i][j] != 0)
				arr4[i][j] = arr2[i][j];
		}
	}
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (arr4[i][j] != arr3[i][j])
				Found = false;
		}
	}
	return Found;

}