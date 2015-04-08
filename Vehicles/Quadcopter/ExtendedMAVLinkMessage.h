#ifndef _EXTENDEDMAVLINKMESSAGE_H
#define _EXTENDEDMAVLINKMESSAGE_H
#include "../Dependencies/MAVLink/ardupilotmega/mavlink.h"
#include <array>
#include <chrono>

const std::array<uint8_t, 0> MEDIUM_PRIORITIES = { };
const std::array<uint8_t, 0> HIGH_PRIORITIES = { };
const std::array<uint8_t, 0> EXTREME_PRIORITIES = { };

class ExtendedMAVLinkMessage : public mavlink_message_t
{
public:
	explicit ExtendedMAVLinkMessage(const mavlink_message_t& baseMessage);
	ExtendedMAVLinkMessage();

	friend bool operator<(const ExtendedMAVLinkMessage& lhs, const ExtendedMAVLinkMessage& rhs);

	enum class Priority
	{
		LOW_PRIORITY,
		MEDIUM_PRIORITY,
		HIGH_PRIORITY,
		EXTREME_PRIORITY
	};
	Priority getPriority() const;
	friend std::ostream& operator<<(std::ostream& stream, const Priority& priority);
private:
	std::chrono::system_clock::time_point timeCreated;
};
#endif