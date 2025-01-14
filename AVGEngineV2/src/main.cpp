
#include "gxp/gxpInterface.h"

#include <stdio.h>

int wmain(int argv, wchar_t* args[])
{
	if (argv < 4)
	{
		printf("Usage:\n");
		printf("Extract Resource : <ToolName> -e <archive path> <extract directory>\n");
		printf("Create Archive : <ToolName> -c <resource directory> <create archive path> [encrypt Flag](y/n,default:y) [archiveEncryptVersion](V2/V3,defalut:V2)\n");
		printf("Extract Scenario Text : <ToolName> -s <script path> <extract directory>\n");
		printf("Import Scenario Text :<ToolName> -i <orig script path> <translated scenario directory> <create new script path>\n");
	}
	else
	{
		if (_wcsicmp(args[1], L"-e") == 0)
		{
			ExtractResourcesFromGxpArchive(args[2], args[3]);
		}
		else if (_wcsicmp(args[1], L"-c") == 0)
		{
			if(argv<5)
			{
				CreateGxpArchiveImportResources(args[2], args[3], true, ArchiveVersion::V2);
			}
			else if (argv == 5)
			{
				CreateGxpArchiveImportResources(args[2], args[3], _wcsicmp(args[4], L"y") == 0 ? true : false,ArchiveVersion::V2);
			}else
			{
				CreateGxpArchiveImportResources(args[2], args[3], _wcsicmp(args[4], L"y") == 0 ? true : false, _wcsicmp(args[5], L"V2") == 0 ? ArchiveVersion::V2 : ArchiveVersion::V3);
			}
		}
		else if (_wcsicmp(args[1], L"-s") == 0)
		{
			ExtractScenarioFromScript(args[2], args[3]);
		}
		else if (_wcsicmp(args[1], L"-i") == 0)
		{
			if (argv >= 5)
			{
				UpdateScenarioByOrigScript(args[2], args[3], args[4]);
			}
			else
			{
				printf("ERROR : please enter <updated script path>\n");
			}
		}
	}

	return 0;
}