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
			D3DXVECTOR3 vResult;
			if (Collision_Box(vResult, pDst, pSrc))
			{
				pDst->Collision(pSrc);
				pSrc->Collision(pDst);
			}
		}
	}
}

bool KJJ_CollisionMgr::Collision_Box(D3DXVECTOR3 vResult, CKJJObj* pDst, CKJJObj* pSrc)
{
	/*
	Result : Src가 Dst를 밀어내는 벡터
	시계방향
	 0		1


	 3		2
	*/

	bool bResult(false), bSrcAxisX(false), bSrcAxisY(false);

	D3DXVECTOR3 vCenter = pDst->Get_Info().vPos - pSrc->Get_Info().vPos;

	D3DXVECTOR3 vSrcAxisX = pSrc->Get_AxisX();
	D3DXVECTOR3 vSrcAxisY = pSrc->Get_AxisY();
	D3DXVECTOR3 vDstAxisX = pDst->Get_AxisX();
	D3DXVECTOR3 vDstAxisY = pDst->Get_AxisY();

	D3DXVECTOR3 vSrcNormX, vSrcNormY, vDstNormX, vDstNormY;

	D3DXVec3Normalize(&vSrcNormX, &vSrcAxisX);
	D3DXVec3Normalize(&vSrcNormY, &vSrcAxisY);
	D3DXVec3Normalize(&vDstNormX, &vDstAxisX);
	D3DXVec3Normalize(&vDstNormY, &vDstAxisY);

	float fCenter_SrcNX = fabsf(D3DXVec3Dot(&vCenter, &vSrcNormX));

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

	D3DXVECTOR3 vSrcPt = pSrc->Get_Point(iSrcPointNum) - pSrc->Get_Info().vPos;

	float fSrcNX_SrcPt	=	D3DXVec3Dot(&vSrcNormX, &vSrcPt);
	float fSrcNX_DstX	=	D3DXVec3Dot(&vSrcNormX, &vDstAxisX);
	float fSrcNX_DstY	=	D3DXVec3Dot(&vSrcNormX, &vDstAxisY);

	float fSrcNX_Sum	=	fabsf(fSrcNX_SrcPt)
							+ fabsf(fSrcNX_DstX)
							+ fabsf(fSrcNX_DstX);
	
	if (fSrcNX_Sum > fabsf(fCenter_SrcNX) + 1.f)
	{
		bSrcAxisX = true;
	}
	else
	{
		bSrcAxisX = false;
	}

	float fCenter_SrcNY =	D3DXVec3Dot(&vCenter, &vSrcNormY);
	float fSrcNY_SrcPt	=	D3DXVec3Dot(&vSrcNormY, &vSrcPt);
	float fSrcNY_DstX	=	D3DXVec3Dot(&vSrcNormY, &vDstAxisX);
	float fSrcNY_DstY	=	D3DXVec3Dot(&vSrcNormY, &vDstAxisY);

	float fSrcNY_Sum	=	fabsf(fSrcNY_SrcPt)
							+ fabsf(fSrcNY_DstX)
							+ fabsf(fSrcNY_DstY);

	if (fSrcNY_Sum > fabsf(fCenter_SrcNY) + 1.f)
	{
		bSrcAxisY = true;
	}
	else
	{
		bSrcAxisY = false;
	}

	bResult = bSrcAxisX && bSrcAxisY;

	if (bResult)
	{
		cout << "충돌" << endl;
	}

	if (fSrcNX_Sum - fabsf(fCenter_SrcNX) < fSrcNY_Sum - fabsf(fCenter_SrcNY))
	{
		vResult = vSrcNormX * (fSrcNX_Sum - fabsf(fCenter_SrcNX));
	}
	else
	{
		vResult = vSrcNormY * (fSrcNY_Sum - fabsf(fCenter_SrcNY));
	}
	return bResult;
}