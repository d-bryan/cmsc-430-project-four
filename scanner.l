/*
 File: scanner.l
 Author: Dylan Bryan
 Date: 8/9/21, 8:33 PM
 Project: project-four
 Purpose: This file contains flex input file
*/

%{
#include <string>

using namespace std;

#include "types.h"
#include "listing.h"
#include "tokens.h"

%}

%option noyywrap

ws		[ \t\r]+
comment		\-\-.*\n
comment2	\/\/.*\n
line		[\n]
id		[A-Za-z][A-Za-z0-9]*
digit		[0-9]
int		{digit}+
punc		[\(\),:;]
real		([0-9]+)(\.?[0-9]+)([eE][-+]?[0-9]+)?
bool		true|false
%%

{ws}		{ ECHO; }
{comment}	{ ECHO; nextLine();}
{comment2}	{ ECHO; nextLine();}
{real}		{ ECHO; return(REAL_LITERAL);}
{bool}		{ ECHO; return(BOOL_LITERAL);}
{line}		{ ECHO; nextLine();}
"<"		{ ECHO; return(RELOP); }
">"		{ ECHO;  return(RELOP); }
"="		{ ECHO; return(RELOP); }
"/="		{ ECHO; return(RELOP); }
"<="		{ ECHO; return(RELOP); }
">="		{ ECHO; return(RELOP); }
"+"		{ ECHO; return(ADDOP); }
"-"		{ ECHO; return(ADDOP); }
"*"		{ ECHO; return(MULOP); }
"/"		{ ECHO; return(MULOP); }
begin		{ ECHO; return(BEGIN_); }
boolean		{ ECHO; return(BOOLEAN); }
end		{ ECHO; return(END); }
endreduce	{ ECHO; return(ENDREDUCE); }
function	{ ECHO; return(FUNCTION); }
integer		{ ECHO; return(INTEGER); }
is		{ ECHO; return(IS); }
reduce		{ ECHO; return(REDUCE); }
returns		{ ECHO; return(RETURNS); }
case		{ ECHO; return(CASE); }
else		{ ECHO; return(ELSE); }
endcase		{ ECHO; return(ENDCASE); }
endif		{ ECHO; return(ENDIF); }
if		{ ECHO; return(IF); }
others		{ ECHO; return(OTHERS); }
real		{ ECHO; return(REAL); }
then		{ ECHO; return(THEN); }
when		{ ECHO; return(WHEN); }
and		{ ECHO; return(ANDOP); }
or		{ ECHO; return(OROP); }
rem		{ ECHO; return(REMOP); }
"**"		{ ECHO; return(EXPOP); }
"=>"		{ ECHO; return(ARROWOP); }
{id}		{ ECHO; yylval.iden = (CharPtr)malloc(yyleng + 1); strcpy(yylval.iden, yytext); return(IDENTIFIER);}
{int}		{ ECHO; yylval.type = INT_TYPE; return(INT_LITERAL); }
{punc}		{ ECHO; return(yytext[0]); }
.		{ ECHO; appendError(LEXICAL, yytext); }

%%

