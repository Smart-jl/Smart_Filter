#include <stdlib.h>
#include "stringUtil.h"

static int _compare(const void* a, const void* b) {
    return (*(char*)a - *(char*)b);
}

void StringUtil_ReplaceSubString(char* str1, const char* str2, const char* str3, char* saveStr){
    int str1Len = strlen(str1);
    int str2Len = strlen(str2);
    int str3Len = strlen(str3);

    // ����һ����ʱ�ַ����飬���ڱ����滻��Ľ��
    char tempStr[str1Len * (str3Len - str2Len) + 1];

    int i, j, k;
    int matchFound;

    for (i = 0, k = 0; i < str1Len; i++) {
        matchFound = 0;

        // �� str1 ��Ѱ�� str2 ��ƥ��
        if (i <= str1Len - str2Len) {
            for (j = 0; j < str2Len; j++) {
                if (str1[i + j] != str2[j]) {
                    break;
                }
            }

            if (j == str2Len) {
                // �ҵ��� str2 ��ƥ�䣬�� str3 ���Ƶ���ʱ�ַ�������
                for (j = 0; j < str3Len; j++) {
                    tempStr[k++] = str3[j];
                }

                i += str2Len - 1;
                matchFound = 1;
            }
        }

        if (!matchFound) {
            // �� str1 ��δ�ҵ� str2 ��ƥ�䣬����ǰ�ַ����Ƶ���ʱ�ַ�������
            tempStr[k++] = str1[i];
        }
    }

    tempStr[k] = '\0';  // ����ʱ�ַ�����ĩβ��ӿ��ַ�

    // ����ʱ�ַ������еĽ�����ƻ� str1
    strcpy(saveStr, tempStr);
}

void StringUtil_ReplaceCharWithSubString(char* str, char ch, const char* substring, char* saveStr){
    int strLen = strlen(str);
    int subLen = strlen(substring);
    int count = 0;

    // ������Ҫ��������ַ������ܳ���
    for (int i = 0; i < strLen; i++) {
        if (str[i] == ch) {
            count++;
        }
    }

    // �����滻����ַ������ܳ���
    int newLen = strLen + (subLen - 1) * count;

    // ����һ����ʱ�ַ����飬���ڱ����滻��Ľ��
    char tempStr[newLen + 1];

    int j = 0;
    for (int i = 0; i < strLen; i++) {
        if (str[i] == ch) {
            // �����ַ������뵽��ʱ�ַ�������
            for (int k = 0; k < subLen; k++) {
                tempStr[j++] = substring[k];
            }
        } else {
            // ����ԭʼ�ַ�����ʱ�ַ�������
            tempStr[j++] = str[i];
        }
    }

    tempStr[j] = '\0';  // ����ʱ�ַ�����ĩβ��ӿ��ַ�

    // ����ʱ�ַ������еĽ�����ƻ� str
    strcpy(saveStr, tempStr);
}

void StringUtil_ReplaceChar(char* str, char oldChar, char newChar, char* saveStr) {
    int length = strlen(str);
    strcpy(saveStr, str);

    for (int i = 0; i < length; i++) {
        if (saveStr[i] == oldChar) {
            saveStr[i] = newChar;
        }
    }
}

void StringUtil_ReplaceLettersWithChar(char* str, char replaceChar, char* saveStr) {
    int length = strlen(str);
    strcpy(saveStr, str);

    for (int i = 0; i < length; i++) {
        if (isalpha(str[i])) {
            saveStr[i] = replaceChar;
        }
    }
}

void StringUtil_ReplaceLettersWithString(char* str, const char* replaceStr, char* saveStr) {
    int strLen = strlen(str);
    int replaceLen = strlen(replaceStr);

    // ����һ����ʱ�ַ����飬���ڱ����滻��Ľ��
    char tempStr[strLen * replaceLen + 1];

    int tempIndex = 0;
    for (int i = 0; i < strLen; i++) {
        if (isalpha(str[i])) {
            // ���滻�ַ������Ƶ���ʱ�ַ�������
            for (int j = 0; j < replaceLen; j++) {
                tempStr[tempIndex++] = replaceStr[j];
            }
        } else {
            // ����ԭʼ�ַ�����ʱ�ַ�������
            tempStr[tempIndex++] = str[i];
        }
    }

    tempStr[tempIndex] = '\0';  // ����ʱ�ַ�����ĩβ��ӿ��ַ�

    // ����ʱ�ַ������еĽ�����ƻ� str
    strcpy(saveStr, tempStr);
}

void StringUtil_GetLettersAndNumber(char* str, char* saveStr){
    int j = 0;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 'a' && str[i] <= 'z'){
            saveStr[j++] = str[i];
        }else if(str[i] >= 'A' && str[i] <= 'Z'){
            saveStr[j++] = str[i];
        }else if(str[i] >= '0' && str[i] <= '9'){
            saveStr[j++] = str[i];
        }
    }
}

char* StringUtil_FindChar(char* str, char charCode){
    while(*str != '\0'){
        if(*str == charCode)
            return str;
        str++;
    }
    return NULL;
}

int StringUtil_Segment(char* inputStr, const char separators, char* saveStr1, char* saveStr2){
    char* _temp = StringUtil_FindChar(inputStr, separators);
    if(_temp != NULL){
        memcpy(saveStr1, inputStr, _temp - inputStr);
        saveStr1[_temp - inputStr] = '\0';
        strcpy(saveStr2, _temp + 1);
        return 0;
    }
    return -1;
}

int StringUtil_StringMath(char* inputStr, const char* matchStr[], int matchStrLen){
    for(int i = 0; i < matchStrLen; i++){
        if(strcmp(inputStr, matchStr[i]) == 0){
            return i;
        }
    }
    return -1;
}

int StringUtil_PreLettersAndNumber(char* inputStr, char* saveStr){
    int _j = 0;
    for(int i = 0; i < strlen(inputStr); i++){
        if((inputStr[i] >= 'A' && inputStr[i] <= 'Z') ||
           (inputStr[i] >= 'a' && inputStr[i] <= 'z') ||
           (inputStr[i] >= '0' && inputStr[i] <= '9')){
            saveStr[_j++] = inputStr[i];
        }
    }
    saveStr[_j] = '\0';

    return _j;
}

int StringUtil_PreLettersAndNumber(char* inputStr, int len,  char* saveStr){
    int _j = 0;
    for(int i = 0; i < len; i++){
        if((inputStr[i] >= 'A' && inputStr[i] <= 'Z') ||
           (inputStr[i] >= 'a' && inputStr[i] <= 'z') ||
           (inputStr[i] >= '0' && inputStr[i] <= '9')){
            saveStr[_j++] = inputStr[i];
        }
    }
    saveStr[_j] = '\0';

    return _j;
}
char* StringUtil_FindSubString(char* inputStr, char* subStr){
    int len = strlen(inputStr);
    int subLen = strlen(subStr);

    if (len < subLen) {
        return NULL;
    }

    for (int i = 0; i <= len - subLen; i++) {
        int j;
        for (j = 0; j < subLen; j++) {
            if (inputStr[i + j] != subStr[j]) {
                break;
            }
        }
        if (j == subLen) {
            return (char*)&inputStr[i];
        }
    }

    return NULL;
}

void StringUtil_Sort(char* inputStr){
    int len = strlen(inputStr);
    qsort(inputStr, len, sizeof(char), _compare);
}

int StringUtil_FilterLettersAndNumber(char* inputStr, char* saveStr){
    int _j = 0;
    for(int i = 0; i < strlen(inputStr); i++){
        if(!((inputStr[i] >= 'A' && inputStr[i] <= 'Z') ||
           (inputStr[i] >= 'a' && inputStr[i] <= 'z') ||
           (inputStr[i] >= '0' && inputStr[i] <= '9'))){
            saveStr[_j++] = inputStr[i];
        }
    }
    saveStr[_j] = '\0';

    return _j;
}