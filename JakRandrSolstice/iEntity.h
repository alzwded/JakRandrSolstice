#pragma once

#include <dllDefines.h>

#include <string>
#include <list>

#include "tEntity.h"
#include "vec.h"

class gsp;
class path;
class ai;

// nice usage:
//    don't check for unprocessed messages, rather check for messages that
//    weren't processed :D
typedef enum {
	ms_PROCESSED = 0,
	ms_UNPROCESSED = 1,
	ms_BACKLOGGED = 2
} msg_state_t;

typedef void (*msg_dealloc_t)(void**);

typedef struct SOLSTICERUNTIME_API msg_s {
	void* data;
	msg_state_t state;
	msg_dealloc_t deallocator;

	bool operator==(const msg_s& other) { return ((data == other.data) && (state == other.state)); }
	bool operator<(const msg_s& other)
	{
		if(data == other.data) 
			return state < other.state;
		else
			return (data < other.data);
	}
} msg_t;
typedef std::list<msg_t> msg_queue_t;

EXPIMP_TEMPLATE template class SOLSTICERUNTIME_API std::list<msg_t>;

class SOLSTICERUNTIME_API iEntity
{
public:	
	// type hierarchy
	virtual bool isA(tEntity) =0;
	// path inside room / model
	// will be something like /room/model/subpart/myname
	virtual path getPath() =0;
	// get my name (tail of path)
	virtual std::string name() =0;
	// retrieve a sub-entity by path
	// can be relative or absolute
	virtual gsp getByPath(const path&) =0;
	// translate in world coordinates
	virtual void translate(const vec3&) =0;
	// rotate in world coordinates
	virtual void rotate(const vec4&) =0;
	// get location in world coordinates
	virtual vec3& getLocation() =0;
	// set data from a loader or somthing (e.g. reader)
	virtual void set(void*) =0;
	// assign an AI
	virtual void setAI(ai) =0;
	// ai loop
	// also loop on all childrens
	virtual void loop() =0;
	// add a sub-entity
	virtual void addEntity(const gsp&) =0;
	// deep copy
	virtual gsp deepCopy() =0;

	// message passing
	// a message is processed internally by ai but data is deallocated in main loop
	//    using the deallocator
	// if data was instantiated inside a plugin, set this to something that
	//    ignores it; then free it inside the plugin
	virtual void send(void* data, msg_dealloc_t deallocator = NULL) =0; // TODO
	// message consuming -- calls deallocator on the data
	virtual void consumeMessages() =0;
	// retrieve message
	virtual msg_queue_t& getMessageQueue() =0;
};