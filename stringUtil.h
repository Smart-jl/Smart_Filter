#ifndef __STRING_UTIL_H
#define __STRING_UTIL_H

#include <string.h>
#include <ctype.h>

/* Ѱ�ҵ����ַ� */
char* StringUtil_FindChar(char* str, char charCode);
/* Ѱ���Ӵ������Ӵ����׵�ַ */
char* StringUtil_FindSubString(char* inputStr, char* subStr);
/* �滻�ַ��� */
void StringUtil_ReplaceSubString(char* str1, const char* str2, const char* str3, char* saveStr);
/* �滻�����ַ� */
void StringUtil_ReplaceChar(char* str, char oldChar, char newChar, char* saveStr);
/* �����ַ��滻Ϊ�Ӵ� */
void StringUtil_ReplaceCharWithSubString(char* str, char ch, const char* substring, char* saveStr);
/* �滻������ĸΪ�ַ� */
void StringUtil_ReplaceLettersWithChar(char* str, char replaceChar, char* saveStr);
/* �滻������ĸΪ�ַ��� */
void StringUtil_ReplaceLettersWithString(char* str, const char* replaceStr, char* saveStr) ;
/* �ַ����ָ� */
int StringUtil_Segment(char* inputStr, const char separators, char* saveStr1, char* saveStr2);
/* �ַ���ȫƥ�� */
int StringUtil_StringMath(char* inputStr, const char* matchStr[], int matchStrLen);
/* ��֤�ַ���ֻ����ĸ������ */
int StringUtil_PreLettersAndNumber(char* inputStr, char* saveStr);
int StringUtil_PreLettersAndNumber(char* inputStr, int len,  char* saveStr);
/* �ַ������� */
void StringUtil_Sort(char* inputStr);
/* ������ĸ������ ֻ���·��� */
int StringUtil_FilterLettersAndNumber(char* inputStr, char* saveStr);
#endif