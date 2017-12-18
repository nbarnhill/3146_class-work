#include <iostream>
using namespace std;

int main()
{
    
    int my_ints[4];//declares the array and predetermines its capacity
      
    int *my_ptrs[4]; //declares the array of pointers
    cout << "Please enter 4 whole numbers of varying magnitude\n";
    
    for(int x=0; x<4; x++)
    {
        
        cin >>my_ints[x];//user input stored inside of array
        
    }
    
   // int *my_ptrs[4]; //declares the array of pointers
     
   
   
    for (int x=0; x<4; x++)
    {
        
        my_ptrs[x]= &my_ints[x];//assigns each pointer to the corresponding index of the
                                //array of user input
    }
    
    /*
    below is a generic bubble sort
    this sort will make the array of pointers
    hold the addresses of the elements in the
    int array in an ascending order without
    altering the intial array of user input
   */
   
    for(int y = 1; y <= 4; y++)
     {
          
          for (int z=0; z <3; z++)
         {
                 // swap elements
               if (*my_ptrs[z+1] < *my_ptrs[z])      
              { 
                    int temp = *my_ptrs[z];
                    *my_ptrs[z] = *my_ptrs[z+1];
                    *my_ptrs[z+1] = temp;
                                   
               }
          }
     }
    
    cout << "\nNow that the array of pointers have been sorted ";
    cout << "it should now display\nthe previously entered numbers";
    cout << " in ascending order.\n";
    
    
    //traverses the pointer array and outputs their
    //newly sorted values
    for (int x=0; x<4;x++)
    {
        
        cout <<*my_ptrs[x]<< "\t";
        
    }
    
   
return 0;    
}

    