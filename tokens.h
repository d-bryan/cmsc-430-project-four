/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT_LITERAL = 259,
     REAL_LITERAL = 260,
     BOOL_LITERAL = 261,
     ADDOP = 262,
     MULOP = 263,
     RELOP = 264,
     REMOP = 265,
     EXPOP = 266,
     ANDOP = 267,
     OROP = 268,
     ARROWOP = 269,
     BEGIN_ = 270,
     BOOLEAN = 271,
     CASE = 272,
     ELSE = 273,
     END = 274,
     ENDCASE = 275,
     ENDIF = 276,
     ENDREDUCE = 277,
     FUNCTION = 278,
     INTEGER = 279,
     IF = 280,
     IS = 281,
     NOT = 282,
     OTHERS = 283,
     REAL = 284,
     REDUCE = 285,
     RETURNS = 286,
     THEN = 287,
     WHEN = 288
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_LITERAL 259
#define REAL_LITERAL 260
#define BOOL_LITERAL 261
#define ADDOP 262
#define MULOP 263
#define RELOP 264
#define REMOP 265
#define EXPOP 266
#define ANDOP 267
#define OROP 268
#define ARROWOP 269
#define BEGIN_ 270
#define BOOLEAN 271
#define CASE 272
#define ELSE 273
#define END 274
#define ENDCASE 275
#define ENDIF 276
#define ENDREDUCE 277
#define FUNCTION 278
#define INTEGER 279
#define IF 280
#define IS 281
#define NOT 282
#define OTHERS 283
#define REAL 284
#define REDUCE 285
#define RETURNS 286
#define THEN 287
#define WHEN 288




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 31 "parser.y"
{
	CharPtr iden;
	Types type;
}
/* Line 1529 of yacc.c.  */
#line 120 "parser.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

