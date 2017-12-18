#include <iostream>
using namespace std;

int main()
{
    
    int myInt=15;
    
    int *myPointer= &myInt;
    
     cout << "The memory location of the variable of myInt is: \n" << &myInt;
     cout << "\nThe value for the the myPointer variable should be the same address as listed above\n";
     cout << myPointer;
     
     cout << "\nThe value of the variable myInt is:\n" << myInt;
     cout << "\nThe value pointed at by the myPointer variable should be the same, let's find out\n";
     cout <<  *myPointer;
     
     cout << "\nSo far so good, now to change the value of myInt and print the memory location of the variable\n";
     myInt=10;
     cout << &myInt; 
     cout << "\nThe new value of myInt is now: " << myInt << "\nand the value of myPointer should be updated as well\n ";
     cout << *myPointer;
     
return 0;    
}

    