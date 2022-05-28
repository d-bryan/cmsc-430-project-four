/*******************************************************************************
 File: listing.cc
 Author: Dylan Bryan
 Date: 8/9/21, 8:33 PM
 Project: project-four
 Purpose: This file contains the bodies of the functions that produces
 the compilation listing
 ******************************************************************************/

#include <cstdio>
#include <string>

using namespace std;

#include "listing.h"

static int lineNumber;
static string error = "";
static int totalErrors = 0;
static int lexicalErrors = 0;
static int syntaxErrors = 0;
static int semanticErrors = 0;

static void displayErrors();

void firstLine()
{
    lineNumber = 1;
    printf("\n%4d  ",lineNumber);
}

void nextLine()
{
    displayErrors();
    lineNumber++;
    printf("%4d  ",lineNumber);
}

int lastLine()
{
    printf("\r");
    displayErrors();
    printf("     \n");
    printf("Total Number of Errors: %i \n", totalErrors);
    if (totalErrors == 0)
        printf("Compiled Successfully\n");
    printf("Lexical Errors: %i \n", lexicalErrors);
    printf("Syntax Errors: %i \n", syntaxErrors );
    printf("Semantic Errors: %i \n", semanticErrors);
    return totalErrors;
}

void appendError(ErrorCategories errorCategory, string message)
{
    string messages[] = { "Lexical Error, Invalid Character ", "",
                          "Semantic Error, ", "Semantic Error, Duplicate Identifier: ",
                          "Semantic Error, Undeclared " };

    if(errorCategory == LEXICAL)
        lexicalErrors++;
    if(errorCategory == SYNTAX)
        syntaxErrors++;
    if(errorCategory == GENERAL_SEMANTIC)
        semanticErrors++;
    error += messages[errorCategory] + message;
    totalErrors++;
}

void displayErrors()
{
    if (error != "")
        printf("%s\n", error.c_str());
    error = "";
}
