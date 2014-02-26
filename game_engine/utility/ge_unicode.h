#ifndef _GAME_ENGINE_UTILITY_UNICODE_H_
#define _GAME_ENGINE_UTILITY_UNICODE_H_

#include "../common/ge_include.h"

namespace ge
{

int GE_API utf8_to_unicode(const char* in_string, wchar_t* out_buff = NULL, int buff_size = 0);
int GE_API unicode_to_utf8(const wchar_t* in_string, char* out_buff = NULL, int buff_size = 0);
int GE_API mbcs_to_unicode(const char* in_string, wchar_t* out_buff = NULL, int buff_size = 0);
int GE_API unicode_to_mbcs(const wchar_t* in_string, char* out_buff = NULL, int buff_size = 0);
int GE_API mbcs_to_utf8(const char* in_string, char* out_buff = NULL, int buff_size = 0);
int GE_API utf8_to_mbcs(const char* in_string, char* out_buff = NULL, int buff_size = 0);

// 有stl不能导出，方便使用
std::wstring	_utf8_to_unicode(const char* in_string);
std::string		_unicode_to_utf8(const wchar_t* in_string);
std::wstring	_mbcs_to_unicode(const char* in_string);
std::string		_unicode_to_mbcs(const wchar_t* in_string);
std::string		_mbcs_to_utf8(const char* in_string);
std::string		_utf8_to_mbcs(const char* in_string);

}

#endif