#include <iostream>
using namespace std;

int main()
{
    int input[9];
    int temp=0;//holds the values beign swapped
    
    cout << "Please enter 10 whole numbers.\n";
    for (int x=0; x<10; x++)
    {
        
        cin>> input[x];
        
    }
    
    cout << "So far so good, now let's reverse the order\n";
    
     for (int i=9; i>=0; i--)
     {
         
         cout<< input[i] << "\t";
         
     }
    
    cout<< "\nNow let's sort the list from least to greatest\n";
    
   
      
      for(int y = 1; y <= 10; y++)
     {
          
          for (int z=0; z < (9); z++)
         {
               if (input[z+1] < input[z])      
              { 
                    temp = input[z];             // swap elements
                    input[z] = input[z+1];
                    input[z+1] = temp;
                                   
               }
          }
     }
     for (int x=0; x<10; x++)
     {
         
         cout<< input[x] << "\t";
         
     }
     
return 0;    
}

    