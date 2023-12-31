#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

//中文请假管理系统
int n1=0,n2=0,n3=0;
int replace=0;
void number_w()//用额外的文件来存储用户数
{
    FILE * fp=fopen("number.txt","w");
    //学生,教师，请假表数量
    fprintf(fp,"%10d%10d%10d",n1,n2,n3);
    fclose(fp);
}
void number_r()
{
    FILE * fp=fopen("number.txt","r");
    //学生,教师，请假表数量
    fscanf(fp,"%10d%10d%10d",&n1,&n2,&n3);
    fclose(fp);
}

struct stu
{
    char id_1[100];
    char name[100];
    char password_1[100];
}s[100];
struct professor
{
    char id_2[100];
    char password_2[100];
}p[100];
struct leave
{
    char name[100];
    char time[100];
    char cause[100];
    char status[100];
}le[100];

void menu1()
{
    printf("#######账号登录注册界面######\n");
    printf("1.登录\n");
    printf("2.注册\n");
    printf("3.退出\n");
}

int content1()                                    //登录
{
    int i,rg;
    //获取注册表信息
    rg=r_situation();
                                if(0==rg)
                                                                            {
    char id_s[100],ps[100];
    printf("学号/教工号：\n");
    getchar();
    gets(id_s);
    printf("密码：\n");
    gets(ps);
    for(i=0;i<n2;i++)
    {
        if(0==strcmp(p[i].id_2,id_s))
        {
            if(0==strcmp(p[i].password_2,ps))
            {
                printf("老师您好,欢迎登录！");
                Sleep(1000);
                system("cls");
                return menu4();
            }             //返回0是退出
        }
    }
    for(i=0;i<n1;i++)
    {
         if(0==strcmp(s[i].id_1,id_s))
        {
              if(0==strcmp(s[i].password_1,ps))
                {printf("学生您好,欢迎登录！");
                replace=i;
                Sleep(1000);
                system("cls");
                return menu3();
                }
        }
     }
         printf( "账号或密码错误！");
         Sleep(1000);
        system("cls");
         return 1;//返回
                                                                                }
                                        else if(-1==rg)
                                        {
                                            return -1;//报错
                                        }
                                        else
    {
        Sleep(1000);
        system("cls");
         return 1;
    }
}

void menu2()//注册
{
    printf("1.学生\n");
    printf("2.教师\n");
    printf("3.返回\n");
}

int content_stu()
{
    int rg;
    printf("请输入您的姓名：\n");
    getchar();
    gets(s[n1].name);
    printf("请输入您的学号：\n");
    gets(s[n1].id_1);
    printf("请输入您的密码：\n");
    gets(s[n1].password_1);
    n1++;//注册信息完成后就已经添加一名用户
    number_w();
    rg=w_situation();
    return rg;
}

int content_teacher()
{
    int rg;
    printf("请输入您的教工号：\n");
    getchar();
    gets(p[n2].id_2);
    printf("请输入您的密码：\n");
    gets(p[n2].password_2);
    n2++;
    number_w();
    rg=w_situation();                                                        // printf("%s",&p[n2].password_2); 测试的代码
    return rg;
}

//将注册信息保存到文件中
int w_situation()
{
    int i;
    FILE * fp=fopen("register_f.txt","w");
    FILE * sp=fopen("register_s.txt","w");
    if(fp==NULL&&sp==NULL)
    {
        return -1;
    }
    for(i=0;i<n1;i++)
    {
        fprintf(sp,"%-15s%-15s%-15s\n",s[i].name,s[i].id_1,s[i].password_1);//学生信息
    }
    for(i=0;i<n2;i++)
    {
        fprintf(fp,"%-15s%-15s\n",p[i].id_2,p[i].password_2);//教师信息
    }
    fclose(fp);
    fclose(sp);
    return 0;
}

//获取信息
int r_situation()
{
    int i,n=0;
    FILE * fp=fopen("register_f.txt","r");
    FILE * sp=fopen("register_s.txt","r");
    if(fp==NULL)
    {
        return -1;
    }

     for(i=0;i<n1;i++)
    {
        fscanf(sp,"%s%s%s",s[i].name,s[i].id_1,s[i].password_1);

    }

    for(i=0;i<n2;i++)
    {
        fscanf(fp,"%s%s",p[i].id_2,p[i].password_2);

    }
    fclose(fp);
    fclose(sp);
    return 0;
}

//学生系统方面的功能表
int menu3()
{
    int i,input=0;
    that:
    printf("1.请假申请\n");
    printf("2.申请状态\n");
    printf("3.退出\n");
    printf("4.返回\n");
    printf("请选择：");
    scanf("%d",&input);
    switch(input)
    {
    case 1:
        system("cls");//申请表填写
        if(write()<0)
            {
                printf("填写失败，请联系管理员。");
                Sleep(1000);
            }
        goto that;
    case 2:
        system("cls");
        if(r_le()<0)
            {
                    printf(" 未找到，是否有填写申请表?");
                    Sleep(1000);
                    system("cls");
                    goto that;
            }
        else
        {
             for(i=0;i<n3;i++)
             {
                 if(0==strcmp(le[i].name,s[replace].name))
                   {
                        printf("%-15s%-15s%-15s%-15s\n","name","time","cause","status");
                        printf("%-15s%-15s%-15s%-15s\n",le[i].name,le[i].time,le[i].cause,"申请中");
                        printf("按任意键返回");
                        getch();
                        system("cls");
                        goto that;
                   }
                 //否则继续循环直到退出
             }
             printf(" 未找到，是否有填写申请表?");
             Sleep(1000);
             system("cls");
             goto that;
        }
    case 3:
        return 0;
    case 4:
        return 1;
    default:
        goto that;
    }
}
int write()//申请表填写
{
    int rg;
    printf("请输入您的姓名：\n");
    getchar();
    gets(le[n3].name);
    printf("请输入申请日期：\n");
    gets(le[n3].time);
    printf("请输入申请原因：\n");
    gets(le[n3].cause);
    n3++;         //假条数
    number_w();
    rg=w_le();
    system("cls");
    return rg;
}

int w_le()//请假信息输入文件
{
    int i;
    FILE * fp=fopen("le.txt","w");
    if(fp==NULL)
    {
        return -1;
    }
    for(i=0;i<n3;i++)
    {
        fprintf(fp,"%-15s%-15s%-15s%-15s\n",le[i].name,le[i].time,le[i].cause,le[i].status);
    }
    fclose(fp);
    return 0;
}

//教师系统方面的功能表
int menu4()
{
    int input=0;
    the:
    printf("1.学生请假条信息:\n");
    printf("2.批阅请假条:\n");
    printf("3.退出\n");
    printf("4.返回\n");
    printf("请选择：");
    scanf("%d",&input);
    switch(input)
    {
        case 1:
            system("cls");
            loup();
            goto the;
        case 2:
            system("cls");
            change();
            goto the;
        case 3:
            return 0;
        case 4:
            return 1;
        default:
            system("cls");
            goto the;
    }
}

void loup()
{
    int i;
    printf("学生请假条信息:\n");
    printf("%-15s%-15s%-15s%-15s%-15s\n","number","name","time","cause","status");
    for(i=0;i<n3;i++)
    {
        if(le[i].status!=0)
            printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,le[i].status);
        else
            printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,"申请中");
    }
    printf("按任意键返回");
    getch();
    system("cls");
}

void change()
{
    char xh[100]="sd";
    int i;
    printf("输入要批阅的学生姓名：");
    scanf("%s",xh);
    for(i=0;i<n3;i++)
    {
        if(0==strcmp(xh,le[i].name))
        {
            printf("%-15s%-15s%-15s%-15s%-15s\n\n","number","name","time","cause","status");
            if(le[i].status!=0)
                printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,le[i].status);
            else
                printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,"申请中");
            printf("您是否批准/拒绝？(请输入)\n");
            scanf("%s",le[i].status);
            r_le();
            goto this;
        }
    }
            printf("找不到该同学！");
            this:
    printf("按任意键返回");
    getch();
    system("cls");
}

int r_le()
{
    int n,i;
    FILE * fp=fopen("le.txt","r");
    if(fp==NULL)
    {
        return -1;
    }
    for(i=0;i<n3;i++)
    {
        fscanf(fp,"%s%s%s%s",le[i].name,le[i].time,le[i].cause,le[i].status);
    }
    fclose(fp);
    return 0;
}

//void lookstatus()
//{
//    int i;
//    char status[100][100];
//    for(i=0;i<n3;n3++)
//    {
//
//    }
//}

int main()
{//需要初始化去使用的函数
    number_r();
    r_situation();
    r_le();
    //菜单栏
    int i=10,j,input=0;
    again:
    menu1();
    printf("请选择：");
    scanf("%d",&input);
    switch(input)//选择功能
    {
           case 1:
               system("cls");
               //登录
               j=content1();
               if(j>0)
               {
                   system("cls");
                   goto again;
               }
               else if(j<0)
               {
                    printf("没有您的注册信息！");
                    Sleep(1000);
                    system("cls");
                    goto again;
               }
               else
               break;
           case 2://注册
               system("cls");
               zhuce:
               menu2();
                   printf("请选择：");
                   scanf("%d",&input);
                   switch(input)//学生注册界面
                   {
                       case 1:
                         if(content_stu()<0)
                         {
                             printf("注册失败，请联系管理员。");
                             Sleep(1000);
                             n1--;
                         }
                         else
                            {printf("注册成功！");
                            Sleep(1000);
                            system("cls");
                            goto again;}
                       case 2://老师注册
                         if(content_teacher()<0)
                         {
                             printf("注册失败，请联系管理员。");
                             Sleep(1000);
                             n2--;
                         }
                         else
                            {Sleep(1000);
                            printf("注册成功！");
                            system("cls");
                            goto again;}
                       case 3:
                          system("cls");
                          goto again;
                      default:
                         printf("错误！请再次选择\n");
                         Sleep(1000);
                         system("cls");
                         goto zhuce;
                    }
                break;
           case 3:
               break;
           default:
               printf("错误！请再次选择\n");
               Sleep(1000);
               system("cls");
               goto again;
     }
     Sleep(1000);
     system("cls");
     //最后再保存
     w_situation();
     w_le();
     return 0;
}
