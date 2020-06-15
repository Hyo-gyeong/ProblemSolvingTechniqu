#include <stdio.h>
#include <string.h>

void EncodedSentence(char sentence[], char alphabet[], char encoded[], int s_len)
{
	int i, j = 0;

	printf("encoded sentence : ");
	while(j < s_len){
		if (sentence[j] == ' ')
			printf(" ");
		else{
			for (i = 0; i < 26; i++)
				if (sentence[j] == alphabet[i]){
					printf("%c", encoded[i]);
					break;
				}
		}
		j++;
	}
	printf("\n");
	return;
}
void printArray(char a[])
{
	int i;

	for (i = 0; i < 26; i++)
		printf("%c",a[i]); 
	printf("\n");
	return;
}
void EncodeAlphabet(char alphabet[], char encoded[], int d)
{
	int i, j;

	for (i = d, j = 0; i < 26; i++, j++)
		encoded[j] = alphabet[i];
	for (i = 0, j = j; j < 26; i++, j++)
		encoded[j] = alphabet[i];
	return;
}
void initAlphabet(char alphabet[])
{
	char c;
	int i = 0;

	for (c = 'A'; c <= 'Z'; c++)
		alphabet[i++] = c;
}
int main(void)
{
	int distance;
	char alphabet[26];
	char encoded[26];
	char sentence[100];

	printf("Enter a distance for encoding: ");
	scanf("%d", &distance); //

	initAlphabet(alphabet);
	printf("---------------------------------------------------\n");
	printf("alphabet : ");
	printArray(alphabet);
	EncodeAlphabet(alphabet, encoded, distance);
	printf("encoded  : ");
	printArray(encoded);
	printf("---------------------------------------------------\n\n");

	printf("Enter a sentence to encode : ");
	while (getchar() != '\n');//버퍼 비우기
	fgets(sentence, sizeof(sentence), stdin);
	printf("original sentence : %s", sentence);
	EncodedSentence(sentence, alphabet, encoded, sizeof(sentence));
}