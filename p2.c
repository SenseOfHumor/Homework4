#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//reading the inp
//i will use a functional approach for every part of the program (easier to debug)

//reusing the code done in class
void radix_hex(unsigned int A[], unsigned int n, unsigned int k){
    unsigned int bucket0[MAX], bucket1[MAX], bucket2[MAX], bucket3[MAX], bucket4[MAX], bucket5[MAX], bucket6[MAX], bucket7[MAX], bucket8[MAX], bucket9[MAX], bucketA[MAX], bucketB[MAX], bucketC[MAX], bucketD[MAX], bucketE[MAX], bucketF[MAX];
    unsigned int mask, count0, count1, count2, count3, count4, count5, count6, count7, count8, count9, countA, countB, countC, countD, countE, countF;

    for (int d = 0; d < k ; d+= 4){
        int counter = 0;
        mask = 0xF;
        count0 = count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = countA = countB = countC = countD = countE = countF = 0;
    //     //loop thru individual elements
    //     for (int i=0; i < n; i++){
    //         if ((A[i] & mask) == 0){
    //             bucket0[count0++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 1){
    //             bucket1[count1++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 2){
    //             bucket2[count2++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 3){
    //             bucket3[count3++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 4){
    //             bucket4[count4++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 5){
    //             bucket5[count5++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 6){
    //             bucket6[count6++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 7){
    //             bucket7[count7++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 8){
    //             bucket8[count8++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 9){
    //             bucket9[count9++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 10){
    //             bucketA[countA++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 11){
    //             bucketB[countB++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 12){
    //             bucketC[countC++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 13){
    //             bucketD[countD++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 14){
    //             bucketE[countE++] = A[i];
    //         }

    //         else if ((A[i] & mask) == 15){
    //             bucketF[countF++] = A[i];
    //         }
    //     }

    //     //copy the elements back to the original array
    //     for (int i = 0 ; i < count0 ; i++){
    //         A[i] = bucket0[i];
    //     }

    //     for (int i = 0 ; i < count1 ; i++){
    //         A[count0 + i] = bucket1[i];
    //         counter= count0 + i;
    //     }

    //     for (int i = 0 ; i < count2; i++){
    //         A[counter + i] = bucket2[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count3; i++){
    //         A[counter + i] = bucket3[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count4; i++){
    //         A[counter + i] = bucket4[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count5; i++){
    //         A[counter + i] = bucket5[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count6; i++){
    //         A[counter + i] = bucket6[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count7; i++){
    //         A[counter + i] = bucket7[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count8; i++){
    //         A[counter + i] = bucket8[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < count9; i++){
    //         A[counter + i] = bucket9[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countA; i++){
    //         A[counter + i] = bucketA[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countB; i++){
    //         A[counter + i] = bucketB[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countC; i++){
    //         A[counter + i] = bucketC[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countD; i++){
    //         A[counter + i] = bucketD[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countE; i++){
    //         A[counter + i] = bucketE[i];
    //         counter += i;
    //     }

    //     for (int i = 0 ; i < countF; i++){
    //         A[counter + i] = bucketF[i];
    //         counter += i;}

        
    // }

    // printf("\nSorted array: ");
    // for (int i = 0 ; i < n ; i++){
    //     printf("%d ", A[i]);
    // }

    int counter = 0;

    //looping thu individual elements and storing them into buckets 
    for (int i = 0 ; i < n ; i++){
        //extractig the 4bit digit for each pass
        int digit = (A[i] >> d) & mask; //shift first then mask

        switch (digit)
    }

    }
}

int main(){
    printf("Enter the count of the elements: ");
    int n;
    scanf("%d",&n);
    // int elem_counter = 0;

    int primary_arr[100]; //the q states that elements <= 100

    
    for (int i=0; i<n; i++){
        printf("Enter the %d-th element: ", i+1); //avoid the 0
    scanf("%d",&primary_arr[i]);}

    //err handling
    if (n < 1 || n > 100)
        printf("Invalid input\n");

    //print
    printf("The elements entered are: ");
    for (int i = 0 ; i < n ; i ++)
        printf("%d ", primary_arr[i]);
    printf("\n");

    radix_hex(primary_arr, n, 32);
}