#define SIZE_OF_INT 4
#define SIZE_OF_CHAR 1
#define SIZE_OF_DOUBLE 8
#define SIZE_OF_POINTER 4
#define SIZE_OF_VOID 0

vector<int>* makelist(int instr);
vector<int>* merge(vector<int>* list1, vector<int>* list2);
vector<int>* backpatch(vector<int>* list,int value);
bool typecheck(type_t* type1, type_t* type2);
int getWidth(type_n type);
int getWidth(type_t* type);

SymbolTable *ST = new SymbolTable();
vector<SymbolTable*> STStack;
SymbolTable *STCurrent = ST;
QuadArary *QA = new QuadArray();

typedef enum{
	INT = 0,
	CHAR,
	VOID,
	DOUBLE,
	MATRIX,
	POINTER,
	FUNCTION
}type_n;

typedef enum {
	OP_ADD,
	OP_SUB,
	OP_MUL,
	OP_DIV,
	OP_MOD,
	OP_LT,
	OP_GT,
	OP_LTE,
	OP_GTE,
	OP_EQ,
	OP_NEQ,
	OP_AND,
	OP_XOR,
	OP_OR,
	OP_COPY,
	OP_IF_LT_GOTO,
	OP_IF_GT_GOTO,
	OP_IF_LTE_GOTO,
	OP_IF_GTE_GOTO,
	OP_IF_EQ_GOTO,
	OP_IF_NEQ_GOTO,
	OP_IF_GOTO,
	OP_IFF_GOTO,
	OP_GOTO
}OPCode;

union init_t{
	int intVal;
	string* strVal;
	char charVal;
	vector<vector<double> > matVal;
	double doubleVal;
}

class type_t{
public:
	type_t();
	type_t(type_n type_,bool isPointer_,bool isArray_);
	void setType(type_n type);
	void setPointedType(type_t* type_);
	void setArrayType(type_t* type_,int No);
	type_t* getPointedType();
	type_t* getArrayType();
	int getNoOfElements();
	bool isPointer();
	bool isArray();
	type_n getTypeName();
private:
	type_n type_name;	
	type_t* pointedType;
	type_t* arrayType;
	bool isPointer;
	bool isArray;
	int noOfElements;
}

type_t *type_global = new type_t();

class decl_t{
public:
	decl_t(type_n type_);
	decl_t(type_t * type_);
	void setType(type_n ty);
	void setType(type_t* ty);
	void setName(string* a);
	void setNestedTable(SymbolTable* table);
	void setInitVal(init_t initVal);
	bool isInitialized();
	string* getName();
	type_t* getType();
	SymbolTable* getNestedTable();
	init_t getInitValue();
private:
	type_t *type;
	string* name;
	bool isInitialized;
	init_t initVal;
	SymbolTable* nestedTable;
}

class expt_t{
public:
	expt_t();
	expt_t(SymbolEntry* SE_);
	SymbolEntry* getSymbolEntry();
	vector<int>* getTrueList();
	vector<int>* getFalseList();
	SymbolEntry* setSymbolEntry();
	void setTrueList(vector<int>* truelist);
	void setFalseList(vector<int>* falselist);
private:
	SymbolEntry* SE;
	vector<int>* trueList;
	vector<int>* falseList;
}

class SymbolEntry{
public:
	SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table);
	SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table,init_t init);
	void setName(string* name);
	void setType(type_t* type);
	void setSize(int size);
	void setNestedTable(SymbolTable* st);
	void initialize(init_t init);
	string* getName();
	type_t* getType();
	int getOffset();
	int getSize();
	bool checkInitialize();
	init_t getInitialValue();
	SymbolTable* getNestedTable();
	void print();
private:
	string* name;
	type_t* type;
	init_t initialValue;
	int size;
	int offset;
	bool initialised;
	SymbolTable* nestedTable;
}

class SymbolTable{
public:
	SymbolTable();	
	SymbolEntry* lookup(string* name);
	SymbolEntry* gentemp(type_t* type);
	SymbolEntry* gentemp(type_t* type,string* name_);
	SymbolEntry* gentemp(decl_t* decl);
	SymbolEntry* gentemp(SymbolEntry* se);
	int getOffset();
	void setOffset(int offset_);
	void update(string* name,init_t initValue);
	void print();
private:
	int offset;
	int tempNo;
	vector<SymbolEntry*> entries;
}

class QuadEntry{
public:
	QuadEntry(OPCode op,string result,string argv1, string argv2);
	QuadEntry(OPCode op,string result,string argv1);
	QuadEntry(OPCode op,string result);
	void setArgv1(string argv);
	void setArgv2(string argv);
	void setResult(string result_);
	string getArgv1();
	string getArgv2();
	string getResult();
	print();
private:
	OPCode op;
	string argv1;
	string argv2;
	string result;
}

class QuadArray{
public:
	QuadArray();
	int getSize();
	void emit(QuadEntry* entry);
	QuadEntry* getEntry(int index);
	print();
private:
	vector<QuadEntry*> entries;
}