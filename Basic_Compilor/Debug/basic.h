struct variable_struct {
	double z;
	double y;
	double x;
};


extern jmp_buf *get_error_slot();
extern jmp_buf *allocate_return_slot();
extern jmp_buf *release_return_slot();
extern void modifier_terminated();

void *memset(void *s, int ch, unsigned n);
 