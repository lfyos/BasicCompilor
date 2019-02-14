#include "StdAfx.h"

#include "Compilor.h"

#include "lexer.cpp"
#include "parser.cpp"

variable_label_head_string::variable_label_head_string()
{
	static bool flag=true;
	static CString my_directory_name,my_variable_struct_name,my_variable_pointer_name,my_label_head_string;

	if(flag){
		flag=false;
		char buf[2000];	
		{
			wchar_t dir_buf[sizeof(buf)/sizeof(buf[0])];	
			::GetModuleFileName(NULL,dir_buf,sizeof(dir_buf));
			my_directory_name=dir_buf;
		}
		for(int i=my_directory_name.GetLength()-1;i>=0;i--)
			if((my_directory_name.GetAt(i)==CString(_T("\\")))||(my_directory_name.GetAt(i)==CString(_T("/")))){
				my_directory_name=my_directory_name.Left(i+1);
				break;
			}
		ifstream f(my_directory_name+_T("head_string.lfy"));	
		f>>buf>>buf;		my_variable_struct_name=buf;
		f>>buf>>buf;		my_variable_pointer_name=buf;
		f>>buf>>buf;		my_label_head_string=buf;

		f.close();
	}
	directory_name=my_directory_name;
	variable_struct_name=my_variable_struct_name;
	variable_pointer_name=my_variable_pointer_name;
	label_head_string=my_label_head_string;
}
void View_marker::release_all()
{
	{
		variable_link_list *p;
		while((p=variable_list_pointer)!=NULL){
			variable_list_pointer=variable_list_pointer->next_variable;
			delete p;
		}
	}
	{
		program_base  *p;
		while((p=first_program_pointer)!=NULL){
			first_program_pointer=first_program_pointer->get_next_program();
			delete p;
		}
	}
}

int View_marker::yyinput()
{
	int ret_val;

	if((source_program_string==NULL)||(current>=length))
		return -1;

	CString str=source_program_string->Mid(current,1);
	str.MakeLower();
	BSTR bstrText=str.AllocSysString();
	char *current_data_buffer=_com_util::ConvertBSTRToString(bstrText);     
	SysFreeString(bstrText);

	ret_val=(int)(current_data_buffer[0]);
	
	delete []current_data_buffer;

	current++;
	line_position++;

	return ret_val;
};

variable_link_list* View_marker::do_compilation(CString *my_source_program_string,bool do_lex_only_flag,long my_mark_begin,long my_mark_end)
{
	{
		release_all();

		length=0;
		if((source_program_string=my_source_program_string)!=NULL)
			length=source_program_string->GetLength();

		if((mark_begin=my_mark_begin)<0)
			mark_begin=0;
		if((mark_end=my_mark_end)<0)
			mark_end=length;

		current=0;
		line_current=0;
		line_position=0;
	}
	{
		int n = 1;

		Compilor_Lexer my_lexer;
		Compilor_Parser my_parser;

		my_lexer.v_m=this;
		my_parser.v_m=this;

		lexer=&my_lexer;
	
		if(my_parser.yycreate(&my_lexer)) 
			if (my_lexer.yycreate(&my_parser)){
				if(do_lex_only_flag){
					for(n=0;;n++)
						if(my_lexer.yylex()==0)
							break;
				}else
					n = my_parser.yyparse();
			}
	}
	return variable_list_pointer;
}

variable_link_list* Compilor::do_compilation(CString *my_source_program_string,bool do_lex_only_flag,long my_mark_begin,long my_mark_end)						
{
		variable_link_list *return_value=View_marker::do_compilation(my_source_program_string,do_lex_only_flag,my_mark_begin,my_mark_end);
		
		execute_object_program		=_T("#include \"all_include.h\"\n")+(View_marker::execute_object_program)+_T("\n");
		var_declare_object_program	=View_marker::var_declare_object_program+_T("\n");

		return return_value;
}

