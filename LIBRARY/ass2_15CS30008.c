#include "./myl.h"
int printStr(char * stream){
    int i = 0;
    int ret = 0;
    while(stream[i] != '\0'){
        i++;
    }
    __asm__("movq $1, %%rax \n"
            "movq $1, %%rdi \n"
            "movq %1, %%rsi \n"
            "movq %2, %%rdx \n"
            "syscall"
            :"=g"(ret):"g"(stream),"g"(i)       
            );
    if(ret > 0)
        return i;
    else
        return ERR;    
}

int readInt(int *n){
    int ret = 0,i = 0;
    int no = 0;
    int flag = 0;
    char str[12];
    __asm__("movq $0, %%rax \n"
            "movq $0, %%rdi \n"
            "syscall"
            :"=g"(ret):"S"(str),"d"(12)         
            );
    if(str[0] == '-'){
        flag = 1;
        i++;
    }
    while(str[i] != '\n'){
        no *= 10;
        if(str[i]-'0' > 9 || str[i]-'0' < 0)
            return ERR;
        if(flag == 1)
            no -= str[i]-'0';
        else
            no += str[i]-'0';
        i++;
    }
    *n = no;
    if(ret < 0 && no > 2147483648) return ERR;
    else return OK;
}   

int printInt(int n){
    int ret = 0,i = 0,j;
    char str[12];
    char temp;
    int start = 0;
    if(n < 0){
        str[0] = '-';
        i++;
        n *= -1;
        start = 1;
    }
    while(n > 0){
        str[i] = '0' + n%10;
        n /= 10;
        i++;
    }
    i--;
    for(j = start; j < start+(i-start+1)/2;j++){
        temp = str[j];
        str[j] = str[i-(j-start)];
        str[i-(j-start)] = temp;
    }
    str[i+1] = '\n';
    i++;
    __asm__("movq $1,%%rax \n"
            "movq $1,%%rdi \n"
            "syscall"
            :"=g"(ret):"S"(str),"d"(i+1)
        );
    if(ret < 0) return ERR;
    else return i;
}

int readFlt(float *f){
    int ret = 0,i = 0;
    float no = 0;
    float dNo = 1;
    int flagPoint = 0;
    int flag = 0;
    char str[40];
    __asm__("movq $0, %%rax \n"
            "movq $0, %%rdi \n"
            "syscall"
            :"=g"(ret):"S"(str),"d"(40)         
            );
    if(str[0] == '-'){
        flag = 1;
        i++;
    }
    while(str[i] != '\n'){
        if(str[i] == '.' && flagPoint == 0){
            flagPoint = 1;
            i++;
            continue;    
        }
        else if(str[i] - '0' > 9 || str[i]-'0' < 0)
            return ERR;
        if(flagPoint == 0){
            no *= 10;
            if(flag == 1)
                no -= str[i]-'0';
            else
                no += str[i]-'0';
            i++;
        }
        else{
            dNo *= 10.0;
            if(flag == 0){
                no += (str[i]-'0')/dNo; 
            }
            else
                no -= (str[i]-'0')/dNo;
            i++;
        }
    }
    *f = no;
    if(ret < 0)
        return ERR;
    else
        return OK;
}

int printFlt(float f){
    char str[40];
    int dLen=0,iLen=0,ret = 0;
    float temp = f;
    int j,t;
    int start = 0;
    char te;
    if(f < 0){
        f *= -1;
        start = 1;
        str[0] = '-';
    }
    t  = (int)f;
    while(t > 0){
        str[start + iLen] = t%10+'0';
        t /= 10;
        iLen++;
    }
    iLen--;
    for(j = start; j < start+(iLen)/2;j++){
        te = str[j];
        str[j] = str[iLen-j];
        str[iLen-j] = te;
    }
    str[start+iLen] = '.'; 
    while((temp-(int)temp) != 0){
        temp *= 10;
        str[start+iLen+1+dLen] =((int) temp)%10+'0';
        dLen++;
    }
    str[start+iLen+dLen+1] = '\n';
    iLen = start+iLen+dLen+1;
    __asm__("movq $1,%%rax \n"
            "movq $1,%%rdi \n"
            "syscall"
            :"=g"(ret):"S"(str),"d"(iLen+1)   
            );
    if(ret < 0)
        return ERR;
    else 
        return iLen;
}
