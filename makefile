all: main.c
	gcc -o batsignal main.c

run: all
	./batsignal
