#ifndef _GAME_ENGINE_UTILITY_UNICODE_H_
#define _GAME_ENGINE_UTILITY_UNICODE_H_

#include "../common/ge_include.h"

namespace ge
{

wchar_t* Utf8ToUnicode(const char* pUtf8);
char* UnicodeToUtf8(const wchar_t* pUnicode);
wchar_t* MbcsToUnicode(const char* pMbcs);
char* UnicodeToMbcs(const wchar_t* pUnicode);
char* MbcsToUtf8(const char* pMbcs);
char* Utf8ToMbcs(const char* pUtf8);
bool StringToInt(const char* strValue, int & iValue);
bool StringToDWord(const char* strValue, unsigned int & dwValue);
bool StringToInt64(const char* strValue, long long & i64Value);
bool StringToUnsignedInt64(const char* strValue, unsigned long long & ui64Value);
inline int UrlEncode(const char *source, char *dest, unsigned max);
char* FormUrlEncode(const char* pEncode);
char* FormUrlDecode(const char* pDecode);
void ReleaseData(void* ptr);

}

#endif