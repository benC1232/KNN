#pragma once
#include <vector>
#include <string>
enum {
	euclidean,
	chebyshev,
	manhattan
};
class Classifiable
{
public:
	Classifiable(std::vector<float> values, std::string _type);
	std::string classify(std::vector<Classifiable> training, int k, int type);
	std::string getType();
private:
	std::vector<float> _values;
	std::string _type;
	float euclideanDistance(Classifiable& other);
	float chebyshevDistance(Classifiable& other);
	float manhattanDistance(Classifiable& other);
};
