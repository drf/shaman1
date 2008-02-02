#ifndef STRINGUTILS_H_
#define STRINGUTILS_H_

#include <iostream>
#include <string.h>
#include <QtGui>

#include <alpm_list.h>

class StringUtils
{
	
public:
	StringUtils();
	virtual ~StringUtils();
	
protected:
	char *strtoupper(char *str);
	char *strtrim(char *str);
	static void _strnadd(char **str, const char *append, unsigned int count);
	char *strreplace(const char *str, const char *needle, const char *replace);
	alpm_list_t *strsplit(const char *str, const char splitchar);
};

#endif /*STRINGUTILS_H_*/
