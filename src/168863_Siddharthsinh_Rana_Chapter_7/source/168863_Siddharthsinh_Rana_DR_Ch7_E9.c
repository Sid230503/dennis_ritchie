/* Owner: Siddharthsinh Rana
 * Topic: Dennis Ritchie
 * Created Date: 16/11/2025
 * Chapter: 5
 * Exercise: 7.9
 * Description: Functions like isupper can be implemented to save space or to save time. Explore both possibilities.
 */

#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <time.h>
#include <ctype.h>
#include "chapter7func.h"

int32_t my_isupper(int32_t c){
    return (c >= 'A' && c <= 'Z');
}

int32_t exercise7_9() {
    
    int32_t ch;
    
    int32_t itr;
    printf("Number of interations to test performance: ");
    scanf("%d", &itr);

    int32_t start, end;
    
    /* Testing the custom my_isupper() */
    start = clock();
    for(int32_t i = 0; i < itr; i++){
        for(ch = 0; ch <= 127; ch++){
            my_isupper(ch);
        }
    }
    end = clock();
    printf("Custom isupper time: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);

    /* Testig the inbuilt isupper() */
    start = clock();
    for(int32_t i = 0; i < itr; i++){
        for(ch = 0; ch <= 127; ch++){
            isupper(ch);
        }
    }
    end = clock();
    printf("Library isupper time: %lf seconds\n", ((double)(end - start)) / CLOCKS_PER_SEC);
    return 0;
}

