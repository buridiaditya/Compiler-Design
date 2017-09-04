
%{
int yylex();
void yyerror(const char*);
%}

%token-table
%nonassoc "then"
%nonassoc "else"
%token IDENTIFIER CONSTANT STRING_LITERAL
%start start
%define parse.error verbose

%%
start : translation_unit {printf("Succesfully Parsed!\n");exit(-1);}
primary_expression : IDENTIFIER {printf("primary_expression <<--- IDENTIFIER\n");}
                   	|CONSTANT   {printf("primary_expression <<--- CONSTANT\n");}
			        |STRING_LITERAL {printf("primary_expression <<--- STRING_LITERAL\n");}
			        |'('expression')' {printf("primary_expression <<--- (expression)\n");}
			        ;

postfix_expression : primary_expression  {printf("postfix_expression <<--- primary_expression \n");}
                   	| postfix_expression '[' expression ']'  {printf("postfix_expression <<--- postfix_expression[expression]\n");}
			        | postfix_expression '(' argument_expression_list ')' {printf("postfix_expression <<--- postfix_expression (argument_expression_list) \n");}
			        | postfix_expression '(' ')' {printf("postfix_expression <<--- postfix_expression () \n");}
			        | postfix_expression '.' IDENTIFIER  {printf("postfix_expression <<--- postfix_expression . IDENTIFIER \n");}
			        | postfix_expression "->" IDENTIFIER {printf("postfix_expression <<--- postfix_expression -> IDENTIFIER \n");}
			        | postfix_expression "++" {printf("postfix_expression <<--- postfix_expression ++\n");}
			        | postfix_expression "--" {printf("postfix_expression <<--- postfix_expression --\n");}
			        | postfix_expression ".'" {printf("postfix_expression <<--- postfix_expression .\n");}
			        ;

argument_expression_list : assignment_expression  {printf("argument_expression_list <<--- assignment_expression \n");}
                         | argument_expression_list ',' assignment_expression  {printf("argument_expression_list <<--- argument_expression_list , assignment_expression\n");}
                         ;

unary_expression : 	postfix_expression   {printf("unary_expression <<--- postfix_expression  \n");}
                 	| "++" unary_expression {printf("unary_expression <<--- ++ unary_expression  \n");}
		        	| "--"  unary_expression {printf("unary_expression <<--- -- unary_expression \n");}
		        	| unary_operator cast_expression {printf("unary_expression <<--- unary_operator cast_expression\n");}
		        	;

unary_operator : '&' {printf("unary_operator <<--- &\n");}
               	| '*' {printf("unary_operator <<--- *\n");}
		        | '+' {printf("unary_operator <<--- +\n");}
		        | '-' {printf("unary_operator <<--- -\n");}
		        ;

cast_expression :	 unary_expression {printf("cast_expression <<--- unary_expression\n");}
				;

multiplicative_expression : cast_expression {printf("multiplicative_expression <<--- cast_expression\n");}
							| multiplicative_expression '*' cast_expression {printf("multiplicative_expression <<--- multiplicative_expression * cast_expression \n");}
							| multiplicative_expression '/' cast_expression {printf("multiplicative_expression <<--- multiplicative_expression / cast_expression\n");}
							| multiplicative_expression '%' cast_expression {printf("multiplicative_expression <<--- multiplicative_expression %% cast_expression\n");}
							;

additive_expression : multiplicative_expression {printf("additive_expression <<--- multiplicative_expression\n");}
                    | additive_expression '+' multiplicative_expression {printf("additive_expression <<--- additive_expression + multiplicative_expression\n");}
        			| additive_expression '-' multiplicative_expression {printf("additive_expression <<--- additive_expression - multiplicative_expression\n");}
        			;

shift_expression : additive_expression {printf("shift_expression <<--- additive_expression\n");}
                 | shift_expression "<<" additive_expression {printf("shift_expression <<--- shift_expression << additive_expression\n");}
        		 | shift_expression ">>" additive_expression {printf("shift_expression <<--- shift_expression >> additive_expression\n");}
        		 ;

relational_expression : shift_expression {printf("relational_expression <<--- shift_expression\n");}
                      | relational_expression '<' shift_expression  {printf("relational_expression <<--- relational_expression < shift_expression\n");}
			          | relational_expression '>' shift_expression  {printf("relational_expression <<--- relational_expression > shift_expression\n");}
			          | relational_expression "<=" shift_expression  {printf("relational_expression <<--- relational_expression <= shift_expression\n");}
			          | relational_expression ">=" shift_expression {printf("relational_expression <<--- relational_expression >= shift_expression\n");}
			          ;

equality_expression : relational_expression {printf("equality_expression <<--- relational_expression\n");}
                    | equality_expression "==" relational_expression  {printf("equality_expression <<--- equality_expression == relational_expression\n");}
        			| equality_expression "!=" relational_expression  {printf("equality_expression <<--- equality_expression != relational_expression\n");}
        			;

AND_expression : equality_expression {printf("AND_expression <<--- equality_expression\n");}
               | AND_expression '&' equality_expression {printf("AND_expression <<--- AND_expression & equality_expression\n");}
               ;

exclusive_OR_expression : AND_expression  {printf("exclusive_OR_expression <<--- AND_expression\n");}
                        | exclusive_OR_expression '^' AND_expression  {printf("exclusive_OR_expression <<--- exclusive_OR_expression ^ AND_expression\n");}
                        ;

inclusive_OR_expression : exclusive_OR_expression {printf("inclusive_OR_expression <<--- exclusive_OR_expression\n");}
                        | inclusive_OR_expression '|' exclusive_OR_expression {printf("inclusive_OR_expression <<--- inclusive_OR_expression | exclusive_OR_expression \n");}
                        ;

logical_AND_expression : inclusive_OR_expression  {printf("logical_AND_expression <<--- inclusive_OR_expression\n");}
                       | logical_AND_expression "&&" inclusive_OR_expression {printf("logical_AND_expression <<--- logical_AND_expression && inclusive_OR_expression\n");}
                       ;

logical_OR_expression : logical_AND_expression {printf("logical_OR_expression <<--- logical_AND_expression\n");}
                      | logical_OR_expression "||" logical_AND_expression {printf("logical_OR_expression <<--- logical_OR_expression || logical_AND_expression\n");}
                      ;

conditional_expression : logical_OR_expression {printf("conditional_expression <<--- logical_OR_expression\n");}
                       | logical_OR_expression '?' expression ':' conditional_expression {printf("conditional_expression <<--- logical_OR_expression ? expression : conditional_expression\n");}

assignment_expression : conditional_expression {printf("assignment_expression <<--- conditional_expression\n");}
                      | unary_expression assignment_operator assignment_expression {printf("assignment_expression <<--- unary_expression assignment_operator assignment_expression \n");}
                      ;

assignment_operator : '=' {printf("assignment_operator <<--- =\n");}
					 | "*=" {printf("assignment_operator <<--- *=\n");} 
					 | "/=" {printf("assignment_operator <<--- /=\n");} 
					 | "%=" {printf("assignment_operator <<--- %%=\n");} 
					 | "+=" {printf("assignment_operator <<--- +=\n");} 
					 | "-=" {printf("assignment_operator <<--- -=\n");} 
					 | "<<=" {printf("assignment_operator <<--- <<=\n");} 
					 | ">>=" {printf("assignment_operator <<--- >>=\n");} 
					 | "&=" {printf("assignment_operator <<--- &=\n");}
					 | "^=" {printf("assignment_operator <<--- ^=\n");}
					 | "|=" {printf("assignment_operator <<--- |=\n");}
					 ;

expression : assignment_expression {printf("expression <<--- assignment_expression\n");}
           | expression ',' assignment_expression {printf("expression <<--- expression , assignment_expression\n");}
           ;

constant_expression : conditional_expression {printf("constant_expression <<--- conditional_expression\n");} ;

declaration : declaration_specifiers init_declarator_list ';' {printf("declaration <<--- declaration_specifiers init_declarator_list ;\n");}
              | declaration_specifiers ';' {printf("declaration <<--- declaration_specifiers ;\n");}
              ;

declaration_specifiers : type_specifier declaration_specifiers {printf("declaration_specifiers <<--- type_specifier declaration_specifiers\n");}
                       | type_specifier {printf("declaration_specifiers <<--- type_specifier\n");}
                       ;

init_declarator_list : init_declarator  {printf("init_declarator_list <<--- init_declarator\n");}
                     | init_declarator_list ',' init_declarator {printf("init_declarator_list <<--- init_declarator_list , init_declarator\n");}
                     ;

init_declarator : declarator {printf("init_declarator <<--- declarator\n");}
                | declarator '=' initializer {printf("init_declarator <<--- declarator = initializer\n");}
                ;

type_specifier : "void" {printf("type_specifier : void\n");}
				| "char" {printf("type_specifier : char\n");}
				| "short" {printf("type_specifier : short\n");}
				| "int"  {printf("type_specifier : int\n");}
				| "long"  {printf("type_specifier : long\n");}
				| "float"  {printf("type_specifier : float\n");}
				| "double"  {printf("type_specifier : double\n");}
				| "Matrix"  {printf("type_specifier : Matrix\n");}
				| "signed"  {printf("type_specifier : signed\n");}
				| "unsigned" {printf("type_specifier : unsigned\n");}
				| "Bool" {printf("type_specifier : Bool\n");}
				 ;

declarator : direct_declarator {printf("declarator <<--- direct_declarator\n");}
		   | pointer direct_declarator {printf("declarator <<--- pointer direct_declarator \n");}
		   ;

direct_declarator : IDENTIFIER {printf("direct_declarator <<--- IDENTIFIER\n");}
				  | '(' declarator ')' {printf("direct_declarator <<--- (declarator)\n");}
				  | direct_declarator '[' assignment_expression ']' {printf("direct_declarator <<--- direct_declarator [assignment_expression]\n");}
				  | direct_declarator '[' ']'   {printf("direct_declarator <<--- direct_declarator []\n");}
				  | direct_declarator '(' parameter_type_list ')' {printf("direct_declarator <<--- direct_declarator (parameter_type_list)\n");}
				  | direct_declarator '(' identifier_list ')' {printf("direct_declarator <<--- direct_declarator (identifier_list)\n");}
				  | direct_declarator '(' ')' {printf("direct_declarator <<--- direct_declarator ()\n");}
				  ;
pointer : '*'  {printf("pointer <<--- *\n");}
		 | '*' pointer {printf("pointer <<--- * pointer\n");}
		 ;

parameter_type_list : parameter_list {printf("parameter_type_list <<--- parameter_list\n");};

parameter_list : parameter_declaration {printf("parameter_list <<--- parameter_declaration\n");}
			   | parameter_list ',' parameter_declaration {printf("parameter_list <<--- parameter_list ',' parameter_declaration\n");}
			   ;

parameter_declaration : declaration_specifiers declarator {printf("parameter_declaration <<--- declaration_specifiers declarator\n");}
					  | declaration_specifiers {printf("parameter_declaration <<--- declaration_specifiers\n");}
					  ;

identifier_list : IDENTIFIER  {printf("identifier_list <<--- IDENTIFIER \n");}
				| identifier_list ',' IDENTIFIER  {printf("identifier_list <<--- identifier_list , IDENTIFIER \n");}
				;

initializer : assignment_expression {printf("initializer <<--- assignment_expression\n");}
			| '{' initializer_row_list '}' {printf("initializer <<--- {initializer_row_list}\n");}
			;

initializer_row_list : initializer_row  {printf("initializer_row_list <<--- initializer_row\n");}
					 | initializer_row_list ';' initializer_row {printf("initializer_row_list <<--- initializer_row_list ; initializer_row\n");}
					 ;

initializer_row : initializer  {printf("initializer_row <<--- initializer\n");}
				| designation initializer {printf("initializer_row <<--- designation initializer\n");}
				| initializer_row ',' initializer {printf("initializer_row <<---  initializer_row , initializer\n");}
				;

designation : designator_list '='   {printf("designation <<--- designator_list =\n");} ;

designator_list : designator  {printf("designator_list <<--- designator\n");}
				| designator_list designator {printf("designator_list <<--- designator_list designator\n");}
				;

designator : '[' constant_expression ']' {printf("designator <<--- [constant_expression]\n");}
		   | '.' IDENTIFIER {printf("designator <<--- . IDENTIFIER\n");}
		   ;

statement : labeled_statement  {printf("statement <<--- labeled_statement\n");}
		  | compound_statement {printf("statement <<--- compound_statement\n");}
		  | expression_statement {printf("statement <<--- expression_statement\n");}
		  | selection_statement	{printf("statement <<--- selection_statement\n");}
		  | iteration_statement	{printf("statement <<--- iteration_statement\n");}
		  | jump_statement	{printf("statement <<--- jump_statement\n");}
		  ;

labeled_statement : IDENTIFIER ':' statement {printf("labeled_statement <<--- IDENTIFIER : statement\n");}
				  | "case" constant_expression ':' statement {printf("labeled_statement <<--- case constant_expression : statement\n");}
				  | "default" ':' statement {printf("labeled_statement <<--- default statement\n");}
				  ;

compound_statement : '{' '}'  {printf("compound_statement : {}\n");}
				   | '{' block_item_list '}'	{printf("compound_statement : {block_item_list}\n");}
				   ;

block_item_list : block_item {printf("block_item_list <<--- block_item\n");}
				| block_item_list block_item {printf("block_item_list <<--- block_item_list block_item\n");}
				;

block_item : declaration {printf("block_item <<--- declaration\n");}
		   | statement {printf("block_item <<--- statement\n");}
		   ;

expression_statement : ';' {printf("expression_statement <<--- ;\n");}
					 | expression ';' {printf("expression_statement <<--- expression ;\n");}
					 ;

selection_statement : "if" '(' expression ')' statement     %prec "then" {printf("selection_statement <<--- if (expression) statement\n");}
					| "if" '(' expression ')' statement "else" statement {printf("selection_statement <<--- if (expression) statement else statement\n");}
					| "switch" '(' expression ')' statement {printf("selection_statement <<--- switch (expression) statement\n");}
					;

expression_opt : expression {printf("expression_opt <<--- expression\n");}
			   | {printf("expression_opt <<--- epsilon\n");}
			   ;

iteration_statement : "while" '(' expression ')' statement  {printf("iteration_statement <<--- while (expression) statement \n");}
					| "do" statement "while" '(' expression ')' ';' {printf("iteration_statement <<--- do statement while (expression);\n");}
					| "for" '(' expression_opt ';' expression_opt ';' expression_opt ')' statement {printf("iteration_statement <<--- for (expression_opt ; expression_opt ; expression_opt) statement\n");}
					| "for" '(' declaration expression_opt';' expression_opt ')' statement {printf("iteration_statement <<--- for(declaration expression_opt; expression_opt) statement\n");}
					;

jump_statement : "goto" IDENTIFIER ';' {printf("jump_statement <<--- goto IDENTIFIER ;\n");}
			   | "continue" ';' {printf("jump_statement <<--- continue;\n");}
			   | "break" ';' {printf("jump_statement <<--- break;\n");}
			   | "return" expression_opt ';' {printf("jump_statement <<--- return expression_opt ;\n");}
			   ;

translation_unit : external_declaration {printf("translation_unit <<--- external_declaration\n");}
				 | translation_unit external_declaration {printf("translation_unit <<--- translation_unit external_declaration\n");}
				 ;

external_declaration : function_definition  {printf("external_declaration <<--- function_definition\n");}
					 | declaration {printf("external_declaration <<--- definition\n");}
					 ;

function_definition : declaration_specifiers declarator declaration_list compound_statement {printf("function_definition <<--- declaration_specifiers declarator declaration_list compound_statement\n");}
 					| declaration_specifiers declarator compound_statement {printf("function_definition <<---declaration_specifiers declarator compound_statement\n");}
 					;

declaration_list : declaration {printf("declaration_list <<--- declaration\n");}
				 | declaration_list declaration {printf("declaration_list <<--- declaration_list declaration\n");}
				 ;


%%

void yyerror(const char* s){
    printf("%s\n",s);
    exit(-1);
}
