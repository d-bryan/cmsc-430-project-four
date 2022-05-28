/*******************************************************************************
 File: types.h
 Author: Dylan Bryan
 Date: 8/9/21, 8:40 PM
 Project: project-four
 Purpose: This file contains type definitions and the function prototypes
 for the type checking functions
 ******************************************************************************/

typedef char* CharPtr;

enum Types {MISMATCH, INT_TYPE, BOOL_TYPE, REAL_TYPE};

void checkAssignment(Types lValue, Types rValue, string message);
void checkIf(Types ifCheck, Types statement1, Types statement2);
void checkCase(Types caseCheck);
void checkCases(Types lValue, Types rValue, string message);
Types checkRemainder(Types left, Types right);
Types checkArithmetic(Types left, Types right);
Types checkLogical(Types left, Types right);
Types checkRelational(Types left, Types right);