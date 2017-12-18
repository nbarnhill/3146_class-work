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

const char* my_messages[4] = {"English: Hello!", 
	   "French: Bonjour!", "Spanish: Hola!", "German: Guten Tag!" };


void *printMessage(void *index)
{
   
   cout << my_messages[*(int*)index] << endl;
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
   
   for (int z= 0; z< 4; z++)
   {
   rc = pthread_create(&id, NULL, printMessage, (void*) &z);
   pthread_join(id, NULL);
   }
   
   if (rc)
   {
      cout << "ERROR; return code from pthread_create() is " << rc << endl;
      return -1;
   }
   

   // NOTE: Using exit here will immediately end execution of all threads
   pthread_exit(0);
}
