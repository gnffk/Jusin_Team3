#include "pch.h"
#include "KJJ_CollisionMgr.h"

void KJJ_CollisionMgr::OBB_Collision(list<CObj*> _pDst, list<CObj*> _pSrc)
{
	for (auto& Dst : _pDst)
	{
		for (auto& Src : _pSrc)
		{
			CKJJObj* pDst = static_cast<CKJJObj*>(Dst);
			CKJJObj* pSrc = static_cast<CKJJObj*>(Src);
			D3DXVECTOR3 vResult = Collision_Box(pDst, pSrc);
			if (D3DXVec3Length(&vResult) != 0)
			{
				pDst->Collision(pSrc);
				pSrc->Collision(pDst);
			}
		}
	}
}

D3DXVECTOR3 KJJ_CollisionMgr::Collision_Box(CKJJObj* pDst, CKJJObj* pSrc)
{
	/*
	벡터방향 Src->Dst
	시계방향
	 0		1


	 3		2
	*/
	D3DXVECTOR3 vCenter = pDst->Get_Info().vPos - pSrc->Get_Info().vPos;

	D3DXVECTOR3 vSrcAxisX = pSrc->Get_AxisX();
	D3DXVECTOR3 vSrcAxisY = pSrc->Get_AxisY();
	D3DXVECTOR3 vDstAxisX = pDst->Get_AxisX();
	D3DXVECTOR3 vDstAxisY = pDst->Get_AxisY();

	float fCenter_SrcX = D3DXVec3Dot(&vCenter, &vSrcAxisX);
	float fCenter_SrcY = D3DXVec3Dot(&vCenter, &vSrcAxisY);

#pragma region int iSrcPointNum
	int iSrcPointNum = 0;
	if (vCenter.y < 0)
	{
		if (vCenter.x < 0)
		{
			iSrcPointNum = 0;
		}
		else
		{
			iSrcPointNum = 1;
		}
	}
	else
	{
		if (vCenter.x > 0)
		{
			iSrcPointNum = 3;
		}
		else
		{
			iSrcPointNum = 4;
		}
	}

#pragma endregion

	D3DXVECTOR3 vSrcPt = pSrc->Get_Point(iSrcPointNum);
	float fSrcX_SrcPt = D3DXVec3Dot(&vSrcAxisX, &vSrcPt);
	float fSrcX_DstX = D3DXVec3Dot(&vSrcAxisX, &vDstAxisX);
	float fSrcX_DstY = D3DXVec3Dot(&vSrcAxisX, &vDstAxisY);

	float fSrcY_SrcPt = D3DXVec3Dot(&vSrcAxisY, &vSrcPt);
	float fSrcY_DstX = D3DXVec3Dot(&vSrcAxisY, &vDstAxisX);
	float fSrcY_DstY = D3DXVec3Dot(&vSrcAxisY, &vDstAxisY);

	float fSrcX_Sum = fSrcX_SrcPt + fSrcX_DstX + fSrcX_DstY;
	float fSrcY_Sum = fSrcY_SrcPt + fSrcY_DstX + fSrcY_DstY;

	if (fSrcX_Sum > fCenter_SrcX && fSrcY_Sum > fCenter_SrcY)
	{
		D3DXVECTOR3 vSrcNormX, vSrcNormY;
		D3DXVec3Normalize(&vSrcAxisX, &vSrcNormX);
		D3DXVec3Normalize(&vSrcAxisY, &vSrcNormY);
		
		return (fSrcX_Sum - fCenter_SrcX) * vSrcNormX +
			(fSrcY_Sum - fCenter_SrcY) * vSrcNormY;
	}
	else
	{
		return { 0,0,0 };
	}
}