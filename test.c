#include "types.h"
#include "user.h"

void test_fcn()
{

  int i;
  for(i=0 ;i<10; i++){
    printf(1,"%d", i);
  }
  exit();
}

int main(int argc, const char* argv[]){

  thread_create(&test_fcn);
  printf(1,"success");
  exit();
  
}
