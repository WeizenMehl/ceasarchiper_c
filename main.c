#include <stdio.h>
#include <stdlib.h>

char eng_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

const char * encrypt(char str[],int shift_value);
int find_index(char value,char str[]);

int main() {
    char input[4] = {}; // just enough so I can test with input 'test'
    int shift_value;

    printf("--||Simple Ceasar Chiper written in C||--");

    printf("\nPlease Input Text:");
    scanf("%s", &input);

    printf("Please input shift value:");
    scanf("%d", &shift_value);

    printf("%s", encrypt(input, shift_value));

    return 0;
}

const char *encrypt(char str[], int shift_value){
    for(int i = 0;str[i] != '\0';i++){
        str[i] = eng_alphabet[find_index(str[i],eng_alphabet)+shift_value];
    }
    return str;
}

int find_index(char value,char str[]){
    for(int i = 0;str[i] != '\0';i++){
        if(value == str[i]){
            return i;
        }
    }
    return 0; //have to figure something out if no Index can b found 
}