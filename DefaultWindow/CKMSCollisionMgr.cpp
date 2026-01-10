#include "pch.h"
#include "CKMSCollisionMgr.h"
#include "CKMSObj.h"
#include "CKMSLine.h"

void CKMSCollisionMgr::CheckLine(CObj* _Body, CObj* _Line)
{

	int Count = 0;
	for (auto i : dynamic_cast<CKMSObj*>(_Body)->Get_Point()) {
		
		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_RIGHTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {

				//cout << Count << "번 점 충돌 <오른쪽>" << endl;
				if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
					dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(0.01f);
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {
						dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(-0.01f);

					}

				}
			}
		}
	

		if (dynamic_cast<CKMSObj*>(_Body)->GetKMSObjType() == KMSOBJ_LEFTSHOES) {
			if (i.y >= static_cast<CKMSObj*>(_Line)->Get_Point().front().y) {

				//cout << Count << "번 점 충돌 <왼쪽>" << endl;
				if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())) {
					dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Plus_Angle(0.01f);
					if (dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject()))) {
						dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(dynamic_cast<CKMSObj*>(_Body)->Get_ParentObject())->Get_ParentObject())->Plus_Angle(0.01f);

					}

				}
			}
		}

		Count++;
	}
	

}
