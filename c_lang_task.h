void print_number_table(short row, short col){
        int i,j;
        for(int k=1;k<=col;k++) printf("**");
        printf("*\n");
        for(i=1;i<=row;i++){
                for(j=1;j<=col;j++) printf("|%d",rand()%10);
                printf("|\n");
                if(i!=row){
                        printf("|");
                        for(int o=1;o<col;o++) printf("-+");
                        printf("-|\n");
                }else{
                        for(int o=1;o<2*(col+1);o++) printf("*");
                }
        }
        printf("\n");
}

void write_nils_to_head_file(const char* full_name, int N){
        FILE *file1;
        file1 = fopen(full_name, "w");
        for(int i =1;i<=N;i++) fprintf(file1, "%2x", 0x00);
        fclose(file1);
}

void write_ones_to_tail_file(const char* full_name, int N){
        FILE *file1;
        file1 = fopen(full_name, "a");
        for(int i =1;i<=N;i++) fprintf(file1, "%2x", 0xff);
        fclose(file1);

}

int read_i_string_from_file(const char* full_name, int i, char* out_str, int max_size){
        FILE *file1;
        char trash;
        file1 = fopen(full_name, "r");
        for(int j=1; j<=i; j++){
                trash = fgetc(file1);
                while(trash!='\n'){
                        if(trash == EOF) return 0;
                        trash = fgetc(file1);
                }
        }
        out_str[0] = fgetc(file1);
        for(int i =1; i<max_size; i++) {
                out_str[i]=fgetc(file1);
                if(out_str[i]=='\n'){
                        out_str[i]='\0';
                        return i;
                }
        }
        out_str[max_size]='\0';
        return max_size;
}

void TEST_memcpy_and_memset(void){
        int* int_array;
        double* double_array;
        char* char_array;
        char* buffer;
        int_array = (int*)malloc(40*sizeof(int));
        double_array = (double*)malloc(20*sizeof(double));
        char_array = (char*)malloc(80*sizeof(char));
        buffer = (char*)malloc(80*sizeof(char));
        memset(char_array,0x01,80);
        memset(double_array,0x00,20*sizeof(double));
        for(int i =0;i<=40;i++) int_array[i]=1;
        for(int i =0;i<=9;i++) printf("%d ", int_array[i]);
        printf("\n");
        for(int i =0;i<=9;i++) printf("%c ", char_array[i]);
        printf("\n");
        for(int i =0; i<=9;i++) printf("%f ", double_array[i]);
        printf("\n \n");
        memcpy(buffer, char_array, 80);
        memcpy(char_array, int_array, 80);
        memcpy(int_array, double_array, 80);
        memcpy(double_array, buffer, 80);
        for(int i =0;i<=9;i++) printf("%d ", int_array[i]);
        printf("\n");
        for(int i =0;i<=9;i++) printf("%c ", char_array[i]);
        printf("\n");
        for(int i =0; i<=9;i++) printf("%f ", double_array[i]);
        printf("\n");

}

void test_read_i_string_from_file(void){
        char* testbuff = (char*)malloc(30*sizeof(char));
        read_i_string_from_file("myfile2",3,testbuff,30);
        printf("%s\n", testbuff);
        free(testbuff);
        testbuff = (char*)malloc(3*sizeof(char));
        read_i_string_from_file("myfile2",3,testbuff,3);
        printf("%s\n", testbuff);
        read_i_string_from_file("myfile2",20,testbuff,3);
        printf("%s\n", testbuff);
        free(testbuff);
}

