#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//摘自https://blog.csdn.net/Qian_Qian_IT/article/details/108805630?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165881629116781790781530%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165881629116781790781530&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_click~default-3-108805630-null-null.142^v34^new_blog_pos_by_title,185^v2^control&utm_term=c%E8%AF%AD%E8%A8%80%E9%93%BE%E8%A1%A8&spm=1018.2226.3001.4187

//typedef:c语言允许为一个数据类型起一个新的别名，就像给人起“绰号”一样。
//参考：https://blog.csdn.net/weixin_45743799/article/details/104532763?ops_request_misc=%257B%2522request%255Fid%2522%253A%2522165881541816782390577334%2522%252C%2522scm%2522%253A%252220140713.130102334..%2522%257D&request_id=165881541816782390577334&biz_id=0&utm_medium=distribute.pc_search_result.none-task-blog-2~all~top_positive~default-1-104532763-null-null.142^v34^new_blog_pos_by_title,185^v2^control&utm_term=typedef&spm=1018.2226.3001.4187
//typedef oldName newName;
//typedef和#define区别：定义宏 比 封装起别名 具有可扩展性

//ElemType默认是int型

//C语言使用结构体来操作链表

//链表的特点：
  //a.n个节点离散分配
  //b.每一个节点之间通过指针相连
  //c.每一个节点有一个前驱节点和一个后继节点
  //d.首节点没有前驱节点，尾节点没有后驱节点


  //单链表的初始化以及增删改查操作，如下：

//封装数据类型int
typedef int ElemType;

//定义一个简单的结构体并封装
typedef struct Node{
    ElemType data;           //定义数据域
    struct Node *next;  //定义指针域 是一个结构体指针 指向下一个节点
}LinkList;//封装为LinkList

//函数声明(C语言格式要求)
int isEmpty(LinkList *head);
int getLen(LinkList *head);
void printLinkList(LinkList *head);
LinkList *createList(int len);
int deleteElem(LinkList *head,int pos);
void changeData(LinkList *head,int pos);
int searchLinkList(LinkList *head,ElemType e);
int insertLinkList(LinkList *head,int pos,ElemType e);
LinkList *reverseLinkList(LinkList *head);
void freeList(LinkList *head);

//判断链表是否为空
int isEmpty(LinkList *head){
    return head->next==NULL;
}

//获取链表长度
int getLen(LinkList *head){
    //头节点指向为空，单链表不含任何元素
    if(head->next==NULL){
        return 0;
    }
    int len=0;
    LinkList *r=head->next;
    while(r){
        r=r->next;
        len+=1;
    }
    return len;
}

//打印链表所有信息
void printLinkList(LinkList *head){
    LinkList *r;
    r=head;//->next;
    while(r){
        printf("%d ",r->data);
        r=r->next;
    }
}

//初始化链表--创建头节点-->
LinkList *initList(LinkList *head){
  head=(LinkList *)malloc(sizeof(LinkList)); //malloc函数为头节点动态分配空间
  //13052502670
    head->next=NULL;//头节点指针域置为空
  return head;
}

//创建指定节点的单链表
//根据输入的长度增加节点
//关键是循环将每一个新加的节点添加到尾部
LinkList *createList(int len){
    int i;
    ElemType e;
    LinkList *head = initList(head),*r,*n;
    //n=NULL;//新指针初始化为NULL
    r=head;//尾指针初始化为头指针-->开始只有头指针，还未有节点加入，所以尾指针初始化为头指针更加合适
    for(i=0;i<len;i++){
        scanf("%d",&e);
        n=(LinkList *)malloc(sizeof(LinkList));//为新的数据域申请空间//这里先分配空间是因为空间大小分配与输入的值大小无关
        n->data=e;//将输入的值放入节点
        n->next=NULL;//新加入的节点指针域置空
        r->next=n;//将新指针链入单链表末尾
        r=r->next;//指针后移
    }
    return head;
}

//删除指定位置的节点
int deleteElem(LinkList *head,int pos){//pos是需要删除的节点的位置
    //判断节点的是否合法
    if(pos<1||pos>getLen(head)){
        printf("删除位置错误");
        return 0;
    }

    LinkList *temp=head,*d;

    //将指针移动到指定位置
    //也可以定义一个for循环进行自增到指定位置
    while(--pos>0){
        temp=temp->next;//
    }
    d=temp->next;
     temp->next=d->next;
    d->next=NULL;
    free(d);
    return 1;

}

//修改节点的值
//传入头节点和需要修改节点的位置
void changeData(LinkList *head,int pos){
    //判断节点是否合法
    if(pos<1||pos>getLen(head)){
        return;
    }
    LinkList *r=head;
    int i=0;
    while(i<pos && r!=NULL){
        r=r->next;
        i++;
    }
    if (r!=NULL){
        printf("请输入修改后的值:");
        scanf("%d\n",&r->data);
    } else{
        printf("该节点不存在\n");
    }
}

//根据元素值查找指定元素的位置
// 返回对应的序号
int searchLinkList(LinkList *head,ElemType e){
    if(isEmpty(head)){
        return -1;
    }
    int pos=1;//位置从1开始(头指针)
    LinkList *r=head->next;
    while(r){//C语言中NULL是一个零指针变量
        if(r->data==e){
            return pos;
        }
        r=r->next;
        pos++;
    }
    return -1;
}

//将元素插入指定位置
int insertLinkList(LinkList *head,int pos,ElemType e){
    //判断链表是否合法
    if(pos<1 || pos>getLen(head)+1){
        return 0;
    }
    LinkList *r=head,*n;
    n=(LinkList *)malloc(sizeof(LinkList));//为插入节点分配空间
    n->data=e;
    n->next=NULL;
    while(--pos>0){
        r=r->next;//移动到将要插入的位置
    }
    n->next=r->next;
    r->next=n;
    return 1;
}

//链表倒置四种方法：https://blog.csdn.net/m0_52072919/article/details/115566960?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80%E9%93%BE%E8%A1%A8%E5%80%92%E7%BD%AE&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-115566960.nonecase&spm=1018.2226.3001.4187
//转置单链表：采用头插法
LinkList *reverseLinkList(LinkList *head){
    LinkList *pf=head,*pb=NULL,*temp=NULL;
    if(head == NULL || head->next == NULL){
        return head;
    }
    pb=pf->next;
    head->next=NULL;//头节点变为空，变为尾指针
    while (pb!= NULL){
        temp=pb;
        pb=pb->next;
        temp->next=pf;
        pf=temp;
    }
    head=pf;
    return head;
}

//释放指针内存空间
void freeList(LinkList *head){
    LinkList *freeNode;
    int num=0;
    while (head!=NULL){
        freeNode=head;
        head=head->next;
        free(freeNode);
        num+=1;
    }
    printf("释放了%d个堆空间",num);
}
int main() {
    //01.创造链表以及打印对应节点存放的值
    LinkList *head;
    ElemType e;
    int len;
    printf("输入你想要创造的链表长度：\n");
    scanf("%d",&len);
    //int len=3;
    head=createList(len);
    int l=getLen(head);
    printf("长度:%d\n",l);
    printLinkList(head);

    //02.返回元素2对应的位置
    int pos1 = searchLinkList(head,2);
    printf("元素2对应的位置是%d\n",pos1);

    //03将第三个位置的值改为4
    changeData(head,3);
    printLinkList(head);
    printf("\n");

    //04在第三个位置上插入元素5
    e=5;
    insertLinkList(head,3,e);
    printLinkList(head);
    printf("\n");

    //05删除第4个位置的节点
    deleteElem(head,4);
    printLinkList(head);
    printf("\n");

    //06倒置链表
    LinkList *new_head=reverseLinkList(head);
    printLinkList(new_head);

    //07释放内存空间
    freeList(new_head);//传入new_head是因为head已经发生了改变 变为了尾指针

    return 0;
}
