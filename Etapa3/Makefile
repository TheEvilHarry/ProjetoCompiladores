etapa3: scanner.l main.c
	bison -v -d parser.y 
	flex -o lex.yy.c scanner.l
	gcc -c lex.yy.c parser.tab.c main.c main.c
	gcc -o etapa3 lex.yy.o parser.tab.o main.o main.o -lfl

clean:
	rm -f *.tab.c *.tab.h *.yy.c *.o *.output etapa3