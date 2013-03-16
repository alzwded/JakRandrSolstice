#pragma once

#include "gsp.h"
#include "iEntity.h"

class ai {
public:
	ai(const gsp&);
	virtual void loop() =0;

	iEntity& ctx();

private:
	gsp m_ctx;
};