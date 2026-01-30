#include <stdio.h>
#include <pthread.h>


void * func1()
{
    printf("Hello this is thread 1 funtion \n");
}


void * func2()
{
    printf("Hello this is thread 2 function \n");
}

int main()  
{
    pthread_t p1 , p2;

    int a = pthread_create(&p1 , NULL , &func1 , NULL);
    int b = pthread_create(&p2 , NULL , &func2 , NULL);

    if(a != 0 || b != 0){
        return -1;
    }

    pthread_join(p1 , NULL); // waits for thread to finish blocks main thread till
    pthread_join(p2 , NULL);
    return 0;
}