#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <sys/stat.h>

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>
#include <dirent.h>
#include <unistd.h>
#include <limits.h>

#include <alpm_list.h>

#include "StringUtils.h"

StringUtils::StringUtils()
{
}

StringUtils::~StringUtils()
{
}

char *StringUtils::strtoupper(char *str)
{
	char *ptr = str;

	while(*ptr) {
		(*ptr) = toupper(*ptr);
		ptr++;
	}
	return str;
}

/* Trim whitespace and newlines from a string
 */
char *StringUtils::strtrim(char *str)
{
	char *pch = str;

	if(str == NULL || *str == '\0') {
		/* string is empty, so we're done. */
		return(str);
	}

	while(isspace(*pch)) {
		pch++;
	}
	if(pch != str) {
		memmove(str, pch, (strlen(pch) + 1));
	}

	/* check if there wasn't anything but whitespace in the string. */
	if(*str == '\0') {
		return(str);
	}

	pch = (str + (strlen(str) - 1));
	while(isspace(*pch)) {
		pch--;
	}
	*++pch = '\0';

	return(str);
}

/* Helper function for strreplace */
void StringUtils::_strnadd(char **str, const char *append, unsigned int count)
{
	if(*str) {
		*str = (char *)realloc(*str, strlen(*str) + count + 1);
	} else {
		*str = (char *)calloc(sizeof(char), count + 1);
	}

	strncat(*str, append, count);
}

/* Replace all occurances of 'needle' with 'replace' in 'str', returning
 * a new string (must be free'd) */
char *StringUtils::strreplace(const char *str, const char *needle, const char *replace)
{
	const char *p, *q;
	p = q = str;

	char *newstr = NULL;
	unsigned int needlesz = strlen(needle),
							 replacesz = strlen(replace);

	while (1) {
		q = strstr(p, needle);
		if(!q) { /* not found */
			if(*p) {
				/* add the rest of 'p' */
				_strnadd(&newstr, p, strlen(p));
			}
			break;
		} else { /* found match */
			if(q > p){
				/* add chars between this occurance and last occurance, if any */
				_strnadd(&newstr, p, q - p);
			}
			_strnadd(&newstr, replace, replacesz);
			p = q + needlesz;
		}
	}

	return newstr;
}

/** Splits a string into a list of strings using the chosen character as
 * a delimiter.
 *
 * @param str the string to split
 * @param splitchar the character to split at
 *
 * @return a list containing the duplicated strings
 */
alpm_list_t *StringUtils::strsplit(const char *str, const char splitchar)
{
	alpm_list_t *list = NULL;
	const char *prev = str;
	char *dup = NULL;

	while((str = strchr(str, splitchar))) {
		dup = strndup(prev, str - prev);
		if(dup == NULL) {
			return(NULL);
		}
		list = alpm_list_add(list, dup);

		str++;
		prev = str;
	}

	dup = strdup(prev);
	if(dup == NULL) {
		return(NULL);
	}
	list = alpm_list_add(list, strdup(prev));

	return(list);
}
