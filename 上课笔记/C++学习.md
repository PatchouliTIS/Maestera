# 5. 文件操作
**临时数据持久化：文件操作**

头文件：< fstream >

文件操作三大类：
1. ofstream 写操作
2. ifstream 读操作
3. fstream  读写


## 5.1 文本文件
### 5.1.1 写文件

写文件步骤：
``` c++
#include<fstream>   //包含文件操作头文件

ofstream ofs;       //创建文件流对象,fstream也可以

ofs.open("filePath",打开方式);             //打开文件，也可以在构造文件流对象时直接调用构造函数ofs("filePath",打开方式)

ofs<<"写入的数据";  //写入数据

ofs.close();        //关闭文件
```

打开方式分类：





### 5.1.2 读文件

读文件步骤:
``` c++
#include<fstream>   //包含文件操作头文件

ifstream ifs;       //创建文件流对象,fstream也可以


ifs.open("filePath",打开方式);
if(!ifs.is_open()){
    cout<<"打开失败";
    return 0;
}             //判断是否打开文件成功


//1.
char buf[1024]={0};
while(ifs>>buf){
    cout<<buf<<endl;
}  //读取数据方法1；
//2.
while(ifs.getline(buf,sizeof(buf))){
    cout<<buf<<endl;
}   //读取数据方法2；
//3.string类读入
string buf;
while(getline(ifs,buf)){
    cout<<buf<<endl;
}
//4.单字符读入
char c;
while((c=ifs.get())!=EOF){
    cout<<c<<endl;
}




ifs.close();        //关闭文件
```


## 5.2 二进制文件
### 5.2.1 写文件

``` c++
#include<fstream>


ofstream ofs("filePath",ios::out|ios::binary);      //写文件，直接调用构造函数

```
