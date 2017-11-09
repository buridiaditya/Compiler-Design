#include <string>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include <iostream>

using namespace std;

/////// DETAILED COMMENTS EXPLAINING CLASS DEFINITIONS CAN BE FOUND IN .cpp file


// Sizes of various basic types
#define SIZE_OF_INT 8
#define SIZE_OF_CHAR 8
#define SIZE_OF_DOUBLE 8
#define SIZE_OF_POINTER 8
#define SIZE_OF_VOID 0

// Prototypes of classes
class SymbolTable;
class SymbolEntry;
class type_t;
class decl_t;
class exp_t;

// Function Prototype
void generateTargetCode();

//////////////////////////////////////////////////////
//////////////////// TYPE_N //////////////////////////
//////////////////////////////////////////////////////
// All the basic types
typedef enum{
	INT = 0,
	CHAR,
	VOID,
	DOUBLE,
	MATRIX,
	POINTER,
	FUNCTION
}type_n;

//////////////////////////////////////////////////////
////////////////// OPCode Enum ///////////////////////
//////////////////////////////////////////////////////
// All the operations possible 
typedef enum {
	OP_ADD,
	OP_NEG,
	OP_SUB,
	OP_LSFT,
	OP_RSFT,
	OP_MUL,
	OP_DIV,
	OP_MOD,
	OP_AND,
	OP_XOR,
	OP_OR,
	OP_COPY,
	OP_DE_REF_L,
	OP_DE_REF_R,
	OP_REF,
	OP_IF_LT_GOTO,
	OP_IF_GT_GOTO,
	OP_IF_LTE_GOTO,
	OP_IF_GTE_GOTO,
	OP_IF_EQ_GOTO,
	OP_IF_NEQ_GOTO,
	OP_IF_GOTO,
	OP_IFF_GOTO,
	OP_ARR_ACC_R,
	OP_ARR_ACC_L,
	OP_INCR,
	OP_DECR,
	OP_GOTO,
	OP_PARAM,
	OP_CALL,
	OP_RETURN,
	OP_FUNC_START,
	OP_FUNC_END
}OPCode;

//////////////////////////////////////////////////////
////////////////// INITIALIZATION ////////////////////
//////////////////////////////////////////////////////
// Stores the initialization value
typedef struct init_t{
	int intVal;
	string* strVal;
	char charVal;
	double doubleVal;
}init_t;


//////////////////////////////////////////////////////
////////////////// COMPLEX TYPE //////////////////////
//////////////////////////////////////////////////////
// Used to represent complex types apart from basic types i.e Matrices and Pointers
class type_t{
public:
	type_t();
	type_t(type_n type);
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
	bool pointerCheck;
	bool arrayCheck;
	int noOfElements;
};

//////////////////////////////////////////////////////
////////////////// SYMBOL ENTRY //////////////////////
//////////////////////////////////////////////////////
// Stores the Symbol Entry data in Symbol Table
class SymbolEntry{
public:
	SymbolEntry();
	SymbolEntry(SymbolEntry* se);
	SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table);
	SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table,init_t init);
	void setName(string* name);
	void setType(type_t* type);
	void setSize(int size);
	void setNestedTable(SymbolTable* st);
	void initialize(init_t init);
	void setOffset(int a);
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
};

//////////////////////////////////////////////////////
////////////////// SYMBOL TABLE //////////////////////
//////////////////////////////////////////////////////
// Symbol Table 
class SymbolTable{
public:
	SymbolTable();	
	SymbolEntry* lookup(string name);
	SymbolEntry* lookup(string* name);
	SymbolEntry* gentemp(type_t* type);
	SymbolEntry* gentemp(decl_t* dec);
	SymbolEntry* gentemp(type_t* type,string* name_);
	SymbolEntry* gentemp(SymbolEntry* se);
	SymbolTable* getParentTable();
	void setParentTable(SymbolTable* st);
	int getOffset();
	void setOffset(int offset_);
	void update(string* name,init_t initValue);
	void print();
	void targetOffsets();
    int getSize();
    SymbolEntry* getEntry(int i);
    void isDefinition(bool v);
    bool checkDefinition();
private:
	int offset;
	int tempNo;
	bool definition;
	vector<SymbolEntry*> entries;
	SymbolTable* parentTable;
};

//////////////////////////////////////////////////////
////////////////// DECLARATIONS //////////////////////
//////////////////////////////////////////////////////
// Data Structure for storing declarations data
class decl_t{
public:
	decl_t(type_n type_);
	decl_t(type_t* type_);
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
	bool checkinitialized;
	init_t initVal;
	SymbolTable* nestedTable;
};

//////////////////////////////////////////////////////
////////////////// EXPRESSIONS ///////////////////////
//////////////////////////////////////////////////////
// Data Structure for storing expression data
class exp_t{
public:
	exp_t();
	exp_t(SymbolEntry* SE_);
	SymbolEntry* getSymbolEntry();
	vector<int>* getTrueList();
	vector<int>* getFalseList();
	vector<int>* getNextList();
	SymbolEntry* getArraySum();
	bool isAddress();
	bool isDeReference();
	bool isConstant();
	bool isArrayAccess();
	bool isFunctionCall();
	init_t getConstantVal();
	type_n getConstantType();
	int getNoOfParams();
	void setSymbolEntry(SymbolEntry* se);
	void setFunctionCall(bool func_,int no);
	void setAddress(bool add_);
	void setConstant(bool const_);
	void setConstant(bool const_,init_t co,type_n ty);
	void setDeReference(bool de_);
	void setArrayAccess(bool ar,SymbolEntry* arraySum);
	void setTrueList(vector<int>* truelist);
	void setFalseList(vector<int>* falselist);
	void setNextList(vector<int>* nextlist);
private:
	SymbolEntry* SE;
	SymbolEntry* arraySum;
	bool checkAddress;
	bool checkDeReference;
	bool checkConstant;
	bool checkArrayAccess;
	bool checkFunctionCall;
	init_t constantVal;
	int noOfParams;
	type_n constType;
	vector<int>* trueList;
	vector<int>* falseList;
	vector<int>* nextList;
};

//////////////////////////////////////////////////////
////////////////// INSTRUCTIONS //////////////////////
//////////////////////////////////////////////////////
// Stores the data of a particular instruction
class QuadEntry{
public:
	QuadEntry(OPCode op,string result,string argv1, string argv2);
	QuadEntry(OPCode op,string result,string argv1);
	QuadEntry(OPCode op,string result);
	QuadEntry(OPCode op,string result,string* argv1, string* argv2);
	QuadEntry(OPCode op,string* result,string* argv1, string* argv2);
	QuadEntry(OPCode op,string* result,string* argv1);
	QuadEntry(OPCode op,string* result);
	QuadEntry(OPCode op);
	QuadEntry(OPCode op,string* result,string* argv1, string argv2);
	QuadEntry(OPCode op,string* result,string argv1, string* argv2);
	void setArgv1(string argv);
	void setArgv2(string argv);
	void setResult(string result_);
	void setLabel(string label_);
	OPCode getOPCode();
	string getArgv1();
	string getArgv2();
	string getResult();
	string getLabel();
	void print(fstream &fs);
private:
	OPCode op;
	string argv1;
	string argv2;
	string result;
	string label;
};

//////////////////////////////////////////////////////
////////////////// INSTRUCTION ARRAY /////////////////
//////////////////////////////////////////////////////
/////// QUAD ARRAY CLASS //////////
class QuadArray{
public:
	QuadArray();
	int getSize();
	void emit(QuadEntry* entry);
	QuadEntry* getEntry(int index);
	void print();
	void createLabels();
private:
	vector<QuadEntry*> entries;
	int lfb;
	int lfe;
	int lc;
};

//////////////////////////////////////////////////////
////////////////// UTILITY ///////////////////////////
//////////////////////////////////////////////////////
// Utility Function
vector<int>* makelist(int instr);
vector<int>* merge(vector<int>* list1, vector<int>* list2);
vector<int>* backpatch(vector<int>* list,int value);
bool typecheck(type_t* type1, type_t* type2);
int getWidth(type_n type);
int getWidth(type_t* type);

//////////////////////////////////////////////////////
////////////////// GLOBAL VARIABLES //////////////////
//////////////////////////////////////////////////////
extern type_t *type_global;
extern SymbolTable *ST;
extern vector<SymbolTable*> STStack;
extern SymbolTable *STCurrent;
extern QuadArray *QA;
