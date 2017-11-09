%{
	int yylex();
	void yyerror(const char*);
	extern string fileName;
	%}

	%union{
		int integerVal;
		char charVal;
		double doubleVal;
		string* strVal;
		decl_t* decl; 
		exp_t* exp;
		type_t* type;
		vector<int>* list;
	}

	
	%token-table
	%nonassoc "then"
	%nonassoc "else"
	// INT_CONSTANT stores an integer type attribute
	%token <integerVal> INT_CONSTANT 
	// DOUBLE_CONSTANT stores a double type attribute
	%token <doubleVal> DOUBLE_CONSTANT 
	// CHAR_CONSTANT stores a character constant
	%token <charVal> CHAR_CONSTANT 
	// STRING_LITERAL stores a string type constant
	%token <strVal> STRING_LITERAL
	// IDENTIFIER stores a string type constant
	%token <strVal> IDENTIFIER 
	// unary_operator stores a string type unary operator "&" "*" "+" "-"
	%type <strVal> unary_operator 
	// Assignment Operator
	%type <strVal> assignment_operator
	// Decl is a decl_t type object for supporting declarations. Class details explained in ass4_15CS30008_translator.h
	%type <decl> init_declarator declarator direct_declarator 
	// exp is a exp_t type object for supporting expressions. Class details explained in ass4_15CS30008_translator.h
	%type <exp> expression_statement expression statement assignment_expression conditional_expression logical_OR_expression logical_AND_expression inclusive_OR_expression exclusive_OR_expression AND_expression equality_expression relational_expression shift_expression additive_expression multiplicative_expression cast_expression unary_expression postfix_expression primary_expression selection_statement iteration_statement initializer block_item_list block_item expression_opt
	// type is a type_t class object to store the type of a variable. Further explanation in ass4_15CS30008_translator.h
	%type <type> pointer type_specifier declaration_specifiers
	// list is vector<int> type object used for storing the instruction number for backpactching purpose.
	%type <list> N
	// To store integer type attribute
	%type <integerVal> M argument_expression_list
	
	%start start

	%%

	start : translation_unit 
	{
		//cout << "Symbol Table" << endl;
		//STCurrent->print();
		//cout << "===================================================" << endl;
		//cout << "Quad Array" << endl;
		//QA->print();
		//exit(0);
	}
	M: 
	{
		// Augmented for getting the next instruction number
		$$ = QA->getSize();
	}
	;
	N:
	{
		// Augmented to generate GOTO instruction when necessary
		$$ = makelist(QA->getSize());
		QuadEntry *qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
	}
	;
	primary_expression : IDENTIFIER 
	{
		SymbolEntry* se = STCurrent->lookup($1); 
		if(se == NULL){
			se = ST->lookup($1);
		}
		$$ = new exp_t(se);
		
	}
	|INT_CONSTANT 
	{	
		$$ = new exp_t();
		init_t i;
		i.intVal = $1;
		$$->setConstant(true,i,INT);
		
	}
	|CHAR_CONSTANT 
	{
		$$ = new exp_t();
		init_t i;
		i.charVal = $1;
		$$->setConstant(true,i,CHAR);
		
	}
	|DOUBLE_CONSTANT
	{
		$$ = new exp_t();
		init_t i;
		i.doubleVal = $1;
		$$->setConstant(true,i,DOUBLE);
		
	}
	|STRING_LITERAL 
	{	
		
	}
	|'('expression')' 
	{
		$$ = $2;	
	}
	;

	postfix_expression : primary_expression  
	{
		$$ = $1; 
		
	}
	| postfix_expression '[' expression ']'  
	{
		$$ = $1;
		SymbolEntry* se = $1->getSymbolEntry();
		SymbolEntry* se1 = $3->getSymbolEntry();
		if($3->isConstant()){
			type_t * ty = new type_t($3->getConstantType());
			se1 = STCurrent->gentemp(ty);
			se1->initialize($3->getConstantVal());
		}
		SymbolEntry* se2;
		type_t* ty = se->getType();
		type_t *ty1 = new type_t(INT);
		ty = ty->getArrayType();
		if(ty == NULL)
			yyerror("Array Element Does not Exist");
		int width_ = getWidth(ty);
		QuadEntry* qe0 = new QuadEntry(OP_MUL,se1->getName(),se1->getName(),to_string(width_));	
		QA->emit(qe0);
		if($1->isArrayAccess()){
			se2 = $1->getArraySum();
			qe0 = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
			QA->emit(qe0);
		}
		se2 = new SymbolEntry(se);
		se2->setType(ty);
		$$->setArrayAccess(true,se1);
		$$->setSymbolEntry(se2);
		
	}
	| postfix_expression '(' argument_expression_list ')' 
	{
		$$ = $1;
		$$->setFunctionCall(true,$3);
		
	}
	| postfix_expression '(' ')' 
	{
		$$ = $1;
		$$->setFunctionCall(true,0);
		
	}
	| postfix_expression '.' IDENTIFIER  {}
	| postfix_expression "->" IDENTIFIER {}
	| postfix_expression "++" 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 ;
		init_t i;
		i.intVal = 1;
		type_t * ty = new type_t(INT);
		se2 = STCurrent->gentemp(ty);
		se2->initialize(i);

		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se1);
			$$->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

	}
	| postfix_expression "--" 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 ;
		init_t i;
		i.intVal = 1;
		type_t * ty = new type_t(INT);
		se2 = STCurrent->gentemp(ty);
		se2->initialize(i);

		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_SUB,se1->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se1);
			$$->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
	}
	| postfix_expression ".'" 
	{
		// TODO
		
	}
	;

	argument_expression_list : assignment_expression  
	{
		$$ = 1;
		SymbolEntry *se = $1->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		
	}
	| argument_expression_list ',' assignment_expression  
	{
		$$ = $1 +1;
		SymbolEntry *se = $3->getSymbolEntry();
		QuadEntry *qe = new QuadEntry(OP_PARAM,se->getName());
		QA->emit(qe);
		
	}
	;

	unary_expression : 	postfix_expression   
	{
		$$ = $1; 
		
	}
	| "++" unary_expression 
	{
		SymbolEntry *se = $2->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if($2->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$2->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($2->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($2->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($2->isConstant()){
			ty1 = new type_t($2->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($2->getConstantVal());
		}
		else if($2->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($2->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_INCR,se1->getName(),se1->getName());
			$$ = new exp_t(se1);
			$$->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| "--"  unary_expression 
	{
		SymbolEntry *se = $2->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2;
		QuadEntry *qe;
		type_t* t1 = se->getType();
		type_t* ty1;
		if($2->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$2->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($2->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($2->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($2->isConstant()){
			ty1 = new type_t($2->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($2->getConstantVal());
		}
		else if($2->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($2->getNoOfParams()));
			QA->emit(qe);
		}

		if(t1->getTypeName() != DOUBLE){
			//se = STCurrent->gentemp(t1);
			qe = new QuadEntry(OP_DECR,se1->getName(),se1->getName());
			$$ = new exp_t(se1);
			$$->setSymbolEntry(se1);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| unary_operator cast_expression 
	{
		$$ = $2;
		SymbolEntry* se = $2->getSymbolEntry();
		SymbolEntry* se1 = se;
		type_t* ty = se->getType();
		QuadEntry *qe;
		if((*$1).compare("+") != 0){
			if($2->isArrayAccess()){
				se1 = STCurrent->gentemp(se->getType());
				qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$2->getArraySum()->getName());
				QA->emit(qe);
				$$->setArrayAccess(false,NULL);
				$$->setSymbolEntry(se1);
			}
			else if($2->isConstant()){
				type_t *ty = new type_t($2->getConstantType());
				se1 = STCurrent->gentemp(ty);
				se1->initialize($2->getConstantVal());
				$$->setConstant(false);
				$$->setSymbolEntry(se1);
			}
			if((*$1).compare("&") == 0){
				if($2->isConstant())
					yyerror("Invalid reference");
				$$->setAddress(true);
			}
			else if((*$1).compare("*") == 0 && ty->getTypeName() == POINTER){
				if($2->isConstant())
					yyerror("Invalid reference");
				$$->setDeReference(true);
			}
			else if((*$1).compare("-") == 0){
				qe = new QuadEntry(OP_NEG,se1->getName(),se1->getName());
				QA->emit(qe);
				$$->setSymbolEntry(se1);				
			}
		}
		
	}
	;

	unary_operator : '&' 
	{
		$$ = new string("&"); 
		
	}
	| '*' 
	{
		$$ = new string("*"); 
		
	}
	| '+' 
	{
		$$ = new string("+"); 
		
	}
	| '-' 
	{
		$$ = new string("-"); 
		
	}
	;

	cast_expression : unary_expression 
	{
		$$ = $1;
		
	}
	;

	multiplicative_expression : cast_expression 
	{ 
		$$ = $1;
		
	}
	| multiplicative_expression '*' cast_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
			
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_MUL,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| multiplicative_expression '/' cast_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DIV,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| multiplicative_expression '%' cast_expression {
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_MOD,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	;

	additive_expression : multiplicative_expression 
	{
		$$ = $1;
		
	}
	| additive_expression '+' multiplicative_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ADD,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| additive_expression '-' multiplicative_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_SUB,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	;

	shift_expression : additive_expression 
	{
		$$ = $1;
		
	}
	| shift_expression "<<" additive_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(ty2->getTypeName() == INT && typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_LSFT,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	| shift_expression ">>" additive_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(ty2->getTypeName() == INT && typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_RSFT,se->getName(),se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");
		
	}
	;

	relational_expression : shift_expression 
	{
		$$ = $1;
		
	}
	| relational_expression '<' shift_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LT_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	| relational_expression '>' shift_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GT_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	| relational_expression "<=" shift_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_LTE_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	| relational_expression ">=" shift_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_GTE_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	;

	equality_expression : relational_expression 
	{
		$$ = $1;
		
	}
	| equality_expression "==" relational_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_EQ_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	| equality_expression "!=" relational_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		

		if(typecheck(ty1,ty2)){
			se = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_IF_NEQ_GOTO,"",se1->getName(),se2->getName());
			$$ = new exp_t(se);
			$$->setSymbolEntry(se);
			$$->setTrueList(makelist(QA->getSize()));
			QA->emit(qe);
		}
		else
			yyerror("Incompactible types.");

		$$->setFalseList(makelist(QA->getSize()));
		qe = new QuadEntry(OP_GOTO,"");
		QA->emit(qe);
		
	}
	;

	AND_expression : equality_expression 
	{
		$$ = $1;
		
	}
	| AND_expression '&' equality_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_AND,se->getName(),se1->getName(),se2->getName());
		$$ = new exp_t(se);
		$$->setSymbolEntry(se);
		QA->emit(qe);
		
		
	}
	;

	exclusive_OR_expression : AND_expression  
	{
		$$ = $1;
		
	}
	| exclusive_OR_expression '^' AND_expression  
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_XOR,se->getName(),se1->getName(),se2->getName());
		$$ = new exp_t(se);
		$$->setSymbolEntry(se);
		QA->emit(qe);
		
		
	}
	;

	inclusive_OR_expression : exclusive_OR_expression 
	{
		$$ = $1;
		
	}
	| inclusive_OR_expression '|' exclusive_OR_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		if($1->isArrayAccess()){
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($1->isDeReference()){
			ty1 = se1->getType();
			ty1 = ty1->getPointedType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
			QA->emit(qe);
		}
		else if($1->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($1->isConstant()){
			ty1 = new type_t($1->getConstantType());
			se1 = STCurrent->gentemp(ty1);
			se1->initialize($1->getConstantVal());
		}
		else if($1->isFunctionCall()){
			se1 = ST->lookup(se->getName());
			SymbolTable *st = se1->getNestedTable();
			se1 = st->lookup("retVal");
			ty1 = se1->getType();
			se1 = STCurrent->gentemp(ty1);
			qe = new QuadEntry(OP_CALL,se1->getName(),se->getName(),to_string($1->getNoOfParams()));
			QA->emit(qe);
		}

		if($3->isArrayAccess()){
			ty2 = se_->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
			QA->emit(qe);
		}
		else if($3->isDeReference()){
			ty2 = se_->getType();
			ty2 = ty2->getPointedType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
			QA->emit(qe);
		}
		else if($3->isAddress()){
			yyerror("Invalid variable type for multiplying.");
		}
		else if($3->isConstant()){
			ty2 = new type_t($3->getConstantType());
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($3->getConstantVal());
		}
		else if($3->isFunctionCall()){
			se2 = ST->lookup(se_->getName());
			SymbolTable *st = se2->getNestedTable();
			se2 = st->lookup("retVal");
			ty2 = se2->getType();
			se2 = STCurrent->gentemp(ty2);
			qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
			QA->emit(qe);
		}

		
		se = STCurrent->gentemp(ty1);
		qe = new QuadEntry(OP_OR,se->getName(),se1->getName(),se2->getName());
		$$ = new exp_t(se);
		$$->setSymbolEntry(se);
		QA->emit(qe);
		
		
	}
	;

	logical_AND_expression : inclusive_OR_expression  
	{
		$$ = $1;
		
	}
	| logical_AND_expression "&&" M inclusive_OR_expression 
	{
		$$ = $1;
		backpatch($1->getTrueList(),$3);
		$$->setFalseList(merge($1->getFalseList(),$4->getFalseList()));
		$$->setTrueList($1->getTrueList());
		
	}
	;

	logical_OR_expression : logical_AND_expression 
	{
		$$ = $1;
		
	}
	| logical_OR_expression "||" M logical_AND_expression 
	{
		$$ = $1;
		backpatch($1->getFalseList(),$3);
		$$->setTrueList(merge($1->getTrueList(),$4->getTrueList()));
		$$->setFalseList($4->getFalseList());
		
	}
	;

	conditional_expression : logical_OR_expression 
	{
		$$ = $1;
		
	}
	| logical_OR_expression '?' M expression ':' M conditional_expression {}

	assignment_expression : conditional_expression 
	{
		$$ = $1;		
	}	
	| unary_expression assignment_operator assignment_expression 
	{
		SymbolEntry *se = $1->getSymbolEntry();
		SymbolEntry *se_ = $3->getSymbolEntry();
		SymbolEntry *se1 = se;
		SymbolEntry *se2 = se_;
		QuadEntry *qe;
		type_t* ty1;
		type_t* ty2;
		if(se != NULL)
			ty1 = se->getType();
		if(se_ != NULL)
			ty2 = se_->getType();
		
		bool b1 = false,b2 = false;
		if($1->isAddress()){
			yyerror("Invalid Assignment.");	
		}
		else if($1->isConstant()){
			yyerror("Invalid Assignment.");
		}
		else if($1->isFunctionCall()){
			yyerror("Invalid Assignment.");
		}
		if($1->isArrayAccess() || $1->isDeReference()){
			b1 = true;
		}
		if($3->isFunctionCall() || $3->isArrayAccess() || $3->isDeReference() || $3->isAddress() || $3->isConstant()){
			b2 = true;
		}
		if(b1 && b2){
			if($3->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($3->getNoOfParams()));
				QA->emit(qe);
			}
			else if($3->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$3->getArraySum()->getName());
				QA->emit(qe);
			}
			else if($3->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if($3->isAddress()){
				ty2 = new type_t(POINTER);
				ty2->setPointedType(se_->getType());
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if($3->isConstant()){
				ty2 = new type_t($3->getConstantType(),false,false);
				se2 = STCurrent->gentemp(ty2);
				se2->initialize($3->getConstantVal());
			}
			if((*$2).compare("=") != 0){
				if($1->isArrayAccess()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
					QA->emit(qe);
				}
				else if($1->isDeReference()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
					QA->emit(qe);
				}
				if($2->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se2->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}			
			}

			if($1->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),$1->getArraySum()->getName(),se2->getName());
				QA->emit(qe);
			}
			else if($1->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se2->getName());
				QA->emit(qe);
			}

		}
		else if(b1 && !b2){
			se2 = se_;
			if((*$2).compare("=") != 0){
				ty1 = se->getType();
				se1 = STCurrent->gentemp(ty1);
				if($1->isArrayAccess()){
					
					qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se->getName(),$1->getArraySum()->getName());
					QA->emit(qe);
				}
				else if($1->isDeReference()){
					ty1 = se->getType();
					se1 = STCurrent->gentemp(ty1);
					qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se->getName());
					QA->emit(qe);
				}
				if($2->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}
				else if($2->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se1->getName(),se1->getName(),se2->getName());
					QA->emit(qe);
				}			
			}
			if($1->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_L,se->getName(),$1->getArraySum()->getName(),se1->getName());
				QA->emit(qe);
			}
			else if($1->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_L,se->getName(),se1->getName());
				QA->emit(qe);
			}
			

		}
		else if(!b1 && b2){
			if($3->isFunctionCall()){
				se2 = se_;
				SymbolTable *st = se2->getNestedTable();
				qe = new QuadEntry(OP_CALL,se1->getName(),se_->getName(),to_string($3->getNoOfParams()));
				QA->emit(qe);
			}
			else if($3->isArrayAccess()){
				qe = new QuadEntry(OP_ARR_ACC_R,se1->getName(),se_->getName(),$3->getArraySum()->getName());
				QA->emit(qe);
			}
			else if($3->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_R,se1->getName(),se_->getName());
				QA->emit(qe);
			}
			else if($3->isAddress()){
				qe = new QuadEntry(OP_REF,se1->getName(),se_->getName());
				QA->emit(qe);
			}
			else if($3->isConstant()){
				se2 = STCurrent->lookup(se1->getName());
				se2->initialize($3->getConstantVal());
			}
			ty1 = se->getType();
			se1 = STCurrent->gentemp(ty1);
			
			if((*$2).compare("=") != 0){
				
				if($2->compare("*=") == 0){
					qe = new QuadEntry(OP_MUL,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare("/=") == 0){
					qe = new QuadEntry(OP_DIV,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare("%=") == 0){
					qe = new QuadEntry(OP_MOD,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare("+=") == 0){
					qe = new QuadEntry(OP_ADD,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare("-=") == 0){
					qe = new QuadEntry(OP_SUB,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare(">>=") == 0){
					qe = new QuadEntry(OP_RSFT,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}
				else if($2->compare("|=") == 0){
					qe = new QuadEntry(OP_OR,se->getName(),se->getName(),se1->getName());
					QA->emit(qe);
				}			
			}
		}
		else{
			if(typecheck(ty1,ty2)){
				if((*$2).compare("=") != 0){
					
					if($2->compare("*=") == 0){
						qe = new QuadEntry(OP_MUL,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare("/=") == 0){
						qe = new QuadEntry(OP_DIV,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare("%=") == 0){
						qe = new QuadEntry(OP_MOD,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare("+=") == 0){
						qe = new QuadEntry(OP_ADD,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare("-=") == 0){
						qe = new QuadEntry(OP_SUB,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare(">>=") == 0){
						qe = new QuadEntry(OP_RSFT,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}
					else if($2->compare("|=") == 0){
						qe = new QuadEntry(OP_OR,se->getName(),se->getName(),se_->getName());
						QA->emit(qe);
					}			
				}
				else{
					qe = new QuadEntry(OP_COPY,se->getName(),se_->getName());
					QA->emit(qe);
				}
			}
			else
				yyerror("Incompactible types.");
		}
		
	}
	;
			
			
assignment_operator : '='
	{
		$$ = new string("=");
	}
	| "*=" 
	{
		$$ = new string("*=");
	} 
	| "/="
	{
		$$ = new string("/=");
	} 
	| "%=" 
	{
		$$ = new string("\%=");
	} 
	| "+=" 
	{
		$$ = new string("+=");
	} 
	| "-=" 
	{
		$$ = new string("-=");
	}
	| "<<=" {}
	| ">>=" 
	{
		$$ = new string(">>=");
	}
	| "&=" {}
	| "^=" {}
	| "|=" 
	{
		$$ = new string("|=");
	}
	;
	expression : assignment_expression 
	{
		$$ = $1;
		type_t *ty2;
		SymbolEntry* se2;
		if($1->isConstant()){
			ty2 = new type_t($1->getConstantType(),false,false);
			se2 = STCurrent->gentemp(ty2);
			se2->initialize($1->getConstantVal());
			$$ = new exp_t(se2);
		}
	}
	| expression ',' assignment_expression 
	{
		$$ = $3;
		
	}
	;

	constant_expression : conditional_expression {} ;

	declaration : declaration_specifiers init_declarator_list ';' {}
	| declaration_specifiers ';' {}
	;

	declaration_specifiers : type_specifier declaration_specifiers 
	{
		$$ = $1; 
		type_global = $1;
		
	}
	| type_specifier 
	{
		$$ = $1; 
		type_global = $1;
		
	}
	;

	init_declarator_list : init_declarator { }
	| init_declarator_list ',' init_declarator { }
	;

	init_declarator : declarator 
	{
		type_t *ty = $1->getType();
		SymbolEntry *se;
		if(ty->getTypeName() == FUNCTION){
			se = STStack.back()->gentemp($1);
			se->setNestedTable(STCurrent);
			STCurrent = STStack.back();
			STStack.pop_back();
		}
		else	
			se = STCurrent->gentemp($1);
		
	}
	| declarator '=' initializer {
		SymbolEntry *se = STCurrent->gentemp($1);
		SymbolEntry *se1 = $3->getSymbolEntry();
		QuadEntry *qe;
		type_t* ty1 = $1->getType();
		type_n ty_N = ty1->getTypeName();
		if(ty_N == POINTER){
			if($3->isAddress()){
				type_t * ty2 = new type_t(POINTER,true,false);
				ty2->setPointedType(se1->getType());
				SymbolEntry *se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_REF,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if($3->isDeReference()){
				type_t * ty2 = se1->getType();
				SymbolEntry *se2 = STCurrent->gentemp(ty2->getPointedType());
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se1->getName());
				QA->emit(qe);
				qe = new QuadEntry(OP_COPY,se->getName(),se2->getName());	
				QA->emit(qe);
			}
			else if($3->isFunctionCall()){
				qe = new QuadEntry(OP_CALL,se->getName(),se1->getName(),to_string($3->getNoOfParams()));
				QA->emit(qe);
			}
			else if($3->isConstant())
				yyerror("Invalid Declaration");
			else{
				qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());	
				QA->emit(qe);
			}
		}
		else if(ty_N == MATRIX){
			// TODO
		}
		else{
			if($3->isAddress())
				yyerror("Cannot Initialize with Address");
			else if($3->isDeReference()){
				qe = new QuadEntry(OP_DE_REF_R,se->getName(),se1->getName());
				QA->emit(qe);
			}
			else if($3->isConstant())
				se->initialize($3->getConstantVal());
			else if($3->isFunctionCall()){
				qe = new QuadEntry(OP_CALL,se->getName(),se1->getName(),to_string($3->getNoOfParams()));
				QA->emit(qe);
			}
			else{
				qe = new QuadEntry(OP_COPY,se->getName(),se1->getName());	
				QA->emit(qe);
			}
		}
		
	}
	;

	type_specifier : "void" 
	{
		$$ = new type_t(VOID,false,false);
		
	}
	| "char" 
	{
		$$ = new type_t(CHAR,false,false);
		
	}
	| "short" 
	{
		
	}
	| "int"  
	{
		$$ = new type_t(INT,false,false);
		
	}
	| "long"  {}
	| "float"  {}
	| "double"  
	{
		$$ = new type_t(DOUBLE,false,false);
		
	}
	| "Matrix"  
	{
		$$ = new type_t(MATRIX,false,true);
		
	}
	| "signed"  {}
	| "unsigned" {}
	| "Bool" {}
	;

	declarator : direct_declarator 
	{
		$$ = $1;
		
	}
	| pointer
	{
		type_global = $1;
	}
	direct_declarator 
	{
		$$ = $3;
		
	}
	;

	direct_declarator : IDENTIFIER 
	{
		$$ = new decl_t(type_global);  
		$$->setName($1); 
		
	}
	| '(' declarator ')' 
	{ 
		type_t* ty = $2->getType();
		typecheck(type_global,ty);
		$$ = $2;
		$$->setType(type_global); 
		
	}
	| direct_declarator '[' assignment_expression ']' 
	{
		$$ = $1;
		int arraySize;
		if($3->isConstant()){
			arraySize = ($3->getConstantVal()).intVal;
		}
		else{
			SymbolEntry *se = $3->getSymbolEntry();
			arraySize = (se->getInitialValue()).intVal;
		}
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType($1->getType(),arraySize);
		$$->setType(ty);
		
	}
	| direct_declarator '[' ']'   
	{
		$$ = $1; 
		type_t* ty = new type_t(MATRIX);
		ty->setArrayType($1->getType(),0);
		$$->setType(ty);
		
	}
	| direct_declarator '('
	{ 
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();	
		STCurrent->setParentTable(STStack.back());
	} 
	parameter_type_list ')' 
	{

		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);

		QuadEntry* qe = new QuadEntry(OP_FUNC_START,$1->getName());
		QA->emit(qe);
		$$ = $1;
		type_t* ty = new type_t(FUNCTION);
		$$->setType(ty);
		$$->setNestedTable(STCurrent); 
	}
	| direct_declarator '(' 
	{
		STStack.push_back(STCurrent);
	}
	identifier_list ')' 
	{
		QuadEntry* qe = new QuadEntry(OP_FUNC_START,$1->getName());
		QA->emit(qe);
		$$ = $1;
		type_t* ty = new type_t(FUNCTION);
		$$->setType(ty);
		STCurrent = new SymbolTable();
		STCurrent->setParentTable(STStack.back());
		$$->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);		
		
	}
	| direct_declarator '(' ')' 
	{
		QuadEntry* qe = new QuadEntry(OP_FUNC_START,$1->getName());
		QA->emit(qe);
		$$ = $1;
		STStack.push_back(STCurrent);
		STCurrent = new SymbolTable();
		STCurrent->setParentTable(STStack.back());
		type_t* ty = new type_t(FUNCTION);
		$$->setType(ty);
		$$->setNestedTable(STCurrent); 
		string* temp_string = new string("retVal");
		SymbolEntry* se = STCurrent->gentemp(type_global,temp_string);
		
	}
	;
	pointer : '*'  
	{
		$$ = new type_t(POINTER,true,false);
		$$->setPointedType(type_global);
		
	}
	| '*' pointer 
	{
		$$ = $2;
		$$->setPointedType($2);
		
	}
	;

	parameter_type_list : parameter_list {};

	parameter_list : parameter_declaration {}
	| parameter_list ',' parameter_declaration {}
	;

	parameter_declaration : declaration_specifiers declarator 
	{
		STCurrent->gentemp($2); 
		
	}
	| declaration_specifiers 
	{
		STCurrent->gentemp($1);
		
	} 
	;

	identifier_list : IDENTIFIER  
	{
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup($1);
		STCurrent->gentemp(se);
		
	}
	| identifier_list ',' IDENTIFIER  
	{
		SymbolTable *st = STStack.back();
		SymbolEntry *se = st->lookup($3);
		STCurrent->gentemp(se);	
		
	}
	;

	initializer : assignment_expression 
	{
		$$ = $1;	
		
	}
	| '{' initializer_row_list '}' {}
	;

	initializer_row_list : initializer_row  {}
	| initializer_row_list ';' initializer_row {}
	;

	initializer_row : initializer  {}
	| designation initializer {}
	| initializer_row ',' initializer {}
	;

	designation : designator_list '='   {} ;

	designator_list : designator  {}
	| designator_list designator {}
	;

	designator : '[' constant_expression ']' {}
	| '.' IDENTIFIER {}
	;

	statement : labeled_statement  
	{
		$$ = new exp_t();
		
	}
	| compound_statement 
	{
		$$ = new exp_t();
		
	}
	| expression_statement 
	{
		$$ = $1;
		
	}
	| selection_statement	
	{
		$$ = $1;
		
	}
	| iteration_statement	
	{
		$$ = $1;
		
	}
	| jump_statement	
	{
	 	$$ = new exp_t();
		
	}
	;

	labeled_statement : IDENTIFIER ':' statement {}
	| "case" constant_expression ':' statement {}
	| "default" ':' statement {}
	;

	compound_statement : '{' '}'  {}
	| '{' block_item_list M'}'	
	{
		backpatch($2->getNextList(),$3);
		
	}
	;

	block_item_list : block_item 
	{
		$$ = $1;
		
	}
	| block_item_list M block_item 
	{
		$$ = new exp_t();
		backpatch($1->getNextList(),$2);
		$$->setNextList(merge($$->getNextList(),$3->getNextList()));
		
	}
	;

	block_item : declaration 
	{
		$$ = new exp_t();
		
	}
	| statement 
	{
		$$ = $1;
		
	}
	;

	expression_statement : ';' {}
	| expression ';' {$$ = $1;}
	;

	selection_statement : "if" '(' expression ')' M statement %prec "then" 
	{
		$$ = new exp_t();
		backpatch($3->getTrueList(),$5);
		$$->setNextList(merge($3->getFalseList(),$6->getNextList()));	
		
	}
	| "if" '(' expression ')' M statement N "else" M statement 
	{
		$$ = new exp_t();
		backpatch($3->getTrueList(),$5);
		backpatch($3->getFalseList(),$9);
		vector<int>* temp = merge($6->getNextList(),$7);
		$$->setNextList(merge(temp,$10->getNextList()));
		
	}
	| "switch" '(' expression ')' M statement 
	{
		$$ = new exp_t();
		backpatch($3->getTrueList(),$5);
		$$->setNextList(merge($3->getFalseList(),$6->getNextList()));
	}
	;

	expression_opt : expression 
	{
		$$ = $1; 
	}
	| 
	{
		$$ = NULL;
		
	}
	;

	iteration_statement : "while" M '(' expression ')' M statement  
	{
		$$ = new exp_t();
		backpatch($7->getNextList(),$2);
		backpatch($4->getTrueList(),$6);
		$$->setNextList($4->getFalseList());
		QuadEntry *qe = new QuadEntry(OP_GOTO,to_string($2));
		QA->emit(qe);
		
	}
	| "do" M statement M "while" '(' expression ')' ';' 
	{
		$$ = new exp_t();
		backpatch($7->getTrueList(),$2);
		backpatch($3->getNextList(),$4);
		$$->setNextList($7->getFalseList());
		
	}
	// 1	 2		3  			4  5		6		 7  8		9		10 11  12   13
 	| "for" '(' expression_opt ';' M expression_opt ';' M expression_opt N ')' M statement 
	{
		$$ = new exp_t();
		$$->setNextList($6->getFalseList());
		backpatch($6->getTrueList(),$12);
		backpatch($13->getNextList(),$8);
		backpatch($10,$5);
	}
	| "for" '(' declaration expression_opt';' expression_opt ')' statement 
	{
		
	}
	;

	jump_statement : "goto" IDENTIFIER ';' {}
	| "continue" ';' {}
	| "break" ';' {}
	| "return" expression_opt ';' 
	{
		QuadEntry *qe;
		if( $2 == NULL ){
			qe = new QuadEntry(OP_RETURN,"");
			QA->emit(qe);
		}
		else{
			SymbolEntry* se_ = $2->getSymbolEntry();
			SymbolEntry* se2 = se_;
			type_t* ty2;
			if($2->isArrayAccess()){
				ty2 = se_->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_ARR_ACC_R,se2->getName(),se_->getName(),$2->getArraySum()->getName());
				QA->emit(qe);
			}
			else if($2->isDeReference()){
				ty2 = se_->getType();
				ty2 = ty2->getPointedType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_DE_REF_R,se2->getName(),se_->getName());
				QA->emit(qe);
			}
			else if($2->isAddress()){
				yyerror("Invalid variable type for multiplying.");
			}
			else if($2->isConstant()){
				ty2 = new type_t($2->getConstantType());
				se2 = STCurrent->gentemp(ty2);
				se2->initialize($2->getConstantVal());
			}
			else if($2->isFunctionCall()){
				se2 = ST->lookup(se_->getName());
				SymbolTable *st = se2->getNestedTable();
				se2 = st->lookup("retVal");
				ty2 = se2->getType();
				se2 = STCurrent->gentemp(ty2);
				qe = new QuadEntry(OP_CALL,se2->getName(),se_->getName(),to_string($2->getNoOfParams()));
				QA->emit(qe);
			}

			qe = new QuadEntry(OP_RETURN,se2->getName());
			QA->emit(qe);
		}
		
	}
	;

	translation_unit : external_declaration 
	{
		
	}
	| translation_unit external_declaration 
	{		
		
	}
	;

	external_declaration : function_definition  {}
	| declaration 
	{
		
	}
	;

	function_definition : declaration_specifiers declarator declaration_list 
	{ 
		SymbolEntry *se = (STStack.back())->gentemp($2);
		se->setNestedTable(STCurrent);
		STCurrent->isDefinition(true);
	} 
	compound_statement 
	{
		QuadEntry* qe = new QuadEntry(OP_FUNC_END,$2->getName());
		QA->emit(qe);
		STCurrent = STStack.back();
		STStack.pop_back();
	}
	| declaration_specifiers declarator 
	{
		SymbolEntry *se = (STStack.back())->gentemp($2);
		se->setNestedTable(STCurrent);
		STCurrent->isDefinition(true);
	}
	compound_statement 
	{
		QuadEntry* qe = new QuadEntry(OP_FUNC_END,$2->getName());
		QA->emit(qe);
		STCurrent = STStack.back();
		STStack.pop_back();
		
	}
	;

	declaration_list : declaration {}
	| declaration_list declaration {}
	;

	%%

	void yyerror(const char* s){
		
		exit(-1);
	}
