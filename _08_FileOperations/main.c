#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    //01.文件定义相关
      //文件定义：文件通常是指在磁盘或固态是的一段已经命名的**缓冲区**
      //c提供了两种模式：文本模式和二进制模式

      //文件名包含3部分：文件路径+文件名主干+文件后缀
      //例如: c:\code\test.txt

      //每个被使用的文件都在内存中开辟了一个相应的文件信息区(缓冲区)，用来存放文件的相关信息（如文件的名字，文件状态及文件当前的位置等）。
      //这些信息是保存在一个结构体变量中的。该结构体类型是有系统声明的，取名FILE

    //02文件的打开和关闭
      //打开文件
        //每当打开一个文件的时候，系统会根据文件的情况自动创建一个FILE结构的变量，并填充其中的信息
        //我们一般通过一个FILE指针来维护这个FILE结构的变量
          FILE* fp01;//创建一个文件指针变量
          FILE* fp02;
          //通过这个文件指针变量能够找到与它关联的文件

          //FILE * fopen ( const char * filename, const char * mode );P8filename
          //filename为文件文件名(即路径)，第二个参数为c语言指定的模式字符串
          fp01=fopen("E:\\C Projects\\_08_FileOperations\\myfile1.txt","w");//以输出的形式(写)打开文件//fp为文件指针//这里使用绝对路径
          fp02=fopen(".\\myfile2.txt","w");//相对路径打开-->修改配置-->Run-->Edit Configuaration-->修改Woking directory,将路径改为工程路径就可以使用相对路径了
          //mode:
          /*文件使用方式	含义	                                 如果指定文件不存在
           "r"（只读）	    为了输入数据，打开一个已经存在的文本文件    出错
           "w"（只写）	    为了输出数据，打开一个文本文件	         建立一个新的文件
           "a"（追加）	    向文本文件尾添加数据	                     建立一个新的文件
           "rb"（只读）	    为了输入数据，打开一个二进制文件      	 出错
           "wb"（只写）	    为了输出数据，打开一个二进制文件	         建立一个新的文件
           *///如果使用w模式打开一个现有的文本文件，该内容会被删除，所以谨慎使用w模式

          //文件操作
          if((fp01!=NULL) && (fp02!=NULL)){
              fputs("fopen example01",fp01);//以字符串形式写入
              fputs("fopen example02",fp02);
              //关闭文件
              //int a=fclose(fp01);//文件成功关闭时fclose函数会返回0，否则返回EOF(EOF指文件结尾)
              //fclose(fp02);
              //printf("%d\n",a);
          }else if((fp01==NULL) && (fp02==NULL)){
              printf("打开文件失败\n");
          }

          //文件读写操作
            //输出/写入 就是将数据写入到文件当中
            //输入/读取 就是将文件中的内容读取到内存当中

            //文件读写函数
               /* 功能      	函数名	适用于
                  字符输入函数	fgetc	所有输入流
                  字符输出函数	fputc	所有输出流

                  文本行输入函数	fgets	所有输入流
                  文本行输出函数	fputs	所有输出流

                  格式化输入函数	fscanf	所有输入流
                  格式化输出函数	fprintf	所有输出流

                  二进制输入	    fread	文件
                  二进制输出  	fwrite	文件
                */

           //fread函数读取文件内容
             //函数原型：size_t fread(void *ptr, size_t size,size_t nmemb, FILE *stream);
             //ptr: 缓冲区指针，也就是说我们读出来的数据放在什么位置
             //size:一次读多大呢？
             //number:读几次呢？
             //stream: 从哪里读呢？
             //return：成功返回读取的次数，失败返回0

             FILE *fp03;
             const char *file_name="myfile3.txt";

             fp03=fopen(file_name,"r");//只读模式打开文件
             if (fp03!=NULL){
                 //定义缓冲区，接收读取到的数据
                 //定义6,那么接收的实际数据为5，多一个字符空间用来存放'/0'
                 char read_buffer[6]={0};
                 //size_t(全称size type,用来记录大小的(size)的数据类型)不是基本数据类型，也不是关键字，而是c语言自定义的数据类型
                 //它是一种"整型类型"，里面保存的时一个整数，类似int,long那样，
                 size_t read_ret=fread(read_buffer,5,1,fp03);
                 if (read_ret==0){
                     printf("读取失败\n");
                     return -1;
                 } else{
                     printf("读取成功,读取到的数据为:%s\n",read_buffer);
                 }


             }
             //fclose(fp03);//逻辑完，关闭文件


          //文件读写移动操作
            //ftell函数：用来获取文件当前位置
              //格式:long n;
              //     n=ftell(fp);
              //     该函数返回一个长整型，表示当前的读写位置;正确返回当前读写位置，错误返回-1L

            //fseek函数：用来改变文件指针的当前位置
              //格式：fseek(FILE *stream,long offset,int from);
              //      打开文件的指针
              //      offset:位移量，类型为long型，表示以from为起点移动的量相对值（字节数）
              //      from:移动的起始位置(基准点)
                 //基准点包括三种枚举
                   //SEEK_SET：文件头。-->0
                   //SEEK_CUR：当前位置。-->1
                   //SEEK_END：文件末尾。-->2
              //      成功返回1，失败返回-1(如果执行失败(比如offset超过文件自身大小)，则不改变stream指向的位置)
              int q=fseek(fp01,3L,0);//将fp01指针移动到离文件开头3字节处；
              printf("fp01指针移动:%d\n",q);
              int w=fseek(fp02,3L,1);//将fp02指针移动到离文件当前位置3字节处；
              printf("fp02指针移动:%d\n",w);
              int e=fseek(fp03,-3L,2);//将fp03指针移动到离文件尾处3字节处；
              printf("fp03指针移动:%d\n",e);

              //关闭
              int a=fclose(fp01);
              printf("%d\n",a);
              fclose(fp02);
              fclose(fp03);
          //其他文件函数用到了再学



    return 0;
}
