#include<stdio.h>
#include<stdbool.h>
#include<pthread.h>


#define MAX_SIZE 100

typedef struct{
  int arr[MAX_SIZE];
  int size;
}Array;
Array array;

pthread_mutex_t lock1;
pthread_mutex_t lock2;

pthread_t insertThread, deleteThread, searchThread;

void* insert(void* arg){
	int val = *(int*)arg;
	pthread_mutex_lock(&lock1);	
	pthread_mutex_lock(&lock2);	
	 if(array.size < MAX_SIZE){
	  array.arr[array.size] = val;
	  array.size++;
	  printf("\nFor Insert:-   new Element %d is added\n", val);
	 }
	 else{
	  printf("Array size is maxout so can not be inserted\n");

	 }
	pthread_mutex_unlock(&lock2);	
	pthread_mutex_unlock(&lock1);	
	 return NULL;
}


//delete a element from the array

void* delete(void* arg){
 int val = *(int*)arg;
 bool found = false;
	pthread_mutex_lock(&lock2);	
	pthread_mutex_lock(&lock1);	
 for(int i = 0; i < array.size; i++){

	if(val == array.arr[i]){
		for(int j = i; j < array.size - 1; j++){
			array.arr[j] = array.arr[j + 1];
		}
	
	array.size--;
	found = true;
	}
 }
	
	printf("\nUnder Delete -");
	if(found == true){

		printf("We have successfully deleled the element:%d \n",val);
	}
	else{
		printf("We can not founda and delete item: %d\n", val);
	} 
	pthread_mutex_unlock(&lock1);	
	pthread_mutex_unlock(&lock2);	
 	return NULL;
 
}

void* search(void* arg){
	int val = *(int*)arg;
	pthread_mutex_lock(&lock1);
	bool found = false;
	for(int i = 0; i < array.size; i++){
		if(array.arr[i] == val){
			found = true;
		}
	}
	printf("\nFor Search");
	if(found) {
		printf("We have a element %d is our array\n", val);
	}
	else{
		printf("we have not found our element in array\n");
	}
	pthread_mutex_unlock(&lock1);
	return NULL;

}


int main(){
	array.size = 0;
	pthread_mutex_init(&lock1, NULL);
	pthread_mutex_init(&lock2, NULL);

	int inserVal = 10;
	int searchVal = 40;
	int deleteVal = 10;
	inserVal = 40;
	pthread_create(&insertThread, NULL, insert, &inserVal);
	pthread_join(insertThread, NULL);

	pthread_create(&searchThread, NULL, search, &searchVal);
	pthread_join(searchThread, NULL);

 	pthread_create(&deleteThread, NULL, delete, &deleteVal);
 	pthread_join(deleteThread, NULL);


 	pthread_mutex_destroy(&lock1);
 	pthread_mutex_destroy(&lock2);

	
	
	
 return 0;
}
