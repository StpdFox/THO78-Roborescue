#ifndef _SERIALPORT_H
#define _SERIALPORT_H
#include <string>
#include <mutex>
class Serial;

class SerialPort
{
public:
	SerialPort(int port, std::string& address);
	explicit SerialPort(const char* device);
	~SerialPort();
	bool writeData(unsigned char* data, int nrOfBytes);
	int readData(unsigned char* buffer, int nrOfBytes);
private:
	Serial* serialDevice;
	std::mutex rwMutex;
};
#endif