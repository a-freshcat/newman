#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>
#include <conio.h>

//������ٹ���ϵͳ
int n1=0,n2=0,n3=0;
int replace=0;
void number_w()//�ö�����ļ����洢�û���
{
    FILE * fp=fopen("number.txt","w");
    //ѧ��,��ʦ����ٱ�����
    fprintf(fp,"%10d%10d%10d",n1,n2,n3);
    fclose(fp);
}
void number_r()
{
    FILE * fp=fopen("number.txt","r");
    //ѧ��,��ʦ����ٱ�����
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
    printf("#######�˺ŵ�¼ע�����######\n");
    printf("1.��¼\n");
    printf("2.ע��\n");
    printf("3.�˳�\n");
}

int content1()                                    //��¼
{
    int i,rg;
    //��ȡע�����Ϣ
    rg=r_situation();
                                if(0==rg)
                                                                            {
    char id_s[100],ps[100];
    printf("ѧ��/�̹��ţ�\n");
    getchar();
    gets(id_s);
    printf("���룺\n");
    gets(ps);
    for(i=0;i<n2;i++)
    {
        if(0==strcmp(p[i].id_2,id_s))
        {
            if(0==strcmp(p[i].password_2,ps))
            {
                printf("��ʦ����,��ӭ��¼��");
                Sleep(1000);
                system("cls");
                return menu4();
            }             //����0���˳�
        }
    }
    for(i=0;i<n1;i++)
    {
         if(0==strcmp(s[i].id_1,id_s))
        {
              if(0==strcmp(s[i].password_1,ps))
                {printf("ѧ������,��ӭ��¼��");
                replace=i;
                Sleep(1000);
                system("cls");
                return menu3();
                }
        }
     }
         printf( "�˺Ż��������");
         Sleep(1000);
        system("cls");
         return 1;//����
                                                                                }
                                        else if(-1==rg)
                                        {
                                            return -1;//����
                                        }
                                        else
    {
        Sleep(1000);
        system("cls");
         return 1;
    }
}

void menu2()//ע��
{
    printf("1.ѧ��\n");
    printf("2.��ʦ\n");
    printf("3.����\n");
}

int content_stu()
{
    int rg;
    printf("����������������\n");
    getchar();
    gets(s[n1].name);
    printf("����������ѧ�ţ�\n");
    gets(s[n1].id_1);
    printf("�������������룺\n");
    gets(s[n1].password_1);
    n1++;//ע����Ϣ��ɺ���Ѿ����һ���û�
    number_w();
    rg=w_situation();
    return rg;
}

int content_teacher()
{
    int rg;
    printf("���������Ľ̹��ţ�\n");
    getchar();
    gets(p[n2].id_2);
    printf("�������������룺\n");
    gets(p[n2].password_2);
    n2++;
    number_w();
    rg=w_situation();                                                        // printf("%s",&p[n2].password_2); ���ԵĴ���
    return rg;
}

//��ע����Ϣ���浽�ļ���
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
        fprintf(sp,"%-15s%-15s%-15s\n",s[i].name,s[i].id_1,s[i].password_1);//ѧ����Ϣ
    }
    for(i=0;i<n2;i++)
    {
        fprintf(fp,"%-15s%-15s\n",p[i].id_2,p[i].password_2);//��ʦ��Ϣ
    }
    fclose(fp);
    fclose(sp);
    return 0;
}

//��ȡ��Ϣ
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

//ѧ��ϵͳ����Ĺ��ܱ�
int menu3()
{
    int i,input=0;
    that:
    printf("1.�������\n");
    printf("2.����״̬\n");
    printf("3.�˳�\n");
    printf("4.����\n");
    printf("��ѡ��");
    scanf("%d",&input);
    switch(input)
    {
    case 1:
        system("cls");//�������д
        if(write()<0)
            {
                printf("��дʧ�ܣ�����ϵ����Ա��");
                Sleep(1000);
            }
        goto that;
    case 2:
        system("cls");
        if(r_le()<0)
            {
                    printf(" δ�ҵ����Ƿ�����д�����?");
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
                        printf("%-15s%-15s%-15s%-15s\n",le[i].name,le[i].time,le[i].cause,"������");
                        printf("�����������");
                        getch();
                        system("cls");
                        goto that;
                   }
                 //�������ѭ��ֱ���˳�
             }
             printf(" δ�ҵ����Ƿ�����д�����?");
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
int write()//�������д
{
    int rg;
    printf("����������������\n");
    getchar();
    gets(le[n3].name);
    printf("�������������ڣ�\n");
    gets(le[n3].time);
    printf("����������ԭ��\n");
    gets(le[n3].cause);
    n3++;         //������
    number_w();
    rg=w_le();
    system("cls");
    return rg;
}

int w_le()//�����Ϣ�����ļ�
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

//��ʦϵͳ����Ĺ��ܱ�
int menu4()
{
    int input=0;
    the:
    printf("1.ѧ���������Ϣ:\n");
    printf("2.���������:\n");
    printf("3.�˳�\n");
    printf("4.����\n");
    printf("��ѡ��");
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
    printf("ѧ���������Ϣ:\n");
    printf("%-15s%-15s%-15s%-15s%-15s\n","number","name","time","cause","status");
    for(i=0;i<n3;i++)
    {
        if(le[i].status!=0)
            printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,le[i].status);
        else
            printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,"������");
    }
    printf("�����������");
    getch();
    system("cls");
}

void change()
{
    char xh[100]="sd";
    int i;
    printf("����Ҫ���ĵ�ѧ��������");
    scanf("%s",xh);
    for(i=0;i<n3;i++)
    {
        if(0==strcmp(xh,le[i].name))
        {
            printf("%-15s%-15s%-15s%-15s%-15s\n\n","number","name","time","cause","status");
            if(le[i].status!=0)
                printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,le[i].status);
            else
                printf("%-15d%-15s%-15s%-15s%-15s\n",i+1,le[i].name,le[i].time,le[i].cause,"������");
            printf("���Ƿ���׼/�ܾ���(������)\n");
            scanf("%s",le[i].status);
            r_le();
            goto this;
        }
    }
            printf("�Ҳ�����ͬѧ��");
            this:
    printf("�����������");
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
{//��Ҫ��ʼ��ȥʹ�õĺ���
    number_r();
    r_situation();
    r_le();
    //�˵���
    int i=10,j,input=0;
    again:
    menu1();
    printf("��ѡ��");
    scanf("%d",&input);
    switch(input)//ѡ����
    {
           case 1:
               system("cls");
               //��¼
               j=content1();
               if(j>0)
               {
                   system("cls");
                   goto again;
               }
               else if(j<0)
               {
                    printf("û������ע����Ϣ��");
                    Sleep(1000);
                    system("cls");
                    goto again;
               }
               else
               break;
           case 2://ע��
               system("cls");
               zhuce:
               menu2();
                   printf("��ѡ��");
                   scanf("%d",&input);
                   switch(input)//ѧ��ע�����
                   {
                       case 1:
                         if(content_stu()<0)
                         {
                             printf("ע��ʧ�ܣ�����ϵ����Ա��");
                             Sleep(1000);
                             n1--;
                         }
                         else
                            {printf("ע��ɹ���");
                            Sleep(1000);
                            system("cls");
                            goto again;}
                       case 2://��ʦע��
                         if(content_teacher()<0)
                         {
                             printf("ע��ʧ�ܣ�����ϵ����Ա��");
                             Sleep(1000);
                             n2--;
                         }
                         else
                            {Sleep(1000);
                            printf("ע��ɹ���");
                            system("cls");
                            goto again;}
                       case 3:
                          system("cls");
                          goto again;
                      default:
                         printf("�������ٴ�ѡ��\n");
                         Sleep(1000);
                         system("cls");
                         goto zhuce;
                    }
                break;
           case 3:
               break;
           default:
               printf("�������ٴ�ѡ��\n");
               Sleep(1000);
               system("cls");
               goto again;
     }
     Sleep(1000);
     system("cls");
     //����ٱ���
     w_situation();
     w_le();
     return 0;
}
