#include "View_mark.h"

class Compilor:public View_marker
{
public:
	CString var_declare_object_program,execute_object_program;

	variable_link_list *do_compilation(CString *my_source_program_string,bool do_lex_only_flag,long my_mark_begin=-1,long my_mark_end=-1);
						
	virtual void do_mark(long begin_index,long end_index,int cf_id)=NULL;
	virtual void output_error_message(CString &error_str,
					long begin_current,		long begin_line_current,	long begin_line_position,
					long end_current,		long end_line_current,		long end_line_position)=NULL;
};

class Program_controller
{
	CString server_name;
	int run_server_port_id,program_server_port_id;
public:
	Program_controller(CString my_server_name,int my_run_server_port_id,int my_program_server_port_id)
	{
		server_name=my_server_name;
		run_server_port_id=my_run_server_port_id;
		program_server_port_id=my_program_server_port_id;
	}
	bool compile_program(CString basic_h,CString basic_c,CString execute_file_name,bool debug_flag);
	bool execute_program(CString execute_file_name);
	inline bool compile_execute_program(CString basic_h,CString basic_c,CString execute_file_name,bool debug_flag)
	{
		bool return_value;
		if((return_value=compile_program(basic_h,basic_c,execute_file_name,debug_flag)))
			return_value=execute_program(execute_file_name);
		return return_value;
	}
	void terminate_program();

	double get_variable_value(int variable_id);
	double set_variable_value(int variable_id,double variable_value);

	bool get_execute_location(	int &begin_current,	int &begin_line_current,	int &begin_line_position,
								int &end_current,	int &end_line_current,		int &end_line_position);
	int set_execute_state(int new_state_id);

	void set_break_point(int break_id,int line_current);
};