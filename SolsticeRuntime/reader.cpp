#include "stdafx.h"
#include <reader.h>
#include <gsp.h>
#include <roomDB.h>
#include <entityDB.h>
#include <string>
#include <sstream>

#include <EntityTria.h>

#define Reader_THROW() do{ \
	std::wstringstream ss; \
	ss << L"unexpected token " << s.c_str(); \
	THROW_MSG(InvalidFormatException, ss.str().c_str()); \
}while(0)

void Reader::readRooms(std::istream& roomStream)
{
	THROW(NotImplementedException);
}

gsp Reader::readSkin(ReaderContextMap& context, std::istream& entityStream)
{
	THROW_MSG(NotImplementedException, L"Not implemented readSkin");
}

gsp Reader::readFleshNode(ReaderContextMap& context, std::istream& enttiyStream)
{
	THROW(NotImplementedException);
}

gsp Reader::readSkelNode(ReaderContextMap& context, std::istream& enttiyStream)
{
	THROW(NotImplementedException);
}

gsp Reader::readSkeleton(ReaderContextMap& context, std::istream& entityStream)
{
	THROW_MSG(NotImplementedException, L"Not implemented readSkeleton");
}

gsp Reader::readQuad(ReaderContextMap& context, std::istream& entityStream)
{
	std::cerr << " TODO write readQuad after asserting readTria works" << std::endl;
	THROW(NotImplementedException);
	return gsp(UNLL);
}

gsp Reader::readTria(ReaderContextMap& context, std::istream& entityStream)
{
	std::string s;
	bool hasRef(false);
	std::string ref;
	struct node {
		bool absolute;
		std::string path;
		vec3 coords;
	} nodes[3];
	std::string name, fill;
	bool isTexture(false);
	int skelNo = 0;

	entityStream >> name;
	name = prefix + "/" + name;

	while(1) {
		entityStream >> s;
		if(s.compare("ref") == 0) {
			switch(skelNo) {
				case 0:
				case 1:
				case 2:
					nodes[skelNo].absolute = false;
					entityStream >> nodes[skelNo].path;
					break;
				default:
					std::cerr << "too many nodes for a triangle" << std::endl;
					THROW(InvalidFormatException);
			}
			skelNo++;
		} else if(s.compare("ref") == 0) {
			hasRef = true;
			entityStream >> ref;
		} else if(s.compare("location") == 0) {
			switch(skelNo) {
				case 0:
				case 1:
				case 2:
					nodes[skelNo].absolute = true;
					float x, y, z;
					entityStream >> nodes[skelNo].coords[0];
					entityStream >> nodes[skelNo].coords[1];
					entityStream >> nodes[skelNo].coords[2];
					break;
			}
			skelNo++;
		} else if(s.compare("color") == 0) {
			isTexture = false;
			entityStream >> fill;
		} else if(s.compare("texture") == 0) {
			isTexture = true;
			entityStream >> fill;
		} else if(s.compare("end_tria") == 0) {
			break;
		} else {
			Reader_THROW();
		}
	}

	gsp e = fEntity::spawn(te_TRIA);
	EntityTria& tria = e.ref<EntityTria>();

	path p(name, true);

	tria.setName(p.last);
	for(int i = 0; i < 3; ++i) {
		if(nodes[i].absolute) {
			tria.setNode(i, nodes[i].coords);
		} else {
			tria.setNode(i, context.find(nodes[i].path).second);
		}
	}

	if(hasRef) {
		tria.setRef(context.find(ref).second);
	}
	
	if(isTexture) {
		tria.setTexture(fill);
	} else {
		tria.setColor(fill);
	}

	return e;
}

ai Reader::readAI(std::istream& entityStream)
{
	std::string entryPoint, dllName;
	entityStream >> entryPoint;
	entityStream >> s;
	if(s.compare("dll") != 0) {
		Reader_THROW();
	}
	entityStream >> dllName;

	entityStream >> s;
	if(s.compare("end_ai") != 0) {
		Reader_THROW();
	}

	aif_t func = SolsticeApplication::GetPluginManager().get(dllName, entryPoint);
	ai intelligence(me, func);

	return ai;
}

void Reader::readBody(ReaderContextMap& context, std::istream& entityStream)
{
	std::string name, s;

	gsp me = fEntity::spawn(te_BODY);
	EntityBody& body = me.ref<EntityBody>();

	entityStream >> name;

	while(1) {
		entityStream >> s;
		if(s.compare("end_body") == 0) {
			break;
		} else if(s.compare("begin_ai") == 0) {
			ai intelligence = readAI(entityStream);
			body.setAI(intelligence);
		} else if(s.compare("begin_skin") == 0) {
			context["_"] = me;
			gsp e = readSkin(context, entityStream);
			context.insert(std::make_pair(name + "/" + e.get()->name(), e));
			body.addSkin(e);
		} else if(s.compare("begin_skeleton") == 0) {
			context["_"] = me;
			gsp e = readSkeleton(context, entityStream);
			context.insert(std::make_pair(name + "/" + e.get()->name(), e));
			body.addSkeleton(e);
		} else {
			Reader_THROW();
		}
	}

	return e;
}

void Reader::readBlob(ReaderContextMap& context, std::istream& entityStream)
{
	std::string name, s;

	gsp me = fEntity::spawn(te_BLOB);
	EntityBlob& blob = me.ref<EntityBlob>();

	entityStream >> name;

	while(1) {
		entityStream >> s;
		if(s.compare("end_blob") == 0) {
			break;
		} else if(s.compare("begin_ai") == 0) {
			ai intelligence = readAI(entityStream);

			blob.setAI(intelligence);
		} else if(s.compare("begin_tria") == 0) {
			context["_"] = me;
			gsp e = readTria(context, entityStream);
			context.insert(std::make_pair(name + "/" + e.get()->name(), e));
			blob.add(e);
		} else if(s.compare("begin_quad") == 0) {
			context["_"] = me;
			gsp e = readQuad(context, entityStream);
			context.insert(std::make_pair(name + "/" + e.get()->name(), e));
			blob.add(e);
		} else {
			Reader_THROW();
		}
	}

	return e;
}

// lazy load entities
void Reader::readEntities(std::istream& entityStream)
{
	while(!entityStream.eof()) {
		std::string s;
		entityStream >> s;
		if(s.compare("begin_body")) {
			ReaderContextMap m;
			gsp e = readBody(m, entityStream);
			m_db.add(e);
		} else if(s.compare("begin_blob")) {
			ReaderContextMap m;
			gsp e = readBlob(m, entityStream);
			m_db.add(e);
		} else if(s.compare("begin_compound")) {
			THROW_MSG(NotImplementedException, L"Compounds not implemented");
		} else {
			Reader_THROW();
		}
	}
}

// spawn entities in rooms
void Reader::done()
{
}