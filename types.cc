/*******************************************************************************
 File: types.cc
 Author: Dylan Bryan
 Date: 8/9/21, 8:40 PM
 Project: project-four
 Purpose: This file contains the bodies of the type checking functions
 ******************************************************************************/

#include <string>
#include <vector>

using namespace std;

#include "types.h"
#include "listing.h"

void checkAssignment(Types lValue, Types rValue, string message)
{
    if (lValue != MISMATCH && rValue != MISMATCH)
    {
        if (lValue == INT_TYPE && rValue == BOOL_TYPE)
            appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
        if (lValue == REAL_TYPE && rValue == BOOL_TYPE)
            appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
        if (lValue == BOOL_TYPE && rValue == INT_TYPE)
            appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
        if (lValue == BOOL_TYPE && rValue == REAL_TYPE)
            appendError(GENERAL_SEMANTIC, "Type Mismatch on " + message);
    }
}

void checkIf(Types ifCheck, Types statement1, Types statement2)
{
    if (ifCheck != BOOL_TYPE)
        appendError(GENERAL_SEMANTIC, "If Expression Must Be Boolean");
    if (statement1 != statement2)
        appendError(GENERAL_SEMANTIC, "Type Mismatch on Then Statements");
}

void checkCase(Types caseCheck)
{
    if (caseCheck != INT_TYPE)
        appendError(GENERAL_SEMANTIC, "Case Expression Must Be Integer");
}

void checkCases(Types lValue, Types rValue, string message)
{
    if (lValue != rValue)
        appendError(GENERAL_SEMANTIC, "Case Expressions Must Match");
}

Types checkRemainder(Types left, Types right)
{
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    if (left != INT_TYPE || right != INT_TYPE)
    {
        appendError(GENERAL_SEMANTIC, "Integer Type Required");
        return MISMATCH;
    }
    return INT_TYPE;
}

Types checkArithmetic(Types left, Types right)
{
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    if (left == BOOL_TYPE || right == BOOL_TYPE)
    {
        appendError(GENERAL_SEMANTIC, "Numeric Type Required");
        return MISMATCH;
    }
    if (left == INT_TYPE || right == INT_TYPE)
        return INT_TYPE;
    return REAL_TYPE;
}


Types checkLogical(Types left, Types right)
{
    if (left == MISMATCH || right == MISMATCH)
        return MISMATCH;
    if (left != BOOL_TYPE || right != BOOL_TYPE)
    {
        appendError(GENERAL_SEMANTIC, "Boolean Type Required");
        return MISMATCH;
    }
    return BOOL_TYPE;
    return MISMATCH;
}

Types checkRelational(Types left, Types right)
{
    if (checkArithmetic(left, right) == MISMATCH)
        return MISMATCH;
    return BOOL_TYPE;
}