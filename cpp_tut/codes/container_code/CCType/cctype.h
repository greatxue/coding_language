/*
 * File: cctype.h
 * --------------
 * This file exports the character type property functions from <cctype>.
 */

#ifndef _cctype_h
#define _cctype_h

bool isdigit(char ch);
bool isxdigit(char ch);
bool islower(char ch);
bool isupper(char ch);
bool isspace(char ch);
bool ispunct(char ch);
bool isalpha(char ch);
bool isalnum(char ch);
bool isprint(char ch);

#endif
