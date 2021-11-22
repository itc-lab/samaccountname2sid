// nametosid.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <windows.h>
#include <sddl.h>

BOOL ConvertNameToSid(LPTSTR lpszName, PSID *ppSid)
{
	TCHAR        szDomainName[256];
	DWORD        dwSizeDomain = sizeof(szDomainName) / sizeof(TCHAR);
	DWORD        dwSizeSid = 0;
	SID_NAME_USE sidName;

	LookupAccountName(NULL, lpszName, NULL, &dwSizeSid, szDomainName, &dwSizeDomain, &sidName);

	*ppSid = (PSID)LocalAlloc(LPTR, dwSizeSid);

	return LookupAccountName(NULL, lpszName, *ppSid, &dwSizeSid, szDomainName, &dwSizeDomain, &sidName);
}

int _tmain(int argc, _TCHAR* argv[])
{
	LPTSTR lpszUserSid;
	PSID   pSidUser;

	if ( argc < 2 ) {
		TCHAR  szUserName[256];			//	current user name
		DWORD dwBufferSize = _countof( szUserName );
		GetUserName( szUserName, &dwBufferSize );
		if ( !ConvertNameToSid( szUserName, &pSidUser) ) {
			wprintf( TEXT( "ERROR" ) );
			return -1;
		}
	} else {
		if ( !ConvertNameToSid(argv[1], &pSidUser) ) {
			wprintf( TEXT( "ERROR" ) );
			return -1;
		}
	}
	ConvertSidToStringSid(pSidUser, &lpszUserSid);
	wprintf( TEXT("%s"), lpszUserSid );
	LocalFree(pSidUser);
	LocalFree(lpszUserSid);
	return 0;
}

