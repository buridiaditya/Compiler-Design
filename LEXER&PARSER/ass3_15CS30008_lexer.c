#include <stdio.h>
#include "ass3_15CS30008.tab.h"
int yylex();
void printTokenName(int a);
int main(){
    int c;
    while(c=yylex()){
        if(c==EOF) break;
    	printTokenName(c);
    }
    return 0;
}

void printTokenName(int a){
	if(a >= 285 && a <= 306)
		printf("<KEYWORD> ");
	else if((a >= 263 && a <= 284) || (a >= 37 && a <= 125))
		printf("<PUNCTUATOR> ");
	else if(a == STRING_LITERAL)
		printf("<STRING_LITERAL> ");
	else if(a == CONSTANT)
		printf("<CONSTANT> ");
	else if(a == IDENTIFIER)
		printf("<IDENTIFIER> ");
	return;
}	
