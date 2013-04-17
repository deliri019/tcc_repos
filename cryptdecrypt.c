//Definir AES Key 256? 

char *crypt(char *, char *key)
char *decrypt(char *, char *key)

main() {
  croypted = crypt("hooray", "BC45A23");
  send(crypted, 127.0.0.1);
  system("nc 1234");
  printf("decrypted = %s\n", decrypt(crypted, "BC45A23");
}
