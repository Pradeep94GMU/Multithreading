#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <unistd.h>
#include<pthread.h>

pthread_t thread1, thread2, thread3;


void* simu(void* arg){
	
	char* stateOfLight =  (char*)arg;
	while(1){
		printf("%s RED\n", stateOfLight);
		sleep(3);

		printf("%s GREEN\n", stateOfLight);
		sleep(1);

		printf("%s YELLOE\n", stateOfLight);
		sleep(2);
	}

	return NULL;
}

int main(){
	

	pthread_create(&thread1, NULL, simu, "Traffic light 1");

	pthread_create(&thread2, NULL, simu, "Traffic light 2");
	pthread_create(&thread3, NULL, simu, "Traffic light 3");

	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
	return 0;

}