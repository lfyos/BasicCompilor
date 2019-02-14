
class variable_label_head_string
{
public:
	CString directory_name;
	CString variable_struct_name,variable_pointer_name,label_head_string;
	variable_label_head_string();
};

class function_list_item
{
public:
	CString basic_function_name,c_function_name;
	int min_arg_number,max_arg_number,type_id;
	
	inline void exchange(function_list_item *p)
	{
		CString str;
		str=p->basic_function_name;		p->basic_function_name	=this->basic_function_name;		this->basic_function_name	=str;
		str=p->c_function_name;			p->c_function_name		=this->c_function_name;			this->c_function_name		=str;
		
		int x;
		x=p->min_arg_number;			p->min_arg_number		=this->min_arg_number;			this->min_arg_number		=x;
		x=p->max_arg_number;			p->max_arg_number		=this->max_arg_number;			this->max_arg_number		=x;
		x=p->type_id;					p->type_id				=this->type_id;					this->type_id		=x;
	}
};

class function_list
{
public:
	int item_number;
	function_list_item  *list_pointer;

	function_list()
	{
		CString file_name=variable_label_head_string().directory_name+_T("function.lfy");

		list_pointer=NULL;
		item_number=0;

		char buf[2000];	

		{
			ifstream f(file_name);
			for(item_number=0;;item_number++){
				int x;
				f>>buf>>buf>>buf>>x>>x;
				if((f.eof())||(f.fail()))
					break;
			}
			f.close();
		}
		if(item_number<=0)
			item_number=1;
		list_pointer=new function_list_item[item_number];

		ifstream f(file_name);
		for(int i=0;i<item_number;i++){
			const char *type_name[]={"integer_function","double_function","modifier"};
			f>>buf;	list_pointer[i].basic_function_name=CString(buf);
			f>>buf;	list_pointer[i].c_function_name=CString(buf);
			f>>buf;	
			list_pointer[i].type_id=0;
			for(int j=0;j<(sizeof(type_name)/sizeof(type_name[0]));j++)
				if(CString(buf)==CString(type_name[j])){
					list_pointer[i].type_id=j;
					break;
				}
			f>>(list_pointer[i].min_arg_number)>>(list_pointer[i].max_arg_number);
			for(int j=i;j>0;j--){
				CString str1=list_pointer[j-1].basic_function_name,str2=list_pointer[j].basic_function_name;
				if(str1<=str2){
					if(str1==str2)
						AfxMessageBox(_T("在函数表中发现相同函数名称:")+str1);
					break;
				}
				list_pointer[j-1].exchange(&(list_pointer[j]));
			}
		}
		f.close();
	}
	~function_list()
	{
		delete []list_pointer;
		list_pointer=NULL;
		item_number=0;
	}
	function_list_item *search_function(CString function_name)
	{
		for(int i=0,j=item_number-1,k;i<=j;){
			function_list_item *p=&(list_pointer[k=(i+j)/2]);
			if(p->basic_function_name==function_name)
				return p;
			else if(p->basic_function_name<function_name)
					i=k+1;
			else
					j=k-1;
		}
		return NULL;
	}
};

class output_list_item
{
public:
	CString command_name,value_function,string_function,number_string_function;

	inline void exchange(output_list_item *p)
	{
		CString str;
		
		str=this->command_name;				this->command_name			=p->command_name;				p->command_name				=str;
		str=this->value_function;			this->value_function		=p->value_function;				p->value_function			=str;
		str=this->string_function;			this->string_function		=p->string_function;			p->string_function			=str;
		str=this->number_string_function;	this->number_string_function=p->number_string_function;		p->number_string_function	=str;
	}
};

class output_list{
public:
	int item_number;
	output_list_item  *list_pointer;

	output_list()
	{
		CString file_name=variable_label_head_string().directory_name+_T("output.lfy");

		list_pointer=NULL;
		item_number=0;

		char buf[2000];	
		{
			ifstream f(file_name);
			for(item_number=0;;item_number++){
				f>>buf>>buf>>buf>>buf;
				if((f.eof())||(f.fail()))
					break;
			}
			f.close();
		}
		if(item_number<=0)
			item_number=1;
		list_pointer=new output_list_item[item_number];

		ifstream f(file_name);
		for(int i=0;i<item_number;i++){
			f>>buf;	list_pointer[i].command_name			=CString(buf);
			f>>buf;	list_pointer[i].value_function			=CString(buf);
			f>>buf;	list_pointer[i].string_function			=CString(buf);
			f>>buf;	list_pointer[i].number_string_function	=CString(buf);

			for(int j=i;j>0;j--){
				CString str1=list_pointer[j-1].command_name,str2=list_pointer[j].command_name;
				if(str1<=str2){
					if(str1==str2)
						AfxMessageBox(_T("在输出命令表中发现相同输出命令名称:")+str1);
					break;
				}
				list_pointer[j-1].exchange(&(list_pointer[j]));
			}
		}
		f.close();
	}
	~output_list()
	{
		delete []list_pointer;
		list_pointer=NULL;
		item_number=0;
	}
	output_list_item *search_command(CString command_name)
	{
		for(int i=0,j=item_number-1,k;i<=j;){
			output_list_item *p=&(list_pointer[k=(i+j)/2]);
			if(p->command_name==command_name)
				return p;
			else if(p->command_name<command_name)
					i=k+1;
			else
					j=k-1;
		}
		return NULL;
	}
};

class variable_link_list{
public:
	int type_id;
	CString var_name;
	variable_link_list *next_variable;
	
	variable_link_list(CString my_var_name,int my_type_id,variable_link_list *my_next_variable)
	{
		type_id=my_type_id;
		var_name=my_var_name;
		next_variable=my_next_variable;
	}

};

class program_base
{
	program_base *next_program;

	inline void init_program_base(View_marker *my_v_m,long my_begin_current,long my_begin_line_current,long my_begin_line_position,long my_end_current,long my_end_line_current,long my_end_line_position)
	{
		v_m=my_v_m;
	
		front_pointer=this;
		back_pointer=this;
		parent=NULL;
	
		next_program=v_m->first_program_pointer;
		v_m->first_program_pointer=this;
	
		current=v_m->current;

		begin_current=my_begin_current;
		begin_line_current=my_begin_line_current;
		begin_line_position=my_begin_line_position;

		end_current=my_end_current;
		end_line_current=my_end_line_current;
		end_line_position=my_end_line_position;

		type_id=0;
		id_name=v_m->id_name;
	}
public:

	inline program_base *get_next_program()
	{
		return next_program;
	}

	View_marker *v_m;

	int type_id;		//0:int 1:double 
	CString id_name,label_name;
		
	program_base *front_pointer,*back_pointer,*parent;
		
	long current;
	long begin_current,begin_line_current,begin_line_position;
	long end_current,end_line_current,end_line_position;
	
	program_base(View_marker *my_v_m,long my_begin_current,long my_begin_line_current,long my_begin_line_position,long my_end_current,long my_end_line_current,long my_end_line_position)
	{
		init_program_base(my_v_m,my_begin_current,my_begin_line_current,my_begin_line_position,my_end_current,my_end_line_current,my_end_line_position);
	}
	program_base(View_marker *my_v_m)
	{
		init_program_base(my_v_m,
			(my_v_m->current)-(my_v_m->lexer->yyleng),	my_v_m->line_current,		(my_v_m->line_position)-(my_v_m->lexer->yyleng),
			my_v_m->current,							my_v_m->line_current,		my_v_m->line_position);
	}

	virtual ~program_base()
	{
		if(front_pointer!=this){
			front_pointer->back_pointer=back_pointer;
			back_pointer->front_pointer=front_pointer;
		}
	}

	program_base *link_next(program_base *next_pointer)
	{
		if(next_pointer!=NULL){
			next_pointer->front_pointer=front_pointer;
			next_pointer->back_pointer=this;

			front_pointer->back_pointer=next_pointer;
			front_pointer=next_pointer;
		}
		return this;
	}
	CString create_space(int space_number)
	{
		CString str;
		for(int i=0;i<space_number;i++)
			str+=_T("\t");
		return _T("\n")+str;
	}
	virtual CString create_program(int space_number)
	{
		return _T("");
	};
	inline CString create_list_program(int space_number)
	{
		CString str,tmp,sub_str;
		program_base *p=this;
		do{
			if((sub_str=p->create_program(space_number))!=_T("")){
				tmp.Format(_T("BASIC_DEBUG_FUNCTION(%d,%d,%d,%d,%d,%d);"),
							p->begin_current,	p->begin_line_current,	p->begin_line_position,
							p->end_current,		p->end_line_current,	p->end_line_position);
				str+=create_space(space_number)+tmp+sub_str;
			}
		}while((p=p->back_pointer)!=this);
		return str;
	}
	inline void set_parent(program_base *child)
	{
		program_base *p=child;
		do{
			p->parent=this;
		}while((p=p->back_pointer)!=child);
	}
	inline program_base* output_error_message(CString error_str)
	{
		v_m->output_error_message(error_str,begin_current,begin_line_current,begin_line_position,end_current,end_line_current,end_line_position);
		return this;
	}
	inline program_base* output_error_message_at_end(CString error_str)
	{
		v_m->output_error_message(error_str,
			(v_m->current)-(v_m->lexer->yyleng),	v_m->line_current,		(v_m->line_position)-(v_m->lexer->yyleng),
			v_m->current,							v_m->line_current,		v_m->line_position);
		return this;
	}
	inline int search_label(CString &search_name)
	{
		int find_number=0;
		for(program_base *q=this;q!=NULL;q=q->parent){
			program_base *p=q;
			do{
				if(p!=this)
					if((p->label_name)==search_name)
						find_number++;
			}while((p=p->back_pointer)!=q);
		}
		return find_number;	
	}
	inline void register_variable()
	{
		for(variable_link_list *p=v_m->variable_list_pointer;p!=NULL;p=p->next_variable)
			if(p->var_name==id_name){
				if(p->type_id!=type_id){					
					CString str1=CString(_T(    "声明为"))+((p->type_id==0)?_T("整型后"):_T("浮点后"));
					CString str2=CString(_T("又被声明为"))+((   type_id==0)?_T("整型"  ):_T("浮点"  ));
					output_error_message(_T("变量")+id_name+str1+str2);
				}
				return;
			}
		v_m->variable_list_pointer=new variable_link_list(id_name,type_id,v_m->variable_list_pointer);
	}
	inline program_base* set_begin(program_base *p)
	{
		this->begin_current=p->begin_current;
		this->begin_line_current=p->begin_line_current;
		this->begin_line_position=p->begin_line_position;
		return this;
	}
	inline program_base* set_end(program_base *p)
	{
		this->end_current=p->end_current;
		this->end_line_current=p->end_line_current;
		this->end_line_position=p->end_line_position;
		return this;
	}
};

class identification_program:public program_base
{
public:
	identification_program(View_marker *my_v_m):program_base(my_v_m)
	{
		type_id=1;
		if(id_name.Right(1)==_T("#")){
			type_id=0;
			id_name=id_name.Left(id_name.GetLength()-1);
		}
	}
};

class variable_declare_program:public program_base
{
public:
	variable_declare_program(View_marker *my_v_m)
		:program_base(my_v_m)
	{
	}
	
	CString create_declare_program()
	{
		variable_label_head_string head_string;
		CString str,tmp;
		int var_number=0;

		for(variable_link_list *p=v_m->variable_list_pointer;p!=NULL;p=p->next_variable){
			str+=create_space(1);
			str+=(p->type_id==0)?_T("int "):_T("double ");
			str+=(p->var_name)+_T(";");
			var_number++;
		}
		if(var_number==0)
			str=create_space(1)+_T("int no_variable;");

		tmp=_T("struct ")+(head_string.variable_struct_name)+_T(" {");
		str=tmp+str+_T("\n};\n");
		return str;
	};

	CString create_set_get_program()
	{
		variable_label_head_string head_str;
		CString str,set_program,get_program;

		get_program =_T("\n\ndouble basic_get_function(struct ");
		get_program+=head_str.variable_struct_name+_T(" *");
		get_program+=head_str.variable_pointer_name+_T(",int get_variable_id)\n{");

		set_program =_T("\n\ndouble basic_set_function(struct ");
		set_program+=head_str.variable_struct_name+_T(" *");
		set_program+=head_str.variable_pointer_name+_T(",int set_variable_id,double set_variable_value)\n{");

		if(v_m->variable_list_pointer==NULL){
			get_program+=create_space(1)+_T("return 0;\n};\n");
			set_program+=create_space(1)+_T("return 0;\n};\n");
			return set_program+get_program;
		}
		get_program+=create_space(1)+_T("switch(get_variable_id){");
		get_program+=create_space(1)+_T("default:");


		set_program+=create_space(1)+_T("switch(set_variable_id){");
		set_program+=create_space(1)+_T("default:");

		int i;
		variable_link_list *p;

		for(i=0,p=v_m->variable_list_pointer;p!=NULL;i++,p=p->next_variable){
			str.Format(_T("case %d:"),i);
			str=create_space(1)+str;
			get_program+=str;
			set_program+=str;

			set_program+=create_space(2)+(head_str.variable_pointer_name)+_T("->")+(p->var_name);
			if(p->type_id==0)
				set_program+=_T("=(int)(set_variable_value);");
			else
				set_program+=_T("=set_variable_value;");

			str=create_space(2)+_T("return (double)(")+(head_str.variable_pointer_name)+_T("->")+p->var_name+_T(");");
			get_program+=str;
			set_program+=str;
		}
		get_program+=create_space(1)+_T("};\n};\n");
		set_program+=create_space(1)+_T("};\n};\n");

		return set_program+get_program;
	};
};

class const_program:public program_base
{
public:
	CString head_string;
	virtual CString create_program(int space_number)
	{
		CString str;
		if(type_id==0)
			str=_T("accumlator_integer=");
		else
			str=_T("accumlator_double=");
		return create_space(space_number)+str+head_string+id_name+_T(";");
	}
	const_program(View_marker *my_v_m,CString my_const_str,int my_type_id,program_base *expr_program,
		CString my_head_string=_T(""))
		:program_base(my_v_m,
						expr_program->begin_current,	expr_program->begin_line_current,	expr_program->begin_line_position,
						expr_program->begin_current,	expr_program->begin_line_current,	expr_program->begin_line_position)
	{
		id_name=my_const_str;
		head_string=my_head_string;
		type_id=my_type_id;
	}
	const_program(View_marker *my_v_m,CString my_const_str,int my_type_id,CString my_head_string=_T(""))
		:program_base(my_v_m)
	{
		id_name=my_const_str;
		head_string=my_head_string;
		type_id=my_type_id;
	}
};

class add_sub_mul_div_program:public program_base
{
	program_base *q1,*q2;
public:
	virtual CString create_program(int space_number)
	{
		CString str_space_0=create_space(space_number);
		CString str_space_1=create_space(1+space_number);
				
		CString str;
		str+=str_space_0+_T("{");
					
		if(q1->type_id==0){
			str+=str_space_1+_T("int tmp_integer;");
			str+=q1->create_program(1+space_number);
			str+=str_space_1+_T("tmp_integer=accumlator_integer;");
			str+=q2->create_program(1+space_number);
			if(q2->type_id==0)
				str+=str_space_1+_T("accumlator_integer=tmp_integer")+id_name+_T("accumlator_integer;");
			else
				str+=str_space_1+_T("accumlator_double=((double)tmp_integer)")+id_name+_T("accumlator_double;");
		}else{
			str+=str_space_1+_T("double tmp_double;");
			str+=q1->create_program(1+space_number);
			str+=str_space_1+_T("tmp_double=accumlator_double;");
			str+=q2->create_program(1+space_number);
			if(q2->type_id==0)										
				str+=str_space_1+_T("accumlator_double=tmp_double")+id_name+_T("((double)accumlator_integer);");
			else
				str+=str_space_1+_T("accumlator_double=tmp_double")+id_name+_T("accumlator_double;");
		}
		str+=str_space_0+_T("}");
		
		return str;
	}
	
	add_sub_mul_div_program(View_marker *my_v_m,CString my_type_str,program_base *p1,program_base *p2=NULL)
		:program_base(my_v_m,p1->begin_current,p1->begin_line_current,p1->begin_line_position,
				(p2==NULL)?(my_v_m->current)		:(p2->end_current),
				(p2==NULL)?(my_v_m->line_current)	:(p2->end_line_current),
				(p2==NULL)?(my_v_m->line_position)	:(p2->end_line_position))
	{
		id_name=my_type_str;
		if((q2=p2)!=NULL)
			q1=p1;
		else{
			q2=p1;
			q1=new const_program(v_m,_T("0"),0);
		}
		set_parent(q1);
		set_parent(q2);
		if((q1->type_id==0)&&(q2->type_id==0))
			type_id=0;
		else
			type_id=1;
	}
};

class relative_logic_program:public program_base
{
	program_base *q1,*q2;
public:
	virtual CString create_program(int space_number)
	{	
		CString str_space_0=create_space(space_number);
		CString str_space_1=create_space(1+space_number);
				
		CString str;
		str+=str_space_0+_T("{");
					
		if(q1->type_id==0){
			str+=str_space_1+_T("int tmp_integer;");
			str+=q1->create_program(1+space_number);
			str+=str_space_1+_T("tmp_integer=accumlator_integer;");
			str+=q2->create_program(1+space_number);
			if(q2->type_id==0)									
				str+=str_space_1+_T("accumlator_integer=")+_T("(tmp_integer")+id_name+_T("accumlator_integer)?1:0;");
			else
				str+=str_space_1+_T("accumlator_integer=")+_T("(((double)tmp_integer)")+id_name+_T("accumlator_double)?1:0;");
		}else{
			str+=str_space_1+_T("double tmp_double;");
			str+=q1->create_program(1+space_number);
			str+=str_space_1+_T("tmp_double=accumlator_double;");
			str+=q2->create_program(1+space_number);
			if(q2->type_id==0)										
				str+=str_space_1+_T("accumlator_integer=")+_T("(tmp_double")+id_name+_T("((double)accumlator_integer))?1:0;");
			else
				str+=str_space_1+_T("accumlator_integer=")+_T("(tmp_double")+id_name+_T("accumlator_double)?1:0;");			
		}
		str+=str_space_0+_T("}");
		
		return str;
	}
	relative_logic_program(View_marker *my_v_m,CString my_type_str,program_base *p1,program_base *p2=NULL)
		:program_base(my_v_m,p1->begin_current,p1->begin_line_current,p1->begin_line_position,
				(p2==NULL)?(my_v_m->current)		:(p2->end_current),
				(p2==NULL)?(my_v_m->line_current)	:(p2->end_line_current),
				(p2==NULL)?(my_v_m->line_position)	:(p2->end_line_position))
	{
		id_name=my_type_str;

		if((q2=p2)!=NULL)
			q1=p1;
		else{
			q2=p1;
			q1=new const_program(v_m,CString(_T("0")),0);
		}
		set_parent(q1);
		set_parent(q2);
		type_id=0;
	}
};

class let_sentence_program:public program_base
{
	program_base *name,*expr;
public:
	virtual CString create_program(int space_number)
	{
		CString str;

		str+=create_space(  space_number)+_T("{");
		str+=expr->create_program(1+space_number);
		str+=create_space(1+space_number)+(variable_label_head_string().variable_pointer_name)+_T("->")+(name->id_name);
		if(name->type_id==0)
			if(expr->type_id==0)
				str+=_T("=accumlator_integer;");
			else
				str+=_T("=(int)accumlator_double;");
		else{
			if(expr->type_id==0)
				str+=_T("=(double)accumlator_integer;");
			else
				str+=_T("=accumlator_double;");
		}
		str+=create_space(  space_number)+_T("}");

		return str;
	}
	let_sentence_program(View_marker *my_v_m,program_base *my_name,program_base *my_expr)
		:program_base(my_v_m,
				my_name->begin_current,my_name->begin_line_current,my_name->begin_line_position,
				my_expr->end_current,my_expr->end_line_current,my_expr->end_line_position)
	{
		my_name->register_variable();
		type_id=my_name->type_id;
		name=my_name;	set_parent(name);
		expr=my_expr;	set_parent(expr);
	}
};

class if_then_else_program:public program_base
{
	program_base *logic_expr,*then_sentence,*else_sentence;
public:
	virtual CString create_program(int space_number)
	{
		CString str_space=create_space(space_number);
		CString str;
		
		str+=logic_expr->create_program(space_number);
		str+=str_space+_T("if(accumlator_integer!=0){");
		str+=then_sentence->create_list_program(1+space_number);
		if(else_sentence!=NULL){
			str+=str_space+_T("}else{");
			str+=else_sentence->create_list_program(1+space_number);
		}
		str+=str_space+_T("}");
		
		return str;
	}
	
	if_then_else_program(View_marker *my_v_m,program_base *my_logic_expr,program_base *my_then_sentence,program_base *my_else_sentence)
		:program_base(my_v_m,
			my_logic_expr->begin_current,	my_logic_expr->begin_line_current,	my_logic_expr->begin_line_position,
			my_v_m->current,				my_v_m->line_current,				my_v_m->line_position)
	{
		logic_expr=my_logic_expr;			set_parent(logic_expr);
		then_sentence=my_then_sentence;		set_parent(then_sentence);
				
		if((else_sentence=my_else_sentence)!=NULL)
			set_parent(else_sentence);
	}
};
class for_next_program:public program_base
{
	program_base *ident,*init_expr,*let_sentence,*terminate_expr,*step_expr,*execute_sentence,*var_name;
public:
	virtual CString create_program(int space_number)
	{
		CString str;

		if((ident->id_name)!=(var_name->id_name))
				var_name->output_error_message(_T("循环变量: ")+(ident->id_name)+_T(" 和 ")+(var_name->id_name)+_T(" 名称前后不一致"));
		else if((ident->type_id)!=(var_name->type_id))
				var_name->output_error_message(_T("循环变量: ")+(ident->id_name)+_T(" 数据类型前后不一致"));
		
		str+=let_sentence->create_program(space_number);
		str+=create_space(space_number)+_T("for(;;){");

		str+=create_space(1+space_number);
		str+=((terminate_expr->type_id==0)?_T("int"):_T("double"));
		str+=_T(" tmp_ternimation;");
		str+=create_space(1+space_number);
		str+=((step_expr     ->type_id==0)?_T("int"):_T("double"));
		str+=_T(" tmp_step;");

		str+=terminate_expr->create_program(1+space_number);
		str+=create_space(1+space_number)+_T("tmp_ternimation=");
		str+=((terminate_expr->type_id==0)?_T("accumlator_integer;"):_T("accumlator_double;"));

		str+=step_expr->create_program(1+space_number);
		str+=create_space(1+space_number)+_T("tmp_step=");
		str+=((step_expr->type_id==0)?_T("accumlator_integer;"):_T("accumlator_double;"));
				
		str+=create_space(1+space_number)+_T("if(tmp_step>0){");
		str+=create_space(2+space_number)+_T("if(")+(variable_label_head_string().variable_pointer_name)+_T("->")+(var_name->id_name)+_T(">tmp_ternimation)");
		str+=create_space(3+space_number)+_T("break;");

		str+=create_space(1+space_number)+_T("}else{");
		str+=create_space(2+space_number)+_T("if(")+(variable_label_head_string().variable_pointer_name)+_T("->")+(var_name->id_name)+_T("<tmp_ternimation)");
		str+=create_space(3+space_number)+_T("break;");
		str+=create_space(1+space_number)+_T("}");

		str+=execute_sentence->create_list_program(1+space_number);

		str+=create_space(1+space_number)+(variable_label_head_string().variable_pointer_name)+_T("->")+(var_name->id_name);
		str+=((ident->type_id==0)?_T("+=(int)tmp_step;"):_T("+=(double)tmp_step;"));

		str+=create_space(space_number)+_T("}");
	
		return str;
	}
	
	class for_next_program(View_marker *my_v_m,program_base *my_ident,program_base *my_init_expr,program_base *my_terminate_expr,program_base *my_step_expr,program_base *my_execute_sentence,program_base *my_var_name)
			:program_base(my_v_m,			my_ident->begin_current,my_ident->begin_line_current,my_ident->begin_line_position,
											my_var_name->end_current,my_var_name->end_line_current,my_var_name->end_line_position)
	{
			ident=my_ident;
			init_expr=my_init_expr;
			
			let_sentence=new let_sentence_program(my_v_m,my_ident,my_init_expr);		set_parent(let_sentence);
			terminate_expr=my_terminate_expr;											set_parent(terminate_expr);
			step_expr=my_step_expr;														set_parent(step_expr);
			execute_sentence=my_execute_sentence;										set_parent(execute_sentence);
			
			var_name=my_var_name;
	}
};

class repeat_until_program:public program_base
{
public:
	program_base *sentence_sequence,*logic_expr;
	
	virtual CString create_program(int space_number)
	{
		CString str;
		
		str+=create_space(space_number)+_T("for(;;){\n");
		
		if(sentence_sequence!=NULL)
			str+=sentence_sequence->create_list_program(1+space_number);
			
		str+=logic_expr->create_program(1+space_number);
		
		str+=create_space(1+space_number)+_T("if(accumlator_integer!=0)");
		str+=create_space(2+space_number)+_T("break;\n");
		
		str+=create_space(space_number)+_T("}\n");
	
		return str;
	}
	repeat_until_program(View_marker *my_v_m,program_base *repeat_keyword,program_base *my_sentence_sequence,program_base *my_logic_expr)
		:program_base(my_v_m,
			repeat_keyword->begin_current,repeat_keyword->begin_line_current,repeat_keyword->begin_line_position,
			my_logic_expr->end_current,my_logic_expr->end_line_current,my_logic_expr->end_line_position)
	{
		if((sentence_sequence=my_sentence_sequence)!=NULL)
			set_parent(sentence_sequence);
		logic_expr=my_logic_expr;
		set_parent(logic_expr);
	}
};
class while_program:public program_base
{
public:
	program_base *sentence_sequence,*logic_expr;
	
	virtual CString create_program(int space_number)
	{
		CString str;
		
		str+=create_space(space_number)+_T("for(;;){");
		
		str+=logic_expr->create_program(1+space_number);
		
		str+=create_space(1+space_number)+_T("if(accumlator_integer==0)");
		str+=create_space(2+space_number)+_T("break;");
		
		str+=sentence_sequence->create_list_program(1+space_number);
	
		str+=create_space(space_number)+_T("}");
		
		return str;
	}
	while_program(View_marker *my_v_m,program_base *while_keyword,program_base *my_sentence_sequence,program_base *my_logic_expr)
		:program_base(my_v_m,
					while_keyword->begin_current,	while_keyword->begin_line_current,	while_keyword->begin_line_position,
					my_v_m->current,				my_v_m->line_current,				my_v_m->line_position)

	{
		sentence_sequence=my_sentence_sequence;		set_parent(sentence_sequence);
		logic_expr=my_logic_expr;					set_parent(logic_expr);
	}
};

class label_defination_program:public program_base
{
public:
	virtual CString create_program(int space_number)
	{
		if(search_label(id_name)!=0)
			output_error_message(_T("转移标号 ")+(id_name)+_T("定义了多次"));
		return create_space(space_number)+(variable_label_head_string().label_head_string)+label_name+_T(":");
	}
	label_defination_program(View_marker *my_v_m,program_base *label_id)
		:program_base(my_v_m,
				label_id->begin_current,label_id->begin_line_current,label_id->begin_line_position,
				my_v_m->current,my_v_m->line_current,my_v_m->line_position)
	{
		id_name=label_id->id_name;
		label_name=label_id->id_name;
	}
};

class goto_program:public program_base
{
public:
	virtual CString create_program(int space_number)
	{
		switch(search_label(id_name)){
		case 0:
			this->output_error_message(_T("转移标号 ")+(this->id_name)+_T(" 没有定义或定义在语句内部"));
			break;
		case 1:
			break;
		default:
			this->output_error_message(_T("转移标号 ")+(this->id_name)+_T("定义了多次"));
			break;
		}
		return create_space(space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+id_name+_T(";");
	}
	goto_program(View_marker *my_v_m,program_base *goto_keyword,program_base *label_id)
		:program_base(my_v_m,			goto_keyword->begin_current,	goto_keyword->begin_line_current,	goto_keyword->begin_line_position,
										label_id->end_current,			label_id->end_line_current,			label_id->end_line_position)
	{
		id_name=label_id->id_name;
	}
};

class gosub_program:public program_base
{
public:
	virtual CString create_program(int space_number)
	{
		switch(search_label(id_name)){
		case 0:
			this->output_error_message(_T("转移标号 ")+(this->id_name)+_T(" 没有定义或定义在语句内部"));
			break;
		case 1:
			break;
		default:
			this->output_error_message(_T("转移标号 ")+(this->id_name)+_T("定义了多次"));
			break;
		}
		
		CString str;
		
		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("jmp_buf *p;");
			
		str+=create_space(1+space_number)+_T("if((p=allocate_return_slot())==NULL)");
			str+=create_space(3+space_number)+_T("longjmp(*(get_error_slot()),1);");
		str+=create_space(1+space_number)+_T("else if(setjmp(*p)==0)");
		str+=create_space(3+space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+id_name+_T(";");
			
		str+=create_space(  space_number)+_T("}");
		return str;
	}
	gosub_program(View_marker *my_v_m,program_base *gosub_keyword,program_base *label_id)
		:program_base(my_v_m,
			gosub_keyword->begin_current,	gosub_keyword->begin_line_current,	gosub_keyword->begin_line_position,
			label_id->end_current,			label_id->end_line_current,			label_id->end_line_position)
	{
		id_name=label_id->id_name;
	}
};

class on_goto_program:public program_base
{
	program_base *expr,*id_list;
public:
	CString create_program(int space_number)
	{
		int i=0;
		CString str,tmp;
		
		str+=expr->create_program(space_number);
		if(expr->type_id==0)
			str+=create_space(space_number)+_T("switch(accumlator_integer){");
		else
			str+=create_space(space_number)+_T("switch((int)accumlator_double){");
		
		program_base *p=id_list;
		do{	
			switch(search_label(p->id_name)){
			case 0:
				p->output_error_message(_T("转移标号 ")+(p->id_name)+_T(" 没有定义或定义在语句内部"));
				break;
			case 1:
				break;
			default:
				p->output_error_message(_T("转移标号 ")+(p->id_name)+_T("定义了多次"));
				break;
			}
	
			tmp.Format(_T("case %d:"),i++);
			str+=create_space(space_number)+tmp;
			str+=create_space(1+space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+(p->id_name)+_T(";");

		}while((p=p->back_pointer)!=id_list);
	
		str+=create_space(space_number)+_T("}");
		return str;
	}
	on_goto_program(View_marker *my_v_m,program_base *on_keyword,program_base *my_expr,program_base *my_id_list)
		:program_base(my_v_m,
			on_keyword->begin_current,				on_keyword->begin_line_current,					on_keyword->begin_line_position,
			my_id_list->front_pointer->end_current,	my_id_list->front_pointer->end_line_current,	my_id_list->front_pointer->end_line_position)
	{
		expr=my_expr;
		id_list=my_id_list;	
	}
};

class on_gosub_program:public program_base
{
	program_base *expr,*id_list;
public:
	CString create_program(int space_number)
	{
		int i=0;
		CString str,tmp;
		
		str+=expr->create_program(space_number);

		str+=create_space(space_number)+_T("{");
		str+=create_space(1+space_number)+_T("jmp_buf *p;");

		if(expr->type_id!=0)
			str+=create_space(1+space_number)+_T("switch((int)accumlator_double){");
		else
			str+=create_space(1+space_number)+_T("switch(accumlator_integer){");

		program_base *p=id_list;
		
		do{	
			switch(search_label(p->id_name)){
			case 0:
				p->output_error_message(_T("转移标号 ")+(p->id_name)+_T(" 没有定义或定义在语句内部"));
				break;
			case 1:
				break;
			default:
				p->output_error_message(_T("转移标号 ")+(p->id_name)+_T("定义了多次"));
				break;
			}	
			tmp.Format(_T("case %d:"),i++);
			str+=create_space(1+space_number)+tmp;
			str+=create_space(2+space_number)+_T("if((p=allocate_return_slot())==NULL)");

				str+=create_space(4+space_number)+_T("longjmp(*(get_error_slot()),1);");

			str+=create_space(2+space_number)+_T("else if(setjmp(*p)==0)");
			str+=create_space(4+space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+(p->id_name)+_T(";");

			str+=create_space(2+space_number)+_T("break;");

		}while((p=p->back_pointer)!=id_list);

		str+=create_space(1+space_number)+_T("}");
		str+=create_space(space_number)+_T("}");

		return str;
	}
	on_gosub_program(View_marker *my_v_m,program_base *on_keyword,program_base *my_expr,program_base *my_id_list)
		:program_base(my_v_m,
			on_keyword->begin_current,					on_keyword->begin_line_current,					on_keyword->begin_line_position,
			my_id_list->front_pointer->end_current,		my_id_list->front_pointer->end_line_current,	my_id_list->front_pointer->end_line_position)
	{
		expr=my_expr;
		id_list=my_id_list;	
	}
};

class return_program:public program_base
{
public:
	CString create_program(int space_number)
	{
		CString str;
		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("jmp_buf *p;");
		str+=create_space(1+space_number)+_T("if((p=release_return_slot())!=NULL)");
			str+=create_space(2+space_number)+_T("longjmp(*p,1);");	
		str+=create_space(1+space_number)+_T("else if((p=allocate_return_slot())!=NULL){");
			str+=create_space(2+space_number)+_T("if(setjmp(*p)==0)");
				str+=create_space(3+space_number)+_T("longjmp(*(get_error_slot()),1);");
		str+=create_space(1+space_number)+_T("}else");
			str+=create_space(2+space_number)+_T("longjmp(*(get_error_slot()),1);");
		str+=create_space(  space_number)+_T("}");

		return str;
	}
	return_program(View_marker *my_v_m)
		:program_base(my_v_m,
			(my_v_m->current)-(my_v_m->lexer->yyleng),	my_v_m->line_current,		(my_v_m->line_position)-(my_v_m->lexer->yyleng),
			my_v_m->current,							my_v_m->line_current,		my_v_m->line_position)
	{
	
	}		
};

class on_error_goto_program:public program_base
{
	program_base *label_program;
public:
	CString create_program(int space_number)
	{
		int i=0;
		CString str;
	
		switch(search_label(label_program->id_name)){
		case 0:
			label_program->output_error_message(_T("转移标号 ")+(label_program->id_name)+_T(" 没有定义或定义在语句内部"));
			break;
		case 1:
			break;
		default:
			label_program->output_error_message(_T("转移标号 ")+(label_program->id_name)+_T("定义了多次"));
			break;
		}	
		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("if(setjmp(*(get_error_slot()))!=0)");
		str+=create_space(2+space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+(label_program->id_name)+_T(";");
			
		str+=create_space(  space_number)+_T("}");
	
		return str;
	}
	on_error_goto_program(View_marker *my_v_m,program_base *on_keyword,program_base *my_label_program)
		:program_base(	my_v_m,		on_keyword->begin_current,			on_keyword->begin_line_current,			on_keyword->begin_line_position,
									my_label_program->end_current,		my_label_program->end_line_current,		my_label_program->end_line_position)
	{
		label_program=my_label_program;	
	}
};

class on_error_gosub_program:public program_base
{
	program_base *label_program;
public:
	CString create_program(int space_number)
	{
		int i=0;
		CString str;
	
		switch(search_label(label_program->id_name)){
		case 0:
			label_program->output_error_message(_T("转移标号 ")+(label_program->id_name)+_T(" 没有定义或定义在语句内部"));
			break;
		case 1:
			break;
		default:
			label_program->output_error_message(_T("转移标号 ")+(label_program->id_name)+_T("定义了多次"));
			break;
		}	
		str+=create_space(  space_number)+_T("{");
			str+=create_space(1+space_number)+_T("if(setjmp(*(get_error_slot()))!=0){");
				str+=create_space(2+space_number)+_T("jmp_buf *p=allocate_return_slot();");
				str+=create_space(2+space_number)+_T("if(p!=NULL)");
					str+=create_space(3+space_number)+_T("if(setjmp(*p)==0)");
						str+=create_space(4+space_number)+_T("goto ")+(variable_label_head_string().label_head_string)+(label_program->id_name)+_T(";");

				str+=create_space(2+space_number)+_T("for(;;)");
					str+=create_space(3+space_number)+_T("if((p=release_return_slot())!=NULL)");
						str+=create_space(4+space_number)+_T("longjmp(*p,1);");
					str+=create_space(3+space_number)+_T("else");
						str+=create_space(4+space_number)+_T("return ;");
				
			str+=create_space(1+space_number)+_T("}");
		str+=create_space(  space_number)+_T("}");
	
		return str;
	}
	on_error_gosub_program(View_marker *my_v_m,program_base *on_keyword,program_base *my_label_program)
		:program_base(	my_v_m,
						on_keyword->begin_current,			on_keyword->begin_line_current,			on_keyword->begin_line_position,
						my_label_program->end_current,		my_label_program->end_line_current,		my_label_program->end_line_position)
	{
		label_program=my_label_program;	
	}
};

class function_name_program:public program_base
{
public:
	function_list_item *function_item;
	function_name_program(View_marker *my_v_m):program_base(my_v_m)
	{
		function_item=v_m->function_item;
		type_id=function_item->type_id;
	}
};

class function_call_program:public program_base
{
public:
	function_name_program *function_name;
	int argument_number;
	program_base *expr_list,*result_program,*modify_program_list;

	virtual CString create_program(int space_number)
	{
		CString str,tmp;

		if(argument_number<(function_name->function_item->min_arg_number)){
			tmp.Format(_T("至少需要%d个参数，程序仅仅给出了%d参数"),function_name->function_item->min_arg_number,argument_number);
			((expr_list!=NULL)?expr_list:function_name)->output_error_message(_T("函数")+(function_name->id_name)+tmp);
		}
		if(argument_number>(function_name->function_item->max_arg_number)){
			tmp.Format(_T("最多需要%d个参数，程序却给出了%d参数"),function_name->function_item->max_arg_number,argument_number);
			((expr_list!=NULL)?expr_list:function_name)->output_error_message(_T("函数")+(function_name->id_name)+tmp);
		}
		str+=create_space(  space_number)+_T("{");

		tmp.Format(_T("tmp_double_array[%d];"),(argument_number<1)?1:argument_number);
		tmp=((result_program==NULL)?_T("double "):_T("double tmp_result_value,"))+tmp;
		str+=create_space(1+space_number)+tmp;

		if(argument_number>0){
			program_base *p=expr_list;
			for(int i=0;i<argument_number;i++,p=p->back_pointer){
				if(p->type_id==0)
					tmp.Format(_T("tmp_double_array[%d]=(double)accumlator_integer;"),i);
				else
					tmp.Format(_T("tmp_double_array[%d]=accumlator_double;"),i);
				str+=p->create_program(1+space_number);
				str+=   create_space(1+space_number)+tmp;
			}
		}
		if(result_program==NULL)
			tmp.Format(_T("(%d,tmp_double_array,NULL);"),argument_number);
		else{
			str+=result_program->create_program(1+space_number)+create_space(1+space_number);
			if(result_program->type_id==0)
				str+=_T("tmp_result_value=(double)accumlator_integer;");
			else
				str+=_T("tmp_result_value=accumlator_double;");
			tmp.Format(_T("(%d,tmp_double_array,&tmp_result_value);"),argument_number);
		}
		if(modify_program_list!=NULL){
			program_base *p=modify_program_list;
			do{
				str+=p->create_program(1+space_number);
			}while((p=p->back_pointer)!=modify_program_list);
		}
		str+=create_space(1+space_number);
		str+=((type_id==0)?_T("accumlator_integer="):_T("accumlator_double="));
		str+=(function_name->function_item->c_function_name)+tmp;
		
		if(modify_program_list!=NULL)
			str+=create_space(1+space_number)+_T("modifier_terminated();");
		
		str+=create_space(  space_number)+_T("}");
		return str;
	}
	function_call_program(View_marker *my_v_m,
				function_name_program *my_function_name,program_base *my_expr_list,
				program_base *my_result_program,program_base *my_modify_program_list)
		:program_base(my_v_m,		my_function_name->begin_current,	my_function_name->begin_line_current,	my_function_name->begin_line_position,
									my_v_m->current,					my_v_m->line_current,					my_v_m->line_position)
	{	
		type_id=my_function_name->type_id;
		
		function_name=my_function_name;
		set_parent(my_function_name);

		argument_number=0;
		if((expr_list=my_expr_list)!=NULL){
			program_base *p=my_expr_list;
			set_parent(my_expr_list);
			do{
				argument_number++;
			}while((p=p->back_pointer)!=expr_list);
		}
		result_program		=my_result_program;
		modify_program_list	=my_modify_program_list;
	}
};

class output_name_program:public program_base
{
public:
	CString channel_name;
	output_list_item *output_item;
	output_name_program(View_marker *my_v_m):program_base(my_v_m)
	{
		channel_name=_T("0");
		output_item=v_m->output_item;
		type_id=0;
	}
};

class output_program:public program_base
{
public:
	CString channel_name;
	program_base *format_argument_1,*format_argument_2;
	int end_flag;
	output_list_item *output_item;

	output_program(View_marker *my_v_m,output_name_program *my_name):program_base(my_v_m)
	{
		format_argument_1=NULL;
		format_argument_2=NULL;
		end_flag=0;
		output_item=my_name->output_item;
		channel_name=my_name->channel_name;
	}
	output_program *set_format(program_base * my_format_argument_1,program_base * my_format_argument_2)
	{
		format_argument_1=my_format_argument_1;
		format_argument_2=my_format_argument_2;
		return this;
	}
	output_program *set_end_flag(int new_end_flag)
	{
		end_flag=new_end_flag;
		return this;
	}
};

class output_value_program:public output_program
{
	program_base *value_program;
public:
	virtual CString create_program(int space_number)
	{
		CString str,tmp,str0,str1,str2;

		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("double tmp_value=0,tmp_format_1=(-1.0),tmp_format_2=(-1.0);");

		if(value_program!=NULL){
			str+=value_program->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_value=");
			str+=((value_program->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}

		if(format_argument_1!=NULL){
			str+=format_argument_1->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_1=");
			str+=((format_argument_1->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		if(format_argument_2!=NULL){
			str+=format_argument_2->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_2=");
			str+=((format_argument_2->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		str+=create_space(1+space_number)+(output_item->value_function)+_T("(tmp_value,");
		tmp.Format(_T(",tmp_format_1,tmp_format_2,%d);"),end_flag);
		str+=channel_name+tmp;
		str+=create_space(  space_number)+_T("}");
		return str;
	}
	output_value_program(View_marker *my_v_m,output_name_program *my_name,program_base *my_value_program):output_program(my_v_m,my_name)
	{
		value_program=my_value_program;
		if(value_program!=NULL)
			set_end(value_program);
	}
};

class output_number_string_program:public output_program
{
	CString print_type;
	program_base *value_program;
public:
	virtual CString create_program(int space_number)
	{
		CString str,tmp,str0,str1,str2;

		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("double tmp_value=0,tmp_format_1=(-1.0),tmp_format_2=(-1.0);");

		if(value_program!=NULL){
			str+=value_program->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_value=");
			str+=((value_program->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		if(format_argument_1!=NULL){
			str+=format_argument_1->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_1=");
			str+=((format_argument_1->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		if(format_argument_2!=NULL){
			str+=format_argument_2->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_2=");
			str+=((format_argument_2->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		tmp.Format(_T("%d);"),end_flag);
		str+=create_space(1+space_number)+(output_item->number_string_function)+_T("(tmp_value,");
		str+=print_type+_T(",")+channel_name+_T(",tmp_format_1,tmp_format_2,")+tmp;
		str+=create_space(  space_number)+_T("}");
		return str;
	}
	output_number_string_program(View_marker *my_v_m,output_name_program *my_name,program_base *my_value_program,CString my_print_type):output_program(my_v_m,my_name)
	{
		value_program=my_value_program;
		print_type=my_print_type;
		if(value_program!=NULL)
			set_end(value_program);
	}
};

class output_string_program:public output_program
{
public:
	virtual CString create_program(int space_number)
	{
		CString str,tmp,str0,str1,str2;

		str+=create_space(  space_number)+_T("{");
		str+=create_space(1+space_number)+_T("double tmp_format_1=(-1.0),tmp_format_2=(-1.0);");
		
		if(format_argument_1!=NULL){
			str+=format_argument_1->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_1=");
			str+=((format_argument_1->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}
		if(format_argument_2!=NULL){
			str+=format_argument_2->create_program(1+space_number);
			str+=create_space(1+space_number)+_T("tmp_format_2=");
			str+=((format_argument_2->type_id==0)?_T("(double)accumlator_integer;"):_T("accumlator_double;"));
		}

		str+=create_space(1+space_number)+(output_item->string_function)+_T("(")+_T("\"")+(this->id_name)+_T("\",");
		
		tmp.Format(_T("%d);"),end_flag);
		str+=channel_name+_T(",tmp_format_1,tmp_format_2,")+tmp;
		str+=create_space(  space_number)+_T("}");
		return str;
	}
	output_string_program(View_marker *my_v_m,output_name_program *my_name):output_program(my_v_m,my_name)
	{

	}
};

class input_name_program:public program_base
{
public:
	CString channel_name;
	
	virtual CString create_program(int space_number)
	{
		CString str;
		str+=create_space(space_number);
		str+=((type_id==0)?_T("accumlator_integer="):_T("accumlator_double="));
		str+=id_name+_T("(")+(channel_name)+_T(");");
		return str;
	}
	input_name_program(View_marker *my_v_m):program_base(my_v_m)
	{
		channel_name=_T("0");
		id_name=v_m->function_item->c_function_name;
		type_id=(v_m->function_item->type_id==0)?0:1;
	}
};

class in_out_program:public program_base
{
public:
	program_base *in_out_keyword,*in_out_list;

	virtual CString create_program(int space_number)
	{
		CString str;
		program_base *p=in_out_list;
		do{
			str+=p->create_program(space_number);
			p=p->back_pointer;
		}while(p!=in_out_list);
		return str;
	}
	in_out_program(View_marker *my_v_m,program_base *my_in_out_keyword,program_base *my_in_out_list):program_base(my_v_m)
	{
		in_out_keyword=my_in_out_keyword;
		in_out_list=my_in_out_list;
		set_begin(in_out_keyword);
		set_end(in_out_list->front_pointer);
	}
};

