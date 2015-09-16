// Execute.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


int _tmain(int argc, _TCHAR* argv[])
{
	TCHAR	tchSolutionDir[MAX_PATH]	= {0};
	TCHAR	tchLuaExe[MAX_PATH]			= {0};
	TCHAR	tchTestLua[MAX_PATH]		= {0};
	TCHAR	tchCmdLine[MAX_PATH]		= {0};
	LPTSTR	lpPosition					= NULL;


	if (GetModuleFileName(NULL, tchSolutionDir, _countof(tchSolutionDir)))
	{
		lpPosition = _tcsrchr(tchSolutionDir, _T('\\'));
		if (lpPosition)
		{
			*(lpPosition) = _T('\0');
			lpPosition = _tcsrchr(tchSolutionDir, _T('\\'));
			if (lpPosition)
			{
				*(lpPosition) = _T('\0');

				_tcscat_s(tchLuaExe, _countof(tchLuaExe), tchSolutionDir);
				_tcscat_s(tchLuaExe, _countof(tchLuaExe), _T("\\Debug\\Lua.exe"));

				_tcscat_s(tchTestLua, _countof(tchTestLua), tchSolutionDir);
				_tcscat_s(tchTestLua, _countof(tchTestLua), _T("\\Test\\Test.lua"));

				_tcscat_s(tchCmdLine, _countof(tchCmdLine), _T("call \""));
				_tcscat_s(tchCmdLine, _countof(tchCmdLine), tchLuaExe);
				_tcscat_s(tchCmdLine, _countof(tchCmdLine), _T("\" \""));
				_tcscat_s(tchCmdLine, _countof(tchCmdLine), tchTestLua);
				_tcscat_s(tchCmdLine, _countof(tchCmdLine), _T("\""));

				CCommandLine::Execute(tchCmdLine, FALSE, FALSE);
			}
		}
	}

	_getch();

	return 0;
}

