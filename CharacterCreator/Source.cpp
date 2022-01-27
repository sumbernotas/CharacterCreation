#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

/////////////////////////
/// creates a weapon variable that holds all available weapon stats 
/////////////////////////
struct Weapon
{
	string m_name = " ";
	int m_strength = 0;
	int m_dexterity = 0;
	int m_magic = 0;
	int m_range = 0;

	//////////////////
	/// weapon function that prints specific weapons stats to the console 
	//////////////////
	void PrintValues(int strength, int dex, int magic, int range)
	{
		cout << "Your weapon strength is " << strength << endl;
		cout << "Your weapon dexterity is " << dex << endl;
		cout << "Your weapon magic is " << magic << endl;
		cout << "Your weapon range is " << range << endl;
	}
};

////////////////////////
/// creates a variable for a character, holding all of the characters avaiable stats
////////////////////////
struct RpgCharacter
{
	string m_name = " ";
	int m_strength = 0;
	int m_dexterity = 0;
	int m_magic = 0;
	Weapon* pWeapon;

	string m_abilityName = " ";

	/////////////
	// prints characters given name
	////////////
	void PrintName(string name)
	{
		cout << name << endl;
	}

	/////////////////
	// prints all character stats to the console
	////////////////
	void PrintAttributes(int strength, int dex, int magic, Weapon* pWeapon)
	{
		cout << "Strength:  " << strength << endl;
		cout << "Dexterity: " << dex << endl;
		cout << "Magic: " << magic << endl;
		//cout << "Weapon: " << pWeapon->m_name << endl;

		if (pWeapon == NULL)
		{
			cout << "Weapon: none" << endl;
		}
		else
		{
			cout << "Weapon: " << pWeapon->m_name << endl;
		}
	}

	//////////////////////////////////
	// uses the weapons function to print the specific weapon that was assigned to the character
	//////////////////////////////////
	void PrintWeapon()
	{
		if (pWeapon != NULL)     // will only display if the character chooses a weapon
		{
			pWeapon->PrintValues(pWeapon->m_strength, pWeapon->m_dexterity, pWeapon->m_magic, pWeapon->m_range);
		}
	}

};

int main()
{
	Weapon sword{ "sword", 5, 2, 0, 2 };
	Weapon longbow{ "longbow", 3, 5, 0, 5 };
	Weapon staff{ "staff", 1, 0, 5, 0 };

	Weapon* p_sword = &sword;
	Weapon* p_longbow = &longbow;              // pointers toward each weapon that allows the character to get access to them
	Weapon* p_staff = &staff;

	RpgCharacter character;          // since this is a one player game intro, this is a premade character set (the player)

	int numberOfNames = 0;
	string presetNameList[10]{ "Summer", "Sage", "Ryan", "Tye", "Jayla", "Emily", "Zack", "Eddie", "Liz", "Claire" };   // this is a preset names list, i created this in order to hold the places of the
																														// players created list. I did not make this list avaiable on its own
	cout << "MENU" << endl;
	cout << "(1) Enter character creation" << endl;
	cout << "(2) Configure random name choices" << endl;

	int playerMenuChoice;
	cin >> playerMenuChoice;

	if (playerMenuChoice == 2)            // takes player into name list generator
	{

		system("cls");

		cout << "How many names will be on your list? (1-10)" << endl;

		cin >> numberOfNames;

		string* nameList = new string[numberOfNames]{};                    // I created a dynamic array using the players choice of size. This array will store the players name list

		cout << "Please enter each name seperately." << endl;

		/////////////////////////////////
		// this loop asks the user which names the want into their list, this loop will end when they reached their max size of names
		///////////////////////////////////
		for (int i = 0; i < numberOfNames; i++)
		{
			cout << "Name # " << i + 1 << endl;

			string playersChosenName;
			cin >> playersChosenName;

			nameList[i] = playersChosenName;
			cout << endl;
		}

		system("cls");

		cout << "Awesome! You created a name list of " << numberOfNames << endl;
		cout << endl;
		cout << "Name List: " << endl;

		////////////////////////////////
		// this will print back the list that the player just created onto the console
		for (int j = 0; j < numberOfNames; j++)
		{
			cout << nameList[j] << ", ";
		}

		/////////////////////////////////////////////////////////////////////////
		///////// this was not exactly intentional,  I was getting a bug when it came to letting the player choose a name out of their list. After multiple
		///////// different attempts to fix this i decided to create an array and redefine each value as the list was created. This probably isn't the best
		///////// way to go about this.. but I got it to work. I tried to put this into a function to ease space, but that gave me difficulties as well.
		/////////////////////////////////////////////////////////////////////////
		if (numberOfNames == 2)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 3)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 4)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 5)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 6)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[5] = nameList[5];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 7)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[5] = nameList[5];
			presetNameList[6] = nameList[6];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 8)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[5] = nameList[5];
			presetNameList[6] = nameList[6];
			presetNameList[7] = nameList[7];
			presetNameList[NULL] = nameList[NULL];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 9)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[5] = nameList[5];
			presetNameList[6] = nameList[6];
			presetNameList[7] = nameList[7];
			presetNameList[8] = nameList[8];
			presetNameList[NULL] = nameList[NULL];
		}
		else if (numberOfNames == 10)
		{
			presetNameList[0] = nameList[0];
			presetNameList[1] = nameList[1];
			presetNameList[2] = nameList[2];
			presetNameList[3] = nameList[3];
			presetNameList[4] = nameList[4];
			presetNameList[5] = nameList[5];
			presetNameList[6] = nameList[6];
			presetNameList[7] = nameList[7];
			presetNameList[8] = nameList[8];
			presetNameList[9] = nameList[9];
		}

		cout << endl;
		system("pause");

		playerMenuChoice = 1;      // allows the player to continue onto creating a character after generating a name list
	}

	if (playerMenuChoice == 1)
	{
		system("cls");

		cout << "Would you like to.. " << endl;
		cout << "(1) get a name from your list" << endl;
		cout << "(2) enter a character name" << endl;

		int playerNameOption;
		cin >> playerNameOption;

		//////////////////
		// this option allows the player to pick a name from their created list
		/////////////////
		if (playerNameOption == 1)
		{
			system("cls");

			//////////////////////////////////
			// if the player has not yet made a list, the will need to make one before continuing
			/////////////////////////////////
			if (numberOfNames == 0)
			{
				cout << "Sorry! You haven't made a name list yet!" << endl;
				cout << "Restart to create a list or continue to type in your own!" << endl;

				system("pause");
				playerNameOption = 2;

			}

			/////////////////////
			// if the player has already created their list, they can chooce their name out of said list
			/////////////////////
			if (numberOfNames != 0)
			{

				cout << "Here is your name list! Type in the corresponding number to choose your name!" << endl;


				for (int x = 0; x < numberOfNames; x++)
				{
					cout << (x) << ": " << presetNameList[x] << endl;
				}

				int choice;
				cin >> choice;

				character.m_name = presetNameList[choice];
			}
		}

		///////////////////////////////////////////////////
		// this option leads the player directly into character creation, letting them type in their own name
		//////////////////////////////////////////////////
		if (playerNameOption == 2)
		{
			system("cls");
			cout << "Please enter your character name." << endl;
			cin >> character.m_name;
		}

		system("cls");

		cout << character.m_name << endl;
		cout << endl;

		cout << "Enter base strength: ";
		cin >> character.m_strength;

		cout << "Enter base dexterity: ";               //// these all take in the players input, letting them set their own characters stats
		cin >> character.m_dexterity;

		cout << "Enter base magic: ";
		cin >> character.m_magic;

		cout << endl;

		cout << "Please choose your weapon" << endl;
		cout << "(1) Sword ~ S:5 D:2 R:2" << endl;
		cout << "(2) Longbow ~ S:3 D:5 R:5" << endl;
		cout << "(3) Staff ~ S:1 M:5" << endl;
		cout << "(0) no weapon" << endl;

		int chooseWeapon;
		cin >> chooseWeapon;

		//////////////////////////////////////////
		// this allows the player to choose their own weapon, depending on which weapon was chose will be assigned to the character
		/////////////////////////////////////////
		if (chooseWeapon == 1)
		{
			character.pWeapon = p_sword;
		}
		else if (chooseWeapon == 2)
		{
			character.pWeapon = p_longbow;
		}
		else if (chooseWeapon == 3)
		{
			character.pWeapon = p_staff;
		}
		else if (chooseWeapon == 0)
		{
			character.pWeapon = NULL;
		}

		system("cls");

		////////////////////////////
		// outputs all character and weapon information 
		///////////////////////////
		character.PrintName(character.m_name);
		cout << endl;
		character.PrintAttributes(character.m_strength, character.m_dexterity, character.m_magic, character.pWeapon);
		cout << endl;
		character.PrintWeapon();
	}

	//delete[] nameList;     // this was giving me errors

	return 0;
}