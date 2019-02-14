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
* lexer.h
* C++ header file generated from lexer.l.
* 
* Date: 05/01/11
* Time: 16:41:28
* 
* ALex Version: 2.07
****************************************************************************/

#ifndef _LEXER_H
#define _LEXER_H

#include <yyclex.h>

/////////////////////////////////////////////////////////////////////////////
// Compilor_Lexer

#ifndef YYEXPLEXER
#define YYEXPLEXER
#endif

class YYEXPLEXER YYFAR Compilor_Lexer : public _YL yyflexer {
public:
	Compilor_Lexer();
	virtual ~Compilor_Lexer();

	// backards compatibility with lex
#ifdef input
	virtual int yyinput();
#endif
#ifdef output
	virtual void yyoutput(int ch);
#endif
#ifdef unput
	virtual void yyunput(int ch);
#endif

protected:
	void yytables();
	virtual int yyaction(int action);

public:
#line 28 ".\\lexer.l"

	// place any extra class members here

	View_marker *v_m;
	
	
	virtual int yyinput()
	{
		return v_m->yyinput();
	}
	virtual void yyunput(int ch)
	{
		v_m->yyunput(ch);
	}
	int yywrap()
	{
		return 1;
	}
	
	int function_process();
	

#line 83 "lexer.h"
};

#ifndef YYLEXERNAME
#define YYLEXERNAME Compilor_Lexer
#endif

#ifndef INITIAL
#define INITIAL 0
#endif

#endif
