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
	unsigned char *msg_cifrada = malloc(800 * sizeof(char));
	unsigned char *msg_decifrada = malloc(800 * sizeof(char));

	int textlen, x, tmp;
	unsigned char *enc_text = malloc(800 * sizeof(char));
	unsigned char *dec_text = malloc(800 * sizeof(char));

	text = readline("Insert the message you wish to encrypt:\t");

	if (!text) {
		printf("Error");
	}

	textlen = strlen(text);

	printf("\n####### Tamanho do texto: %d #######\n", textlen);

    AES_KEY aeskey;

	AES_set_encrypt_key(key, 256, &aeskey);
//	AES_encrypt(text, enc_text, &aeskey);

	AES_set_decrypt_key(key, 256, &aeskey);
	AES_decrypt(enc_text, dec_text, &aeskey);

/*
 * * Start loop to encrypt/decrypt
 */
	printf("\nOriginal Message (string) FULL:\t");
	printf("%s ",text);

	printf("\nOriginal Message (hexa) FULL:\t");
	for (x=0;*(text+x)!=0x00; x++)
		printf("%2.X ",*(text+x));

	//Loop to encrypt 16 to 16 bytes
	x=0;
	tmp=textlen;
   /*do {
		if (tmp < 16 && tmp > 0) {
			AES_encrypt(text+x, enc_text, &aeskey);
	        memcpy(&msg_cifrada[x], enc_text, tmp);
			tmp--;
			x++;
			printf("\n####Entrei no loop final#####\t");
			printf("\n#MsgCifrada###%2.X####\t",msg_cifrada[x]);
			printf("\n###valor de x = %d###\n", x);
		} else if (tmp >= 16) {
			AES_encrypt(text+x, enc_text, &aeskey);
			memcpy(&msg_cifrada[x], enc_text, 16);
			tmp-=16;
			x++;
			printf("\n####Entrei 1 vez no loop de 16####\t");
			printf("\n#MsgCifrada###%2.X####\t",msg_cifrada[x]);
			printf("\n###valor de x = %d###\n", x);
		}
	} while (tmp > 0);*/
    do {
			AES_encrypt(text+x, enc_text+x, &aeskey);
	        memcpy(&msg_cifrada[x], enc_text+x, tmp);
			tmp--;
			x++;
	} while (tmp > 0);

	printf("\nEncrypted Message (hexa) FULL:\t");

	for (x=0; x < textlen; x++)
	printf("%2.X ",msg_cifrada[x]);

	//Loop to decrypt 16 to 16 bytes
	x=0;
	tmp=textlen;
 	do {
		AES_decrypt(msg_cifrada+x, dec_text+x, &aeskey);
		memcpy(&msg_decifrada[x], dec_text+x, tmp);

		printf("\nMSGCIFRADA = ###%2.X###\t", *msg_cifrada+x);
		printf("\n##DEC_TEXT = ###%2.X\t", *dec_text);

		tmp--;
		x++;
	} while (tmp > 0);

	printf("\nDecrypted Message (hexa) FULL:\t");
	for (x=0; x < textlen; x++)
		printf("%2.X ",msg_decifrada[x]);
/*
 * * Finish loop to encrypt/decrypt
 */

	printf("%s ", "\n\nA PARTIR DAQUI TA WORKANDO\n");

	printf("\nOriginal Message (string):\t");
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
	if (msg_cifrada != NULL)
		free(msg_cifrada);
	if (msg_decifrada != NULL)
		free(msg_decifrada);

	return 0;
}
