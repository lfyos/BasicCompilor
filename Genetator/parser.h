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
* parser.h
* C++ header file generated from parser.y.
* 
* Date: 05/11/11
* Time: 02:41:24
* 
* AYACC Version: 2.07
****************************************************************************/

#ifndef _PARSER_H
#define _PARSER_H

#include <yycpars.h>

/////////////////////////////////////////////////////////////////////////////
// Compilor_Parser

#ifndef YYEXPPARSER
#define YYEXPPARSER
#endif

class YYEXPPARSER YYFAR Compilor_Parser : public _YL yyfparser {
public:
	Compilor_Parser();
	virtual ~Compilor_Parser();

protected:
	void yytables();
	virtual void yyaction(int action);
#ifdef YYDEBUG
	void YYFAR* yyattribute1(int index) const;
	void yyinitdebug(void YYFAR** p, int count) const;
#endif

	// attribute functions
	virtual void yystacktoval(int index);
	virtual void yyvaltostack(int index);
	virtual void yylvaltoval();
	virtual void yyvaltolval();
	virtual void yylvaltostack(int index);

	virtual void YYFAR* yynewattribute(int count);
	virtual void yydeleteattribute(void YYFAR* attribute);
	virtual void yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count);

public:
#line 25 ".\\parser.y"

	// place any extra class members here
	View_marker *v_m;
	program_base *input_function;
	program_base *output_function;

#line 71 "parser.h"
};

#ifndef YYPARSERNAME
#define YYPARSERNAME Compilor_Parser
#endif

#line 43 ".\\parser.y"

#ifndef YYSTYPE
#define YYSTYPE program_base*
#endif

#line 84 "parser.h"
#define TOKEN_IF 257
#define TOKEN_THEN 258
#define TOKEN_ELSE 259
#define TOKEN_ELSEIF 260
#define TOKEN_ENDIF 261
#define TOKEN_FOR 262
#define TOKEN_TO 263
#define TOKEN_STEP 264
#define TOKEN_NEXT 265
#define TOKEN_REPEAT 266
#define TOKEN_UNTIL 267
#define TOKEN_WHILE_BEGIN 268
#define TOKEN_WHILE_END 269
#define TOKEN_WAIT_UNTIL 270
#define TOKEN_ON 271
#define TOKEN_GOTO 272
#define TOKEN_GOSUB 273
#define TOKEN_BASIC_ERROR 274
#define TOKEN_RETURN 275
#define TOKEN_COLON 276
#define TOKEN_SEMICOLON 277
#define TOKEN_COMMA 278
#define TOKEN_OR 279
#define TOKEN_XOR 280
#define TOKEN_AND 281
#define TOKEN_NOT 282
#define TOKEN_EQUAL 283
#define TOKEN_NOT_EQUAL 284
#define TOKEN_GREAT 285
#define TOKEN_GREAT_EQUAL 286
#define TOKEN_LESS 287
#define TOKEN_LESS_EQUAL 288
#define TOKEN_ADD 289
#define TOKEN_SUB 290
#define TOKEN_MUL 291
#define TOKEN_DIV 292
#define TOKEN_RIGHT_SQUARE_BRACKET 293
#define TOKEN_LEFT_SQUARE_BRACKET 294
#define TOKEN_RIGHT_PARENTHESIS 295
#define TOKEN_LEFT_PARENTHESIS 296
#define TOKEN_NUMBER_CHARACTER 297
#define TOKEN_CHANNEL_NUMBER 298
#define TOKEN_IDENTIFICATION 299
#define TOKEN_INTEGER_FUNCTION_NAME 300
#define TOKEN_DOUBLE_FUNCTION_NAME 301
#define TOKEN_MODIFY_NAME 302
#define TOKEN_OUTPUT_NAME 303
#define TOKEN_INPUT_NAME 304
#define TOKEN_CONST_INT 305
#define TOKEN_CONST_DOUBLE 306
#define TOKEN_STRING 307
#endif
