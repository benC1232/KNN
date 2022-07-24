#include "Classifiable.h"
#include <cmath>
#include <map>

#include <algorithm>
Classifiable::Classifiable(std::vector<float> values, std::string type)
{
	this->_type = type;
	this->_values = values;
}

std::string Classifiable::classify(std::vector<Classifiable> training, int k, int type)
{
	int distance;
	std::vector<std::pair<std::string, int>> distances;
	for (Classifiable neighbor : training)
	{
		switch (type)
		{
		case euclidean:
			distance = this->euclideanDistance(neighbor);
			break;
		case chebyshev:
			distance = this->chebyshevDistance(neighbor);
			break;
		case manhattan:
			distance = this->chebyshevDistance(neighbor);
			break;
		}
		distances.push_back(std::pair<std::string, float>(neighbor.getType(), distance));
	}
	std::sort(distances.begin(), distances.end(), [](auto& left, auto& right) {
		return left.second < right.second;
		});
	distances.resize(k);
}

std::string Classifiable::getType()
{
	return this->_type;
}

float Classifiable::euclideanDistance(Classifiable& other)
{
	if (this->_values.size() != other._values.size())
	{
		throw std::exception("tried to calculate distance between objects with a different number of elements");
	}
	int i = 0;
	float distance = 0;
	for (i = 0; i < this->_values.size(); i++)
	{
		distance += pow(this->_values[i] - other._values[i], 2);
	}
	return sqrt(distance);
}

float Classifiable::chebyshevDistance(Classifiable& other)
{
	if (this->_values.size() != other._values.size())
	{
		throw std::exception("tried to calculate distance between objects with a different number of elements");
	}
	int i = 0;
	float max = 0;
	for (i = 0; i < this->_values.size(); i++)
	{
		if (this->_values[i] - other._values[i] > max)
		{
			max = this->_values[i] - other._values[i];
		}
	}
	return max;
}

float Classifiable::manhattanDistance(Classifiable& other)
{
	if (this->_values.size() != other._values.size())
	{
		throw std::exception("tried to calculate distance between objects with a different number of elements");
	}
	int i = 0;
	int distance = 0;
	for (i = 0; i < this->_values.size(); i++)
	{
		distance += abs(this->_values[i] - other._values[i]);
	}
	return distance;
}