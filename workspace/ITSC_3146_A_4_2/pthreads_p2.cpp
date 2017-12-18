/*
 @file: pthreads_skeleton.cpp
 
 @author: student name1, student2@uncc.edu
 @author: student name2, student2@uncc.edu
 @author: student name3, student3@uncc.edu
 
 @description: A program that demonstrates processes.
 
 @course: ITSC 3146
 @assignment: in-class activity [n]
 */

#include <pthread.h>
#include <iostream>

using namespace std;


// This function shows the skeleton that pthread 
// functions must adhere to. 
// Copy this skeleton for any pthread function 
// you need to define. 
// In the copy, modify the name of the function 
// and the function body as needed. 

int my_Array [10];//global array
int final_Average=0;
int total_Neg=0;

void *countNegatives(void *arg)
{

   for (int x=0; x<10;x++)
   {
      if (my_Array[x]<0)
         total_Neg++;
   }
   cout<< "Total negative numbers: "<<total_Neg<<endl<<endl;
   return 0;
}


void *average(void *arg)
{  
   int runningTotal=0;
   
   for (int x=0; x<10; x++)
   {
      
      runningTotal+=my_Array[x];
      
   }
   final_Average=(runningTotal/10);
   cout << "Average: "<< final_Average<<endl<<endl;
   return 0;
}

void *reverse(void *arg)
{
   cout << "The numbers in reverse:\n";
   for (int x=9; x>-1; x--)
   cout << my_Array[x]<<endl;
   
   return 0;
}



int main()
{
   // id is used to store a unique thread identifier,
   // returned by the call to create a new POSIX thread
   pthread_t id;
   
   
   // rc is used to store the code returned by the
   // call to create a new POSIX thread. The value is
   // zero (0) if the call succeeds.
   int rc;
   
   cout<< "Please enter 10 whole numbers.\n";
   for (int x=0;x<10;x++)
   {
      
      cin>> my_Array[x];
      
   }

   
   // Create thread(s)
   // TODO: Modify according to assignment requirements
   rc = pthread_create(&id, NULL, countNegatives, NULL);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   for (int count = 0; count < 100000; count++);
   
   rc = pthread_create(&id, NULL, average, NULL);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   
   for (int count = 0; count < 100000; count++);
   
   rc = pthread_create(&id, NULL, reverse, NULL);

   if (rc){
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
