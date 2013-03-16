#pragma once

#include <string>

#include "tEntity.h"
#include "vec.h"

class gsp;
class path;
class ai;

class iEntity
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
	virtual void setAI(const ai&) =0;
	// ai loop
	// also loop on all childrens
	virtual void loop() =0;
	// add a sub-entity
	virtual void addEntity(const gsp&) =0;
	// deep copy
	virtual gsp deepCopy() =0;
};