#pragma once

#include <dllDefines.h>

#include "iEntity.h"
#include <ai.h>

// implementation
// implement isA mechanism
// set name
// setAI
// TODO determine what other things to implement here

class SOLSTICERUNTIME_API bEntity : public iEntity
{
public:
	virtual void send(void* data, msg_dealloc_t deallocator = NULL);
	virtual void consumeMessages();
	virtual msg_queue_t& getMessageQueue();

	void setName(const std::string&);
	virtual void setAI(ai);
private:
	msg_queue_t m_msgQ;
	ai m_ai;
	std::string name;
};