#pragma once
#include "CKJJObj.h"
class KJJ_CollisionMgr
{
public:
	static void OBB_Collision(list<CObj*> _pDst, list<CObj*> _pSrc);
	static D3DXVECTOR3 Collision_Box(CKJJObj* pDst, CKJJObj* pSrc);
};

