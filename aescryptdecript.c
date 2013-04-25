#include <stdio.h> 
#include <stdlib.h>
#include <openssl/aes.h>   
#include <string.h>
#include <readline/readline.h>

static const unsigned char key[] = {
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
    0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77,
    0x88, 0x99, 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff,
    0x00, 0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07,
};

int main()
{
    char *text;
    unsigned char * enc_text = malloc(80*sizeof(char)); 
    unsigned char * dec_text = malloc(80*sizeof(char));

    text = readline("Insert the message you wish to encrypt:\t");

    AES_KEY aeskey;
    
    AES_set_encrypt_key(key, 256, &aeskey);
    AES_encrypt(text, enc_text, &aeskey);
    
    AES_set_decrypt_key(key, 256, &aeskey); 
    AES_decrypt(enc_text, dec_text, &aeskey);

    int x;
    printf("Original Message (string):\t");
        printf("%s",text);
    printf("\nOriginal Message: (hex):\t");
    for (x=0;*(text+x)!=0x00; x++)
   	printf("%X ",*(text+x));
    printf("\nEncrypted Message (hex):\t");
    for (x=0;*(enc_text+x)!=0x00; x++)
    	printf("%X ",*(enc_text+x));   
    printf("\nDecrypted Message (hex):\t");
    for (x=0;*(dec_text+x)!=0x00; x++)
    	printf("%X ",*(dec_text+x));
    printf("\n");
    free(enc_text);
    free(dec_text);
    
    return 0;
}
