#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

char eng_alphabet[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '\0'};

char * encrypt(char str[],int shift_value);
int find_index(char value,const char str[]);
int getUserInput(char **input);

int main() {
    char *input = malloc(2);
    if(input == NULL){
        printf("Allocating input varable failed");
        return 1;
    }
    int shift_value;

    printf("--||Simple Ceasar Chiper written in C||--");

    printf("\nPlease Input Text:");
    if(!getUserInput(&input)){
        free(input);
        return 1;
    }

    printf("Please input shift value:");
    scanf("%d", &shift_value);

    printf("%s", encrypt(input, shift_value));

    free(input);
    return 0;
}

char *encrypt(char str[], int shift_value){
    for(int i = 0;i <= sizeof(eng_alphabet)-1;i++){
        int index = find_index(str[i],eng_alphabet);
        if(index!= -1){
            str[i] = eng_alphabet[(index+shift_value) % sizeof(eng_alphabet)];
        }
    }
    return str;
}

int find_index(char value,const char str[]){
    for(int i = 0;str[i] != '\0';i++){
        if(value == str[i]){
            return i;
        }
    }
    return -1;
}

int getUserInput(char **input){
    int capacity = 2;
    int length = 0;

    int ch;
    
    while((ch = getchar()) != EOF && ch != '\n'){
        if(length + 1 >= capacity){
            int new_capacity = capacity * 2;
            char *temp = realloc(*input,new_capacity);

            if(temp ==NULL){
                perror("Cant allocate more memory for User Input");
                return 0;
            }

            *input = temp;
            capacity = new_capacity;
        }
        (*input)[length++] = (char)ch;
    }
    *input[length] = '\0';
    return 1;
}