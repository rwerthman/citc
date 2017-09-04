#include <iostream>


char *compressed_string(char *original_string) {
    int len_original_string = strlen(original_string);
    char *compressed_string = (char *) calloc(0, 1);
    int i, j;
    for (i = 0; i < len_original_string; i++) {
        char character = original_string[i];
        int count_of_character = 0;
        char *new_compressed_string = (char *) calloc(strlen(compressed_string) + 1, 1);
        strncpy(new_compressed_string, compressed_string, strlen(compressed_string));
        strncat(new_compressed_string, &character, 1);
        compressed_string = (char *) realloc(compressed_string, strlen(new_compressed_string));
        strncpy(compressed_string, new_compressed_string, strlen(new_compressed_string));
        free(new_compressed_string);
        for (j = i; j < len_original_string; j++) {
            if (character == original_string[j]) {
                count_of_character += 1;
            } else {
                break;
            }
        }

        if (count_of_character > 1) {
            char count_as_string[sizeof(count_of_character)];
            sprintf(count_as_string, "%d", count_of_character);
            char *new_compressed_string = (char *) calloc(strlen(compressed_string) + 1, 1);
            strncpy(new_compressed_string, compressed_string, strlen(compressed_string));
            strncat(new_compressed_string, count_as_string, 1);
            compressed_string = (char *) realloc(compressed_string, strlen(compressed_string) + strlen(count_as_string));
            strncpy(compressed_string, new_compressed_string, strlen(new_compressed_string));
            free(new_compressed_string);
            i = i + (count_of_character - 1);
        }

    }

    if (strlen(compressed_string) < len_original_string) {
        return compressed_string;
    } else {
        free(compressed_string);
        return original_string;
    }
}

int main() {
    char *original_string = "aab";
    char *new_string = compressed_string(original_string);
    std::cout << new_string << std::endl;
    free(new_string);

    original_string = "aabcccccaaa";
    new_string = compressed_string(original_string);
    std::cout << new_string << std::endl;
    free(new_string);
    return 0;
}
