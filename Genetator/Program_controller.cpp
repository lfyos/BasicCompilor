#include "StdAfx.h"

#include "Compilor.h"
bool Program_controller::compile_program(CString basic_h,CString basic_c,CString execute_file_name,bool debug_flag)
{
	if(!debug_flag)
		basic_h=_T("#define BASIC_DEBUG_FUNCTION(x1,y1,z1,x2,y2,z2)\n")+basic_h;
	else
		basic_h=_T("#define BASIC_DEBUG_FUNCTION(x1,y1,z1,x2,y2,z2)	do_basic_debug((x1),(y1),(z1),(x2),(y2),(z2));\n")+basic_h;

	if(!(Run_program_client::tranfer_file_data(run_server_port_id,server_name,basic_h,_T("basic.h"),1024)))
		return false;
	if(!(Run_program_client::tranfer_file_data(run_server_port_id,server_name,basic_c,_T("basic.c"),1024)))
		return false;
	
	Run_program_client a(run_server_port_id,server_name,_T("emake 2>basic.result >/dev/null"));
	if((a.reply_data==NULL)||(a.reply_length<=0)){
		AfxMessageBox(_T("执行make失败"));
		return false;
	}
	Run_program_client b(run_server_port_id,server_name,_T("lbasic.result"));
	if((b.reply_data==NULL)||(b.reply_length<=0)){
		AfxMessageBox(_T("提取编译连接出错信息失败"));
		return false;
	}
	int length=0;
	sscanf_s(b.reply_data,"%d",&length);
	if(length>0){
		AfxMessageBox(_T("编译连接程序时出错"));
		return false;
	}
	return true;
}
bool Program_controller::execute_program(CString execute_file_name)
{
	CString str;
	str.Format(_T(" %d "),program_server_port_id);
	str=execute_file_name+str+server_name+_T("&");
	Run_program_client c(run_server_port_id,server_name,_T("e")+str);
	if((c.reply_data==NULL)||(c.reply_length<=0)){
		AfxMessageBox(_T("执行basic程序失败"));
		return false;
	}
	return true;
}

void Program_controller::terminate_program()
{
	Run_program_client(program_server_port_id,server_name,_T("t   "));
}

double Program_controller::get_variable_value(int variable_id)
{
	CString str;
	double return_value=0.0;

	str.Format(_T("%d\n"),variable_id);
	Run_program_client a(program_server_port_id,server_name,_T("g")+str);
	
	if((a.reply_data==NULL)||(a.reply_length<=0)){
		AfxMessageBox(_T("执行提取变量数值失败"));
		return 0;
	}
	sscanf_s(a.reply_data,"%lf",&return_value);
	return return_value;
}
double Program_controller::set_variable_value(int variable_id,double variable_value)
{
	CString str;
	
	str.Format(_T("%d %lf\n"),variable_id,variable_value);
	Run_program_client a(program_server_port_id,server_name,_T("s")+str);
	
	if((a.reply_data==NULL)||(a.reply_length<=0)){
		AfxMessageBox(_T("执行设置变量数值失败"));
		return variable_value;
	}
	sscanf_s(a.reply_data,"%lf",&variable_value);
	return variable_value;
}

bool Program_controller:: get_execute_location(
		int &begin_current,	int &begin_line_current,	int &begin_line_position,
		int &end_current,	int &end_line_current,		int &end_line_position)
{
	Run_program_client a(program_server_port_id,server_name,_T("l"));
	
	if((a.reply_data==NULL)||(a.reply_length<=0)){
		AfxMessageBox(_T("提取程序执行位置失败"));
		return false;
	}
	sscanf_s(a.reply_data,"%d%d%d%d%d%d",
			&begin_current,	&begin_line_current,	&begin_line_position,
			&end_current,	&end_line_current,		&end_line_position);
	return true;
}

int Program_controller::set_execute_state(int new_state_id)
{
	CString str;
	str.Format(_T("c%d\n"),new_state_id);
	Run_program_client a(program_server_port_id,server_name,str);
	
	if((a.reply_data==NULL)||(a.reply_length<=0)){
		AfxMessageBox(_T("设置程序执行状态失败"));
		return false;
	}
	sscanf_s(a.reply_data,"%d",&new_state_id);
	return new_state_id;
}

void Program_controller::set_break_point(int break_id,int line_current)
{
	CString str;
	str.Format(_T("b%d %d\n"),break_id,line_current);
	Run_program_client a(program_server_port_id,server_name,str);
	
	if((a.reply_data==NULL)||(a.reply_length<=0))
		AfxMessageBox((break_id<0)?_T("执行清除所有断点失败"):(line_current>=0)?_T("执行设置断点失败"):_T("执行清除断点失败"));
}