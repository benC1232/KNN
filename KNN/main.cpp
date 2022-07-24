#include <iostream>
#include "Classifiable.h"
#include "CsvHelper.h"
#include <map>
int main()
{
	int k = 0;
	std::cout << "how many K?: ";
	std::cin >> k;
	std::vector<Classifiable> classified = CsvHelper::csvToClassifiable("classified.csv");
	std::vector<Classifiable> unclassified = CsvHelper::csvToClassifiable("unclassified.csv");
}