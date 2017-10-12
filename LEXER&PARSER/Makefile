bin: translator clean prompt
translator: utility ass3_15CS30008.tab.c lex.yy.c
	@g++ -std=c++14 utility.o lex.yy.c ass3_15CS30008_parser.c -lfl -o translator
lex.yy.c: ass3_15CS30008.l ass3_15CS30008.y
	@flex ass3_15CS30008.l
utility: 
	@g++ -std=c++14 -c translator.cpp -o utility.o
ass3_15CS30008.tab.h: ass3_15CS30008.y
	@bison -d ass3_15CS30008.y
ass3_15CS30008.tab.c: ass3_15CS30008.y
	@bison -d ass3_15CS30008.y
clean:
	@rm ass3_15CS30008.tab.h ass3_15CS30008.tab.c lex.yy.c utility.o
test:
	@./translator 
prompt:
	@echo "Run 'make test' to execute."