#include <openssl.h>

char *crypt(chrar *, char *key);
char *decrypt(chrar *, char *key);

main() {
  crypted = crypt("hooray", "BC45A23");
  send(crypted, 192.168.6.69);
  system("nc 1234");
  printf("decrypted = %s\n", decrypt(crypted, "BC45A23");
}
