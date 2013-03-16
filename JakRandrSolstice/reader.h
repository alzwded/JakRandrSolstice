#pragma once
#include <iostream>

#include "iEntity.h"
#include "path.h"

/*
formats:
	_ is a placeholder; it can mean NULL, or DEFAULT
	; comments begin with semicolon and go on until EOL
	physical location inside the game world is relative to a ref and offset
		these are symbolized through ref <id> and location <coords>

	room files: (extension .rooms)
		begin_room first
			begin_link second
				x, y, z
				x, y, z
			end_link
			begin_link third
				x, y, z
				x, y, z
			end_link
			begin_entity ball1
				type ball
				location x, y, z
			end_entity
			begin_entity ball2
				type ball
				location x, y, z
			end_entity
			begin_quad _
				0, 0, 0
				0, 100, 0
				100, 100, 0
				100, 0, 0
			end_quad
			begin_quad _
				0, 0, 100
				0, 100, 100
				100, 100, 100
				100, 0, 100
			end_quad
		end_room
		begin_room second
			begin_link first
				x, y, z
				x, y, z
			end_link
			begin_link fourth
				x, y, z
				x, y, z
			end_link
			begin_entity bucket1
				ref _
				type bucket
				location x, y, z
			end_entity
			begin_entity bucket3
				ref bucket1
				type bucket
				location x, y, z
			end_entity
		end_room
		begin_room third
			begin_link first
				x, y, z
				x, y, z
			end_link
			begin_link second
				x, y, z
				x, y, z
			end_link
			begin_entity bucket2
				location x, y, z
				type bucket
			end_entity
		end_room
		begin_room fourth
			begin_link first
				x, y, z
				x, y, z
			end_link
			begin_quad _
				0, 0, 100
				0, 100, 100
				100, 100, 100
				100, 0, 100
			end_quad
			begin_quad _
				0, 0, 100
				0, 100, 100
				100, 100, 100
				100, 0, 100
			end_quad
			begin_quad _
				0, 0, 100
				0, 100, 100
				100, 100, 100
				100, 0, 100
			end_quad
		end_room

	entity files: (extension .entitites)
		begin_body ball
			begin_skel mySkeleton
				ref _				; location is relative to centre of ball
				location 0, 0, 0
				begin_skelnode sk1
					ref _			; location is relative to center of mySkeleton
					location 10, 0, 0
				end_skelnode
				begin_skelnode sk2
					ref _
					location -10, 0, 0
				end_skelnode
				begin_skelnode sk1a
					ref sk1			; location is relative to node sk1
									; skeleton nodes are a bit special because when
									; the parent moves, the child moves too
					location 0, -10, 0
				end_skelnode
				begin_skelnode sk2a
					ref sk2a
					location 0, -10, 0
				end_skelnode
				begin_fleshnode tip
					ref _
					location 0, 10, 0
				end_fleshnode
			end_skel
			begin_skel otherSkeleton
				; some stuff here
			end_skel
			begin_skin _
				begin_tria _			; the actual coordinates are computed 
										; at display-time
					ref mySkeleton/sk1
					ref mySkeleton/sk1a
					ref mySkeleton/tip
				end_tria
				begin_tria _
					ref mySkeleton/sk2
					ref mySkeleton/tip
					ref mySkeleton/sk2a
				end_tria
			end_skin
		end_body
		begin_blob bucket
			begin_quad _
				; coords
			end_quad
			begin_tria
				; coords
			end_tria
		end_blob
		begin_compound complicated
			begin_entity _
				type ball
				ref _
				location 0, 0, 10
			end_entity
			begin_entity b1
				type ball
				ref _
				location 100, 0, 0
			end_entity
			begin_entity b2
				type bucket
				ref b1/mySkeleton/sk2a	; when that node moves, this moves with it
				location -2, -1, 0		; while staying relative
			end_entity
			begin_entity b3
				type ball
				ref b2
				location -20, 0, 2
			end_entity
		end_compound
*/

/*
	Reader r(root);
	istream roomFile("roomfile.rooms"));
	r.readRooms(file);
	istream entities1("core.entities");
	r.readEntities(entities1);
	istream entities2("additional.entities");
	r.readEntities(entities2);

	activeRoom = r.getFirstRoom();
	globalRoomList = activeRoom.computeGlobalRoomList();
	for(;;) {
		receiveInput();

		activeRoom = movePlayerEntityAndUpdateCamera(activeRoom);

		activeRoom.loop();
		for(activeRoom::iterator i = globalRoomList.begin(); i != globalRoomList.end(); ++i) {
			i->loop();
		}

		activeRoom.computeVisible();
		render(activeRoom);
		for(activeRoom::iterator i = activeRoom.begin(); i != activeRoom.end(); ++i) {
			render(*i);
		}

		sleep_();
	}
*/

class Reader
{
public:
	Reader();

	readRooms(const istream& roomStream);
	readEntities(const istream& entityStream);
};