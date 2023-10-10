#include <stdio.h>
#include <string.h>
#define SIZE 200

int main(void) {
    char word[SIZE], reverse_word[SIZE];
    int i, j;

	// Get the user inputs
    printf("Enter the word: ");
    scanf("%s", word);

    int word_size = strlen(word);

    // Reverse the input word and store it in reverse_word
    for(i=0; i<word_size; i++) {
        reverse_word[i] = word[word_size - 1 - i];
    }

    printf("Reversed word: %s\n", reverse_word);

    // Compare the reversed word with the original word
    for(j=0; j<word_size; j++){
    	if (reverse_word[j] != word[j]) {
            printf("%s is not a palindrome\n", word);
            return 0;
        }
	}	
	printf("%s is a palindrome\n", word);
   
    return 0;
}

