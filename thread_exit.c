#include <stdio.h>
#include <pthread.h>


void * func() {

  printf("this code will be executed! \n");


  pthread_exit(NULL);


  for(int i = 0; i < 10 ; i++){

  }


  printf("This part will not be executed thread is already terminated! \n");

}


int main() {
    
  pthread_t t1;

  pthread_create(&t1 , NULL , &func , NULL);


  pthread_join(t1 , NULL);

}



