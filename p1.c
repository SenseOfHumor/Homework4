#include<stdio.h>
#include<stdlib.h>

#define MAX 100

/*
Majority of the heavy lifting is done by reusing the code from problem 2
since I solved that first
but with a few modifications to handle the float values, changed the long long ints to ints
and one key difference is in the function to handle the positives and negative numbers
where instead of reversing the array, i just looped thru, since the negative elements 
are already in the correct order due to IEEE 754 representation which states that
the sign bit is the most significant bit and reversing the bits will put the smallest number
at the end of the array which we dont want.
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

//reusing the code done in class but with cases for hex (since writing 16 for loop is a pain)
void radix_hex(unsigned int A[], unsigned int n, unsigned int k){
    unsigned int bucket0[MAX], bucket1[MAX], bucket2[MAX], bucket3[MAX], bucket4[MAX], bucket5[MAX], bucket6[MAX], bucket7[MAX], bucket8[MAX], bucket9[MAX], bucketA[MAX], bucketB[MAX], bucketC[MAX], bucketD[MAX], bucketE[MAX], bucketF[MAX];
    unsigned int mask, count0, count1, count2, count3, count4, count5, count6, count7, count8, count9, countA, countB, countC, countD, countE, countF;

    for (int d = 0; d < k ; d+= 4){
        int counter = 0;

        count0 = count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = countA = countB = countC = countD = countE = countF = 0;

    //looping thu individual elements and storing them into buckets 
    for (int i = 0 ; i < n ; i++){
        //extractig the 4bit digit for each pass
        int mask = 0xF;
        int digit = (A[i] >> d) & 0xF;


        switch (digit){
            case 0: bucket0[count0++] = A[i]; break; //storing in appt buckets
            case 1: bucket1[count1++] = A[i]; break;
            case 2: bucket2[count2++] = A[i]; break;
            case 3: bucket3[count3++] = A[i]; break;
            case 4: bucket4[count4++] = A[i]; break;
            case 5: bucket5[count5++] = A[i]; break;
            case 6: bucket6[count6++] = A[i]; break;
            case 7: bucket7[count7++] = A[i]; break;
            case 8: bucket8[count8++] = A[i]; break;
            case 9: bucket9[count9++] = A[i]; break;
            case 10: bucketA[countA++] = A[i]; break;
            case 11: bucketB[countB++] = A[i]; break;
            case 12: bucketC[countC++] = A[i]; break;
            case 13: bucketD[countD++] = A[i]; break;
            case 14: bucketE[countE++] = A[i]; break;
            case 15: bucketF[countF++] = A[i]; break;
        }

    }

    //copy to original arr
    //only if C had a F string format like python, i would have constructed 
    //a string of the bucket names and used that to loop thru the buckets
    //this entire code would have been simpler :( :/ :o :(
    for (int i = 0 ; i < count0; i++) A[counter++] = bucket0[i];
    for (int i = 0 ; i < count1; i++) A[counter++] = bucket1[i];
    for (int i = 0 ; i < count2; i++) A[counter++] = bucket2[i];
    for (int i = 0 ; i < count3; i++) A[counter++] = bucket3[i];
    for (int i = 0 ; i < count4; i++) A[counter++] = bucket4[i];
    for (int i = 0 ; i < count5; i++) A[counter++] = bucket5[i];
    for (int i = 0 ; i < count6; i++) A[counter++] = bucket6[i];
    for (int i = 0 ; i < count7; i++) A[counter++] = bucket7[i];
    for (int i = 0 ; i < count8; i++) A[counter++] = bucket8[i];
    for (int i = 0 ; i < count9; i++) A[counter++] = bucket9[i];
    for (int i = 0 ; i < countA; i++) A[counter++] = bucketA[i];
    for (int i = 0 ; i < countB; i++) A[counter++] = bucketB[i];
    for (int i = 0 ; i < countC; i++) A[counter++] = bucketC[i];
    for (int i = 0 ; i < countD; i++) A[counter++] = bucketD[i];
    for (int i = 0 ; i < countE; i++) A[counter++] = bucketE[i];
    for (int i = 0 ; i < countF; i++) A[counter++] = bucketF[i];

    }

    // printf("\nSorted array: ");
    // for (int i = 0 ; i < n ; i++){
    //     printf("%d ", A[i]);
    // }
}

    //copid the code from class to handle the negative and positive separation and sorting\
     then merging in reverse order for the negative numbers
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

    radix_hex(positive, pos_count, K);
    radix_hex(negative, neg_count, K);

            int counter = 0;


        //for(int i = neg_count -1; i >= 0; i--){
        for(int i = 0; i < neg_count; i++){
            A[counter++] = ~negative[i]; //negating back to get the original number
            //A[i] = ~negative[neg_count - i - 1];
        }

        for(int i = 0; i < pos_count; i++){
            A[counter++] = positive[i];
        }

       //printf("\nSorted array (signed): ");
       
        for (int i = 0 ; i < n ; i++){
            printf("%f\n", int2float(A[i]));
        }

        //printing the float values
        
    }





int main(){
    //printf("Enter the count of the elements: ");
    int n;
    scanf("%d",&n);
    // int elem_counter = 0;

    float primary_arr_f[100]; //the q states that elements <= 100

    //err handling
    if (n < 1 || n > 100)
        printf("Invalid input\n");
    
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