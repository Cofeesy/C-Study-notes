#include <stdio.h>

void swap(int *p1,int *p2)			//定义swap函数
{
    int temp;
    temp=*p1;					//使*p1和*p2互换
    *p1=*p2;
    *p2=temp;
}

int main() {
    //01.数组：一组相同类型元素的集合
    //一维数组
    //创建以及初始化：数据类型 数组名称[长度] = {...};-->长度为一个常量,不能为一个变量
    int arr1[6] = {1, 2, 3};//-->arr[0]=1，剩下的默认初始化为0
    int count = 2;
    int arr2[count];
    char array[5] = {'a', 'b'};//将b改为98也是可行的，98是b的
    printf("声明没有初始化arr2:%d\n", arr2);
    //获取数组长度:sizeof(arr)/sizeof(arr[0]);
    int len = sizeof(arr1) / sizeof(arr1[0]);
    printf("arr1的数组长度为%d\n", len);
    //数组遍历
    int i;
    for (i = 0; i < len; i++) {
        printf("%d\n", arr1[i]);
    }
    //一维数组在内存中是连续存放的

    //二维数组
    //简单创建以及初始化：数据类型 数组名称[行数][列数]或者[宽度][长度]
    int arr3[3][4] = {1, 2, 3, 4};//这样只初始化了第一行--> 1,2,3,4
    //   0,0,0,0
    //   0,0,0,0
    printf("arr3第一行第三列%d\n", arr3[0][2]);//-->3
    printf("arr3第二行第二列%d\n", arr3[1][1]);//-->0
    int arr4[3][4] = {{1, 2},
                      {3, 4}};//-->   1,2,0,0
    //   3,4,0,0
    //   0,0,0,0

    printf("arr4第二行第二列:%d\n", arr4[1][1]);//-->4
    printf("arr4第二行第一列:%d\n", arr4[1][0]);//-->3
    //获取二维数组的长度和宽度
    int length = sizeof(arr3[0]) / sizeof(arr3[0][0]);
    printf("arr3的长度为%d\n", length);//--> =列数=4
    int width = sizeof(arr3) / sizeof(arr3[0]);//-->=行数=3
    printf("arr3的宽度为%d\n", width);
    //for循环创建二维数组：
    int arr5[4][5] = {0};
    int j;
    for (j = 0; j < sizeof(arr5) / sizeof(arr5[0]); j++) {
        int k;
        for (k = 0; k < sizeof(arr5[0]) / sizeof(arr5[0][0]); k++) {
            arr5[j][k] = i + j;
        }
    }
    //for循环打印:
    for (i = 0; i < sizeof(arr5) / sizeof(arr5[0]); i++) {
        int k;
        for (k = 0; k < sizeof(arr5[0]) / sizeof(arr5[0][0]); k++) {
            printf("%d", arr5[i][k]);
        }
        printf("\n");
    }
    //注意：
    //a.二维数组也是连续存储的
    //b.数组记得做越界检查
    //c.&数组名,取出的是数组的地址
    //d.sizeof(数组名),计算整个数组的大小

    //.变长数组
    int n;
    printf("Input a number:");
    scanf("%d", &n);
    int arr[n];//长度声明在数组声明前面
    printf("这个变长数组的长度是%d\n", sizeof(arr) / sizeof(arr[0]));

    //02.指针(简单部分)-->后续补充深入知识
    //声明以及赋值
    int a = 100;
    char b = 'o';
    double c = 100.5;

    int *iptr;
    char *cptr;
    double *dptr;

    iptr = &a;
    cptr = &b;
    dptr = &c;
    //指针变量作为函数参数：将一个变量的地址传送到另一个函数中
    int d, e;
    int *pointer_1, *pointer_2;    //定义两个int *型的指针变量
    printf("please enter a and b:\n");
    scanf("%d,%d", &d, &e);        //输入两个整数
    pointer_1 = &d;            //使pointer_1指向d
    pointer_2 = &e;            //使pointer_2指向e
    if (d < e) {
        swap(pointer_1, pointer_2); //如果d<e，调用swap函数
    }
    printf("max=%d,min=%d\n", d, e);    //输出结果
    //通过指针引用数组元素：https://blog.csdn.net/weixin_43283397/article/details/103377157
    //下标法：如a[i]形式
    //指针法：如*(a+i)或*(p+i)-->a是数组名，p是指向数组元素的指针变量，其初值为p=a,指向数组a的第一个元素
      //数组的数组名其实可以看作一个指针
        int array1[10]={0};,*p;
        p=array1;
        p++;//-->相当于(array1+1)
        array1[1]//-->相当于*(array1+1);同理，array1[2]相当于*(array1+2);
        //通过数组名计算元素地址，找出元素的值
            // int i,a[5];
            //for(i=0;i<5;i++){
            //scanf("%d",&a[i]); // or scanf("%d",a+i)
            //}
            //for(i=0;i<5;i++){
            //printf("%d ",*(a+i));
            //}
        //通过指针变量输出整型数组 a 的5个元素
          //int i,a[5],*p;
          //p=a;

          //printf("Please enter 5 integer numbers:\n");
          //for(i=0;i<5;i++){
          //scanf("%d",p++);
          //}
          //p=a;//-->此时经过输入，p指针已经指向了该数组(a)的末尾，需要重新指向开头
          //for(i=0;i<5;i++,p++){    // or for(i=0;i<5;i++)
          //printf("%d ",*p);   //        printf("%d", *p++);
          //}
          //printf("\n");

     //用数组名(或指针变量)做函数参数
       //数组元素作实参时，参数传递具有单向性，即实参的改变可以影响形参，而形参的改变无法影响实参
       //但是当数组名(数组名是指针变量)或者指针变量作函数参数时，实参和形参的改变可以相互影响


    return 0;
}
