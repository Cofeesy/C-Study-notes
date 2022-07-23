#include <stdio.h>
#include <string.h>

struct Student02{
    char name[20];
    int num;
    float score;
};

void exchange(struct Student02 *p1, struct Student02 *p2){//Student使用需要先声明
    struct Student02 testStu;
    testStu=*p1;
    *p1=*p2;
    *p2=testStu;
}


int main() {
    //01.字符串：在c语言中没有特别的关键字来表示字符串，如果想把一个字符串读取到程序中，必须首先预留存储字符串的空间，然后用输入输出函数来获取这个字符串
      //字符串常量：以 NUL 字节结尾的 0 个或多个字符组成的序列。字符串常量是不可被修改的
        //一般以一对双引号""括起的一串字符串表示
        //在 C 语言中，常通过声明一个指向 char 类型的指针并将其初始化为一个字符串常量的方式来访问一个字符串
          char charArray1[]="hello,world";//声明并初始化一个字符数组,可以不用声明长度
          char *ptr;//声明一个char类型的指针
          ptr=charArray1;//指向charArray1
          printf("%s\n",ptr);//访问该字符串常量
          char charArray2[] = {'H','e','l','l','o'};    // 声明并初始化一个字符数组，可以不用声明长度
          char *message = "Hello World";//这里的message即指向的这个字符常量的第一个字符的地址，因此可以有以下两种操作：
          //a.可以通过字符指针 message 来访问字符串常量
            printf("%s\n",message);
          //b.访问这个字符常量的每一个字符
            while(*message != '\0'){//转义字符\0表示NULL
               printf("%c ",*message++);//
            }
            printf("\n");
      //创建存储空间(字符串数组)
        //a.通过数组分配
          char str[6];//如果没有初始化就需要声明长度
        //b.C语言动态内存分配--><后面补充>
      //输入函数(C库提供了三个读取字符串的函数)
        //gets()函数-->通过判断遇到的第一个换行符(\n)结束输入
          char str1[2];//最大可装20个字符的字符数组
          printf("请输入一个gets函数字符串:\n");
          gets(str1);//gets()函数读取输入的字符并存入str1,超出数组长度不会报错
          printf("gets()函数读取的str1:%s\n",str1);//输出存入的字符串
        //scanf()函数:使用%s格式来读入一个字符串
          //如果使用%s格式，字符串读取到(但不包括)下一个空白字符(比如空格、制表符或换行符)
          char str2[20];
          printf("请输入一个printf函数字符串:\n");
          scanf("%s",&str2);//绑定地址
          printf("scanf()函数读取的str2:%s\n",str2);
        //fgets()函数：需要额外两个参数：
          //fgets()读取到换行符，就会把它存到字符串里，而不是像gets()那样丢弃。
          //它需要第二个参数来说明最大读入字符数。如果这个参数值为n，fgets()就会读取最多n-1个字符或者读完一个换行符为止(因为会自动添加一个空字符(\n))，由这两者中最先满足的那个结束输入
          //它还需要第三个参数来说明读哪一个文件，从键盘上读取数据时，可以使用stdin(代表standard input)作为参数，这个标识符在stdio.h中定义
            char str3[20];//创建一个存储空间
            printf("请输入一个fgets函数字符串:\n");
            fgets(str3,10,stdin);//stdin固定
            printf("fgets()函数读取的str3:%s\n",str3);
      //输出函数
        //puts()函数：将一个字符串(以'\0'结束的字符序列)输出到终端。
          //输出的时候自动在后面添加换行符
          char str4[20];
          gets(str4);//接收
          puts(str4);//输出

          puts("I'm an argument to puts().\n"); //直接用字符串做参数输出

          char str5[80] = "An array was initialized to me.\n";
          puts(str5);//输出已经定义好的数组
        //fputs()函数
          //fputs()函数需要第二个参数来说明要写的文件，可以使用stdout(standard output)作为参数来进行输出显示。
          //输出的时候不自动添加换行符
        //printf()函数
          //printf()函数在输出字符串的时候同样需要一个字符串地址作为参数
          //输出的时候不自动添加换行符
      //其他函数:
        //strcat()函数-->字符串连接函数
          //格式：strcat(字符数组1,字符数组2)-->将字符串2连接到字符串1后面，结果放在字符串1中
            char str6[10]="kkk";
            char str7[10]="xxx";
            strcat(str6,str7);//拼接在str6

            printf("strcat函数拼接后:%s\n",str6);
        //strcpy()函数-->(strncpy函数)字符串复制的函数-->将字符数组2复制到字符数组1当中
            char str8[10]="ttt";
            char str9[10]="uuu";
            strcpy(str8,str9);//复制到str8

            printf("strcpy函数复制后:%s\n",str8);

        //strcmp()函数-->(strcmp函数)两个字符串比较函数-->字符串不能用等号比较大小，用此函数
          //格式：strcmp(字符串1，字符串2)；
          //规则
            //(1)如果全部字符相同，则认为两个字符串相等
            //(2)若出现不相同的字符，则以第一对不相同的字符比较结果为准。（'a'<'z'；'A'<'Z'）
            //(3)比较结果由函数值返回：
              //相同，返回0
              //字符串1>字符串2，返回整数
              //字符串2>字符串1，返回负数
              char str10[10]="qwer";
              char str11[10]="qwe";
              int n= strcmp(str10,str11);
              printf("比较后返回的是:%d\n",n);
          //strncmp()函数
            //格式：strncmp(字符串1,字符串2,n);-->n：选择字符串的前n个字符进行比较，定义和strcmp一样
            //规则与strcmp函数一样

        //strlen()函数-->测字符串长度
          //函数的值为字符串实际的长度(不包括 '\0' 在内)
          //格式：strlen(字符串);
            char str12[10]="wzwz";
            int m=strlen(str12);//m:返回的字符串的长度(整型)
            printf("str12字符串长度为:%d\n",m);

        //strlwr()函数-->将字符串全部转换为小写
          //格式：strlwr(字符串);

        //strupr()函数-->将字符串全部转换为大写
          //格式：strupr(字符串);

        //strstr()函数-->查找字符串
          //格式:strstr(字符串1，字符串2)；
            //判断字符串2是否是字符串1的字串
              //是，返回str2在str1中首次出现的地址
              //否，返回NULL
                // char a[] = "abcdefg";
                //char b[] = "bc";

                //char* ret = strstr(a, b);

                //if (ret == NULL){
                // printf("Can not find!\n");
                // }
                //else{
                //printf("%s\n", ret);  //输出 bcdefg

      //注意：
        //a.gets()函数不会检查存储区是否能够容纳实际输入的数据，多出来的字符简单地溢出到相邻的内存区
        //b.在使用字符串处理函数时，一定要使用  #include <string.h>  开头
        //c.空指针和空字符是不一样的，不要混淆。空指针是一个地址，而空字符是一个char类型的数据对象其值为0，数字上都可以用0表示，但是概念不同：NULL是一个指针，而0是一个char类型的常量


    //02.结构体：C语言中可以用来存放一组不同的数据类型
      //声明结构体示例：
        struct Student01{  //声明结构体
         char name[20];  //姓名
         int num;        //学号
         float score;    //成绩
         };//-->注意分号代表结束结构体
          //它们
          //全局结构体，类似全局变量，声明在所有函数之外，
          //局部结构体

      //定义结构体变量：
        //格式：struct 结构体名 结构体变量名;
          struct Student01 stu1;    //定义结构体变量
          //或者结结构体变量的定义也可以与结构体的声明同时，简化代码：
          //struct Student{
           //char name[20];-->占4个字节
           //int num;-->占4个字节
           //float score;-->占4个字节
          //}stu1{"mimi",20,99.1};            //在定义之后跟变量名//并且在此可以同时初始化-->注意顺序

          //结构体Student是定义的数据类型，不是变量不占空间

         //或者定义匿名结构体：
          struct {                //没有结构名
            char name[20];
            int num;
            float score;
          }stu2;

      //访问结构体变量：
        //结构体变量名.成员名
        stu1.name;
        stu1.num;
        stu1.score;

      //结构体变量初始化：
        //逐个赋值：
          stu1.num=20;
          stu1.score=98.4;
          //stu1.name="George";-->这样赋值是错误的，不能直接给数组名赋值-->数组名是一个指针常量
          strcpy(stu1.name,"George");//-->使用字符串复制函数
        //整个赋值：只能在定义的时候就同时初始化整个赋值；先定义 后赋值，这种情况只能单独赋值
          struct Student01 stu3={
                  "George",//相互之间用","隔开
                  38,
                  88.2
          };//定义的同时初始化整个赋值
          printf("stu3结构体变量访问：%s\n",stu3.name);
          //%c-->字符占位符

         //可以用一个已经存在的结构体去初始化一个新的相同类型的结构体变量，是整体的拷贝（每一个成员都一一赋值给新的结构体变量），而不是地址赋值
         struct Student01 stu4;
         stu4=stu3;//将stu3的值传给stu4

      //结构体数组
        //一般格式：
          //struct 结构名 {
            //成员列表;
          //} 数组名[数组长度];
        /*  struct Student02{
              char name[20];
              int num;
              float score;
          };*/
          //定义的时候整个赋值：
          struct Student02 stu5[10] = {
                  {
                      "George02",
                      33,
                      76
                  },//结构体之间逗号别忘掉
                  {
                      "George03",
                      22,
                      99
                  }
          };
          printf("结构体数组%s",stu5[0].name);
          //逐个赋值
            strcpy(stu5[2].name,"George04");//数组不能直接用字符串单独赋值
            stu5[2].score=99;
            stu5[2].num=55;
          //输出结构体
            //先获取结构体数组的长度
            int length = sizeof(stu5)/ sizeof(struct Student02);
            //逐个输出结构体数组的元素
            for (int i = 0; i < length; i++) {
            printf("姓名：%s  学号：%d  成绩：%f \n", stu5[i].name, stu5[i].num, stu5[i].score);
            }
     //结构体嵌套
       //结构体中的成员可以又是一个结构体，构成结构体的嵌套
         struct Birthday{                //声明结构体 Birthday
             int year;
             int month;
             int day;
         };
         struct Student04{                 //声明结构体 Student04
             char name[20];
             int num;
             float score;
             struct Birthday birthday;   //生日
         };

     //结构体与指针
      //一般格式：struct 结构体名* 指针名
        struct Student01 *p;//结构体指针
          p=&stu1;

        struct Student02 *ptr01;
        ptr01=stu5;//结构体数组指针，直接指向数组名字-->指针变量
        struct Student02 *ptr02;
        ptr02=&stu5[2];//stu[1]本身不是地址
        //ptr02=&stu5[2].name-->这种方法是错误的，不能用结构体指针 访问其成员变量

      //结构体指针变量访问结构体变量成员(需要指针先指向)(两种方式等价)：
        //第一种方式：
         (*p).num;//这里的括号不能少
        //第二种方式：
          p->num;

    //结构体作为函数参数
      //使用结构体变量作为函数参数的时候，采取的是值传递的方式，结构体所占内存单元的内容全部传递给形参
      //结构体所占内存单元的内容全部传递给形参
      //使用指针可以进行改变结构体变量
        struct Student02 *ptr03;
        struct Student02 *ptr04;

        ptr03=&stu5[0];
        ptr04=&stu5[1];

        exchange(ptr03,ptr04);
        printf("指针传递修改后：%s\n",stu5[0].name);//George03修改成功

    //清空结构体
      //一般情况下，以stu3为例-->187
        //stu3.name[0]='\0';
        //stu3.num=0;
        //stu3.score=0;
      //memset()方法清空：
        memset(&stu3,0, sizeof(struct Student01));
        printf("memset方法清空stu3结构体：%d\n",stu3.num);
    //链式结构(后面补充)


    return 0;
}
