#pragma once

#include <dllDefines.h>

#include "iEntity.h"

// implementation
// implement isA mechanism
// TODO determine what other things to implement here

class SOLSTICERUNTIME_API bEntity : public iEntity
{
public:
	virtual void send(void* data, msg_dealloc_t deallocator = NULL);
	virtual void consumeMessages();
	virtual msg_queue_t& getMessageQueue();
private:
	msg_queue_t m_msgQ;
};