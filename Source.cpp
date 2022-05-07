#include <iostream>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <stdlib.h>
using namespace std;

bool isSetup = false;
bool isClicking = false;
bool isUsingAntiCatch;

char yesorno;
char mouseButton;

int maxWait, minWait;
int msWaitTime;

void Setup()
{
	cout << "PancakeHat's MaxClick autoclicker for Minecraft\n\n";
	cout << "Enable AntiCatch? (y/n)\n&:";
	cin >> yesorno;

	if (yesorno == 'y')
		isUsingAntiCatch = true;
	else
		isUsingAntiCatch = false;

	if (isUsingAntiCatch)
	{
		cout << "\nInput max wait time (in ms)\n&:";
		cin >> maxWait;
		cout << "\nInput min wait time (in ms)\n&:";
		cin >> minWait;
		cout << "\n Which mouse button? (l/r)\n&:";
		cin >> mouseButton;
	}
	else if (!isUsingAntiCatch)
	{
		cout << "Wait time (in milliseconds)\n&: ";
		cin >> msWaitTime;
		cout << "\nWhich mouse button? (l/r)\n&:";
		cin >> mouseButton;
	}

	system("CLS");
	cout << "\n\nPress'F7' to toggle clicking";
	isSetup = true;
}

void Click()
{

	if (isClicking)
	{
		if (isUsingAntiCatch)
		{
			srand(time(0));
			msWaitTime = (rand() % maxWait) + minWait;
		}

		if (mouseButton == 'l')
		{
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
		}
		else if (mouseButton == 'r')
		{
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			Sleep(100);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
		}

	}
		Sleep(msWaitTime);
}

int main()
{
	Setup();

	while (isSetup)
	{
		if (GetAsyncKeyState(VK_F7) & 0x8000)
		{
			isClicking = !isClicking;
		}

		Click();
	}

	return 0;
}