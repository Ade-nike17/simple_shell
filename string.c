#include "shell.h"


size_t strlen(const char *str)
{

	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}

char *strcpy(char *dest, const char *src)
{
	char *ptr = dest;

	while (*src != '\0') {
		*ptr = *src;

		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}