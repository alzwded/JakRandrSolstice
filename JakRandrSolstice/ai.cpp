#include "stdafx.h"
#include "ai.h"
#include "iEntity.h"
#include "gsp.h"

ai::ai(gsp & e, aif_t func)
: m_ctx(e)
, m_func(func)
{}

iEntity& ai::ctx()
{
	return m_ctx.ref<iEntity>();
}