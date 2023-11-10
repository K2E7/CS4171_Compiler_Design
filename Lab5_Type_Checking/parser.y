%{
#include "lex.yy.c"
#include "hash.c"
#include "icode.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>



void yyerror(char *s);

%}

//defining the yyval union
%union {
	int number;		//for integer constants
	float decimal;	//for real constants
	char *string;	//for identifier names
	struct Dtype {	//for datatype of expression
		int dtype;
		char *place;	//for place value of expression
	} Dtype;
}

// Single caharacter lexemes
%token LPAREN_TOK
%token GT_TOK
%token LT_TOK
%token RPAREN_TOK
%token ASSIGN_TOK
%token MINUS_TOK
%token PLUS_TOK
%token MULT_TOK
%token DIV_TOK
%token MOD_TOK
%token NOT_TOK
%token SEMICOLON_TOK
%token HASH_TOK
%token DOT_TOK
%token COMMA_TOK
%token LCURL_TOK
%token RCURL_TOK
%token LSQUARE_TOK
%token RSQUARE_TOK
%token BIT_AND_TOK
%token BIT_OR_TOK
%token BACKSLASH_TOK
%token SPEECH_TOK
%token INVCOMMA_TOK
%token XOR_TOK
%token NEG_TOK

%left PLUS_TOK MINUS_TOK
%left MULT_TOK DIV_TOK MOD_TOK

//Double character lexemes
%token EQ_TOK
%token GTE_TOK
%token LTE_TOK
%token LSHIFT_TOK
%token RSHIFT_TOK
%token AND_TOK
%token OR_TOK
%token NEQ_TOK
%token INC_TOK
%token DEC_TOK

//Arithmetic assignment operators
%token PLUS_ASSIGN_TOK
%token MINUS_ASSIGN_TOK
%token MULT_ASSIGN_TOK
%token DIV_ASSIGN_TOK
%token MOD_ASSIGN_TOK

// Reserved words
%token DO_TOK
%token WHILE_TOK
%token FOR_TOK
%token IF_TOK
%token ELSE_TOK
%token RET_TOK
%token PRINT_TOK
%token SCAN_TOK
%token DEF_TOK
%token TYPEDEF_TOK
%token BREAK_TOK
%token CONTINUE_TOK
%token SIZEOF_TOK
%token CASE_TOK
%token SWITCH_TOK
%token MAIN_TOK
%token INCLUDE_TOK
%token PRINTF_TOK
%token SCANF_TOK

// Identifiers, constants
%token ID_TOK
%token INT_CONST_TOK
%token CHAR_CONST_TOK
%token REAL_CONST_TOK
%token STRING_CONST_TOK

// Type specifiers
%token INT_TOK
%token CHAR_TOK
%token FLOAT_TOK
%token DOUBLE_TOK
%token LONG_TOK
%token SHORT_TOK
%token VOID_TOK

//%type tells bison which member of the yyval union is used by which expression
%type<number> INT_CONST_TOK
%type<string> ID_TOK
%type<string> comparison
%type<string> arith_op
%type<decimal> REAL_CONST_TOK
%type<string> CHAR_CONST_TOK
%type<string> STRING_CONST_TOK
%type<Dtype> expression
%type<Dtype> FUNCTION_CALL
%type<Dtype> cond_exp
%type<string> PLUS_TOK
%type<string> MINUS_TOK
%type<string> MULT_TOK
%type<string> DIV_TOK
%type<string> MOD_TOK
%type<string> GT_TOK
%type<string> LT_TOK
%type<string> GTE_TOK
%type<string> LTE_TOK
%type<string> EQ_TOK
%type<string> NEQ_TOK
%type<string> AND_TOK
%type<string> OR_TOK

%start S

%%

S: 				header S
  				| header
				| MAIN_FN
				| USER_FN S1
				| DECLARE_ASSIGN SEMICOLON_TOK S1
				;

S1: 			USER_FN S1
				| DECLARE_ASSIGN SEMICOLON_TOK S1
				| header
				| USER_FN
				| MAIN_FN
				| DECLARE_ASSIGN SEMICOLON_TOK
				;

open_paren:		LPAREN_TOK											{scope++;}
				;

close_paren:	RPAREN_TOK											{scope--;}
				;

header:			HASH_TOK INCLUDE_TOK LT_TOK ID_TOK DOT_TOK ID_TOK GT_TOK 		{printf("Header syntax correct;\tline no:\t%d\n", yylineno);}
    			| HASH_TOK INCLUDE_TOK STRING_CONST_TOK 						{printf("Header syntax correct;\tline no:\t%d\n", yylineno);}
				;

MAIN_FN:		INT_TOK MAIN_TOK 					{	char msg[50];
														sprintf(msg, "main:\n");
														generate(interm_label, msg);
														interm_label++;
													}
				param block  						{	char msg[50];
														sprintf(msg, "end main\n");
														generate(interm_label, msg);
														interm_label++;
														printf("Main function syntax OK;\tline no:\t%d\n", yylineno);
													}
				;

USER_FN:		datatype ID_TOK 					{	int c = addFunction($2); 
														if(c == -1) { 
															char msg[100]; 
															sprintf(msg, ": Symbol table full"); 
															yyerror(msg);
														}
														char msg[50];
														sprintf(msg, "%s:\n", $2);
														generate(interm_label, msg);
														interm_label++;
													}
				param block 						{	char msg[50];
														sprintf(msg, "end %s\n", $2);
														generate(interm_label, msg);
														interm_label++;
														printf("User defined function OK;\tline no:\t%d\n", yylineno);
													}
				;

param:			open_paren params close_paren						
    			| LPAREN_TOK RPAREN_TOK
				;

params: 		datatype ID_TOK COMMA_TOK params					{	int c = alreadyDeclared($2);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($2);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
				| datatype ID_TOK									{	int c = alreadyDeclared($2);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($2);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
				;

datatype:		INT_TOK												{dtype = 1;}
	 			| FLOAT_TOK											{dtype = 2;}
				| DOUBLE_TOK										{dtype = 2;}
				| CHAR_TOK											{dtype = 4;}
				| VOID_TOK											{dtype = 5;}
				;

start_block:	LCURL_TOK											{scope++;}
				;

end_block:		RCURL_TOK											{deleteScopeSyms(scope); scope--;}
				;

block:			start_block blocks end_block
      			| start_block end_block
      			;

blocks: 		block STATEMENTS blocks
       			| STATEMENTS blocks
				| STATEMENTS
				;

STATEMENTS:		stmt STATEMENTS
	   			| stmt
				;

stmt:			DECLARE_ASSIGN SEMICOLON_TOK						{printf("Declaration over;\tline no:\t%d\n", yylineno);}
				| EXP_ASSIGN SEMICOLON_TOK							{printf("Assignment over;\tline no:\t%d\n", yylineno);}
				| CONDITIONAL										{printf("Conditional block ends;\tline no:\t%d\n", yylineno);}
				| ITERATIVE											{printf("Iterative block ends;\tline no:\t%d\n", yylineno);}
				| FUNCTION_CALL SEMICOLON_TOK									
				| RET_TOK expression SEMICOLON_TOK					{	char msg[50];
																		sprintf(msg, "return %s\n", $2.place);
																		generate(interm_label, msg);
																		interm_label++;
																		printf("Return statement found;\tline no:\t%d\n", yylineno);
																	}
				| PRINTF_ST
    			;

PRINTF_ST:		PRINTF_TOK args SEMICOLON_TOK						{printf("printf statement found;\tline no:\t%d\n", yylineno);}
	  			;

expression:		ID_TOK												{	if(!isPresent($1)) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			$$.dtype = getDatatype($1);
																			$$.place = strdup($1);
																		}
																	}
				| ID_TOK array_ele									{	if(!isPresent($1)) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			$$.dtype = getDatatype($1);
																			$$.place = strdup($1);
																		}
																	}
	   			| INT_CONST_TOK										{	$$.dtype = 1;
				   														char tmp[20];
																		sprintf(tmp, "%d", $1);
																		$$.place = strdup(tmp);
																	}
				| REAL_CONST_TOK									{	$$.dtype = 2;
																		char tmp[20];
																		sprintf(tmp, "%.2f", $1);
																		$$.place = strdup(tmp);
																	}
				| CHAR_CONST_TOK									{	$$.dtype = 4;
																		char tmp[5];
																		sprintf(tmp, "%s", $1);
																		$$.place = strdup(tmp);
																	}
				| STRING_CONST_TOK									{	$$.dtype = 5;
																		char tmp[100];
																		sprintf(tmp, "%s", $1);
																		$$.place = strdup(tmp);
																	}
				| FUNCTION_CALL										{	$$.dtype = $1.dtype;
																		$$.place = strdup($1.place);
																	}
				| LPAREN_TOK expression RPAREN_TOK					{	$$.dtype = $2.dtype;
																		$$.place = strdup($2.place);
																	}
				| expression arith_op expression					{	if($1.dtype != $3.dtype) {
																			char msg[100];
																			sprintf(msg, ": Type matching error in expression");
																			yyerror(msg);
																		}
																		else {
																			char *tmp = new_temp_var();
																			new_tmp_index++;
																			$$.place = strdup(tmp);

																			char msg[50];
																			sprintf(msg, "%s = %s %s %s\n", $$.place, $1.place, $2, $3.place);
																			generate(interm_label, msg);
																			strcpy(expr_var, $$.place);
																			interm_label++;
																		}
																		$$.dtype = $1.dtype;
																	}
				;

arith_op:		PLUS_TOK	{$$ = strdup($1);}										
	 			| MINUS_TOK	{$$ = strdup($1);}
				| MULT_TOK	{$$ = strdup($1);}
				| DIV_TOK	{$$ = strdup($1);}
				| MOD_TOK	{$$ = strdup($1);}
				;

DECLARE_ASSIGN:	datatype varlist
				;

array_ele:		LSQUARE_TOK ID_TOK RSQUARE_TOK						{	if(!isPresent($2)) {
																			char msg[100];
																			sprintf(msg, ": Undeclared identifier found");
																			yyerror(msg);
																		}
																	}
				| LSQUARE_TOK INT_CONST_TOK RSQUARE_TOK
				| LSQUARE_TOK RSQUARE_TOK							{	char msg[100];
																		sprintf(msg, ": Unspecified array element access");
																		yyerror(msg);
																	}
				;

array_size:		LSQUARE_TOK INT_CONST_TOK RSQUARE_TOK
				| LSQUARE_TOK REAL_CONST_TOK RSQUARE_TOK			{	char msg[100];
																		sprintf(msg, ": Incorrect type for array size");
																		yyerror(msg);
																	}
				;

varlist:		ID_TOK												{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
	    		| ID_TOK COMMA_TOK varlist							{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of the identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
				| ID_TOK ASSIGN_TOK expression COMMA_TOK varlist	{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																		if(dtype != $3.dtype) {
																			sprintf(msg, ": Type mismatch between identifier and expression");
																			yyerror(msg);
																		}
																		else {
																			char msg[100];
																			sprintf(msg, "%s = %s\n", $1, $3.place);
																			generate(interm_label, msg);
																			strcpy(expr_var, $1);
																			interm_label++;
																		}
																	}
				| ID_TOK ASSIGN_TOK expression						{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																		if(getDatatype($1) != $3.dtype) {
																			sprintf(msg, ": Type mismatch between identifier and expression");
																			yyerror(msg);
																		}
																		else {
																			char msg[100];
																			sprintf(msg, "%s = %s\n", $1, $3.place);
																			generate(interm_label, msg);
																			strcpy(expr_var, $1);
																			interm_label++;
																		}
																	}
				| ID_TOK array_size COMMA_TOK varlist				{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
				| ID_TOK array_size									{	int c = alreadyDeclared($1);
																		char msg[100];
																		if(c == 1) {
																			sprintf(msg, ": Multiple declarations of identifier in same scope");
																			yyerror(msg);
																		}
																		else if(c == 2) {
																			sprintf(msg, ": Conflicting types for identifier");
																			yyerror(msg);
																		}
																		else {
																			int x = addSymbol($1);
																			if(x == -1) {
																				sprintf(msg, ": Symbol table full");
																				yyerror(msg);
																			}
																		}
																	}
				;

EXP_ASSIGN:		ID_TOK ASSIGN_TOK expression						{	if(!isPresent($1)) {
																			char msg[100];
																			sprintf(msg, ": Undefined identifier found");
																			yyerror(msg);
																		}
																		else {
																			if(getDatatype($1) != $3.dtype) {
																				char msg[100];
																				sprintf(msg, ": Type mismatch between identifier and expression");
																				yyerror(msg);
																			}
																			else {
																				char msg[100];
																				sprintf(msg, "%s = %s\n", $1, $3.place);
																				generate(interm_label, msg);
																				strcpy(expr_var, $1);
																				interm_label++;
																			}
																		}
																	}
				;

IF_ST:			IF_TOK {temp_label = interm_label;}
				open_paren cond_exp close_paren						{	char *tmp = new_temp_var();
																		new_tmp_index++;
																		char msg[50];
																		sprintf(msg, "%s = not %s\n", tmp, expr_var);
																		generate(interm_label, msg);
																		interm_label++;
																		backpatch_label = interm_label;
																		strcpy(tmp_var, tmp);
																		interm_label++;
																	}
    			;

ELSE_PART:		ELSE_TOK 	{	//backpatching
								char msg[50];
								sprintf(msg, "if %s goto %d\n", tmp_var, interm_label+1);
								generate(backpatch_label, msg);
								backpatch_label = interm_label;
								interm_label++;
							}
				block		{	//backpatching
								char msg[50];
								sprintf(msg, "goto %d\n", interm_label);
								generate(backpatch_label, msg);
							}
				;

IF_PART:		IF_ST block
				;

CONDITIONAL:	IF_PART ELSE_PART
	    		| IF_PART	{	//backpatching
								char msg[50];
								sprintf(msg, "if %s goto %d\n", tmp_var, interm_label);
								generate(backpatch_label, msg);
							}
				;

cond_exp:		expression											{	$$.dtype = $1.dtype;
																		$$.place = strdup($1.place);
																	}
				| expression comparison expression					{	if($1.dtype != $3.dtype) {
																			char msg[100];
																			sprintf(msg, ": Type matching error in expression");
																			yyerror(msg);
																		}
																		else {
																			char *tmp = new_temp_var();
																			new_tmp_index++;
																			$$.place = strdup(tmp);

																			char msg[50];
																			sprintf(msg, "%s = %s %s %s\n", $$.place, $1.place, $2, $3.place);
																			generate(interm_label, msg);
																			strcpy(expr_var, $$.place);
																			interm_label++;
																		}
																		$$.dtype = $1.dtype;
																	}
				;

comparison:		GT_TOK		{$$ = strdup($1);}
	   			| LT_TOK	{$$ = strdup($1);}
				| GTE_TOK	{$$ = strdup($1);}
				| LTE_TOK	{$$ = strdup($1);}
				| NEQ_TOK	{$$ = strdup($1);}
				| EQ_TOK	{$$ = strdup($1);}
				| AND_TOK	{$$ = strdup($1);}
	   			| OR_TOK	{$$ = strdup($1);}
				;

WHILE_ST:		WHILE_TOK {temp_label = interm_label;} 
				open_paren cond_exp close_paren			{	
															char *tmp = new_temp_var();
															new_tmp_index++;
															char msg[50];
															sprintf(msg, "%s = not %s\n", tmp, expr_var);
															generate(interm_label, msg);
															interm_label++;
															backpatch_label = interm_label;
															strcpy(tmp_var, tmp);
															interm_label++;
														}
	 			;

ITERATIVE:		WHILE_ST block							{
															char msg[50];
															sprintf(msg, "goto %d\n", temp_label);
															generate(interm_label, msg);
															interm_label++;

															//backpatching
															sprintf(msg, "if %s goto %d\n", tmp_var, interm_label);
															generate(backpatch_label, msg);
														}
				;

FUNCTION_CALL:	ID_TOK args											{	printf("Function call statement found;\tline no:\t%d\n", yylineno);
																		if(!isPresent($1)) {
																			char msg[100];
																			sprintf(msg, ": Undeclared identifier found");
																			yyerror(msg);
																		}
																		else {
																			$$.dtype = getDatatype($1);
																			$$.place = strdup($1);
																		}
																	}
				;

args:			LPAREN_TOK arg RPAREN_TOK
				| LPAREN_TOK RPAREN_TOK
				;

arg:			expression
    			| expression COMMA_TOK arg
				;

%%

void yyerror(char *s) {
	flag = 1;
	printf("\nParsing error at line: %d; Error%s\n\n", yylineno, s);
}

int main() {
	yyin = fopen("test.c", "r");
	out_file = fopen("interm_code.txt", "w");
	initTable();
	if(yyparse() == 0){
		if(flag == 0)
			printf("Parsed Successfully\n");
		else
			printf("Parsing Finished\n");
	}
	else {
		printf("\nSyntax error at line no.: %d\n", yylineno);
		printf("Last read token: %s\n", yytext);
	}
	write_to_file();
	fclose(yyin);
	fclose(out_file);
	out_file = fopen("interm_code.txt", "r");
	assemblyFile = fopen("assembly_code.txt", "w");
	convert();
	fclose(out_file);
	fclose(assemblyFile);
	freeTable();
	printf("All operations completed successfully.\nThe intermediate code can be found in file 'interm_code.txt'.\nThe assembly code can be found in file 'assembly_code.txt'.\n");
	return 0;
}