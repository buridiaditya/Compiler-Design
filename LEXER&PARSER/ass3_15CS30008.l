%{
#define YYPRINT
#include "ass3_15CS30008.tab.h"
#include "ass3_15CS30008.tab.c"
#define ERROR -1;
#include <string.h>
int getTokenTypeCode(char*);
%}

ws [ \t\n]+
digit [0-9]
identifier_nondigit [A-Za-z_]
identifier {identifier_nondigit}({digit}|{identifier_nondigit})*
zero_constant 0
non_zero_digit [1-9]
sign \+|-
keyword unsigned|break|return|void|case|float|short|char|for|signed|while|goto|Bool|continue|if|default|do|int|switch|double|long|else|Matrix
digit_sequence {digit}+
integer_constant {non_zero_digit}{digit}*
fractional_constant ({digit_sequence}?\.{digit_sequence})|({digit_sequence}\.)
exponent_part (e|E){sign}?{digit_sequence}
floating_constant ({fractional_constant}{exponent_part}?)|({digit_sequence}{exponent_part})
escape_sequence \\'|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v
c_char [^'\\]|{escape_sequence}
s_char [^"\\]|{escape_sequence}
error ('.*('|\\)+.*')|(\".*(\"|\\|\\n)+.*\")
s_char_sequence {s_char}+
c_char_sequence {c_char}+
character_constant '{c_char_sequence}'
constant {integer_constant}|{floating_constant}|{character_constant}|{zero_constant}
string_literal \"{s_char_sequence}?\"
single_line_comments "//".*
multi_line_comments "/*"([^*]|(\*+[^*/]))*\*+\/ 
punctuator  \[|\]|\(|\)|\{|\}|\.|-\>|\+\+|--|&|\*|\+|-|~|!|\/|%|\<\<|\>\>|\<|\>|\<=|\>=|==|!=|\^|\||&&|\|\||\?|:|;|=|\*=|\/=|%=|\+=|-=|\<\<=|\>\>=|&=|\^=|\|=|,|#|\.'

%%
{ws} {}
{keyword} {return getTokenTypeCode(yytext);}
{identifier} {return IDENTIFIER;}
{constant} {return CONSTANT;}
{string_literal} {return STRING_LITERAL;}
{single_line_comments} {}
{multi_line_comments} {}
{punctuator} {return getTokenTypeCode(yytext);}
%%
//{error} {printf("<ERROR> in input %s",yytext);return ERROR;}

int getTokenTypeCode(char* a){
	int i;
	if(strlen(a) == 1) return a[0];
	for(i = 0; i < YYNTOKENS; i++){
		if (yytname[i] != 0
        && yytname[i][0] == '"'
        && ! strncmp (yytname[i] + 1, a,strlen(a))
        && yytname[i][strlen (a) + 1] == '"'
        && yytname[i][strlen (a) + 2] == 0)
     		break;
	}
	return yytoknum[i];
}