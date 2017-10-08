%{
	#include "translator.h"
	int yylex();
	void yyerror(const char*);
	%}

	%union{
		int integerVal;
		char charVal;
		double doubleVal;
		string* strVal;
		vector<vector<double> > matVal; 
		decl_t* decl; 
		exp_t* exp;
		type_t* type;
		vector<int>* list;
	}

	%token-table
	%nonassoc "then"
	%nonassoc "else"
	%token <integerVal> INT_CONSTANT 
	%token <doubleVal> DOUBLE_CONSTANT 
	%token <charVal> CHAR_CONSTANT 
	%token <strVal> STRING_LITERAL
	%token <strVal> IDENTIFIER 
	%type <strVal> unary_operator
	%type <decl> init_declarator declarator direct_declarator 
	%type <exp> expression statement assignment_expression conditional_expression logical_OR_expression logical_AND_expression inclusive_OR_expression exclusive_OR_expression AND_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression selection_statement iteration_statement initializer
	%type <type> pointer type_specifier declaration_specifiers
	%type <list> N
	%type <intergerVal> M
 	%start start

	%%

	start : translation_unit {exit(-1);}
	M: 
	{
		$$ = QA->getSize();
	}
	;
	N:
	{
		$$ = makelist(QA->getSize());
		QuadEntry *qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
	}
	;
	primary_expression : IDENTIFIER 
	{
		SymbolEntry* se = STCurrent->lookup($1); 
		$$ = new exp_t(se);
		printf("primary_expression <<--- IDENTIFIER\n");
	}
	|INT_CONSTANT 
	{	
		type_t* typeT = new type_t(INT,false,false);
		SymbolEntry* se = STCurrent->gentemp(typeT);
		$$ = new exp_t(se);
		string* s = new string(to_string($1));
		QuadEntry* qe = new QuadEntry(OP_COPY,se->getName(),&s);
		QA->emit(qe);
		printf("primary_expression <<--- CONSTANT\n");
	}
	|CHAR_CONSTANT 
	{
		type_t* typeT = new type_t(CHAR,false,false);
		SymbolEntry* se = STCurrent->gentemp(typeT);
		$$ = new exp_t(se);
		string* s = new string(to_string($1));
		QuadEntry* qe = new QuadEntry(OP_COPY,se->getName(),&s);
		QA->emit(qe);
		printf("primary_expression <<--- CONSTANT\n");
	}
	|DOUBLE_CONSTANT
	{
		type_t* typeT = new type_t(DOUBLE,false,false);
		SymbolEntry* se = STCurrent->gentemp(typeT);
		$$ = new exp_t(se);
		string* s = new string(to_string($1));
		QuadEntry* qe = new QuadEntry(OP_COPY,se->getName(),&s);
		QA->emit(qe);
		printf("primary_expression <<--- CONSTANT\n");
	}
	|STRING_LITERAL 
	{
		printf("primary_expression <<--- STRING_LITERAL\n");
	}
	|'('expression')' 
	{
		$$ = $2;
		printf("primary_expression <<--- (expression)\n");
	}
	;

	postfix_expression : primary_expression  
	{
		$$ = $1; 
		printf("postfix_expression <<--- primary_expression \n");
	}
	| postfix_expression '[' expression ']'  
	{
		$$ = $1;
		SymbolEntry* se = $1->getSymbolEntry();
		SymbolEntry* se1 = $3->getSymbolEntry();

		type_t* ty = $1->getArrayType();
		SymbolEntry* se3 = new SymbolEntry(INT);
		SymbolEntry* se2 = STCurrent->gentemp(ty);
		int width_ = getWidth(ty);

		QuadEntry* qe0 = new QuadEntry(OP_MUL,se3->getName(),se1->getName(),to_string(width_));	
		
		QuadEntry* qe1 = new QuadEntry(OP_ADD,se2->getName(),se->getName(),se3->getName());	
		
		$$->setSymbolEntry(se2);
		printf("postfix_expression <<--- postfix_expression[expression]\n");
	}
	| postfix_expression '(' argument_expression_list ')' {printf("postfix_expression <<--- postfix_expression (argument_expression_list) \n");}
	| postfix_expression '(' ')' {printf("postfix_expression <<--- postfix_expression () \n");}
	| postfix_expression '.' IDENTIFIER  {printf("postfix_expression <<--- postfix_expression . IDENTIFIER \n");}
	| postfix_expression "->" IDENTIFIER {printf("postfix_expression <<--- postfix_expression -> IDENTIFIER \n");}
	| postfix_expression "++" {printf("postfix_expression <<--- postfix_expression ++\n");}
	| postfix_expression "--" {printf("postfix_expression <<--- postfix_expression --\n");}
	| postfix_expression ".'" 
	{
		$$ = $1;
		printf("postfix_expression <<--- postfix_expression .'\n");
	}
	;

	argument_expression_list : assignment_expression  {printf("argument_expression_list <<--- assignment_expression \n");}
	| argument_expression_list ',' assignment_expression  {printf("argument_expression_list <<--- argument_expression_list , assignment_expression\n");}
	;

	unary_expression : 	postfix_expression   
	{
		$$ = $1; 
		printf("unary_expression <<--- postfix_expression  \n");
	}
	| "++" unary_expression {printf("unary_expression <<--- ++ unary_expression  \n");}
	| "--"  unary_expression {printf("unary_expression <<--- -- unary_expression \n");}
	| unary_operator cast_expression 
	{
		$$ = $2;
		SymbolEntry* se = $2->getSymbolEntry();
		SymbolEntry* se1;
		type_t* ty = se->getType();
		QuadEntry *qe;
		if(strcmp(*$1,"&") == 0){
			type_t* ty1 = new type_t(POINTER,true,false);
			ty1->setPointedType(ty);
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF,se1->getName(),se->getName());
		}
		else if(strcmp(*$1,"*") == 0 && ty->getTypeName() == POINTER){
			
		}
		else if(strcmp(*$1,"-") == 0){
			
		}
		printf("unary_expression <<--- unary_operator cast_expression\n");
	}
	;

	unary_operator : '&' 
	{
		$$ = $1; 
		printf("unary_operator <<--- &\n");
	}
	| '*' 
	{
		$$ = $1; 
		printf("unary_operator <<--- *\n");
	}
	| '+' 
	{
		$$ = $1;
		printf("unary_operator <<--- +\n");
	}
	| '-' 
	{
		$$ = $1;
		printf("unary_operator <<--- -\n");
	}
	;

	cast_expression : unary_expression 
	{
		$$ = $1;
		printf("cast_expression <<--- unary_expression\n");
	}
	;

	multiplicative_expression : cast_expression 
	{ 
		$$ = $1;
		printf("multiplicative_expression <<--- cast_expression\n");
	}
	| multiplicative_expression '*' cast_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_MUL,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("multiplicative_expression <<--- multiplicative_expression * cast_expression \n");
	}
	| multiplicative_expression '/' cast_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_DIV,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("multiplicative_expression <<--- multiplicative_expression / cast_expression\n");
	}
	| multiplicative_expression '%' cast_expression {
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2) && ){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_MOD,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("multiplicative_expression <<--- multiplicative_expression %% cast_expression\n");
	}
	;

	additive_expression : multiplicative_expression 
	{
		$$ = $1;
		printf("additive_expression <<--- multiplicative_expression\n");
	}
	| additive_expression '+' multiplicative_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_ADD,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("additive_expression <<--- additive_expression + multiplicative_expression\n");
	}
	| additive_expression '-' multiplicative_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_SUB,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("additive_expression <<--- additive_expression - multiplicative_expression\n");
	}
	;

	shift_expression : additive_expression 
	{
		$$ = $1;
		printf("shift_expression <<--- additive_expression\n");
	}
	| shift_expression "<<" additive_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_LSFT,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("shift_expression <<--- shift_expression << additive_expression\n");
	}
	| shift_expression ">>" additive_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		if(typecheck(t1,t2)){
			se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_RSFT,se->getName(),s1->getName(),s2->getName());
		}
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("shift_expression <<--- shift_expression >> additive_expression\n");
	}
	;

	relational_expression : shift_expression 
	{
		$$ = $1;
		printf("relational_expression <<--- shift_expression\n");
	}
	| relational_expression '<' shift_expression  
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){	
			qe = new QuadEntry(OP_IF_LT_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression < shift_expression\n");
	}
	| relational_expression '>' shift_expression  
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){
			qe = new QuadEntry(OP_IF_GT_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression > shift_expression\n");
	}
	| relational_expression "<=" shift_expression  
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){
			qe = new QuadEntry(OP_IF_LTE_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression <= shift_expression\n");
	}
	| relational_expression ">=" shift_expression 
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){
			qe = new QuadEntry(OP_IF_GTE_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("relational_expression <<--- relational_expression >= shift_expression\n");
	}
	;

	equality_expression : relational_expression 
	{
		$$ = $1;
		printf("equality_expression <<--- relational_expression\n");
	}
	| equality_expression "==" relational_expression  
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){
			qe = new QuadEntry(OP_IF_EQ_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("equality_expression <<--- equality_expression == relational_expression\n");
	}
	| equality_expression "!=" relational_expression  
	{
		$$ = $1;
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		$$->setTrueList(makelist(QA->getSize()));
		if(typecheck(t1,t2)){
			qe = new QuadEntry(OP_IF_NEQ_GOTO,"",s1->getName(),s2->getName());
			QA->emit(qe);
		}
		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		printf("equality_expression <<--- equality_expression != relational_expression\n");
	}
	;

	AND_expression : equality_expression 
	{
		$$ = $1;
		printf("AND_expression <<--- equality_expression\n");
	}
	| AND_expression '&' equality_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		se = STCurrent->gentemp(t1);
		qe = new QuadEntry(OP_AND,se->getName(),s1->getName(),s2->getName());
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("AND_expression <<--- AND_expression & equality_expression\n");
	}
	;

	exclusive_OR_expression : AND_expression  
	{
		$$ = $1;
		printf("exclusive_OR_expression <<--- AND_expression\n");
	}
	| exclusive_OR_expression '^' AND_expression  
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		se = STCurrent->gentemp(t1);
		qe = new QuadEntry(OP_XOR,se->getName(),s1->getName(),s2->getName());
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("exclusive_OR_expression <<--- exclusive_OR_expression ^ AND_expression\n");
	}
	;

	inclusive_OR_expression : exclusive_OR_expression 
	{
		$$ = $1;
		printf("inclusive_OR_expression <<--- exclusive_OR_expression\n");
	}
	| inclusive_OR_expression '|' exclusive_OR_expression 
	{
		SymbolEntry *s1 = $1->getSymbolEntry();
		SymbolEntry *s2 = $3->getSymbolEntry();
		SymbolEntry *se;
		QuadEntry *qe;
		type_t* t1 = s1->getType();
		type_t* t2 = s2->getType();
		se = STCurrent->gentemp(t1);
		qe = new QuadEntry(OP_OR,se->getName(),s1->getName(),s2->getName());
		$$ = $1;
		$$->setSymbolEntry(se);
		printf("inclusive_OR_expression <<--- inclusive_OR_expression | exclusive_OR_expression \n");
	}
	;

	logical_AND_expression : inclusive_OR_expression  
	{
		$$ = $1;
		printf("logical_AND_expression <<--- inclusive_OR_expression\n");
	}
	| logical_AND_expression "&&" M inclusive_OR_expression 
	{
		$$ = $1;
		backpatch($1->getTrueList(),$3);
		$$->setFalseList(merge($1->getFalseList(),$4->getFalseList()));
		$$->setTrueList($1->getTrueList());
		printf("logical_AND_expression <<--- logical_AND_expression && inclusive_OR_expression\n");
	}
	;

	logical_OR_expression : logical_AND_expression 
	{
		$$ = $1;
		printf("logical_OR_expression <<--- logical_AND_expression\n");
	}
	| logical_OR_expression "||" M logical_AND_expression 
	{
		$$ = $1;
		backpatch($1->getFalseList(),$3);
		$$->setTrueList(merge($1->getTrueList(),$4->getTrueList()));
		$$->setFalseList($4->getFalseList());
		printf("logical_OR_expression <<--- logical_OR_expression || logical_AND_expression\n");
	}
	;

	conditional_expression : logical_OR_expression {printf("conditional_expression <<--- logical_OR_expression\n");}
	| logical_OR_expression '?' M expression ':' M conditional_expression {printf("conditional_expression <<--- logical_OR_expression ? expression : conditional_expression\n");}

	assignment_expression : conditional_expression 
	{
		$$ = $1;	
		printf("assignment_expression <<--- conditional_expression\n");
	}
	| unary_expression assignment_operator assignment_expression 
	{
		SymbolEntry* se0 = $1->getSymbolEntry();
		SymbolEntry* se1 = $3->getSymbolEntry();
		se0->initialize(se1->getInitialValue());
		type_t* ty = se0->getType();
		QuadEntry *qe;
		if(ty->isArray())
		qe = new QuadEntry();
		else if(ty->isPointer())

		else
		qe = new QuadEntry(OP_COPY,se0->getName(),se1->getName());
		QA->emit(qe);
		printf("assignment_expression <<--- unary_expression assignment_operator assignment_expression \n");
	}
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

	declaration : declaration_specifiers 
	{	
		type_global = $1;
	} 
	init_declarator_list ';' {printf("declaration <<--- declaration_specifiers init_declarator_list ;\n");}
	| declaration_specifiers ';' {printf("declaration <<--- declaration_specifiers ;\n");}
	;

	declaration_specifiers : type_specifier declaration_specifiers 
	{
		$$ = $1; 
		printf("declaration_specifiers <<--- type_specifier declaration_specifiers\n");
	}
	| type_specifier 
	{
		$$ = $1; 
		printf("declaration_specifiers <<--- type_specifier\n");
	}
	;

	init_declarator_list : init_declarator { printf("init_declarator_list <<--- init_declarator\n");}
	| init_declarator_list ',' init_declarator { printf("init_declarator_list <<--- init_declarator_list , init_declarator\n");}
	;

	init_declarator : declarator 
	{
		SymbolEntry *se = STCurrent->gentemp($1);
		printf("init_declarator <<--- declarator\n");
	}
	| declarator '=' initializer {
		SymbolEntry *se = STCurrent->gentemp($1);
		SymbolEntry *se1 = $3->getSymbolEntry();
		QuadEntry *qe;
		type_t* ty1 = declarator->getType();
		type_n ty_N = ty1->getTypeName();
		if(ty_N == POINTER)

		else if(ty_N == MATRIX)

		else
			qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());
		QA->emit(qe);
		printf("init_declarator <<--- declarator = initializer\n");
	}
	;

	type_specifier : "void" 
	{
		$$ = new type_t(VOID,false,false);
		printf("type_specifier : void\n");
	}
	| "char" 
	{
		$$ = new type_t(CHAR,false,false);
		printf("type_specifier : char\n");
	}
	| "short" 
	{
		printf("type_specifier : short\n");
	}
	| "int"  
	{
		$$ = new type_t(INT,false,false);
		printf("type_specifier : int\n");
	}
	| "long"  {printf("type_specifier : long\n");}
	| "float"  {printf("type_specifier : float\n");}
	| "double"  
	{
		$$ = new type_t(DOUBLE,false,false);
		printf("type_specifier : double\n");
	}
	| "Matrix"  
	{
		$$ = new type_t(MATRIX,false,true);
		printf("type_specifier : Matrix\n");
	}
	| "signed"  {printf("type_specifier : signed\n");}
	| "unsigned" {printf("type_specifier : unsigned\n");}
	| "Bool" {printf("type_specifier : Bool\n");}
	;

	declarator : direct_declarator 
	{
		$$ = $1;
		printf("declarator <<--- direct_declarator\n");
	}
	| pointer
	{
		type_global = $1;
	}
	direct_declarator 
	{
		$$ = $3;
		printf("declarator <<--- pointer direct_declarator \n");
	}
	;

	direct_declarator : IDENTIFIER 
	{
		$$ = new decl_t(type_global);  
		$$->setName($1); 
		printf("direct_declarator <<--- IDENTIFIER\n");
	}
	| '(' declarator ')' 
	{ 
		type_t* ty = $2->getType();
		typecheck(type_global,ty);
		$$ = $2;
		$$->setType(type_global); 
		printf("direct_declarator <<--- (declarator)\n");
	}
	| direct_declarator '[' assignment_expression ']' 
	{
		$$ = $1;
		SymbolEntry *se = $3->getSymbolEntry();
		int arraySize = se->getInitialValue();
		$$->setArrayType($1->getType,arraySize);
		printf("direct_declarator <<--- direct_declarator [assignment_expression]\n");
	}
	| direct_declarator '[' ']'   
	{
		$$ = $1; 
		$$->setArrayType($1->getType,arraySize);
		printf("direct_declarator <<--- direct_declarator []\n");
	}
	| direct_declarator '('
	{ 
		$$ = $1;
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();
		$$->setType(FUNCTION);
		$$->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
	} 
	parameter_type_list ')' { printf("direct_declarator <<--- direct_declarator (parameter_type_list)\n");}
	| direct_declarator '(' 
	{
		$$ = $1;
		STStack.push_back(STCurrent);
		$$->setType(FUNCTION);
	}
	identifier_list ')' 
	{
		STCurrent = new SymbolTable();
		$$->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);		
		printf("direct_declarator <<--- direct_declarator (identifier_list)\n");
	}
	| direct_declarator '(' 
	{
		$$ = $1;
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();
		$$->setType(FUNCTION);
		$$->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
	} 
	')' {printf("direct_declarator <<--- direct_declarator ()\n");}
	;
	pointer : '*'  
	{
		$$ = new type_t(POINTER,true,false)
		$$->setPointedType(type_global);
		printf("pointer <<--- *\n");
	}
	| '*' pointer 
	{
		$$ = $2;
		$$->setPointedType($2);
		printf("pointer <<--- * pointer\n");
	}
	;

	parameter_type_list : parameter_list {printf("parameter_type_list <<--- parameter_list\n");};

	parameter_list : parameter_declaration {printf("parameter_list <<--- parameter_declaration\n");}
	| parameter_list ',' parameter_declaration {printf("parameter_list <<--- parameter_list ',' parameter_declaration\n");}
	;

	parameter_declaration : declaration_specifiers 
	{
		type_global = $1.getType(); 
	} 
	declarator 
	{
		STCurrent->gentemp($3); 
		printf("parameter_declaration <<--- declaration_specifiers declarator\n");
	}
	| declaration_specifiers 
	{
		STCurrent->gentemp($1);
		printf("parameter_declaration <<--- declaration_specifiers\n");
	} 
	;

	identifier_list : IDENTIFIER  
	{
		SymbolTable *st = STStack->back();
		SymbolEntry *se = st->lookup($1);
		STCurrent->gentemp(se);
		printf("identifier_list <<--- IDENTIFIER \n");
	}
	| identifier_list ',' IDENTIFIER  
	{
		SymbolTable *st = STStack->back();
		SymbolEntry *se = st->lookup($3);
		STCurrent->gentemp(se);	
		printf("identifier_list <<--- identifier_list , IDENTIFIER \n");
	}
	;

	initializer : assignment_expression 
	{
		$$ = $1;	
		printf("initializer <<--- assignment_expression\n");
	}
	| '{' initializer_row_list '}' {printf("initializer <<--- {initializer_row_list}\n");}
	;

	initializer_row_list : initializer_row  {printf("initializer_row_list <<--- initializer_row\n");}
	| initializer_row_list ';' initializer_row {printf("initializer_row_list <<--- initializer_row_list ; initializer_row\n");}
	;

	initializer_row : initializer  {printf("initializer_row <<--- initializer\n");}
	| designation initializer {printf("initializer_row <<--- designation initializer\n");}
	| initializer_row ',' initializer {printf("initializer_row <<---  initializer_row , initializer\n");}
	;l

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

	selection_statement : "if" '(' expression ')' M statement     %prec "then" 
	{
		backpatch($3->getTrueList(),$5);
		$$->setNextList(merge($3->getFalseList(),$6->nextList());	
			printf("selection_statement <<--- if (expression) statement\n");
		}
		| "if" '(' expression ')' M statement N "else" M statement 
		{
			backpatch($3->getTrueList(),$5);
			backpatch($3->getFalseList(),$9);
			vector<int>* temp = merge($6->getNextList(),$7->getNextList());
			$$->setNextList(merge(temp,$10->getNextList()));
			printf("selection_statement <<--- if (expression) statement else statement\n");
		}
		| "switch" '(' expression ')' statement {printf("selection_statement <<--- switch (expression) statement\n");}
		;

		expression_opt : expression 
		{
			$$ = $1; printf("expression_opt <<--- expression\n");
		}
		| {printf("expression_opt <<--- epsilon\n");}
		;

		iteration_statement : "while" M '(' expression ')' M statement  
		{
			backpatch($7->getNextList(),$2);
			backpatch($4->getTrueList(),$6);
			$$->setNextList($4->getFalseList());
			QuadEntry *qe = new QuadEntry(OP_GOTO,to_string($2));
			QA->emit(qe);
			printf("iteration_statement <<--- while (expression) statement \n");
		}
		| "do" M statement M "while" '(' expression ')' ';' 
		{
			backpatch($7->getTrueList(),$2);
			backpatch($3->getNextList(),$4);
			$$->setNextList($7->getFalseList());
			printf("iteration_statement <<--- do statement while (expression);\n");
		}
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
		| declaration 
		{

			printf("external_declaration <<--- definition\n");
		}
		;

		function_definition : declaration_specifiers 
		{	
			type_global = $1.getType();
		} 
		declarator declaration_list compound_statement 
		{
			STCurrent = STStack.back();
			STStack.pop_back();
			printf("function_definition <<--- declaration_specifiers declarator declaration_list compound_statement\n");
		}
		| declaration_specifiers 
		{	
			type_global = $1.getType();
		} 
		declarator compound_statement 
		{
			STCurrent = STStack.back();
			STStack.pop_back();
			printf("function_definition <<---declaration_specifiers declarator compound_statement\n");
		}
		;

		declaration_list : declaration {printf("declaration_list <<--- declaration\n");}
		| declaration_list declaration {printf("declaration_list <<--- declaration_list declaration\n");}
		;

		%%

		void yyerror(const char* s){
			printf("%s\n",s);
			exit(-1);
		}
