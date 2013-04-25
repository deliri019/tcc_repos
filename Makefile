OPENSSLLIB_FLAGS = -lssl -lcrypto
LDFLAGS = ${OPENSSLLIB_FLAGS} -lreadline

all:
	gcc aescryptdecript.c -o aescryptdecript -g ${LDFLAGS}

test:
	gcc test.c -o test -g ${LDFLAGS}
