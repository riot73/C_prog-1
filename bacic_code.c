//using the assert method
#include<stdio.h>
#include<assert.h>
#define NDEBUG
int main(void){
    double number = -10.2 ;
    assert(number > -10.3) ;
    printf("Done it is !~") ;
    return 0 ;
}
--if u use the NDEBUG method , then the compiler will avoid all kind of assert functions and logic 
--using assert for debugging is great but its low the performance ....for production after debugging use NDEBUG //

//Another simple example of assert and sqrt() 
#include<stdio.h>
#include<math.h>
#include<assert.h>
int main(void){
    double number = -1.0021 ;
    assert(number >= 0) ;
    printf("The squire of number is :%.4f\n" , sqrt(number)) ;
}
--check it before compiling because sqrt(negetive) is not valid ...first check that this is positive or not ! 

//malloc() only work for void pointer so first convert into int if need or any data types whatever 
#include<stdio.h>
#include<stdlib.h>
int main(void){
    int *ptr = (int *)malloc(sizeof(int)) ;
    if(ptr == NULL){
        perror("Failed .....") ;
        return -1 ;
    }
    *ptr = 10 ;
    printf("Allocated number is :%d\n" , *ptr) ;
    printf("Addr :%p\n" , ptr) ;
    free(ptr) ;
}

//double pointer 
#include<stdio.h>
int main(void){
    int number = 10 ;
    int *ptr1 = &number ;
    int **ptr2 = &ptr1 ;
    printf("Number is :%d\n" , number) ;
    printf("ptr1 is :%d\n" , *ptr1) ;
    printf("ptr 2 is :%d\n" , **ptr2) ;
    return 0 ;
}
//A simple example of double ptr and with malloc() 
#include<stdio.h>
#include<stdlib.h>
int main(void){
    int *ptr ;
    int **ptr2 ;
    ptr = (int *)malloc(sizeof(int)) ;
    if(ptr == NULL){
        perror("Failed to do it !") ;
        return -1 ;
    }
    *ptr = 666 ;
    ptr2 = &ptr ;
    printf("ptr 1 is :%d\n" , *ptr) ;
    printf("ptr 2 is :%d\n" , **ptr2) ;
}

//Another simple example 
#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n = 10;
    int *array = (int *)malloc(n * sizeof(int));
    if (array == NULL) {
        perror("Failed to allocate !");
        return -1;
    }
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
        printf("array is :%d\n", array[i]);
    }
    long long int product = 1;
    for (int i = 0; i < n; i++) {
        product *= array[i];
    }
    printf("The Product of array is :%lld\n", product);
    free(array);
    return 0;
}
//Another simple example of pointer arithmetic 
#include <stdio.h>
int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int *p = arr;
    for (int i = 0; i < 5; i++) {
        printf("Value: %d\n", *(p + i));
    }
    return 0;
}

