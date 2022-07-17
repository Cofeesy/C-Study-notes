#include <stdio.h>//打开工具库

int main()//程序入口
{//在c语言中大括号可以单起一行，区别于go
    printf("Hello, 我的World!\n")  ;//每一行结束需要分号，rust，java同样，go不需要//空格前可以有空格或者换行区别于java
    printf("%d\n",12+34);
    return 0;
    //gcc编译过程-->step1.预处理(Preprocessing)-->step02.编译(Compiler)-->step03.汇编(Assemble)-->step04.链接(Linker),生成一个二进制文件
    // )
}

/*基本程序框架
 #include <stdio.h>

 int main()
 {
  return 0
 }
 */
