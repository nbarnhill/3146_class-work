#include <iostream>
#include <pthread.h>

#define TOTAL_THREADS 2

int count;
int turn;                  // Shared variable, indicates
                           // whose turn it is to execute

bool interested[TOTAL_THREADS];  // Shared variable, indicates
                                 // processes interested in executing

// The thread_id will be either 0 or 1
void enter_region(int thread_id)
{
   int other;                       // ID of the other thread
   
   other = 1 - thread_id;           // The oposite of thread_id
   
   
   // TODO: Add the code to indicate the
   //       thread's interest in executing.
   interested[thread_id]=true;
   
   // TODO: Indicate the thread's turn to execute next
   turn=thread_id;
   
   // TODO: Busy wait until it is the thread's turn to execute
    while(interested[other]==true && turn==thread_id);
   //while(turn==thread_id && interested[other]==true);
}


void leave_region(int thread_id)
{
   // TODO: Add the code to set the flag
   //       indicating that the thread has
   //       exited the critical region.
        interested[thread_id]=false;
   
}


void* myFunction(void* arg)
{
	int thread_id = *((int*) arg);
    
	for(unsigned int i = 0; i < 10; ++i) {
        
      //  TODO:
      //  Make sure that the thread waits for its turn
      //  before it enters the critical region.
      //
      //  HINT: You need one function call
        enter_region(thread_id);
      
      //  Beginning of the critical region
        
      count++;
      std::cout << "Thread #" << thread_id << " count = " << count << std::endl;
        
      //  End of the critical region
      leave_region(thread_id);
      
      // TODO:
      // Make sure that the other thread gets a turn
      //
      //  HINT: You need one function call
        //enter_region(thread_id);
	}
    
	pthread_exit(NULL);
}


//  HINT: It is not necessary to make any changes in main()
int main()
{
    int rc[TOTAL_THREADS];
    pthread_t ids[TOTAL_THREADS];
    int args[TOTAL_THREADS];
    
    count = 0;
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        args[i] = i;
        rc[i] = pthread_create(&ids[i], NULL, myFunction, (void*) &args[i]);
    }
    
    for(unsigned int i = 0; i < TOTAL_THREADS; ++i) {
        pthread_join(ids[i], NULL);
    }
    
    std::cout << "Final count = " << count << std::endl;
    pthread_exit(NULL);
}