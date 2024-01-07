#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <conio.h>
#include <cstdio>
#include <random>


void header()
{
	// the special character (the white block) id on the ascii table
	int bar = 219;
	
	std::cout << "\n\n\n\n\t\t\t\t";	
	
	for(int i = 0; i < 30; i++)
	{
		std::cout << char(bar);
	}
	
	std::cout << "\n\n";
	std::cout << "\t\t\t\t" << char(bar) << " PASSWORD SECURITY CHECK V1 " << char(bar);
	std::cout << "\n\n\t\t\t\t";
	
	for(int i = 0; i < 30; i++)
	{
		std::cout << char(bar);
	}
	
	std::cout << "\n\n\n\n";
}

void checkpass()
{
	system("cls");
	std::cout << "\n\n ENTER YOUR PASSWORD: \n";
	std::string pass;
	std::cin >> pass;
	
	// array of booleans.
	
	// **** ARRAY CONTENTS **** //
	
	// has uppercase, has lowercase, has a digit, has a special character, is longer than 8 characters
	
	// **** ARRAY CONTENTS **** //
	
	std::vector <bool> secure(5, false);
	
	 // if the password is longer than 8 characters then the last member becomes true
	if(pass.size() > 8) secure[4] = true;
	
	for(int i = 0; i < pass.size(); i++)
	{
		if(std::isupper(pass[i]))
		{
			secure[0] = true;
		}
		else if(std::islower(pass[i]))
		{
			secure[1] = true;
		}
		else if(std::isdigit(pass[i]))
		{
			secure[2] = true;
		}
		else
		{
			secure[3] = true;
		}
	}
	
	int score = 0;
	
	// counts how many requirements it checks off
	for(int i = 0; i < 5; i++)
	{
		if(secure[i] == true)
		{
			score++;
		}
	}


	if(score < 5 && pass.size() > 12)
	{
		score++;
	}
	else if(pass.size() > 15 && score = 2)
	{
		score = 4;
	}
	else if(pass.size() > 15 && score = 3 )
	{
		score = 5;
	}
	
	switch(score)
	{
		case 0:
			std::cout << "ERROR. DID YOU TYPE IN A PASSWORD? \n\n";
			break;
		case 1:
			std::cout << "YOUR PASSWORD IS UNSAFE \n\n";
			break;
		case 2:
			std::cout << "YOUR PASSWORD IS OK. RELATIVELY UNSAFE \n\n";
			break;
		case 3:
			std::cout << "YOUR PASSWORD IS ALRIGHT. NEEDS SLIGHT IMPROVEMENTS. RELATIVELY SAFE \n\n";
			break;
		case 4:
			std::cout << "YOUR PASSWORD IS PRETTY SAFE! BUT STILL COULD BE SAFER \n\n";
			break;
		case 5:
			std::cout << "YOUR PASSWORD IS VERY SAFE AND SECURE! \n\n";
			break;
	}
}

void generatepass()
{
	system("cls");
	std::cout << "\n\n IS YOUR SAFE AND SECURE PASSWORD: \n\n";
	
	for(int i = 0; i < 15; i++)
	{
		std::cout << char(33 + (rand() % 90));
	}
	
	std::cout << "\n\n";
}

int main()
{
	
	// set the color of the terminal	
	system("COLOR 17");
	system("cls");
	
	header();
	
	std::cout << "0 - CHECK SAFETY OF YOUR PASSWORD \n";
	std::cout << "1 - GENERATE A NEW SAFE PASSWORD \n";
	std::cout << "2 - RESTART APP \n";
	std::cout << "3 - EXIT \n\n";
	
	int resp;
	
	std::cin >> resp;
	
	// checking the response and recalling the main function in case of restart.
	switch(resp)
	{
		case 0:
			checkpass();
			std::cout << "PRESS ANY KEY TO GO TO THE MAIN MENU";
			_getch();
			main();
			break;
		case 1:	
			generatepass();
			std::cout << "PRESS ANY KEY TO GO TO THE MAIN MENU";
			_getch();
			main();
			break;
		case 2:
			main();
			break;
		case 3:
			system("cls");
			return 0;
			break;
		default: 
			main();
			break;
	}
	
}
