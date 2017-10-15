//performs insertion sort on file containing ints. Starts sort based on second line.

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

void merge(vector<int> &a, vector<int> &tempArray, int leftPos, int rightPos, int rightEnd) {
	int leftEnd = rightPos - 1;
	int tempPos = leftPos;
	int numElements = rightEnd - leftPos + 1;
	while (leftPos <= leftEnd && rightPos <= rightEnd) {
		if (a[leftPos] <= a[rightPos])
			tempArray[tempPos++] = a[leftPos++];
		else
			tempArray[tempPos++] = a[rightPos++];
		while (leftPos <= leftEnd) 
			tempArray[tempPos++] = a[leftPos++];
		while (rightPos <= rightEnd) 
			tempArray[tempPos++] = a[rightPos++];
		for (int i = 0; i < numElements; i++, --rightEnd)
			a[rightEnd] = tempArray[rightEnd];		
	}
}


void mergeSort(vector<int> &a, vector<int> &tempArray, int left, int right) {
	if (left < right) {
		int center = (left + right) / 2;
		mergeSort(a, tempArray, left, center);
		mergeSort(a, tempArray, center + 1, right);
		merge(a, tempArray, left, center + 1, right);
	}
}


vector<int> mergeSortDriver(vector<int> a) {
	/*std::vector<int> vec2;
	return vec2; */
	vector<int> tempArray(a.size());
	mergeSort(a, tempArray, 0, a.size() - 1);
	return a;
}  



int main() {
	std::vector<int> ar;
	int x = 32;
	ar.insert(ar.begin(), x);
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
	ar = mergeSortDriver(ar);
	for (int i = 0; i < ar.size(); i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;

}
