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

//Another simple example to copy from source to destination  
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void *my_memcpy(void *dst, const void *src, size_t n) {
    if (dst == NULL || src == NULL) {
        fprintf(stderr, "[FATAL] Null pointer passed to my_memcpy()\n");
        exit(EXIT_FAILURE);
    }
    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;
    while (n-- > 0) {
        *d++ = *s++;
    }
    return dst;
}
int main(void) {
    const char src[] = "Rose Sir !";
    char dest[20] = {0};  // static buffer, zero initialized at compile-time
    size_t size = strlen(src) + 1;
    if (size > sizeof(dest)) {
        fprintf(stderr, "[ERROR] Source string is too large for destination buffer!\n");
        return 1;
    }
    my_memcpy(dest, src, size);
    printf("Dst copied as: %s\n", dest);
    return 0;
}
//Another simple example to copy form source to dst with using memset
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *my_memcpy(void *dst, const void *src, size_t n) {
    if (dst == NULL || src == NULL) {
        fprintf(stderr, "[FATAL] Null pointer passed to my_memcpy()\n");
        exit(EXIT_FAILURE);
    }

    const unsigned char *s = (const unsigned char *)src;
    unsigned char *d = (unsigned char *)dst;

    while (n-- > 0) {
        *d++ = *s++;
    }

    return dst;
}

int main(void) {
    const char src[] = "Rose Sir !";
    char dest[20];                         // uninitialized
    memset(dest, 0, sizeof(dest));         // please initialize with 0 to overcome all kinds of garbage value!
    size_t size = strlen(src) + 1;
    if (size > sizeof(dest)) {
        fprintf(stderr, "[ERROR] Source string is too large for destination buffer!\n");
        return 1;
    }
    my_memcpy(dest, src, size);
    printf("Dst copied as: %s\n", dest);
    return 0;
}

//another simple example of a little bit of Bare metal way 
#include <stdio.h>
#include <stdlib.h>
// Extreme raw memory set function: fills 'n' bytes at 'ptr' with value 'val'
void *my_memset(void *ptr, int val, size_t n) {
    if (ptr == NULL) {
        fprintf(stderr, "[FATAL] Null pointer passed to my_memset()\n");
        exit(EXIT_FAILURE);
    }
    unsigned char *p = (unsigned char *)ptr;
    while (n-- > 0) {
        *p++ = (unsigned char)val;
    }
    return ptr;
}
int main(void) {
    char buffer[20];
    my_memset(buffer, 0, sizeof(buffer));
    my_memset(buffer, 0x41, 10);
    buffer[10] = '\0';
    printf("Buffer content: %s\n", buffer); 
    return 0;
}
