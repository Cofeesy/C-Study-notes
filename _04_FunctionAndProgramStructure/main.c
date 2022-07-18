#include <stdio.h>//stdio.h 是C语言函数库中的一个头文件；里面声明了一些常用的输入输出函数，比如往屏幕上输出内容的printf函数
#include "sub.c"//调用不同.c文件时需要引用 //这是相对路径，也可以使用绝对路径
#include "square.c"
//#include是C语言的预处理指令之一(所谓预处理，就是在编译之前做的处理)

//头文件: .h文件,提供接口,头文件不得包含函数入口,头文件不不可单独编译成一个程序,仅仅包含函数片段或定义常,变量
//源文件: .c文件,提供实现,源文件必须包含函数入口,即main函数
//目标文件: .o文件,该文件是指源码经过编译程序产生的且能被cpu直接识别二进制代码,由编译器生成

int num(int a,int b){
    return a+b;
}
int swap(int *a,int *b){
    *a=*a+*b;
    *b=*a-*b;
    *a=*a-*b;
}

static void show(){
    printf("%s\n","这是main.c文件的show方法");
}

extern int square(int);//extern可以省略


int main() {
    //01.函数的声明以及定义：默认情况下，只有后面定义的函数才可以调用前面定义过的函数(调用顺序会被警告)
      //a.声明格式：返回值类型 函数名(参数1,参数2,....)-->P3
      //b.无参函数:
        //类型名  函数名（）
        // {
        //函数体
        // }
        //或者
        //类型名  函数名（）
        // {
        //函数体
        // }
      //c.有参函数
        //类型名 函数名（形式参数表列）
        // {
        //函数体
        // }
     //d.空函数
        //类型名 函数名（）
        //{    }
     // 调用1(本.c文件中)：
        printf("函数调用的结果是%d",num(5,6));
     //调用2(其他.c文件中)：
        //int c=sub(12,11);
        //printf("%d",c);
        //P13和P14是错误调用方式
          int c =sub(12,11);//-->P2引用
          printf("正确调用后c=%d\n",c);

    //02.参数传递
      //值传递
      //指针传递(类似go)-->&取地址，*取值和声明指针变量
        int a=3;
        int b=6;
        printf("交换前a=%d,b=%d\n",a,b);
        swap(&a,&b);
        printf("交换后a=%d,b=%d\n",a,b);

    //03.函数返回
      //有返回值
        //每次调用函数只能有一个return语句被执行-->并且只有一个返回值(go语言支持多个返回值)
      //无返回值：void关键字(java)
        //void函数中如果有return语句，该语句**只能起到结束函数运行的功能。**其格式为: return;
        //一旦函数返回值类型被定义成void，就不能再接收它的值了：
          // void func(){printf("http://xxxxx\n");}
          //int a = func();-->这个语句是错误的

    //04.函数递归

    //05.全局变量和局部变量-->变量的作用域
      //程序结尾的全局变量是没有意义的

    //06.内部函数和外部函数
      //外部函数:extern-->引用外部函数都需要在头部声明
        printf("外部函数%d\n",square(6));
      //内部函数:static-->声明在返回值类型前面-->避免出现重名的情况
        //注意：
          //a.声明外部函数时，无论有没有关键字extern，外部函数与原函数定义的返回值类型、函数名称和参数列表必须一致
          //b.定义内部函数时，需要在函数的返回值类型前面添加static关键字
          //c.注意:(https://blog.csdn.net/guotianqing/article/details/79828100?ops_request_misc=&request_id=&biz_id=102&utm_term=c%E8%AF%AD%E8%A8%80static%E5%85%B3%E9%94%AE%E8%AF%8D&utm_medium=distribute.pc_search_result.none-task-blog-2~all~sobaiduweb~default-3-79828100.nonecase&spm=1018.2226.3001.4187)
            //d.static功能类似全局变量
            //e.静态函数只能在声明它的文件中可见，其他文件不能引用该函数
            //f.不同的文件可以使用相同名字的静态函数，互不影响
            show();//只有main.c文件可以引用该函数

    return 0;
}