#pragma once

class CDeltaMgr
{
private:
	CDeltaMgr():
		m_dwTime(GetTickCount()),
		m_fDelta(m_dwTime / 1000.f),
		m_fElapsed(0.f)
	{}
	CDeltaMgr& operator=(CDeltaMgr&) = delete;
	CDeltaMgr(const CDeltaMgr& rhs) = delete;
	~CDeltaMgr() = default;

public:
	void TickUpdate()
	{
		DWORD dwCurr = GetTickCount();
		m_fDelta = (float)(dwCurr - m_dwTime) / 1000.f;
		m_fElapsed += m_fDelta;
		m_dwTime = dwCurr;
	}
	float Get_Delta() { return m_fDelta; }
	float Get_Elapsed() { return m_fElapsed; }

private:
	DWORD m_dwTime;
	float m_fDelta;
	float m_fElapsed;

public:
	static CDeltaMgr* Get_Instance()
	{
		if (nullptr == m_pInstance)
			m_pInstance = new CDeltaMgr;

		return m_pInstance;
	}

	static void		Destroy_Instacne()
	{
		if (m_pInstance)
		{
			delete m_pInstance;
			m_pInstance = nullptr;
		}
	}

private:
	static CDeltaMgr* m_pInstance;
};

