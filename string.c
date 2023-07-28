#include "shell.h"

/**
 * _strlen - Calculates the length of a null-terminated string.
 *
 * @str: Pointer to the null-terminated input string.
 *
 * Return: The length of the input string (excluding the null terminator).
 */

size_t _strlen(const char *str)
{

	size_t length = 0;

	while (str[length] != '\0')
	{
		length++;
	}

	return (length);
}


/**
 * _strcpy - Copies a null-terminated string from the source to the dest
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the null-terminated source string.
 *
 * Return: A pointer to the destination buffer.
 */

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


/**
 * _strcat - Concatenates a null-terminated string to the end
 *
 * @dest: Pointer to the destination buffer.
 * @src: Pointer to the null-terminated source string.
 * Return: A pointer to the destination buffer, now containing result
 */

char *_strcat(char *dest, const char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src != '\0')
	{
		*ptr = *src;
		ptr++;
		src++;
	}

	*ptr = '\0';

	return (dest);
}


/**
 * _strcmp - Compares two null-terminated strings lexicographically.
 *
 * @str1: Pointer to the first null-terminated string.
 * @str2: Pointer to the second null-terminated string.
 * Return: An integer
 */

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

/**
 * _strdup - Duplicates a null terminated string.
 *
 * @str: Pointer to the null-terminated string to duplicate.
 *
 * Return: Pointer to the newly allocated memory containing the duplicate
 */
char *_strdup(const char *str)
{
	size_t length, i;
	char *duplicate;

	if (str == NULL)
		return (NULL);

	length = 0;

	while (str[length] != '\0')
		length++;

	duplicate = (char *)malloc((length + 1) * sizeof(char));
	if (duplicate == NULL)
	{
		free(duplicate);
		return (NULL);
	}

	else if (duplicate != NULL)
	{
		for (i = 0; i <= length; i++)
			duplicate[i] = str[i];
	}

	return (duplicate);
}

