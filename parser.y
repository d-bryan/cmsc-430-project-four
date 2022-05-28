/*
 File: parser.y
 Author: Dylan Bryan
 Date: 8/9/21, 8:33 PM
 Project: project-four
 Purpose: Define Parse tree grammar
 and syntactic analyzer
*/

%{
#include <string>
#include <vector>
#include <map>

using namespace std;

#include "types.h"
#include "listing.h"
#include "symbols.h"

int yylex();
void yyerror(const char* message);

Symbols<Types> symbols;

%}

%error-verbose

%union
{
	CharPtr iden;
	Types type;
}

%token <iden> IDENTIFIER
%token <type> INT_LITERAL REAL_LITERAL BOOL_LITERAL

%token ADDOP MULOP RELOP REMOP EXPOP ANDOP OROP ARROWOP

%token BEGIN_ BOOLEAN CASE ELSE END ENDCASE ENDIF ENDREDUCE FUNCTION INTEGER
%token IF IS NOT OTHERS REAL REDUCE RETURNS THEN WHEN

%type <type> type statement statement_ reductions expression expression2 relation relation2 relation3 term factor primary cases case case2

%%

function:
	function_header_ variables2 body ;

function_header_:
	function_header |
	error ';' ;

function_header:
	FUNCTION IDENTIFIER parameters RETURNS type ';' ;

parameters:
	parameter optional_parameter ;

optional_parameter:
	',' parameter |
	;

parameter:
	IDENTIFIER ':' type ;

variables2:
	variables optional_variable ;

variables:
	variable optional_variable |
	error ';' ;

optional_variable:
	variable |
	;

variable:
	IDENTIFIER ':' type IS statement_
		{checkAssignment($3, $5, "Variable Initialization");
		symbols.findDuplicate($1, $3);
		symbols.insert($1, $3);} ;

type:
	INTEGER {$$ = INT_TYPE;} |
	REAL {$$ = REAL_TYPE;} |
	BOOLEAN {$$ = BOOL_TYPE;} ;

body:
	BEGIN_ statement_ END ';' ;

statement_:
	statement ';' |
	error ';' {$$ = MISMATCH;} ;

statement:
	expression |
	REDUCE operator reductions ENDREDUCE {$$ = $3;} |
	IF expression THEN statement_ ELSE statement_ ENDIF {checkIf($2, $4, $6);} |
	CASE expression IS cases OTHERS ARROWOP statement_ ENDCASE {checkCase($2);} ;

operator:
	ADDOP |
	MULOP ;

reductions:
	reductions statement_ {$$ = checkArithmetic($1, $2);} |
	{$$ = INT_TYPE;} ;

cases:
	case case2 {checkCases($1, $2, "Case");} ;

case:
	WHEN INT_LITERAL ARROWOP expression ';' {$$ = $4;} ;

case2:
	WHEN INT_LITERAL ARROWOP expression ';' {$$ = $4;} ;

expression:
	expression ANDOP expression2 {$$ = checkLogical($1, $3);} |
	expression2 ;

expression2:
	expression2 OROP relation {$$ = checkLogical($1, $3);}  |
	relation ;

relation:
	relation RELOP relation2 {$$ = checkRelational($1, $3);}|
	relation2 ;

relation2:
	relation2 REMOP relation3 {$$ = checkRemainder($1, $3);} |
	relation3 ;

relation3:
	relation3 EXPOP term {$$ = checkArithmetic($1, $3);} |
	term ;

term:
	term ADDOP factor {$$ = checkArithmetic($1, $3);} |
	factor ;

factor:
	factor MULOP primary  {$$ = checkArithmetic($1, $3);} |
	primary ;

primary:
	'(' expression ')' {$$ = $2;} |
	NOT expression {$$ = $2;} |
	INT_LITERAL |
	REAL_LITERAL |
	BOOL_LITERAL |
	IDENTIFIER {if (!symbols.find($1, $$)) appendError(UNDECLARED, $1);} ;
    
%%

void yyerror(const char* message)
{
	appendError(SYNTAX, message);
}

int main(int argc, char *argv[])    
{
	firstLine();
	yyparse();
	lastLine();
	return 0;
} 
