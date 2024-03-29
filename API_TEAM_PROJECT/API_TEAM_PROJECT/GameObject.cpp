#include "stdafx.h"
#include "GameObject.h"
#include "ResourceManager.h"
CGameObject::CGameObject()
	: m_fSpeed(0.f), m_bIsDead(false), m_iAniCount(0), m_iCount(0)
{
}


CGameObject::~CGameObject()
{
}

const INFO & CGameObject::GetInfo() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tInfo;
}

const RECT & CGameObject::GetRect() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_tRect;
}

const HDC & CGameObject::GetImage() const
{
	// TODO: 여기에 반환 구문을 삽입합니다.
	return m_Image;
}

void CGameObject::SetPos(float x, float y)
{
	m_tInfo.fX = x;
	m_tInfo.fY = y;
}

void CGameObject::SetDirection(float dir)
{
	m_fDirection = dir;
}

void CGameObject::SetSpeed(float speed)
{
	m_fSpeed = speed;
}

void CGameObject::SetSprite(wstring sprite)
{
	m_Image = CMainGame::GetInstance()->GetResource()->Get(sprite);
	m_AniData = CMainGame::GetInstance()->GetResource()->GetAniData(sprite);
}

void CGameObject::SetRect()
{
	m_tInfo.fCX = this->m_AniData.iWarpWidth*2;
	m_tInfo.fCY = this->m_AniData.iHeight*2;
}

void CGameObject::SetAniCount(int _count)
{
	m_iAniCount = _count;
}

void CGameObject::SetDamaged()
{
	SetDead(true);
}

int CGameObject::GetAniCount()
{
	return m_iAniCount;
}

AniData CGameObject::GetAniData()
{
	return m_AniData;
}

void CGameObject::SetDead(bool bIsDead)

{
	m_bIsDead = bIsDead;
}

void CGameObject::UpdateRect()
{
	m_tRect.left = static_cast<LONG>(m_tInfo.fX - m_tInfo.fCX * 0.5f);
	m_tRect.top = static_cast<LONG>(m_tInfo.fY - m_tInfo.fCY * 0.5f);
	m_tRect.right = static_cast<LONG>(m_tInfo.fX + m_tInfo.fCX * 0.5f);
	m_tRect.bottom = static_cast<LONG>(m_tInfo.fY + m_tInfo.fCY * 0.5f);
}
