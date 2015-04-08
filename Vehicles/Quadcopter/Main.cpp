#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>
#include <list>
#include <conio.h>

SerialPort serialPort("COM4");
MAVLinkExchanger exchanger{ serialPort };
Quadcopter quadcopter{ exchanger };
void inputs();

int main() 
{
	std::thread exchangeThread{ &MAVLinkExchanger::loop, &exchanger };
	std::thread inputThread{ inputs };
	std::thread quadcopterThread{ &Quadcopter::loop, &quadcopter };

	inputThread.detach();
	exchangeThread.detach();
	quadcopterThread.join();
}

void inputs()
{
	while (1)
	{
		switch (_getch())
		{
		case 'a':
			quadcopter.arm();
			break;
		case 'd':
			quadcopter.disarm();
			break;
		}
	}
}