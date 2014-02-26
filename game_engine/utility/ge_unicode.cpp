#include "ge_unicode.h"

namespace ge
{

int utf8_to_unicode( const char* in_string, wchar_t* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	int n_cnt = MultiByteToWideChar(CP_UTF8, 0, in_string, -1, out_buff, buff_size);
	return n_cnt;
}

std::wstring _utf8_to_unicode( const char* in_string )
{
	std::wstring out_string;
	int out_size = utf8_to_unicode(in_string);
	if (out_size <= 0) return out_string;
	out_string.assign(out_size, '\0');
	utf8_to_unicode(in_string, (wchar_t*)out_string.c_str(), out_size);
	return out_string;
}

int unicode_to_utf8( const wchar_t* in_string, char* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	int n_cnt = WideCharToMultiByte(CP_UTF8, 0, in_string, -1, out_buff, buff_size, 0, 0);
	return n_cnt;
}

std::string _unicode_to_utf8( const wchar_t* in_string )
{
	std::string out_string;
	int out_size = unicode_to_utf8(in_string);
	if (out_size <= 0) return out_string;
	out_string.assign(out_size, '\0');
	unicode_to_utf8(in_string, (char*)out_string.c_str(), out_size);
	return out_string;
}

int mbcs_to_unicode( const char* in_string, wchar_t* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;
	int n_cnt = MultiByteToWideChar(codepage, 0, in_string, -1, out_buff, buff_size);
	return n_cnt;
}

std::wstring _mbcs_to_unicode( const char* in_string )
{
	std::wstring out_string;
	int out_size = mbcs_to_unicode(in_string);
	if (out_size <= 0) return out_string;
	out_string.assign(out_size, '\0');
	mbcs_to_unicode(in_string, (wchar_t*)out_string.c_str(), out_size);
	return out_string;
}

int unicode_to_mbcs( const wchar_t* in_string, char* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	int codepage = AreFileApisANSI() ? CP_ACP : CP_OEMCP;
	int n_cnt = WideCharToMultiByte(codepage, 0, in_string, -1, out_buff, buff_size, 0, 0);
	return n_cnt;
}

std::string _unicode_to_mbcs( const wchar_t* in_string )
{
	std::string out_string;
	int out_size = unicode_to_mbcs(in_string);
	if (out_size <= 0) return out_string;
	out_string.assign(out_size, '\0');
	unicode_to_mbcs(in_string, (char*)out_string.c_str(), out_size);
	return out_string;
}

int mbcs_to_utf8( const char* in_string, char* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	std::wstring temp_buff = _mbcs_to_unicode(in_string);
	return unicode_to_utf8(temp_buff.c_str(), out_buff, buff_size);
}

std::string _mbcs_to_utf8( const char* in_string )
{
	std::wstring temp_string = _mbcs_to_unicode(in_string);
	std::string out_string = _unicode_to_utf8(temp_string.c_str());
	return out_string;
}

int utf8_to_mbcs( const char* in_string, char* out_buff /*= NULL*/, int buff_size /*= 0*/ )
{
	if (in_string == NULL) return 0;

	std::wstring temp_buff = _utf8_to_unicode(in_string);
	return unicode_to_mbcs(temp_buff.c_str(), out_buff, buff_size);
}

std::string _utf8_to_mbcs( const char* in_string )
{
	std::wstring temp_string = _utf8_to_unicode(in_string);
	std::string out_string = _unicode_to_mbcs(temp_string.c_str());
	return out_string;
}

}
