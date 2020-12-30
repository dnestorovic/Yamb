#ifndef CONNECTIONROOM_H
#define CONNECTIONROOM_H

#include <set>

#include "../NetworkCommon/common.h"
#include "../Classes/Game.h"
#include "DeliverType.h"
#include "ConnectionParticipant.h"

// Rensposible for participant manipulation and message delivery.
class ConnectionRoom
{
public:
	bool is_full() const;
	void join(participant_ptr participant);
	void leave(participant_ptr participant);
	void deliver(Message& msg, DeliverType d_type);
	std::size_t number_of_participants() const;

private:
	std::set<participant_ptr> _participants;
	Game _game;
};

typedef std::shared_ptr<ConnectionRoom> room_ptr;

#endif