#include "fileutils.h"
namespace GameEngine {
	std::string read_file(const char *filepath)
	{
		FILE* f;
		fopen_s(&f, filepath, "rt");
		fseek(f, 0, SEEK_END);
		unsigned long length = ftell(f);
		char* data = new char[length + 1];
		memset(data, 0, length + 1);
		fseek(f, 0, SEEK_SET);
		fread(data, 1, length, f);
		fclose(f);

		std::string result(data);
		delete(data);
		return result;
	}
}