#ifndef _MAVLINKEXCHANGER_H
#define _MAVLINKEXCHANGER_H
#include <queue>
#include "ExtendedMAVLinkMessage.h"

class SerialPort;

class MAVLinkExchanger
{
public:
	explicit MAVLinkExchanger(SerialPort& serialPort);
	void enqueueMessage(ExtendedMAVLinkMessage& message);
	ExtendedMAVLinkMessage dequeueMessage();
	ExtendedMAVLinkMessage peek();
	int sendQueueSize();
	int receiveQueueSize();
	void loop();
private:
	SerialPort& serialPort;
	std::priority_queue<ExtendedMAVLinkMessage> sendQueue;
	std::priority_queue<ExtendedMAVLinkMessage> receiveQueue;

	void sendMessage(const ExtendedMAVLinkMessage& message);
	bool receiveMessage(ExtendedMAVLinkMessage& message);
};
#endif