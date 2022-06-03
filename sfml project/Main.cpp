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

const int SizeOfFastSud = 4;
#define Unassigned 0

const int SizeOfSud = 9;

const int SizeOfGiantSud = 16;
#define UnassignedGiant '0'
                                   /*******************************/
/***********************************(Functions about sud4*4's sfml)*******************************************************/

void DrawGridFast(sf::RenderWindow &window, int arr[SizeOfFastSud][SizeOfFastSud]);
void DrawSpaceFast(sf::RenderWindow &window, int i, int j);
void DrawNumberFast(sf::RenderWindow &window, int arr[SizeOfFastSud][SizeOfFastSud], int arr2[SizeOfFastSud][SizeOfFastSud]);
bool isSolvedFast(int arr1[SizeOfFastSud][SizeOfFastSud], int arr2[SizeOfFastSud][SizeOfFastSud], int arr3[SizeOfFastSud][SizeOfFastSud]);
void keyboardUsing_Right_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]);
void keyboardUsing_Left_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]);
void keyboardUsing_Down_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]);
void keyboardUsing_Up_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]);

                                     /*******************************/
/************************************(Functions about sud4*4's logic)*******************************************************/

bool FindUnassignedLocation_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int &row, int &col);
bool UsedInRow_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int row, int num);
bool UsedIncoloumn_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int col, int num);
bool UsedInBox_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int StartBoxRow, int StartBoxCol, int num);
bool IsSafe_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int row, int col, int num);
bool SolveOfSud_FastSud(int grid[SizeOfFastSud][SizeOfFastSud]);

void MakeGridDrawFast(int arr[SizeOfFastSud][SizeOfFastSud], int arrprint[SizeOfFastSud][SizeOfFastSud]);
void PrintSolveOfSud_GiantSud(int grid[SizeOfFastSud][SizeOfFastSud]);

                                  /********************************/
/***********************************(Functions about sud9*9's sfml)*******************************************************/

void DrawGrid(sf::RenderWindow &window, int Grid[SizeOfSud][SizeOfSud]); 
void draw1_solve(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]);
void draw2(sf::RenderWindow &window, int arr[SizeOfSud][SizeOfSud]);
void DrawSpace(sf::RenderWindow &window, int i, int j);
void keyboardUsing_Right(int &i, int &j, int arr[SizeOfSud][SizeOfSud]);
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
void DrawClock(sf::RenderWindow &window ,sf::Time &s , int m);
void game_controles(sf::RenderWindow &window);

                                     /**********************************/
/************************************(Functions about sudkok9*9's logic)*************************************/

//void MakeGrids(int GridGiant[9][9] , int );
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
int  MakeGrid(int grid[SizeOfSud][SizeOfSud]);
void MakeGridDrawEasy(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);
void MakeGridDrawMedium(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);
void MakeGridDrawHard(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]);

                                   /*********************************/
/***********************************(Functions about sud16*16's sfml)*******************************************************/

void DrawGridGiant(sf::RenderWindow &window, char arr[SizeOfGiantSud][SizeOfGiantSud]);
void DrawSpaceGiant(sf::RenderWindow &window, int i, int j);
void DrawNumberGiant(sf::RenderWindow &window, char arr[16][16], char arr2[16][16]);
bool isSolvedGaint(char arr1[16][16], char arr2[16][16], char arr3[16][16]);
void keyboardUsing_Right_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]);
void keyboardUsing_Left_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]);
void keyboardUsing_Down_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]);
void keyboardUsing_Up_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]);

                                   /**********************************/
/***********************************(Functions about sud16*16's logic)*******************************************************/

bool FindUnassignedLocation_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int &row, int &col);
bool UsedInRow_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int row, char num);
bool UsedIncoloumn_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int col, char num);
bool UsedInBox_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int StartBoxRow, int StartBoxCol, char num);
bool IsSafe_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int row, int col, char num);
bool SolveOfSud_GiantSud(char  grid[SizeOfGiantSud][SizeOfGiantSud]);
void MakeGiantSudPrint(char arr[SizeOfGiantSud][SizeOfGiantSud], char arrprint[SizeOfGiantSud][SizeOfGiantSud]);
void PrintSolveOfSud_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud]);

/******************************************************************************************************/




//main function 
void main()
{
	
	int Mistake = 0, Hint = 2;
	bool pause = false;
	sf::Clock time1;
	Time min , sec;
	srand((unsigned int)time(NULL));

	
	//loop Game
	while (true)
	{
		
		bool exit = false;
		int min = 0;

		/*************************************(Sudoko 4*4)****************************************************/
		int GridDrawFast[SizeOfFastSud][SizeOfFastSud], GridUserFast[SizeOfFastSud][SizeOfFastSud] = { 0 };

		int n;
		n = 1 + rand() % 4;
		//////////////////////cout << " x is : " << n << endl;

		int GridFast[SizeOfFastSud][SizeOfFastSud] =
		{   n,0 , 0,0 ,
		    0,0 , n,0 ,

			0,0 , 0,n ,
			0,n , 0,0 , };


		/******************************cout << "************************************************************" << endl;
		PrintSolveOfSud_GiantSud(GridFast);
		cout << "************************************************************" << endl;
		*
		if (SolveOfSud_FastSud(GridFast))
			PrintSolveOfSud_GiantSud(GridFast);
		else cout << "No Solution" << endl;*//////////////

		SolveOfSud_FastSud(GridFast);

		///////////cout << "************************************************************" << endl;
		MakeGridDrawFast(GridFast, GridDrawFast);
		/*******PrintSolveOfSud_GiantSud(GridDrawFast);
		cout << "************************************************************" << endl;*////

		/**************************************(Sudoko 9*9)****************************************************/

		int a, b;
		
		while (true) {
			a = 1 + rand() % 9;
			b = 1 + rand() % 9;
			if (a != b)
				break;
		}

		int GridDrawEasy[SizeOfSud][SizeOfSud] = {}, GridDrawMedium[SizeOfSud][SizeOfSud] = {}, 
			GridDrawHard[SizeOfSud][SizeOfSud] = {}, GridDrawUser  [SizeOfSud][SizeOfSud] = {},
			GridDrawLoad[SizeOfSud][SizeOfSud] = {};
		
		
		int Grid[9][9] = 
		{   { a, b, 0, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, a, b, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, a, b, 0 },
			{ 0, 0, 0, 0, 0, 0, b, 0, a },
			{ 0, 0, 0, b, 0, a, 0, 0, 0 },
			{ b, 0, a, 0, 0, 0, 0, 0, 0 },
			{ 0, a, b, 0, 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, a, b, 0, 0, 0 },
			{ 0, 0, 0, 0, 0, 0, 0, a, b }   };

		SolveOfSud(Grid);
		MakeGridDrawEasy(Grid, GridDrawEasy);
		MakeGridDrawMedium(Grid, GridDrawMedium);
		MakeGridDrawHard(Grid, GridDrawHard);

		
		/****************************************(Sudoko 16*16)****************************************************/


		char GridDrawGiant[SizeOfGiantSud][SizeOfGiantSud];

		srand((unsigned int)time(NULL));
		char x, y, z;

		while (true) {
			x = '1' + rand() % 9;
			y = 'A' + rand() % 7;
			z = '1' + rand() % 9;
			if (z == x) {
				z = 'A' + rand() % 7;
				if (z != y)
					break;
			}
		}
		

		char GridGiant[SizeOfGiantSud][SizeOfGiantSud] =
	  { {  x , y , z ,'0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' ,  x , y , z ,'0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' ,  x , y , z ,'0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' ,  x , y , z ,'0' },

		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' ,  y , z ,'0', x  },
		{ '0','0','0','0' , '0','0','0','0' ,  y , z ,'0', x  , '0','0','0','0' },
		{ '0','0','0','0' ,  y , z ,'0', x  , '0','0','0','0' , '0','0','0','0' },
		{  y , z ,'0', x  , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },

		{ '0', x , y , z  , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0', x , y , z  , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0', x , y , z  , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0', x , y , z  },

		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' ,  z ,'0', x , y  },
		{ '0','0','0','0' , '0','0','0','0' ,  z ,'0', x , y  , '0','0','0','0' },
		{ '0','0','0','0' ,  z ,'0', x , y  , '0','0','0','0' , '0','0','0','0' },
		{  z ,'0', x , y  , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' } };


		char GridUserGiant[SizeOfGiantSud][SizeOfGiantSud] =
	  { { '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },

		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },

		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },

		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' },
		{ '0','0','0','0' , '0','0','0','0' , '0','0','0','0' , '0','0','0','0' } };


		SolveOfSud_GiantSud(GridGiant);
		MakeGiantSudPrint(GridGiant, GridDrawGiant);
		

		/********************************************************************************************/

		//first main_window im the game 
		
		sf::RenderWindow main_window(sf::VideoMode(1500, 1000), "Sudoko Game");

		MainMenuu main_menu(1500, 1000);
		sf::Texture Photo1;
		if (!Photo1.loadFromFile("Sudoko-Game.png"))
		{
			//error
		}
		
		
		sf::Sprite FirstPage;
		FirstPage.setTexture(Photo1);


		//bool exit = false;

		while (main_window.isOpen())
		{
			
			sf::Event evnt;
			while (main_window.pollEvent(evnt))
			{
				
				if (evnt.type == sf::Event::Closed) {
					exit = true;
					main_window.close();
				}
				
				if (evnt.type == sf::Event::KeyReleased)
				{
					if (evnt.key.code == sf::Keyboard::Up)
					{
						main_menu.moveUp();
						break;

					}
					
					if (evnt.key.code == sf::Keyboard::Down)
					{
						main_menu.moveDown();
						break;
					}


					if (evnt.key.code == sf::Keyboard::Return)
					{

						if (main_menu.MainMenuPressed() == 0)
						{
							main_window.close();
							page_number = 0;

						}

						if (main_menu.MainMenuPressed() == 1)
						{
							main_window.close();
							page_number = 1;

						}

						if (main_menu.MainMenuPressed() == 2)
						{
							main_window.close();
							page_number = 2;

						}
						if (main_menu.MainMenuPressed() == 3)
						{
							main_window.close();
							page_number = 3;

						}

					}

				}








			}





			main_window.clear();
			main_window.draw(FirstPage);
			main_menu.draw(main_window);
			main_window.display();
		}
		
		
		if (exit) {
			break;
		}
		
		/////////////enter to level menu 
		if (page_number == 0)
		{
			
			
			sf::RenderWindow levels_window(VideoMode(1500, 1000), "Levels");
			
			sf::Texture photo2;
			if (!photo2.loadFromFile("Sudoko-Game.png")){
				cout << "error in load level page photo";
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


			//////////////////////////////Some thing is missed we need yasser /////////////////////////////
			//////////////////////////////fast level
			if (page_levels == 0) {

				sf::RenderWindow fast_window(VideoMode(1500, 1000), "Fast");

				int count1 = 0, count2 = 0;
				Mistake = 0; Hint = 1;


				sf::Texture photo3;
				///this is not the photo
				if (!photo3.loadFromFile("121212.png"))
				{
					//error
				}
				sf::Sprite SudokoGrid;
				SudokoGrid.setTexture(photo3);


				while (fast_window.isOpen())
				{


					fast_window.clear();

					fast_window.draw(SudokoGrid);
					DrawGridFast(fast_window, GridDrawFast);
					DrawMistake(fast_window, Mistake);
					DrawHint(fast_window, Hint);

					DrawNumberFast(fast_window, GridUserFast, GridFast);

					if (GridDrawFast[count1][count2] == 0) {
						///position :
						DrawSpaceFast(fast_window, count2, count1);

					}


					if (Mistake >= 3) {
						///Lose(fast_window, Mistake);

					}

					if (isSolvedFast(GridDrawFast, GridUserFast, GridFast)) {
						///Win(fast_window);
					}


					sf::Event evnt;
					while (fast_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							fast_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3) {
								fast_window.close();
							}

							switch (evnt.key.code) {

							case sf::Keyboard::Right:
								std::cout << "right click" << std::endl;
								keyboardUsing_Right_Fast(count2, count1, GridDrawFast);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left_Fast(count2, count1, GridDrawFast);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down_Fast(count2, count1, GridDrawFast);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up_Fast(count2, count1, GridDrawFast);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;
								GridUserFast[count1][count2] = 1;
								if (GridUserFast[count1][count2] != GridFast[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								GridUserFast[count1][count2] = 2;
								if (GridUserFast[count1][count2] != GridFast[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								GridUserFast[count1][count2] = 3;
								if (GridUserFast[count1][count2] != GridFast[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								GridUserFast[count1][count2] = 4;
								if (GridUserFast[count1][count2] != GridFast[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "BACK click" << std::endl;
								GridUserFast[count1][count2] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								if (Hint > 0) {
									GridUserFast[count1][count2] = GridFast[count1][count2];
									Hint--;
								}
								break;

							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(fast_window, pause);
								break;
							}

						}


					}





					fast_window.display();

				}



			}

			//////////////////easy level
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
				
				int s = 0;  
				Mistake = 0; Hint = 2;
				

				EndMenuu end_menu (1500,1000);






				////////****************/each of levels is almost done (lose and win page and the clock when it pau1se) ****/ 
				
				while (easy_window.isOpen())
				{

					sec = time1.getElapsedTime();

					////////////////////////0
					easy_window.clear();
					easy_window.draw(SudokoGrid);
					DrawGrid(easy_window, GridDrawEasy);
					DrawMistake(easy_window, Mistake);
					DrawHint(easy_window, Hint);
					
					
					DrawClock(easy_window, sec , min);
					game_controles(easy_window);


					if (GridDrawEasy[count1][count2] == 0) {

						DrawSpace(easy_window, count2, count1);

					}
					DrawNumber(easy_window, GridDrawUser, Grid, Mistake);

					///////////////////////////need to edit/////////////////////////////////
					
					if (Mistake >= 3) {
						//Lose(easy_window, Mistake);
						easy_window.clear();
						easy_window.draw(LosePhoto);
						Lose(easy_window, Mistake);

					}

					if (isSolved(GridDrawEasy, GridDrawUser, Grid)) {
						easy_window.clear();
						easy_window.draw(LosePhoto);
						Win(easy_window);
					}


					


					sf::Event evnt;
					while (easy_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							easy_window.close();
							if (Mistake < 3 || !isSolved(GridDrawEasy, GridDrawUser, Grid))
								save_game(Grid, GridDrawEasy , GridDrawUser , Hint , Mistake);
							
						}


						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3 || isSolved(GridDrawEasy, GridDrawUser, Grid) ) {
								easy_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								keyboardUsing_Right(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Left:
								keyboardUsing_Left(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Down:
								keyboardUsing_Down(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Up:
								keyboardUsing_Up(count2, count1, GridDrawEasy);
								break;

							case sf::Keyboard::Num0:
								for (int i = 0; i < 9; i++) {
									for (int j = 0; j < 9; j++) {
										cout << Grid[i][j] << " ";
									}
									cout << endl;
								}
								break;


							case sf::Keyboard::Num1:
								GridDrawUser[count1][count2] = 1;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								GridDrawUser[count1][count2] = 2;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								GridDrawUser[count1][count2] = 3;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								GridDrawUser[count1][count2] = 4;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								GridDrawUser[count1][count2] = 5;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								GridDrawUser[count1][count2] = 6;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								GridDrawUser[count1][count2] = 7;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								GridDrawUser[count1][count2] = 8;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num9:
								GridDrawUser[count1][count2] = 9;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								GridDrawUser[count1][count2] = 0;
								break;

							case sf::Keyboard::H:
								if (Hint > 0) {
									GridDrawUser[count1][count2] = Grid[count1][count2];
									Hint--;
								}
								break;

							case sf::Keyboard::Escape:
								pause = true;
								game_pause(easy_window , pause);
								
								
                                /*******************************
								if (pause)
									s = sec.asSeconds();
								if (!pause)
									sec = time1.getElapsedTime();
								********************************/
								

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
				int GridDrawUser[9][9] = {};
				Mistake = 0; Hint = 2;



				while (Medium_window.isOpen())
				{







					sec = time1.getElapsedTime();







					Medium_window.clear();
					Medium_window.draw(SudokoGrid);
					DrawGrid(Medium_window, GridDrawMedium);
					DrawMistake(Medium_window, Mistake);
					DrawHint(Medium_window, Hint);
					DrawClock(Medium_window, sec, min);




					if (GridDrawMedium[count1][count2] == 0) {

						DrawSpace(Medium_window, count2, count1);

					}
					DrawNumber(Medium_window, GridDrawUser, Grid, Mistake);

					if (Mistake >= 3) {
						Lose(Medium_window, Mistake);
					}

					if (isSolved(GridDrawMedium, GridDrawUser, Grid)) {
						Win(Medium_window);
					}


					sf::Event evnt;
					while (Medium_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							
							if (Mistake < 3 || !isSolved(GridDrawMedium, GridDrawUser, Grid))
								save_game(Grid, GridDrawMedium, GridDrawUser, Hint, Mistake);





							Medium_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							if (Mistake >= 3 || isSolved(GridDrawMedium, GridDrawUser, Grid)) {
								Medium_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								keyboardUsing_Right(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Left:
								keyboardUsing_Left(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Down:
								keyboardUsing_Down(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Up:
								keyboardUsing_Up(count2, count1, GridDrawMedium);
								break;

							case sf::Keyboard::Num1:
								GridDrawUser[count1][count2] = 1;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								GridDrawUser[count1][count2] = 2;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								GridDrawUser[count1][count2] = 3;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								GridDrawUser[count1][count2] = 4;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								GridDrawUser[count1][count2] = 5;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								GridDrawUser[count1][count2] = 6;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								GridDrawUser[count1][count2] = 7;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								GridDrawUser[count1][count2] = 8;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num9:
								GridDrawUser[count1][count2] = 9;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								GridDrawUser[count1][count2] = 0;
								break;

							case sf::Keyboard::H:
								if (Hint > 0) {
									GridDrawUser[count1][count2] = Grid[count1][count2];
									Hint--;
								}
								break;

							case sf::Keyboard::Escape:
								pause = true;
								game_pause(Medium_window, pause);


								/*******************************
								if (pause)
								s = sec.asSeconds();
								if (!pause)
								sec = time1.getElapsedTime();
								********************************/


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
				int	GridDrawUser[9][9] = {};
				Mistake = 0; Hint = 2;
				


				time1.restart();





				while (hard_window.isOpen())
				{






					sec = time1.getElapsedTime();







					hard_window.clear();
					hard_window.draw(SudokoGrid);
					DrawGrid(hard_window, GridDrawHard);
					DrawMistake(hard_window, Mistake);
					DrawHint(hard_window, Hint);
					DrawClock(hard_window, sec, min);




					if (GridDrawHard[count1][count2] == 0) {
						DrawSpace(hard_window, count2, count1);
					}
					DrawNumber(hard_window, GridDrawUser, Grid, Mistake);

					if (Mistake >= 3) {
						Lose(hard_window, Mistake);
					}

					if (isSolved(GridDrawHard, GridDrawUser, Grid)) {
						Win(hard_window);
					}


					sf::Event evnt;
					while (hard_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							if (Mistake < 3 || !isSolved(GridDrawHard, GridDrawUser, Grid)) 
								save_game(Grid, GridDrawHard, GridDrawUser, Hint, Mistake);


							hard_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							if (Mistake >= 3 || isSolved(GridDrawHard, GridDrawUser, Grid)) {
								hard_window.close();
							}





							switch (evnt.key.code)
							{
							case sf::Keyboard::Right:
								keyboardUsing_Right(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Left:
								keyboardUsing_Left(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Down:
								keyboardUsing_Down(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Up:
								keyboardUsing_Up(count2, count1, GridDrawHard);
								break;

							case sf::Keyboard::Num1:
								GridDrawUser[count1][count2] = 1;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								GridDrawUser[count1][count2] = 2;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								GridDrawUser[count1][count2] = 3;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								GridDrawUser[count1][count2] = 4;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								GridDrawUser[count1][count2] = 5;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								GridDrawUser[count1][count2] = 6;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								GridDrawUser[count1][count2] = 7;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								GridDrawUser[count1][count2] = 8;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num9:
								GridDrawUser[count1][count2] = 9;
								if (GridDrawUser[count1][count2] != Grid[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								GridDrawUser[count1][count2] = 0;
								break;

							case sf::Keyboard::H:
								if (Hint > 0) {
									GridDrawUser[count1][count2] = Grid[count1][count2];
									Hint--;
								}
								break;

							case sf::Keyboard::Escape:
								pause = true;
								game_pause(hard_window, pause);


								/*******************************
								if (pause)
								s = sec.asSeconds();
								if (!pause)
								sec = time1.getElapsedTime();
								********************************/


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
				Mistake = 0; Hint = 3;


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
					DrawGridGiant(giant_window, GridDrawGiant);
					DrawMistake(giant_window, Mistake);
					DrawHint(giant_window, Hint);
					DrawNumberGiant(giant_window, GridUserGiant, GridGiant );

					if (GridDrawGiant[count1][count2] == '0' ) {
						///position :
						DrawSpaceGiant(giant_window, count2, count1);

					}

					
					if (Mistake >= 3) {
						Lose(giant_window, Mistake);

					}

					if (isSolvedGaint(GridDrawGiant, GridUserGiant, GridGiant)) {
						Win(giant_window);
					}


					sf::Event evnt;
					while (giant_window.pollEvent(evnt))
					{
						if (evnt.type == sf::Event::Closed) {

							giant_window.close();

						}

						switch (evnt.type)
						{
						case sf::Event::KeyPressed:
							std::cout << "key has been pressed" << std::endl;

							if (Mistake >= 3 || isSolvedGaint(GridDrawGiant, GridUserGiant, GridGiant)) {
								giant_window.close();
							}

							switch (evnt.key.code) {

							case sf::Keyboard::Right:
								std::cout << "right click" << std::endl;
								keyboardUsing_Right_Giant(count2, count1, GridDrawGiant);
								break;

							case sf::Keyboard::Left:
								std::cout << "left click" << std::endl;
								keyboardUsing_Left_Giant(count2, count1, GridDrawGiant);
								break;

							case sf::Keyboard::Down:
								std::cout << "Down click" << std::endl;
								keyboardUsing_Down_Giant(count2, count1, GridDrawGiant);
								break;

							case sf::Keyboard::Up:
								std::cout << "Up click" << std::endl;
								keyboardUsing_Up_Giant(count2, count1, GridDrawGiant);
								break;

							case sf::Keyboard::Num1:
								std::cout << "1 click" << std::endl;
								GridUserGiant[count1][count2] = '1';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								GridUserGiant[count1][count2] = '2';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								GridUserGiant[count1][count2] = '3';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								GridUserGiant[count1][count2] = '4';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								GridUserGiant[count1][count2] = '5';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								GridUserGiant[count1][count2] = '6';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								GridUserGiant[count1][count2] = '7';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								GridUserGiant[count1][count2] = '8';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								GridUserGiant[count1][count2] = '9';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::A:
								std::cout << "A click" << std::endl;
								GridUserGiant[count1][count2] = 'A';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::B:
								std::cout << "B click" << std::endl;
								GridUserGiant[count1][count2] = 'B';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::C:
								std::cout << "C click" << std::endl;
								GridUserGiant[count1][count2] = 'C';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::D:
								std::cout << "D click" << std::endl;
								GridUserGiant[count1][count2] = 'D';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::E:
								std::cout << "E click" << std::endl;
								GridUserGiant[count1][count2] = 'E';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::F:
								std::cout << "F click" << std::endl;
								GridUserGiant[count1][count2] = 'F';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::G:
								std::cout << "G click" << std::endl;
								GridUserGiant[count1][count2] = 'G';
								if (GridUserGiant[count1][count2] != GridGiant[count1][count2])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "BACK click" << std::endl;
								GridUserGiant[count1][count2] = '0';
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								if (Hint > 0) {
									GridUserGiant[count1][count2] = GridGiant[count1][count2];
									Hint--;
								}
								break;

							case sf::Keyboard::Escape:
								std::cout << "esc click" << std::endl;
								pause = true;
								game_pause(giant_window, pause);
								break;
							}

						}


					}




					
					giant_window.display();

				}

		

			}




		}



		//////////////////////////////////Stopped Here/////////////////////////////////////////////

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
				

				load_game(Grid , GridDrawLoad , GridDrawUser , Hint , Mistake) ;

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
				int k = 0,x,y, arrnote[3][3] = {};
				EndMenuu end_menu(1500, 1000);





				//Mistake /= 9;



				while (easy_window.isOpen())
				{














					easy_window.clear();
					easy_window.draw(SudokoGrid);
					DrawGrid(easy_window, GridDrawLoad);
					DrawMistake(easy_window, Mistake);
					DrawHint(easy_window, Hint);
					//draw_notes(easy_window, notes);
					//draw_arrofnotes(easy_window, count1, count2, arrnote);




					if (GridDrawLoad[count1][count2] == 0) {

						DrawSpace(easy_window, count2, count1);

					}
					DrawNumber(easy_window, GridDrawUser, Grid, Mistake);

					/*if (Mistake >= 3) {
						Lose(easy_window, Mistake);
						//easy_window.clear();
						//easy_window.draw(LosePhoto);
					}*/

					if (isSolved(GridDrawLoad, GridDrawUser, Grid)) {
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
									out << GridDrawUser[i][j] << " ";

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


								x = count1;   y = count2;

								if (notes) {
									arrnote[1][1] = 1;
									break;

								}
								GridDrawUser[x][y] = 1;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num2:
								std::cout << "2 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 2;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num3:
								std::cout << "3 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 3;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num4:
								std::cout << "4 click" << std::endl;
								k++;
								x = count1; y = count2;
								GridDrawUser[x][y] = 4;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num5:
								std::cout << "5 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 5;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num6:
								std::cout << "6 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 6;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num7:
								std::cout << "7 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 7;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::Num8:
								std::cout << "8 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 8;
								break;

							case sf::Keyboard::Num9:
								std::cout << "9 click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 9;
								if (GridDrawUser[x][y] != Grid[x][y])
									Mistake++;
								break;

							case sf::Keyboard::BackSpace:
								std::cout << "C click" << std::endl;
								x = count1; y = count2;
								GridDrawUser[x][y] = 0;
								break;


							case sf::Keyboard::H:
								std::cout << "h click" << std::endl;
								x = count1; y = count2;
								if (Hint > 0) {
									GridDrawUser[x][y] = Grid[x][y];
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

				DrawSpace(solve_window, count2, count1);

				DrawNumberSolve(solve_window, Arr);

				
				/*if (ArrToSolve[count1][count2] == 0) {

					DrawSpace(solve_window, count2, count1);

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
							a = count1; b = count2;
							if (Hint > 0) {
								ArrToSolve[a][b] = Grid[a][b];
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

}


                                       /*************************/
/***************************************(Functions sud4*4's Sfml)*************************************************/

void DrawGridFast(sf::RenderWindow &window, int arr[SizeOfFastSud][SizeOfFastSud]) {

	sf::Font font;
	if (!font.loadFromFile("BebasNeue.otf")) {}

	sf::Text text;

	string num;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {

			if (arr[j][i] == 0)
				continue;

			num = to_string(arr[j][i]);
			text.setFont(font);
			text.setString(num);
			text.setCharacterSize(60);
			text.setFillColor(sf::Color::Black);
			text.setPosition(300 + i * 108.5, 22 + j * 110);
			window.draw(text);
		}
	}


}


void DrawSpaceFast(sf::RenderWindow &window, int i, int j) {

	string space = ":";

	Font fon;
	if (!fon.loadFromFile("BebasNeue.otf")) {}


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

void DrawNumberFast(sf::RenderWindow &window, int arr[SizeOfFastSud][SizeOfFastSud], int arr2[SizeOfFastSud][SizeOfFastSud]) {
	Font fon;
	if (!fon.loadFromFile("BebasNeue.otf")) {}
	string num;

	Text tex;
	for (int m = 0; m < 4; m++) {
		for (int n = 0; n < 4; n++) {
			if (arr[n][m] == 0)
				continue;

			num = to_string(arr[n][m]);
			tex.setFont(fon);
			tex.setString(num);
			tex.setCharacterSize(60);
			tex.setPosition(300 + m * 108.5, 25 + n * 110);
			if (arr[n][m] == arr2[n][m])
				tex.setFillColor(sf::Color::Blue);
			else if (arr[n][m] != arr2[n][m] && arr[n][m] != 0) {
				tex.setFillColor(sf::Color::Red);
			}


			window.draw(tex);


		}
	}

}

bool isSolvedFast(int arr1[SizeOfFastSud][SizeOfFastSud], int arr2[SizeOfFastSud][SizeOfFastSud], int arr3[SizeOfFastSud][SizeOfFastSud]) {
	char arr4[4][4] = { 0 };
	bool Found = true;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr1[i][j] != 0)
				arr4[i][j] = arr1[i][j];
			if (arr2[i][j] != 0)
				arr4[i][j] = arr2[i][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			if (arr4[i][j] != arr3[i][j])
				Found = false;
		}
	}
	return Found;

}

void keyboardUsing_Right_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]) {

	while (true)
	{

		if (j <= 4)
		{

			if (i <= 4)
			{
				i++;
				if (i == 4) {
					i = 0;
					j++;

					
				}
				if (j == 4)
					j = 0;
				if (arr[j][i] == 0) {
					break;
				}

			}
		
		}

	}



}

/**
void right() {
	while (true)
	{

		if (j > -1 && j < 4)
		{
			if (i > -1 && i < 3)
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
*/

void keyboardUsing_Left_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]) {

	while (true)
	{

		if (j >= -1)
		{

			if (i >= -1)
			{
				i--;
				if (i == -1) {
					i = 3;
					j--;


				}
				if (j == -1)
					j = 3;
				if (arr[j][i] == 0) {
					break;
				}

			}

		}

	}


}



void keyboardUsing_Down_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]) {

	while (true)
	{


		if (j <= 4)
		{
			j++;
			if (j == 4)
				j = 0;
			if (arr[j][i] == 0) {
				break;
			}

		}


	}

}
void keyboardUsing_Up_Fast(int &i, int &j, int arr[SizeOfFastSud][SizeOfFastSud]) {

	while (true) {
		if (j >= -1)
		{
			j--;
			if (j == -1)
				j = 3;
			if (arr[j][i] == 0) {
				break;
			}
			
		}
	}

	

}

/*void up()
{
	while (true)
	{


		if (j > -1 && j < 4)
		{
			j--;
			if (arr[j][i] == 0) {
				break;
			}
			else continue;
		}
		else if (j < 0)
		{


			j = 3;
			if (arr[j][i] == 0)
				break;
			else continue;
		}


	}
}*/

                                       /**************************/
/***************************************(Functions sud4*4's Logic)*************************************************/

bool SolveOfSud_FastSud(int grid[SizeOfFastSud][SizeOfFastSud]) {
	int row, col;
	if (!FindUnassignedLocation_FastSud(grid, row, col))
		return true;
	for (int num = 1; num <= 4; num++)
	{

		if (IsSafe_FastSud(grid, row, col, num)) {
			grid[row][col] = num;
			if (SolveOfSud_FastSud(grid))
				return true;
			grid[row][col] = Unassigned;

		}

	}
	return false;
}

bool IsSafe_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int row, int col, int num) {
	return !UsedInRow_FastSud(grid, row, num)
		&& !UsedIncoloumn_FastSud(grid, col, num)
		&& !UsedInBox_FastSud(grid, row - row % 2, col - col % 2, num)
		&& grid[row][col] == Unassigned;
}


bool FindUnassignedLocation_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int &row, int &col) {
	for (row = 0; row < SizeOfFastSud; row++)
		for (col = 0; col < SizeOfFastSud; col++)
			if (grid[row][col] == Unassigned)
				return true;
	return false;

}

bool UsedInRow_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int row, int num) {
	for (int col = 0; col < SizeOfFastSud; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedIncoloumn_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int col, int num) {
	for (int row = 0; row < SizeOfFastSud; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedInBox_FastSud(int grid[SizeOfFastSud][SizeOfFastSud], int StartBoxRow, int StartBoxCol, int num) {
	for (int row = 0; row < 2; row++)
		for (int col = 0; col < 2; col++)
			if (grid[row + StartBoxRow][col + StartBoxCol] == num)
				return true;
	return false;
}

void PrintSolveOfSud_GiantSud(int grid[SizeOfFastSud][SizeOfFastSud]) {
	cout << "\nThe Solve of this Sudoko is : \n";
	for (int row = 0; row < SizeOfFastSud; row++)
	{
		for (int col = 0; col < SizeOfFastSud; col++)
			cout << grid[row][col] << "  ";
		cout << "\n";
	}
	cout << endl;
}

void MakeGridDrawFast(int arr[SizeOfFastSud][SizeOfFastSud], int arrprint[SizeOfFastSud][SizeOfFastSud]) {

	for (int i = 0; i < SizeOfFastSud; i++) {
		for (int j = 0; j < SizeOfFastSud; j++) {
			arrprint[i][j] = arr[i][j];
		}
	}
	int k = 0;
	while (true) {
		int x = rand() % 4;
		int y = rand() % 4;

		if (arrprint[x][y] != 0) {
			arrprint[x][y] = 0;
			k++;
		}
		if (k == 6) {
			break;
		}

	}
}


                                      /***************************/
/***************************************(Functions sud9*9's Sfml)*************************************************/

void sudoko(float width, float hight, sf::RenderWindow &window) {
//void draw(sf::RenderWindow &main_window);

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
/*void draw(sf::RenderWindow &main_window) {
	main_window.draw
}*/
/*void DrawGrid(sf::RenderWindow &main_window,int arr) {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			string s1 = arr[i][j];
			text.setString(s1);
			text.setPosition(65 * j + 30, 65 * i + 1);
			windowgrid.draw(text);
		}
	}
	main_window.draw(s[i]);
}*/

void DrawGrid(sf::RenderWindow &window, int Grid[SizeOfSud][SizeOfSud]) {
	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	string s1;
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			
			if (Grid[j][i]==0)
				continue;
			
			s1 = to_string(Grid[j][i]);
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
			/*int a, b;
			a = rand() % 9;
			b = rand() % 9;*/


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
			/*int a, b;
			a = rand() % 9;
			b = rand() % 9;


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
					//main_window.draw(text);
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



void DrawSpace(sf::RenderWindow &window, int i, int j) {
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
		
		if (j <= 9)
		{

			if (i <= 9)
			{
				i++;
				if (i == 9) {
					i = 0;
					j++;


				}
				if (j == 9)
					j = 0;
				if (arr[j][i] == 0) {
					break;
				}

			}

		}

		
	
	}

	

}


void keyboardUsing_Left(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
	while (true)
	{

		if (j >= -1)
		{

			if (i >= -1)
			{
				i--;
				if (i == -1) {
					i = 8;
					j--;


				}
				if (j == -1)
					j = 8;
				if (arr[j][i] == 0) {
					break;
				}

			}

		}
	}


}


void keyboardUsing_Down(int &i, int &j, int arr[SizeOfSud][SizeOfSud]){

	while (true)
	{

		
		if (j <= 9)
		{
			j++;
			if (j == 9)
				j = 0;
			if (arr[j][i] == 0) {
				break;
			}

		}
		
	}



}


void keyboardUsing_Up(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
	
	while (true)
	{

		if (j >= -1)
		{
			j--;
			if (j == -1)
				j = 8;
			if (arr[j][i] == 0) {
				break;
			}

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

	//main_window.draw(tex );
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

	//main_window.draw(tex );
}

void Lose(sf::RenderWindow &window, int K) {
	//main_window.display();
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
	

	sf::Texture photo;
	if (!photo.loadFromFile("Sudoko-Game.png"))
	{
		//error
	}
	sf::Sprite win;
	win.setTexture(photo);

	sf::Font font;
	if (!font.loadFromFile("ArialCE.ttf")) {}

	sf::Text text;
	sf::Text text2;


	text.setFont(font);
	text.setString("You Won");
	text.setCharacterSize(100);
	text.setFillColor(sf::Color::White);
	text.setPosition(60, 100);


	text2.setFont(font);
	text2.setString("press any key to contiuo");
	text2.setCharacterSize(41);
	text2.setFillColor(sf::Color::Blue);
	text2.setPosition(10, 300);

	window.draw(win);
	window.draw(text);
	window.draw(text2);

}

void DrawClock(sf::RenderWindow &window, sf::Time &s, int m) {
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
	main_window.draw(text);
	main_window.draw(text2);*/
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

//////////////////////its save the game if it done :)
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


void game_pause(sf::RenderWindow &window, bool &p) {
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
	cout << GridGiant[i][j] << "\t";
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
				//GridGiant[i][j] = num;



			{


				num = 1 + rand() % 9;
				while (true)
				{
					if (IsSafe2(grid, i, j, num)) {
						grid[i][j] = num;
						//cout << GridGiant[i][j] << " ";
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

void MakeGridDrawEasy(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {

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

void MakeGridDrawMedium(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {
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
void MakeGridDrawHard(int arr[SizeOfSud][SizeOfSud], int arrprint[SizeOfSud][SizeOfSud]) {

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


                                 /*****************************************/
/**************************************(Function Sudokok16*16 Sfml)*********************************************************/



void DrawGridGiant(sf::RenderWindow &window, char arr[SizeOfGiantSud][SizeOfGiantSud]) {

	sf::Font font;
	if (!font.loadFromFile("Zombie-Slayer.ttf")) {}

	sf::Text text;


	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {

			if (arr[j][i] == '0')
				continue;
			
			text.setFont(font);
			text.setString(arr[j][i]);
			text.setCharacterSize(60);
			text.setFillColor(sf::Color::Black);
			text.setPosition(300 + i * 108.5, 22 + j * 110);
			window.draw(text);
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
	tex.setPosition(310 + i * 108.5, 25 + j * 110);


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
			tex.setPosition(300 + m * 108.5, 25 + n * 110);
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
	for (int i = 0; i < 16; i++) {
		for (int j = 0; j < 16; j++) {
			if (arr4[i][j] != arr3[i][j])
				Found = false;
		}
	}
	return Found;

}
/*
void copy() {
	void keyboardUsing_Right(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
		while (true)
		{

			if (j <= 9)
			{

				if (i <= 9)
				{
					i++;
					if (i == 9) {
						i = 0;
						j++;


					}
					if (j == 9)
						j = 0;
					if (arr[j][i] == 0) {
						break;
					}

				}

			}



		}



	}


	void keyboardUsing_Left(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {
		while (true)
		{

			if (j >= -1)
			{

				if (i >= -1)
				{
					i--;
					if (i == -1) {
						i = 8;
						j--;


					}
					if (j == -1)
						j = 8;
					if (arr[j][i] == 0) {
						break;
					}

				}

			}
		}


	}


	void keyboardUsing_Down(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {

		while (true)
		{


			if (j <= 9)
			{
				j++;
				if (j == 9)
					j = 0;
				if (arr[j][i] == 0) {
					break;
				}

			}

		}



	}


	void keyboardUsing_Up(int &i, int &j, int arr[SizeOfSud][SizeOfSud]) {

		while (true)
		{

			if (j >= -1)
			{
				j--;
				if (j == -1)
					j = 8;
				if (arr[j][i] == 0) {
					break;
				}

			}

		}

	}

}
*/

void keyboardUsing_Right_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]) {

	while (true)
	{

		/*
		if (j > -1 && j < 16)
		{
			if (i > -1 && i < 15)
			{
				i++;
				if (arr[j][i] == '0') {
					break;
				}
				else continue;
			}
			else
			{

				j++;
				i = 0;
				if (arr[j][i] == '0')
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
	*/
		if (j <= 16)
		{

			if (i <= 16)
			{
				i++;
				if (i == 16) {
					i = 0;
					j++;


				}
				if (j == 16)
					j = 0;
				if (arr[j][i] == '0') {
					break;
				}

			}

		}

	
	
	}



}

void keyboardUsing_Left_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]) {
	
	while (true)
	{
		/*
		if (j > -1 && j < 16)
		{
			if (i > 0 && i < 16)
			{
				i--;
				if (arr[j][i] == '0') {
					break;
				}
				else continue;
			}
			else
			{

				j--;
				i = 15;
				if (arr[j][i] == '0')
					break;
				else continue;
			}
		}
		else
		{
			i = 15;
			j = 15;
			continue;
		}*/


		if (j >= -1)
		{

			if (i >= -1)
			{
				i--;
				if (i == -1) {
					i = 16;
					j--;


				}
				if (j == -1)
					j = 16;
				if (arr[j][i] == '0') {
					break;
				}

			}

		}
		
	}


}

void keyboardUsing_Down_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]) {

	while (true)
	{


		/*if (j > -1 && j < 16)
		{
			j++;
			if (arr[j][i] == '0') {
				break;
			}
			else continue;
		}
		else if (j > 15)
		{


			j = 0;
			if (arr[j][i] == '0')
				break;
			else continue;
		}*/

		if (j <= 16)
		{
			j++;
			if (j == 16)
				j = 0;
			if (arr[j][i] == '0') {
				break;
			}

		}


	}

}
void keyboardUsing_Up_Giant(int &i, int &j, char arr[SizeOfGiantSud][SizeOfGiantSud]) {

	while (true)
	{

		/*
		if (j >= 0 && j < 16)
		{
			j--;
			if (arr[j][i] == '0') {
				break;
			}
			else continue;
		}
		else if (j < 0)
		{


			j = 15;
			if (arr[j][i] == '0')
				break;
			else continue;
		}
		*/
		if (j >= -1)
		{
			j--;
			if (j == -1)
				j = 8;
			if (arr[j][i] == 0) {
				break;
			}

		}

	}

}



/****************************************************************************************/
/************************(Function logic 16*16)**************************/
bool SolveOfSud_GiantSud(char  grid[SizeOfGiantSud][SizeOfGiantSud]) {
	int row, col;
	if (!FindUnassignedLocation_GiantSud(grid, row, col))
		return true;
	for (char num = '0'; num <= 'G'; num++)
	{
		if (num == '9' + 1) {
			num = 'A';
		}
		if (IsSafe_GiantSud(grid, row, col, num)) {
			grid[row][col] = num;
			if (SolveOfSud_GiantSud(grid))
				return true;
			grid[row][col] = UnassignedGiant;

		}

	}
	return false;
}

bool IsSafe_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int row, int col, char num) {
	return !UsedInRow_GiantSud(grid, row, num)
		&& !UsedIncoloumn_GiantSud(grid, col, num)
		&& !UsedInBox_GiantSud(grid, row - row % 4, col - col % 4, num)
		&& grid[row][col] == UnassignedGiant;
}


bool FindUnassignedLocation_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int &row, int &col) {
	for (row = 0; row < SizeOfGiantSud; row++)
		for (col = 0; col < SizeOfGiantSud; col++)
			if (grid[row][col] == UnassignedGiant)
				return true;
	return false;

}

bool UsedInRow_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int row, char num) {
	for (int col = 0; col < SizeOfGiantSud; col++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedIncoloumn_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int col, char num) {
	for (int row = 0; row < SizeOfGiantSud; row++)
		if (grid[row][col] == num)
			return true;
	return false;
}


bool UsedInBox_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud], int StartBoxRow, int StartBoxCol, char num) {
	for (int row = 0; row < 4; row++)
		for (int col = 0; col < 4; col++)
			if (grid[row + StartBoxRow][col + StartBoxCol] == num)
				return true;
	return false;
}


void MakeGiantSudPrint(char arr[SizeOfGiantSud][SizeOfGiantSud], char arrprint[SizeOfGiantSud][SizeOfGiantSud]) {

	for (int i = 0; i < SizeOfGiantSud; i++) {
		for (int j = 0; j < SizeOfGiantSud; j++) {
			arrprint[i][j] = arr[i][j];
		}
	}
	int k = 0;
	while (true) {
		int x = rand() % 16;
		int y = rand() % 16;

		if (arrprint[x][y] != '0') {
			arrprint[x][y] = '0';
			k++;
		}
		if (k == (14 + 18 + 5) * 2) {
			break;
		}

	}
}

void PrintSolveOfSud_GiantSud(char grid[SizeOfGiantSud][SizeOfGiantSud]) {
	cout << "\nThe Solve of this Sudoko is : \n";
	for (int row = 0; row < SizeOfGiantSud; row++)
	{
		for (int col = 0; col < SizeOfGiantSud; col++)
			cout << grid[row][col] << "  ";
		cout << "\n";
	}
	cout << endl;
}