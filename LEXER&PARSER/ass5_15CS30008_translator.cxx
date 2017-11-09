#include "ass5_15CS30008_translator.h"

type_t *type_global = new type_t();
SymbolTable *ST = new SymbolTable();
vector<SymbolTable*> STStack;
SymbolTable *STCurrent = ST;
QuadArray *QA = new QuadArray();
string fileName;

//////////// TYPE_T CLASS /////////////////////
// Constructors
type_t::type_t(){}

type_t::type_t(type_n type_){
	type_name = type_;
	if(type_ == POINTER)
		pointerCheck = true;
	else 
		pointerCheck = false;
	if(type_ == MATRIX)
		arrayCheck = true;
	else
		arrayCheck = false;
	noOfElements = 0;
}

type_t::type_t(type_n type_, bool isPointer_, bool isArray_){
	type_name = type_;
	pointerCheck = isPointer_;
	arrayCheck = isArray_;
	noOfElements = 0;
}

// Setter to set type
void type_t::setType(type_n type){
	type_name = type;
}

// Setter to set Pointed type incase of a pointer
void type_t::setPointedType(type_t* type_){
	pointerCheck = true;
	pointedType = type_;
}

// Setter to set the type of each array element incase of a array/Matrix type
// no_ represents no of array elements
void type_t::setArrayType(type_t* type_,int no_){
	arrayCheck = true;
	noOfElements = no_;
	arrayType = type_;
}

// GETTERS
type_t* type_t::getPointedType(){
	return pointedType;
}

type_t* type_t::getArrayType(){
	return arrayType;
}

int type_t::getNoOfElements(){
	return noOfElements;
}

bool type_t::isPointer(){
	return pointerCheck;
}

bool type_t::isArray(){
	return arrayCheck;
}

type_n type_t::getTypeName(){
	return type_name;
}

//////////// DECL_T CLASS /////////////////////

decl_t::decl_t(type_n type_){
	type = new type_t(type_,false,false);
	name = NULL;
	nestedTable = NULL;
}

decl_t::decl_t(type_t* type_){
	type = type_;
	name = NULL;
	nestedTable = NULL;
	initVal = * new init_t();
}

void decl_t::setType(type_n ty){
	type->setType(ty);
}

void decl_t::setType(type_t* ty){
	type = ty;
}

void decl_t::setName(string* a){
	name = a;
}

void decl_t::setNestedTable(SymbolTable* table){
	nestedTable = table;
}

void decl_t::setInitVal(init_t init_){
	checkinitialized = true;
	initVal = init_;
}

bool decl_t::isInitialized(){
	return checkinitialized;
}

string* decl_t::getName(){
	return name;
}

type_t* decl_t::getType(){
	return type;
}

SymbolTable* decl_t::getNestedTable(){
	return nestedTable;
}

init_t decl_t::getInitValue(){
	return initVal;
}

///////////// EXP_T CLASS ///////////////////
exp_t::exp_t(){
	trueList = new vector<int>(0);
	falseList = new vector<int>(0);
	nextList = new vector<int>(0);
	checkAddress = false;
	checkDeReference = false;
	checkConstant = false;
	checkArrayAccess = false;
	checkFunctionCall = false;
	SE = NULL;
}

exp_t::exp_t(SymbolEntry* SE_){
	trueList = new vector<int>(0);
	falseList = new vector<int>(0);
	nextList = new vector<int>(0);
	checkAddress = false;
	checkDeReference = false;
	checkConstant = false;
	checkArrayAccess = false;
	checkFunctionCall = false;
	SE = SE_;
}

SymbolEntry* exp_t::getSymbolEntry(){
	return SE;
}

vector<int>* exp_t::getTrueList(){
	return trueList;
}

vector<int>* exp_t::getFalseList(){
	return falseList;
}

vector<int>* exp_t::getNextList(){
	return nextList;
}

SymbolEntry* exp_t::getArraySum(){
	return arraySum;
}

bool exp_t::isAddress(){
	return checkAddress;
}

bool exp_t::isDeReference(){
	return checkDeReference;
}

bool exp_t::isConstant(){
	return checkConstant;
}

bool exp_t::isArrayAccess(){
	return checkArrayAccess;
}

bool exp_t::isFunctionCall(){
	return checkFunctionCall;
}

init_t exp_t::getConstantVal(){
	return constantVal;
}

type_n exp_t::getConstantType(){
	return constType;
}

int exp_t::getNoOfParams(){
	return noOfParams;
}

void exp_t::setSymbolEntry(SymbolEntry* SE_){
	SE = SE_;
}

void exp_t::setFunctionCall(bool func_,int no){
	checkFunctionCall = func_;
	noOfParams = no;
}

void exp_t::setAddress(bool add_){
	checkAddress = add_;
}

void exp_t::setConstant(bool const_){
	checkConstant = const_;
}

void exp_t::setConstant(bool const_,init_t co,type_n ty){
	checkConstant = const_;
	constantVal = co;
	constType = ty;
}

void exp_t::setDeReference(bool de_){
	checkDeReference = de_;
}

void exp_t::setArrayAccess(bool ar,SymbolEntry* ars){
	checkArrayAccess = ar;
	arraySum = ars;
}

void exp_t::setTrueList(vector<int>* truelist){
	trueList = truelist;
}

void exp_t::setFalseList(vector<int>* falselist){
	falseList = falselist;
}

void exp_t::setNextList(vector<int>* nextlist){
	nextList = nextlist;
}

///////////// SYMBOL ENTRY //////////////////
SymbolEntry::SymbolEntry(){

}
SymbolEntry::SymbolEntry(SymbolEntry* se){
	offset = se->getOffset();
	size = se->getSize();
	initialised = se->checkInitialize();
	name = se->getName();
	type = se->getType();
	nestedTable = se->getNestedTable();
}

SymbolEntry::SymbolEntry(string* name_,type_t* type_, int width_,int offset_,SymbolTable* table){
	offset = offset_;
	size = width_;
	initialised = false;
	name = name_;
	type = type_;
	nestedTable = table;
}

SymbolEntry::SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table, init_t init){
	offset = offset_;
	size = width_;
	initialised = true;
	name = name_;
	type = type_;
	initialValue = init;
	nestedTable = table;
}

void SymbolEntry::setName(string* name_){
	name = name_;
}

void SymbolEntry::setType(type_t* type_){
	type = type_;
}

void SymbolEntry::setSize(int width){
	size = width;
	offset = ST->getOffset();
}

void SymbolEntry::setNestedTable(SymbolTable* st){
	nestedTable = st;
}

void SymbolEntry::initialize(init_t init_){
	initialised = true;
	initialValue = init_;
}

string* SymbolEntry::getName(){
	return name;
}

type_t* SymbolEntry::getType(){
	return type;
}

int SymbolEntry::getOffset(){
	return offset;
}

int SymbolEntry::getSize(){
	return size;
}

bool SymbolEntry::checkInitialize(){
	return initialised;
}

init_t SymbolEntry::getInitialValue(){
	return initialValue;
}

SymbolTable* SymbolEntry::getNestedTable(){
	return nestedTable;
}


void SymbolEntry::setOffset(int a){
	offset = a;
}


void SymbolEntry::print(){
	string a;
	string b = "";
	switch(type->getTypeName()){
		case INT:
			a = "INT";
			b = to_string(initialValue.intVal);
			break;
		case CHAR:
			a = "CHAR";
			b = to_string(initialValue.charVal);
			break;
		case VOID:
			a = "VOID";
			break;
		case DOUBLE:
			a = "DOUBLE";
			b = to_string(initialValue.doubleVal);
			break;
		case MATRIX:
			a = "MATRIX";
			break;
		case POINTER:
			a = "POINTER";
			break;
		case FUNCTION:
			a = "FUNCTION";
			break;
	}
	cout << "NAME : " << *name << "        TYPE : " << a << "        INITIAL VALUE : " << b << "        SIZE : " << size << "        OFFSET : " << offset << endl;
	if(type->getTypeName() == FUNCTION){
		cout << "------------------Nested Table-----------------------" << endl;
		nestedTable->print();
		cout << "-----------------------------------------------------" << endl;
	}
}

///////////////// SYMBOL TABLE ////////////////////

SymbolTable::SymbolTable(){
	tempNo = 0;
	offset = 0;
	parentTable = NULL;
	definition = false;
}

SymbolEntry* SymbolTable::lookup(string name){
	for(int i = 0; i < entries.size(); i++){
		if(name.compare(*entries[i]->getName()) == 0)
			return entries[i];
	}
	if(parentTable != NULL)
		return parentTable->lookup(name);
	return NULL;
}

SymbolEntry* SymbolTable::lookup(string* name){
	for(int i = 0; i < entries.size(); i++){
		if(name->compare(*entries[i]->getName()) == 0)
			return entries[i];
	}
	if(parentTable != NULL)
		return parentTable->lookup(name);
	return NULL;
}

int SymbolTable::getSize(){
    return entries.size();
}

SymbolEntry* SymbolTable::gentemp(type_t* type){
	SymbolEntry* temp;
	string* tempName = new string("temp");
	tempName->append(to_string(tempNo));
	tempNo++;
	int width_ = getWidth(type);
	temp = new SymbolEntry(tempName,type,width_,offset+8,NULL);
	offset += width_;
	entries.push_back(temp);
	return temp;
}

SymbolEntry* SymbolTable::gentemp(type_t* type,string* name_){
	SymbolEntry* temp;
	int width_ = getWidth(type);
	temp = new SymbolEntry(name_,type,width_,offset+8,NULL);
	offset += width_;
	entries.push_back(temp);
	return temp;
}

SymbolEntry* SymbolTable::gentemp(decl_t* decl){
	SymbolEntry* temp;
	type_t *ty = decl->getType();
	int width_ = getWidth(ty);
	temp = new SymbolEntry(decl->getName(),ty,width_,offset+8,decl->getNestedTable());
	entries.push_back(temp);
	offset += width_;
	return temp;
}

SymbolEntry* SymbolTable::gentemp(SymbolEntry* temp){
	type_t *ty = temp->getType();
	int width_ = getWidth(ty);
	temp = new SymbolEntry(temp->getName(),ty,width_,offset+8,temp->getNestedTable());
	entries.push_back(temp);
	offset += width_;
	return temp;
}

void SymbolTable::setParentTable(SymbolTable* st){
	parentTable = st;
}

SymbolTable* SymbolTable::getParentTable(){
	return parentTable;
}

int SymbolTable::getOffset(){
	return offset;
}

SymbolEntry* SymbolTable::getEntry(int i){
    return entries[i];
}

void SymbolTable::setOffset(int offset_){
	offset = offset_;
}

void SymbolTable::update(string* name,init_t initValue){
	SymbolEntry* se = lookup(name);
	se->initialize(initValue);
}

void SymbolTable::print(){	
	for(int i = 0; i < entries.size(); i++){
		cout << i << " : ";entries[i]->print();
	}
}

void SymbolTable::targetOffsets(){
	int retLoc = -1;
	for(int i = 0; i < entries.size(); i++){
		if(entries[i]->getName()->compare("retVal") == 0){
			retLoc = i;
			break;
		}
	}
	if(retLoc == -1)
		return;
	int O = 16,off = 0;
	for(int i = retLoc; i >= 0; i--){
		entries[i]->setOffset(O);
		O += 8;
	}
	O = -8;
	for(int i = retLoc+1; i < entries.size(); i++){
		entries[i]->setOffset(O);
		O -= entries[i]->getSize();
        off += entries[i]->getSize();
	}
    offset = off;
	return;
}

void SymbolTable::isDefinition(bool v){
	definition = v;
}

bool SymbolTable::checkDefinition(){
	return definition;
}

//////////////// QUAD ENTRY //////////////////////
QuadEntry::QuadEntry(OPCode op_,string result_,string argv1_,string argv2_){
	op = op_;
	argv1 = argv1_;
	argv2 = argv2_;
	result = result_;
}

QuadEntry::QuadEntry(OPCode op_,string result_,string argv1_){
	op = op_;
	argv1 = argv1_;
	argv2 = "";
	result = result_;
}

QuadEntry::QuadEntry(OPCode op_,string result_){
	op = op_;
	argv1 = "";
	argv2 = "";
	result = result_;
}

QuadEntry::QuadEntry(OPCode op_,string *result_,string *argv1_,string *argv2_){
	op = op_;
	argv1 = *argv1_;
	argv2 = *argv2_;
	result = *result_;
}

QuadEntry::QuadEntry(OPCode op_,string result_,string *argv1_,string *argv2_){
	op = op_;
	argv1 = *argv1_;
	argv2 = *argv2_;
	result = result_;
}

QuadEntry::QuadEntry(OPCode op_,string *result_,string argv1_,string *argv2_){
	op = op_;
	argv1 = argv1_;
	argv2 = *argv2_;
	result = *result_;
}

QuadEntry::QuadEntry(OPCode op_,string *result_,string *argv1_,string argv2_){
	op = op_;
	argv1 = *argv1_;
	argv2 = argv2_;
	result = *result_;
}

QuadEntry::QuadEntry(OPCode op_,string *result_,string *argv1_){
	op = op_;
	argv1 = *argv1_;
	argv2 = "";
	result = *result_;
}

QuadEntry::QuadEntry(OPCode op_,string *result_){
	op = op_;
	argv1 = "";
	argv2 = "";
	result = *result_;
}

QuadEntry::QuadEntry(OPCode op_){
	op = op_;
	argv1 = "";
	argv2 = "";
	result = "";
}

string QuadEntry::getArgv1(){
	return argv1;
}

string QuadEntry::getArgv2(){
	return argv2;
}

string QuadEntry::getResult(){
	return result;
}

OPCode QuadEntry::getOPCode(){
	return op;
}

string QuadEntry::getLabel(){
	return label;
}

void QuadEntry::setLabel(string label_){
	label = label_;
}

void QuadEntry::setArgv1(string argv){
	argv1 = argv;
}

void QuadEntry::setArgv2(string argv){
	argv2 = argv;
}

void QuadEntry::setResult(string result_){
	result = result_;
}

void QuadEntry::print(fstream &fs){
	switch(op){
		case OP_ADD:
			fs << result + " = " + argv1 + " + " + argv2 << endl;
			break;
		case OP_NEG:
			fs << result + " = -" + argv1 << endl;
			break;
		case OP_SUB:
			fs << result + " = " + argv1 + " - " + argv2 << endl;
			break;
		case OP_LSFT:
			fs << result + " = " + argv1 + " << " + argv2 << endl;
			break;
		case OP_RSFT:
			fs << result + " = " + argv1 + " >> " + argv2 << endl;
			break;
		case OP_MUL:
			fs << result + " = " + argv1 + " * " + argv2 << endl;
			break;
		case OP_DIV:
			fs << result + " = " + argv1 + " / " + argv2 << endl;
			break;
		case OP_MOD:	
			fs << result + " = " + argv1 + " %% " + argv2 << endl;
			break;
		case OP_AND:
			fs << result + " = " + argv1 + " & " + argv2 << endl;
			break;
		case OP_XOR:
			fs << result + " = " + argv1 + " ^ " + argv2 << endl;
			break;
		case OP_OR:
			fs << result + " = " + argv1 + " | " + argv2 << endl;
			break;
		case OP_COPY:
			fs << result + " = " + argv1 << endl;
			break;
		case OP_DE_REF_L:
			fs << "*" + result + " = " + argv1 << endl;
			break;
		case OP_DE_REF_R:
			fs << result + " = *" + argv1 << endl;
			break;
		case OP_REF:
			fs << result + " = &" + argv1 << endl;
			break;
		case OP_IF_LT_GOTO:
			fs << "if " + argv1 + " < " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_GT_GOTO:
			fs << "if " + argv1 + " > " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_LTE_GOTO:
			fs << "if " + argv1 + " <= " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_GTE_GOTO:
			fs << "if " + argv1 + " >= " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_EQ_GOTO:
			fs << "if " + argv1 + " == " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_NEQ_GOTO:
			fs << "if " + argv1 + " != " + argv2 + " then goto " + result << endl;
			break;
		case OP_IF_GOTO:
			fs << "if " + argv1 + " then goto " + result << endl;
			break;
		case OP_IFF_GOTO:
			fs << "if not " + argv1 + " then goto " + result << endl;
			break;
		case OP_ARR_ACC_R:
			fs << result + " = " + argv1 + "[" + argv2 + "]" << endl;
			break;
		case OP_ARR_ACC_L: 
			fs << result + "[" + argv1 + "]" " = " + argv2 << endl;
			break;
		case OP_INCR:
			fs << result + " = ++" + argv1 << endl;
			break;
		case OP_DECR:
			fs << result + " = --" + argv1 << endl;
			break;
		case OP_GOTO:
			fs << "goto " + result << endl;
			break;
		case OP_PARAM:
			fs << "param " + result << endl;
			break;
		case OP_CALL:
			fs << result + " = call " + argv1 + " , " + argv2 << endl;
			break;
		case OP_RETURN:
			fs << "return " + result << endl;
			break;
		case OP_FUNC_START:
			//fs << "OP_FUNC_START " << result << endl;
			break;
		case OP_FUNC_END:
			//fs << "OP_FUNC_END " << result << endl;
			break;
	}
}

////////////////// QUAD ARRAY //////////////////
// Quad Entries are stored in a vector named entries
QuadArray::QuadArray(){
	lfb = 0;
	lfe = 0;
	lc = 0;
}

// Used to push the Quad Entry into the entries vector. This effectively strores an instruction
void QuadArray::emit(QuadEntry* qd){
	entries.push_back(qd);
}

int QuadArray::getSize(){
	return entries.size();
}

QuadEntry* QuadArray::getEntry(int index){
	return entries[index];
}

void QuadArray::print(){
	fstream fs;
	int j = 0;
	fs.open(fileName+".out",ios::out | ios::in);
	for(int i = 0; i < entries.size(); i++){
		if(entries[i]->getOPCode() == OP_FUNC_START || entries[i]->getOPCode() == OP_FUNC_END)
				continue;
		fs << j << " : ";entries[i]->print(fs);
		j++;
	}
	fs.close();
}

void QuadArray::createLabels(){
	for(int i = 0; i < entries.size(); i++){
		if(entries[i]->getOPCode() == OP_FUNC_START){
			entries[i]->setLabel(".LFB" + to_string(lfb));
			lfb++;
		}
		if(entries[i]->getOPCode() == OP_FUNC_END){
			entries[i]->setLabel(".LFE" + to_string(lfe));
			lfe++;
		}
		if(entries[i]->getOPCode() == OP_GOTO || 
			entries[i]->getOPCode() == OP_IF_LT_GOTO ||
			entries[i]->getOPCode() == OP_IF_GT_GOTO ||
			entries[i]->getOPCode() == OP_IF_LTE_GOTO ||
			entries[i]->getOPCode() == OP_IF_GTE_GOTO ||
			entries[i]->getOPCode() == OP_IF_EQ_GOTO ||
			entries[i]->getOPCode() == OP_IF_NEQ_GOTO ||
			entries[i]->getOPCode() == OP_IF_GOTO ||
			entries[i]->getOPCode() == OP_IFF_GOTO )
		{
			int j = atoi(entries[i]->getResult().c_str());
			entries[j]->setLabel(".L" + to_string(lc));
			lc++;
		}
	}	
}

////////////// BACKPATCHING //////////////	

vector<int>* makelist(int instr){
	vector<int>* list = new vector<int>(0);
	list->push_back(instr); 
	return list;
}

vector<int>* merge(vector<int>* list1,vector<int>* list2){
	vector<int>* list = new vector<int>(0);
	for(int i = 0; i < list1->size(); i++)
		list->push_back(list1->at(i));
	for(int i = 0; i < list2->size(); i++)
		list->push_back(list2->at(i));

	return list;
}

// Backpatching. Every Quad Entry with index number in the list ,
//the result cell of the instruction will be replaced with "instr" 
vector<int>* backpatch(vector<int>* list, int instr){
	for(int i = 0; i < list->size(); i++){
		QuadEntry* temp = QA->getEntry(list->at(i));
		if(temp->getResult().compare("") == 0)
			temp->setResult(to_string(instr));
	}
	return list;
}

int getWidth(type_n type){
	int size;
	switch(type){
		case INT:
			return SIZE_OF_INT;
		case CHAR:
			return SIZE_OF_CHAR;
		case POINTER:
			return SIZE_OF_POINTER;
		case DOUBLE:
			return SIZE_OF_DOUBLE;
		case VOID:
			return SIZE_OF_VOID;
		case FUNCTION:
			return 0;
		case MATRIX:
			return SIZE_OF_DOUBLE;
			return size;
	}
}

// Computes the size of a complex type
int getWidth(type_t* type){
	type_n type_ = type->getTypeName();
	int size = 1;
	if(type_ == MATRIX){
		while(type->getArrayType() != NULL){
			size *= type->getNoOfElements();
			type = type->getArrayType();
		}  
		size *= SIZE_OF_DOUBLE;
		return size;
	}
	return getWidth(type_);
}

// Type casts whenever possible and updates the resultant types as pointers are passed.
bool typecheck(type_t* type1, type_t* type2){
	type_n t1 = type1->getTypeName();
	type_n t2 = type2->getTypeName();
	if(!((t1 == MATRIX) ^ (t2 == MATRIX))){
		if(type1->getNoOfElements() != type2->getNoOfElements())
			return false;
		else{
			if(type1->isArray() && type1->getNoOfElements() != type2->getNoOfElements()){
				type1 = type1->getArrayType();
				type2 = type2->getArrayType();
				return false;
			}
		}
	}
	else if(t1 != t2){
		if(t1 == INT){
			if(t2 == DOUBLE)
				type1 = type2;
			else if(t2 == CHAR)
				type2 = type1;
		}
		else if(t1 == DOUBLE){
			if(t2 == INT || t2 == CHAR)
				type2 = type1;
		}
	}
	return true;
}

