

# 大数乘法

## 1.阶乘

```c++
#include<iostream>
using namespace std;
//大于12的数的阶乘   此时已经超过int数据上限
int main(){
	int num[3000]={0};		//存放大数乘法的结果
    int tmp=0;				//当前位
    int carry=0;			//进位
    int k=1;   				//标记数组num[]的数字个数  注意是从1开始，与数组下标不同
    int N;
    cin>>N;
    for(int i=2;i<=N;i++){
        for(int j=0;j<=k-1;j++){
            tmp=num[j]*i+carry;
            num[j]=tmp%10;
            carry=tmp/10;
        }
        while(carry){				//	一轮乘法结束之后还有进位，需要额外判断
            num[k]=carry%10;
            carry/=10;
            k++;
        }
    }
    for(int i=k-1;i>=0;i--){		//倒序排列，数组低位存放的是高位数字
        cout<<num[i];
    }
    return 0;
}
```

## 2.大数组相乘

```c++
#include<iostream>					//使用动态数组vector库函数来实现数据的动态输入和相乘
#include<vector>
using namespace std;

void Multi_(vector<int> &a, vector<int> &b,int Ka,int Kb) {
	//遍历数组a[]和b[]，获得最大下标Ka,Kb   数组默认倒装
    vector<int> C(Ka+Kb,0);
	int tmp = 0,  carry = 0, i = 0, j = 0, ctc = 0;
	for (i = 0; i < Ka; i++) {
		for (j = 0; j < Kb; j++) {						//注意括号内不能写int i  会覆盖外面定义的局部变量i j
			tmp = a[j] * b[i] + carry + C[j + i];
			C[i + j] = tmp% 10;
			carry = tmp / 10;
		}
		while (carry) {
			C[j + i] =(C[j+i]+carry )% 10;
			carry /= 10;
			j++;
		}
	}
	ctc = i+j-1;
	for (int k = 0; k < ctc; k++) {
		cout << C[k];
	}
}




int main() {
	int cta = 0, ctb = 0,temp=0;
	cout << "请倒序输入数字A：";
	vector<int> A;
	for (temp = 0; cin >> temp;) {
		A.push_back(temp);
		if (cin.get() == '\n') break;
	}	
	cta = A.size();
	for (int i = 0; i < cta; i++)
		cout << "A[" << i << "] : " << A[i] << endl;


	cout << "请倒序输入数字B：";
	vector<int> B;
	for (temp = 0; cin >> temp;) {
		B.push_back(temp);
		if (cin.get() == '\n') break;					//使用cin动态输入数字，当输入回车（换行符）即刻终止
	}

	ctb = B.size();
	for (int i = 0; i < ctb; i++)
		cout << "B[" << i << "] : " << B[i] << endl;
	Multi_(A, B, cta, ctb);
	system("Pause");
	return 0;
}
```

## 3. 大数加法

![image-20210318200206666](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210318200206666.png)

```c++
   //按位相乘
	#include<iostream>
    using namespace std;
    #define MAX 100005
    int a[MAX + 5] = { 0 };
    int main() {
        int tmp=0,carry=0,i=0,j=0;
        int A,N;
        cin>>A>>N;
        if(N==0) cout<<0;
        for(i=N;i>0;i--){
            tmp=i*A+carry;
            a[j++]=tmp%10;
            carry=tmp/10;
        }
        while(carry){
            a[j++]=carry%10;
            carry/=10;
        }
        for(int k=j-1;k>=0;k--) cout<<a[k];
        return 0;
    }
```




# PAT习题

## 7-23 币值转换

![image-20210319143200477](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210319143200477.png)

```c++
//大体思路是使用一个动态string数组存储每四位数
//之后按字输出，每输出一个字进行判断是否输出单位“千、百、十”
#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main(){
    char a[10]={'a','b','c','d','e','f','g','h','i','j'};int len=0,oplen=0,elementSize=0;
    string S;vector<string> OutPut;
    getline(cin,S);
    len=S.length();
    if(S=="0") {							//！！边界情况！！输入为零判断  不存在输入多个零的情况  
        cout<<"a";return 0;
    }
    int i=len-1;							/////////////////////////
    while(i>=0){	
        string temp="";						//临时字符串，每次循环前需要重置为空
        int cnt=0;							//计数器，四个一组压入OutPut//
        while((cnt+1)%5!=0&&i>=0){
            temp.push_back(a[S[i]-'0']);	//倒序将字符串压入vector中//
            i--;cnt++;
        }
        OutPut.push_back(temp);
    }										////////////////////////
    oplen=OutPut.size();int flag=0;
    for(int i=oplen-1;i>=0;i--){							//////////////////////////////
        elementSize=OutPut[i].length();
        for(int j=elementSize-1;j>=0;j--){
            if(OutPut[i][j]=='a'&&(flag==0||flag==1)) {		//使用flag来判断是否输出零“a”
                flag=1;continue;
            }
            else if(OutPut[i][j]!='a'&&flag==1){
                flag=0;
                cout<<"a"<<OutPut[i][j];
                }
            else if(OutPut[i][j]!='a'&&flag==0)
                cout<<OutPut[i][j];
            switch(j){
                case 3:cout<<"Q";break;								//倒序输出字符串
                case 2:cout<<"B";break;
                case 1:cout<<"S";break;
                default:break;
            }
            }
        switch(i+1){
            case 2:cout<<"W";break;
            case 3:cout<<"Y";break;
            default:break;
        }
    }													////////////////////////////////////////
    return 0;
}
```

## 7-29 删除字符串中的子串

​	![image-20210320233237017](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210320233237017.png)

```c++
///////////////////基本与法实现//////////////////////////
#include<iostream>
#include<string>

using namespace std;

int main(){
    string S,tmp;
    getline(cin,S);getline(cin,tmp);
    int Slen=S.length();int Tlen=tmp.length();
    int flag=0,i,j,k,mk=0;
    while(!flag){
                    flag=1;
        for(i=0;i<Slen;i++){

            if(S[i]==tmp[0]){
                mk=1;
                for(j=i,k=0;k<Tlen;j++,k++){
                    if(S[j]!=tmp[k]) {
                        mk=0;break;
                    }
                }
                            if(mk){
                flag=0;
                for(;j<Slen;j++,i++) S[i]=S[j];	
                S[i]='\0';						//交换完毕，尾部添加'\0'表示结束
                Slen=S.length();
                break;							//退出当前for循环，重新判断并且从头开始遍历
            }
            }
        }
    }
    cout<<S;
    return 0;
}



////////使用string库函数实现//////////////////
#include<iostream>
#include<string>

using namespace std;

int main(){
    string S,tmp;
    getline(cin,S);getline(cin,tmp);
    int Slen,Tlen,pos=0;
    int flag=0;
    while(!flag){
        flag=1;
        if(S.find(tmp)!=S.npos){
            flag=0;
            Slen=S.length();Tlen=tmp.length();	
            pos=S.find(tmp);					
            S.erase(pos,Tlen);
        }
    }
    cout<<S;
    return 0;
}
```

# LeetCode 习题

## 二维前缀和系列

### 303.  一维数组前缀和

![image-20210422095855314](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210422095855314.png)

**数学思想：**
$$
sumRange(i,j)=
\sum_{k=i}^{j}{nums[k]}\\
=\sum_{k=0}^{j}{nums[k]}-\sum_{k=0}^{i}{nums[k]}
$$


```c++
    class NumArray {
    private:
        int* sum;
    public:

        NumArray(vector<int>& nums) {
            int len=nums.size();
            sum=new int[len+1];
            sum[0]=0;						//方便后续计算
            for(int i=1;i<len;i++){
                sum[i+1]=sum[i]+nums[i];
            }
        }

        int sumRange(int left, int right) {
            return sum[right+1]-sum[left];
        }
    };
```

### 304.  二维数组前缀和

![image-20210422101328018](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210422101328018.png)

```c++
class NumMatrix {
private:
    vector<vector<int>> sum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int col=matrix[0].size();
        int row=matrix.size();
        sum.resize(row+1,vector<int>(col+1));        //自动全为零
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                sum[i+1][j+1]=sum[i][j+1]+sum[i+1][j]+matrix[i][j]-sum[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sum[row2+1][col2+1]-sum[row1][col2+1]-sum[row2+1][col1]+sum[row1][col1];		//与一维前缀和不同
    }
};
```

![image-20210422102847868](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210422102847868.png)

### 363.  矩形区域不超过K的最大数值和

![image-20210422102932047](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210422102932047.png)

```c++
class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
		
    }
};
```

## 最长递增子序列

### 300.最长递增子序列

![image-20210423112900804](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210423112900804.png)

```c++
//动态规划可解
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        vector<int> f(n,0);
        for(int i=0;i<n;i++){
            int len=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    if(f[j]+1>len){
                        len=f[j]+1;

                    }
                }
            }
            f[i]=len;
        }
        
        int index=max_element(f.begin(),f.end())-f.begin();
        return f[index];
    }
};
```

### 368.  最大整除子集

![image-20210423115358179](C:\Users\ASUS\AppData\Roaming\Typora\typora-user-images\image-20210423115358179.png)

```c++
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=nums.size();
        if(len==0||len==1) return nums;
        vector<int> f(len,0);			//动态规划数组，f[i]表示以nums[i]为结束的最长整除子序列
        vector<int> g(len,0);			//回溯数组，用于输出序列
        sort(nums.begin(),nums.end());
        for(int i=0;i<len;i++){
            int lth=1;int prev=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(f[j]+1>lth){
                        lth=f[j]+1;
                        prev=j;
                    }
                }
            }
            f[i]=lth;
            g[i]=prev;
        }


        int index=max_element(f.begin(),f.end())-f.begin();
        int max=f[index];

        vector<int> op;
        while(op.size()<max){
            op.push_back(nums[index]);
            index=g[index];
        }

        return op;
    }
};
```

