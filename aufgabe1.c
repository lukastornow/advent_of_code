#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int MAX_LAENGE = 500;

int read_array_from_file(int array[], size_t size, char *filename) {
    FILE *file_pointer = fopen(filename, "r");
    if (file_pointer == NULL){
        perror(filename);
        exit(1);
    }
    int i = 0;

    while(i < size && fscanf(file_pointer, "%d", &array[i]) != EOF){
        i++;
    }
    fclose(file_pointer);
    return i;
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Aufruf: %s <Dateiname>\n", argv[0]);
        printf("Beispiel: %s aoc1.txt\n", argv[0]);
        exit(1);
    }

    char *filename = argv[1];

    int input_array[MAX_LAENGE];
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);
    int sum = 0;
    
    for (int i = 0; i < len - 2; i++) {
        for (int j = 1; j < len -1; j++) {
            for (int k = 2; k < len; k++) {
                if (input_array[i] + input_array[j] + input_array[k] == 2020) {
                    sum = input_array[i]*input_array[j]*input_array[k];
                    break;
                }
            }
        }
    }
    
    printf("%d \n", sum);
} 