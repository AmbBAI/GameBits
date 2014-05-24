#ifndef _GAME_ENGINE_UTILITY_FILE_H_
#define _GAME_ENGINE_UTILITY_FILE_H_

#include "common/ge_include.h"

namespace ge
{

class GE_API GEResource
{

};

class GE_API GEFile
{
public:
	GEFile();
	virtual ~GEFile();

public:
	bool open(const char* file_path);
	bool load(size_t pos = 0, size_t size = 0);

	void* get_data();
	size_t get_data_size();
	void release_data();

	void close();

protected:
	std::string		path_;

	FILE*			file_;
	size_t			len_;

	void*			data_;
	size_t			data_size_;
};

}

#endif // _GAME_ENGINE_UTILITY_FILE_H_