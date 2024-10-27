#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/*
Majority of the heavy lifting is done by resuing the code done in class
TODO: Change the negative array to be in the correct order
*/

/*
idea -> passing the float value, then using an unsigned
pointer to get the value in the memory location of the float
then returning the value by dereferencing the pointer
*/
//function to convert float to unsigned int
unsigned int float2int(float f){

    unsigned int *p = (unsigned int *) &f;
    return *p;
}


//function to convert unsigned int to float
//works the same way as the above function but in reverse

float int2float(unsigned int i){
    float *p = (float *) &i;
    return *p;
}


//radix sort 
void radix_sort(unsigned int A[], unsigned int n, unsigned int k){
        unsigned int bucket0[MAX], bucket1[MAX];
        unsigned int mask, count0, count1;

        for (int d = 0 ; d < k ; d++){  //loop thru least significant bit to most significant bit
            mask = 1 << d;  //mask to extract the d-th bit
            count0 = count1 = 0;

            for (int i = 0 ; i < n ; i++){  //loop thru elements in the array
                if ((A[i] & mask) == 0){
                    bucket0[count0++] = A[i];
                } else {
                    bucket1[count1++] = A[i];
                }
                
            }

            //copy the elements back to the original array
            for (int i = 0 ; i < count0 ; i++){
                A[i] = bucket0[i];
            }

            for (int i = 0 ; i < count1 ; i++){
                A[count0 + i] = bucket1[i];
            }
        }

        // printf("\nSorted array: ");
        // for (int i = 0 ; i < n ; i++){
        //     printf("%f ", int2float(A[i]));
        //}
    }


    void radix_sort_signed(int A[], int n, int K){
        int positive[MAX], negative[MAX];
        int neg_count = 0, pos_count = 0;

        //separate positive and negative numbers
        for (int i=0; i<n; i++){
            if (A[i] >= 0){
                positive[pos_count++] = A[i];
            }

            else{
                negative[neg_count++] = ~A[i]; //negating to mantain the correct order as positive
            }
        }

        radix_sort(positive, pos_count, K);
        radix_sort(negative, neg_count, K);

        int counter = 0; //had to have this else the negative numbers would be in the wrong order
        //having the counter ensures that the negative numbers are in the correct order

        //for(int i = neg_count -1; i >= 0; i--){
        for(int i = 0; i < neg_count; i++){
            A[counter++] = ~negative[i]; //negating back to get the original number
        }

        for(int i = 0; i < pos_count; i++){
            A[counter++] = positive[i];
        }

        //printf("\nSorted array (signed): ");
        for (int i = 0 ; i < n ; i++){
            printf("%f\n", int2float(A[i]));
        }
    }


int main(){
    //printf("Enter the count of the elements: ");
    int n;
    scanf("%d",&n);
    // int elem_counter = 0;

    float primary_arr_f[100]; //the q states that elements <= 100

    //err handling
    if (n < 1 || n > 100){
        printf("Invalid input\n");
        return 0;}
    
    for (int i=0; i<n; i++){
    //printf("Enter the %d-th element: ", i+1); //avoid the 0
    scanf("%f",&primary_arr_f[i]);}


    // //print
    // printf("The elements entered are: ");
    // for (int i = 0 ; i < n ; i ++)
    //     printf("%f ", primary_arr_f[i]);
    // printf("\n");

    //convert to unsigned int
    unsigned int primary_arr_int[100];
    for (int i = 0 ; i < n ; i++)
        primary_arr_int[i] = float2int(primary_arr_f[i]);

    // //print
    // printf("The elements in unsigned int are: ");
    // for (int i = 0 ; i < n ; i ++)
    //     printf("%u ", primary_arr_int[i]);
    // printf("\n");



    radix_sort_signed(primary_arr_int, n, 32);
}