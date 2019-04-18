#include<stdio.h>
// #include<conio.h>
#include<string.h>
#include <stdlib.h>
void main()
{
	char opcode[10],operand[10],label[10],code[10][10],ch;
	char mnemonic[10]/*[10]={"START","LDA","STA","LDCH","STCH","LDB","STB","END"}*/;
	int locctr,start,len,i=0,j=0;
	FILE *fp1,*fp2,*fp3,*fp4;
	//clrscr();
	fp1=fopen("INPUT.DAT","r");
	fp2=fopen("SYMTAB.DAT","w");
	fp3=fopen("OUT.DAT","w");
	fp4=fopen("OPTAB.DAT","r");

	//read first input line
	fscanf(fp1,"%s%s%s",label,opcode,operand);

	//if start is present
	if(strcmp(opcode,"START")==0)
	{
		start=atoi(operand);  //getting starting address
		locctr=start;  //locctr is set

		fprintf(fp3,"%s\t%s\t%s\n",label,opcode,operand);  //write listing line
		fscanf(fp1,"%s%s%s",label,opcode,operand);  //read next line
	}
	else
		locctr=0;  // since start is not present

	//till end of program
	while(strcmp(opcode,"END")!=0)
	{
		fprintf(fp3,"%d",locctr); // for loc col of program
		if(strcmp(label,"**")!=0)
			fprintf(fp2,"%s\t%d\n",label,locctr); // since no label no symtab
        //
		rewind(fp4);
        //
		fscanf(fp4,"%s",mnemonic);
        //
		while(strcmp(mnemonic,"END")!=0)
		{
			if(strcmp(opcode,mnemonic)==0)
			{
				locctr+=3;
				break;
			}
			fscanf(fp4,"%s",mnemonic);
			j++;
		}
		if(strcmp(opcode,"WORD")==0)
			locctr+=3;
		else if(strcmp(opcode,"RESW")==0)
			locctr+=(3*(atoi(operand)));
		else if(strcmp(opcode,"RESB")==0)
			locctr+=(atoi(operand));
		else if(strcmp(opcode,"BYTE")==0)
			++locctr;
		fprintf(fp3,"\t%s\t%s\t%s\n",label,opcode,operand);  //writing to intermediate file
		fscanf(fp1,"%s%s%s",label,opcode,operand);  //read next line
		j=0;
	}

	fprintf(fp3,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);  //writing last line to intermediate file
	_fcloseall();

	//to print input table
	printf("\n\nThe contents of Input Table :\n\n");
	fp1=fopen("INPUT.DAT","r");
	ch=fgetc(fp1);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp1);
	}

	//to print output table
	printf("\n\nThe contents of Output Table :\n\n\t");
	fp3=fopen("OUT.DAT","r");
	ch=fgetc(fp3);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp3);
	}
	len=locctr-start;

	printf("\nThe length of the program is %d.\n\n",len);

	//to print symtab
	printf("\n\nThe contents of Symbol Table :\n\n");
	fp2=fopen("SYMTAB.DAT","r");
	ch=fgetc(fp2);
	while(ch!=EOF)
	{
		printf("%c",ch);
		ch=fgetc(fp2);
	}
	_fcloseall();
	//getch();
}
