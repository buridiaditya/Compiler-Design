bin: a.out clean1 prompt
a.out: utility ass5_15CS30008.tab.c lex.yy.c 
	@g++ -std=c++11 lex.yy.c utility.a -lfl -o a.out
lex.yy.c: ass5_15CS30008.l ass5_15CS30008.y
	@flex ass5_15CS30008.l
utility: 
	@g++ -std=c++11 -c ass5_15CS30008_translator.cxx -o u1.o
	@g++ -std=c++11 -c ass5_15CS30008_target_translator.cxx -o u2.o
	@ar cr utility.a u1.o u2.o
ass5_15CS30008.tab.h: ass5_15CS30008.y
	@bison -d ass5_15CS30008.y
ass5_15CS30008.tab.c: ass5_15CS30008.y
	@bison -d ass5_15CS30008.y
clean1:
	@rm ass5_15CS30008.tab.h ass5_15CS30008.tab.c lex.yy.c utility.a u1.o u2.o 
test:
	@mkdir Target\ Assembly\ Codes 
	@./a.out ass5_15CS30008_test1 < ./TestCases/ass5_15CS30008_test1.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads1.asm
	@./a.out ass5_15CS30008_test2 < ./TestCases/ass5_15CS30008_test2.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads2.asm
	@./a.out ass5_15CS30008_test3 < ./TestCases/ass5_15CS30008_test3.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads3.asm
	@./a.out ass5_15CS30008_test4 < ./TestCases/ass5_15CS30008_test4.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads4.asm
	@./a.out ass5_15CS30008_test5 < ./TestCases/ass5_15CS30008_test5.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads5.asm
generate: myl
	@mkdir TestBinaries
	@./a.out ass5_15CS30008_test1 < ./TestCases/ass5_15CS30008_test1.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads1.s
	@./a.out ass5_15CS30008_test2 < ./TestCases/ass5_15CS30008_test2.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads2.s
	@./a.out ass5_15CS30008_test3 < ./TestCases/ass5_15CS30008_test3.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads3.s
	@./a.out ass5_15CS30008_test4 < ./TestCases/ass5_15CS30008_test4.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads4.s
	@./a.out ass5_15CS30008_test5 < ./TestCases/ass5_15CS30008_test5.c > ./Target\ Assembly\ Codes/ass5_15CS30008_quads5.s
	@gcc myl.o ./Target\ Assembly\ Codes/ass5_15CS30008_quads1.s -o  ./TestBinaries/test1
	@gcc myl.o ./Target\ Assembly\ Codes/ass5_15CS30008_quads2.s -o  ./TestBinaries/test2
	@gcc myl.o ./Target\ Assembly\ Codes/ass5_15CS30008_quads3.s -o  ./TestBinaries/test3
	@gcc myl.o ./Target\ Assembly\ Codes/ass5_15CS30008_quads4.s -o  ./TestBinaries/test4
	@gcc myl.o ./Target\ Assembly\ Codes/ass5_15CS30008_quads5.s -o  ./TestBinaries/test5 
	@rm myl.o 
	@rm -r ./Target\ Assembly\ Codes/*.s
myl:
	@gcc -c myl.c -o myl.o
clean: 
	@rm -r Target\ Assembly\ Codes a.out TestBinaries
prompt:
	@echo "Run 'make test' to generate assembly code for test cases."
	@#@echo "Run 'make generate' to generate binaries for test cases."
	@echo "Run 'make clean' to clean all the binaries and assembly codes generated."
