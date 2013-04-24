#include <openssl/aes.h>
#include <stdio.h>

char *crypt(char *mensagem){
	int x;
	for (x=0; x < 3; x++){
		printf("%c", mensagem[x]);
	}
}

main() {
	char mensagem[3];
	printf("Digite a mensagem que sera criptografada:\n");
	scanf("%s", mensagem);
	crypt(mensagem);
}
