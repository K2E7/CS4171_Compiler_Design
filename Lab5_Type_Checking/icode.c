#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//file to store the intermediate code generated
FILE *out_file;

//variables to keep track of labels for intermediate code
int interm_label = 0, temp_label = 0, backpatch_label = 0;

//variable to help create new unique temporary variables
int new_tmp_index = 1;

int temp = 0;

//stores intermediate code corresponding to a label
char *interm_table[100];

//expr_var keeps track of last assigned var in expressions/assignment
//temp_var used in backpatching
char expr_var[20], tmp_var[20];

//function to return name of new temporary variable
char *new_temp_var() {
	static char t[5];
	sprintf(t, "t%d", new_tmp_index);
	return t;
}

//function to write quadruple to output array
void generate(int label, char *str) {
	interm_table[label] = (char *)malloc((strlen(str) + 1) * sizeof(char));
	strcpy(interm_table[label], str); 
}

//function to print intermediate code to output file
void write_to_file() {
	for(int i=0;i<100;i++) {
		if(interm_table[i] != NULL) {
			fprintf(out_file, "%d: %s", i, interm_table[i]);
			free(interm_table[i]);
			interm_table[i] = NULL;
		}
	}
}

/* Intermediate Code Generation functions end */

/* Code to handle conversion of intermediate code to assembly language */

FILE *assemblyFile;

// struct to store register information
typedef struct Reg
{
    int isOccupied;
    // list of identifiers whose value is in that register
    char name[5][5];
} RegInfo;

// Registor Descriptor table (considering 4 registers: B, C, D, E)
RegInfo regDesc[4];

// counter to keep track of count of labels
int label_no = 0;

// function to return a new label name
char* getNewLabel ( )
{
    static char label[5];
    sprintf(label, "L%d", label_no);
    label_no++;
    return label;
}

//function to check if a variable is in register descriptor table
int inRegDesc ( char* var )
{
    int found = 0;
    int reg_no = -1;
    for (int i = 0; i < 4; i++)
    {
        if (found)
            break;

        if (regDesc[i].isOccupied)
        {
            for (int j = 0; j < 5; j++)
            {
                if (strlen(regDesc[i].name[j]) == 0)
                    break;

                if (strcmp(regDesc[i].name[j], var) == 0)
                {
                    found = 1;
                    reg_no = i;
                    break;
                }
            }
        }
    }
    return reg_no;
}

//function to generate the assembly language code from intermediate code
void convert () {
    const int BUFFER_SIZE = 50;
    char line_read[BUFFER_SIZE];
    size_t len = 0;
    srand(time(0));

    // Error in reading the file
    if (out_file == NULL) {
        printf("Error in opening file");
        exit(1);
    }

    // initializing the register descriptor table
    for (int i = 0; i < 4; i++)
    {
        regDesc[i].isOccupied = 0;
        for (int j = 0; j < 5; j++)
            memset(regDesc[i].name[j], 0, 5);
    }

    // initializing variable to store the tokens of a read line
    char *tokens[6];
    for (int i = 0; i < 6; i++) {
        tokens[i] = NULL;
    }

    //reading the intermediate code file
    while (fgets(line_read, BUFFER_SIZE, out_file)){
        // removing newline from the end
        line_read[strlen(line_read)-1] = '\0';

        //printf("starting read\n");
        //printf("%s: line read now\n", line_read);
        // tokenizing the string based on ' '
        char *token = strtok(line_read," ");
        int i = 0;
        while (token != NULL){
            //printf("token = %s\n", token);
            tokens[i] = (char*) malloc( 5 * sizeof(char));
            strcpy(tokens[i], token);
            
            //printf("token written = %s\n", token);
            token = strtok(NULL," ");
            i++;
        }

        //printf("i = %d\n", i);
        //skipping labels for functions or end statements or return statements
        if(tokens[1][strlen(tokens[1])-1] == ':' || strcmp(tokens[1], "end") == 0 || strcmp(tokens[1], "return") == 0) {
            continue;
        }

        /* for(int j=0;j<i;j++) {
            printf("tokens[%d] = %s\n", j, tokens[j]);
        }*/ 
        // action associated with an assignment expression
        if (strcmp(tokens[2], "=") == 0){
            //printf("= found\n");
            // handling "not"
            if (strcmp(tokens[3], "not") == 0){
                char *l1 = getNewLabel();
                char *l2 = getNewLabel();
                fprintf(assemblyFile, "LHLD %s\n", tokens[4]);
                fprintf(assemblyFile, "MOV A,M\n");
                fprintf(assemblyFile, "ADI 0\n");
                fprintf(assemblyFile, "JZ %s\n", l1);
                fprintf(assemblyFile, "MVI A,0\n");
                fprintf(assemblyFile, "JMP %s\n", l2);
                fprintf(assemblyFile, "%s: MVI A,1\n", l1);
                fprintf(assemblyFile, "%s: NOP\n", l2);

                int done = 0;
                int reg_no = 0;
                for (int i = 0; i < 4; i++){
                    if (!regDesc[i].isOccupied){
                        reg_no = i;
                        done = 1;
                        break;
                    }
                }
                if (!done)
                    reg_no = rand() % 4;

                regDesc[reg_no].isOccupied = 1;
                strcpy(regDesc[reg_no].name[0], tokens[1]);

                fprintf(assemblyFile, "MOV R%d,A\n", reg_no);
            }

            // simple assignment
            else if (tokens[4]==NULL) {
                fprintf (assemblyFile, "LHLD %s\n", tokens[3]);

                int reg_no = inRegDesc(tokens[3]);
                if (reg_no != -1)
                {
                    for(int j = 0; j < 5; j++)
                        if (strlen(regDesc[reg_no].name[j]) == 0)
                            strcpy(regDesc[reg_no].name[j], tokens[1]);
                }

                else
                {
                    int done = 0;
                    int reg_no1 = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        if (!regDesc[i].isOccupied)
                        {
                            reg_no1 = i;
                            done = 1;
                            break;
                        }
                    }
                    if (!done)
                        reg_no1 = rand() % 4;

                    regDesc[reg_no1].isOccupied = 1;
                    strcpy(regDesc[reg_no1].name[0], tokens[1]);

                    fprintf(assemblyFile, "MOV R%d,M\n", reg_no1);
                }
            }

            // handling statements of type (number+something) or (number-something)
            else if (tokens[3][0]>='0' && tokens[3][0]<='9') {
                // type (number+number) or (number-number)
                if (tokens[5][0]>='0' && tokens[5][0]<='9') {
                    fprintf(assemblyFile, "MVI A,%s\n", tokens[3]);
                    if (strcmp(tokens[4], "+") == 0)
                        fprintf(assemblyFile, "ADI %s\n", tokens[5]);
                    else
                        fprintf(assemblyFile, "SUI %s\n", tokens[5]);

                    int done = 0;
                    int reg_no = 0;
                    for (int i = 0; i < 4; i++)
                    {
                        if (!regDesc[i].isOccupied)
                        {
                            reg_no = i;
                            done = 1;
                            break;
                        }
                    }
                    if (!done)
                        reg_no = rand() % 4;

                    regDesc[reg_no].isOccupied = 1;
                    strcpy(regDesc[reg_no].name[0], tokens[1]);

                    fprintf(assemblyFile, "MOV R%d,A\n", reg_no);
                }

                // type (number+id) or (number-id)
                else {
                    int reg_no = inRegDesc(tokens[5]);
                    if (reg_no == -1) {
                        fprintf(assemblyFile, "LHLD %s\n", tokens[5]);
                        fprintf(assemblyFile, "MOV A,M\n");
                    }
                    else
                        fprintf(assemblyFile, "MOV A,R%d\n", reg_no);

                    if (strcmp(tokens[4], "+") == 0)
                        fprintf(assemblyFile, "ADI %s\n", tokens[3]);
                    else
                        fprintf(assemblyFile, "SUI %s\n", tokens[3]);

                    int done = 0;
                    reg_no = 0;
                    for (int i = 0; i < 4; i++) {
                        if (!regDesc[i].isOccupied) {
                            reg_no = i;
                            done = 1;
                            break;
                        }
                    }
                    if (!done)
                        reg_no = rand() % 4;

                    regDesc[reg_no].isOccupied = 1;
                    strcpy(regDesc[reg_no].name[0], tokens[1]);

                    fprintf(assemblyFile, "MOV R%d,A\n", reg_no);
                }
            }

            // type (id+number) or (id-number)
            else if (tokens[5][0]>='0' && tokens[5][0]<='9') {
                int reg_no = inRegDesc(tokens[3]);
                if (reg_no == -1) {
                    fprintf(assemblyFile, "LHLD %s\n", tokens[3]);
                    fprintf(assemblyFile, "MOV A,M\n");
                }
                else
                    fprintf(assemblyFile, "MOV A,R%d\n", reg_no);

                if (strcmp(tokens[4], "+")==0)
                    fprintf(assemblyFile, "ADI %s\n", tokens[5]);
                else
                    fprintf(assemblyFile, "SUI %s\n", tokens[5]);


                int done = 0;
                reg_no = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (!regDesc[i].isOccupied)
                    {
                        reg_no = i;
                        done = 1;
                        break;
                    }
                }
                if (!done)
                    reg_no = rand() % 4;

                regDesc[reg_no].isOccupied = 1;
                strcpy(regDesc[reg_no].name[0], tokens[1]);

                fprintf(assemblyFile, "MOV R%d,A\n", reg_no);
            }

            // type (id+id) or (id-id)
            else {
                int reg_no = inRegDesc(tokens[3]);
                if (reg_no == -1) {
                    fprintf(assemblyFile, "LHLD %s\n", tokens[3]);
                    fprintf(assemblyFile, "MOV A,M\n");
                }
                else
                    fprintf(assemblyFile, "MOV A,R%d\n", reg_no);

                reg_no = inRegDesc(tokens[5]);
                if (reg_no == -1)
                {
                    fprintf(assemblyFile, "LHLD %s\n", tokens[5]);
                    if (strcmp(tokens[4], "+") == 0)
                        fprintf(assemblyFile,"ADD M\n");
                    else
                        fprintf(assemblyFile,"SUB M\n");
                }
                else
                {
                    if (strcmp(tokens[4], "+") == 0)
                        fprintf(assemblyFile, "ADD R%d\n", reg_no);
                    else
                        fprintf(assemblyFile, "SUB R%d\n", reg_no);

                }

                int done = 0;
                reg_no = 0;
                for (int i = 0; i < 4; i++)
                {
                    if (!regDesc[i].isOccupied)
                    {
                        reg_no = i;
                        done = 1;
                        break;
                    }
                }
                if (!done)
                    reg_no = rand() % 4;

                regDesc[reg_no].isOccupied = 1;
                strcpy(regDesc[reg_no].name[0], tokens[1]);

                fprintf(assemblyFile,"MOV R%d,A\n",reg_no);
            }
        }

        // handling jump statements
        else {
            // unconditional jump
            if (strcmp(tokens[1], "goto") == 0)
                fprintf(assemblyFile, "JMP %s\n", tokens[2]);

            // conditional jump
            else {
                fprintf(assemblyFile, "LHLD %s\n", tokens[2]);
                fprintf(assemblyFile, "MOV A,M\n");
                fprintf(assemblyFile, "ADI 0\n");
                fprintf(assemblyFile, "JNZ %s\n", tokens[4]);
            }
        }

        // Free allocated space
        for (int i = 0; i < 6; i++)
        {
            free(tokens[i]);
            tokens[i] = NULL;
        }
    }
}

/* code to handle conversion ends */