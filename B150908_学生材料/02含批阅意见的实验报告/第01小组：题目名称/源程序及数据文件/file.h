/*li12_1.c*/  
#include<stdio.h>  
#include<stdlib.h>  
#include"file.h"  
#include"book.h"  
void printHead( )/*打印图书信息的表头*/  
{
     printf("%8s%10s%8s%6s%8s%6s\n","编号","书名","类别","作者名","销量","营业额");  
}   
void menu( )         /*顶层菜单函数*/  
{  
 printf("******** 1. 显示基本信息 ********\n");  
 printf("******** 2. 图书销量管理 ********\n");  
 printf("******** 3. 图书信息查询 ********\n");  
printf("******** 0. 退出         ********\n");  
 } 
 void menuBase( )     /*2、基本信息管理菜单函数*/  
 {  
 		printf("%%%%%%%% 1. 添加图书信息 %%%%%%%%\n");  
 		printf("%%%%%%%% 2. 删除图书信息 %%%%%%%%\n");  
 		printf("%%%%%%%% 3. 修改图书信息 %%%%%%%%\n");
printf("%%%%%%%% 4. 维护图书信息%%%%%%%%\n");  
 		printf("%%%%%%%% 0. 返回上层菜单 %%%%%%%%\n");  
 }  
 void menuScore( )     /*3、图书销量菜单函数*/  
 {  
 		printf("@@@@@@@@ 1. 计算销量 @@@@@@@@\n");  
 		printf("@@@@@@@@ 2. 根据销量排名 @@@@@@@@\n");  
 		printf("@@@@@@@@ 0. 返回上层菜单 @@@@@@@@\n");  
 }    
 void menuCount( )    /*4、图书营业额菜单函数*/  
 {  
 		printf("&&&&&&&& 1. 求营业额最高图书 &&&&&&&&\n");  
 		printf("&&&&&&&& 2. 求营业额最低图书 &&&&&&&&\n");  
 		printf("&&&&&&&& 0. 返回上层菜单 &&&&&&&&\n");  
 }  
   
 void menuSearch()    /*5、根据条件查询菜单函数*/  
 {  
 	    printf("######## 1. 按编号查询   ########\n");  
 		printf("######## 2. 按书名查询   ########\n");  
 		printf("######## 3. 按作者名查询   ########\n");  
	    printf("######## 0. 返回上层菜单 ########\n");  
 }  
  
 int baseManage(Book bk[],int n)    	     /*该函数完成基本信息管理*/  
 /*按编号进行插入删除修改，编号不能重复*/  
 {    
 	int choice,t,find[NUM];  
    Book s;  
    do  
	{     
     menuBase( );                  /*显示对应的二级菜单*/  
     printf("choose one operation you want to do:\n");  
     scanf("%d",&choice);	          /*读入选项*/  
	 switch(choice)  
		  {  
 		   case 1:	 readBook(&s,1);       /*读入一条待插入的图书记录*/  
			   n=insertBook(bk,n,s);   /*调用函数插入图书记录*/  
 					 break;  
		   case 2:  printf("Input the number deleted\n");  
 					 scanf("%ld",&s.num);  /*读入一个待删除的图书学号*/  
 					 n=deleteSBook(bk,n,s);   /*调用函数删除指定学号的学生记录*/  
 					 break;  
 		   case 3:  printf("Input the number modified\n");  
 					 scanf("%ld",&s.num);  /*读入一个待修改的学生学号*/  
 				      t=searchBook(bk,n,s,1,find) ; /*调用函数查找指定图书的记录*/  
 				      if (t)                 /*如果该编号的记录存在*/  
 					 {  
 						  readBook (&s,1);   /*读入一条完整的图书记录信息*/  
 					      bk[find[0]]=s;    /*将刚读入的记录赋值给需要修改的数组记录*/ 					   
 					  }					   
 					 else                 /*如果该编号的记录不存在*/   
  printf("this book is not in,can not be modified.\n"); /*输出提示信息*/  
 					 break;  
 			    case 0: break;  
 		   }  
 	}while(choice);  
 return n;                             /*返回当前操作结束后的实际记录条数*/  
 }  
 void scoreManage(Book bk[],int n)          /*该函数完成图书销量管理功能*/  
 {    
 	int choice;  
 	do  
 	{  
 		menuScore( );                        /*显示对应的二级菜单*/  
 		printf("choose one operation you want to do:\n");  
 		scanf("%d",&choice);	                 /*读入二级选项*/  
 		switch(choice)  
 		{  
 			case 1:   calcuTotal(stu,n);         /*求所有图书的销量*/  
 					  break;  
 			case 2:   calcuRank(bk,n);         /*根据所有图书的销量排名次*/  
 				      break;		  
 			case 0:   break;  
 		}  
 	}while(choice);  
 }
 
  void printMarkCourse(char *s,double m[3][3],int k)   /*打印分数通用函数，被countManage 调用*/  
 {                 /*形式参数k代表输出不同的内容，0、1、分别对应最高销量、最低销量*/  
 int i;  
     printf(s);                                  /*这里的s传入的是输出分数的提示信息*/  
     for (i=0;i<3;i++)                           /*i控制哪一个月*/  
 		  printf("%10.2lf",m[i][k]);  
 	   printf("\n");  
 }  
   
 void countManage(Student bk[],int n)               /*该函数完成营业额统计功能*/  
 {  
 		int choice;  
 		double mark[3][3];  
 		do  
 		{  
 			menuCount( );                        /*显示对应的二级菜单*/  
 			calcuMark(mark,bk,n);                 /*调用此函数求营业额的最高、最低*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printMarkCourse("营业额最高分别是:\n",mark,0);  /*输出最高者*/  
 				      break;  
 				case 2:   printMarkCourse("营业额的最低分分别是:\n",mark,1);  /*输出最低分者*/  
 				      break;  
 				case 0:   break;  
 			}  
 		}while (choice);  
 }  
   
 void searchManage(Book bk[],int n)               /*该函数完成根据条件查询功能*/  
 {  
     int i,choice,findnum,f[NUM];  
 Student s;  
 	   do  
 {  
 			menuSearch( );                         /*显示对应的二级菜单*/  
 			printf("choose one operation you want to do:\n");  
 			scanf("%d",&choice);  
 			switch(choice)  
 			{  
 				case 1:   printf("Input a student\'s num will be searched:\n");  
 				      scanf("%ld",&s.num);         /*输入待查询图书的学号*/  
 					  break;  
 				case 2:   printf("Input a student\'s name will be searched:\n");  
 				      scanf("%s",s.name);	          /*输入待查询图书的姓名*/		    
 				      break;     
 				case 3:   printf("Input a rank will be searched:\n");  
 				      scanf("%d",&s.rank);          /*输入待查询图书的名次*/  
 					  break;  
 				case 0:   break;  
 			}  
 		 	if (choice>=1&&choice<=3)  
 			{   
 				findnum=searchStu(stu,n,s,choice,f);    /*查找的符合条件元素的下标存于f数组中*/  
 				if (findnum)				     /*如果查找成功*/  
 				{  
 			   		 printHead( );                  /*打印表头*/  
 					 for (i=0;i<findnum;i++)         /*循环控制f数组的下标*/  
 	      	 printBook(&bk[f[i]],1);      /*每次输出一条记录*/  
 				}  
 		    		else  
 			    	    printf("this record does not exist!\n"); /*如果查找不到元素，则输出提示信息*/  
 		     }		  
 	    }while (choice);  
 }  
   
 int runMain(Book bk[],int n,int choice)    /*主控模块，对应于一级菜单其下各功能选择执行*/  
 {  
 		switch(choice)  
 		{  
 			case 1: printHead( );           /* 1. 显示基本信息*/  
 				 sortStu(bk,n,1);         /*按编号由小到大的顺序排序记录*/   
           	 printBook(bk,n);          /*按编号由小到大的顺序输出所有记录*/  
 					break;  
 			case 2: n=baseManage(bk,n);    /* 2. 基本信息管理*/  
 			   	     break;  
 			case 3: scoreManage(bk,n);     /* 3. 图书销量管理*/  
 					break;  
 			case 4: countManage(bk,n);     /* 4. 营业额统计*/  
 					break;  
 			case 5: searchManage(bk,n);     /* 5. 根据条件查询*/  
 				     break;  
           case 0: break;  
 		}  
 		return n;  
 }  
  
 int main( )  
 {  
 	   Bookt bk[NUM];                /*定义实参一维数组存储图书记录*/  
       int choice,n;  
 	   n=readFile(bk);                  /*首先读取文件，记录条数返回赋值给n*/  
     	 if (!n)                          /*如果原来的文件为空*/  
 	     {  
 		    n=createFile(bk);              /*则首先要建立文件，从键盘上读入一系列记录存于文件*/  
		 }	 	   
 	     do  
 	     {  
 	         menu();                      /*显示主菜单*/  
 	         printf("Please input your choice: ");  
 	         scanf("%d",&choice);  
 	         if (choice>=0&&choice<=5)  
 	              n=runMain(bk,n,choice);    /*通过调用此函数进行一级功能项的选择执行*/  
 	         else   
 		          printf("error input,please input your choice again!\n");  
 	} while (choice);  
 	sortBook(bk,n,1);                   /*存入文件前按编号由小到大排序*/   
 	     saveFile(bk,n);                   /*将结果存入文件*/  
       return 0;  
 }   
