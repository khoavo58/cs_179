#include "types.h"
#include "user.h"

void test_fcn()
{
  int conuter;
  for(int i=0;i<10;i++){
    counter += i;
    printf(counter);
  }
  exit();
}

int main(int argc, chat argv[]){

  thread_create(&test_func);
  printf("success");
  exit();
  
}
