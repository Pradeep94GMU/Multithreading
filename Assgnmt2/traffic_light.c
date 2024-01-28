#include<stdio.h>
#include <unistd.h>

void simulationOfLight(){
	printf("Green Light\n");
    sleep(30); 

    printf("Yellow Light\n");
    sleep(5); 

    printf("Red Light\n");
    sleep(35); 
}


int main(){
	
	while(1){
		simulationOfLight();
	}
}