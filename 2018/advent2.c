#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main (){
    FILE* fp = fopen("input.txt","r");
    if (fp == NULL){
        printf("no file found\n");
        return -1;
    }
    char* line = malloc(BUFSIZ);
    size_t lineSize = BUFSIZ;
    int checksum = 0;
    // break up into lines
    while ( getline(&line, &lineSize, fp) > 0 ){
        printf("reading string %s",line);
        int lineNum; int numbers[16]; int i = 0;
            // break the line into numbers
            char* numString = strtok(line, "\t");
            while ( numString != NULL){
                int num = atoi(numString);
                // check for divisiblity
                for ( int j = 0; j<i; j++){
                    if ( numbers[j]%num == 0 ){
                        lineNum = numbers[j]/num; break;
                    }else if ( num%numbers[j] == 0 ){
                        lineNum = num/numbers[j]; break;
                    }
                }
                // add to the array of possible matches
                numbers[i++] = num;
                numString = strtok(NULL, "\t");
            }
        checksum += lineNum;
    }
    printf("checksum is %d\n",checksum);
    // Read the line
    // calc the difference
    // print the sum
    fclose(fp);
}
