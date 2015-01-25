#ifndef _GAME_ENGINE_DEBUG_H_
#define _GAME_ENGINE_DEBUG_H_

#include "common/ge_include.h"

namespace ge
{

class GE_API Debug
{

public:
	static void log(const char* message, const void* context = nullptr);
	static void log_warning(const char* message, const void* context = nullptr);
	static void log_exception(const char* message, const void* context = nullptr);
	static void log_error(const char* message, const void* context = nullptr);

	static void set_developer_console_visible(bool is_visible);

private:
	static bool is_developer_console_visible_;
};

}

#endif // _GAME_ENGINE_DEBUG_H_