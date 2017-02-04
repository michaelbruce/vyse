build: *.c
	mkdir -p target
	cc -std=c99 -Wall -ledit vyse.c -o target/vyse
