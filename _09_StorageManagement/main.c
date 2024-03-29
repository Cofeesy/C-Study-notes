#include <stdio.h>
#include <malloc.h>
#include <malloc.h>
int main() {

    //c语言五大内存分区
      //堆区：该区由程序员申请后使用，需要手动释放否则会造成内存泄露。如果没有手动释放，那么程序结束后可能由OS回收
        //malloc函数申请，释放free函数
      //栈区：存放函数形参和局部变量(auto类型),由编译器自动分配和释放
        //例如，声明在函数中一个局部变量“int b“。系统自动在栈中为b开辟空间，当对应的生存周期结束后栈空间自动释放
      //全局/静态存储区：存放全局变量和静态变量(包括静态全局变量和静态局部变量)，初始化的全局变量和静态局部变量放在一块儿，未初始化的放在另一块儿
      //文字常量区：常量在统一运行被创建，常量区的内存是只读的，程序结束后由系统释放
      //程序代码区：存放程序的二进制代码，内存由系统管理


    //c语言四种存储类别
      // 自动变量(auto)
        //定义：通常在自定义函数内或代码段中（用“{}”括起来的）定义的变量，都是自动变量

      //静态变量(static)
        //有时希望函数中的局部变量的值在函数调用结束后不消失而保留原值

      //寄存器变量(register)
        //

      //外部变量(extern)-->全局变量
        //定义：再函数外部定义的，它的作用域从变量定义处开始，到本程序的末尾
        //如果外部变量不在文件的开头定义,其有效的作用范围只限于定义处到文件末尾

    //动态内存管理

      //动态内存函数
        //malloc()函数:用来在堆中开辟动态内存(申请堆空间)
          //需要头文件<malloc.h> --> #include <malloc.h>
          //void *malloc(size_t size);
          //申请成功返回，返回指向这篇空间的指针，若失败返回NULL
          //由于返回的是void*，我们并不知道size字节存储的数据类型，所以需要我们自行决定
          //如果size=0，此行为是未定义的，会发生未知错误，取决于编译器

          //创建一个数组p[n]
          int *p1=NULL;
          int n;
          scanf("%d",&n);
          p1=(int *)malloc(sizeof(int) * n);

          if(p1!=NULL){
              printf("malloc()函数分配了一块%d字节大小的堆空间\n",sizeof(int) * n);
          }else{
              printf("malloc()函数分配内存空间失败\n");
          }

    //free()函数：用来释放创建的堆空间

          //先设为NULL
          p1=NULL;
          //操作完成，释放空间
          free(p1);
          //free(p);不能重复释放，会出现内存错误

    //calloc()函数
      //需要头文件<stdlib.h> --> #include <stdlib.h>
      //void *colloc(size_t num_elements,size_t element_size);
      //功能同malloc()函数一样的
      //参数:num_elements是所需的元素的数量，element_size是每个元素的字节数
      //申请成功返回，返回指向这篇空间的指针，若失败返回NULL，，同malloc()函数一样
      int m;
      scanf("%d",&m);
      int *p2=(int *)calloc(m, sizeof(int));
      if(p2!=NULL){
          printf("calloc()函数分配了一块%d字节大小的堆空间\n",sizeof(int) * m);
      }else{
          printf("calloc()函数分配内存空间失败\n");
      }


      //释放时先将指针设为NULL
      p2=NULL;
      //同样需要释放空间
      free(p2);


    //realloc()函数:动态扩大缩小申请的内存(动态数组)
      //需要头文件<stdlib.h> --> #include <stdlib.h>
      //void *realloc(void *ptr,size_t new_size);
      //功能:在指针ptr指向的内存基础上扩大或者缩小内存
      //参数:ptr是指向先前通过malloc,calloc和realloc函数后分配的内存块的指针，new_size是内存块的新尺寸，可能大于或者小于原有内存尺寸；这个是追加到new_size的新的内存
      //注意点:
        //a.当扩展内存的时候，不会对添加进内存块的字节进行初始化
        //b.若不能调整内存则返回NULL，但原有内存中的数据是不会发生改变的
        //c.若第一个参数为NULL那么功能 等同与malloc函数，若第二个参数为0,那么会释放调用内存块
          //realloc(NULL,10*size(int)) 等同malloc(10*sizeof(int));
          //realloc(p,0); 等同于free
        //d.当缩小或者扩大内存时，一般不会对其进行移动，若无法扩大内存块，那么啃呢个会在别处分配新的内存快，然后把旧内存块的数据复制到新块 中，并将旧块删除释放内存


    //内存错误注意点：
      //01 指针消亡了，并不意味着它所指向的内存会被自动释放-->解决：在free之前，直接将指针设为NULL，然后再free指针
      //02 野指针()
        //野指针是指指针变量声明了但未初始化(这种指针将指向随机空间)-->任何指针在刚刚被创建的时候不会自动成为NULL指针
        //所以指针在声明的时候要么让它指向NULL，要么让它执行合法内存
      //03 多次free同一个指针会导致程序崩溃
    return 0;
}
