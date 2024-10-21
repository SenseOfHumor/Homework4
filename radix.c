    #include <stdio.h>
    #define MAX 100
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

        printf("\nSorted array: ");
        for (int i = 0 ; i < n ; i++){
            printf("%d ", A[i]);
        }
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

        for(int i = neg_count -1; i >= 0; i--){
            A[neg_count - i -1] = ~negative[i]; //negating back to get the original number
        }

        for(int i = 0; i < pos_count; i++){
            A[neg_count + i] = positive[i];
        }

        printf("\nSorted array (signed): ");
        for (int i = 0 ; i < n ; i++){
            printf("%d ", A[i]);
        }
    }

    int main(){
        unsigned int A[] = {6,5,1,2,0,9,2,3,8};
        unsigned int n = sizeof(A)/sizeof(A[0]); //no of elements in the array

        unsigned int k = sizeof(int)*8; //no of bits in an integer 

        //org array
        printf("\nOriginal array: ");
        for (int i = 0 ; i < n ; i++){
            printf("%d ", A[i]);
        }

        //calling the function
        radix_sort(A, n, k);

        //signed array
        int B[] = {6,-5,1,2,0,-9,2,3,8, -7};
        int n1 = sizeof(B)/sizeof(B[0]); //no of elements in the array

        int k1 = sizeof(int)*8; //no of bits in an integer

        //org array
        printf("\nOriginal array (signed): ");
        for (int i = 0 ; i < n1 ; i++){
            printf("%d ", B[i]);
        }

        //calling the function
        radix_sort_signed(B, n1, k1);
    }