#include "CsvHelper.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
std::vector<Classifiable> CsvHelper::csvToClassifiable(std::string path)
{
	std::vector<Classifiable> content;
	std::vector<std::string> row;
	std::string line, word;
	std::vector<float> values;
	bool flag = false;
	std::fstream file(path, std::ios::in);
	if (file.is_open())
	{
		while (getline(file, line))
		{
			row.clear();
			values.clear();
			flag = false;
			std::stringstream str(line);

			while (getline(str, word, ','))
				row.push_back(word);
			for (std::string word : row)
			{
				try
				{
					float temp = std::stof(word);
				}
				catch (...)
				{
					content.push_back(Classifiable(values, word));
					flag = true;
				}
			}
			if (!flag)
			{
				content.push_back(Classifiable(values, std::string("unclassified")));
			}
		}
	}
	else
	{
		std::string errMessage = "could not open file: " + path;
		throw std::exception(errMessage.c_str());
	}
	return content;
}