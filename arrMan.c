#include<stdio.h>
#include<stdbool.h>

#define MAX_SIZE 100

typedef struct{
  int arr[MAX_SIZE];
  int size;
}Array;

void insert(Array* array, int val){
 if(array->size < MAX_SIZE){
  array->arr[array->size] = val;
  array->size++;
  printf("\nA new Element %d is added\n", val);
 }
 else{
  printf("Array size is maxout so can not be inserted\n");

 }
}


//delete a element from the array

void delete(Array* array, int val){
 bool found = false;
 for(int i = 0; i < array->size; i++){

	if(val == array->arr[i]){
		for(int j = i; j < array->size - 1; j++){
			array->arr[j] = array->arr[j + 1];
		}
	
	array->size--;
	found = true;
	}
 }

	if(found == true){
		printf("\nWe have successfully deleled the element:%d \n",val);
	}
	else{
		printf("We can not found any item: %d\n", val);
	} 

 
}

void search(Array* array, int val){
	bool found = false;
	for(int i = 0; i < array->size; i++){
		if(array->arr[i] == val){
			found = true;
		}
	}

	if(found) {
		printf("We have a element %d is our array\n", val);
	}
	else{
		printf("we have not found our element in array\n");
	}


}

void display(Array* array){
 printf("The array's Data is:\n");
 for(int i = 0; i < array->size; i++){
     printf("%d ",array->arr[i]);

 }
 return;

}

int main(){
 Array array;
 array.size = 0;

 insert(&array, 10);
 insert(&array, 20);
 insert(&array, 7);
 
 display(&array);

 delete(&array, 10);
 delete(&array, 5);

 display(&array);
 insert(&array, 16);
 search(&array, 7);
 search(&array, 16);
 search(&array, 100);
 return 0;
}
