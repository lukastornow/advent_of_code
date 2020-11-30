#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int MAX_LAENGE = 1000;

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
    int output_array[MAX_LAENGE];
    int sum;
    int len = read_array_from_file(input_array, MAX_LAENGE, filename);

    for (int i = 0; i < len; i++) {
        int k, amount = 0;
        output_array[i] = input_array[i];

        
        while (output_array[k] > 0) {
            
            output_array[k + 1] = (output_array[k] / 3) - 2;
            k++;
            amount++;
        }
    
        for (int j = 0; j < amount; j++) {
            sum = sum + output_array[j];
        }
    }

    printf("%d \n", sum);

} 