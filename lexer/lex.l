%{
#define KEYWORD 1
#define IDENTIFIER 2
#define CONSTANT 3
#define STRING_LITERAL 4
#define PUNCTUATOR 5
#define COMMENT 0;
#define ERROR -1;
%}

ws [ \t\n]+
digit [0-9]
identifier_nondigit [A-Za-z_]
identifier {identifier_nondigit}({digit}|{identifier_nondigit})*
zero_constant 0
non_zero_digit [1-9]
sign [+-]
keyword unsigned|break|return|void|case|float|short|char|for|signed|while|goto|Bool|continue|if|default|do|int|switch|double|long|else|Matrix
digit_sequence {digit}+
integer_constant {non_zero_digit}{digit}*
fractional_constant ({digit_sequence}?\.{digit_sequence})|({digit_sequence}\.)
exponent_part (e|E){sign}?{digit_sequence}
floating_constant ({fractional_constant}{exponent_part}?)|({digit_sequence}{exponent_part})
escape_sequence \\n|\\'|\\\?|\\\\|\\a|\\b|\\f|\\n|\\r|\\t|\\v
c_char [^'\\\n]
s_char [^"\\\n]
s_char_sequence {s_char}+
c_char_sequence {c_char}+
character_constant '{c_char_sequence}'
constant {integer_constant}|{floating_constant}|{character_constant}|{zero_constant}
string_literal \"{s_char_sequence}?\"
single_line_comments \/\/.*\\n
multi_line_comments \/*(.|\\n)*\*\/
punctuator  \[|\]|\(|\)|\{|\}|\.|-\>|\+\+|--|&|\*|\+|-|~|!|\/|%|\<\<|\>\>|\<|\>|\<=|\>=|==|!=|\^|\||&&|\|\||\?|:|;|=|\*=|\/=|%=|\+=|-=|\<\<=|\>\>=|&=|\^=|\|=|,|#|'

%%
{ws} {}
{keyword} {printf("<KEYWORD> ");return KEYWORD;}
{identifier} {printf("<IDENTIFIER> ");return IDENTIFIER;}
{constant} {printf("<CONSTANT> ");return CONSTANT;}
{string_literal} {printf("<STRING_LITERAL> ");return STRING_LITERAL;}
{single_line_comments} {printf("<COMMENT> ");return COMMENT;}
{multi_line_comments} {printf("<COMMENT> ");return COMMENT;}
{punctuator} {printf("<PUNCTUATOR> ");return PUNCTUATOR;}
.* {printf("<ERROR> in input %s",yytext);return ERROR;}
%%

int main(){
	while(1)
		yylex();
	return 0;		
}
