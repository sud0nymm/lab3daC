/****************************
 * Lab 3: exercise 2        *
 ****************************/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <numeric>

double distanceTraveled(const std::vector<std::pair<int, int>> points);
double calculateDistance(const std::pair<int, int>& p1, const std::pair<int, int>& p2);

int main() {

	std::ifstream file("C:/Users/ville/Desktop/tng033/lab3/code/points.txt");

	std::string line;

	if (file.is_open()) {

		std::vector<std::pair<int, int>> points;

		int s1, s2;

		char comma;

		std::cout << "The points:\n";

		while (file >> s1 >> comma >> s2) {
			points.emplace_back(s1, s2);
			std::cout << "(" << s1 << "," << s2 << ")\n";
		}

		double f = distanceTraveled(points);

		std::cout << "\nDistance travelled = " << f <<"\n";


	}
	else {
		std::cout << " haha";
	}

}

double distanceTraveled(const std::vector<std::pair<int, int>> points) {
	// ( början 1 vector, slutet, början på annan vektor, funktion för göra med resultat, funktionen som körs på varje del )
	return std::inner_product(std::next(points.begin()), points.end(), points.begin(), 0.0, std::plus<>{}, calculateDistance);

}

double calculateDistance(const std::pair<int, int>& p1, const std::pair<int, int>& p2) {

	return std::sqrt(std::pow(p1.first - p2.first, 2) + std::pow(p1.second - p2.second, 2));
}

