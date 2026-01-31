#include <stdio.h>
#include <pthread.h>


void * func()
{
   printf("Func is called ! \n");
}

int main()
{
   
   pthread_t t[4];
   
   for(int i = 0; i < 4; i++)
   {
     if(pthread_create(&t[i] , NULL , &func , NULL) != 0)
     {
       return -1; // error termination
     }

     printf("Thread %d is spawned! " , i);
   }

   for(int i = 0; i < 4; i++){
     if(pthread_join(t[i] , NULL) != 0){
        return -2;
     }
   }
    return 0;
}