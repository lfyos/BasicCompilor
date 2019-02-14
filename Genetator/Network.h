class File_data;

class Run_program_client
{
	void init(int port_id,CString service_name,char *data,int data_length);
public:
	int reply_length;
	char *reply_data;

	Run_program_client(int port_id,CString service_name,char *data,int data_length);
	Run_program_client(int port_id,CString service_name,CString data_str);

	~Run_program_client()
	{
		if(reply_data!=NULL){
			delete []reply_data;
			reply_data=NULL;
		}
		reply_length=0;
	}
	static bool tranfer_file_data(int port_id,CString server_name,	CString &file_data,			CString file_name,int max_packet_length);
	static bool tranfer_file_data(int port_id,CString server_name,	char *data,int data_length,	CString file_name,int max_packet_length);
	static bool tranfer_file_data(int port_id,CString server_name,	File_data &f,				CString file_name,int max_packet_length);
};
