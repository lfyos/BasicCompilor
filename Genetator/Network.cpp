#include "StdAfx.h"

#include "const.h"
#include "File_data.h"
#include "Network.h"

Run_program_client::Run_program_client(int port_id,CString service_name,CString data_str)
{
	File_data f_data;
	f_data.load_string_data(data_str);
	init(port_id,service_name,f_data.data_pointer(),f_data.data_length());
}
Run_program_client::Run_program_client(int port_id,CString service_name,char *data,int data_length)
{
	init(port_id,service_name,data,data_length);
}
void Run_program_client::init(int port_id,CString service_name,char *data,int data_length)
{
	int socket_id;
	struct sockaddr_in network_address;
	struct hostent *host_info;

	reply_length=0;
	reply_data=NULL;
	socket_id=-1;

	if((data_length<=0)||(data==NULL))
		return;

	if((socket_id=::socket(AF_INET,SOCK_STREAM,0))<0){
		socket_id=-1;
		return;
	}

	File_data f_address;
	f_address.load_string_data(service_name);

	if((host_info=::gethostbyname(f_address.data_pointer()))==NULL){
		::closesocket(socket_id);
		socket_id=-1;
		return;
	}
	network_address.sin_family = AF_INET;
	network_address.sin_port = ::htons(port_id);
	network_address.sin_addr = *((struct in_addr *)host_info->h_addr);
	::memset(&(network_address.sin_zero),'\0',8);

	if(::connect(socket_id,(struct sockaddr *)(&network_address),sizeof(network_address))<0){
		::closesocket(socket_id);
		socket_id=-1;
		return;
	}

	if((data_length=::send(socket_id,data,data_length,0))<=0){
		::closesocket(socket_id);
		socket_id=-1;
		return;
	}
	char *data_buffer=new char[MAX_NETWORK_BUFFER_LENGTH];
	if((reply_length=::recv(socket_id,data_buffer,MAX_NETWORK_BUFFER_LENGTH,0))>0){
		reply_data=new char[reply_length+4];
		::memcpy(reply_data,data_buffer,reply_length);
		reply_data[reply_length+0]='\0';
		reply_data[reply_length+1]='\0';
		reply_data[reply_length+2]='\0';
	}
	delete []data_buffer;
	::closesocket(socket_id);
	socket_id=-1;
	return;
}
 bool Run_program_client::tranfer_file_data(int port_id,CString server_name,CString &file_data,CString file_name,int max_packet_length)
 {
	File_data f;
	f.load_string_data(file_data);
	return Run_program_client::tranfer_file_data(port_id,server_name,f,file_name,max_packet_length);
 }
 bool Run_program_client::tranfer_file_data(int port_id,CString server_name,	File_data &f,				CString file_name,int max_packet_length)
 {
	 return Run_program_client::tranfer_file_data(port_id,server_name,f.data_pointer(),f.data_length(),file_name,max_packet_length);
 }
 bool Run_program_client::tranfer_file_data(int port_id,CString server_name,char *data,int data_length,CString file_name,int max_packet_length)
 {
	char *buffer_pointer=new char[max_packet_length+1];

	for(int i=0,length=0;i<data_length;i+=max_packet_length){
		if((length=data_length-i)>max_packet_length)
			length=max_packet_length;
		memcpy(buffer_pointer+1,data+i,length);
		buffer_pointer[0]=((i==0)?'s':'a');
		
		Run_program_client a(port_id,server_name,buffer_pointer,length+1);
		if((a.reply_data==NULL)||(a.reply_length<=0)){
			delete[]buffer_pointer;
			AfxMessageBox(_T("传输文件")+file_name+_T("失败"));
			return false;
		}
		if(CString(a.reply_data)!=_T("success")){
			delete[]buffer_pointer;
			AfxMessageBox(_T("传输文件")+file_name+_T("没有成功"));
			return false;
		}
	}
	{
		Run_program_client a(port_id,server_name,_T("n")+file_name);
		if((a.reply_data==NULL)||(a.reply_length<=0)){
			delete[]buffer_pointer;
			AfxMessageBox(_T("命名文件")+file_name+_T("失败"));
			return false;
		}
		if(CString(a.reply_data)!=_T("success")){
			delete[]buffer_pointer;
			AfxMessageBox(_T("命名文件")+file_name+_T("没有成功"));
			return false;
		}
	}
	delete[]buffer_pointer;
	return true;
 }
