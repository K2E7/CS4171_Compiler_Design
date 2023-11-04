all:
	lex lexer.l
	gcc lex.yy.c -ll -o lexer

run:
	./lexer < source.c

clean:
	rm -f lex.yy.c lexer 