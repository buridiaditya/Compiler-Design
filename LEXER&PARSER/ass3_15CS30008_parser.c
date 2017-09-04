#include <stdio.h>
#include <stdlib.h>
int yyparse();
int main(){
    while(1)
        yyparse();
    return 0;
}

