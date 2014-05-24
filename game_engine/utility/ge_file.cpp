#include "ge_file.h"

namespace ge
{

GEFile::GEFile()
: path_()
, file_(NULL)
, len_(0)
, data_(0)
{

}

GEFile::~GEFile()
{
	release_data();
	close();
}


bool GEFile::open( const char* file_path )
{
	release_data();
	close();

	file_ = fopen(file_path, "rb");
	if (file_ == NULL) return false;

	_fseeki64(file_, 0, SEEK_END);
	len_ = _ftelli64(file_);
	_fseeki64(file_, 0, SEEK_CUR);
	return true;
}

bool GEFile::load( size_t pos /*= 0*/, size_t size /*= 0*/ )
{
	if (file_ == NULL)
	{
		if (!open(path_.c_str()))
			return false;
	}
	release_data();

	if (size <= 0)
		size = len_ - pos;
	if (len_ <= 0) return false;

	data_ = new char[size];
	if (data_ == NULL) return false;
	size_t ret_sz = fread(data_, size, 1, file_);
	if (ret_sz != data_size_)
	{
		release_data();
		return false;
	}
	else
	{
		data_size_ = size;
		return true;
	}
}

void* GEFile::get_data()
{
	return data_;
}

size_t GEFile::get_data_size()
{
	return data_size_;
}

void GEFile::release_data()
{
	if (data_)
	{
		delete data_;
		data_ = NULL;
	}
	data_size_ = 0;
}

void GEFile::close()
{
	if (file_)
	{
		fclose(file_);
		file_ = NULL;
	}
}





}


