#pragma once

#define _USE_MATH_DEFINES

#include <math.h>
#include <fstream>
using namespace std;

class Compilor_Lexer;
class Compilor_Parser;

class program_base;
class variable_link_list;
class function_list_item;
class output_list_item;
class input_list_item;

class View_marker
{
	long length,mark_begin,mark_end;
	CString *source_program_string;
public:
	long current,line_current,line_position;

	Compilor_Lexer *lexer;
	
	void release_all();

	View_marker()
	{
		source_program_string=NULL;
		length=0;
		mark_begin=0;
		mark_end=0;

		current=0;
		line_current=0;
		line_position=0;

		first_program_pointer=NULL;
		variable_list_pointer=NULL;
	}

	~View_marker(void)
	{
		release_all();
	};
		
	int yyinput();
	void yyunput( int ch )
	{
		current--;
		line_position--;
	}		
	CString var_declare_object_program,execute_object_program;

	program_base *first_program_pointer;
	variable_link_list *variable_list_pointer;

	CString id_name;
	function_list_item  *function_item;
	output_list_item	*output_item;

	inline void mark(long length,int cf_id)
	{
		mark(current-length,current,cf_id);
	}
	inline void mark(long begin_index,long end_index,int cf_id)
	{
		if((end_index<mark_begin)||(begin_index>mark_end))
			return;
		do_mark(begin_index,end_index,cf_id);
	}
	virtual void do_mark(long begin_index,long end_index,int cf_id)=NULL;
	virtual void output_error_message(CString &error_str,
					long begin_current,	long begin_line_current,	long begin_line_position,
					long end_current,	long end_line_current,		long end_line_position)=NULL;
	variable_link_list *do_compilation(CString *my_source_program_string,bool do_lex_only_flag,long my_mark_begin,long my_mark_end);
};



#include "lexer.h"
#include "parser.h"
#include "Program.h"
#include "File_data.h"
#include "Network.h"

