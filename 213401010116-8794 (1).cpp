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
    int   num;        //����
    char  sex[20];    //�Ա� 
    char  name[20];   //����
    int   age;        //����
    char  address[20];//����
    int   type;       //�������
}ElemType;

typedef struct LNode  //���嵥����ڵ�����
{
    ElemType data;   //���Ԫ��ֵ
    struct LNode* next;  //ָ���̽ڵ�
} LinkList;

/*void InitList(LinkList*& L); //��ʼ�����Ա�
void DestroyList(LinkList*& L); //�������Ա� �ͷſռ�
void CreateListR(LinkList*& L);   // ����β�巨��������  ������Ϣ
void DispList(LinkList* L);  //�����Ϣ
void LocateElem(LinkList* L);//������Ϣ
int ListDelete(LinkList*& L); //ɾ����Ϣ
int Ccreate(LinkList*& L);//�޸���Ϣ
void sort(LinkList*& L);    //������Ϣ
void sumList(LinkList*& L);    //ͳ����Ϣ
void InsertList(LinkList* L);   //������Ϣ
void Display(LinkList* L);//�����Ϣ
void import(LinkList*& L);//���ļ�
void save(LinkList*& L);//���ļ�
void DispListKH(LinkList* L);//�����Ϣ
void ListInsert(LinkList*& L, LinkList* p);//�����µĽڵ�

*/
//������������ʼ�����Ա�����һ���յĵ���������һ��ͷ���
void InitList(LinkList*& L)
{
    L = (LinkList*)malloc(sizeof(LinkList)); //��ϵͳ��������ڴ�ռ���װLinkList�������͵�ָ�����ݵ��ڴ��С
    L->next = NULL;  //����ͷ��㣬��next����ΪNULL
}

void DestroyList(LinkList*& L) //�ͷŵ�����Lռ�õ��ڴ�ռ䣬����һ�ͷ�ȫ���ڵ�Ŀռ�  //�ͷſռ�
{
    LinkList* p = L, * q = p->next;
    while (q != NULL)
    {
        free(p);  //�ͷ��ڴ�,pָ��ĵ�ַ����
        p = q;
        q = p->next;
    }
    free(p);
    printf("�˱���ϵͳ�Ŀ�����Ϣ�Ѿ�ȫ�������\n\n\n");

}

void CreateListR(LinkList*& L)   // ����β�巨��������   //������Ϣ

{
    int n;     //�������������
    printf("������μӿ��ԵĿ�������������\n");
    scanf("%d", &n);
    LinkList* s, * r;
    int i;    //����LinkList *s��Ϊ������½��    ����LinkList *rʼ��ָ��β���
    L = (LinkList*)malloc(sizeof(LinkList));
    r = L;
    printf("���뿼��  ����  �Ա�  ����  ����  �������\n");
    printf("���Ե����:1.�ļ� 2.���� 3.���� 4.���� 5.��· \n");
    for (i = 0; i < n; i++)//ʹ��forѭ�����½����β�������֮��������int i<n��
    {
        s = (LinkList*)malloc(sizeof(LinkList));
        scanf("%d %s %s %s %d %d", &s->data.num, &s->data.name, &s->data.sex, &s->data.address, &s->data.age, &s->data.type);
        r->next = s;
        r = s;
    }
    r->next = NULL;            //��β���ָ��null

}

void DispList(LinkList* L)  //�����Ϣ
{
    LinkList* p = L->next;   //����LinkList *p ָ���һ��Ԫ�ؽ��
    if (p == NULL)
        printf("�ÿ��Ա���ϵͳ��ϢΪ�գ�����ӣ�\n");
    while (p != NULL) //��whileѭ������������Ԫ�أ�������p!=null��
    {
        printf("���� ����  �Ա�  ����  ����  �������\n");
        printf(" %d   %s    %s    %s   %d     %d\n", p->data.num, p->data.name, p->data.sex, p->data.address, p->data.age, p->data.type);
        p = p->next;
    }
    printf("  \n");

}

void LocateElem(LinkList* L)   //������Ϣ
{
    ElemType e;
    int n;
    int count = 0;
    int i;
    printf("��ѡ��1.�������Ž��в�ѯ2.���������в�ѯ \n");
    scanf("%d", &n);
    switch (n)
    {
    case 1:
    {
        printf("������Ҫ���ҵĿ����Ŀ��ţ�\n");
        scanf("%d", &e.num);
        LinkList* p = L->next;         // ����LinkList *pָ���һ��Ԫ�ؽ��
        while (p != NULL && p->data.num != e.num)//��whileѭ������Ҫ���ҵĽ��
        {
            p = p->next;
        }
        if (p == NULL)
        {
            printf("��Ҫ���ҵĿ��������ڣ����������룡\n");

        }
        else
        {
            printf("����:");
            printf("%d\n", p->data.num);
            printf("����:");
            printf("%s\n", p->data.name);
            printf("�Ա�:");
            printf("%s\n", p->data.sex);
            printf("ѧԺ:");
            printf("%s\n", p->data.address);
            printf("����:");
            printf("%d\n", p->data.age);
            printf("�������:");
            printf("%d\n", p->data.type);
        }
        break;
    }
    case 2:
    {
        printf("������Ҫ���ҵĿ�����������\n");
        scanf("%s", &e.name);
        LinkList* p = L->next;         // ����LinkList *pָ���һ��Ԫ�ؽ��
        if (p == NULL)
        {
            printf("�����ҵĸ������Ŀ��������ڣ�\n");
        }
        do
        {
            if (strcmp(e.name, p->data.name) == 0)
            {
                printf("����:");
                printf("%d\n", p->data.num);
                printf("����:");
                printf("%s\n", p->data.name);
                printf("�Ա�:");
                printf("%s\n", p->data.sex);
                printf("����:");
                printf("%s\n", p->data.address);
                printf("����:");
                printf("%d\n", p->data.age);
                printf("�������:");
                printf("%d\n", p->data.type);
            }
            p = p->next;
        } while (p != NULL);
        break;
    }
    }
}

int ListDelete(LinkList*& L)    //ɾ����Ϣ
{
    ElemType e;
    printf("������Ҫɾ�������Ŀ��ţ�");
    scanf("%d", &e.num);
    LinkList* p = L, * q;        //����LinkList *p  ָ��ͷ���        ����LinkList *q ��Ϊ�洢ɾ�����ı���
    q = p->next;
    while (e.num != q->data.num && q->next != NULL)    //��whileѭ�����Ҹý�㣬������free(q)��ոý��
    {
        q = q->next;
        p = p->next;
    }
    if (e.num != q->data.num)
    {
        printf("��Ǹ��û���ҵ��ÿ��ţ�\n");
        return 0;
    }
    else
    {
        q = p->next;
        if (q == NULL)
            return 0;
        p->next = q->next;
        free(q);
        printf("���ɾ���Ժ��ȫ����Ϣ��\n\n");
        DispList(L);
        return 1;
    }
}

int create(LinkList*& L)      //�޸���Ϣ
{
    ElemType e;
    printf("������Ҫ�޸ĵĿ����Ŀ��ţ�\n");
    scanf("%d", &e.num);
    LinkList* p = L->next;         //����LinkList *pָ���һ��Ԫ��
    while (e.num != p->data.num && p->next != NULL)     //��whileѭ�����Ҹý��
    {
        p = p->next;
    }


    if (p->data.num == e.num)
    {
        printf("�����޸ģ�\n");
        printf("������:����  �Ա�  ����  ����  �������\n");
        scanf("%s %s %s %d %d", &p->data.name, &p->data.sex, &p->data.address, &p->data.age, &p->data.type);
        printf("����޸��Ժ��ȫ����Ϣ��\n\n");
        DispList(L);
        return 0;

    }
    printf("û�д˿��ţ������޸ģ�����ִ���޸���Ϣ��\n");
    return 0;
}

void sort(LinkList*& L)    //������Ϣ
{
    for (LinkList* first = L->next; first != NULL; first = first->next)//����ָ��firstָ��δ����ĵ�һ���ڵ�
    {
        for (LinkList* second = L->next; second != NULL; second = second->next)//����ָ��secondҲָ��δ����ĵ�һ���ڵ�
        {
            if (second->next != NULL)//��second->next��Ϊ��ʱ����ִ��
            {
                if (second->data.num > second->next->data.num)//��С�Ľڵ���ǰ��
                {
                    struct student temp;
                    temp = second->data;
                    second->data = second->next->data;
                    second->next->data = temp;
                }
            }
        }
    }
    DispList(L);//�������������
}

void sumList(LinkList*& L)    //ͳ����Ϣ,ͳ�Ƹ�������Ե�����
{
    LinkList* p = L;            //����LinkList *pָ��ͷ���        
    int n = 0, m = 0, h = 0, i = 0, j = 0, k = 0; //����������ͳ�Ʊ������Ƶ�����
    while (p->next != NULL)             //��whileѭ����if���ͳ������
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
    printf("�������Ե�������Ϊ: ");
    printf("%d\n", n);
    printf("����Ӣ���ļ�������Ϊ��");
    printf("%d\n", m);
    printf("����Ӣ������������Ϊ��");
    printf("%d\n", i);
    printf("��������������Ϊ��");
    printf("%d\n", h);
    printf("�������������Ϊ��");
    printf("%d\n", j);
    printf("������·������Ϊ��");
    printf("%d\n", k);
}

/*���濼����Ϣ��score.txt�ļ���*/
void save(LinkList*& L)//����ѧ����Ϣ���ļ�
{
    FILE* fp;
    //WORK*p;
    //p = worker;
    LinkList* p = L->next;

    if ((fp = fopen("C://Users//hp//Desktop//score.txt", "w")) == NULL)// �Կ�д�ķ�ʽ�򿪵�ǰĿ¼�µ�.txt
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
    printf("���Ѿ���������Ϣ�ɹ����浽�� score.txt�ļ��У�\n ");
}

void ListInsert(LinkList*& L, LinkList* p)//�����µĽڵ�
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

/*���������������¿�������Ϣ*/
void InsertList(LinkList* L)   //������Ϣ����
{
    ElemType e;
    printf("�����뿼������Ϣ��\n");
    printf("�����ţ�");
    scanf("%d", &e.num);
    LinkList* q = L->next;
    while (q != NULL)
    {
        if (q->data.num == e.num)
        {
            printf("�ÿ����Ѵ������������룡\n");
            break;
        }
        q = q->next;
    }
    if (q == NULL)
    {
        LinkList* p;
        InitList(p);

        p->data.num = e.num;//�Ѻ��ߵ����ݿ�����ǰ����

        printf("������");
        scanf("%s", &e.name);
        strcpy(p->data.name, e.name);//�Ѻ��ߵ����ݿ�����ǰ����

        printf("�Ա𣺣�wΪ�� mΪŮ��");
        scanf(" %s", &e.sex);
        strcpy(p->data.sex, e.sex);

        printf("���䣺");
        scanf("%d", &e.age);
        p->data.age = e.age;

        printf("���᣺");
        scanf("%s", &e.address);
        strcpy(p->data.address, e.address);

        printf("���ͣ�");
        scanf("%d", &e.type);
        p->data.type = e.type;

        ListInsert(L, p);
        printf("��ӿ�����Ϣ�ɹ��������Ŀ�����ϢΪ��\n");
        DispList(L);
    }
}
//�������������ܽ���

void display()
{
    printf("**********��ӭ�������Ա���ϵͳ**********\n");
    printf("             1.���뿼������Ϣ\n");
    printf("             2.�����������Ϣ                  \n");
    printf("             3.���ҿ�������Ϣ                  \n");
    printf("             4.ɾ����������Ϣ                  \n");
    printf("             5.�޸Ŀ�������Ϣ                  \n");
    printf("             6.��������Ϣ����ѧ�Ž�������                  \n");
    printf("             7.ͳ�ƿ���������Ϣ                  \n");
    printf("             8.���뿼��������Ϣ                 \n");
    printf("             9.������п����ı�����Ϣ                  \n");
    printf("             10.���濼����Ϣ���ļ���      \n");
    printf("             0.�˳����Ա���ϵͳ              \n");
    printf("-----------------------------------------------------------\n");
    system("color 70");
}

void Display(LinkList* L)//����0��10������ѡ����
{
    while (1)
    {
        display();
        int a;//�������a��Ϊѡ�����
        printf("������Ҫ��������Ŀ�ı��:\n");
        scanf("%d", &a);
        switch (a)       //��switch��䣬��дѡ����Ŀ
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
            printf("���Ѿ��ɹ��˳����Ա���ϵͳ��\n");
            exit(0);
        }
        }
    }
}

int main()
{
    LinkList* L;  //����LinkList *L
    InitList(L); //���ó�ʼ�����Ա���
    Display(L); //������ʾ�˵�����
    return 0;
}

