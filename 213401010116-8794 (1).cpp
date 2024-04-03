#include <malloc.h>
#include <stdlib.h>

#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include<fstream>
using namespace std;
typedef struct student
{
    int   num;        //考号
    char  sex[20];    //性别 
    char  name[20];   //姓名
    int   age;        //年龄
    char  address[20];//籍贯
    int   type;       //考试类别
}ElemType;

typedef struct LNode  //定义单链表节点类型
{
    ElemType data;   //存放元素值
    struct LNode* next;  //指向后继节点
} LinkList;

/*void InitList(LinkList*& L); //初始化线性表
void DestroyList(LinkList*& L); //销毁线性表 释放空间
void CreateListR(LinkList*& L);   // 采用尾插法创建链表  输入信息
void DispList(LinkList* L);  //输出信息
void LocateElem(LinkList* L);//查找信息
int ListDelete(LinkList*& L); //删除信息
int Ccreate(LinkList*& L);//修改信息
void sort(LinkList*& L);    //排序信息
void sumList(LinkList*& L);    //统计信息
void InsertList(LinkList* L);   //插入信息
void Display(LinkList* L);//输出信息
void import(LinkList*& L);//读文件
void save(LinkList*& L);//存文件
void DispListKH(LinkList* L);//输出信息
void ListInsert(LinkList*& L, LinkList* p);//插入新的节点

*/
//功能描述：初始化线性表，建立一个空的单链表，创建一个头结点
void InitList(LinkList*& L)
{
    L = (LinkList*)malloc(sizeof(LinkList)); //向系统请求分配内存空间来装LinkList这种类型的指针数据的内存大小
    L->next = NULL;  //创建头结点，其next域置为NULL
}

void DestroyList(LinkList*& L) //释放单链表L占用的内存空间，即逐一释放全部节点的空间  //释放空间
{
    LinkList* p = L, * q = p->next;
    while (q != NULL)
    {
        free(p);  //释放内存,p指向的地址不变
        p = q;
        q = p->next;
    }
    free(p);
    printf("此报名系统的考生信息已经全部清除！\n\n\n");

}

void CreateListR(LinkList*& L)   // 采用尾插法创建链表   //输入信息

{
    int n;     //该链表的总人数
    printf("请输入参加考试的考生的总人数：\n");
    scanf("%d", &n);
    LinkList* s, * r;
    int i;    //定义LinkList *s作为插入的新结点    定义LinkList *r始终指向尾结点
    L = (LinkList*)malloc(sizeof(LinkList));
    r = L;
    printf("输入考号  姓名  性别  籍贯  年龄  考试类别\n");
    printf("考试的类别:1.四级 2.六级 3.高数 4.大物 5.电路 \n");
    for (i = 0; i < n; i++)//使用for循环将新结点逐次插入链表之后（条件是int i<n）
    {
        s = (LinkList*)malloc(sizeof(LinkList));
        scanf("%d %s %s %s %d %d", &s->data.num, &s->data.name, &s->data.sex, &s->data.address, &s->data.age, &s->data.type);
        r->next = s;
        r = s;
    }
    r->next = NULL;            //将尾结点指向null

}

void DispList(LinkList* L)  //输出信息
{
    LinkList* p = L->next;   //定义LinkList *p 指向第一个元素结点
    if (p == NULL)
        printf("该考试报名系统信息为空，请添加！\n");
    while (p != NULL) //用while循环逐次输出链表元素（条件是p!=null）
    {
        printf("考号 姓名  性别  籍贯  年龄  考试类别\n");
        printf(" %d   %s    %s    %s   %d     %d\n", p->data.num, p->data.name, p->data.sex, p->data.address, p->data.age, p->data.type);
        p = p->next;
    }
    printf("  \n");

}

void LocateElem(LinkList* L)   //查找信息
{
    ElemType e;
    int n;
    int count = 0;
    int i;
    printf("请选择1.按考生号进行查询2.按姓名进行查询 \n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    {
        printf("请输入要查找的考生的考号：\n");
        scanf("%d", &e.num);
        LinkList* p = L->next;         // 定义LinkList *p指向第一个元素结点
        while (p != NULL && p->data.num != e.num)//用while循环查找要查找的结点
        {
            p = p->next;
        }
        if (p == NULL)
        {
            printf("您要查找的考生不存在，请重新输入！\n");

        }
        else
        {
            printf("考号:");
            printf("%d\n", p->data.num);
            printf("姓名:");
            printf("%s\n", p->data.name);
            printf("性别:");
            printf("%s\n", p->data.sex);
            printf("学院:");
            printf("%s\n", p->data.address);
            printf("年龄:");
            printf("%d\n", p->data.age);
            printf("考试类别:");
            printf("%d\n", p->data.type);
        }
        break;
    }
    case 2:
    {
        printf("请输入要查找的考生的姓名：\n");
        scanf("%s", &e.name);
        LinkList* p = L->next;         // 定义LinkList *p指向第一个元素结点
        if (p == NULL)
        {
            printf("您查找的该姓名的考生不存在！\n");
        }
        do
        {
            if (strcmp(e.name, p->data.name) == 0)
            {
                printf("考号:");
                printf("%d\n", p->data.num);
                printf("姓名:");
                printf("%s\n", p->data.name);
                printf("性别:");
                printf("%s\n", p->data.sex);
                printf("籍贯:");
                printf("%s\n", p->data.address);
                printf("年龄:");
                printf("%d\n", p->data.age);
                printf("考试类别:");
                printf("%d\n", p->data.type);
            }
            p = p->next;
        } while (p != NULL);
        break;
    }
    }
}

int ListDelete(LinkList*& L)    //删除信息
{
    ElemType e;
    printf("请输入要删除考生的考号：");
    scanf("%d", &e.num);
    LinkList* p = L, * q;        //定义LinkList *p  指向头结点        定义LinkList *q 作为存储删除结点的变量
    q = p->next;
    while (e.num != q->data.num && q->next != NULL)    //用while循环查找该结点，并且用free(q)清空该结点
    {
        q = q->next;
        p = p->next;
    }
    if (e.num != q->data.num)
    {
        printf("抱歉，没有找到该考号！\n");
        return 0;
    }
    else
    {
        q = p->next;
        if (q == NULL)
            return 0;
        p->next = q->next;
        free(q);
        printf("输出删除以后的全部信息：\n\n");
        DispList(L);
        return 1;
    }
}

int create(LinkList*& L)      //修改信息
{
    ElemType e;
    printf("请输入要修改的考生的考号：\n");
    scanf("%d", &e.num);
    LinkList* p = L->next;         //定义LinkList *p指向第一个元素
    while (e.num != p->data.num && p->next != NULL)     //用while循环查找该结点
    {
        p = p->next;
    }


    if (p->data.num == e.num)
    {
        printf("允许修改！\n");
        printf("请输入:姓名  性别  籍贯  年龄  考试类别\n");
        scanf("%s %s %s %d %d", &p->data.name, &p->data.sex, &p->data.address, &p->data.age, &p->data.type);
        printf("输出修改以后的全部信息：\n\n");
        DispList(L);
        return 0;

    }
    printf("没有此考号，不能修改，重新执行修改信息！\n");
    return 0;
}

void sort(LinkList*& L)    //排序信息
{
    for (LinkList* first = L->next; first != NULL; first = first->next)//定义指针first指向未排序的第一个节点
    {
        for (LinkList* second = L->next; second != NULL; second = second->next)//定义指针second也指向未排序的第一个节点
        {
            if (second->next != NULL)//当second->next不为空时继续执行
            {
                if (second->data.num > second->next->data.num)//将小的节点往前移
                {
                    struct student temp;
                    temp = second->data;
                    second->data = second->next->data;
                    second->next->data = temp;
                }
            }
        }
    }
    DispList(L);//输出排序后的链表
}

void sumList(LinkList*& L)    //统计信息,统计各个类别考试的人数
{
    LinkList* p = L;            //定义LinkList *p指向头结点        
    int n = 0, m = 0, h = 0, i = 0, j = 0, k = 0; //定义多个变量统计报考各科的人数
    while (p->next != NULL)             //用while循环和if语句统计人数
    {
        n++;

        if (p->next->data.type == 1)
            m++;
        if (p->next->data.type == 2)
            i++;
        if (p->next->data.type == 3)
            h++;
        if (p->next->data.type == 4)
            j++;
        if (p->next->data.type == 5)
            k++;

        p = p->next;
    }
    printf("报名考试的总人数为: ");
    printf("%d\n", n);
    printf("报考英语四级的人数为：");
    printf("%d\n", m);
    printf("报考英语六级的人数为：");
    printf("%d\n", i);
    printf("报考高数的人数为：");
    printf("%d\n", h);
    printf("报考大物的人数为：");
    printf("%d\n", j);
    printf("报考电路的人数为：");
    printf("%d\n", k);
}

/*保存考生信息到score.txt文件中*/
void save(LinkList*& L)//保存学生信息到文件
{
    FILE* fp;
    //WORK*p;
    //p = worker;
    LinkList* p = L->next;

    if ((fp = fopen("C://Users//hp//Desktop//score.txt", "w")) == NULL)// 以可写的方式打开当前目录下的.txt
    {
        printf("Can not open the file,press any key exit!");
        exit(0);
    }
    while (p)
    {
        //printf("*******\n");
        //display(p);
        fprintf(fp, "%d %s %s %s %d %d \n", p->data.num, &p->data.name, &p->data.sex, &p->data.address, p->data.age, p->data.type);
        p = p->next;
    }
    fclose(fp);
    printf("您已经将考生信息成功保存到了 score.txt文件中！\n ");
}

void ListInsert(LinkList*& L, LinkList* p)//插入新的节点
{
    LinkList* q = NULL;
    q = L;
    if (q->next == NULL)
    {
        q->next = p;
        p->next = NULL;
    }
    else
    {
        p->next = q->next;
        q->next = p;
    }
}

/*功能描述：增加新考生的信息*/
void InsertList(LinkList* L)   //插入信息函数
{
    ElemType e;
    printf("请输入考生的信息：\n");
    printf("考生号：");
    scanf("%d", &e.num);
    LinkList* q = L->next;
    while (q != NULL)
    {
        if (q->data.num == e.num)
        {
            printf("该考生已存在请重新输入！\n");
            break;
        }
        q = q->next;
    }
    if (q == NULL)
    {
        LinkList* p;
        InitList(p);

        p->data.num = e.num;//把后者的内容拷贝到前者中

        printf("姓名：");
        scanf("%s", &e.name);
        strcpy(p->data.name, e.name);//把后者的内容拷贝到前者中

        printf("性别：（w为男 m为女）");
        scanf(" %s", &e.sex);
        strcpy(p->data.sex, e.sex);

        printf("年龄：");
        scanf("%d", &e.age);
        p->data.age = e.age;

        printf("籍贯：");
        scanf("%s", &e.address);
        strcpy(p->data.address, e.address);

        printf("类型：");
        scanf("%d", &e.type);
        p->data.type = e.type;

        ListInsert(L, p);
        printf("添加考生信息成功，添加完的考生信息为：\n");
        DispList(L);
    }
}
//功能描述：功能界面

void display()
{
    printf("**********欢迎来到考试报名系统**********\n");
    printf("             1.输入考生的信息\n");
    printf("             2.输出考生的信息                  \n");
    printf("             3.查找考生的信息                  \n");
    printf("             4.删除考生的信息                  \n");
    printf("             5.修改考生的信息                  \n");
    printf("             6.考生的信息按照学号进行排序                  \n");
    printf("             7.统计考生报名信息                  \n");
    printf("             8.插入考生报名信息                 \n");
    printf("             9.清除所有考生的报名信息                  \n");
    printf("             10.保存考生信息到文件中      \n");
    printf("             0.退出考试报名系统              \n");
    printf("-----------------------------------------------------------\n");
    system("color 70");
}

void Display(LinkList* L)//输入0—10的数字选择功能
{
    while (1)
    {
        display();
        int a;//定义变量a作为选择变量
        printf("请输入要操作的项目的编号:\n");
        scanf("%d", &a);
        switch (a)       //用switch语句，编写选择项目
        {
        case 1:
        {
            CreateListR(L);
            break;
        }
        case 2:
        {
            DispList(L);
            break;
        }
        case 3:
        {
            LocateElem(L);
            break;
        }
        case 4:
        {
            ListDelete(L);
            break;
        }
        case 5:
        {
            create(L);
            break;
        }
        case 6:
        {
            sort(L);
            break;
        }
        case 7:
        {
            sumList(L);
            break;
        }
        case 8:
        {
            InsertList(L);
            break; }
        case 9:
        {
            DestroyList(L);
            break;
        }
        case 10:
        {
            save(L);
            break;
        }
        case 0:
        {
            printf("您已经成功退出考试报名系统。\n");
            exit(0);
        }
        }
    }
}

int main()
{
    LinkList* L;  //定义LinkList *L
    InitList(L); //调用初始化线性表函数
    Display(L); //调用显示菜单函数
    return 0;
}

