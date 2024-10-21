#include<stdio.h>
#include<stdlib.h>

#define MAX 100

//reusing the code done in class but with cases for hex (since writing 16 for loop is a pain)
void radix_hex(unsigned long long int A[], unsigned int n, unsigned int k){
    unsigned long long int bucket0[MAX], bucket1[MAX], bucket2[MAX], bucket3[MAX], bucket4[MAX], bucket5[MAX], bucket6[MAX], bucket7[MAX], bucket8[MAX], bucket9[MAX], bucketA[MAX], bucketB[MAX], bucketC[MAX], bucketD[MAX], bucketE[MAX], bucketF[MAX];
    unsigned int mask, count0, count1, count2, count3, count4, count5, count6, count7, count8, count9, countA, countB, countC, countD, countE, countF;

    for (int d = 0; d < k ; d+= 4){
        int counter = 0;

        count0 = count1 = count2 = count3 = count4 = count5 = count6 = count7 = count8 = count9 = countA = countB = countC = countD = countE = countF = 0;

    //looping thu individual elements and storing them into buckets 
    for (int i = 0 ; i < n ; i++){
        //extractig the 4bit digit for each pass
                long long mask = 0xF;
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
    void radix_sort_signed(long long int A[], int n, int K){
        long long int positive[MAX], negative[MAX];
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

    radix_hex((unsigned long long *)positive, pos_count, K);
    radix_hex((unsigned long long *)negative, neg_count, K);

        for(int i = neg_count -1; i >= 0; i--){
            A[neg_count - i -1] = ~negative[i]; //negating back to get the original number
        }

        for(int i = 0; i < pos_count; i++){
            A[neg_count + i] = positive[i];
        }

       //printf("\nSorted array (signed): ");
        for (int i = 0 ; i < n ; i++){
            printf("%lld\n", A[i]);
        }
    }

int main(){
    //printf("Enter the count of the elements: ");
    int n;
    scanf("%d",&n);
    // int elem_counter = 0;

    long long int primary_arr[100]; //the q states that elements <= 100

    
    for (int i=0; i<n; i++){
        //printf("Enter the %d-th element: ", i+1); //avoid the 0
    scanf("%lld",&primary_arr[i]);}

    //err handling
    if (n < 1 || n > 100)
        printf("Invalid input\n");

    //print
    // printf("The elements entered are: ");
    // for (int i = 0 ; i < n ; i ++)
    //     printf("%d ", primary_arr[i]);
    // printf("\n");

    radix_sort_signed(primary_arr, n, 64);
}