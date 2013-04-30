#include <stdio.h>
#include <stdlib.h>
#include <openssl/aes.h>
#include <readline/readline.h>

static const unsigned char key[] = {
	0x00, 0x91, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
	0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
	0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
	0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
};

int main()
{
	char *text;
	int textlen, x;
	unsigned char *enc_text = malloc(800 * sizeof(char));
	unsigned char *dec_text = malloc(800 * sizeof(char));

	text = readline("Insert the message you wish to encrypt:\t");

	if (!text) {
		printf("Error");
	}

	textlen = strlen(text);
	printf("####### Tamanho do texto: %d #######\n", textlen);

    AES_KEY aeskey;

	AES_set_encrypt_key(key, 256, &aeskey);
	AES_encrypt(text, enc_text, &aeskey);

	AES_set_decrypt_key(key, 256, &aeskey);
	AES_decrypt(enc_text, dec_text, &aeskey);

/*
Começa loop pra cifrar dados;
*/
for (x=0; x<textlen; x++){

}

/*
Termina fluxo de cifra de dados;
*/

	printf("Original Message (string):\t");
	printf("%s ",text);

	printf("\nOriginal Message (hexa):\t");
	for (x=0;*(text+x)!=0x00; x++)
		printf("%2.X ",*(text+x));

	printf("\nEncrypted Message (hexa):\t");
	for (x = 0; *(enc_text+x) != 0x00; x++)
		printf("%2.X ",*(enc_text+x));

	printf("\nDecrypted Message (hexa):\t");
	for (x=0;*(dec_text+x)!=0x00; x++)
		printf("%2.X ",*(dec_text+x));

	printf("\n");

	if (dec_text != NULL)
		free(dec_text);
	if (enc_text != NULL)
		free(enc_text);
	if (text != NULL)
		free(text);

	return 0;
}
