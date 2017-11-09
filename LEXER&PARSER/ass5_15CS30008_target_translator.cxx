#include "ass5_15CS30008_translator.h"

void generateTargetCode(QuadEntry *qe,QuadArray* QA, SymbolTable* st){
	SymbolEntry* a1;
	SymbolEntry* a2;
	SymbolEntry* a3;
	int result;
	string f;
	switch(qe->getOPCode()){
		case OP_ADD:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\taddq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_NEG:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tnegq\t%rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_SUB:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\tsubq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_LSFT:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\tshlq\t$" << a3->getInitialValue().intVal << ", %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_RSFT:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\tshrq\t$" << a3->getInitialValue().intVal << ", %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_MUL:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\timulq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_DIV:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rcx\n";
			cout << "\tcqto\n";
			cout << "\tidivq\t%rcx\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_MOD:	
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rcx\n";
			cout << "\tcqto\n";
			cout << "\tidivq\t%rcx\n";
			cout << "\tmovq\t%rdx, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_AND:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\tandq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_XOR:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\txorq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_OR:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a2->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\torq\t%rdx, %rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_COPY:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
		case OP_DE_REF_L:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a3->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rdx\n";
			cout << "\tmovq\t%rdx, (%rax)\n";
			break;
		case OP_DE_REF_R:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t(%rax), %rax";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_REF:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tleaq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_IF_LT_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tjl\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_GT_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tjg\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_LTE_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tjle\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_GTE_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tjge\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_EQ_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tje\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_NEQ_GOTO:
			a1 = st->lookup(qe->getArgv1());
			a2 = st->lookup(qe->getArgv2());
			result = atoi(qe->getResult().c_str());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tcmpq\t%rax, " << a2->getOffset() << "(%rbp)\n";
			cout << "\tjne\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_IF_GOTO:
			break;
		case OP_IFF_GOTO:
			break;
		case OP_ARR_ACC_R:
			break;
		case OP_ARR_ACC_L: 
			break;
		case OP_INCR:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tincq\t%rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_DECR:
			a1 = st->lookup(qe->getArgv1());
			a3 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tdecq\t%rax\n";
			cout << "\tmovq\t%rax, " << a3->getOffset() << "(%rbp)\n";
			break;
		case OP_GOTO:
			result = atoi(qe->getResult().c_str());
			cout << "\tjmp\t" << QA->getEntry(result)->getLabel() << "\n";
			break;
		case OP_PARAM:
			a1 = st->lookup(qe->getResult());
			cout << "\tmovq\t" << a1->getOffset() << "(%rbp), " << "%rax\n";
			cout << "\tpushq\t%rax\n";
			break;
		case OP_CALL:
			a1 = st->lookup(qe->getResult());
			f = qe->getArgv1();
			result = atoi(qe->getArgv2().c_str());
			cout << "\tsubq\t$8, %rsp\n";
			cout << "\tcall\t" << f << "\n";
			cout << "\tmovq\t(%rsp), %rax\n"; 
			cout << "\tmovq\t%rax, " << a1->getOffset() << "(%rbp)\n";
			result *= 8;
			cout << "\taddq\t$" << result+8 << ", %rsp\n";
			break;
		case OP_RETURN:
			if((qe->getResult()).compare("") == 0){
				cout << "\taddq\t$" << st->getOffset() << ", %rsp\n";
				cout << "\tpopq\t%rbp\n";
				cout << "\tret\n";	
			}
			else{
				a1 = st->lookup("retVal");
				a3 = st->lookup(qe->getResult());
				cout << "\taddq\t$" << st->getOffset() << ", %rsp\n";
				cout << "\tmovq\t" << a3->getOffset() << "(%rbp), " << "%rax\n";
				cout << "\tmovq\t%rax, " << a1->getOffset() << "(%rbp)\n";
				cout << "\tpopq\t%rbp\n";
				cout << "\tleave\n";
                cout << "\tret\n";	
			}
			break;
		case OP_FUNC_START:
			f = qe->getResult();
			cout << "\t.globl\t" << f << "\n";
			cout << "\t.type\t" << f << ", @function\n";
			cout << f << ":\n";
			cout << qe->getLabel() + ":\n";
			cout << "\tpushq\t%rbp\n";
			cout << "\tmovq\t%rsp, %rbp\n";
			cout << "\tsubq\t$" << st->getOffset() << ", %rsp\n";
			for(int i = 0; i < st->getSize(); i++){
                SymbolEntry *temp = st->getEntry(i);
                if(temp->checkInitialize()){
                    init_t I = temp->getInitialValue();
                    int con = I.intVal;
                    cout << "\tmovq\t$"<< con << ", " << temp->getOffset() << "(%rbp)\n";
                }
            }
            break;
		case OP_FUNC_END:
			cout << qe->getLabel() + ":\n";
			cout << "\t.size\t" << qe->getResult() << ", .-" << qe->getResult() << "\n";
			break;
		default:
			cout << "Unknown OPCODE\n";
			break;
	}
}

void generateTargetCode(){
	SymbolEntry *se;
	SymbolTable *st = ST;
	QuadEntry* qe;
	int i = 1;
	bool inFunction = false;
	QA->createLabels();
	QA->print();
	//cout << "-----------------------------------------------TARGET CODE-----------------------------------------------\n";
	cout << "\t.text\n";
	for(int i = 0; i < QA->getSize(); i++){
		qe = QA->getEntry(i);
		if(qe->getOPCode() == OP_FUNC_START){
			se = ST->lookup(qe->getResult());
			st = se->getNestedTable();
			st->targetOffsets();
			inFunction = true;
		}
		if(qe->getOPCode() == OP_FUNC_END){
			inFunction = false;
			if(!st->checkDefinition() && (qe->getOPCode() == OP_FUNC_START || qe->getOPCode() == OP_FUNC_END)){
				st = ST;
				continue;
			}
		}
		if(qe->getLabel().compare("") != 0 && qe->getOPCode() != OP_FUNC_START && qe->getOPCode() != OP_FUNC_END){
			cout << qe->getLabel() + ":\n";
		}
		if(!st->checkDefinition() && (qe->getOPCode() == OP_FUNC_START || qe->getOPCode() == OP_FUNC_END))
			continue;
		generateTargetCode(qe,QA,st);
	}
}
