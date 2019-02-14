/****************************************************************************
*                         A C A D E M I C   C O P Y
* 
* This file was produced by an ACADEMIC COPY of Parser Generator. It is for
* use in non-commercial software only. An ACADEMIC COPY of Parser Generator
* can only be used by a student, or a member of an academic community. If
* however you want to use Parser Generator for commercial purposes then you
* will need to purchase a license. For more information see the online help or
* go to the Bumble-Bee Software homepage at:
* 
* http://www.bumblebeesoftware.com
* 
* This notice must remain present in the file. It cannot be removed.
****************************************************************************/

/****************************************************************************
* lexer.cpp
* C++ source file generated from lexer.l.
* 
* Date: 05/01/11
* Time: 16:41:28
* 
* ALex Version: 2.07
****************************************************************************/

#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\lexer.l"

/****************************************************************************
lexer.l
ParserWizard generated Lex file.

Date: 2011Äê2ÔÂ22ÈÕ
****************************************************************************/


#include "parser.h"


class View_marker;
class program_base;
class Compilor_Lexer;
class Compilor_Parser;



#line 57 "lexer.cpp"
// repeated because of possible precompiled header
#include <yyclex.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\lexer.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYLEXERNAME::YYLEXERNAME()
{
	yytables();
#line 52 ".\\lexer.l"

	// place any extra initialisation code here

#line 81 "lexer.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYLEXERNAME::~YYLEXERNAME()
{
#line 57 ".\\lexer.l"

	// place any extra cleanup code here

#line 93 "lexer.cpp"
}

#ifndef YYTEXT_SIZE
#define YYTEXT_SIZE 100
#endif
#ifndef YYUNPUT_SIZE
#define YYUNPUT_SIZE YYTEXT_SIZE
#endif
#ifndef YYTEXT_MAX
#define YYTEXT_MAX 0
#endif
#ifndef YYUNPUT_MAX
#define YYUNPUT_MAX YYTEXT_MAX
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYLEXERNAME error then you have not declared
* the name of the lexical analyser. The easiest way to do this is to use a
* name declaration. This is placed in the declarations section of your Lex
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the lexer mylexer:
* 
* %name mylexer
* 
* For more information see help.
****************************************************************************/

// backwards compatability with lex
#ifdef input
int YYLEXERNAME::yyinput()
{
	return input();
}
#else
#define input yyinput
#endif

#ifdef output
void YYLEXERNAME::yyoutput(int ch)
{
	output(ch);
}
#else
#define output yyoutput
#endif

#ifdef unput
void YYLEXERNAME::yyunput(int ch)
{
	unput(ch);
}
#else
#define unput yyunput
#endif

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn -rch		// <warning: unreachable code> off
#endif
#endif

int YYLEXERNAME::yyaction(int action)
{
#line 66 ".\\lexer.l"

	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;

#line 164 "lexer.cpp"
	yyreturnflg = yytrue;
	switch (action) {
	case 1:
		{
#line 73 ".\\lexer.l"
v_m->id_name=CString(yytext);					v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			
#line 171 "lexer.cpp"
		}
		break;
	case 2:
		{
#line 74 ".\\lexer.l"
v_m->id_name=_T("0x")+CString(&(yytext[1]));	v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			
#line 178 "lexer.cpp"
		}
		break;
	case 3:
		{
#line 75 ".\\lexer.l"
v_m->id_name=CString(yytext)+_T("0");			v_m->mark(yyleng,1);		return TOKEN_CONST_DOUBLE;		
#line 185 "lexer.cpp"
		}
		break;
	case 4:
		{
#line 77 ".\\lexer.l"
v_m->id_name=_T("1");							v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			
#line 192 "lexer.cpp"
		}
		break;
	case 5:
		{
#line 78 ".\\lexer.l"
v_m->id_name=_T("0");							v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			
#line 199 "lexer.cpp"
		}
		break;
	case 6:
		{
#line 79 ".\\lexer.l"
v_m->id_name=_T("3.1415926535897932");			v_m->mark(yyleng,1);		return TOKEN_CONST_DOUBLE;		
#line 206 "lexer.cpp"
		}
		break;
	case 7:
		{
#line 81 ".\\lexer.l"
												v_m->mark(yyleng,2);		return TOKEN_LEFT_PARENTHESIS;	
#line 213 "lexer.cpp"
		}
		break;
	case 8:
		{
#line 82 ".\\lexer.l"
												v_m->mark(yyleng,2);		return TOKEN_RIGHT_PARENTHESIS;	
#line 220 "lexer.cpp"
		}
		break;
	case 9:
		{
#line 83 ".\\lexer.l"
												v_m->mark(yyleng,2);		return TOKEN_LEFT_SQUARE_BRACKET;
#line 227 "lexer.cpp"
		}
		break;
	case 10:
		{
#line 84 ".\\lexer.l"
												v_m->mark(yyleng,2);		return TOKEN_RIGHT_SQUARE_BRACKET;
#line 234 "lexer.cpp"
		}
		break;
	case 11:
		{
#line 86 ".\\lexer.l"
												v_m->mark(yyleng,3);		return TOKEN_MUL;				
#line 241 "lexer.cpp"
		}
		break;
	case 12:
		{
#line 87 ".\\lexer.l"
												v_m->mark(yyleng,3);		return TOKEN_DIV;				
#line 248 "lexer.cpp"
		}
		break;
	case 13:
		{
#line 88 ".\\lexer.l"
												v_m->mark(yyleng,3);		return TOKEN_ADD;				
#line 255 "lexer.cpp"
		}
		break;
	case 14:
		{
#line 89 ".\\lexer.l"
												v_m->mark(yyleng,3);		return TOKEN_SUB;				
#line 262 "lexer.cpp"
		}
		break;
	case 15:
		{
#line 91 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_EQUAL;				
#line 269 "lexer.cpp"
		}
		break;
	case 16:
		{
#line 92 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_NOT_EQUAL;			
#line 276 "lexer.cpp"
		}
		break;
	case 17:
		{
#line 93 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_GREAT;				
#line 283 "lexer.cpp"
		}
		break;
	case 18:
		{
#line 94 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_GREAT_EQUAL;		
#line 290 "lexer.cpp"
		}
		break;
	case 19:
		{
#line 95 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_LESS;				
#line 297 "lexer.cpp"
		}
		break;
	case 20:
		{
#line 96 ".\\lexer.l"
												v_m->mark(yyleng,4);		return TOKEN_LESS_EQUAL;		
#line 304 "lexer.cpp"
		}
		break;
	case 21:
		{
#line 98 ".\\lexer.l"
												v_m->mark(yyleng,5);		return TOKEN_NOT;				
#line 311 "lexer.cpp"
		}
		break;
	case 22:
		{
#line 99 ".\\lexer.l"
												v_m->mark(yyleng,5);		return TOKEN_AND;				
#line 318 "lexer.cpp"
		}
		break;
	case 23:
		{
#line 100 ".\\lexer.l"
												v_m->mark(yyleng,5);		return TOKEN_OR;				
#line 325 "lexer.cpp"
		}
		break;
	case 24:
		{
#line 101 ".\\lexer.l"
												v_m->mark(yyleng,5);		return TOKEN_XOR;				
#line 332 "lexer.cpp"
		}
		break;
	case 25:
		{
#line 103 ".\\lexer.l"
												v_m->mark(yyleng,6);		return TOKEN_COLON;				
#line 339 "lexer.cpp"
		}
		break;
	case 26:
		{
#line 104 ".\\lexer.l"
												v_m->mark(yyleng,6);		return TOKEN_SEMICOLON;			
#line 346 "lexer.cpp"
		}
		break;
	case 27:
		{
#line 105 ".\\lexer.l"
												v_m->mark(yyleng,6);		return TOKEN_COMMA;				
#line 353 "lexer.cpp"
		}
		break;
	case 28:
		{
#line 107 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_IF;				
#line 360 "lexer.cpp"
		}
		break;
	case 29:
		{
#line 108 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_THEN;				
#line 367 "lexer.cpp"
		}
		break;
	case 30:
		{
#line 109 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_ELSE;				
#line 374 "lexer.cpp"
		}
		break;
	case 31:
		{
#line 110 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_ENDIF;				
#line 381 "lexer.cpp"
		}
		break;
	case 32:
		{
#line 111 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_ELSEIF;			
#line 388 "lexer.cpp"
		}
		break;
	case 33:
		{
#line 112 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_FOR;				
#line 395 "lexer.cpp"
		}
		break;
	case 34:
		{
#line 113 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_TO;				
#line 402 "lexer.cpp"
		}
		break;
	case 35:
		{
#line 114 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_STEP;				
#line 409 "lexer.cpp"
		}
		break;
	case 36:
		{
#line 115 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_NEXT;				
#line 416 "lexer.cpp"
		}
		break;
	case 37:
		{
#line 116 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_REPEAT;			
#line 423 "lexer.cpp"
		}
		break;
	case 38:
		{
#line 117 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_UNTIL;				
#line 430 "lexer.cpp"
		}
		break;
	case 39:
		{
#line 118 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_WHILE_BEGIN;		
#line 437 "lexer.cpp"
		}
		break;
	case 40:
		{
#line 119 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_WHILE_END;			
#line 444 "lexer.cpp"
		}
		break;
	case 41:
		{
#line 120 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_GOTO;				
#line 451 "lexer.cpp"
		}
		break;
	case 42:
		{
#line 121 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_GOSUB;				
#line 458 "lexer.cpp"
		}
		break;
	case 43:
		{
#line 122 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_RETURN;			
#line 465 "lexer.cpp"
		}
		break;
	case 44:
		{
#line 123 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_ON;				
#line 472 "lexer.cpp"
		}
		break;
	case 45:
		{
#line 124 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_BASIC_ERROR;		
#line 479 "lexer.cpp"
		}
		break;
	case 46:
		{
#line 125 ".\\lexer.l"
												v_m->mark(yyleng,7);		return TOKEN_WAIT_UNTIL;		
#line 486 "lexer.cpp"
		}
		break;
	case 47:
		{
#line 127 ".\\lexer.l"
v_m->id_name=_T("wait_idle");												return this->function_process();
#line 493 "lexer.cpp"
		}
		break;
	case 48:
		{
#line 128 ".\\lexer.l"
v_m->id_name=_T("wait_load");												return this->function_process();
#line 500 "lexer.cpp"
		}
		break;
	case 49:
		{
#line 130 ".\\lexer.l"
v_m->id_name=_T("0");							v_m->mark(yyleng,8);		return TOKEN_NUMBER_CHARACTER;	
#line 507 "lexer.cpp"
		}
		break;
	case 50:
		{
#line 131 ".\\lexer.l"
v_m->id_name=_T("1");							v_m->mark(yyleng,8);		return TOKEN_NUMBER_CHARACTER;	
#line 514 "lexer.cpp"
		}
		break;
	case 51:
		{
#line 132 ".\\lexer.l"
v_m->id_name=CString(&(yytext[1]));			v_m->mark(yyleng,9);		return TOKEN_CHANNEL_NUMBER;	
#line 521 "lexer.cpp"
		}
		break;
	case 52:
		{
#line 134 ".\\lexer.l"
v_m->id_name=CString(yytext);												return this->function_process();
#line 528 "lexer.cpp"
		}
		break;
	case 53:
		{
#line 135 ".\\lexer.l"
v_m->id_name=CString(yytext).Mid(1,yyleng-2);	v_m->mark(yyleng,16);		return TOKEN_STRING;			
#line 535 "lexer.cpp"
		}
		break;
#line 136 ".\\lexer.l"
										
#line 540 "lexer.cpp"
	case 54:
		{
#line 137 ".\\lexer.l"
v_m->line_current++;v_m->line_position=0;																	
#line 545 "lexer.cpp"
		}
		break;
	case 55:
		{
#line 139 ".\\lexer.l"
												v_m->mark(yyleng,0);										
#line 552 "lexer.cpp"
		}
		break;
	case 56:
		{
#line 141 ".\\lexer.l"
																											
#line 559 "lexer.cpp"
		}
		break;
	default:
		yyassert(0);
		break;
	}
	yyreturnflg = yyfalse;
	return 0;
}

#ifndef YYNBORLANDWARN
#ifdef __BORLANDC__
#pragma warn .rch		// <warning: unreachable code> to the old state
#endif
#endif

void YYLEXERNAME::yytables()
{
	yystext_size = YYTEXT_SIZE;
	yysunput_size = YYUNPUT_SIZE;
	yytext_max = YYTEXT_MAX;
	yyunput_max = YYUNPUT_MAX;

	static const yymatch_t YYNEARFAR YYBASED_CODE match[] = {
		0
	};
	yymatch = match;

	yytransitionmax = 265;
	static const yytransition_t YYNEARFAR YYBASED_CODE transition[] = {
		{ 0, 0 },
		{ 3, 1 },
		{ 3, 1 },
		{ 55, 29 },
		{ 62, 34 },
		{ 4, 1 },
		{ 0, 5 },
		{ 72, 40 },
		{ 68, 38 },
		{ 0, 5 },
		{ 60, 33 },
		{ 73, 40 },
		{ 63, 34 },
		{ 67, 37 },
		{ 74, 40 },
		{ 69, 38 },
		{ 64, 34 },
		{ 56, 29 },
		{ 70, 38 },
		{ 89, 66 },
		{ 61, 33 },
		{ 46, 19 },
		{ 47, 19 },
		{ 90, 66 },
		{ 3, 1 },
		{ 52, 27 },
		{ 5, 1 },
		{ 6, 1 },
		{ 7, 1 },
		{ 71, 39 },
		{ 42, 5 },
		{ 8, 1 },
		{ 9, 1 },
		{ 10, 1 },
		{ 11, 1 },
		{ 12, 1 },
		{ 13, 1 },
		{ 14, 1 },
		{ 122, 122 },
		{ 15, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 16, 1 },
		{ 17, 1 },
		{ 18, 1 },
		{ 19, 1 },
		{ 20, 1 },
		{ 21, 1 },
		{ 3, 3 },
		{ 3, 3 },
		{ 122, 112 },
		{ 83, 57 },
		{ 84, 57 },
		{ 45, 16 },
		{ 122, 122 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 16, 16 },
		{ 53, 28 },
		{ 0, 8 },
		{ 54, 28 },
		{ 75, 41 },
		{ 48, 21 },
		{ 57, 30 },
		{ 3, 3 },
		{ 58, 31 },
		{ 122, 112 },
		{ 76, 50 },
		{ 77, 51 },
		{ 23, 1 },
		{ 78, 52 },
		{ 24, 1 },
		{ 79, 53 },
		{ 80, 54 },
		{ 81, 55 },
		{ 25, 1 },
		{ 26, 1 },
		{ 27, 1 },
		{ 82, 56 },
		{ 28, 1 },
		{ 29, 1 },
		{ 30, 1 },
		{ 31, 1 },
		{ 32, 1 },
		{ 59, 32 },
		{ 85, 58 },
		{ 86, 60 },
		{ 87, 61 },
		{ 33, 1 },
		{ 34, 1 },
		{ 35, 1 },
		{ 88, 62 },
		{ 36, 1 },
		{ 37, 1 },
		{ 38, 1 },
		{ 39, 1 },
		{ 91, 67 },
		{ 40, 1 },
		{ 41, 1 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 43, 43 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 44, 44 },
		{ 50, 25 },
		{ 128, 122 },
		{ 49, 143 },
		{ 92, 68 },
		{ 129, 122 },
		{ 93, 70 },
		{ 94, 71 },
		{ 95, 72 },
		{ 96, 73 },
		{ 97, 74 },
		{ 98, 75 },
		{ 99, 77 },
		{ 100, 79 },
		{ 130, 122 },
		{ 101, 80 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 102, 81 },
		{ 103, 83 },
		{ 104, 84 },
		{ 105, 86 },
		{ 106, 89 },
		{ 107, 90 },
		{ 108, 91 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 109, 92 },
		{ 110, 93 },
		{ 111, 94 },
		{ 112, 95 },
		{ 113, 96 },
		{ 114, 97 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 22, 143 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 45, 45 },
		{ 115, 99 },
		{ 116, 100 },
		{ 117, 101 },
		{ 88, 102 },
		{ 118, 103 },
		{ 119, 106 },
		{ 120, 107 },
		{ 121, 111 },
		{ 51, 26 },
		{ 123, 114 },
		{ 124, 115 },
		{ 125, 116 },
		{ 126, 119 },
		{ 127, 120 },
		{ 65, 35 },
		{ 131, 124 },
		{ 132, 128 },
		{ 133, 129 },
		{ 134, 130 },
		{ 135, 131 },
		{ 136, 132 },
		{ 137, 133 },
		{ 138, 134 },
		{ 139, 135 },
		{ 140, 136 },
		{ 141, 137 },
		{ 142, 138 },
		{ 143, 139 },
		{ 144, 141 },
		{ 145, 142 },
		{ 66, 36 },
		{ 146, 144 }
	};
	yytransition = transition;

	static const yystate_t YYNEARFAR YYBASED_CODE state[] = {
		{ 0, 0, 0 },
		{ 143, -8, 0 },
		{ 1, 0, 0 },
		{ 0, 46, 56 },
		{ 0, 0, 54 },
		{ -5, -4, 0 },
		{ 43, 0, 0 },
		{ 44, 0, 0 },
		{ -8, 60, 55 },
		{ 0, 0, 7 },
		{ 0, 0, 8 },
		{ 0, 0, 11 },
		{ 0, 0, 13 },
		{ 0, 0, 27 },
		{ 0, 0, 14 },
		{ 0, 0, 12 },
		{ 0, 14, 1 },
		{ 0, 0, 25 },
		{ 0, 0, 26 },
		{ 0, -40, 19 },
		{ 0, 0, 15 },
		{ 0, 15, 17 },
		{ 143, 0, 52 },
		{ 0, 0, 9 },
		{ 0, 0, 10 },
		{ 143, 23, 52 },
		{ 143, 144, 52 },
		{ 143, -79, 52 },
		{ 143, -36, 52 },
		{ 143, -94, 52 },
		{ 143, -34, 52 },
		{ 143, -22, 52 },
		{ 143, -4, 52 },
		{ 143, -91, 52 },
		{ 143, -98, 52 },
		{ 143, 142, 52 },
		{ 143, 162, 52 },
		{ 143, -103, 52 },
		{ 143, -96, 52 },
		{ 143, -81, 52 },
		{ 143, -90, 52 },
		{ 143, -36, 52 },
		{ 0, 0, 53 },
		{ 0, 65, 51 },
		{ 0, 75, 2 },
		{ 0, 175, 3 },
		{ 0, 0, 20 },
		{ 0, 0, 16 },
		{ 0, 0, 18 },
		{ 0, 0, 52 },
		{ 143, -19, 52 },
		{ 143, -33, 52 },
		{ 143, -30, 52 },
		{ 143, -29, 52 },
		{ 143, -13, 52 },
		{ 143, -20, 52 },
		{ 143, -22, 52 },
		{ 143, -57, 52 },
		{ 143, -21, 52 },
		{ 143, 0, 28 },
		{ 143, -20, 52 },
		{ 143, -15, 52 },
		{ 143, 3, 52 },
		{ 143, 0, 44 },
		{ 143, 0, 23 },
		{ 143, 0, 6 },
		{ 143, -93, 52 },
		{ 143, 9, 52 },
		{ 143, 35, 52 },
		{ 143, 0, 34 },
		{ 143, 21, 52 },
		{ 143, 23, 52 },
		{ 143, 35, 52 },
		{ 143, 31, 52 },
		{ 143, 37, 52 },
		{ 143, 29, 52 },
		{ 143, 0, 22 },
		{ 143, 39, 52 },
		{ 143, 0, 49 },
		{ 143, 44, 52 },
		{ 143, 42, 52 },
		{ 143, 43, 52 },
		{ 143, 0, 33 },
		{ 143, 42, 52 },
		{ 143, 49, 52 },
		{ 143, 0, 50 },
		{ 143, 45, 52 },
		{ 143, 0, 21 },
		{ 143, 0, 5 },
		{ 143, 61, 52 },
		{ 143, 46, 52 },
		{ 143, 52, 52 },
		{ 143, 81, 52 },
		{ 143, 91, 52 },
		{ 143, 88, 52 },
		{ 143, 78, 52 },
		{ 143, 95, 52 },
		{ 143, 88, 52 },
		{ 143, 0, 24 },
		{ 143, 134, 52 },
		{ 143, 129, 30 },
		{ 143, 133, 52 },
		{ 143, 135, 52 },
		{ 143, 139, 52 },
		{ 143, 0, 41 },
		{ 143, 0, 36 },
		{ 143, 141, 52 },
		{ 143, 125, 52 },
		{ 143, 0, 35 },
		{ 143, 0, 29 },
		{ 143, 0, 4 },
		{ 143, 132, 52 },
		{ 143, 48, 52 },
		{ 143, 0, 40 },
		{ 143, 141, 52 },
		{ 143, 142, 52 },
		{ 143, 142, 52 },
		{ 143, 0, 31 },
		{ 143, 0, 42 },
		{ 143, 129, 52 },
		{ 143, 136, 52 },
		{ 143, 0, 38 },
		{ 0, 29, 0 },
		{ 143, 0, 39 },
		{ 143, 134, 52 },
		{ 143, 0, 32 },
		{ 143, 0, 37 },
		{ 143, 0, 43 },
		{ 0, 149, 0 },
		{ 0, 139, 0 },
		{ 0, 141, 0 },
		{ 143, 138, 52 },
		{ 0, 145, 0 },
		{ 0, 157, 0 },
		{ 0, 139, 0 },
		{ 143, 145, 52 },
		{ 0, 156, 0 },
		{ 0, 158, 0 },
		{ 0, 154, 0 },
		{ 143, 146, 52 },
		{ 0, 0, 47 },
		{ 0, 160, 0 },
		{ 0, 154, 0 },
		{ 0, 100, 45 },
		{ 0, 164, 0 },
		{ 0, 0, 46 },
		{ 0, 0, 48 }
	};
	yystate = state;

	static const yybackup_t YYNEARFAR YYBASED_CODE backup[] = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0
	};
	yybackup = backup;
}
#line 143 ".\\lexer.l"


/////////////////////////////////////////////////////////////////////////////
// programs section


int Compilor_Lexer::function_process(){
		static function_list	fun_list;
		static output_list		out_list;
		
		if((v_m->function_item=fun_list.search_function(v_m->id_name))!=NULL){
			if((v_m->function_item->min_arg_number>=0)&&(v_m->function_item->max_arg_number>=0)){
				switch(v_m->function_item->type_id){
				default:
				case 0:
					v_m->mark(yyleng,10);
					return TOKEN_INTEGER_FUNCTION_NAME;
				case 1:
					v_m->mark(yyleng,11);
					return TOKEN_DOUBLE_FUNCTION_NAME;
				case 2:
					v_m->mark(yyleng,12);
					return TOKEN_MODIFY_NAME;
				}
			}else{
				v_m->mark(yyleng,13);
				return TOKEN_INPUT_NAME;			
			}
		}
		{
			output_list_item *p;
			if((p=out_list.search_command(v_m->id_name))!=NULL){		
				v_m->output_item=p;
				v_m->mark(yyleng,14);
				return TOKEN_OUTPUT_NAME;
			}
		}
		v_m->mark(yyleng,15);
		return TOKEN_IDENTIFICATION;
}	


