#include "types.h"
#include "user.h"



thread_lock* loc;

void test_fcn()
{

  int i;
  
  for(i=0 ;i<10; i++){
    //lock
    lock_set(loc);
    printf(1,"%d",i);
    lock_release(loc);
    //unlock
    //join_thread();
  }
  exit();
}

int main(int argc, const char* argv[]){

  lock_create(loc);
  thread_create(&test_fcn);
  //user__kernel_thread_info();
  //user_display_lock(true, tid);
  //join_thread();
  //join_thread();
  printf(1,"success");
  
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
