bin: translator clean prompt
translator: utility ass4_15CS30008.tab.c lex.yy.c
	@g++ -std=c++14 utility.o lex.yy.c  -lfl -o translator
lex.yy.c: ass4_15CS30008.l ass4_15CS30008.y
	@flex ass4_15CS30008.l
utility: 
	@g++ -std=c++14 -c ass4_15CS30008_translator.cxx -o utility.o
ass4_15CS30008.tab.h: ass4_15CS30008.y
	@bison -d ass4_15CS30008.y
ass4_15CS30008.tab.c: ass4_15CS30008.y
	@bison -d ass4_15CS30008.y
clean:
	@rm ass4_15CS30008.tab.h ass4_15CS30008.tab.c lex.yy.c utility.o
test:
	@./translator < ass4_15CS30008_test1.mm > ass4_15CS30008_quads1.out
	@./translator < ass4_15CS30008_test2.mm > ass4_15CS30008_quads2.out
	@./translator < ass4_15CS30008_test3.mm > ass4_15CS30008_quads3.out
prompt:
	@echo "Run 'make test' to execute."
