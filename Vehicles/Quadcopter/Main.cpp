#include "Quadcopter.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <string>
#include "MAVLinkExchanger.h"
#include <iostream>
#include <thread>

int main() 
{
	SerialPort serialPort("COM4");
	MAVLinkExchanger exchanger{ serialPort };
	Quadcopter quadcopter(exchanger);
	std::thread exchangerThread{ &MAVLinkExchanger::loop, &exchanger };
	std::thread quadcopterThread{ &Quadcopter::loop, &quadcopter };
	exchangerThread.detach();
	quadcopterThread.detach();
	while (1)
	{
		//Doe dingen
	}
}