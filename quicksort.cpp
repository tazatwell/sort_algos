//performs insertion sort on file containing ints. Starts sort based on second line.

#include <vector>
#include <iostream>
#include <utility>

using namespace std;


vector<int>  quickSort(vector<int> vec) {
	//cout << "using quick sort..." << endl;
	/*std::vector<int> vec2;
	return vec2; */
	if (vec.size() > 1) {
		vector<int> smaller;
		vector<int> same;
		vector<int> larger;
		vector<int> result;
		int chosen = vec[vec.size() / 2];
		for (int i = 0; i < vec.size(); i++) {
			if (vec[i] < chosen) 
				smaller.push_back(vec[i]);
			else if (vec[i] > chosen)
				larger.push_back(vec[i]);
			else
				same.push_back(vec[i]);
		}
		smaller = quickSort(smaller);
		larger = quickSort(larger);
		result.insert(result.end(), smaller.begin(), smaller.end());
		result.insert(result.end(), same.begin(), same.end());
		result.insert(result.end(), larger.begin(), larger.end());
		return result;
	}
	return vec;

}  


/*
int main() {
	std::vector<int> ar;
	ar.insert(ar.begin(), 32);
	ar.insert(ar.begin() + 1, 18);
	ar.insert(ar.begin() + 2, 6);
	ar.insert(ar.begin() + 3, 22);
	ar.insert(ar.begin() + 4, 28);
	ar.insert(ar.begin() + 5, 2);
	ar.insert(ar.begin() + 6, 14);	
	ar.insert(ar.begin() + 7, 1);	 
	for (int i = 0; i < ar.size(); i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;
	ar = quickSort(ar);
	for (int i = 0; i < ar.size(); i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;

} */
