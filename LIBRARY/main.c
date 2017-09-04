#include "./myl.h"
#include <stdio.h>
int main(){
    char * str = "Buridi\n";
    int n;
    float f;
    
    if(readInt(&n) == OK)
        printf("INT OK: %d\n",n);
    if(readFlt(&f) == OK)
        printf("FLOAT OK: %f\n",f);
    printStr(str);
    printInt(100);
    printFlt(1000.00123021);
    return 0;    
}
