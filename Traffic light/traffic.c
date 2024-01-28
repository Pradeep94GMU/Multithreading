#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>

pthread_t thread1, thread2, thread3;
pthread_mutex_t lock;


void* simu(void* arg){

	char* stateOfLight =  (char*)arg;
	while(1){
		
		printf("%s RED\n", stateOfLight);
		sleep(5);
		
		pthread_mutex_lock(&lock);
		printf("%s GREEN\n", stateOfLight);
		sleep(2);
		pthread_mutex_unlock(&lock);
		
		printf("%s YELLOE\n", stateOfLight);
		sleep(5);
		
	}

	return NULL;
}

int main(){
	
	pthread_mutex_init(&lock, NULL);

	pthread_create(&thread1, NULL, simu, "Path A");

	pthread_create(&thread2, NULL, simu, "Path B");
	pthread_create(&thread3, NULL, simu, "Path C");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);

	pthread_mutex_destroy(&lock);
	return 0;

}