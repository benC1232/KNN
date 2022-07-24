#include <iostream>
#include "Classifiable.h"
#include "CsvHelper.h"
int main()
{
	std::vector<std::string> euclidean;
	std::vector<std::string> chebyshev;
	std::vector<std::string> mahattan;
	int k = 0;
	std::cout << "how many K?: ";
	std::cin >> k;
	std::vector<Classifiable> classified = CsvHelper::csvToClassifiable("classified.csv");
	std::vector<Classifiable> unclassified = CsvHelper::csvToClassifiable("unclassified.csv");
}