%{
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


%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// lexical analyser name
%name Compilor_Lexer

// class definition
{
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
	
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

%%

/////////////////////////////////////////////////////////////////////////////
// rules section

%{
	// extract yylval for use later on in actions
	YYSTYPE YYFAR& yylval = *(YYSTYPE YYFAR*)yyparserptr->yylvalptr;
%}

// place your Lex rules here

[0-9]+										{v_m->id_name=CString(yytext);					v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			}
"$"[0-9]+									{v_m->id_name=_T("0x")+CString(&(yytext[1]));	v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			}
([0-9]+)\.([0-9]*)							{v_m->id_name=CString(yytext)+_T("0");			v_m->mark(yyleng,1);		return TOKEN_CONST_DOUBLE;		}

"true"										{v_m->id_name=_T("1");							v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			}
"off"|"false"								{v_m->id_name=_T("0");							v_m->mark(yyleng,1);		return TOKEN_CONST_INT;			}
"pi"										{v_m->id_name=_T("3.1415926535897932");			v_m->mark(yyleng,1);		return TOKEN_CONST_DOUBLE;		}

"("											{												v_m->mark(yyleng,2);		return TOKEN_LEFT_PARENTHESIS;	}
")"											{												v_m->mark(yyleng,2);		return TOKEN_RIGHT_PARENTHESIS;	}
"["											{												v_m->mark(yyleng,2);		return TOKEN_LEFT_SQUARE_BRACKET;}
"]"											{												v_m->mark(yyleng,2);		return TOKEN_RIGHT_SQUARE_BRACKET;}

"*"											{												v_m->mark(yyleng,3);		return TOKEN_MUL;				}
"/"											{												v_m->mark(yyleng,3);		return TOKEN_DIV;				}
"+"											{												v_m->mark(yyleng,3);		return TOKEN_ADD;				}
"-"											{												v_m->mark(yyleng,3);		return TOKEN_SUB;				}

"="											{												v_m->mark(yyleng,4);		return TOKEN_EQUAL;				}
"<>"										{												v_m->mark(yyleng,4);		return TOKEN_NOT_EQUAL;			}
">"											{												v_m->mark(yyleng,4);		return TOKEN_GREAT;				}
">="										{												v_m->mark(yyleng,4);		return TOKEN_GREAT_EQUAL;		}
"<"											{												v_m->mark(yyleng,4);		return TOKEN_LESS;				}
"<="										{												v_m->mark(yyleng,4);		return TOKEN_LESS_EQUAL;		}

"not"										{												v_m->mark(yyleng,5);		return TOKEN_NOT;				}
"and"										{												v_m->mark(yyleng,5);		return TOKEN_AND;				}
"or"										{												v_m->mark(yyleng,5);		return TOKEN_OR;				}
"xor"										{												v_m->mark(yyleng,5);		return TOKEN_XOR;				}

":"											{												v_m->mark(yyleng,6);		return TOKEN_COLON;				}
";"											{												v_m->mark(yyleng,6);		return TOKEN_SEMICOLON;			}
","											{												v_m->mark(yyleng,6);		return TOKEN_COMMA;				}

"if"										{												v_m->mark(yyleng,7);		return TOKEN_IF;				}
"then"										{												v_m->mark(yyleng,7);		return TOKEN_THEN;				}
"else"										{												v_m->mark(yyleng,7);		return TOKEN_ELSE;				}
"endif"										{												v_m->mark(yyleng,7);		return TOKEN_ENDIF;				}
"elseif"									{												v_m->mark(yyleng,7);		return TOKEN_ELSEIF;			}
"for"										{												v_m->mark(yyleng,7);		return TOKEN_FOR;				}
"to"										{												v_m->mark(yyleng,7);		return TOKEN_TO;				}
"step"										{												v_m->mark(yyleng,7);		return TOKEN_STEP;				}
"next"										{												v_m->mark(yyleng,7);		return TOKEN_NEXT;				}
"repeat"									{												v_m->mark(yyleng,7);		return TOKEN_REPEAT;			}
"until"										{												v_m->mark(yyleng,7);		return TOKEN_UNTIL;				}
"while"										{												v_m->mark(yyleng,7);		return TOKEN_WHILE_BEGIN;		}
"wend"										{												v_m->mark(yyleng,7);		return TOKEN_WHILE_END;			}
"goto"										{												v_m->mark(yyleng,7);		return TOKEN_GOTO;				}
"gosub"										{												v_m->mark(yyleng,7);		return TOKEN_GOSUB;				}
"return"									{												v_m->mark(yyleng,7);		return TOKEN_RETURN;			}						
"on"										{												v_m->mark(yyleng,7);		return TOKEN_ON;				}
"basicerror"								{												v_m->mark(yyleng,7);		return TOKEN_BASIC_ERROR;		}
"wait"[ \t]+"until"							{												v_m->mark(yyleng,7);		return TOKEN_WAIT_UNTIL;		}

"wait"[ \t]+"idle"							{v_m->id_name=_T("wait_idle");												return this->function_process();}
"wait"[ \t]+"loaded"						{v_m->id_name=_T("wait_load");												return this->function_process();}

"chr"										{v_m->id_name=_T("0");							v_m->mark(yyleng,8);		return TOKEN_NUMBER_CHARACTER;	}
"hex"										{v_m->id_name=_T("1");							v_m->mark(yyleng,8);		return TOKEN_NUMBER_CHARACTER;	}
"#"[0-9]+									{v_m->id_name=CString(&(yytext[1]));			v_m->mark(yyleng,9);		return TOKEN_CHANNEL_NUMBER;	}

[a-zA-Z][0-9a-zA-Z]*("#"{0,1})				{v_m->id_name=CString(yytext);												return this->function_process();}
\"[^\r\n\"]*\"								{v_m->id_name=CString(yytext).Mid(1,yyleng-2);	v_m->mark(yyleng,16);		return TOKEN_STRING;			}
										
[\r]										{v_m->line_current++;v_m->line_position=0;																	}

"'"[^\r]*									{												v_m->mark(yyleng,0);										}		//delete comment

([ \t\n])+									{																											}

%%

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

