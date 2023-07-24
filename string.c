#include "shell.h"


size_t _strlen(const char *str)
{

	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

char *_strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src != '\0')
	{
		*ptr = *src;

		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}


char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + strlen(dest);

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}


int _strcmp(const char *str1, const char *str2)
{
	unsigned char char1, char2;

	while (*str1 && *str1 == *str2)
	{
		str1++;
		str2++;
	}

	char1 = *(unsigned char *)str1;
	char2 = *(unsigned char *)str2;


	return (char1 - char2);
}
