#include <stdio.h>
#include <pthread.h>

 pthread_mutex_t lock;


 int counter = 0;

void * func1()
{
       pthread_mutex_lock(&lock); 
      
    for(int i = 0; i < 1000000; i++)
    { 
     
         counter++;
        
     
    }

     pthread_mutex_unlock(&lock);

     
   
}


int main()
{
   
  pthread_t t[2];

  pthread_mutex_init(&lock , NULL);


  for(int i = 0; i < 2; i++)
{

   int isCreated =  pthread_create(&t[i] , NULL , &func1 , NULL);

   if(isCreated != 0){
     return -1;
   }
   printf("\n Thread %d is created!" , i);

}

   pthread_join(t[0] , NULL);
   pthread_join(t[1] , NULL);


   pthread_mutex_destroy(&lock);

   





   printf("Value of counter = %d ", counter);




}