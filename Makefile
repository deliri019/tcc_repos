OPENSSLLIB_FLAGS = '-lssl -lcrypto'

all:
	gcc cryptdecrypt.c -o cryptdecrypt -g ${OPENSSLLIB_FLAGS}
