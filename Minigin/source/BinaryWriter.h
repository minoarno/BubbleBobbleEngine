#pragma once
#include <fstream>
#include "Structs.h"

namespace BinaryWriter
{
	void SaveToBin(std::ofstream& out, float f);
	void SaveToBin(std::ofstream& out, const std::string& s);
	void SaveToBin(std::ofstream& out, int i);
	void SaveToBin(std::ofstream& out, DataType d);
};

