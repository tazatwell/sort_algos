# sort_algos
Timed tests displaying performance times of various sorting algorithms.

TO USE:
  Sorts.cpp is the driver program, taking what type of sort and what file as input. Displays CPU Time after performing
  the sort. Heapsort.cpp, Insertionsort.cpp, Shellsort.cpp, and Quicksort.cpp only have one function, which is called
  by the driver. Each of these take a vector parameter and return a sorted vector. test.py is a python script that 
  creates three input files: A File0.dat that has integers from 1 to 5000 in increasing order (a pre-sorted file), 
  File1.dat has random ints from 1 to 5000, and File2.dat has ints from 5000 to 1 in decreasing order (worst- case 
  scenario for most sorts). test2.py is identical except the files include 500000 ints instead of 5000. 

SPECIAL THANKS:
  Sean Davis, UC Davis Computer Science, created a timetest for comparing insertion and deletion times of various ADTs,
  for a Data Structures assignment. Sorts.cpp is derived from Sean's timetest.cpp but was modfied to include different
  functions and files for sorting vectors instead of adt insertion and deletion. CPUTimer.h is exactly as his. No other 
  files share resemblance.

CONDUCT:
  All are welcome to contribute to this project. Issues that need to be fixed are viewable on the Issues tab. All who
  work on this project must follow the code of conduct viewable in the root repository.
