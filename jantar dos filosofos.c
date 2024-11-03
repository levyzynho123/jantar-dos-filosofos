#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t gf1,gf2,gf3,gf4,gf5;

void *acoes(void * arg){
    
    int id = *((int *) arg);
    
    printf("\n o filosofo %d está pensando\n",id);
    sleep(2);
    
    while(1){
        //se alimentar
        
        if (id == 5){
            pthread_mutex_lock(&gf5);
            pthread_mutex_lock(&gf1);
            printf("\no filosofo %d iniciou a refeição\n", id);
            sleep(1);
            printf("\no filosofo %d finalizou\n", id);
            pthread_mutex_unlock(&gf5);
            pthread_mutex_unlock(&gf1);
        }
        
        else if (id == 3){
            pthread_mutex_lock(&gf4);
            pthread_mutex_lock(&gf3);
            printf("\no filosofo %d iniciou a refeição\n", id);
            sleep(1);
            printf("\no filosofo %d finalizou\n", id);
            pthread_mutex_unlock(&gf4);
            pthread_mutex_unlock(&gf3);
        }
        
        else if (id == 1){
            pthread_mutex_lock(&gf1);
            pthread_mutex_lock(&gf2);
            printf("\no filosofo %d iniciou a refeição\n", id);
            sleep(1);
            printf("\no filosofo %d finalizou\n", id);
            pthread_mutex_unlock(&gf1);
            pthread_mutex_unlock(&gf2);
        }
        
        else if (id == 4){
            pthread_mutex_lock(&gf5);
            pthread_mutex_lock(&gf4);
            printf("\no filosofo %d iniciou a refeição\n", id);
            sleep(1);
            printf("\no filosofo %d finalizou\n", id);
            pthread_mutex_unlock(&gf5);
            pthread_mutex_unlock(&gf4);
        }
        
        else if (id == 2){
            pthread_mutex_lock(&gf3);
            pthread_mutex_lock(&gf2);
            printf("\no filosofo %d iniciou a refeição\n", id);
            sleep(1);
            printf("\no filosofo %d finalizou\n", id);
            pthread_mutex_unlock(&gf3);
            pthread_mutex_unlock(&gf2);
        }
        //descansar
        printf("\no filosofo %d iniciou o descanso e começou a pensar\n", id);
        sleep(5);
        printf("\no filosofo %d finalizou o descanso \n", id);
        
    }
    
}

int main(){
    
    pthread_mutex_init(&gf1, NULL);
    pthread_mutex_init(&gf2, NULL);
    pthread_mutex_init(&gf3, NULL);
    pthread_mutex_init(&gf4, NULL);
    pthread_mutex_init(&gf5, NULL);
    
    pthread_t f1,f2,f3,f4,f5;
    
    int id1=1;
    int id2=2;
    int id3=3;
    int id4=4;
    int id5=5;
    
    pthread_create(&f1, NULL, acoes,&id1);
    pthread_create(&f2, NULL, acoes,&id2);
    pthread_create(&f3, NULL, acoes,&id3);
    pthread_create(&f4, NULL, acoes,&id4);
    pthread_create(&f5, NULL, acoes,&id5);
    
     pthread_join(f1, NULL);
    pthread_join(f2, NULL);
    pthread_join(f3, NULL);
    pthread_join(f4, NULL);
    pthread_join(f5, NULL);
    
    pthread_mutex_destroy(&gf1);
    pthread_mutex_destroy(&gf2);
    pthread_mutex_destroy(&gf3);
    pthread_mutex_destroy(&gf4);
    pthread_mutex_destroy(&gf5);
    
    
    return 0;
}