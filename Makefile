e: hdump.c
	gcc -D_FILE_OFFSET_BITS=64  hdump.c -o hdump
	cp hdump /bin
	chmod 777 hdump
