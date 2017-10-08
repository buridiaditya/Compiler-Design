#include "translator.h"

//////////// TYPE_T CLASS /////////////////////

type_t::type_t(type_n type_, bool isPointer_, bool isArray_){
	type_name = type_;
	pointerCheck = isPointer_;
	arrayCheck = isArray_;
	noOfElements = 0;
}

void type_t::setType(type_n type){
	type_name = type;
}

void type_t::setPointedType(type_t* type_){
	pointerCheck = true;
	pointedType = type_;
}

void type_t::setArrayType(type_t* type_,int no_){
	arrayCheck = true;
	noOfElements = no_;
	arrayType = type_;
}

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
}

void decl_t::setType(type_n ty)
	type->setType(ty);

void decl_t::setType(type_t* ty)
	type = ty;

void decl_t::setPointedType(type_t* ty)
	type->setPointedType(ty);

void decl_t::setRow(int row)
	type->setRow(row);

void decl_t::setCol(int col)
	type->setCol(col);

void decl_t::setName(string* a)
	name = a;

void decl_t::setNestedTable(SymbolTable* table)
	nestedTable = table;

void decl_t::setInitVal(init_t init_){
	checkinitialized = true;
	initVal = init_;
}

bool decl_t::isInitialized()
	return checkinitialized;

string* decl_t::getName()
	return name;

type_t* decl_t::getType()
	return type;

SymbolTable* decl_t::getNestedTable()
	return nestedTable;

init_t decl_t::getInitValue()
	return initVal;

///////////// EXP_T CLASS ///////////////////
exp_t::exp_t(){
	trueList = NULL;
	falseList = NULL;
	nextList = NULL;
	SE = NULL;
}

exp_t::exp_t(SymbolEntry* SE_){
	trueList = NULL;
	falseList = NULL;
	nextList = NULL;
	SE = SE_;
}

SymbolEntry* exp_t::getSymbolEntry()
	return SE;

void exp_t::setSymbolEntry(SymbolEntry* SE_)
	SE = SE_;

void exp_t::setTrueList(vector<int>* truelist)
	trueList = truelist;

void exp_t::setFalseList(vector<int>* falselist)
	falseList = falselist;

void exp_t::setNextList(vector<int>* nextlist)
	nextList = nextlist;

vector<int>* exp_t::getTrueList()
	return trueList;

vector<int>* exp_t::getFalseList()
	return falseList;

///////////// SYMBOL ENTRY //////////////////
SymbolEntry::SymbolEntry(string* name_,type_t* type_, int width_,int offset_,SymbolTable* table){
	offset = offset_;
	size = width_;
	initialized = false;
	name = name_;
	type = type_;
	nestedTable = table;
}

SymbolEntry::SymbolEntry(string* name_,type_t* type_,int width_,int offset_,SymbolTable* table, init_t init){
	offset = offset_;
	size = width_;
	initialized = true;
	name = name_;
	type = type_;
	initialValue = init;
	nestedTable = table;
}

void SymbolEntry::setName(string* name_)
	name = name_;

void SymbolEntry::setType(type_t* type_)
	type = type_;

void SymbolEntry::setSize(int width){
	size = width;
	offset = ST->getOffset;
}

void SymbolEntry::setNestedTable(SymbolTable* st)
	nestedTable = st;

void SymbolEntry::initialize(init_t init_)
	initialValue = init_;

string* SymbolEntry::getName()
	return name;

type_t* SymbolEntry::getType()
	return type;

int SymbolEntry::getOffset()
	return offset;

int SymbolEntry::getSize()
	return size;

bool SymbolEntry::checkInitialize()
	return initialized;

init_t SymbolEntry::getInitialValue()
	return initialValue;

SymbolTable* SymbolEntry::getNestedTable()
	return nestedTable;

void print(){

}

///////////////// SYMBOL TABLE ////////////////////

SymbolTable::SymbolTable(){
	tempNo = 0;
	offset = 0;
}

SymbolEntry* SymbolTable::lookup(string* name){
	for(int i = 0; i < entries.size(); i++){
		if(name->compare(*entries[i].getName()) == 0)
			return entries[i];
	}
	return NULL;
}

SymbolEntry* SymbolTable::gentemp(type_t* type){
	SymbolEntry* temp;
	string tempName = "temp";
	tempName.append('0'+tempNo);
	tempNo++;
	int width_ = getWidth(type);
	temp = new SymbolEntry(tempName,type,width_,offset,NULL);
	offset += width_;
	entries.push_back(temp);
	return temp;
}

SymbolEntry* SymbolTable::gentemp(type_t* type,string* name_){
	SymbolEntry* temp;
	int width_ = getWidth(type);
	temp = new SymbolEntry(name_,type,width_,offset,NULL);
	offset += width_;
	entries.push_back(temp);
	return temp;
}

SymbolEntry* SymbolTable::gentemp(decl_t* decl){
	SymbolEntry* temp;
	type_t *ty = decl->getType();
	int width_ = getWidth(ty);
	temp = new SymbolEntry(decl->getName(),ty,width_,offset,decl->getNestedTable());
	entries.push_back(temp);
	offset += width_;
	return temp;
}

SymbolEntry* SymbolTable::gentemp(SymbolEntry* temp){
	type_t *ty = temp->getType();
	int width_ = getWidth(ty);
	temp = new SymbolEntry(temp->getName(),ty,width_,offset,temp->getNestedTable());
	entries.push_back(temp);
	offset += width_;
	return temp;
}

int SymbolTable::getOffset()
	return offset;

void SymbolTable::setOffset(int offset_)
	offset = offset_;

void update(string* name,init_t initValue){
	SymbolEntry* se = lookup(name);
	se->setInitVal(initValue);
	return;
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

string QuadEntry::getArgv1()
	return argv1;

string QuadEntry::getArgv2()
	return argv2;

string QuadEntry::getResult()
	return result;

void QuadEntry::setArgv1(string argv)
	argv1 = argv;

void QuadEntry::setArgv2(string argv)
	argv2 = argv;

void QuadEntry::setResult(string result_)
	result = result_;

void QuadEntry::print(){

}

////////////////// QUAD ARRAY //////////////////
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

}

////////////// BACKPATCHING //////////////	
vector<int>* makelist(int instr){
	vector<int>* list = new vector<int>();
	list->push_back(instr); 
}

vector<int>* merge(vector<int>* list1,vector<int>* list2){
	vector<int>* list = new vector<int>();
	for(int i = 0; i < list1->size(); i++)
		list->push_back(list1->at(i));
	for(int i = 0; i < list2->size(); i++)
		list->push_back(list2->at(i));
	return list;
}

vector<int>* backpatch(vector<int>* list, int instr){
	for(int i = 0; i < list->size(); i++){
		QuadEntry* temp = QA->getEntry(list->at(i));
		if(temp->getResult.compare("") == 0)
			temp->setResult(to_string(instr));
	return list;
}

int getWidth(type_n type){
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
	}
}

int getWidth(type_t* type){
	int type_ = type->getTypeName();
	return getWidth(type_);
}