#include "stdafx.h"
#include <bEntity.h>

void bEntity::send(void* data, msg_dealloc_t deallocator)
{
	msg_t msg = { data, ms_UNPROCESSED, deallocator };
	m_msgQ.push_back(msg);
}

msg_queue_t& bEntity::getMessageQueue()
{
	return m_msgQ;
}

void bEntity::consumeMessages()
{
	msg_queue_t backlog;

	for(msg_queue_t::iterator i = m_msgQ.begin(); i != m_msgQ.end(); ++i) {
		if(i->state == ms_UNPROCESSED) {
			i->state = ms_BACKLOGGED;
			backlog.push_back(*i);
			continue;
		}

		if(i->deallocator) {
			i->deallocator(&i->data);
		} else {
			delete i->data;
		}
	}

	m_msgQ.clear();
	m_msgQ.splice(m_msgQ.begin(), backlog);
}