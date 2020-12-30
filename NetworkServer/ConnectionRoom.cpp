#include "ConnectionRoom.h"

bool ConnectionRoom::is_full() const
{
    return number_of_participants() == ROOM_LIMIT;
}

void ConnectionRoom::join(participant_ptr participant)
{
    if (participant->get_player())
    {
        // This check is neccesarry because of waiting room.
        _game.add_player(participant->get_player());
    }
    _participants.insert(participant);
}

void ConnectionRoom::leave(participant_ptr participant)
{
    _participants.erase(participant);
}

void ConnectionRoom::deliver(Message& msg, DeliverType d_type)
{
    if (d_type == DeliverType::ALL)
    {
        for (const participant_ptr& participant : _participants)
            participant->deliver(msg);
    }
    else if (d_type == DeliverType::SAME)
    {
        for (const participant_ptr& participant : _participants)
        {
            if (participant->get_owner_id() == msg.get_header().get_owner_id())
                participant->deliver(msg);
        }
    }
    else if (d_type == DeliverType::OPPOSITE)
    {
        for (const participant_ptr& participant : _participants)
        {
            if (participant->get_owner_id() != msg.get_header().get_owner_id())
                participant->deliver(msg);
        }
    }
}

std::size_t ConnectionRoom::number_of_participants() const
{
    return _participants.size();
}