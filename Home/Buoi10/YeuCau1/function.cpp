#include "Header.h"

char* replaceStr(char* src, char* sub, char* rep) {
    if (src == nullptr) return nullptr;

    int srcLen = strlen(src);
    int subLen = strlen(sub);
    int repLen = strlen(rep);

    int count = 0;
    for (const char* temp = strstr(src, sub); temp != nullptr; temp = strstr(temp + subLen, sub)) {
        count++;
    }

    int newLen = srcLen + count * (repLen - subLen) + 1;
    char* result = new char[newLen];
    if (!result) return nullptr;

    char* current = result;
    char* next;

    while ((next = strstr(src, sub)) != nullptr) {
        int segmentLen = next - src;
        strncpy(current, src, segmentLen);
        current += segmentLen;

        strcpy(current, rep);
        current += repLen;

        src = next + subLen;
    }

    strcpy(current, src);

    return result;
}
