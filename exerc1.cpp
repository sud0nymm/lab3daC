/*****************************************
 * Lab 3: exercise 1                      *
 ******************************************/

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

 /*

AE EM 102
AN PS 190
EM BD 23
CK EM 15
FF CK 17
AE CK 9
PS FF 50
DH FF 35
DH EM 65
PS AN 75
FF CK 18
AE EM 91
JP FF 203
0 0 0
*/


int main() {

	std::cout << "input transactions:\n\n";

	std::map <std::string, int> transactions;

	std::string payer;
	std::string reciever;
	int amount;

	while (std::cin >> payer >> reciever >> amount) {

		if (payer == "0" || reciever == "0" || amount == 0) break;

		transactions[payer] += amount;
		transactions[reciever] -= amount;
	}

	std::vector<std::pair<std::string, int>> namesAndAmount(transactions.begin(), transactions.end());
	std::sort(namesAndAmount.begin(), namesAndAmount.end(), [](const auto& a, const auto& b) {
		return a.second > b.second;
	});

	for (auto const& v : namesAndAmount) {
		// v is a reference to a vector element

		std::cout << v.first << "\t" << v.second << "\n";
	}

	return 0;
}
