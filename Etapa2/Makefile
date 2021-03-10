etapa2: scanner.l main.c
	bison -v -d parser.y 
	flex -o lex.yy.c scanner.l
	gcc -c lex.yy.c parser.tab.c
	gcc -o etapa2 lex.yy.o parser.tab.o -ll

clean:
	rm -f *.tab.c *.tab.h *.yy.c *.o *.output etapa2