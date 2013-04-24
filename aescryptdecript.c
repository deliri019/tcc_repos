#include <stdio.h> 
#include <stdlib.h>
#include <openssl/aes.h>   

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
    unsigned char text[]="Virident";
    unsigned char * enc_text = malloc(80*sizeof(char)); 
    unsigned char * dec_text = malloc(80*sizeof(char));

    AES_KEY key_in, key_out;
    
    AES_set_encrypt_key(key, 256, &key_in);
    AES_encrypt(text, enc_text, &key_in);
    
    AES_set_decrypt_key(key, 256, &key_out); 
    AES_decrypt(enc_text, dec_text, &key_out);

    int x;

    printf("Original message: (hex): \t");
    for (x=0;*(text+x)!=0x00; x++){
   	 printf("%X ",*(text+x));
    }
    printf("\n");
    printf("Encrypted message (hex): \t");
    for (x=0;*(enc_text+x)!=0x00; x++){
    	printf("%X "),*(enc_text+x);
    }
    printf("\n");
    printf("Decrypted message (hex): \t");
    for (x=0;*(dec_text+x)!=0x00; x++){
    	printf("%X "),*(dec_text+x);
    }
    printf("\n");
    free(enc_text);
    free(dec_text);
    
    return 0;
}
