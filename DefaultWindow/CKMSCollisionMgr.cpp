#include "pch.h"
#include "CKMSCollisionMgr.h"
#include "CKMSObj.h"

void CKMSCollisionMgr::CheckShoeseLine(CObj* _Shose, CObj* _Line)
{
	D3DXVECTOR3 _ShoesVec;
	auto max = max_element(dynamic_cast<CKMSObj*>(_Shose)->Get_Point().begin(),
		dynamic_cast<CKMSObj*>(_Shose)->Get_Point().end(), [&](const D3DXVECTOR3& a, const D3DXVECTOR3& b) {
			return a.y > b.y;
		});
	

	



}
