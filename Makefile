build:
	gcc -o smli.out smli.c interpreter.c io.c screen.c -I.

docker:
	docker build -t smli .