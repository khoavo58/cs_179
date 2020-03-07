#include "types.h"
#include "user.h"

void test_fcn()
{
  int counter;
  int i;
  for(i=0 ;i<10; i++){
    counter += i;
    printf(1,"%d",counter);
  }
  exit();
}

int main(int argc, const char* argv[]){

  thread_create(&test_fnc);
  printf(1,"success");
  exit();
  
}
