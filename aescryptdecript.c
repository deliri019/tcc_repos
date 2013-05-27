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

AES_KEY aeskey;

void print_hex(unsigned char *buffer) {
	for (; *buffer != 0x00; buffer++)
		printf("%2.X ", *buffer);
	printf("\n");
}

char *crypt_buff(unsigned char *buffer) {
	int len;
	int cbuff_len;
	int x;
	unsigned char *cbuff;

	len = strlen(buffer);

	cbuff_len = len / 16;
	cbuff_len = (float)cbuff_len < ((float)len / 16) ? cbuff_len + 1 : cbuff_len;
	cbuff_len *= 16;

	cbuff = NULL;
	cbuff = malloc(cbuff_len);
	printf("len: %d\n", cbuff_len);

	memset(cbuff, 0, cbuff_len);

	for (x = 0; x < cbuff_len; x += 16) {
		AES_encrypt(buffer + x, cbuff + x, &aeskey);
	}
	return cbuff;
}

char *decrypt_buff(unsigned char *buffer) {
	int dbuff_len;
	int x;
	unsigned char *dbuff;

	dbuff_len = strlen(buffer);

	dbuff = malloc(dbuff_len);

	memset(dbuff, 0, dbuff_len);

	for (x = 0; x < dbuff_len; x += 16) {
		AES_decrypt(buffer, dbuff, &aeskey);
	}

	return dbuff;
}

int main()
{
	char *text;
	unsigned char *msg_cifrada;
	unsigned char *msg_decifrada;

	int textlen, x, tmp;

	text = readline("Insert the message you wish to encrypt:\t");

	if (!text) {
		printf("Error");
	}

	textlen = strlen(text);

	printf("\n####### Tamanho do texto: %d #######\n", textlen);


	AES_set_encrypt_key(key, 256, &aeskey);
	AES_set_decrypt_key(key, 256, &aeskey);

	msg_cifrada = crypt_buff(text);
	msg_decifrada = decrypt_buff(msg_cifrada);


	printf("\nOriginal Message (string):\t");
	printf("%s ", text);

	printf("\nOriginal Message (hexa):\t");
	print_hex(text);

	printf("\nEncrypted Message (hexa):\t");
	print_hex(msg_cifrada);

	printf("\nDecrypted Message (hexa):\t");
	print_hex(msg_decifrada);

	printf("\n");

	if (text != NULL)
		free(text);
	if (msg_cifrada != NULL)
		free(msg_cifrada);
	if (msg_decifrada != NULL)
		free(msg_decifrada);

	return 0;
}
