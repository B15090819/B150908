/*li12_1.c*/  
#include<stdio.h>  
#include<stdlib.h>  
#include"file.h"  
#include"book.h"  
void printHead( )/*��ӡͼ����Ϣ�ı�ͷ*/  
{
     printf("%8s%10s%8s%6s%8s%6s\n","���","����","���","������","����","Ӫҵ��");  
}   
void menu( )         /*����˵�����*/  
{  
 printf("******** 1. ��ʾ������Ϣ ********\n");  
 printf("******** 2. ͼ���������� ********\n");  
 printf("******** 3. ͼ����Ϣ��ѯ ********\n");  
printf("******** 0. �˳�         ********\n");  
 } 
 void menuBase( )     /*2��������Ϣ����˵�����*/  
 {  
 		printf("%%%%%%%% 1. ���ͼ����Ϣ %%%%%%%%\n");  
 		printf("%%%%%%%% 2. ɾ��ͼ����Ϣ %%%%%%%%\n");  
 		printf("%%%%%%%% 3. �޸�ͼ����Ϣ %%%%%%%%\n");
printf("%%%%%%%% 4. ά��ͼ����Ϣ%%%%%%%%\n");  
 		printf("%%%%%%%% 0. �����ϲ�˵� %%%%%%%%\n");  
 }  
 void menuScore( )     /*3��ͼ�������˵�����*/  
 {  
 		printf("@@@@@@@@ 1. �������� @@@@@@@@\n");  
 		printf("@@@@@@@@ 2. ������������ @@@@@@@@\n");  
 		printf("@@@@@@@@ 0. �����ϲ�˵� @@@@@@@@\n");  
 }    
 void menuCount( )    /*4��ͼ��Ӫҵ��˵�����*/  
 {  
 		printf("&&&&&&&& 1. ��Ӫҵ�����ͼ�� &&&&&&&&\n");  
 		printf("&&&&&&&& 2. ��Ӫҵ�����ͼ�� &&&&&&&&\n");  
 		printf("&&&&&&&& 0. �����ϲ�˵� &&&&&&&&\n");  
 }  
   
 void menuSearch()    /*5������������ѯ�˵�����*/  
 {  
 	    printf("######## 1. ����Ų�ѯ   ########\n");  
 		printf("######## 2. ��������ѯ   ########\n");  
 		printf("######## 3. ����������ѯ   ########\n");  
	    printf("######## 0. �����ϲ�˵� ########\n");  
 }  
  
 int baseManage(Book bk[],int n)    	     /*�ú�����ɻ�����Ϣ����*/  
 /*����Ž��в���ɾ���޸ģ���Ų����ظ�*/  
 {    
 	int choice,t,find[NUM];  
    Book s;  
    do  
	{     
     menuBase( );                  /*��ʾ��Ӧ�Ķ����˵�*/  
     printf("choose one operation you want to do:\n");  
     scanf("%d",&choice);	          /*����ѡ��*/  
	 switch(choice)  
		  {  
 		   case 1:	 readBook(&s,1);       /*����һ���������ͼ���¼*/  
			   n=insertBook(bk,n,s);   /*���ú�������ͼ���¼*/  
 					 break;  
		   case 2:  printf("Input the number deleted\n");  
 					 scanf("%ld",&s.num);  /*����һ����ɾ����ͼ��ѧ��*/  
 					 n=deleteSBook(bk,n,s);   /*���ú���ɾ��ָ��ѧ�ŵ�ѧ����¼*/  
 					 break;  
 		   case 3:  printf("Input the number modified\n");  
 					 scanf("%ld",&s.num);  /*����һ�����޸ĵ�ѧ��ѧ��*/  
 				      t=searchBook(bk,n,s,1,find) ; /*���ú�������ָ��ͼ��ļ�¼*/  
 				      if (t)                 /*����ñ�ŵļ�¼����*/  
 					 {  
 						  readBook (&s,1);   /*����һ��������ͼ���¼��Ϣ*/  
 					      bk[find[0]]=s;    /*���ն���ļ�¼��ֵ����Ҫ�޸ĵ������¼*/ 					   
 					  }					   
 					 else                 /*����ñ�ŵļ�¼������*/   
  printf("this book is not in,can not be modified.\n"); /*�����ʾ��Ϣ*/  
 					 break;  
 			    case 0: break;  
 		   }  
 	}while(choice);  
 return n;                             /*���ص�ǰ�����������ʵ�ʼ�¼����*/  
 }  
 void scoreManage(Book bk[],int n)          /*�ú������ͼ������������*/  
 {    
 	int choice;  
 	do  
 	{  
 		menuScore( );                        /*��ʾ��Ӧ�Ķ����˵�*/  
 		printf("choose one operation you want to do:\n");  
 		scanf("%d",&choice);	                 /*�������ѡ��*/  
 		switch(choice)  
 		{  
 			case 1:   calcuTotal(stu,n);         /*������ͼ�������*/  
 					  break;  
 			case 2:   calcuRank(bk,n);         /*��������ͼ�������������*/  
 				      break;		  
 			case 0:   break;  
 		}  
 	}while(choice);  
 }
 
  void printMarkCourse(char *s,double m[3][3],int k)   /*��ӡ����ͨ�ú�������countManage ����*/  
 {                 /*��ʽ����k���������ͬ�����ݣ�0��1���ֱ��Ӧ����������������*/  
 int i;  
     printf(s);                                  /*�����s������������������ʾ��Ϣ*/  
     for (i=0;i<3;i++)                           /*i������һ����*/  
 		  printf("%10.2lf",m[i][k]);  
 	   printf("\n");  
 }  
   
 void countManage(Student bk[],int n)               /*�ú������Ӫҵ��ͳ�ƹ���*/  
 {  
 		int choice;  
 		double mark[3][3];  
 		do  
 		{  
 			menuCount( );                        /*��ʾ��Ӧ�Ķ����˵�*/  
 			calcuMark(mark,bk,n);                 /*���ô˺�����Ӫҵ�����ߡ����*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printMarkCourse("Ӫҵ����߷ֱ���:\n",mark,0);  /*��������*/  
 				      break;  
 				case 2:   printMarkCourse("Ӫҵ�����ͷֱַ���:\n",mark,1);  /*�����ͷ���*/  
 				      break;  
 				case 0:   break;  
 			}  
 		}while (choice);  
 }  
   
 void searchManage(Book bk[],int n)               /*�ú�����ɸ���������ѯ����*/  
 {  
     int i,choice,findnum,f[NUM];  
 Student s;  
 	   do  
 {  
 			menuSearch( );                         /*��ʾ��Ӧ�Ķ����˵�*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printf("Input a student\'s num will be searched:\n");  
 				      scanf("%ld",&s.num);         /*�������ѯͼ���ѧ��*/  
 					  break;  
 				case 2:   printf("Input a student\'s name will be searched:\n");  
 				      scanf("%s",s.name);	          /*�������ѯͼ�������*/		    
 				      break;     
 				case 3:   printf("Input a rank will be searched:\n");  
 				      scanf("%d",&s.rank);          /*�������ѯͼ�������*/  
 					  break;  
 				case 0:   break;  
 			}  
 		 	if (choice>=1&&choice<=3)  
 			{   
 				findnum=searchStu(stu,n,s,choice,f);    /*���ҵķ�������Ԫ�ص��±����f������*/  
 				if (findnum)				     /*������ҳɹ�*/  
 				{  
 			   		 printHead( );                  /*��ӡ��ͷ*/  
 					 for (i=0;i<findnum;i++)         /*ѭ������f������±�*/  
 	      	 printBook(&bk[f[i]],1);      /*ÿ�����һ����¼*/  
 				}  
 		    		else  
 			    	    printf("this record does not exist!\n"); /*������Ҳ���Ԫ�أ��������ʾ��Ϣ*/  
 		     }		  
 	    }while (choice);  
 }  
   
 int runMain(Book bk[],int n,int choice)    /*����ģ�飬��Ӧ��һ���˵����¸�����ѡ��ִ��*/  
 {  
 		switch(choice)  
 		{  
 			case 1: printHead( );           /* 1. ��ʾ������Ϣ*/  
 				 sortStu(bk,n,1);         /*�������С�����˳�������¼*/   
           	 printBook(bk,n);          /*�������С�����˳��������м�¼*/  
 					break;  
 			case 2: n=baseManage(bk,n);    /* 2. ������Ϣ����*/  
 			   	     break;  
 			case 3: scoreManage(bk,n);     /* 3. ͼ����������*/  
 					break;  
 			case 4: countManage(bk,n);     /* 4. Ӫҵ��ͳ��*/  
 					break;  
 			case 5: searchManage(bk,n);     /* 5. ����������ѯ*/  
 				     break;  
           case 0: break;  
 		}  
 		return n;  
 }  
  
 int main( )  
 {  
 	   Bookt bk[NUM];                /*����ʵ��һά����洢ͼ���¼*/  
       int choice,n;  
 	   n=readFile(bk);                  /*���ȶ�ȡ�ļ�����¼�������ظ�ֵ��n*/  
     	 if (!n)                          /*���ԭ�����ļ�Ϊ��*/  
 	     {  
 		    n=createFile(bk);              /*������Ҫ�����ļ����Ӽ����϶���һϵ�м�¼�����ļ�*/  
		 }	 	   
 	     do  
 	     {  
 	         menu();                      /*��ʾ���˵�*/  
 	         printf("Please input your choice: ");  
 	         scanf("%d",&choice);  
 	         if (choice>=0&&choice<=5)  
 	              n=runMain(bk,n,choice);    /*ͨ�����ô˺�������һ���������ѡ��ִ��*/  
 	         else   
 		          printf("error input,please input your choice again!\n");  
 	} while (choice);  
 	sortBook(bk,n,1);                   /*�����ļ�ǰ�������С��������*/   
 	     saveFile(bk,n);                   /*����������ļ�*/  
       return 0;  
 }   
