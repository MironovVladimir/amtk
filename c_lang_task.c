#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "c_lang_task.h"

int main(){
	char str[11];
	print_number_table(6,8);
	write_nils_to_head_file("myfile", 10);
	write_ones_to_tail_file("myfile", 15);
	TEST_memcpy_and_memset();
	test_read_i_string_from_file();
	return 0;
}
