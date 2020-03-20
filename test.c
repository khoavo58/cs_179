#include "types.h"
#include "user.h"

//test functions declaration
void test_fcn(void *arg_ptr);
void test_fcn2(void *arg_ptr);

//Global variables
int ppid;
int COUNT = 0;
//lock struct
thread_lock* locked;

//assert definition
#define assert(x) if (x) {} else { \
   printf(1, "%s: %d ", __FILE__, __LINE__); \
   printf(1, "assert failed (%s)\n", # x); \
   printf(1, "TEST FAILED\n"); \
   kill(ppid); \
   exit(); \
}


int main(int argc, const char* argv[]){

   ppid = getpid();
   lock_create(&locked);

   int arg = 25;
  
    //create 10 threads
   int thread_pid1 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 1. PID : %d\n\n", thread_pid1);

   int thread_pid2 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 2. PID : %d\n\n", thread_pid2);

   int thread_pid3 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 3. PID : %d\n\n", thread_pid3);

   int thread_pid4 = thread_create(test_fcn2, &arg);
   printf(1, "Created thread 4. PID : %d\n\n", thread_pid4);

   int thread_pid5 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 5. PID : %d\n\n", thread_pid5);

   int thread_pid6 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 6. PID : %d\n\n", thread_pid6);
   
   int thread_pid7 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 7. PID : %d\n\n", thread_pid7);
   
   int thread_pid8 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 8. PID : %d\n\n", thread_pid8);
   
   int thread_pid9 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 9. PID : %d\n\n", thread_pid9);
   
   int thread_pid10 = thread_create(test_fcn, &arg);
   printf(1, "Created thread 10. PID : %d\n\n", thread_pid10);

    //assert threads' creation
   assert(thread_pid1 > 0);
   assert(thread_pid2 > 0);
   assert(thread_pid3 > 0);
   assert(thread_pid4 > 0);
   assert(thread_pid5 > 0);
   assert(thread_pid6 > 0);
   assert(thread_pid7 > 0);
   assert(thread_pid8 > 0);
   assert(thread_pid9 > 0);
   assert(thread_pid10 > 0);

   sleep(100);
   
   //9 thread joins
   int join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
  
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n", join_pid);
   
   join_pid = thread_join();
   printf(1, "Joined : %d\n\n", join_pid);

   printf(1, "COUNT : %d\n", COUNT);
   assert(COUNT == 6);

   printf(1, "TEST PASSED\n");
   exit();
}

void

//simple addition of COUNT with spinlocks
test_fcn(void *arg_ptr) {
   int i;
   int arg = *(int*)arg_ptr;
   assert(arg == 25);

   for(i = 0; i < 1000; i++) {
     lock_set(&locked);
     COUNT = COUNT + 2;
     lock_release(&locked);
   }

   exit();
}

//simple multiplication and division of COUNT with spinlocks
void
test_fcn2(void *arg_ptr) {
  int arg = *(int*)arg_ptr;
  assert(arg == 25);
  
  while (COUNT < 1000);
  lock_set(&locked);
  COUNT = COUNT * 2;
  sleep(20);
  COUNT = COUNT / 2;
  lock_release(&locked);
  exit();
}


/*
  DISPLAY
  tid1: has lock
  tid2: has lock
  
  THREAD INFO:
  DISPLAYS STACK,
  HEAP,
  #Threads
  
*/
