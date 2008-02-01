#ifndef CONFIGURATIONPARSER_H_
#define CONFIGURATIONPARSER_H_

#include <iostream>
#include <string>
#include <alpm.h>
#include <alpm_list.h>
#include <string.h>

#include "StringUtils.h"

using namespace std;

struct PcCnf {
	alpm_list_t *syncdbs;
	alpm_list_t *NoUpgrade;
	alpm_list_t *NoExtract;
	alpm_list_t *IgnorePkg;
	alpm_list_t *IgnoreGrp;
	alpm_list_t *HoldPkg;
	int noPassiveFTP;
	int useDelta;
	int useSysLog;
	char *xferCommand;
	alpm_list_t *serverAssoc;
	bool loaded;
};

struct PkCnf {
	string somefield;
};

typedef struct PcCnf PacmanConf;
typedef struct PkCnf PaKmodConf;

class ConfigurationParser : private StringUtils
{
public:
	ConfigurationParser();
	virtual ~ConfigurationParser();
	
	PacmanConf getPacmanConf(bool forcereload);
	PaKmodConf getPaKmodConf(bool forcereload);
	
protected:
	alpm_list_t *setrepeatingoption(const char *ptr);
	
private:
	void parsePacmanConfig(const char *file, const char *givensection,
			char *givendb);
	void parsePaKmodConf();
	
private:
	PacmanConf pacData;
	PaKmodConf paKData;
};

#endif /*CONFIGURATIONPARSER_H_*/
