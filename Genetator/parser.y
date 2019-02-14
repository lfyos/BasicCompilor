%{
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

%}

/////////////////////////////////////////////////////////////////////////////
// declarations section

// parser name
%name Compilor_Parser

// class definition
{
	// place any extra class members here
	View_marker *v_m;
	program_base *input_function;
	program_base *output_function;
}

// constructor
{
	// place any extra initialisation code here
}

// destructor
{
	// place any extra cleanup code here
}

// attribute type
%include {
#ifndef YYSTYPE
#define YYSTYPE program_base*
#endif
}

// place any declarations here

%token	TOKEN_IF,TOKEN_THEN,TOKEN_ELSE,TOKEN_ELSEIF,TOKEN_ENDIF,TOKEN_FOR,TOKEN_TO,TOKEN_STEP,TOKEN_NEXT,TOKEN_REPEAT,TOKEN_UNTIL,TOKEN_WHILE_BEGIN,TOKEN_WHILE_END,TOKEN_WAIT_UNTIL
%token	TOKEN_ON,TOKEN_GOTO,TOKEN_GOSUB,TOKEN_BASIC_ERROR,TOKEN_RETURN

%token	TOKEN_COLON,TOKEN_SEMICOLON,TOKEN_COMMA

%left	TOKEN_OR
%left	TOKEN_XOR
%left	TOKEN_AND
%right	TOKEN_NOT

%nonassoc TOKEN_EQUAL,TOKEN_NOT_EQUAL,TOKEN_GREAT,TOKEN_GREAT_EQUAL,TOKEN_LESS,TOKEN_LESS_EQUAL

%left	TOKEN_ADD,TOKEN_SUB
%left	TOKEN_MUL,TOKEN_DIV

%token	TOKEN_RIGHT_SQUARE_BRACKET
%token	TOKEN_LEFT_SQUARE_BRACKET

%token TOKEN_RIGHT_PARENTHESIS
%token	TOKEN_LEFT_PARENTHESIS

%token TOKEN_NUMBER_CHARACTER,TOKEN_CHANNEL_NUMBER

%token	TOKEN_IDENTIFICATION,TOKEN_INTEGER_FUNCTION_NAME,TOKEN_DOUBLE_FUNCTION_NAME,TOKEN_MODIFY_NAME,TOKEN_OUTPUT_NAME,TOKEN_INPUT_NAME

%token	TOKEN_CONST_INT,TOKEN_CONST_DOUBLE,TOKEN_STRING


%%

/////////////////////////////////////////////////////////////////////////////
// rules section

// place your YACC rules here (there must be at least one)


whole_program				:	sentence_list
								{
									variable_declare_program *p;
									variable_label_head_string head_str;
									CString str;
									
									str =_T("\n\nvoid basic_run_function(struct ");
									str+=head_str.variable_struct_name+_T(" *");
									str+=head_str.variable_pointer_name+_T(")\n{");
									str+=_T("\n	register int accumlator_integer=0;");
									str+=_T("\n	register double accumlator_double=0;\n");
									str+=_T("\n	memset(")+(head_str.variable_pointer_name)+_T(",0,sizeof(*")+(head_str.variable_pointer_name)+_T("));\n");

									v_m->execute_object_program=str+(($1)->create_list_program(1))+_T("\n}\n");	
																	
									p=new variable_declare_program(v_m);
									v_m->execute_object_program		+=p->create_set_get_program();
																		
									v_m->var_declare_object_program	 =p->create_declare_program();
								}
							;
sentence_list				:	not_empty_sentence_list												{ $$=$1;}
							|																		{ $$=new program_base(v_m);}
							;
not_empty_sentence_list		:	sentence															{ $$=$1;}
							|	not_empty_sentence_list		sentence								{ $$=($1)->link_next($2);}
							;
sentence					:	identification		TOKEN_EQUAL		arith_expr						{ $$=new let_sentence_program(v_m,$1,$3);}
							|	identification		TOKEN_COLON										{ $$=new label_defination_program(v_m,$1);}
							|	identification		error											{($$=$1)->output_error_message_at_end(_T("标识符 ")+($1)->id_name+_T(" 后面应紧跟等号（= 赋值语句) 或 冒号（: 标号定义语句)"));}
					
							|	input_keyword		input_list										{ $$=new in_out_program(v_m,$1,$2);}
						
							|	function	parenthese_expr											{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,NULL,NULL);}
							|	function	parenthese_expr	modifier_list							{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,NULL,$3  );}
							|	function	parenthese_expr					TOKEN_EQUAL	arith_expr	{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,$4,  NULL);}
							|	function	parenthese_expr	modifier_list	TOKEN_EQUAL	arith_expr	{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,$5,  $3  );}
									
							|	output_keyword		output_list										{ $$=new in_out_program(v_m,$1,$2);}
						
							|	if_sentence			sentence_list	TOKEN_ENDIF						{ $$=new if_then_else_program(v_m,$1,$2,NULL);}
							|	if_sentence			sentence_list	else_sentence	TOKEN_ENDIF		{ $$=new if_then_else_program(v_m,$1,$2,$3);}
				
							|	for_head	for_1	for_2	for_3	sentence_list	for_tail		{ $$=new for_next_program(v_m,$1,$2,$3,$4,$5,$6);}
							|	repeat_keyword		sentence_list	TOKEN_UNTIL		logic_expr		{ $$=new repeat_until_program(v_m,$1,$2,$4);}
							|	while_begin_keyword	logic_expr		sentence_list	TOKEN_WHILE_END	{ $$=new while_program(v_m,$1,$3,$2);}
							|	wait_until_keyword	logic_expr										{ $$=new repeat_until_program(v_m,$1,NULL,$2);}
				
							|	goto_keyword		identification									{ $$=new goto_program(v_m,$1,$2);}
							|	goto_keyword		error											{($$=$1)->output_error_message_at_end(_T("goto 后面应紧跟标号"));}
							|	gosub_keyword		identification									{ $$=new gosub_program(v_m,$1,$2);}
							|	gosub_keyword		error											{($$=$1)->output_error_message_at_end(_T("gosub 后面应紧跟标号"));}	
				
							|	on_keyword	arith_expr			TOKEN_GOTO		identification_list	{ $$=new on_goto_program(v_m,$1,$2,$4);}
							|	on_keyword	arith_expr			TOKEN_GOTO		error				{($$=$1)->output_error_message_at_end(_T("on goto 语句 goto 后面的标号列表错误"));	}
							|	on_keyword	arith_expr			TOKEN_GOSUB		identification_list	{ $$=new on_gosub_program(v_m,$1,$2,$4);}
							|	on_keyword	arith_expr			TOKEN_GOSUB		error				{($$=$1)->output_error_message_at_end(_T("on gosub 语句gosub后面的标号列表错误"));}
							|	on_keyword	arith_expr			error								{($$=$1)->output_error_message_at_end(_T("on语句算数表达式后面应紧跟goto 或 gosub"));}
				
							|	on_keyword	TOKEN_BASIC_ERROR	TOKEN_GOTO		identification		{ $$=new on_error_goto_program(v_m,$1,$4);}
							|	on_keyword	TOKEN_BASIC_ERROR	TOKEN_GOTO		error				{($$=$1)->output_error_message_at_end(_T("on basicerror goto 语句gosub后面的标号列表错误"));}
							|	on_keyword	TOKEN_BASIC_ERROR	TOKEN_GOSUB		identification		{ $$=new on_error_gosub_program(v_m,$1,$4);}
							|	on_keyword	TOKEN_BASIC_ERROR	TOKEN_GOSUB		error				{($$=$1)->output_error_message_at_end(_T("on basicerror gosub 语句gosub后面的标号列表错误"));}
							|	on_keyword	TOKEN_BASIC_ERROR	error								{($$=$1)->output_error_message_at_end(_T("on basicerror语句后面应紧跟goto 或 gosub"));}
							|	TOKEN_RETURN														{ $$=new return_program(v_m);}
							|	error																{($$=new program_base(v_m))->output_error_message_at_end(_T("编译器发现语法错误"));}
							;
output_keyword				:	TOKEN_OUTPUT_NAME													{ output_function=new output_name_program(v_m);$$=output_function;}	
							|	output_keyword		channel_number_keyword							{((output_name_program *)($$=$1))->channel_name=($2)->id_name;}
							|	output_keyword		channel_number_keyword		TOKEN_COMMA			{((output_name_program *)($$=$1))->channel_name=($2)->id_name;}
							;
input_keyword				:	TOKEN_INPUT_NAME													{ input_function=new input_name_program(v_m);$$=input_function;}	
							|	input_keyword		channel_number_keyword							{(( input_name_program *)($$=$1))->channel_name=($2)->id_name;}
							|	input_keyword		channel_number_keyword		TOKEN_COMMA			{(( input_name_program *)($$=$1))->channel_name=($2)->id_name;}
							;
input_list					:	input_item															{ $$=$1;}
							|	input_list	TOKEN_COMMA		input_item								{($$=$1)->link_next($3);}
							;
input_item					:	identification														{($$=new let_sentence_program(v_m,$1,input_function))->set_begin(input_function);}
							|	function	parenthese_expr											{($$=new function_call_program(v_m,(function_name_program *)($1),$2,input_function,NULL))->set_begin(input_function);}
							|	function	parenthese_expr	modifier_list							{($$=new function_call_program(v_m,(function_name_program *)($1),$2,input_function,$3  ))->set_begin(input_function);}
							;		
output_list					:	output_format														{ $$=$1;}
							|	output_list	TOKEN_COMMA		output_format							{ $$=($1)->link_next($3);((output_program *)(($3)->front_pointer))->set_end_flag(1);}
							|	output_list	TOKEN_SEMICOLON	output_format							{ $$=($1)->link_next($3);((output_program *)(($3)->front_pointer))->set_end_flag(2);}
							;
output_format				:	output_item																									{ $$=$1;}
							|	output_item	TOKEN_LEFT_SQUARE_BRACKET	arith_expr							TOKEN_RIGHT_SQUARE_BRACKET		{ ((output_program *)($$=$1))->set_format($3,NULL);}
							|	output_item	TOKEN_LEFT_SQUARE_BRACKET	arith_expr	TOKEN_COMMA	arith_expr	TOKEN_RIGHT_SQUARE_BRACKET		{ ((output_program *)($$=$1))->set_format($3,$5  );}
							|	output_item	TOKEN_LEFT_SQUARE_BRACKET	arith_expr	error							{ ((output_program *)($$=$1))->set_format($3,NULL);	($3)->output_error_message(_T("第一个格式表达式后应紧跟逗号或右中括号"));}
							|	output_item	TOKEN_LEFT_SQUARE_BRACKET	arith_expr	TOKEN_COMMA	arith_expr	error	{ ((output_program *)($$=$1))->set_format($3,$5);	($5)->output_error_message(_T("第二个格式表达式后应紧跟右中括号"));}
							;												
output_item					:	TOKEN_STRING																		{ $$=new output_string_program(v_m,(output_name_program *)output_function);}
							|	arith_expr																			{ $$=new output_value_program (v_m,(output_name_program *)output_function,$1);}
							|	number_string		TOKEN_LEFT_PARENTHESIS	arith_expr	TOKEN_RIGHT_PARENTHESIS		{ $$=new output_number_string_program(v_m,(output_name_program *)output_function,$3,($1)->id_name);}
							|	number_string		error											{($$=new output_number_string_program(v_m,(output_name_program *)output_function,NULL,($1)->id_name))->output_error_message_at_end(_T("此处应为左括号"));}
							|	number_string		TOKEN_LEFT_PARENTHESIS	arith_expr	error		{($$=new output_number_string_program(v_m,(output_name_program *)output_function,$3,($1)->id_name  ))->output_error_message_at_end(_T("只有左括号，缺少右括号，左右括号不匹配"));}
							;
modifier_list				:	modifier			parenthese_expr									{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,NULL,NULL);}
							|	modifier_list		modifier		parenthese_expr					{ $$=($1)->link_next(new function_call_program(v_m,(function_name_program *)($2),$3,NULL,NULL));}
							;
for_head					:	for_keyword			identification									{($$=$2)->set_begin($1);}
							|	for_keyword			error											{($$=$1)->output_error_message_at_end(_T("for 后面应该紧跟变量名"));}
							;
for_1						:	TOKEN_EQUAL			arith_expr										{ $$=$2;}
							|	error																{($$=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("此处应为等号="));}
							;
for_2						:	TOKEN_TO			arith_expr										{ $$=$2;}
							|	error																{($$=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("此处应为 to "));}
							;
for_3						:	TOKEN_STEP			arith_expr										{ $$=$2;}
							|																		{ $$=new const_program(v_m,_T("1"),0);}
							;
for_tail					:	TOKEN_NEXT	identification											{ $$=$2;}
							|	TOKEN_NEXT	error													{($$=new program_base(v_m))->output_error_message_at_end(_T("next后面的变量名错误"));}
							;
if_sentence					:	if_keyword	logic_expr	TOKEN_THEN									{($$=$2)->set_begin($1);}
							|	if_keyword	logic_expr	error										{($$=$2)->set_begin($1)->output_error_message_at_end(_T("if <表达式> 后面应接then"));}
							;
else_sentence				:	TOKEN_ELSE			sentence_list									{ $$=$2;}
							|	else_sub_sentence	sentence_list									{ $$=new if_then_else_program(v_m,$1,$2,NULL);}
							|	else_sub_sentence	sentence_list		else_sentence				{ $$=new if_then_else_program(v_m,$1,$2,$3);}
							;
else_sub_sentence			:	TOKEN_ELSEIF	logic_expr	TOKEN_THEN								{ $$=$2;}
							|	TOKEN_ELSEIF	logic_expr	error									{($$=$2)->output_error_message_at_end(_T("elseif <表达式> 后面应接then"));}
							;
arith_expr					:	TOKEN_CONST_INT														{ $$=new const_program(v_m,v_m->id_name,0);}
							|	TOKEN_CONST_DOUBLE													{ $$=new const_program(v_m,v_m->id_name,1);}
							|	TOKEN_ON															{ $$=new const_program(v_m,_T("1"),0);}
					
							|	identification														{($$=new const_program(v_m,($1)->id_name,($1)->type_id,variable_label_head_string().variable_pointer_name+_T("->")))->register_variable();}
					
							|	function		parenthese_expr										{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,NULL,NULL);}
							|	function		parenthese_expr			modifier_list				{ $$=new function_call_program(v_m,(function_name_program *)($1),$2,NULL,$3  );}

							|	arith_expr		TOKEN_ADD				arith_expr					{ $$=new add_sub_mul_div_program(v_m,_T("+"),$1,$3);}
							|	arith_expr		TOKEN_SUB				arith_expr					{ $$=new add_sub_mul_div_program(v_m,_T("-"),$1,$3);}
							|	arith_expr		TOKEN_MUL				arith_expr					{ $$=new add_sub_mul_div_program(v_m,_T("*"),$1,$3);}		
							|	arith_expr		TOKEN_DIV				arith_expr					{ $$=new add_sub_mul_div_program(v_m,_T("/"),$1,$3);}
				
							|	TOKEN_LEFT_PARENTHESIS	arith_expr	TOKEN_RIGHT_PARENTHESIS			{ $$=$2;}
							|	TOKEN_SUB				arith_expr									{ $$=new add_sub_mul_div_program(v_m,_T("-"),$2);}
							|	error																{($$=new const_program(v_m,_T("0"),0))->output_error_message_at_end(_T("识别表达式时发现语法错误"));}
							;
relative_expr				:	arith_expr		TOKEN_EQUAL				arith_expr					{ $$=new relative_logic_program(v_m,_T("=="),$1,$3);}
							|	arith_expr		TOKEN_NOT_EQUAL			arith_expr					{ $$=new relative_logic_program(v_m,_T("!="),$1,$3);}
							|	arith_expr		TOKEN_GREAT				arith_expr					{ $$=new relative_logic_program(v_m,_T(">" ),$1,$3);}
							|	arith_expr		TOKEN_GREAT_EQUAL		arith_expr					{ $$=new relative_logic_program(v_m,_T(">="),$1,$3);}
							|	arith_expr		TOKEN_LESS				arith_expr					{ $$=new relative_logic_program(v_m,_T("<" ),$1,$3);}
							|	arith_expr		TOKEN_LESS_EQUAL		arith_expr					{ $$=new relative_logic_program(v_m,_T("<="),$1,$3);}
							|	arith_expr		error												{($$=new relative_logic_program(v_m,_T("=="),$1))->output_error_message_at_end(_T("识别关系表达式时发现关系算符错误"));}
							;	
logic_expr					:	relative_expr														{ $$=$1;}
							|	logic_expr		TOKEN_AND			logic_expr						{ $$=new relative_logic_program(v_m,_T("&"),$1,$3);}
							|	logic_expr		TOKEN_OR			logic_expr						{ $$=new relative_logic_program(v_m,_T("|"),$1,$3);}
							|	logic_expr		TOKEN_XOR			logic_expr						{ $$=new relative_logic_program(v_m,_T("^"),$1,$3);}
					
							|	TOKEN_NOT								logic_expr					{ $$=new relative_logic_program(v_m,_T("=="),$2);}
							|	TOKEN_LEFT_PARENTHESIS	logic_expr	TOKEN_RIGHT_PARENTHESIS			{ $$=$2;}
							|	TOKEN_LEFT_PARENTHESIS	logic_expr	error							{($$=$2)->output_error_message_at_end(_T("识别逻辑表达式时发现左右括号不对应"));}
							;
parenthese_expr				:																		{ $$=NULL;}
							|	TOKEN_LEFT_PARENTHESIS	TOKEN_RIGHT_PARENTHESIS						{ $$=NULL;}
							|	TOKEN_LEFT_PARENTHESIS	arith_expr_list	TOKEN_RIGHT_PARENTHESIS		{ $$=$2;  }
							|	TOKEN_LEFT_PARENTHESIS	arith_expr_list	error						{($$=$2)->output_error_message_at_end(_T("参数表左右括号不匹配"));}
							;
arith_expr_list				:	arith_expr															{ $$=$1;}
							|	arith_expr_list			TOKEN_COMMA		arith_expr					{ $$=($1)->link_next($3);}
								;
identification_list			:	identification														{ $$=$1;}
							|	identification_list		TOKEN_COMMA		identification				{ $$=($1)->link_next($3);}
							;
identification				:	TOKEN_IDENTIFICATION												{ $$=new identification_program(v_m);}
							;	
function					:	TOKEN_INTEGER_FUNCTION_NAME											{ $$=new function_name_program(v_m);}
							|	TOKEN_DOUBLE_FUNCTION_NAME											{ $$=new function_name_program(v_m);}
							;
modifier					:	TOKEN_MODIFY_NAME													{ $$=new function_name_program(v_m);}
							;						
repeat_keyword				:	TOKEN_REPEAT														{ $$=new program_base(v_m);}
							;				
while_begin_keyword			:	TOKEN_WHILE_BEGIN													{ $$=new program_base(v_m);}
							;
wait_until_keyword			:	TOKEN_WAIT_UNTIL													{ $$=new program_base(v_m);}
							;
gosub_keyword				:	TOKEN_GOSUB															{ $$=new program_base(v_m);}
							;
goto_keyword				:	TOKEN_GOTO															{ $$=new program_base(v_m);}
							;
on_keyword					:	TOKEN_ON															{ $$=new program_base(v_m);}
							;
for_keyword					:	TOKEN_FOR															{ $$=new program_base(v_m);}
							;
if_keyword					:	TOKEN_IF															{ $$=new program_base(v_m);}
							;
number_string				:	TOKEN_NUMBER_CHARACTER												{ $$=new program_base(v_m);}	
							;
channel_number_keyword		:	TOKEN_CHANNEL_NUMBER												{ $$=new program_base(v_m);}	
							;
%%

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


