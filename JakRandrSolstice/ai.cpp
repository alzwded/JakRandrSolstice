#include "ai.h"
#include "iEntity.h"
#include "gsp.h"

ai::ai(const gsp & e)
: m_ctx(e)
{}

iEntity& ai::ctx()
{
	return m_ctx.ref<iEntity>();
}