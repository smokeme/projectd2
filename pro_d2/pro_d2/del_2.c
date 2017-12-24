#include <stdlib.h>
#include <stdio.h>
#include <string.h>
//project del2 
//students names:         ID:
//Lamees Almutairi        25728
//Aeshah Alhamdan         25716

typedef struct EmployeeInformationTable
	{
		
		char FirstName[10];
		char LastName[10];
		int SSN ;
		int ID;
		char Position[15];
		int Salary;
		
		
		
}EmployeeInformationTable;

typedef struct EmployeeAddressTable
	{
		
		
		char FirstName[10];
		char LastName[10];
		int ID;
		char City[10];
		char State[5];
		int Bldg;
		
		
		
}EmployeeAddressTable;

typedef struct EmployeeBenefitstable 
	{
		
		char FirstName[10];
		char LastName[10];
		int ID;
		char Position[15];
		int  Salary;
		int Bounce;
		
		
		
}EmployeeBenefitstable;

typedef struct EmployeeStatisticsTable  
	{			
		int EmployeeIDNo;
		char Position[15];
		int Salary;
		int Benefits;
		
		
}EmployeeStatisticsTable;

int MainMenu ();
void Load_Tables_file(EmployeeInformationTable * a,EmployeeAddressTable * b, EmployeeBenefitstable * c,EmployeeStatisticsTable * d, FILE * f1, FILE * f2, FILE * f3, FILE * f4 );
void Load_Queries_file(char y[100][100], FILE * fq);
void  Execute_and_Display_Screen();
void Execute_and_Store_File();
int main()
{
	int x;
	char y[100][100];
	EmployeeInformationTable * a=(EmployeeInformationTable *)malloc(countlines("EmployeeInformationTable.txt")*sizeof(EmployeeInformationTable));
	EmployeeAddressTable * b=(EmployeeAddressTable *)malloc(countlines("EmployeeAddressTable.txt")*sizeof(EmployeeAddressTable));
	EmployeeBenefitstable * c=(EmployeeBenefitstable *)malloc(countlines("EmployeeBenefitstable.txt")*sizeof(EmployeeBenefitstable));
	EmployeeStatisticsTable * d=(EmployeeStatisticsTable *)malloc(countlines("EmployeeStatisticsTable.txt")*sizeof(EmployeeStatisticsTable));
	FILE * f1=fopen("EmployeeInformationTable.txt","r");
	FILE * f2=fopen("EmployeeAddressTable.txt","r");
	FILE * f3=fopen("EmployeeBenefitstable.txt","r");
	FILE * f4=fopen("EmployeeStatisticsTable.txt","r");
	FILE * fq;
	x=MainMenu();
	
	while (x!=5){
		switch(x){
		case 1:
			f1=fopen("EmployeeInformationTable.txt","r");
	        f2=fopen("EmployeeAddressTable.txt","r");
	        f3=fopen("EmployeeBenefitstable.txt","r");
            f4=fopen("EmployeeStatisticsTable.txt","r");
			Load_Tables_file(a, b, c, d, f1, f2, f3, f4);
	        fclose(f1);
	        fclose(f2);
            fclose(f3);
            fclose(f4);
			break;
		case 2:
			fq=fopen("appendixb.txt","r");
			Load_Queries_file(y,fq);
			fclose(fq);
			break;
		case 3:
			fq=fopen("appendixb.txt","r");
			Execute_and_Display_Screen(y,fq);
			fclose(fq);
			break;
			//Execute_and_Display_Screen();
			break;
		case 4:
			//Execute_and_Store_File();
			break;
		case 5:
			system("cls");
			//Exit
			break;
	default:
		printf("\nPlease check your opction it is not valid!\n\n");
		break;
	}
		x=MainMenu();
}

	free(a);
    free(b);
    free(c);
    free(d);
    


	system("pause");
	return 0;
}
 
int countlines(char *filename)
{                                 
  FILE *fp = fopen(filename,"r");
  int ch=0;
  int lines=0;

  if (fp == NULL);
  return 0;

  lines++;
  while(!feof(fp))
{
  ch = fgetc(fp);
  if(ch == '\n')
  {
    lines++;
  }
}
  fclose(fp);
  return lines;
}

int MainMenu (){
	int a;
	printf("Please Choose One of the Options Below:\n");
	printf("1.Load Tabels Files\n");
	printf("2.Load Queries Files\n");
	printf("3.Excute and Display to Screen\n");
	printf("4.Excute and Store to File\n");
	printf("5.Exit!\n");
	scanf("%d",&a);
	return a;
}

void Load_Tables_file(EmployeeInformationTable * a,EmployeeAddressTable * b, EmployeeBenefitstable * c,EmployeeStatisticsTable * d, FILE * f1, FILE * f2, FILE * f3, FILE * f4 )
{
	int j;
	int i;
	int L=0;
	int L1=0;
	int L2=0;
	int L3=0;
	int L4=0;

	printf("\n");
	while(fscanf(f1,"%s",a[L].FirstName)!=EOF)
	{
	fscanf(f1,"%s",a[L].LastName);
	fscanf(f1,"%d",&a[L].SSN);
	fscanf(f1,"%d",&a[L].ID);
	fscanf(f1,"%s",a[L].Position);
	fscanf(f1,"%d",&a[L].Salary);
	L++;
	}
		printf("\n\t\tEmployee Information Table\t\t\n");
	for(i=0;i<L;i++)
	{
	printf("\t%s   ",a[i].FirstName);
	printf("\t%s   ",a[i].LastName);
	printf("\t%d   ",a[i].SSN);
	printf("\t%d   ",a[i].ID);
	printf("\t%s   ",a[i].Position);
	printf("\t%d  \n",a[i].Salary);
	
	
}
		
	
		while(fscanf(f2,"%s",b[L1].FirstName)!=EOF)
	{
	fscanf(f2,"%s",b[L1].LastName);
	fscanf(f2,"%d",&b[L1].ID);
	fscanf(f2,"%s",b[L1].City);
	fscanf(f2,"%s",b[L1].State);
	fscanf(f2,"%d",&b[L1].Bldg);
	L1++;
	}
	printf("\n\t\tEmployee Address Table\t\t\n");
	for(i=0;i<L1;i++)
	{

	printf("%s   ",b[i].FirstName);
	printf("\t%s    ",b[i].LastName);
	printf("\t%d    ",b[i].ID);
	printf("\t%s    ",b[i].City);
	printf("\t%s    ",b[i].State);
	printf("\t%d    \n",b[i].Bldg);
	
	
}

	while(fscanf(f3,"%s",c[L3].FirstName)!=EOF)
	{
	fscanf(f3,"%s",c[L3].LastName);
	fscanf(f3,"%d",&c[L3].ID);
	fscanf(f3,"%d",&c[L3].Salary);
	fscanf(f3,"%d",&c[L3].Bounce);
	fscanf(f3,"%s",c[L3].Position);
	
	
	L3++;
	}
	printf("\n\t\tEmployee Benefits table\t\t\n");
	for(i=0;i<L3;i++)
	{
    printf("%s ",c[i].FirstName);
	printf("\t%s ",c[i].LastName);
	printf("\t%d ",c[i].ID);
	printf("\t%d ",c[i].Salary);
	printf("\t%d ",c[i].Bounce);
	printf("\t%s \n",c[i].Position);

	}


	
	while(fscanf(f4,"%d",&d[L4].EmployeeIDNo)!=EOF)
	{
	
	fscanf(f4,"%d",&d[L4].Salary);
	fscanf(f4,"%d",&d[L4].Benefits);
	fscanf(f4,"%s",d[L4].Position);
	L4++;
	}
	printf("\n\t\tEmployee Statistics Table\t\t\n");
	for(i=0;i<L4;i++)
	{
	printf("%d   ",d[i].EmployeeIDNo);
	printf("\t%d ",d[i].Salary);
	printf("\t%d  ",d[i].Benefits);
	printf("\t%s  \n",d[i].Position);
	}
}
	
void Load_Queries_file(char y[100][100], FILE * fq)
{

	
	char *c;
	char line[256];
	
	int i=0;
	while(fgets(line ,sizeof(line),fq))
	{
		

		c = strtok(line, "  , ");
         while(c !=NULL)
          {
            printf("%s ",c);
			strcpy(y[i],c);
            c = strtok (NULL, " , ");
			i++;
		 }
    printf("\n");
	}
	
}


void  Execute_and_Display_Screen(char y[100][100], FILE * fq)
{
	char *c;
	
	char line[256];
	
	int i=0;
	while(fgets(line ,sizeof(line),fq))
	{
		

		c = strtok(line, "  , ");
         while(c !=NULL)
          {
			string x = c;
            printf("%s %s\n",c,x.Substring(0, 0));
			strcpy(y[i],c);
            c = strtok (NULL, " , ");
			i++;
		 }
    printf("\n");
	}

}


void Execute_and_Store_File()
{


}