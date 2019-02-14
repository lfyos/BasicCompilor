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
* parser.cpp
* C++ source file generated from parser.y.
* 
* Date: 05/11/11
* Time: 02:41:24
* 
* AYACC Version: 2.07
****************************************************************************/

#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#line 1 ".\\parser.y"

/****************************************************************************
parser.y
ParserWizard generated YACC file.

Date: 2011年2月22日
****************************************************************************/

#include "lexer.h"

class View_marker;
class program_base;
class Compilor_Lexer;
class Compilor_Parser;


#line 54 "parser.cpp"
// repeated because of possible precompiled header
#include <yycpars.h>

// namespaces
#ifdef YYSTDCPPLIB
using namespace std;
#endif
#ifdef YYNAMESPACE
using namespace yl;
#endif

#include ".\parser.h"

/////////////////////////////////////////////////////////////////////////////
// constructor

YYPARSERNAME::YYPARSERNAME()
{
	yytables();
#line 33 ".\\parser.y"

	// place any extra initialisation code here

#line 78 "parser.cpp"
}

/////////////////////////////////////////////////////////////////////////////
// destructor

YYPARSERNAME::~YYPARSERNAME()
{
	// allows virtual functions to be called properly for correct cleanup
	yydestroy();
#line 38 ".\\parser.y"

	// place any extra cleanup code here

#line 92 "parser.cpp"
}

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#ifndef YYSTACK_SIZE
#define YYSTACK_SIZE 100
#endif
#ifndef YYSTACK_MAX
#define YYSTACK_MAX 0
#endif

/****************************************************************************
* N O T E
* 
* If the compiler generates a YYPARSERNAME error then you have not declared
* the name of the parser. The easiest way to do this is to use a name
* declaration. This is placed in the declarations section of your YACC
* source file and is introduced with the %name keyword. For instance, the
* following name declaration declares the parser myparser:
* 
* %name myparser
* 
* For more information see help.
****************************************************************************/

// yyattribute
#ifdef YYDEBUG
void YYFAR* YYPARSERNAME::yyattribute1(int index) const
{
	YYSTYPE YYFAR* p = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + index];
	return p;
}
#define yyattribute(index) (*(YYSTYPE YYFAR*)yyattribute1(index))
#else
#define yyattribute(index) (((YYSTYPE YYFAR*)yyattributestackptr)[yytop + (index)])
#endif

void YYPARSERNAME::yystacktoval(int index)
{
	yyassert(index >= 0);
	*(YYSTYPE YYFAR*)yyvalptr = ((YYSTYPE YYFAR*)yyattributestackptr)[index];
}

void YYPARSERNAME::yyvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltoval()
{
	*(YYSTYPE YYFAR*)yyvalptr = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYPARSERNAME::yyvaltolval()
{
	*(YYSTYPE YYFAR*)yylvalptr = *(YYSTYPE YYFAR*)yyvalptr;
}

void YYPARSERNAME::yylvaltostack(int index)
{
	yyassert(index >= 0);
	((YYSTYPE YYFAR*)yyattributestackptr)[index] = *(YYSTYPE YYFAR*)yylvalptr;
}

void YYFAR* YYPARSERNAME::yynewattribute(int count)
{
	yyassert(count >= 0);
	return new YYFAR YYSTYPE[count];
}

void YYPARSERNAME::yydeleteattribute(void YYFAR* attribute)
{
	delete[] (YYSTYPE YYFAR*)attribute;
}

void YYPARSERNAME::yycopyattribute(void YYFAR* dest, const void YYFAR* src, int count)
{
	for (int i = 0; i < count; i++) {
		((YYSTYPE YYFAR*)dest)[i] = ((YYSTYPE YYFAR*)src)[i];
	}
}

#ifdef YYDEBUG
void YYPARSERNAME::yyinitdebug(void YYFAR** p, int count) const
{
	yyassert(p != NULL);
	yyassert(count >= 1);

	YYSTYPE YYFAR** p1 = (YYSTYPE YYFAR**)p;
	for (int i = 0; i < count; i++) {
		p1[i] = &((YYSTYPE YYFAR*)yyattributestackptr)[yytop + i - (count - 1)];
	}
}
#endif

void YYPARSERNAME::yyaction(int action)
{
	switch (action) {
	case 0:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 88 ".\\parser.y"

									variable_declare_program *p;
									variable_label_head_string head_str;
									CString str;
									
									str =_T("\n\nvoid basic_run_function(struct ");
									str+=head_str.variable_struct_name+_T(" *");
									str+=head_str.variable_pointer_name+_T(")\n{");
									str+=_T("\n	register int accumlator_integer=0;");
									str+=_T("\n	register double accumlator_double=0;\n");
									str+=_T("\n	memset(")+(head_str.variable_pointer_name)+_T(",0,sizeof(*")+(head_str.variable_pointer_name)+_T("));\n");

									v_m->execute_object_program=str+((yyattribute(1 - 1))->create_list_program(1))+_T("\n}\n");	
																	
									p=new variable_declare_program(v_m);
									v_m->execute_object_program		+=p->create_set_get_program();
																		
									v_m->var_declare_object_program	 =p->create_declare_program();
								
#line 220 "parser.cpp"
			}
		}
		break;
	case 1:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 108 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 233 "parser.cpp"
			}
		}
		break;
	case 2:
		{
#line 109 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 241 "parser.cpp"
		}
		break;
	case 3:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 111 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 253 "parser.cpp"
			}
		}
		break;
	case 4:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 112 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 2))->link_next(yyattribute(2 - 2));
#line 266 "parser.cpp"
			}
		}
		break;
	case 5:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 114 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new let_sentence_program(v_m,yyattribute(1 - 3),yyattribute(3 - 3));
#line 279 "parser.cpp"
			}
		}
		break;
	case 6:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 115 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new label_defination_program(v_m,yyattribute(1 - 2));
#line 292 "parser.cpp"
			}
		}
		break;
	case 7:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 116 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2))->output_error_message_at_end(_T("标识符 ")+(yyattribute(1 - 2))->id_name+_T(" 后面应紧跟等号（= 赋值语句) 或 冒号（: 标号定义语句)"));
#line 305 "parser.cpp"
			}
		}
		break;
	case 8:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 118 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new in_out_program(v_m,yyattribute(1 - 2),yyattribute(2 - 2));
#line 318 "parser.cpp"
			}
		}
		break;
	case 9:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 120 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 2)),yyattribute(2 - 2),NULL,NULL);
#line 331 "parser.cpp"
			}
		}
		break;
	case 10:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 121 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 3)),yyattribute(2 - 3),NULL,yyattribute(3 - 3)  );
#line 344 "parser.cpp"
			}
		}
		break;
	case 11:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 122 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 4)),yyattribute(2 - 4),yyattribute(4 - 4),  NULL);
#line 357 "parser.cpp"
			}
		}
		break;
	case 12:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[6];
			yyinitdebug((void YYFAR**)yya, 6);
#endif
			{
#line 123 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 5)),yyattribute(2 - 5),yyattribute(5 - 5),  yyattribute(3 - 5)  );
#line 370 "parser.cpp"
			}
		}
		break;
	case 13:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 125 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new in_out_program(v_m,yyattribute(1 - 2),yyattribute(2 - 2));
#line 383 "parser.cpp"
			}
		}
		break;
	case 14:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 127 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new if_then_else_program(v_m,yyattribute(1 - 3),yyattribute(2 - 3),NULL);
#line 396 "parser.cpp"
			}
		}
		break;
	case 15:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 128 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new if_then_else_program(v_m,yyattribute(1 - 4),yyattribute(2 - 4),yyattribute(3 - 4));
#line 409 "parser.cpp"
			}
		}
		break;
	case 16:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 130 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new for_next_program(v_m,yyattribute(1 - 6),yyattribute(2 - 6),yyattribute(3 - 6),yyattribute(4 - 6),yyattribute(5 - 6),yyattribute(6 - 6));
#line 422 "parser.cpp"
			}
		}
		break;
	case 17:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 131 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new repeat_until_program(v_m,yyattribute(1 - 4),yyattribute(2 - 4),yyattribute(4 - 4));
#line 435 "parser.cpp"
			}
		}
		break;
	case 18:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 132 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new while_program(v_m,yyattribute(1 - 4),yyattribute(3 - 4),yyattribute(2 - 4));
#line 448 "parser.cpp"
			}
		}
		break;
	case 19:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 133 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new repeat_until_program(v_m,yyattribute(1 - 2),NULL,yyattribute(2 - 2));
#line 461 "parser.cpp"
			}
		}
		break;
	case 20:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 135 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new goto_program(v_m,yyattribute(1 - 2),yyattribute(2 - 2));
#line 474 "parser.cpp"
			}
		}
		break;
	case 21:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 136 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2))->output_error_message_at_end(_T("goto 后面应紧跟标号"));
#line 487 "parser.cpp"
			}
		}
		break;
	case 22:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 137 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new gosub_program(v_m,yyattribute(1 - 2),yyattribute(2 - 2));
#line 500 "parser.cpp"
			}
		}
		break;
	case 23:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 138 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2))->output_error_message_at_end(_T("gosub 后面应紧跟标号"));
#line 513 "parser.cpp"
			}
		}
		break;
	case 24:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 140 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new on_goto_program(v_m,yyattribute(1 - 4),yyattribute(2 - 4),yyattribute(4 - 4));
#line 526 "parser.cpp"
			}
		}
		break;
	case 25:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 141 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4))->output_error_message_at_end(_T("on goto 语句 goto 后面的标号列表错误"));	
#line 539 "parser.cpp"
			}
		}
		break;
	case 26:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 142 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new on_gosub_program(v_m,yyattribute(1 - 4),yyattribute(2 - 4),yyattribute(4 - 4));
#line 552 "parser.cpp"
			}
		}
		break;
	case 27:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 143 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4))->output_error_message_at_end(_T("on gosub 语句gosub后面的标号列表错误"));
#line 565 "parser.cpp"
			}
		}
		break;
	case 28:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 144 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3))->output_error_message_at_end(_T("on语句算数表达式后面应紧跟goto 或 gosub"));
#line 578 "parser.cpp"
			}
		}
		break;
	case 29:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 146 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new on_error_goto_program(v_m,yyattribute(1 - 4),yyattribute(4 - 4));
#line 591 "parser.cpp"
			}
		}
		break;
	case 30:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 147 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4))->output_error_message_at_end(_T("on basicerror goto 语句gosub后面的标号列表错误"));
#line 604 "parser.cpp"
			}
		}
		break;
	case 31:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 148 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new on_error_gosub_program(v_m,yyattribute(1 - 4),yyattribute(4 - 4));
#line 617 "parser.cpp"
			}
		}
		break;
	case 32:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 149 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4))->output_error_message_at_end(_T("on basicerror gosub 语句gosub后面的标号列表错误"));
#line 630 "parser.cpp"
			}
		}
		break;
	case 33:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 150 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3))->output_error_message_at_end(_T("on basicerror语句后面应紧跟goto 或 gosub"));
#line 643 "parser.cpp"
			}
		}
		break;
	case 34:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 151 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new return_program(v_m);
#line 656 "parser.cpp"
			}
		}
		break;
	case 35:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 152 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m))->output_error_message_at_end(_T("编译器发现语法错误"));
#line 669 "parser.cpp"
			}
		}
		break;
	case 36:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 154 ".\\parser.y"
 output_function=new output_name_program(v_m);(*(YYSTYPE YYFAR*)yyvalptr)=output_function;
#line 682 "parser.cpp"
			}
		}
		break;
	case 37:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 155 ".\\parser.y"
((output_name_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2)))->channel_name=(yyattribute(2 - 2))->id_name;
#line 695 "parser.cpp"
			}
		}
		break;
	case 38:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 156 ".\\parser.y"
((output_name_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3)))->channel_name=(yyattribute(2 - 3))->id_name;
#line 708 "parser.cpp"
			}
		}
		break;
	case 39:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 158 ".\\parser.y"
 input_function=new input_name_program(v_m);(*(YYSTYPE YYFAR*)yyvalptr)=input_function;
#line 721 "parser.cpp"
			}
		}
		break;
	case 40:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 159 ".\\parser.y"
(( input_name_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2)))->channel_name=(yyattribute(2 - 2))->id_name;
#line 734 "parser.cpp"
			}
		}
		break;
	case 41:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 160 ".\\parser.y"
(( input_name_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3)))->channel_name=(yyattribute(2 - 3))->id_name;
#line 747 "parser.cpp"
			}
		}
		break;
	case 42:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 162 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 760 "parser.cpp"
			}
		}
		break;
	case 43:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 163 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 3))->link_next(yyattribute(3 - 3));
#line 773 "parser.cpp"
			}
		}
		break;
	case 44:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 165 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new let_sentence_program(v_m,yyattribute(1 - 1),input_function))->set_begin(input_function);
#line 786 "parser.cpp"
			}
		}
		break;
	case 45:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 166 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 2)),yyattribute(2 - 2),input_function,NULL))->set_begin(input_function);
#line 799 "parser.cpp"
			}
		}
		break;
	case 46:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 167 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 3)),yyattribute(2 - 3),input_function,yyattribute(3 - 3)  ))->set_begin(input_function);
#line 812 "parser.cpp"
			}
		}
		break;
	case 47:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 169 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 825 "parser.cpp"
			}
		}
		break;
	case 48:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 170 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 3))->link_next(yyattribute(3 - 3));((output_program *)((yyattribute(3 - 3))->front_pointer))->set_end_flag(1);
#line 838 "parser.cpp"
			}
		}
		break;
	case 49:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 171 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 3))->link_next(yyattribute(3 - 3));((output_program *)((yyattribute(3 - 3))->front_pointer))->set_end_flag(2);
#line 851 "parser.cpp"
			}
		}
		break;
	case 50:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 173 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 864 "parser.cpp"
			}
		}
		break;
	case 51:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 174 ".\\parser.y"
 ((output_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4)))->set_format(yyattribute(3 - 4),NULL);
#line 877 "parser.cpp"
			}
		}
		break;
	case 52:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 175 ".\\parser.y"
 ((output_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 6)))->set_format(yyattribute(3 - 6),yyattribute(5 - 6)  );
#line 890 "parser.cpp"
			}
		}
		break;
	case 53:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 176 ".\\parser.y"
 ((output_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 4)))->set_format(yyattribute(3 - 4),NULL);	(yyattribute(3 - 4))->output_error_message(_T("第一个格式表达式后应紧跟逗号或右中括号"));
#line 903 "parser.cpp"
			}
		}
		break;
	case 54:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[7];
			yyinitdebug((void YYFAR**)yya, 7);
#endif
			{
#line 177 ".\\parser.y"
 ((output_program *)((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 6)))->set_format(yyattribute(3 - 6),yyattribute(5 - 6));	(yyattribute(5 - 6))->output_error_message(_T("第二个格式表达式后应紧跟右中括号"));
#line 916 "parser.cpp"
			}
		}
		break;
	case 55:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 179 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new output_string_program(v_m,(output_name_program *)output_function);
#line 929 "parser.cpp"
			}
		}
		break;
	case 56:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 180 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new output_value_program (v_m,(output_name_program *)output_function,yyattribute(1 - 1));
#line 942 "parser.cpp"
			}
		}
		break;
	case 57:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 181 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new output_number_string_program(v_m,(output_name_program *)output_function,yyattribute(3 - 4),(yyattribute(1 - 4))->id_name);
#line 955 "parser.cpp"
			}
		}
		break;
	case 58:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 182 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new output_number_string_program(v_m,(output_name_program *)output_function,NULL,(yyattribute(1 - 2))->id_name))->output_error_message_at_end(_T("此处应为左括号"));
#line 968 "parser.cpp"
			}
		}
		break;
	case 59:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[5];
			yyinitdebug((void YYFAR**)yya, 5);
#endif
			{
#line 183 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new output_number_string_program(v_m,(output_name_program *)output_function,yyattribute(3 - 4),(yyattribute(1 - 4))->id_name  ))->output_error_message_at_end(_T("只有左括号，缺少右括号，左右括号不匹配"));
#line 981 "parser.cpp"
			}
		}
		break;
	case 60:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 185 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 2)),yyattribute(2 - 2),NULL,NULL);
#line 994 "parser.cpp"
			}
		}
		break;
	case 61:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 186 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 3))->link_next(new function_call_program(v_m,(function_name_program *)(yyattribute(2 - 3)),yyattribute(3 - 3),NULL,NULL));
#line 1007 "parser.cpp"
			}
		}
		break;
	case 62:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 188 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2))->set_begin(yyattribute(1 - 2));
#line 1020 "parser.cpp"
			}
		}
		break;
	case 63:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 189 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 2))->output_error_message_at_end(_T("for 后面应该紧跟变量名"));
#line 1033 "parser.cpp"
			}
		}
		break;
	case 64:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 191 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
#line 1046 "parser.cpp"
			}
		}
		break;
	case 65:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 192 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("此处应为等号="));
#line 1059 "parser.cpp"
			}
		}
		break;
	case 66:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 194 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
#line 1072 "parser.cpp"
			}
		}
		break;
	case 67:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 195 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("此处应为 to "));
#line 1085 "parser.cpp"
			}
		}
		break;
	case 68:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 197 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
#line 1098 "parser.cpp"
			}
		}
		break;
	case 69:
		{
#line 198 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,_T("1"),0);
#line 1106 "parser.cpp"
		}
		break;
	case 70:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 200 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
#line 1118 "parser.cpp"
			}
		}
		break;
	case 71:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 201 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m))->output_error_message_at_end(_T("next后面的变量名错误"));
#line 1131 "parser.cpp"
			}
		}
		break;
	case 72:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 203 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3))->set_begin(yyattribute(1 - 3));
#line 1144 "parser.cpp"
			}
		}
		break;
	case 73:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 204 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3))->set_begin(yyattribute(1 - 3))->output_error_message_at_end(_T("if <表达式> 后面应接then"));
#line 1157 "parser.cpp"
			}
		}
		break;
	case 74:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 206 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 2);
#line 1170 "parser.cpp"
			}
		}
		break;
	case 75:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 207 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new if_then_else_program(v_m,yyattribute(1 - 2),yyattribute(2 - 2),NULL);
#line 1183 "parser.cpp"
			}
		}
		break;
	case 76:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 208 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new if_then_else_program(v_m,yyattribute(1 - 3),yyattribute(2 - 3),yyattribute(3 - 3));
#line 1196 "parser.cpp"
			}
		}
		break;
	case 77:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 210 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 1209 "parser.cpp"
			}
		}
		break;
	case 78:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 211 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3))->output_error_message_at_end(_T("elseif <表达式> 后面应接then"));
#line 1222 "parser.cpp"
			}
		}
		break;
	case 79:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 213 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,v_m->id_name,0);
#line 1235 "parser.cpp"
			}
		}
		break;
	case 80:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 214 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,v_m->id_name,1);
#line 1248 "parser.cpp"
			}
		}
		break;
	case 81:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 215 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,_T("1"),0);
#line 1261 "parser.cpp"
			}
		}
		break;
	case 82:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 217 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,(yyattribute(1 - 1))->id_name,(yyattribute(1 - 1))->type_id,variable_label_head_string().variable_pointer_name+_T("->")))->register_variable();
#line 1274 "parser.cpp"
			}
		}
		break;
	case 83:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 219 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 2)),yyattribute(2 - 2),NULL,NULL);
#line 1287 "parser.cpp"
			}
		}
		break;
	case 84:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 220 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_call_program(v_m,(function_name_program *)(yyattribute(1 - 3)),yyattribute(2 - 3),NULL,yyattribute(3 - 3)  );
#line 1300 "parser.cpp"
			}
		}
		break;
	case 85:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 222 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new add_sub_mul_div_program(v_m,_T("+"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1313 "parser.cpp"
			}
		}
		break;
	case 86:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 223 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new add_sub_mul_div_program(v_m,_T("-"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1326 "parser.cpp"
			}
		}
		break;
	case 87:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 224 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new add_sub_mul_div_program(v_m,_T("*"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1339 "parser.cpp"
			}
		}
		break;
	case 88:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 225 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new add_sub_mul_div_program(v_m,_T("/"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1352 "parser.cpp"
			}
		}
		break;
	case 89:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 227 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 1365 "parser.cpp"
			}
		}
		break;
	case 90:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 228 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new add_sub_mul_div_program(v_m,_T("-"),yyattribute(2 - 2));
#line 1378 "parser.cpp"
			}
		}
		break;
	case 91:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 229 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("识别表达式时发现语法错误"));
#line 1391 "parser.cpp"
			}
		}
		break;
	case 92:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 231 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("=="),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1404 "parser.cpp"
			}
		}
		break;
	case 93:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 232 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("!="),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1417 "parser.cpp"
			}
		}
		break;
	case 94:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 233 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T(">" ),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1430 "parser.cpp"
			}
		}
		break;
	case 95:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 234 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T(">="),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1443 "parser.cpp"
			}
		}
		break;
	case 96:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 235 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("<" ),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1456 "parser.cpp"
			}
		}
		break;
	case 97:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 236 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("<="),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1469 "parser.cpp"
			}
		}
		break;
	case 98:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 237 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("=="),yyattribute(1 - 2)))->output_error_message_at_end(_T("识别关系表达式时发现关系算符错误"));
#line 1482 "parser.cpp"
			}
		}
		break;
	case 99:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 239 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1495 "parser.cpp"
			}
		}
		break;
	case 100:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 240 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("&"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1508 "parser.cpp"
			}
		}
		break;
	case 101:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 241 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("|"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1521 "parser.cpp"
			}
		}
		break;
	case 102:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 242 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("^"),yyattribute(1 - 3),yyattribute(3 - 3));
#line 1534 "parser.cpp"
			}
		}
		break;
	case 103:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 244 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new relative_logic_program(v_m,_T("=="),yyattribute(2 - 2));
#line 1547 "parser.cpp"
			}
		}
		break;
	case 104:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 245 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);
#line 1560 "parser.cpp"
			}
		}
		break;
	case 105:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 246 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3))->output_error_message_at_end(_T("识别逻辑表达式时发现左右括号不对应"));
#line 1573 "parser.cpp"
			}
		}
		break;
	case 106:
		{
#line 248 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
#line 1581 "parser.cpp"
		}
		break;
	case 107:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[3];
			yyinitdebug((void YYFAR**)yya, 3);
#endif
			{
#line 249 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=NULL;
#line 1593 "parser.cpp"
			}
		}
		break;
	case 108:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 250 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3);  
#line 1606 "parser.cpp"
			}
		}
		break;
	case 109:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 251 ".\\parser.y"
((*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(2 - 3))->output_error_message_at_end(_T("参数表左右括号不匹配"));
#line 1619 "parser.cpp"
			}
		}
		break;
	case 110:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 253 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1632 "parser.cpp"
			}
		}
		break;
	case 111:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 254 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 3))->link_next(yyattribute(3 - 3));
#line 1645 "parser.cpp"
			}
		}
		break;
	case 112:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 256 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=yyattribute(1 - 1);
#line 1658 "parser.cpp"
			}
		}
		break;
	case 113:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[4];
			yyinitdebug((void YYFAR**)yya, 4);
#endif
			{
#line 257 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=(yyattribute(1 - 3))->link_next(yyattribute(3 - 3));
#line 1671 "parser.cpp"
			}
		}
		break;
	case 114:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 259 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new identification_program(v_m);
#line 1684 "parser.cpp"
			}
		}
		break;
	case 115:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 261 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_name_program(v_m);
#line 1697 "parser.cpp"
			}
		}
		break;
	case 116:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 262 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_name_program(v_m);
#line 1710 "parser.cpp"
			}
		}
		break;
	case 117:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 264 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new function_name_program(v_m);
#line 1723 "parser.cpp"
			}
		}
		break;
	case 118:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 266 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1736 "parser.cpp"
			}
		}
		break;
	case 119:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 268 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1749 "parser.cpp"
			}
		}
		break;
	case 120:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 270 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1762 "parser.cpp"
			}
		}
		break;
	case 121:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 272 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1775 "parser.cpp"
			}
		}
		break;
	case 122:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 274 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1788 "parser.cpp"
			}
		}
		break;
	case 123:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 276 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1801 "parser.cpp"
			}
		}
		break;
	case 124:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 278 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1814 "parser.cpp"
			}
		}
		break;
	case 125:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 280 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1827 "parser.cpp"
			}
		}
		break;
	case 126:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 282 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1840 "parser.cpp"
			}
		}
		break;
	case 127:
		{
#ifdef YYDEBUG
			YYSTYPE YYFAR* yya[2];
			yyinitdebug((void YYFAR**)yya, 2);
#endif
			{
#line 284 ".\\parser.y"
 (*(YYSTYPE YYFAR*)yyvalptr)=new program_base(v_m);
#line 1853 "parser.cpp"
			}
		}
		break;
	default:
		yyassert(0);
		break;
	}
}

void YYPARSERNAME::yytables()
{
	yyattribute_size = sizeof(YYSTYPE);
	yysstack_size = YYSTACK_SIZE;
	yystack_max = YYSTACK_MAX;

#ifdef YYDEBUG
	static const yysymbol_t YYNEARFAR YYBASED_CODE symbol[] = {
		{ "$end", 0 },
		{ "error", 256 },
		{ "TOKEN_IF", 257 },
		{ "TOKEN_THEN", 258 },
		{ "TOKEN_ELSE", 259 },
		{ "TOKEN_ELSEIF", 260 },
		{ "TOKEN_ENDIF", 261 },
		{ "TOKEN_FOR", 262 },
		{ "TOKEN_TO", 263 },
		{ "TOKEN_STEP", 264 },
		{ "TOKEN_NEXT", 265 },
		{ "TOKEN_REPEAT", 266 },
		{ "TOKEN_UNTIL", 267 },
		{ "TOKEN_WHILE_BEGIN", 268 },
		{ "TOKEN_WHILE_END", 269 },
		{ "TOKEN_WAIT_UNTIL", 270 },
		{ "TOKEN_ON", 271 },
		{ "TOKEN_GOTO", 272 },
		{ "TOKEN_GOSUB", 273 },
		{ "TOKEN_BASIC_ERROR", 274 },
		{ "TOKEN_RETURN", 275 },
		{ "TOKEN_COLON", 276 },
		{ "TOKEN_SEMICOLON", 277 },
		{ "TOKEN_COMMA", 278 },
		{ "TOKEN_OR", 279 },
		{ "TOKEN_XOR", 280 },
		{ "TOKEN_AND", 281 },
		{ "TOKEN_NOT", 282 },
		{ "TOKEN_EQUAL", 283 },
		{ "TOKEN_NOT_EQUAL", 284 },
		{ "TOKEN_GREAT", 285 },
		{ "TOKEN_GREAT_EQUAL", 286 },
		{ "TOKEN_LESS", 287 },
		{ "TOKEN_LESS_EQUAL", 288 },
		{ "TOKEN_ADD", 289 },
		{ "TOKEN_SUB", 290 },
		{ "TOKEN_MUL", 291 },
		{ "TOKEN_DIV", 292 },
		{ "TOKEN_RIGHT_SQUARE_BRACKET", 293 },
		{ "TOKEN_LEFT_SQUARE_BRACKET", 294 },
		{ "TOKEN_RIGHT_PARENTHESIS", 295 },
		{ "TOKEN_LEFT_PARENTHESIS", 296 },
		{ "TOKEN_NUMBER_CHARACTER", 297 },
		{ "TOKEN_CHANNEL_NUMBER", 298 },
		{ "TOKEN_IDENTIFICATION", 299 },
		{ "TOKEN_INTEGER_FUNCTION_NAME", 300 },
		{ "TOKEN_DOUBLE_FUNCTION_NAME", 301 },
		{ "TOKEN_MODIFY_NAME", 302 },
		{ "TOKEN_OUTPUT_NAME", 303 },
		{ "TOKEN_INPUT_NAME", 304 },
		{ "TOKEN_CONST_INT", 305 },
		{ "TOKEN_CONST_DOUBLE", 306 },
		{ "TOKEN_STRING", 307 },
		{ NULL, 0 }
	};
	yysymbol = symbol;

	static const char* const YYNEARFAR YYBASED_CODE rule[] = {
		"$accept: whole_program",
		"whole_program: sentence_list",
		"sentence_list: not_empty_sentence_list",
		"sentence_list:",
		"not_empty_sentence_list: sentence",
		"not_empty_sentence_list: not_empty_sentence_list sentence",
		"sentence: identification TOKEN_EQUAL arith_expr",
		"sentence: identification TOKEN_COLON",
		"sentence: identification error",
		"sentence: input_keyword input_list",
		"sentence: function parenthese_expr",
		"sentence: function parenthese_expr modifier_list",
		"sentence: function parenthese_expr TOKEN_EQUAL arith_expr",
		"sentence: function parenthese_expr modifier_list TOKEN_EQUAL arith_expr",
		"sentence: output_keyword output_list",
		"sentence: if_sentence sentence_list TOKEN_ENDIF",
		"sentence: if_sentence sentence_list else_sentence TOKEN_ENDIF",
		"sentence: for_head for_1 for_2 for_3 sentence_list for_tail",
		"sentence: repeat_keyword sentence_list TOKEN_UNTIL logic_expr",
		"sentence: while_begin_keyword logic_expr sentence_list TOKEN_WHILE_END",
		"sentence: wait_until_keyword logic_expr",
		"sentence: goto_keyword identification",
		"sentence: goto_keyword error",
		"sentence: gosub_keyword identification",
		"sentence: gosub_keyword error",
		"sentence: on_keyword arith_expr TOKEN_GOTO identification_list",
		"sentence: on_keyword arith_expr TOKEN_GOTO error",
		"sentence: on_keyword arith_expr TOKEN_GOSUB identification_list",
		"sentence: on_keyword arith_expr TOKEN_GOSUB error",
		"sentence: on_keyword arith_expr error",
		"sentence: on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO identification",
		"sentence: on_keyword TOKEN_BASIC_ERROR TOKEN_GOTO error",
		"sentence: on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB identification",
		"sentence: on_keyword TOKEN_BASIC_ERROR TOKEN_GOSUB error",
		"sentence: on_keyword TOKEN_BASIC_ERROR error",
		"sentence: TOKEN_RETURN",
		"sentence: error",
		"output_keyword: TOKEN_OUTPUT_NAME",
		"output_keyword: output_keyword channel_number_keyword",
		"output_keyword: output_keyword channel_number_keyword TOKEN_COMMA",
		"input_keyword: TOKEN_INPUT_NAME",
		"input_keyword: input_keyword channel_number_keyword",
		"input_keyword: input_keyword channel_number_keyword TOKEN_COMMA",
		"input_list: input_item",
		"input_list: input_list TOKEN_COMMA input_item",
		"input_item: identification",
		"input_item: function parenthese_expr",
		"input_item: function parenthese_expr modifier_list",
		"output_list: output_format",
		"output_list: output_list TOKEN_COMMA output_format",
		"output_list: output_list TOKEN_SEMICOLON output_format",
		"output_format: output_item",
		"output_format: output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_RIGHT_SQUARE_BRACKET",
		"output_format: output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr TOKEN_RIGHT_SQUARE_BRACKET",
		"output_format: output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr error",
		"output_format: output_item TOKEN_LEFT_SQUARE_BRACKET arith_expr TOKEN_COMMA arith_expr error",
		"output_item: TOKEN_STRING",
		"output_item: arith_expr",
		"output_item: number_string TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS",
		"output_item: number_string error",
		"output_item: number_string TOKEN_LEFT_PARENTHESIS arith_expr error",
		"modifier_list: modifier parenthese_expr",
		"modifier_list: modifier_list modifier parenthese_expr",
		"for_head: for_keyword identification",
		"for_head: for_keyword error",
		"for_1: TOKEN_EQUAL arith_expr",
		"for_1: error",
		"for_2: TOKEN_TO arith_expr",
		"for_2: error",
		"for_3: TOKEN_STEP arith_expr",
		"for_3:",
		"for_tail: TOKEN_NEXT identification",
		"for_tail: TOKEN_NEXT error",
		"if_sentence: if_keyword logic_expr TOKEN_THEN",
		"if_sentence: if_keyword logic_expr error",
		"else_sentence: TOKEN_ELSE sentence_list",
		"else_sentence: else_sub_sentence sentence_list",
		"else_sentence: else_sub_sentence sentence_list else_sentence",
		"else_sub_sentence: TOKEN_ELSEIF logic_expr TOKEN_THEN",
		"else_sub_sentence: TOKEN_ELSEIF logic_expr error",
		"arith_expr: TOKEN_CONST_INT",
		"arith_expr: TOKEN_CONST_DOUBLE",
		"arith_expr: TOKEN_ON",
		"arith_expr: identification",
		"arith_expr: function parenthese_expr",
		"arith_expr: function parenthese_expr modifier_list",
		"arith_expr: arith_expr TOKEN_ADD arith_expr",
		"arith_expr: arith_expr TOKEN_SUB arith_expr",
		"arith_expr: arith_expr TOKEN_MUL arith_expr",
		"arith_expr: arith_expr TOKEN_DIV arith_expr",
		"arith_expr: TOKEN_LEFT_PARENTHESIS arith_expr TOKEN_RIGHT_PARENTHESIS",
		"arith_expr: TOKEN_SUB arith_expr",
		"arith_expr: error",
		"relative_expr: arith_expr TOKEN_EQUAL arith_expr",
		"relative_expr: arith_expr TOKEN_NOT_EQUAL arith_expr",
		"relative_expr: arith_expr TOKEN_GREAT arith_expr",
		"relative_expr: arith_expr TOKEN_GREAT_EQUAL arith_expr",
		"relative_expr: arith_expr TOKEN_LESS arith_expr",
		"relative_expr: arith_expr TOKEN_LESS_EQUAL arith_expr",
		"relative_expr: arith_expr error",
		"logic_expr: relative_expr",
		"logic_expr: logic_expr TOKEN_AND logic_expr",
		"logic_expr: logic_expr TOKEN_OR logic_expr",
		"logic_expr: logic_expr TOKEN_XOR logic_expr",
		"logic_expr: TOKEN_NOT logic_expr",
		"logic_expr: TOKEN_LEFT_PARENTHESIS logic_expr TOKEN_RIGHT_PARENTHESIS",
		"logic_expr: TOKEN_LEFT_PARENTHESIS logic_expr error",
		"parenthese_expr:",
		"parenthese_expr: TOKEN_LEFT_PARENTHESIS TOKEN_RIGHT_PARENTHESIS",
		"parenthese_expr: TOKEN_LEFT_PARENTHESIS arith_expr_list TOKEN_RIGHT_PARENTHESIS",
		"parenthese_expr: TOKEN_LEFT_PARENTHESIS arith_expr_list error",
		"arith_expr_list: arith_expr",
		"arith_expr_list: arith_expr_list TOKEN_COMMA arith_expr",
		"identification_list: identification",
		"identification_list: identification_list TOKEN_COMMA identification",
		"identification: TOKEN_IDENTIFICATION",
		"function: TOKEN_INTEGER_FUNCTION_NAME",
		"function: TOKEN_DOUBLE_FUNCTION_NAME",
		"modifier: TOKEN_MODIFY_NAME",
		"repeat_keyword: TOKEN_REPEAT",
		"while_begin_keyword: TOKEN_WHILE_BEGIN",
		"wait_until_keyword: TOKEN_WAIT_UNTIL",
		"gosub_keyword: TOKEN_GOSUB",
		"goto_keyword: TOKEN_GOTO",
		"on_keyword: TOKEN_ON",
		"for_keyword: TOKEN_FOR",
		"if_keyword: TOKEN_IF",
		"number_string: TOKEN_NUMBER_CHARACTER",
		"channel_number_keyword: TOKEN_CHANNEL_NUMBER"
	};
	yyrule = rule;
#endif

	static const yyreduction_t YYNEARFAR YYBASED_CODE reduction[] = {
		{ 0, 1, -1 },
		{ 1, 1, 0 },
		{ 2, 1, 1 },
		{ 2, 0, 2 },
		{ 3, 1, 3 },
		{ 3, 2, 4 },
		{ 4, 3, 5 },
		{ 4, 2, 6 },
		{ 4, 2, 7 },
		{ 4, 2, 8 },
		{ 4, 2, 9 },
		{ 4, 3, 10 },
		{ 4, 4, 11 },
		{ 4, 5, 12 },
		{ 4, 2, 13 },
		{ 4, 3, 14 },
		{ 4, 4, 15 },
		{ 4, 6, 16 },
		{ 4, 4, 17 },
		{ 4, 4, 18 },
		{ 4, 2, 19 },
		{ 4, 2, 20 },
		{ 4, 2, 21 },
		{ 4, 2, 22 },
		{ 4, 2, 23 },
		{ 4, 4, 24 },
		{ 4, 4, 25 },
		{ 4, 4, 26 },
		{ 4, 4, 27 },
		{ 4, 3, 28 },
		{ 4, 4, 29 },
		{ 4, 4, 30 },
		{ 4, 4, 31 },
		{ 4, 4, 32 },
		{ 4, 3, 33 },
		{ 4, 1, 34 },
		{ 4, 1, 35 },
		{ 5, 1, 36 },
		{ 5, 2, 37 },
		{ 5, 3, 38 },
		{ 6, 1, 39 },
		{ 6, 2, 40 },
		{ 6, 3, 41 },
		{ 7, 1, 42 },
		{ 7, 3, 43 },
		{ 8, 1, 44 },
		{ 8, 2, 45 },
		{ 8, 3, 46 },
		{ 9, 1, 47 },
		{ 9, 3, 48 },
		{ 9, 3, 49 },
		{ 10, 1, 50 },
		{ 10, 4, 51 },
		{ 10, 6, 52 },
		{ 10, 4, 53 },
		{ 10, 6, 54 },
		{ 11, 1, 55 },
		{ 11, 1, 56 },
		{ 11, 4, 57 },
		{ 11, 2, 58 },
		{ 11, 4, 59 },
		{ 12, 2, 60 },
		{ 12, 3, 61 },
		{ 13, 2, 62 },
		{ 13, 2, 63 },
		{ 14, 2, 64 },
		{ 14, 1, 65 },
		{ 15, 2, 66 },
		{ 15, 1, 67 },
		{ 16, 2, 68 },
		{ 16, 0, 69 },
		{ 17, 2, 70 },
		{ 17, 2, 71 },
		{ 18, 3, 72 },
		{ 18, 3, 73 },
		{ 19, 2, 74 },
		{ 19, 2, 75 },
		{ 19, 3, 76 },
		{ 20, 3, 77 },
		{ 20, 3, 78 },
		{ 21, 1, 79 },
		{ 21, 1, 80 },
		{ 21, 1, 81 },
		{ 21, 1, 82 },
		{ 21, 2, 83 },
		{ 21, 3, 84 },
		{ 21, 3, 85 },
		{ 21, 3, 86 },
		{ 21, 3, 87 },
		{ 21, 3, 88 },
		{ 21, 3, 89 },
		{ 21, 2, 90 },
		{ 21, 1, 91 },
		{ 22, 3, 92 },
		{ 22, 3, 93 },
		{ 22, 3, 94 },
		{ 22, 3, 95 },
		{ 22, 3, 96 },
		{ 22, 3, 97 },
		{ 22, 2, 98 },
		{ 23, 1, 99 },
		{ 23, 3, 100 },
		{ 23, 3, 101 },
		{ 23, 3, 102 },
		{ 23, 2, 103 },
		{ 23, 3, 104 },
		{ 23, 3, 105 },
		{ 24, 0, 106 },
		{ 24, 2, 107 },
		{ 24, 3, 108 },
		{ 24, 3, 109 },
		{ 25, 1, 110 },
		{ 25, 3, 111 },
		{ 26, 1, 112 },
		{ 26, 3, 113 },
		{ 27, 1, 114 },
		{ 28, 1, 115 },
		{ 28, 1, 116 },
		{ 29, 1, 117 },
		{ 30, 1, 118 },
		{ 31, 1, 119 },
		{ 32, 1, 120 },
		{ 33, 1, 121 },
		{ 34, 1, 122 },
		{ 35, 1, 123 },
		{ 36, 1, 124 },
		{ 37, 1, 125 },
		{ 38, 1, 126 },
		{ 39, 1, 127 }
	};
	yyreduction = reduction;

	yytokenaction_size = 306;

	static const yytokenaction_t YYNEARFAR YYBASED_CODE tokenaction[] = {
		{ 70, YYAT_SHIFT, 1 },
		{ 70, YYAT_SHIFT, 2 },
		{ 20, YYAT_SHIFT, 35 },
		{ 118, YYAT_SHIFT, 165 },
		{ 25, YYAT_SHIFT, 63 },
		{ 118, YYAT_ERROR, 0 },
		{ 70, YYAT_SHIFT, 3 },
		{ 201, YYAT_SHIFT, 206 },
		{ 101, YYAT_SHIFT, 50 },
		{ 61, YYAT_SHIFT, 104 },
		{ 70, YYAT_SHIFT, 4 },
		{ 77, YYAT_SHIFT, 130 },
		{ 70, YYAT_SHIFT, 5 },
		{ 199, YYAT_SHIFT, 11 },
		{ 70, YYAT_SHIFT, 6 },
		{ 70, YYAT_SHIFT, 7 },
		{ 70, YYAT_SHIFT, 8 },
		{ 70, YYAT_SHIFT, 9 },
		{ 101, YYAT_SHIFT, 53 },
		{ 70, YYAT_SHIFT, 10 },
		{ 163, YYAT_SHIFT, 1 },
		{ 163, YYAT_SHIFT, 2 },
		{ 20, YYAT_SHIFT, 36 },
		{ 70, YYAT_SHIFT, 126 },
		{ 70, YYAT_SHIFT, 127 },
		{ 70, YYAT_SHIFT, 128 },
		{ 163, YYAT_SHIFT, 3 },
		{ 77, YYAT_SHIFT, 131 },
		{ 77, YYAT_SHIFT, 132 },
		{ 20, YYAT_SHIFT, 37 },
		{ 163, YYAT_SHIFT, 4 },
		{ 25, YYAT_SHIFT, 64 },
		{ 163, YYAT_SHIFT, 5 },
		{ 198, YYAT_SHIFT, 201 },
		{ 163, YYAT_SHIFT, 6 },
		{ 163, YYAT_SHIFT, 7 },
		{ 163, YYAT_SHIFT, 8 },
		{ 163, YYAT_SHIFT, 9 },
		{ 185, YYAT_SHIFT, 199 },
		{ 163, YYAT_SHIFT, 10 },
		{ 110, YYAT_SHIFT, 1 },
		{ 110, YYAT_SHIFT, 2 },
		{ 118, YYAT_SHIFT, 166 },
		{ 70, YYAT_SHIFT, 11 },
		{ 70, YYAT_SHIFT, 12 },
		{ 70, YYAT_SHIFT, 13 },
		{ 110, YYAT_SHIFT, 3 },
		{ 70, YYAT_SHIFT, 14 },
		{ 70, YYAT_SHIFT, 15 },
		{ 61, YYAT_SHIFT, 105 },
		{ 110, YYAT_SHIFT, 4 },
		{ 65, YYAT_SHIFT, 112 },
		{ 110, YYAT_SHIFT, 5 },
		{ 183, YYAT_SHIFT, 199 },
		{ 110, YYAT_SHIFT, 6 },
		{ 110, YYAT_SHIFT, 7 },
		{ 110, YYAT_SHIFT, 8 },
		{ 110, YYAT_SHIFT, 9 },
		{ 65, YYAT_SHIFT, 113 },
		{ 110, YYAT_SHIFT, 10 },
		{ 106, YYAT_SHIFT, 1 },
		{ 106, YYAT_SHIFT, 2 },
		{ 174, YYAT_SHIFT, 128 },
		{ 163, YYAT_SHIFT, 11 },
		{ 163, YYAT_SHIFT, 12 },
		{ 163, YYAT_SHIFT, 13 },
		{ 106, YYAT_SHIFT, 3 },
		{ 163, YYAT_SHIFT, 14 },
		{ 163, YYAT_SHIFT, 15 },
		{ 81, YYAT_SHIFT, 136 },
		{ 106, YYAT_SHIFT, 4 },
		{ 81, YYAT_SHIFT, 137 },
		{ 106, YYAT_SHIFT, 5 },
		{ 152, YYAT_SHIFT, 90 },
		{ 106, YYAT_SHIFT, 6 },
		{ 106, YYAT_SHIFT, 7 },
		{ 106, YYAT_SHIFT, 8 },
		{ 106, YYAT_SHIFT, 9 },
		{ 145, YYAT_SHIFT, 44 },
		{ 106, YYAT_SHIFT, 10 },
		{ 26, YYAT_SHIFT, 1 },
		{ 26, YYAT_SHIFT, 2 },
		{ 139, YYAT_SHIFT, 90 },
		{ 110, YYAT_SHIFT, 11 },
		{ 110, YYAT_SHIFT, 12 },
		{ 110, YYAT_SHIFT, 13 },
		{ 26, YYAT_SHIFT, 3 },
		{ 110, YYAT_SHIFT, 14 },
		{ 110, YYAT_SHIFT, 15 },
		{ 135, YYAT_SHIFT, 184 },
		{ 26, YYAT_SHIFT, 4 },
		{ 134, YYAT_SHIFT, 181 },
		{ 26, YYAT_SHIFT, 5 },
		{ 132, YYAT_SHIFT, 179 },
		{ 26, YYAT_SHIFT, 6 },
		{ 26, YYAT_SHIFT, 7 },
		{ 26, YYAT_SHIFT, 8 },
		{ 26, YYAT_SHIFT, 9 },
		{ 131, YYAT_SHIFT, 177 },
		{ 26, YYAT_SHIFT, 10 },
		{ 24, YYAT_SHIFT, 1 },
		{ 24, YYAT_SHIFT, 2 },
		{ 129, YYAT_SHIFT, 176 },
		{ 106, YYAT_SHIFT, 11 },
		{ 106, YYAT_SHIFT, 12 },
		{ 106, YYAT_SHIFT, 13 },
		{ 24, YYAT_SHIFT, 3 },
		{ 106, YYAT_SHIFT, 14 },
		{ 106, YYAT_SHIFT, 15 },
		{ 114, YYAT_SHIFT, 162 },
		{ 24, YYAT_SHIFT, 4 },
		{ 109, YYAT_SHIFT, 159 },
		{ 24, YYAT_SHIFT, 5 },
		{ 99, YYAT_SHIFT, 90 },
		{ 24, YYAT_SHIFT, 6 },
		{ 24, YYAT_SHIFT, 7 },
		{ 24, YYAT_SHIFT, 8 },
		{ 24, YYAT_SHIFT, 9 },
		{ 92, YYAT_SHIFT, 44 },
		{ 24, YYAT_SHIFT, 10 },
		{ 18, YYAT_SHIFT, 1 },
		{ 18, YYAT_SHIFT, 2 },
		{ 94, YYAT_ERROR, 0 },
		{ 26, YYAT_SHIFT, 11 },
		{ 26, YYAT_SHIFT, 12 },
		{ 26, YYAT_SHIFT, 13 },
		{ 18, YYAT_SHIFT, 3 },
		{ 26, YYAT_SHIFT, 14 },
		{ 26, YYAT_SHIFT, 15 },
		{ 155, YYAT_SHIFT, 189 },
		{ 18, YYAT_SHIFT, 4 },
		{ 84, YYAT_SHIFT, 90 },
		{ 18, YYAT_SHIFT, 5 },
		{ 69, YYAT_ERROR, 0 },
		{ 18, YYAT_SHIFT, 6 },
		{ 18, YYAT_SHIFT, 7 },
		{ 18, YYAT_SHIFT, 8 },
		{ 18, YYAT_SHIFT, 9 },
		{ 66, YYAT_SHIFT, 115 },
		{ 18, YYAT_SHIFT, 10 },
		{ 0, YYAT_SHIFT, 1 },
		{ 0, YYAT_SHIFT, 2 },
		{ 60, YYAT_SHIFT, 103 },
		{ 24, YYAT_SHIFT, 11 },
		{ 24, YYAT_SHIFT, 12 },
		{ 24, YYAT_SHIFT, 13 },
		{ 0, YYAT_SHIFT, 3 },
		{ 24, YYAT_SHIFT, 14 },
		{ 24, YYAT_SHIFT, 15 },
		{ 117, YYAT_SHIFT, 119 },
		{ 0, YYAT_SHIFT, 4 },
		{ 155, YYAT_SHIFT, 190 },
		{ 0, YYAT_SHIFT, 5 },
		{ 78, YYAT_SHIFT, 133 },
		{ 0, YYAT_SHIFT, 6 },
		{ 0, YYAT_SHIFT, 7 },
		{ 0, YYAT_SHIFT, 8 },
		{ 0, YYAT_SHIFT, 9 },
		{ 190, YYAT_SHIFT, 46 },
		{ 0, YYAT_SHIFT, 10 },
		{ 200, YYAT_SHIFT, 204 },
		{ 94, YYAT_SHIFT, 147 },
		{ 156, YYAT_SHIFT, 192 },
		{ 18, YYAT_SHIFT, 11 },
		{ 18, YYAT_SHIFT, 12 },
		{ 18, YYAT_SHIFT, 13 },
		{ 155, YYAT_SHIFT, 191 },
		{ 18, YYAT_SHIFT, 14 },
		{ 18, YYAT_SHIFT, 15 },
		{ 78, YYAT_SHIFT, 134 },
		{ 78, YYAT_SHIFT, 135 },
		{ 173, YYAT_SHIFT, 127 },
		{ 173, YYAT_SHIFT, 128 },
		{ 190, YYAT_SHIFT, 47 },
		{ 160, YYAT_SHIFT, 106 },
		{ 160, YYAT_SHIFT, 107 },
		{ 117, YYAT_SHIFT, 120 },
		{ 117, YYAT_SHIFT, 121 },
		{ 117, YYAT_SHIFT, 122 },
		{ 117, YYAT_SHIFT, 123 },
		{ 117, YYAT_SHIFT, 124 },
		{ 117, YYAT_SHIFT, 125 },
		{ 88, YYAT_SHIFT, 140 },
		{ 0, YYAT_SHIFT, 11 },
		{ 0, YYAT_SHIFT, 12 },
		{ 0, YYAT_SHIFT, 13 },
		{ 91, YYAT_SHIFT, 144 },
		{ 0, YYAT_SHIFT, 14 },
		{ 0, YYAT_SHIFT, 15 },
		{ 158, YYAT_SHIFT, 194 },
		{ 78, YYAT_ERROR, 0 },
		{ 158, YYAT_SHIFT, 195 },
		{ 190, YYAT_SHIFT, 48 },
		{ 200, YYAT_SHIFT, 95 },
		{ 200, YYAT_SHIFT, 96 },
		{ 200, YYAT_SHIFT, 97 },
		{ 200, YYAT_SHIFT, 98 },
		{ 200, YYAT_SHIFT, 205 },
		{ 190, YYAT_SHIFT, 49 },
		{ 156, YYAT_ERROR, 0 },
		{ 45, YYAT_SHIFT, 89 },
		{ 156, YYAT_SHIFT, 193 },
		{ 128, YYAT_SHIFT, 67 },
		{ 58, YYAT_SHIFT, 102 },
		{ 88, YYAT_SHIFT, 141 },
		{ 91, YYAT_SHIFT, 90 },
		{ 56, YYAT_SHIFT, 44 },
		{ 190, YYAT_SHIFT, 51 },
		{ 190, YYAT_SHIFT, 52 },
		{ 164, YYAT_SHIFT, 126 },
		{ 164, YYAT_SHIFT, 127 },
		{ 164, YYAT_SHIFT, 128 },
		{ 158, YYAT_SHIFT, 126 },
		{ 158, YYAT_SHIFT, 127 },
		{ 158, YYAT_SHIFT, 128 },
		{ 44, YYAT_SHIFT, 86 },
		{ 128, YYAT_SHIFT, 68 },
		{ 149, YYAT_SHIFT, 97 },
		{ 149, YYAT_SHIFT, 98 },
		{ 45, YYAT_SHIFT, 90 },
		{ 42, YYAT_SHIFT, 85 },
		{ 88, YYAT_SHIFT, 142 },
		{ 197, YYAT_SHIFT, 95 },
		{ 197, YYAT_SHIFT, 96 },
		{ 197, YYAT_SHIFT, 97 },
		{ 197, YYAT_SHIFT, 98 },
		{ 187, YYAT_SHIFT, 95 },
		{ 187, YYAT_SHIFT, 96 },
		{ 187, YYAT_SHIFT, 97 },
		{ 187, YYAT_SHIFT, 98 },
		{ 186, YYAT_SHIFT, 95 },
		{ 186, YYAT_SHIFT, 96 },
		{ 186, YYAT_SHIFT, 97 },
		{ 186, YYAT_SHIFT, 98 },
		{ 172, YYAT_SHIFT, 95 },
		{ 172, YYAT_SHIFT, 96 },
		{ 172, YYAT_SHIFT, 97 },
		{ 172, YYAT_SHIFT, 98 },
		{ 171, YYAT_SHIFT, 95 },
		{ 171, YYAT_SHIFT, 96 },
		{ 171, YYAT_SHIFT, 97 },
		{ 171, YYAT_SHIFT, 98 },
		{ 170, YYAT_SHIFT, 95 },
		{ 170, YYAT_SHIFT, 96 },
		{ 170, YYAT_SHIFT, 97 },
		{ 170, YYAT_SHIFT, 98 },
		{ 169, YYAT_SHIFT, 95 },
		{ 169, YYAT_SHIFT, 96 },
		{ 169, YYAT_SHIFT, 97 },
		{ 169, YYAT_SHIFT, 98 },
		{ 168, YYAT_SHIFT, 95 },
		{ 168, YYAT_SHIFT, 96 },
		{ 168, YYAT_SHIFT, 97 },
		{ 168, YYAT_SHIFT, 98 },
		{ 167, YYAT_SHIFT, 95 },
		{ 167, YYAT_SHIFT, 96 },
		{ 167, YYAT_SHIFT, 97 },
		{ 167, YYAT_SHIFT, 98 },
		{ 161, YYAT_SHIFT, 95 },
		{ 161, YYAT_SHIFT, 96 },
		{ 161, YYAT_SHIFT, 97 },
		{ 161, YYAT_SHIFT, 98 },
		{ 143, YYAT_SHIFT, 95 },
		{ 143, YYAT_SHIFT, 96 },
		{ 143, YYAT_SHIFT, 97 },
		{ 143, YYAT_SHIFT, 98 },
		{ 111, YYAT_SHIFT, 95 },
		{ 111, YYAT_SHIFT, 96 },
		{ 111, YYAT_SHIFT, 97 },
		{ 111, YYAT_SHIFT, 98 },
		{ 87, YYAT_SHIFT, 95 },
		{ 87, YYAT_SHIFT, 96 },
		{ 87, YYAT_SHIFT, 97 },
		{ 87, YYAT_SHIFT, 98 },
		{ 82, YYAT_SHIFT, 95 },
		{ 82, YYAT_SHIFT, 96 },
		{ 82, YYAT_SHIFT, 97 },
		{ 82, YYAT_SHIFT, 98 },
		{ 55, YYAT_SHIFT, 95 },
		{ 55, YYAT_SHIFT, 96 },
		{ 55, YYAT_SHIFT, 97 },
		{ 55, YYAT_SHIFT, 98 },
		{ 72, YYAT_SHIFT, 126 },
		{ 72, YYAT_SHIFT, 127 },
		{ 72, YYAT_SHIFT, 128 },
		{ 62, YYAT_SHIFT, 106 },
		{ 62, YYAT_SHIFT, 107 },
		{ 62, YYAT_SHIFT, 108 },
		{ 148, YYAT_SHIFT, 97 },
		{ 148, YYAT_SHIFT, 98 },
		{ 93, YYAT_SHIFT, 97 },
		{ 93, YYAT_SHIFT, 98 },
		{ 83, YYAT_SHIFT, 12 },
		{ 83, YYAT_SHIFT, 13 },
		{ 57, YYAT_SHIFT, 100 },
		{ 57, YYAT_SHIFT, 101 },
		{ 41, YYAT_SHIFT, 44 },
		{ 40, YYAT_SHIFT, 83 },
		{ 32, YYAT_SHIFT, 79 },
		{ 31, YYAT_SHIFT, 77 },
		{ 30, YYAT_SHIFT, 75 },
		{ 29, YYAT_SHIFT, 73 },
		{ 23, YYAT_SHIFT, 38 },
		{ 22, YYAT_SHIFT, 44 },
		{ 21, YYAT_SHIFT, 38 },
		{ 16, YYAT_ACCEPT, 0 }
	};
	yytokenaction = tokenaction;

	static const yystateaction_t YYNEARFAR YYBASED_CODE stateaction[] = {
		{ -116, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 36 },
		{ 0, 0, YYAT_REDUCE, 126 },
		{ 0, 0, YYAT_REDUCE, 125 },
		{ 0, 0, YYAT_REDUCE, 119 },
		{ 0, 0, YYAT_REDUCE, 120 },
		{ 0, 0, YYAT_REDUCE, 121 },
		{ 0, 0, YYAT_REDUCE, 124 },
		{ 0, 0, YYAT_REDUCE, 123 },
		{ 0, 0, YYAT_REDUCE, 122 },
		{ 0, 0, YYAT_REDUCE, 35 },
		{ 0, 0, YYAT_REDUCE, 115 },
		{ 0, 0, YYAT_REDUCE, 116 },
		{ 0, 0, YYAT_REDUCE, 117 },
		{ 0, 0, YYAT_REDUCE, 37 },
		{ 0, 0, YYAT_REDUCE, 40 },
		{ 305, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 1 },
		{ -136, 1, YYAT_REDUCE, 2 },
		{ 0, 0, YYAT_REDUCE, 4 },
		{ -254, 1, YYAT_ERROR, 0 },
		{ 6, 1, YYAT_DEFAULT, 83 },
		{ 7, 1, YYAT_REDUCE, 107 },
		{ 4, 1, YYAT_DEFAULT, 101 },
		{ -156, 1, YYAT_REDUCE, 3 },
		{ -252, 1, YYAT_ERROR, 0 },
		{ -176, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 45, 1, YYAT_DEFAULT, 201 },
		{ 44, 1, YYAT_DEFAULT, 201 },
		{ 25, 1, YYAT_DEFAULT, 190 },
		{ 42, 1, YYAT_DEFAULT, 201 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 5 },
		{ 0, 0, YYAT_REDUCE, 8 },
		{ 0, 0, YYAT_REDUCE, 7 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 128 },
		{ 0, 0, YYAT_REDUCE, 45 },
		{ 19, 1, YYAT_REDUCE, 9 },
		{ 0, 1, YYAT_REDUCE, 107 },
		{ -58, 1, YYAT_REDUCE, 41 },
		{ 0, 0, YYAT_REDUCE, 43 },
		{ -80, 1, YYAT_DEFAULT, 190 },
		{ -83, 1, YYAT_REDUCE, 10 },
		{ 0, 0, YYAT_REDUCE, 92 },
		{ 0, 0, YYAT_REDUCE, 82 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 127 },
		{ 0, 0, YYAT_REDUCE, 80 },
		{ 0, 0, YYAT_REDUCE, 81 },
		{ 0, 0, YYAT_REDUCE, 56 },
		{ 0, 0, YYAT_REDUCE, 83 },
		{ -11, 1, YYAT_REDUCE, 57 },
		{ -90, 1, YYAT_REDUCE, 107 },
		{ 17, 1, YYAT_REDUCE, 14 },
		{ -75, 1, YYAT_REDUCE, 38 },
		{ 0, 0, YYAT_REDUCE, 48 },
		{ -152, 1, YYAT_REDUCE, 51 },
		{ -247, 1, YYAT_ERROR, 0 },
		{ 26, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 66 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -205, 1, YYAT_ERROR, 0 },
		{ -129, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ -162, 1, YYAT_DEFAULT, 117 },
		{ -256, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_REDUCE, 100 },
		{ 3, 1, YYAT_REDUCE, 20 },
		{ 0, 0, YYAT_REDUCE, 22 },
		{ 0, 0, YYAT_REDUCE, 21 },
		{ 0, 0, YYAT_REDUCE, 24 },
		{ 0, 0, YYAT_REDUCE, 23 },
		{ -245, 1, YYAT_ERROR, 0 },
		{ -103, 1, YYAT_DEFAULT, 200 },
		{ 0, 0, YYAT_REDUCE, 64 },
		{ 0, 0, YYAT_REDUCE, 63 },
		{ -187, 1, YYAT_DEFAULT, 158 },
		{ -15, 1, YYAT_REDUCE, 6 },
		{ -8, 1, YYAT_DEFAULT, 199 },
		{ -171, 1, YYAT_REDUCE, 46 },
		{ 0, 0, YYAT_REDUCE, 42 },
		{ 0, 0, YYAT_REDUCE, 108 },
		{ -19, 1, YYAT_REDUCE, 111 },
		{ -74, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 118 },
		{ -97, 1, YYAT_REDUCE, 11 },
		{ -178, 1, YYAT_REDUCE, 107 },
		{ -1, 1, YYAT_REDUCE, 91 },
		{ -134, 1, YYAT_DEFAULT, 156 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -189, 1, YYAT_REDUCE, 84 },
		{ 0, 0, YYAT_DEFAULT, 101 },
		{ -289, 1, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 39 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 59 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -196, 1, YYAT_REDUCE, 3 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 15 },
		{ -150, 1, YYAT_ERROR, 0 },
		{ -216, 1, YYAT_REDUCE, 3 },
		{ -23, 1, YYAT_REDUCE, 65 },
		{ 0, 0, YYAT_REDUCE, 68 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -155, 1, YYAT_REDUCE, 70 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_REDUCE, 104 },
		{ -107, 1, YYAT_DEFAULT, 94 },
		{ -253, 1, YYAT_DEFAULT, 158 },
		{ 0, 0, YYAT_REDUCE, 99 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ 0, 0, YYAT_DEFAULT, 128 },
		{ -80, 1, YYAT_DEFAULT, 190 },
		{ -167, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 34 },
		{ -158, 1, YYAT_DEFAULT, 201 },
		{ -163, 1, YYAT_DEFAULT, 201 },
		{ 0, 0, YYAT_REDUCE, 29 },
		{ -165, 1, YYAT_DEFAULT, 201 },
		{ -167, 1, YYAT_DEFAULT, 201 },
		{ 0, 0, YYAT_REDUCE, 74 },
		{ 0, 0, YYAT_REDUCE, 73 },
		{ 0, 0, YYAT_REDUCE, 44 },
		{ -220, 1, YYAT_REDUCE, 47 },
		{ 0, 0, YYAT_REDUCE, 110 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ 0, 0, YYAT_REDUCE, 109 },
		{ -27, 1, YYAT_REDUCE, 12 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -218, 1, YYAT_REDUCE, 107 },
		{ 0, 0, YYAT_REDUCE, 61 },
		{ 0, 0, YYAT_REDUCE, 90 },
		{ -3, 1, YYAT_REDUCE, 86 },
		{ -74, 1, YYAT_REDUCE, 87 },
		{ 0, 0, YYAT_REDUCE, 88 },
		{ 0, 0, YYAT_REDUCE, 89 },
		{ -229, 1, YYAT_REDUCE, 85 },
		{ 0, 0, YYAT_REDUCE, 50 },
		{ 0, 0, YYAT_REDUCE, 49 },
		{ -127, 1, YYAT_DEFAULT, 200 },
		{ -94, 1, YYAT_DEFAULT, 200 },
		{ 0, 0, YYAT_REDUCE, 75 },
		{ -67, 1, YYAT_ERROR, 0 },
		{ 0, 0, YYAT_REDUCE, 16 },
		{ -85, 1, YYAT_REDUCE, 76 },
		{ -31, 1, YYAT_REDUCE, 67 },
		{ 0, 0, YYAT_DEFAULT, 190 },
		{ -236, 1, YYAT_REDUCE, 3 },
		{ -70, 1, YYAT_REDUCE, 18 },
		{ 0, 0, YYAT_REDUCE, 106 },
		{ 0, 0, YYAT_REDUCE, 105 },
		{ -35, 1, YYAT_REDUCE, 93 },
		{ -39, 1, YYAT_REDUCE, 94 },
		{ -43, 1, YYAT_REDUCE, 95 },
		{ -47, 1, YYAT_REDUCE, 96 },
		{ -51, 1, YYAT_REDUCE, 97 },
		{ -55, 1, YYAT_REDUCE, 98 },
		{ -109, 1, YYAT_REDUCE, 102 },
		{ -219, 1, YYAT_REDUCE, 103 },
		{ 0, 0, YYAT_REDUCE, 101 },
		{ 0, 0, YYAT_REDUCE, 19 },
		{ 0, 0, YYAT_REDUCE, 31 },
		{ 0, 0, YYAT_REDUCE, 30 },
		{ 0, 0, YYAT_REDUCE, 33 },
		{ 0, 0, YYAT_REDUCE, 32 },
		{ 0, 0, YYAT_REDUCE, 26 },
		{ 0, 0, YYAT_REDUCE, 113 },
		{ -225, 1, YYAT_REDUCE, 25 },
		{ 0, 0, YYAT_REDUCE, 28 },
		{ -240, 1, YYAT_REDUCE, 27 },
		{ -59, 1, YYAT_REDUCE, 112 },
		{ -63, 1, YYAT_REDUCE, 13 },
		{ 0, 0, YYAT_REDUCE, 62 },
		{ 0, 0, YYAT_REDUCE, 54 },
		{ -98, 1, YYAT_DEFAULT, 83 },
		{ 0, 0, YYAT_REDUCE, 52 },
		{ 0, 0, YYAT_REDUCE, 60 },
		{ 0, 0, YYAT_REDUCE, 58 },
		{ 0, 0, YYAT_REDUCE, 79 },
		{ 0, 0, YYAT_REDUCE, 78 },
		{ 0, 0, YYAT_REDUCE, 77 },
		{ -67, 1, YYAT_REDUCE, 69 },
		{ -232, 1, YYAT_ERROR, 0 },
		{ -286, 1, YYAT_ERROR, 0 },
		{ -96, 1, YYAT_ERROR, 0 },
		{ -249, 1, YYAT_DEFAULT, 199 },
		{ 0, 0, YYAT_REDUCE, 17 },
		{ 0, 0, YYAT_REDUCE, 114 },
		{ 0, 0, YYAT_REDUCE, 55 },
		{ 0, 0, YYAT_REDUCE, 53 },
		{ 0, 0, YYAT_REDUCE, 72 },
		{ 0, 0, YYAT_REDUCE, 71 }
	};
	yystateaction = stateaction;

	yynontermgoto_size = 108;

	static const yynontermgoto_t YYNEARFAR YYBASED_CODE nontermgoto[] = {
		{ 163, 198 },
		{ 163, 18 },
		{ 163, 19 },
		{ 163, 23 },
		{ 163, 21 },
		{ 21, 40 },
		{ 21, 43 },
		{ 99, 152 },
		{ 101, 154 },
		{ 101, 60 },
		{ 44, 87 },
		{ 163, 25 },
		{ 23, 57 },
		{ 23, 59 },
		{ 44, 88 },
		{ 190, 200 },
		{ 163, 24 },
		{ 160, 196 },
		{ 160, 110 },
		{ 101, 55 },
		{ 83, 138 },
		{ 190, 54 },
		{ 190, 56 },
		{ 201, 207 },
		{ 99, 92 },
		{ 163, 20 },
		{ 163, 22 },
		{ 199, 203 },
		{ 163, 26 },
		{ 163, 27 },
		{ 163, 28 },
		{ 163, 30 },
		{ 163, 29 },
		{ 163, 31 },
		{ 163, 32 },
		{ 163, 33 },
		{ 101, 61 },
		{ 21, 42 },
		{ 198, 202 },
		{ 83, 39 },
		{ 83, 41 },
		{ 162, 197 },
		{ 23, 58 },
		{ 128, 69 },
		{ 128, 71 },
		{ 128, 175 },
		{ 18, -1 },
		{ 18, -1 },
		{ 18, 34 },
		{ 68, 117 },
		{ 152, 145 },
		{ 68, 118 },
		{ 135, 185 },
		{ 135, 182 },
		{ 0, 16 },
		{ 0, 17 },
		{ 145, 188 },
		{ 144, 187 },
		{ 141, 186 },
		{ 134, 183 },
		{ 132, 180 },
		{ 131, 178 },
		{ 127, 174 },
		{ 126, 173 },
		{ 125, 172 },
		{ 124, 171 },
		{ 123, 170 },
		{ 122, 169 },
		{ 121, 168 },
		{ 120, 167 },
		{ 115, 164 },
		{ 114, 163 },
		{ 113, 161 },
		{ 110, 160 },
		{ 107, 158 },
		{ 106, 157 },
		{ 105, 156 },
		{ 103, 155 },
		{ 100, 153 },
		{ 98, 151 },
		{ 97, 150 },
		{ 96, 149 },
		{ 95, 148 },
		{ 92, 146 },
		{ 89, 143 },
		{ 84, 139 },
		{ 70, 129 },
		{ 67, 116 },
		{ 65, 114 },
		{ 64, 111 },
		{ 62, 109 },
		{ 56, 99 },
		{ 49, 94 },
		{ 48, 93 },
		{ 45, 91 },
		{ 41, 84 },
		{ 37, 82 },
		{ 33, 81 },
		{ 32, 80 },
		{ 31, 78 },
		{ 30, 76 },
		{ 29, 74 },
		{ 28, 72 },
		{ 27, 70 },
		{ 26, 66 },
		{ 25, 65 },
		{ 24, 62 },
		{ 22, 45 }
	};
	yynontermgoto = nontermgoto;

	static const yystategoto_t YYNEARFAR YYBASED_CODE stategoto[] = {
		{ 53, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 44, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, 83 },
		{ 83, -1 },
		{ 3, 101 },
		{ 104, 163 },
		{ 91, -1 },
		{ 102, 163 },
		{ 80, 128 },
		{ 79, 128 },
		{ 74, -1 },
		{ 73, -1 },
		{ 78, 190 },
		{ 71, -1 },
		{ 74, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 75, 190 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -11, 190 },
		{ 82, 99 },
		{ 0, -1 },
		{ 0, -1 },
		{ 72, 190 },
		{ 71, 190 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 67, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, 160 },
		{ 0, -1 },
		{ 68, 190 },
		{ 73, -1 },
		{ 0, -1 },
		{ 64, 128 },
		{ 28, 128 },
		{ 0, -1 },
		{ 84, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 12, -1 },
		{ 73, 99 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 63, 190 },
		{ 0, -1 },
		{ 0, 152 },
		{ 59, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 61, 190 },
		{ 60, 190 },
		{ 59, 190 },
		{ 58, 190 },
		{ -5, -1 },
		{ 68, 101 },
		{ -2, 190 },
		{ 0, -1 },
		{ 56, 190 },
		{ 0, -1 },
		{ 55, 190 },
		{ 73, 163 },
		{ 51, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 71, 163 },
		{ 0, -1 },
		{ 0, -1 },
		{ 51, 190 },
		{ 55, -1 },
		{ 47, 128 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 48, 190 },
		{ 47, 190 },
		{ 46, 190 },
		{ 45, 190 },
		{ 44, 190 },
		{ 43, 190 },
		{ 40, 128 },
		{ 39, 128 },
		{ 22, 190 },
		{ 0, -1 },
		{ 0, -1 },
		{ 34, -1 },
		{ 33, -1 },
		{ 0, -1 },
		{ 33, 135 },
		{ 26, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, 152 },
		{ 0, -1 },
		{ 37, 190 },
		{ 0, -1 },
		{ 0, -1 },
		{ 36, 190 },
		{ 32, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -2, -1 },
		{ 0, -1 },
		{ 20, 190 },
		{ -2, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -6, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 21, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ -4, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 },
		{ 0, -1 }
	};
	yystategoto = stategoto;

	yydestructorptr = NULL;

	yytokendestptr = NULL;
	yytokendest_size = 0;

	yytokendestbaseptr = NULL;
	yytokendestbase_size = 0;
}
#line 286 ".\\parser.y"


/////////////////////////////////////////////////////////////////////////////
// programs section

/*
int Compilor_main(void)
{
	int n = 1;
	Compilor_Lexer lexer;
	Compilor_Parser parser;
	if (parser.yycreate(&lexer)) {
		if (lexer.yycreate(&parser)) {
			n = parser.yyparse();
		}
	}
	return n;
}
*/

#pragma comment( lib,"ylmtri.lib")



