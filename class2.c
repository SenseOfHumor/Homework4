#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void func(){
    int *nums;
    nums = (int*)malloc(50);

    //always free
    free(nums);
}

int main(){

    // malloc
    // int *ptr = (int*)malloc(sizeof(int));

    // *ptr = 1;
    // *(ptr+1) = 2;
    // *(ptr+2) = 3;

    // for (int i = 0; i < 3; i++){
    //     printf("%d\n", *(ptr+i));
    // }

    //calloc
    int *ptr = (int*)calloc(3, sizeof(int));
    *ptr = 1;
    *(ptr+1) = 2;
    *(ptr+2) = 3;

    for (int i = 0; i < 3; i++){
        printf("%d\n", *(ptr+i));
    }

    //realloc
    int *qptr = (int *)realloc(ptr, 10*sizeof(int));

    for (int i = 0; i < 5; i++){
        printf("%d\n", *(qptr+i));
    }

    //strings are stored in memory as an array of characters with a null terminator
    char str[] = "abcd";
    printf("%lu\n", sizeof(str)); 
    printf("%lu\n", strlen(str));

    //strtok
    char str2[] = "sd2269@@njit.edu:fall24/cs288/home/dale";
    char delimiter[] = "@.:/";

    //first call
    char *token;
    token = strtok(str2, delimiter);
    //printf("%s\n", token);

    //subsequent calls
    while (token != NULL){
        printf("%s\n", token);
        token = strtok(NULL, delimiter);
        //we use NULL to continue from the last token
        //if we use str2, it will start from the beginning
    }

    //pointer to pointer

    int var = 10; 
    int *ptr0 = &var; 
    int **pptr0 = &ptr0;

    printf("%d\n", *pptr0); //single dereference = address of var
    printf("%d\n", **pptr0); //double dereference = value of var

    int *arr0[5];
    for (int i = 0; i<5; i++){
        arr0[i] = (int*)malloc(sizeof(int));
        *arr0[i] = i;
    }

    for (int i = 0; i<5; i++){
        printf("%p\n", *arr0[i]);
    }

    int **arr2 = (int**)malloc(sizeof(int*));
    for (int i = 0; i<5; i++){
        arr2[i] = (int*)malloc(sizeof(int));
        *arr2[i] = i;
    }

    for (int i = 0; i<5; i++){
        printf("%p\n", *arr2[i]);
    }


}