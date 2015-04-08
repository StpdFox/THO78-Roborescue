#include "MAVLinkExchanger.h"
#include "../Dependencies/Serial/SerialPort.h"
#include <iostream>

MAVLinkExchanger::MAVLinkExchanger(SerialPort& serialPort):
serialPort{ serialPort }
{
}

void MAVLinkExchanger::enqueueMessage(ExtendedMAVLinkMessage& message)
{
	sendQueue.push(message);
}

ExtendedMAVLinkMessage MAVLinkExchanger::peek()
{
	if (receiveQueue.size())
	{
		return receiveQueue.top();
	}
	return ExtendedMAVLinkMessage{};
}

int MAVLinkExchanger::sendQueueSize()
{
	return sendQueue.size();
}

int MAVLinkExchanger::receiveQueueSize()
{
	return receiveQueue.size();
}

void MAVLinkExchanger::loop()
{
	ExtendedMAVLinkMessage message;
	while (1)
	{
		if (sendQueue.size())
		{
			sendMessage(sendQueue.top());
			sendQueue.pop();
		}
		if (receiveMessage(message))
		{
			receiveQueue.push(message);
		}
	}
}

ExtendedMAVLinkMessage MAVLinkExchanger::dequeueMessage()
{
	auto message = peek();
	receiveQueue.pop();
	return message;
}

void MAVLinkExchanger::sendMessage(const ExtendedMAVLinkMessage& message)
{
	unsigned char buffer[MAVLINK_NUM_NON_PAYLOAD_BYTES + message.len];
	int len = mavlink_msg_to_send_buffer(buffer, &message);
	serialPort.writeData(buffer, len);
}

bool MAVLinkExchanger::receiveMessage(ExtendedMAVLinkMessage& message)
{
	mavlink_status_t status;
	unsigned char c;
	serialPort.readData(&c, 1);
	if(mavlink_parse_char(MAVLINK_COMM_0, c, &message, &status))
	{
		return true;
	}
	return false;
}