#include "StdAfx.h"
#include "View_Compilor.h"

View_Compilor::View_Compilor(CRichEditView *my_mark_view,int my_mark_length)
{
	mark_view=my_mark_view;
	cp=&(mark_view->GetRichEditCtrl());
	mark_length=my_mark_length;
}

variable_link_list *View_Compilor::do_compilation(bool do_lex_only_flag)
{
	CString str;
	long old_selection_begin,old_select_end;

	if(cp->GetTextRange(0,cp->GetTextLength(),str)<=0)
		str=_T("");

	cp->GetSel(old_selection_begin,old_select_end);
	error_number=0;
	mark_view->ShowWindow(SW_HIDE);
	variable_link_list *return_value=Compilor::do_compilation(&str,do_lex_only_flag,old_selection_begin-mark_length,old_select_end+mark_length);
	mark_view->ShowWindow(SW_SHOW);
	cp->SetSel(old_selection_begin,old_select_end);

	return return_value;
}

void View_Compilor::do_mark(long begin_index,long end_index,int cf_id)
{
	static int cf_number=-1;
	static CHARFORMAT2 cf[1000];

	if(cf_number<0){
		char buf[2000];
		ifstream f(variable_label_head_string().directory_name+_T("font.lfy"));

		memset(cf,0,sizeof(cf)); 
		for(cf_number=0;cf_number<(sizeof(cf)/sizeof(cf[0]));cf_number++){
			int red_value=0,green_value=0,blue_value=0;
			f>>buf>>red_value>>green_value>>blue_value;
			if((f.eof())||(f.fail()))
				break;

			cf[cf_number].cbSize=sizeof(cf[cf_number]);
			cf[cf_number].dwMask=CFM_COLOR|CFM_BOLD;
			cf[cf_number].crTextColor=COLORREF(RGB(red_value,green_value,blue_value));
			cf[cf_number].dwEffects = CFE_BOLD;
		}
		f.close();
	}

	if((cf_id<0)||(cf_id>=cf_number))
		return;

	cp->SetSel(begin_index,end_index);
	cp->SetWordCharFormat(cf[cf_id]);
};

void View_Compilor::output_error_message(CString &error_str,
			long begin_current,	long begin_line_current,	long begin_line_position,
			long end_current,	long end_line_current,		long end_line_position)
{
	error_message[error_number].error_message=error_str;

	error_message[error_number].begin_current=begin_current;
	error_message[error_number].begin_line_current=begin_line_current;
	error_message[error_number].begin_line_position=begin_line_position;
	error_message[error_number].end_current=end_current;
	error_message[error_number].end_line_current=end_line_current;
	error_message[error_number].end_line_position=end_line_position;
	
	error_number++;
}

void View_Compilor::display_error_message(CMFCPropertyGridCtrl &list)
{
	class error_message_display:public CMFCPropertyGridProperty
	{
			CRichEditCtrl *cp;
	public:
			long begin_current,	begin_line_current,	begin_line_position;
			long end_current,	end_line_current,	end_line_position;

			error_message_display(CRichEditCtrl *my_cp,CString name,CString descr,
				long my_begin_current,	long my_begin_line_current,	long my_begin_line_position,
			long my_end_current,	long my_end_line_current,	long my_end_line_position)
			:CMFCPropertyGridProperty(name,descr,descr)
		{
			cp=my_cp;

			begin_current=my_begin_current;
			begin_line_current=my_begin_line_current;
			begin_line_position=my_begin_line_position;

			end_current=my_end_current;
			end_line_current=my_end_line_current;
			end_line_position=my_end_line_position;
		}
		virtual void OnClickName(CPoint C)
		{
			cp->SetSel(begin_current,end_current);
		};
		virtual BOOL OnClickValue(UINT uiMsg,CPoint point)
		{
			 OnClickName(point);
			 return FALSE;
		};
		virtual BOOL OnEndEdit()
		{
			return TRUE;
		}
	};
	
	CString name,descr;

	list.RemoveAll();
	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T("出错信息"));
	
	for(int i=0;i<error_number;i++){
		name.Format(_T("%3d,%3d -%3d,%3d"),
			error_message[i].begin_line_current,error_message[i].begin_line_position,
			error_message[i].end_line_current,error_message[i].end_line_position);
		descr=error_message[i].error_message;
		
		pGroup->AddSubItem(new error_message_display(cp,name,descr,
									error_message[i].begin_current,error_message[i].begin_line_current,error_message[i].begin_line_position,
									error_message[i].end_current,error_message[i].end_line_current,error_message[i].end_line_position));
	}
	list.AddProperty(pGroup);
}

void View_Compilor::display_variable_list(CRichEditCtrl *my_cp,CMFCPropertyGridCtrl &list,variable_link_list *p,CString server_name,int run_server_port_id,int program_server_port_id)
{
	class variable_list_display:public CMFCPropertyGridProperty
	{
	public:
		int variable_id,run_server_port_id,program_server_port_id;
		CString server_name;
		
		variable_list_display(int my_variable_id,
			CString my_server_name,int my_run_server_port_id,int my_program_server_port_id,
			CString name):CMFCPropertyGridProperty(name,_T("0"),_T(" "))
		{
			variable_id=my_variable_id;
			server_name=my_server_name;
			run_server_port_id=my_run_server_port_id;
			program_server_port_id=my_program_server_port_id;
		}
		virtual void OnClickName(CPoint C)
		{
			CString str;
			str.Format(_T("%lf"),Program_controller(server_name,run_server_port_id,program_server_port_id).get_variable_value(variable_id));
			SetValue(str);
			
			CMFCPropertyGridProperty::OnClickName(C);
		};
		virtual BOOL OnEndEdit()
		{
			CString str=GetValue();
			File_data f;
			f.load_string_data(str);
			double value=0;
			sscanf_s(f.data_pointer(),"%lf",&value);
			Program_controller(server_name,run_server_port_id,program_server_port_id).set_variable_value(variable_id,value);
			return CMFCPropertyGridProperty::OnEndEdit();
		}
	};

	class break_list_display:public CMFCPropertyGridProperty
	{
		CRichEditCtrl *cp;
	public:
		int break_id,line_id,run_server_port_id,program_server_port_id;
		CString server_name;
		
		break_list_display(CRichEditCtrl *my_cp,int my_break_id,
			CString my_server_name,int my_run_server_port_id,int my_program_server_port_id,
			CString name):CMFCPropertyGridProperty(name,_T("-1"),_T(" "))
		{
			cp=my_cp;
			break_id=my_break_id;
			line_id=-1;
			server_name=my_server_name;
			run_server_port_id=my_run_server_port_id;
			program_server_port_id=my_program_server_port_id;
		}
		virtual void OnClickName(CPoint C)				
		{
			if(line_id>=0){
				int begin_char_loc=cp->LineIndex(line_id);
				int end_char_loc=cp->LineIndex(line_id+1)-1;
				cp->SetSel(begin_char_loc,end_char_loc);
			}
		};
		virtual BOOL OnClickValue(UINT uiMsg,CPoint point)
		{
			CString str;
			long begin_loc,end_loc;
			cp->GetSel(begin_loc,end_loc);

			if(line_id<0){
				line_id=(int)(cp->LineFromChar(begin_loc));
				Program_controller(server_name,run_server_port_id,program_server_port_id).set_break_point(break_id,line_id);
				str.Format(_T("%d"),line_id);
				OnClickName(point);
			}else{
				line_id=-1;
				Program_controller(server_name,run_server_port_id,program_server_port_id).set_break_point(break_id,line_id);
				str=_T("    ");
			}
			SetValue(str);
			return CMFCPropertyGridProperty::OnClickValue(uiMsg,point);
		};
	};

	list.RemoveAll();
	CMFCPropertyGridProperty* pGroup = new CMFCPropertyGridProperty(_T("变量列表"));

	for(int i=0;p!=NULL;i++,p=p->next_variable)
		pGroup->AddSubItem(new variable_list_display(i,server_name,run_server_port_id,program_server_port_id,p->var_name));

	list.AddProperty(pGroup);

	 pGroup = new CMFCPropertyGridProperty(_T("断点列表"));

	 for(int i=0;i<5;i++){
		 CString str;
		 str.Format(_T("断点:%d"),i+1);
		 pGroup->AddSubItem(new break_list_display(my_cp,i,
			server_name,run_server_port_id,program_server_port_id,str));
	 }

	 list.AddProperty(pGroup);
}