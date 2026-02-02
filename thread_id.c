#include <stdio.h>
#include <pthread.h>




void * threadFunction() {

     pthread_t threadId = pthread_self(); // returns thread id 
     
     printf("\nThread id = %lu" , (unsigned long ) threadId);
}

int main() {

    pthread_t t1;

    pthread_create(&t1 , NULL , threadFunction , NULL);

    pthread_join(t1 , NULL);
}