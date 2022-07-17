#include <stdio.h>
#define size 10//标识符常量-->P40
int main() {
    //01.变量定义：<类型名称><变量名称>
      //声明变量：int price;
      //变量赋值：price = 60;
      // int amount;
      //声明多个变量:int price,amount;

      //变量三要素 (变量名+值+数据类型)

    //02.变量的数据类型
      //基本类型--数值类型和字符类型（char）
        //数值类型--整型和浮点型
          //整形：短整型（short），整型（int），长整型（long）
            short a = 3;
            printf("%d\n",a);
            //long b = 5;
          //浮点型：单精度型（float），双精度型（double）
            //浮点型默认为double型，声明float时，须后面加'f'或'F'
            //int q = 2.4;
            // printf("%d",q);-->输出结果:2-->系统认定为整型，自动四舍五入
            //float w=3.12f;
            //printf("%f\n",w);-->输出时，自动保留小数点6位
            //double e=3.14;-->通常情况下，使用double型比float更精确
            //printf("%f",e);
        //字符类型char
          //char c1 = 'a';
          //在c中，char的本质是一个整数，输出时，是ASCLL码对应的字符
          //本质
            //存储：字符’a’——>码值 (97)——>二进制 (1100001)——>存储()
            //读取：二进制(1100001)——>码值(97)——> 字符’a’——>读取(显示)
         //布尔类型_Bool
           //C89没有定义bool类型，以0为假，非0为真
           //C99开始支持_Bool来定义布尔类型
     //03.常量
       //字面常量
         //const修饰的常量
           //const int a = 1;
           //a = 2;-->会报错，常量一旦被const修饰就不能被修改
         //define定义的标识符常量
           int arr[size]={0};
       //枚举常量(enum)
         //形式：
           /*enum 标识符
           {
               枚举数据表
           }；*/
           enum Sex{
               MALE,// 0
               FEMALE,// 1
               SECRET// 2
           };
           //枚举类型Sex有三个数据(无赋值，自动赋值)，MALE，FEMALE，SECRET，序号分别是0，1，2，代表男性，女性，未知
           enum Sex s = FEMALE;
           printf("%d\n",MALE);
           printf("%d\n",FEMALE);
           printf("%d\n",SECRET);

           enum status
           {
               copy = 6,
               delete// 7
           };



      //04.sizeof运算符-->sizeof运算符用于获得数据类型或表达式的长度
        //sizeof(对象)
        //sizeof(类型)
        //sizeof 对象

      //05.signed和unsigned
        //signed：代表有符号的，第一个位代表正负
        //unsigned：代表无符号的，所有的位都为大小，没有负数(如go语言中的uint8)
          short i=-1;
          unsigned short j = -1;

          printf("%d\n",i);//d打印带符号的
          printf("%u\n",j);//u打印不带符号的



      //06.赋值运算符：
        //=；+=；-=；*=；/=；%=
        //C语言赋值运算符支持的是基本数据类型，包括char，int，和double，字符串和字符数组不能使用

      //07.算术运算符
        //+；-；*；/；%；++；--

      //08.关系运算符

      //09.逻辑运算符

      //10.三目运算符
        //语法：表达式1?表达式2:表达式3;
        //语义，先执行表达式1，如果表达式1的结果如果为真，那么执行表达式2，并且这个整体的运算式的结果是表达式2的结果；如果表达式1的结果如果为假，执行表达式3，运算式的结果是表达式3的结果。

      return 0;//这句以后的代码作废
}
