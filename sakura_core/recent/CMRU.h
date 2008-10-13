/*!	@file
	@brief MRU���X�g�ƌĂ΂�郊�X�g���Ǘ�����

	@author YAZAKI
	@date 2001/12/23  �V�K�쐬
*/
/*
	Copyright (C) 1998-2001, YAZAKI
	Copyright (C) 2000, jepro
	Copyright (C) 2002, YAZAKI, aroka
	Copyright (C) 2003, MIK
	Copyright (C) 2004, genta

	This software is provided 'as-is', without any express or implied
	warranty. In no event will the authors be held liable for any damages
	arising from the use of this software.

	Permission is granted to anyone to use this software for any purpose, 
	including commercial applications, and to alter it and redistribute it 
	freely, subject to the following restrictions:

		1. The origin of this software must not be misrepresented;
		   you must not claim that you wrote the original software.
		   If you use this software in a product, an acknowledgment
		   in the product documentation would be appreciated but is
		   not required.

		2. Altered source versions must be plainly marked as such, 
		   and must not be misrepresented as being the original software.

		3. This notice may not be removed or altered from any source
		   distribution.
*/
class CMRU;

#ifndef _CMRU_H_
#define _CMRU_H_

#include <windows.h> /// BOOL,HMENU // 2002/2/10 aroka
#include <vector>
#include "recent/CRecentFile.h"
struct EditInfo; // 2004.04.11 genta �p�����[�^����struct���폜���邽�߁Ddoxygen�΍�
class CMenuDrawer;

//	@date 2002.2.17 YAZAKI CShareData�̃C���X�^���X�́ACProcess�ɂЂƂ���̂݁B
class CMRU{
public:
	//	�R���X�g���N�^
	CMRU();
	~CMRU();

	//	���j���[���擾����
	HMENU CreateMenu( CMenuDrawer* pCMenuDrawer );	//	���[��BpCMenuDrawer���K�v�Ȃ��Ȃ�Ƃ����Ȃ��B
	BOOL DestroyMenu( HMENU hMenu );
	
	//	�t�@�C�����̈ꗗ��������
	std::vector<LPCTSTR> GetPathList() const;

	//	�A�N�Z�X�֐�
	int Length(void);	//	�A�C�e���̐��B
	void ClearAll(void);//	�A�C�e�����폜�`�B
	bool GetEditInfo( int num, EditInfo* pfi );				//	�ԍ��Ŏw�肵��EditInfo�i�����܂邲�Ɓj
	bool GetEditInfo( const TCHAR* pszPath, EditInfo* pfi );	//	�t�@�C�����Ŏw�肵��EditInfo�i�����܂邲�Ɓj
	void Add( EditInfo* pEditInfo );		//	*pFileInfo��ǉ�����B

protected:
	//	���L�������A�N�Z�X�p�B
	struct DLLSHAREDATA*	m_pShareData;		//	���L���������Q�Ƃ����B
	bool IsRemovableDrive( const char* pszDrive );

private:
	CRecentFile	m_cRecentFile;	//����	//@@@ 2003.04.08 MIK

};
#endif