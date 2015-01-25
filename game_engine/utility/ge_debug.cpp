#include "ge_debug.h"

namespace ge
{

bool Debug::is_developer_console_visible_ = false;

void Debug::set_developer_console_visible(bool is_visible)
{
	if (is_developer_console_visible_ == is_visible) return;

	if (is_visible)
	{
		::FreeConsole();
		if (::AllocConsole())
		{
			freopen("CONOUT$", "w", stdout);
			freopen("CONOUT$", "w", stderr);
			is_developer_console_visible_ = is_visible;
		}
	}
	else
	{
		if (::FreeConsole())
		{
			is_developer_console_visible_ = is_visible;
		}
	}
}

void Debug::log(const char* message, const void* context /*= nullptr*/)
{
	// TODO
}

void Debug::log_warning(const char* message, const void* context /*= nullptr*/)
{
	// TODO
}

void Debug::log_exception(const char* message, const void* context /*= nullptr*/)
{
	// TODO
}

void Debug::log_error(const char* message, const void* context /*= nullptr*/)
{

}

}


