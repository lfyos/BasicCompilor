#pragma once
#include "Compilor.h"

class CRichEditView;
class CMFCPropertyGridCtrl;

class compilor_error_message
{
public:
	long begin_current,begin_line_current,begin_line_position,end_current,end_line_current,end_line_position;
	CString error_message;
};

class View_Compilor :public Compilor
{
	CRichEditView *mark_view;
	CRichEditCtrl *cp;
	long mark_length;
public:
	compilor_error_message error_message[100];
	int error_number;

	View_Compilor(CRichEditView *my_mark_view,int my_mark_length);

	variable_link_list *do_compilation(bool do_lex_only_flag);
	
	virtual void do_mark(long begin_index,long end_index,int cf_id);
	virtual void output_error_message(CString &error_str,
					long begin_current,	long begin_line_current,	long begin_line_position,
					long end_current,	long end_line_current,		long end_line_position);

	void display_error_message(CMFCPropertyGridCtrl &list);
	void display_variable_list(CRichEditCtrl *my_cp,CMFCPropertyGridCtrl &list,variable_link_list *p,CString server_name,int run_server_port_id,int program_server_port_id);

};
