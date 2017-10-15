//performs insertion sort on file containing ints. Starts sort based on second line.

#include <vector>
#include <iostream>
#include <utility>

using namespace std;

int leftChild(int i) {
	return 2 * i + 1;
}

void percDown(vector<int> &a, int i, int n) {
	int child;
	int temp;
	for (temp = a[i]; leftChild(i) < n; i = child) {
		child = leftChild(i);
		if (child != n - 1 && a[child] < a[child + 1]) 
			child++;
		if (temp < a[child]) 
			a[i] = a[child];
		else 
			break;
	}
	a[i] = temp;
}

vector<int>  heapSort(vector<int> vec) {
	cout << "using heap sort...";
	/*std::vector<int> vec2;
	return vec2;	 */
	for (int i = vec.size() / 2 - 1; i >= 0; i--) {
		percDown(vec, i, vec.size());	
	}
	for (int j = vec.size() - 1; j > 0; j--) {
		int swapper = vec[0];
		vec[0] = vec[j];
		vec[j] = swapper;
		percDown(vec, 0, j);
	}
	return vec;
}  



/*int main() {
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
	ar = heapSort(ar);
	for (int i = 0; i < ar.size(); i++) {
		std::cout << ar[i] << " ";
	}
	std::cout << std::endl;

} */
