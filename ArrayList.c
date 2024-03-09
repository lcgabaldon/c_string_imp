#include "ArrayList.h"
#include <stdlib.h>
typedef struct{
    void **array; // this is the array
    size_t size; // this holds the number of elements in the array list
    size_t capacity; // capacity of the array

}ArrayList_t;

ArrayList_t *AL_init(void){

    ArrayList_t *list = (ArrayList_t *)malloc(sizeof(ArrayList_t));
    if (list == NULL){
        
        return NULL;
    }
}

int AL_free(ArrayList_t *AL, int (*delete_data)(void *)){
    if (AL == NULL){
        return 1;
    }

    for(int i = 0; i < AL->size; i++){
        // call the delete_data function to delete the elements( what the fuck does this mean I will figure it out later)
        if(delete_data(AL->size) != 0){
             //If delete_data returns non-zero, there was an error deleting the element(take this out to )
             return 1;
        }
    }

    // Free the memory
    free(AL);

    return 0;
}

void AL_print(ArrayList_t *AL, void(* print_data)(void *)){
    if(AL == NULL){
        printf("Error: ArrayList is null\n");
        return;
    }
    for(int i = 0; i < AL->size;i++){
        print_data(AL->array[i]);
    }
}

void *AL_get_at(ArrayList_t *AL, size_t i){
    if(AL == NULL){
        return NULL;
    }

    if(i < 0 || i >= AL->size){
        //If the index is out of bounds, return NULL
        return NULL;
    }
    return AL->array[i];

}

int AL_set_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data(void *)), int (*delete_data)(void *)){
    if(AL == NULL){
        return 1;
    }

    if(i < 0 || i >= AL->size){
        return 1; 
    }
    if(delete_data(AL->array[i]) != 0){
        return 1;
    }
    /* code to copy new element data and update the element at index i */
    AL->array[i] = copy_data(elem);
    return 0;
}
int AL_insert_first(ArrayList_t *AL, void *elem, void *(*copy_data)(void *)){
    //checks resize
    if(AL->size == AL-> capacity){
        // resize the array list
        // fix this for later!
    }

    //shifts elemt to the right
    for(int i = AL-> size - 1; i >= 0; i --){
        AL->array[i+1]=AL->array[i];
    }

    //copy new element
    AL->array[0] = copy_data(elem);

    //update the size if the array
    AL->size++;
    // returing zero to show that it worked
    return 0;
}

int AL_delete_first(ArrayList_t *AL, int(*delete_data)(void *)){
    //checks array is empty
    if(AL->size == 0){
        return 1;
    }

    //Delete the data of the first element using delete_data function
    if(delete_data(AL->array[0])!=0){
        //if delete_data return non-zerp, there was ana error 
        // return 1 to show that is didnt work
        return 1;
    }

    //shift to the left
    for(int i = 0; i < AL-> size -1; i++){
        // remeber this is going to get fixed tomorrow this is just a place holder for now 
        AL->array[i]= AL->array[i+1];

    }
    AL->size--;

    return 0;
}

int AL_append(ArrayList_t *AL, void *elem, void *(*copy_data)(void *)){
    if(AL == NULL){
        return 1;
    }

    if(AL->size == AL->capacity){
        //resize
        //LOOK AT THIS TOO
    }

    AL->array[AL->size] = copy_data(elem);

    //update size
    AL->size++;

    return 0;
}
int AL_delete_last(ArrayList_t *AL, int (*delete_data)(void *)){
    if(AL== NULL || AL->size == 0){
        return 1;
    }

    if(delete_data(AL->array[AL->size-1] != 0)){
        return 1; 
    }
    AL->size--;

    return 0; 
}
int AL_insert_at(ArrayList_t *AL, size_t i, void *elem, void *(*copy_data)(void *)){
    if(AL == NULL){
        return 1;
    }
    //HEY THIS STILL NEEDS TO GET DONE BUT ITS JUST CREATING THE ARRAY AND THEN IT IS JUST REPETITION
    if(AL->size == AL->capacity){

    }

    if(i >= AL->size){
        return AL_insert_last(AL, elem, copy_data);
    }
    for(size_t j = AL->size; j > i; j--){
        AL->array[j] = AL->array[j - 1];

    }
    AL->array[i] = copy_data(elem);

    AL->size++;

    return 0; 
}
int AL_delete_at(ArrayList_t *AL, size_t i, int (*delete_data)(void *)){
    if(AL == NULL){
        return 1;
    }

    if(i>= AL->size){
        return 1;
    }

    //delete the data of the element at the deletion infrx using delete_data function
    if(delete_data(AL->array[i]!=0)){
        return 1;
    }

    for(size_t j = i; j< AL->size - 1; j++){
        AL->array[j] = AL->array[j+1];
    }
    AL->size--;

    return 0;
}





