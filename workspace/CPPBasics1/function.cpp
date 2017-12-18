#include <iostream>
using namespace std;

 void swapInts (int *x, int *y)
 {
     int temp=0;
     temp=*x;
     *x=*y;
     *y=temp;
     
     
 }


int main()
{
    
   int num1, num2;
   num1=num2=0;
   
   cout<< "Please enter int two whole numbers\n";
    cin>>num1;
    cin>>num2;
    
    cout << "Now let's swap the two values:" << num1<< "\t" << num2<<endl;
    
    swapInts(&num1, &num2);
    
    cout << "The values should now be :" << num1 <<"\t"<< num2<<endl;
    
    
   
return 0;    
}

    