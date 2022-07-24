#pragma once
#include "Classifiable.h"

class CsvHelper
{
public:
	static std::vector<Classifiable> csvToClassifiable(std::string path);
};
