bin: lexer parser clean
lexer: ass3_15CS30008.tab.c ass3_15CS30008.tab.h lex.yy.c  
	gcc lex.yy.c ass3_15CS30008_lexer.c -lfl -o lexer
parser: ass3_15CS30008.tab.c lex.yy.c
	gcc lex.yy.c ass3_15CS30008_parser.c -lfl -o parser
lex.yy.c: ass3_15CS30008.l ass3_15CS30008.y
	flex ass3_15CS30008.l
ass3_15CS30008.tab.h ass3_15CS30008.tab.c: ass3_15CS30008.y
	bison -d ass3_15CS30008.y
clean:
	rm ass3_15CS30008.tab.h 
