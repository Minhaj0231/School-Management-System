#include <stdio.h>
#include <string.h>
void open_fle();
void add_student(FILE *f);
void search_student(FILE *f);
void del(FILE *f,char fname[20]);
void modify(FILE *f,char fname[20]);
struct course
{
   char course_name[3];
   float cgpa;
};
struct student
{
    char name[30];
    char id[10];
    char dept[40];
    char major[15];
    char mobile_no[11];
    char ssc_gpa[4];
    char hsc_gpa[4];
};
int main()
{
    char another='y';
    struct student s;
    FILE *f,*ff;
         int a,b,c,option;
     char fname[20];
     printf(" enter 1 for file open\n      2 for creat file ");
     scanf("%d",&a);
      printf("enter the name of file\nmaximum 20 character\n(type .txt after the file name)\n");
     scanf("%s",fname);
     if(a==2){
        f=fopen(fname,"w");
        fprintf(f,"Id             NAME                               DEPERTMENT");
        fprintf(f,"                                   MAJOR               MOBILE_NO       SSC_GPA     HSC_GPA\n");
     }
     else if(a==1){
        f=fopen(fname,"r+");
     }
     fclose(f);



    printf("\n\n\t\t\t1. ADD Student");
    printf("\n\n\t\t\t2. DELETE Student");
    printf("\n\n\t\t\t3. MODIFY Student");
    printf("\n\n\t\t\t4. Search Record");
    printf("\n\n\t\t\t0. EXIT");

    printf("\n\n\t\tEnter Your Option :--> ");
    scanf("%d",&option);

    switch(option)
    {
        case 0: return 1;
                break;
        case 1: f = fopen(fname,"r+");
                add_student(f);
                fclose(f);
                break;
        case 2: fopen(fname,"r+");
                del(f,fname);
                break;
        case 3: fopen(fname,"r+") ;
                modify(f,fname);
                break;
        case 4: fopen(fname,"r+");
                search_student(f);
                fclose(f);
                break;
        default: printf("\n\t\tYou Pressed wrong key");
                  printf("\n\t\tProgram terminated");
                  system("taskkill/IM cb_console_runner.exe");
                  getch();
                  exit(0);



}
}

void add_student(FILE *f)
{
    fseek(f,0,SEEK_END);
   // fprintf(f,"\n");
    char another='y';
    struct student s ;
    while(another == 'y'||another =='Y')
    {

        fflush(stdin);
        printf("name : ");
        gets(s.name);
        printf("id : ");
        scanf("%s",s.id);
        fflush(stdin);
        printf("DEPERTMENT : ");
        gets(s.dept);
        printf("major : ");
        gets(s.major);
        printf("mobile no : ");
        scanf("%s",s.mobile_no);
        printf("SSC GPA : ");
        scanf("%s",s.ssc_gpa);
        printf("HSC GPA : ");
        scanf("%s",s.hsc_gpa);
        fprintf(f,"%s",s.id);
        fseek(f,15-strlen(s.id),SEEK_CUR);
        fprintf(f,"%s",s.name);
        fseek(f,35-strlen(s.name),SEEK_CUR);
        fprintf(f,"%s",s.dept);
        fseek(f,45-strlen(s.dept),SEEK_CUR);
        fprintf(f,"%s",s.major);
        fseek(f,20-strlen(s.major),SEEK_CUR);
        fprintf(f,"%s",s.mobile_no);
        fseek(f,16-strlen(s.mobile_no),SEEK_CUR);
        fprintf(f,"%s",s.ssc_gpa);
        fseek(f,12-strlen(s.ssc_gpa),SEEK_CUR);
        fprintf(f,"%s\n",s.hsc_gpa);
          fflush(stdin);
        printf("add another student(y/n) : ");
        scanf("%c",&another);
         fflush(stdin);
    }
}

void search_student(FILE *f)
{
    struct student s;
    int a,b,c;
    char id[10];
    char fid[10];
    char line[300];

        printf("enter the id of the student : ");
        scanf("%s",id);

        while(feof(f)==0){
            fgets(line,300,f);
            sscanf(line,"%s",fid);
            if(strcmp(id,fid)==0){
                b=1;
                break;
            }
        }
        if(b==0){
            printf("id not found\n");
        }
        else{
            sscanf(line,"%s %s %s %s %s %s %s",s.id,s.name,s.dept,s.major,s.mobile_no,s.ssc_gpa,s.hsc_gpa);
            printf("ID = %s\nNAME = %s\nDEPARTMENT = %s\nMAJOR =  %s\nMOBILE NO =%s\nSSC GPA = %s\nHSC GPA =  %s\n",s.id,s.name,s.dept,s.major,s.mobile_no,s.ssc_gpa,s.hsc_gpa);
        }


}
void del(FILE *f,char fname[20])
{
    struct student s;
        int a,b=0,c,i,j;
        char id[10];
        char fid[10];
        char line[300];
    FILE *ft;
    ft= fopen("temp2.txt","w");
    if(ft==NULL){
    printf("temporary file could not open\n");

    }
    else{
            printf("enter the id of the student : ");
            fflush(stdin);
            scanf("%s",id);

            fseek(f,0,SEEK_SET);

            while(feof(f)==0){
                fgets(line,300,f);
                sscanf(line,"%s",fid);
                if(strcmp(id,fid)==0){
                    b=1;
                    break;
                }
            }
            if(b==0){
                printf("id not found\n");
                fclose(ft);
                fclose(f);
            }
            else {
                fseek(f,0,SEEK_SET);

                do{
                    fgets(line,300,f);
                    sscanf(line,"%s",fid);
                    if(strcmp(id,fid)==0){
                    continue;
                    }
                    fputs(line,ft);
                }while(feof(f)==0);

            fclose(ft);
            fclose(f);
            remove(fname);
            rename("temp2.txt",fname);
            }

    }
}

void modify(FILE *f,char fname[20])
{
    struct student s;
        int a,b=0,c,i,j;
        char id[10];
        char fid[10];
        char line[300];
    FILE *ft;
    ft= fopen("temp2.txt","w");
    if(ft==NULL){
    printf("temporary file could not open\n");

    }
    else{
            printf("enter the id of the student : ");
            fflush(stdin);
            scanf("%s",id);

            fseek(f,0,SEEK_SET);

            while(feof(f)==0){
                fgets(line,300,f);
                sscanf(line,"%s",fid);
                if(strcmp(id,fid)==0){
                    b=1;
                    break;
                }
            }
            if(b==0){
                printf("id not found\n");
                fclose(ft);
                fclose(f);
            }
            else {
                fseek(f,0,SEEK_SET);

                do{
                    fgets(line,300,f);
                    sscanf(line,"%s",fid);
                    if(strcmp(id,fid)==0){
                    continue;
                    }
                    fputs(line,ft);
                }while(feof(f)==0);


            fprintf(ft,"\n");
            fflush(stdin);
            printf("name : ");
            gets(s.name);
            printf("id : ");
            scanf("%s",s.id);
            fflush(stdin);
            printf("DEPERTMENT : ");
            gets(s.dept);
            printf("major : ");
            gets(s.major);
            printf("mobile no : ");
            scanf("%s",s.mobile_no);
            printf("SSC GPA : ");
            scanf("%s",s.ssc_gpa);
            printf("HSC GPA : ");
            scanf("%s",s.hsc_gpa);
            fprintf(ft,"%s",s.id);
            fseek(ft,15-strlen(s.id),SEEK_CUR);
            fprintf(ft,"%s",s.name);
            fseek(ft,35-strlen(s.name),SEEK_CUR);
            fprintf(ft,"%s",s.dept);
            fseek(ft,45-strlen(s.dept),SEEK_CUR);
            fprintf(ft,"%s",s.major);
            fseek(ft,20-strlen(s.major),SEEK_CUR);
            fprintf(ft,"%s",s.mobile_no);
            fseek(ft,16-strlen(s.mobile_no),SEEK_CUR);
            fprintf(ft,"%s",s.ssc_gpa);
            fseek(ft,12-strlen(s.ssc_gpa),SEEK_CUR);
            fprintf(ft,"%s\n",s.hsc_gpa);

        fclose(ft);
        fclose(f);
        remove(fname);
        rename("temp2.txt",fname);
            }
    }

}

