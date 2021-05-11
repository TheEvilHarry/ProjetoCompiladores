etapa6: scanner.l main.c
	bison -v -d parser.y 
	flex -o lex.yy.c scanner.l
	gcc -g -c main.c lex.yy.c parser.tab.c tokenutils.c ast.c symbolTable.c ilocfunctions.c parserUtils.c assembly.c
	gcc -o etapa6 main.o lex.yy.o parser.tab.o tokenutils.o ast.o symbolTable.o ilocfunctions.o parserUtils.o assembly.o -ll

clean:
	rm -f *.tab.c *.tab.h *.yy.c *.o *.output etapa6 bison.report tree