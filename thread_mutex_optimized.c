#include <stdio.h>
#include <pthread.h>



int counter = 0;


pthread_mutex_t lock;

void * loopfunc()
{
  int value = 0; // local variable to perform 


  for(int i =0; i < 1000000 ; i++){
    value++;
  }


  pthread_mutex_lock(&lock);

  counter += value;
   
  pthread_mutex_unlock(&lock);


}
int main()
{
   pthread_t t1 , t2;

   pthread_mutex_init(&lock , NULL);
   pthread_create(&t1 , NULL , loopfunc , NULL);

   pthread_create(&t2 , NULL , loopfunc, NULL);

   pthread_join(t1 , NULL);
   pthread_join(t2 , NULL);


   pthread_mutex_destroy(&lock);



   printf("value of counter = %d " , counter);



    return 0;
}