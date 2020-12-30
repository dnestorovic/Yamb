enum class DeliverType
{
	SAME, // Send a message to the owner of the message.
	OPPOSITE, // Send a message to participants who don't own the message.
	ALL // Send a message to all participants.
};