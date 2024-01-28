#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include <unistd.h>


void simu(){
	while(1){
		printf("RED\n");
		sleep(5);

		printf("GREEN\n");
		sleep(2);

		printf("YELLOE\n");
		sleep(3);
	}
}

int main(){
	simu();

}