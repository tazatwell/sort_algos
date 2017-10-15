#include "CPUTimer.h"
#include <fstream>
#include <sys/resource.h>
#include "insertionsort.cpp"
#include "shellsort.cpp"
#include "heapsort.cpp"
#include "quicksort.cpp"

using namespace std;


CPUTimer ct;
const int MAX_SIZE = 2500001;

int getChoice(int *size, int *M, int *L)
{
  int choice;
  do{
    cout << "\n      ADT Menu\n0. Quit\n1.  Insertion Sort\n";
    cout << "2.  Shell Sort\n3.  Heap Sort\n";
    cout << "4.  Quick Sort\n";
    cout << "Your choice >> ";
    cin >> choice;
    if(choice < 0 || choice > 4)
      cout << "Your choice is not between 1 and 4.\nPlease try again.\n";
  } while (choice < 0 || choice > 4);
  
	return choice;
} // getChoice()


void RunInsertionSort(char *filename)
{
  std::vector<int> vec;
	ifstream inf(filename);
  int i;


  while(inf >> i)
  {
    vec.push_back(i);
  } //while
	vec = insertionSort(vec);
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}  
	cout << endl;
	cout << vec[vec.size() - 1] << endl;  */
} // RunList()



void RunShellSort(char *filename)
{
  std::vector<int> vec;
	ifstream inf(filename);
  int i;
  while(inf >> i)
  {
    vec.push_back(i);
  } //while
	vec = shellSort(vec);
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}  
	cout << endl; 
	cout << vec[vec.size() - 1] << endl;  */
} // RunList()


void RunHeapSort(char *filename)
{
  std::vector<int> vec;
	ifstream inf(filename);
  int i;
  while(inf >> i)
  {
    vec.push_back(i);
  } //while
	vec = heapSort(vec);
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}  
	cout << endl; 
	cout << vec[vec.size() - 1] << endl;  */
} // RunList()



void RunQuickSort(char *filename)
{
  std::vector<int> vec;
	ifstream inf(filename);
  int i;
  while(inf >> i)
  {
    vec.push_back(i);
  } //while
	vec = quickSort(vec);
	/*for (int i = 0; i < vec.size(); i++) {
		cout << vec[i] << " ";
	}  
	cout << endl; 
	cout << vec[vec.size() - 1] << endl;  */
} // RunList()



int main(){
  char filename[80];
  int choice, size, M, L;
  const rlim_t kStackSize = 256 * 1024 * 1024;   // min stack size = 256 MB
  struct rlimit rl;
  int result;

  result = getrlimit(RLIMIT_STACK, &rl);
  if (result == 0)
  {
    if (rl.rlim_cur < kStackSize)
    {
      rl.rlim_cur = kStackSize;
      result = setrlimit(RLIMIT_STACK, &rl);
      if (result != 0)
        fprintf(stderr, "setrlimit returned result = %d\n", result);
    }
  }

  cout << "Filename >> ";
  cin >> filename;

  do
  {
    choice = getChoice(&size, &M, &L);
    ct.reset();

    switch (choice)
    {
      case 1: RunInsertionSort(filename); break;
      case 2: RunShellSort(filename); break;
      case 3: RunHeapSort(filename); break;
      case 4: RunQuickSort(filename); break;
    }

    cout << "CPU time: " << ct.cur_CPUTime() << endl;
  } while(choice > 0);

  return 0;
}  

