import os;
import random;

def removeAll():
    for i in range(5):
        name = "File" + str(i) + ".dat";
        os.remove(name);
        print("removed " + name);
    return 0;

def allIncreasing(fileName):
    edit = open(fileName, "w");
    for i in range(5000):
        insert = str(i) + " ";
        edit.write(insert);
    return 0;

def randomInsert(fileName):
    edit = open(fileName, "w");
    for i in range(5000):
	x = random.randint(1,5000);
	insert = str(x) + " ";
	edit.write(insert);	
    return 0;

def allDecreasing(fileName):
	edit = open(fileName, "w");
	for i in range(5000):
		insert = str(5000-i) + " ";
		edit.write(insert);
	return 0;


for i in range(3):
    name = "File" + str(i) + ".dat";
    newfile = open(name, "w");
    print("made " + name);
#val = removeAll();
allIncreasing("File0.dat");
randomInsert("File1.dat");
allDecreasing("File2.dat");


