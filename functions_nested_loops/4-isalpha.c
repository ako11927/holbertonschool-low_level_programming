#include "main.h"

/**
 * _isalpha - checks for an alphabetic character
 * @c: char code
 * Return: 1 if a letter, 0 otherwise
 */
int _isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
