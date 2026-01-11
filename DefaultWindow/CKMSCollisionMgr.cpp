#include "pch.h"
#include "CKMSCollisionMgr.h"
#include "CKMSObj.h"
#include "CKMSLine.h"
#include "CKeyMgr.h"
#include "CKMSPlayer.h"
#include "CLeftShose.h"
#include "CRightShose.h"
void CKMSCollisionMgr::CheckLine(CObj* _Body, CObj* _Line)
{

	int Count = 0;
	for (auto i : dynamic_cast<CKMSObj*>(_Body)->Get_Point()) {
		
		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_RIGHTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
		
				D3DXVECTOR3 m_UpVec;
				D3DXVECTOR3 m_DownVec;
				D3DXVECTOR3 m_DirVec;
				D3DXVECTOR3 m_DirLook;
			//	cout << Count << "번 점 충돌 <오른쪽>" << endl;
				if (CKeyMgr::Get_Instance()->Key_Pressing('O') || CKeyMgr::Get_Instance()->Key_Pressing('P')) {
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
						m_UpVec = dynamic_cast<CKMSObj*>(_Body)->Get_Point()[0];
						m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_Point()[0];
						m_DirVec = m_UpVec - m_DownVec;
						m_DirLook = { 1.f, 0.f, 0.f };
						float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);

						if (fCosTheta > 0) {
							dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(0.01f);
							if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

								m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
								m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
								m_DirVec = m_UpVec - m_DownVec;
								m_DirLook = { 1.f, 0.f, 0.f };
								float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
								if (fCosTheta >= 0)
								{
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
								}

								else {
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
								}
							}
						}

						if (fCosTheta < 0) {
							dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(-0.01f);

							if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

								m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
								m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
								m_DirVec = m_UpVec - m_DownVec;
								m_DirLook = { 1.f, 0.f, 0.f };
								float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
								if (fCosTheta >= 0)
								{
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
								}

								else {
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
								}
							}
						}

			

					}
				}
				if (!CKeyMgr::Get_Instance()->Key_Pressing('O') || !CKeyMgr::Get_Instance()->Key_Pressing('P')) {
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
						m_UpVec = dynamic_cast<CKMSObj*>(_Body)->Get_Point()[0];
						m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_Point()[0];
						m_DirVec = m_UpVec - m_DownVec;
						m_DirLook = { 1.f, 0.f, 0.f };
						float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);

						if (fCosTheta > 0) {
							dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(-0.01f);
							if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

								m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
								m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
								m_DirVec = m_UpVec - m_DownVec;
								m_DirLook = { 1.f, 0.f, 0.f };
								float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
								if (fCosTheta >= 0)
								{
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
								}

								else {
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
								}
							}
						}

						if (fCosTheta < 0) {
							dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(-0.01f);

							if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

								m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
								m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
								m_DirVec = m_UpVec - m_DownVec;
								m_DirLook = { 1.f, 0.f, 0.f };
								float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
								if (fCosTheta >= 0)
								{
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
								}
								else {
									dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
								}
							}
						}



					}
					static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_RightIs(true);
					dynamic_cast<CRightShose*>(_Body)->Set_CollisionIs(true);
				}

				if (i.y > static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
					//auto j = (static_cast<CKMSObj*>(_Line)->Get_Point().front().y - i.y);
					auto j = static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Get_PrevPos() - static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body))->Get_RootObject()->Get_Info().vPos;
			
			
					static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_Pos(static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body))->Get_RootObject()->Get_Info().vPos + j);
				

					if (CKeyMgr::Get_Instance()->Key_Pressing('O') || CKeyMgr::Get_Instance()->Key_Pressing('P')) {

						static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_RightIs(false);
						dynamic_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Add_Point();
						dynamic_cast<CRightShose*>(_Body)->Set_CollisionIs(false);
					}
				}

			}
		}
	

		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_LEFTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
		
				//cout << Count << "번 점 충돌 <왼쪽>" << endl;
				D3DXVECTOR3 m_UpVec;
				D3DXVECTOR3 m_DownVec;
				D3DXVECTOR3 m_DirVec;
				D3DXVECTOR3 m_DirLook;
				if (CKeyMgr::Get_Instance()->Key_Pressing('Q') || CKeyMgr::Get_Instance()->Key_Pressing('W')) {
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
						m_UpVec = dynamic_cast<CKMSObj*>(_Body)->Get_Point()[0];
						m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_Point()[0];
						m_DirVec = m_UpVec - m_DownVec;
						m_DirLook = { 1.f, 0.f, 0.f };
						float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);

						{
							if (fCosTheta > 0) {
								dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(0.01f);
								if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

									m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
									m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
									m_DirVec = m_UpVec - m_DownVec;
									m_DirLook = { 1.f, 0.f, 0.f };
									float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
									if (fCosTheta >= 0)
									{
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
									}

									else {
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
									}


								}
							}

							if (fCosTheta < 0) {
								dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(-0.01f);

								if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

									m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
									m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
									m_DirVec = m_UpVec - m_DownVec;
									m_DirLook = { 1.f, 0.f, 0.f };
									float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
									if (fCosTheta > 0)
									{
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
									}

									else {
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
									}
								}
							}
						}

							
	
						

					}
				}
	
				if (!CKeyMgr::Get_Instance()->Key_Pressing('Q') && !CKeyMgr::Get_Instance()->Key_Pressing('W')) {
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
						m_UpVec = dynamic_cast<CKMSObj*>(_Body)->Get_Point()[0];
						m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_Point()[0];
						m_DirVec = m_UpVec - m_DownVec;
						m_DirLook = { 1.f, 0.f, 0.f };
						float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);


					
							if (fCosTheta > 0) {
								dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(-0.01f);
								if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

									m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
									m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
									m_DirVec = m_UpVec - m_DownVec;
									m_DirLook = { 1.f, 0.f, 0.f };
									float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
									if (fCosTheta >= 0)
									{
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
									}
									else {
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
									}
								}
							}

							if (fCosTheta < 0) {
								dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(0.01f);

								if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {

									m_UpVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body))->Get_Point()[0];
									m_DownVec = dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Get_Point()[0];
									m_DirVec = m_UpVec - m_DownVec;
									m_DirLook = { 1.f, 0.f, 0.f };
									float fCosTheta = D3DXVec3Dot(&m_DirVec, &m_DirLook);
									if (fCosTheta > 0)
									{
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);
									}
									else {
										dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);
									}
								}
							}

							static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_LeftIs(true);


							dynamic_cast<CLeftShose*>(_Body)->Set_CollisionIs(true);

					}
				}

				if (i.y  > static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
					//auto j = (static_cast<CKMSObj*>(_Line)->Get_Point().front().y - i.y);
					auto j = static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Get_PrevPos() - static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body))->Get_RootObject()->Get_Info().vPos;

					
					/*				static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_Pos({ static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Get_Info().vPos.x
										,static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Get_Info().vPos.y + j ,0.f });*/
					static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_Pos(static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body))->Get_RootObject()->Get_Info().vPos + j);

					if (CKeyMgr::Get_Instance()->Key_Pressing('Q') || CKeyMgr::Get_Instance()->Key_Pressing('W')) {

						dynamic_cast<CLeftShose*>(_Body)->Set_CollisionIs(false);
						static_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_LeftIs(false);
						dynamic_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Add_Point();
					}
				}

			
			}
		}

		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_BODY) {
			if (i.y >= 590.f) {

				dynamic_cast<CKMSPlayer*>(dynamic_cast<CKMSObj*>(_Body)->Get_RootObject())->Set_Gravity(false);
			}
		}
		Count++;
	}
	

}

int CKMSCollisionMgr::CheckCorrect(CObj* _Body, CObj* _Line)
{
	for (auto i : dynamic_cast<CKMSObj*>(_Body)->Get_Point()) {

		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_RIGHTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
				return 1;
			}
		}


		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_LEFTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {
				
				return 1;
			}
		}

	
	}

	return 0;

}
