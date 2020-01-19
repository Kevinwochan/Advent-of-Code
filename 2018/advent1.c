#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int main (){
    FILE* fp = fopen("input.txt", "r");
    // Read input text into an array
    char input[BUFSIZ];
    int size = 0;
    char num; int sum = 0;
    while ( '\n' != (num = fgetc(fp)) ){
        input[size++] = num - '0';
    }

    // Compute Output
    for (int i = 0; i<size; i++){
        int halfwayAround = ( 2*(i+1) > size ? i - size/2 : i + size/2);
        if ( input[halfwayAround] == input[i] ){
            printf("match at %d: %d  %d\n",i,input[halfwayAround],input[i]);
            sum += input[i];
        }
    }
    // prev now contains the last character before EOF
    printf("the sum is %d\n",sum);
    fclose(fp);
}
