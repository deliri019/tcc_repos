OPENSSLLIB_FLAGS = -lssl -lcrypto

all:
	gcc aescryptdecript.c -o aescryptdecript -g ${OPENSSLLIB_FLAGS}

test:
	gcc test.c -o test -g ${OPENSSLLIB_FLAGS}
