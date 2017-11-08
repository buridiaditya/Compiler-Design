bin: a.out clean prompt
a.out: utility 15CS30008.tab.c lex.yy.c
	@g++ -std=c++11 utility.o lex.yy.c  -lfl -o a.out
lex.yy.c: 15CS30008.l 15CS30008.y
	@flex 15CS30008.l
utility: 
	@g++ -std=c++11 -c 15CS30008_translator.cxx -o utility.o
15CS30008.tab.h: 15CS30008.y
	@bison -d 15CS30008.y
15CS30008.tab.c: 15CS30008.y
	@bison -d 15CS30008.y
clean:
	@rm 15CS30008.tab.h 15CS30008.tab.c lex.yy.c utility.o
test: 
	@./a.out < 15CS30008_test1.mm > 15CS30008_quads_1.s
	@./a.out < 15CS30008_test2.mm > 15CS30008_quads_2.s
prompt:
	@echo "Run 'make test' to execute."
