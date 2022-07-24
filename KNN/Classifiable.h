#pragma once
#include <vector>
#include <string>
class Classifiable
{
public:
	Classifiable(std::vector<float> values, std::string _type);
	float euclideanDistance(Classifiable& other);
	float chebyshevDistance(Classifiable& other);
	float manhattanDistance(Classifiable& other);
private:
	std::vector<float> _values;
	std::string _type;
};
