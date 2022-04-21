# 第一部分 程序结构和执行

## 第二章 信息的表示和处理

### 2.1 信息存储

#### 练习题2.1

A. 0x39A7F8 = $0011|1001|1010|0111|1111|1000_2$

B. $1100|1001|0111|1011_2$ = 0xC97B

C. 0xD5E4C = $1101|0101|1110|0100|1100_2$

D. $10|0110|1110|0111|1011|0101_2$ = 0x26E7D5

#### 练习题2.2

| n      | $2^n$（十进制） | $2^n$（十六进制） |
| ------ | --------------- | ----------------- |
| **9**  | **512**         | **0x200**         |
| **19** | 524288          | 0x80000           |
| 14     | **16384**       | 0x4000            |
| 16     | 65536           | **0x10000**       |
| **17** | 131072          | 0x20000           |
| 5      | **32**          | 0x20              |
| 7      | 128             | **0x80**          |

#### 练习题2.3

| 十进制  | 二进制        | 十六进制 |
| ------- | ------------- | -------- |
| **0**   | **0000 0000** | **0x00** |
| **167** |               |          |
| **62**  |               |          |
| **188** |               |          |
|         | **0011 0111** |          |
|         | **1000 1000** |          |
|         | **1111 0011** |          |
|         |               | **0x52** |
|         |               | **0xAC** |
|         |               | **0xE7** |

#### 练习题2.4

A. 0x503c + 0x8 = 0x5044

B. 0x503c - 0x40 = 0x499c

C. 0x503c + 64 = 0x503c + 0x40 = 0x507c

D. 0x50ea - 0x503c = 0xae

#### 练习题2.5

|     | 小端法   | 大端法   |
| --- | -------- | -------- |
| A   | 21       | 87       |
| B   | 21 43    | 87 65    |
| C   | 21 43 65 | 87 65 43 |

#### 练习题2.6

A. 0x00359141 = 0000 0000 0011 0101 1001 0001 0100 0001

​	 0x4A564504 = 0100 1010 0101 0110 0100 0101 0000 0100

B. 00000000001**101011001000101000001**

​         010010100**101011001000101000001**00

​	共21位匹配

C. 整数的前11位，浮点数的前九位和后两位

#### 练习题2.7

 61 62 63 64 65 66

#### 练习题2.8

略

#### 练习题2.9

略

#### 练习题2.10

| 步骤  | *x        | *y        |
| ----- | --------- | --------- |
| 初始  | a         | b         |
| 第1步 | a         | b^a       |
| 第2步 | a^(b^a)=b | b^a       |
| 第3步 | b         | (b^a)^b=a |

#### 练习题2.11

略

#### 练习题2.12

A.

```C
x = x & 0x000000FF;
```

B.

```C
x = x ^ 0xFFFFFF00;
```

C.

```C
x = x | 0x000000FF;
```

#### 练习题2.13

```C
int bis(int x, int m) {
    return x | m;
}

int bic(int x, int m) {
    return (x ^ m) & x;
}

int bool_or(int x, int y) {
    int result = bis(x, y);
    return result;
}

int bool_xor(int x, int y) {
    int result = bis(bic(x, y), bic(y, x));
    return result;
}
```

直接看位模式推理更简单。

#### 练习题2.14

略

#### 练习题2.15

```C
!!(x^y)
```

### 2.2 整数表示

#### 练习题2.16

| x        |          | x<<3     |          | x>>2(逻辑) |          | x>>2(算术) |          |
| -------- | -------- | -------- | -------- | ---------- | -------- | ---------- | -------- |
| 十六进制 | 二进制   | 二进制   | 十六进制 | 二进制     | 十六进制 | 二进制     | 十六进制 |
| **0xC3** | 11000011 | 00011000 | 0x18     | 00110000   | 0x30     | 11110000   | 0xF0     |
| **0x75** | 01110101 | 10101000 | 0xA8     | 00011101   | 0x1D     | 00011101   | 0x1D     |
| **0x87** | 10000111 | 00111000 | 0x38     | 00100001   | 0x21     | 11100001   | 0xE1     |
| **0x66** | 01100110 | 00110000 | 0x30     | 00011001   | 0x19     | 00011001   | 0x19     |

#### 练习题2.17

略

#### 练习题2.18

略

#### 练习题2.19

略

#### 练习题2.20

略

#### 练习题2.21

略

#### 练习题2.22

略

#### 练习题2.23

A.

| w          | fun1(w)    | fun2(w)    |
| ---------- | ---------- | ---------- |
| 0x00000076 | 0x00000076 | 0x00000076 |
| 0x87654321 | 0x00000021 | 0x00000021 |
| 0x000000C9 | 0x000000C9 | 0xFFFFFFC9 |
| 0xEDCBA987 | 0x00000087 | 0xFFFFFF87 |

B.

取word最后八位，前面24位置0（fun1）或者根据后八位最高位置0或1（fun2）

#### 练习题2.24

| 十六进制 |        | 无符号 |        | 补码   |        |
| -------- | ------ | ------ | ------ | ------ | ------ |
| 原始值   | 截断值 | 原始值 | 截断值 | 原始值 | 截断值 |
| 0        | 0      | 0      | 0      | 0      | 0      |
| 2        | 2      | 2      | 2      | 2      | 2      |
| 9        | 1      | 9      | 1      | -7     | 1      |
| B        | 3      | 11     | 3      | -5     | 3      |
| F        | 7      | 15     | 7      | -1     | -1     |

#### 练习题2.25

略

#### 练习题2.26

略

### 2.3 整数运算

#### 练习题2.27

```C
int uadd_ok(unsigned x, unsigned y) {
    unsigned result = x + y;
    return x < result;
}
```

#### 练习题2.28

略

#### 练习题2.29

略

#### 练习题2.30

```c
int tadd_ok(int x, int y) {
    int result = x + y;
    return !((x>0&&y>0&&result<=0)||(x<0&&y<0&&result>=0));
}
```

#### 练习题2.31

略

#### 练习题2.32

理论上是正确的，但是由于表示范围的不对称，-TMin = TMin，所以y=TMin时要单独处理

#### 练习题2.33

略

#### 练习题2.34

| 模式   | x      | y      | x*y       | 截断的x*y |
| ------ | ------ | ------ | --------- | --------- |
| 无符号 | 100=4  | 101=5  | 10100=20  | 100=4     |
| 补码   | 100=-4 | 101=-3 | 01100=12  | 100=-4    |
| 无符号 | 010=2  | 111=7  | 01110=14  | 110=6     |
| 补码   | 010=2  | 111=-1 | 11110=-2  | 110=-2    |
| 无符号 | 110=6  | 110=6  | 100100=36 | 100=4     |
| 补码   | 110=-2 | 110=-2 | 000100=4  | 100=4     |

#### 练习题2.35

略

#### 练习题2.36

略

#### 练习题2.37 

略

#### 练习题2.38

a*($2^k\pm 1)$或a\*$2^k$

#### 练习题2.39

x<<(n+1) = 0

#### 练习题2.40

| K          | 移位 | 加减法 | 表达式                           |
| ---------- | ---- | ------ | -------------------------------- |
| 6(110)     | 2    | 1      | (x<<2)+(x<<1) or (x<<3) - (x<<1) |
| 31(11111)  | 1    | 1      | (x<<5)-x                         |
| -6(2 - 8)  | 2    | 1      | (x<<1)-(x<<3)                    |
| 55(110111) | 2    | 2      | (x<<6)-(x<<3)-x                  |

#### 练习题2.41

略

==练习2.42-2.44==

### 2.4 浮点数

#### 练习题2.45

略

#### 练习题2.46

A. 0.00000000000000000000000[1100]..

B.0.1-x = 0.0[0011].. * $2^{-20}$ = 9.537e-8

C. x = 0.099999905 s

运行了100h，实际运行了100h/x s = 3600003tick

差值为0.343s

D. $\Delta t \vdot v$ = 686m

#### 练习题2.47

| 位      | e   | E   | $2^E$ | f   | M   | $2^E \times M$ | V   | 十进制 |
| ------- | --- | --- | ----- | --- | --- | -------------- | --- | ------ |
| 0 00 00 | 0   | 0   | 1     | 0/4 | 0/4 | 0/4            | 0/4 | 0      |
| 0 00 01 | 0   | 0   | 1     | 1/4 | 1/4 | 1/4            | 1/4 | 0.25   |
| 0 00 10 | 0   | 0   | 1     | 2/4 | 2/4 | 2/4            | 2/4 | 0.5    |
| 0 00 11 | 0   | 0   | 1     | 3/4 | 3/4 | 3/4            | 3/4 | 0.75   |
| 0 01 00 | 1   | 0   | 1     | 0/4 | 4/4 | 4/4            | 1   | 1      |
| 0 01 01 | 1   | 0   | 1     | 1/4 | 5/4 | 5/4            | 5/4 | 1.25   |
| 0 01 10 | 1   | 0   | 1     | 2/4 | 6/4 | 6/4            | 3/2 | 1.5    |
| 0 01 11 | 1   | 0   | 1     | 3/4 | 7/4 | 7/4            | 7/4 | 1.75   |
| 0 10 00 | 2   | 1   | 2     | 0/4 | 4/4 | 8/4            | 2   | 2      |
| 0 10 01 | 2   | 1   | 2     | 1/4 | 5/4 | 10/4           | 5/2 | 2.5    |
| 0 10 10 | 2   | 1   | 2     | 2/4 | 6/4 | 12/4           | 3   | 3      |
| 0 10 11 | 2   | 1   | 2     | 3/4 | 7/4 | 14/4           | 7/2 | 3.5    |
| 0 11 00 | -   | -   | -     | -   | -   | -              |     | -      |
| 0 11 01 | -   | -   | -     | -   | -   | -              |     | -      |
| 0 11 10 | -   | -   | -     | -   | -   | -              |     | -      |
| 0 11 11 | -   | -   | -     | -   | -   | -              |     | -      |

#### 练习题2.48

3510593 = 0000 0000 001**1 0101 1001 0001 0100 0001** = 1.101011001000101000001 * $2^{21}$

s = 0

E = 21 e = 148 exp = 1001 0100

frac = 1010 1100 1000 1010 0000 100

所以单精度浮点表示为 0100 1010 0**101 0110 0100 0101 0000 01**00 = 0x4A564504

#### 练习题2.49

A.

对于n位小数格式，其最小精度为$2^{-n}$，当阶数E>n时，显然不能精确表示。

能精确表示的最大正整数-1为1.1111...1 * $2^n$ = $(2-2^{-n}) * 2^n$ = $2^{n+1} -1 $

能精确表示的最大正整数为1.00000...0 * $2^{n+1}$ = $2^{n+1}$

则不能精确表示的最小正整数为$2^{n+1}+1$

B.

$2^{24} + 1$ = 16777217

#### 练习题2.50

略

#### 练习题2.51

略

#### 练习题2.52

略

#### 练习题2.53

略

#### 练习题2.54

略

### 家庭作业

#### 2.55

略

#### 2.56

略

#### 2.57

```C
void show_short(short x) {
    show_bytes((byte_pointer) &x, sizeof(short)); 
}

void show_long(long x) {
    show_bytes((byte_pointer) &x, sizeof(long)); 
}

void show_double(double x) {
    show_bytes((byte_pointer) &x, sizeof(double));
}
```

#### 2.58

```C
int is_little_endian() {
    int x = 0xFC;
    byte_pointer start = (byte_pointer) &x;
    if ((int) *start == 0xFC) {
        return 1;
    }
    return 0;
}
```

#### 2.59

```C
int combine(int x, int y) {
    return (x & 0x00FF) | (y >> 8 << 8);
}
```

#### 2.60

```C
unsigned replace_byte(unsigned x, int i, unsigned char b) {
    return (x & ~(0xFF << (i*8))) | (b << (i*8));
}
```

#### 2.61

```C
int a = !(~x);
int b = !x;
int c = !(~(x << (w-8) >> (w-8)));
int d = !(x >> (w-8));
```

#### 2.62

```C
int int_shifts_are_arithmetic() {
    int w = sizeof(int) << 3;
    int x = 0x000000FF;
    return !(~(x << (w-8) >> (w-8)));
}
```

#### 2.63

```C
unsigned srl(unsigned x, int k) {
    unsigned xsra = (int) x >> k;
    int w = sizeof(int) << 3;
    unsigned mask = ~(0xFFFFFFFF << (w-k));
    return xsra & mask;
}

int sra(int x, int k) {
    int xsrl = (unsigned) x >> k;
    int w = sizeof(int) << 3;
    int mask = (-(!!(x & 0x80000000))) << (w-k);
    return xsrl | mask;
}
```

#### 2.64

```C
int any_odd_one(unsigned x) {
    unsigned mask = 0xAAAAAAAA; // 0x55555555 otherwise
    return !!(x & mask);
}
```

#### 2.65

```C
int odd_ones(unsigned x) {
    x = (x >> 16) ^ x;
    x = (x >> 8) ^ x;
    x = (x >> 4) ^ x;
    x = (x >> 2) ^ x;
    x = (x >> 1) ^ x;
    return x & 0x00000001;
}
```

#### 2.66

我的答案（运算符过多）

```C
int leftmost_one(unsigned x) {
    int pos = !!(x >> 16) * 16; // leftmost_one is in 16-31 or 0-15
    pos += !!(x >> (pos + 8)) * 8;
    pos += !!(x >> (pos + 4)) * 4;
    pos += !!(x >> (pos + 2)) * 2;
    pos += !!(x >> (pos + 1));
    return (1 << pos) & x;
}
```

满足要求的答案

```C
int leftmost_one(unsigned x) {
  x |= x >> 1;
  x |= x >> 2;
  x |= x >> 4;
  x |= x >> 8;
  x |= x >> 16;
  return (x >> 1) + (x && 1);
}
```

其核心思想就是用最左侧的1 把右侧（包括最左1位）的2、4、8、16、32位全部置1

#### 2.67

A.

位移数不得大于等于位数

B.

```C
int int_size_is_32() {
    int set_msb = 1 << 31;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
```

C.

```C
int int_size_is_32() {
    int set_msb = 1 << 15 << 15 << 1;
    int beyond_msb = set_msb << 1;
    return set_msb && !beyond_msb;
}
```

#### 2.68

```C
int lower_one_mask(int n) {
    return (((1 << (n-1)) - 1) << 1) + 1;
}
```

#### 2.69

```C
unsigned rotate_left(unsigned x, int n) {
    int w = sizeof(x) << 3;
    unsigned left = x << n;
    unsigned right = x >> (w-n);
    return left | right;
}
```

#### 2.70

```C
int fits_bits(int x, int n) {
    int max = (1 << n-1) - 1;
    int min = -(1 << (n-1));
    return x <= max && x >= min;
}
```

#### 2.71

A.

不是符号扩展

B.

```C
int xbyte(packed_t word, int bytenum) {
    return (int)word << ((3-bytenum)<<3) >> 24;
}
```

#### 2.72

A.

运算结果被转换成size_t格式（unsigned），无论如何都大于等于0

B.

```C
void copy_int(int val, void *buf, int maxbytes) {
    if (maxbytes-(int)sizeof(val) >= 0)
        memcpy(buf, (void *) &val, sizeof(val));
}
```

#### 2.73

我的答案

```C
int saturating_add(int x, int y) {
    int w = sizeof(int) << 3;
    int result = x + y, INT_MAX = (1 << (w-1)) - 1, INT_MIN = 1 << (w-1);
    int p_of = x>0 && y>0 && result <= 0, n_of = x<0 && y<0 && result >= 0, of = p_of || n_of;
    int p_mask = p_of << (w-1) >> (w-1), n_mask = n_of << (w-1) >> (w-1), re_mask = (!of) << (w-1) >> (w-1);
    return (result & re_mask) | (p_mask & INT_MAX) | (n_mask & INT_MIN);
}
```

问题1：太过繁琐

问题2：使用了比较运算（不过可以通过取最高位的方式代替，不影响）

看一下大佬的解法

```C
int saturating_add(int x,int y){
    int sum = x+y;
    int mask = INT_MIN;
    int pos_over = !(x&mask)&&!(y&mask)&&(sum&mask);
    int neg_over = (x&mask)&&(y&mask)&&!(sum&mask);
    (pos_over&&(sum=INT_MAX))||(neg_over&&(sum=INT_MIN));//这段是求教大佬得到的，实在精妙
    return sum;
}
```

非常巧妙的是在不允许用条件语句的情况下，用了一个逻辑表达式的短路求值达到了条件语句的效果

#### 2.74

```C
int tsub_ok(int x,int y){
    int sub = x-y;
    return !((x>0&&y<0&&sub<0)||(x<0&&y>0&&sub>0));
}
```

#### 2.75

$$
x'\vdot y' = (x + x_{w-1}2^w)\vdot (y+y_{w-1} 2^w) \\
= x\vdot y + (xy_{w-1} + x_{w-1}y)2^w + x_{w-1}y_{w-1}2^{2w}
$$

```C
unsigned unsigned_high_prod(unsigned x, unsigned y) {
  int sig_x = x >> 31;
  int sig_y = y >> 31;
  int signed_prod = signed_high_prod(x, y);
  return signed_prod + x * sig_y + y * sig_x;
}
```

#### 2.76

```C
void *calloc(size_t nmemb, size_t size) {
    if (nmemb == 0 || size == 0) return NULL;
    int mult = nmemb * size;
    if (nmemb = mult / size) {
        void *p = malloc(nmemb * size);
        if (p)
            memset(p, 0, nmemb * size);
        return p;
    }
    return NULL;
}
```

其实如果乘法溢出的话，结果是不是肯定小于原来的结果？会造成漏洞吗？

#### 2.77

A. x << 4 + x

B. x - (x << 3)

C. (x << 6) - (x << 2)

D. (x << 4) - (x << 7)

#### 2.78

```C
int divide_power2(int x,int k){
    int sig = x&INT_MIN;
    (sig&&(x=x+(1<<k)-1));
    return x>>k;
}
```

#### 2.79

思考：是否可以先除后乘呢？

3*x/4 = 3\*(4k+i)/4 = 12k+3i/4 = 3k + 3i/4 = 3(k + i/4)

```C
int divide_power2(int x,int k){
    int sig = x&INT_MIN;
    (sig&&(x=x+(1<<k)-1));
    return x>>k;
}

int mul3div4(int x) {
    return divide_power2(x, 2) * 3;
}
```

#### 2.80

略，写不动了

#### 2.81

A.

```C
(-1) << k;
```

B.

```C
((unsigned) -1 >> (k+j)) << j;
```

#### 2.82

A.

x=INT_MIN时，-x仍等于INT_MIN

B.

是

C.

是

注意到取反和取负之间的关系

-x = ~x + 1 （对于INT_MIN不成立）

~(x+y) = -(x+y)-1 = -x - 1 -y -1 + 1 = ~x + ~y + 1

或者直接计算

~x = (1-$x_{w-1}$)(-$2^{w-1}$)+(1-$x_{w-2}$)$2^{w-2}$+...+(1-$x_0$)

=(-$2^{w-1}$+$2^{w-2}$+...+1)-x = -1 - x

D.

是

E.

是

#### 2.83

A.

0.yyyy...<<k = y.yyyy... =  Y + 0.yyyy

0.yyyy = Y / (2^k -1)

B.

(a) 5/7

(b) 6/15 = 2/5

(c) 19/63

#### 2.84
根据浮点数特性，相同符号的数直接可以通过直接比较位模式来比较大小，则
* 若sx=1，sy=0，则返回1
* 若sx=0，sy=1，则返回0
* 否则直接比较位模式，并根据符号位决定是否取反
  * sx=sy=0, ux<=uy
  * sx=sy=1, ux>=uy
```C
(sx==1&&sy==0)||(sx==sy&&((sx==0&&ux<=uy>)||(sx==0&&ux>=uy)))
```
#### 2.85
A. 

7 = $111_2$ = 1.11 * 2^2

M = 1.11 f=0.11 E = 2 exp = 2 - ($2^{k-1}$-1) = 3 - $2^{k-1}$

位模式 0 100..11 11000...0

B. 

见练习题2.49

C.

最小的规格化数为，exp=000...1，frac=0000...000，E=$2-2^{k-1}$，M=1，V=$2^E$

则其倒数的V=$2^{-E}$，E=$2^{k-1}-2$，M=1

#### 2.86

最小的正非规格化数，阶码为000..0，E=1-($2^{14}$-1)=2-$2^{14}$，M=0.0000...1=$2^{-63}$，则V=$2^{2-2^{14}}$*$2^{-63}$=$2^{-61-2^{14}}$

最小的正规格化数，阶码为000...1，E=1-($2^{14}$-1)=2-$2^{14}$，M=1.000...0=1，则V=$2^{2-2^{14}}$

最大的规格化数，阶码为111...0，E=$2^{15}$-2-($2^{14}$-1)=$2^{14}$-1，M=1.111...1 = 2 - $2^{-63}$，则V=(2 - $2^{-63}$) * ($2^{2^{14}-1}$) = $2^{2^{14}}$ - $2^{2^{14}-64}$

#### 2.87

| 描述                   | Hex   | M  | E | V  | D    |
|------------------------|-------|----|---|----|------|
| -0                     | 8000  | 0  | 0 | -0 | -0.0 |
| 最小的>2的值           | B2  0 | C2 |   |    |      |
| 512                    | B3    | C3 |   |    |      |
| 最大的非规格化数       |       |    |   |    |      |
| -∞                    |       |    |   |    |      |
| 十六进制表示为3BB0的数 | **3BB0**     |    |   |    |      |

## 第三章 程序的机器级表示
### 3.4 访问信息
#### 练习题3.1

| 操作数         | 值    |
|----------------|-------|
| %rax           | 0x100 |
| 0x104          | 0xAB  |
| $0x108         | 0x108 |
| (%rax)         | 0xFF  |
| 4(%rax)        | 0xAB  |
| 9(%rax,%rdx)   | 0x11  |
| 260(%rcx,%rdx) | 0x13  |
| 0xFC(,%rcx,4)  | 0xFF  |
| (%rax,%rdx,4)  | 0x11  |
  
#### 练习题3.2

| 指令 | 操作数               |
|------|----------------------|
| movl | %eax, (%rsp)         |
| movw | (%rax), %dx          |
| movb | $0xFF, %bl           |
| movb | (%rsp, %rdx, 4), %dl |
| movq | (%rdx), %rax         |
| movw | %dx, (%rax)          |

#### 练习题3.3

| 指令                 | 错误原因                               |
|----------------------|----------------------------------------|
| movb $0xF, (%ebx)    | 必须使用64位寄存器指定内存地址         |
| movl %rax, (%rsp)    | 指令指明的操作数长度与寄存器长度不匹配 |
| movw (%rax), 4(%rsp) | 不能从内存传送到内存                   |
| movb %al, %sl        | 没有sl寄存器                           |
| movq %rax, $0x123    | 不能以立即数作为目标地址               |
| movl %eax, %rdx      | 指令指明的操作数长度与寄存器长度不匹配 | 
| movb %si, (%rbp)     | 指令指明的操作数长度与寄存器长度不匹配 |

#### 练习题3.4

| src_t | dest_t | 指令                                   |
|-------|--------|----------------------------------------|
| long  | long   | movq (%rdi), %rax<br>movq %rax, (%rsi) |
| char | int | movsbl (%rdi), %eax<br>movl %eax, (%rsi)<br>(注：char大多数情况下默认有符号，但是也看具体编译器实现，C标准无规定) |
| char  | unsigned   | movsbl (%rdi), %eax<br>movl %eax, (%rsi) |
| unsigned char  | long | movzbq (%rdi), %rax<br>movq %rax, (%rsi) |
| int  | char  | movl (%rdi), %eax<br>movb %al, (%rsi) |
| unsigned  | unsigned char   | movl (%rdi), %eax<br>movb %al, (%rsi) |
| char  | short   | movsbw (%rdi), %ax<br>movw %ax, (%rsi) |

#### 练习题3.5

| decode1           |                 |
|-------------------|-----------------|
| movq (%rdi), %r8  | temp1 = xp      |
| movq (%rsi), %rcx | temp2 = yp      |
| movq (%rdx), %rax | ret = zp        |
| movq %r8, (%rsi)  | yp = temp1(=xp) |
| movq %rcx, (%rdx) | zp = temp2(=yp) |
| movq %rax, (%rdi) | xp = ret(=zp)   |
| ret               |                 |

```C
void decode1(long *xp, long *yp, long *zp) {
    long t1 = *xp;
    long t2 = *yp;
    long t3 = *zp;
    *yp = t1;
    *zp = t2;
    *xp = t3;
    return;
}
```

### 3.5 算术和逻辑操作

#### 练习题3.6
| 表达式                      | 结果   |
|-----------------------------|--------|
| leaq 6(%rax), %rdx          | x+6    |
| leaq (%rax, %rcx), %rdx     | x+y    |
| leaq (%rax, %rcx, 4), %rdx  | x+4*y  |
| leaq 7(%rax, %rax, 8), %rdx | 9*x+7  |
| leaq 0xA(,%rcx, 4), %rdx    | 4*y+10 |
| leaq 9(%rax, %rcx, 2), %rdx | x+2*y+9|

#### 练习题3.7

| scale2                     |                     |
|----------------------------|---------------------|
| leaq (%rdi, %rdi, 4), %rax | temp1 = 5*x         |
| leaq (%rax, %rsi, 2), %rax | temp1 = temp1 + 2*y |
| leaq (%rax, %rdx, 8), %rax | temp1 = temp1 + 8*z |
| ret                        | return temp1        |

```C
long t = 5*x + 2*y + 8*z;
```
#### 练习题3.8

| 指令                       | 目的  | 值    |
|----------------------------|-------|-------|
| addq %rcx, (%rax)          | 0x100 | 0x100 |
| subq %rdx, 8(%rax)         | 0x108 | 0xA8  |
| imulq $16, (%rax, %rdx, 8) | 0x118 | 0x110 |
| incq 16(%rax)              | 0x110 | 0x14  |
| decq %rcx                  | %rcx  | 0x0   |
| subq %rdx, %rax            | %rax  | 0xFD  |

#### 练习题3.9

salq $4, %rax
sarq %cl, %rax

#### 练习题3.10

| arith2:         |                 |
|-----------------|-----------------|
| orq %rsi, %rdi  | x = x^y         |
| sarq $3, %rdi   | x = x >> 3      |
| notq %rdi       | x = ~x          |
| movq %rdx, %rax | temp = z        |
| subq %rdi, %rax | temp = temp - x |
| ret             |                 |

```C
long arith2(long x, long y, long z) {
    long t1 = x^y;
    long t2 = t1 >> 3;
    long t3 = ~t2;
    long t4 = z-t3;
    return t4;
}
```

#### 练习题3.11

A. 
把rdx寄存器置零

B.
movq $0, %rdx

C. 

#### 练习题3.12

| uremdiv |              | 
|---------|--------------|
| movq    | %rdx, %r8    |
| movq    | %rdi, %rax   |
| movl    | $0, %edx     |
| divq    | %rsi         |
| movq    | %rax, (%r8)  |
| movq    | %rdx, (%rcx) |

### 3.6 控制
#### 练习题3.13

A. 32位有符号数 int
B. 16位有符号数 short
C. 8位无符号数 unsigned char
D. 64位数 long unsigned long (订正：或者指针)

#### 练习题3.14

A. 64位有符号数 long
B. 16位 short unsigned short
C. 8位无符号数 unsigned char
D. 32位有符号数 int 

#### 练习题3.15

A. 0x4003fc+0x02=0x4003fe

B. 0x400431+(-12) = 0x400425

C. addr(pop)+0x02=0x400547

addr(pop) = 0x400545

addr(ja) = addr(pop)-2 = 0x400543

D. 0x4005ed+(0xffffff73=-0x8d=-141)=0x400560

#### 练习题3.16
A.
```C
void goto_cond(long a, long b) {
    if (p == 0)
        goto p_nz;
    if (p >= a)
        goto p_nz;
    *p = a;
 p_nz:
    return;
}
```

B. 因为条件语句中包含两个条件，且包含短路求值

#### 练习题3.17

A.
```C
long gotodiff_se(long x, long y) {
    long result;
    if (x < y)
        goto x_lt_y;
    lt_cnt++;
    result = y - x;
    return 
    result;
 x_lt_y:
    ge_cnt++;
    result = x - y;
    return result;
}
```

B. 对没有else的语句友好

#### 练习题3.18

| test:    |                    |                       |
|----------|--------------------|-----------------------|
| leaq     | (%rdi, %rsi), %rax | temp1 = x+y           |
| addq     | %rdx, %rax         | temp1 = temp1+z       |
| cmpq     | $-3, %rdi          | comp x and -3         |
| jge      | .L2                | if (x >= -3) goto .L2 |
| cmpq     | %rdx, %rsi         | comp y and z          |
| jge      | .L3                | if (y >= z) goto .L3  |
| movq     | %rdi, %rax         | temp1 = x             |
| imulq    | %rsi, %rax         | temp1 = temp1*y       |
| ret      |                    | return                |
| **.L3:** |                    |                       |
| movq     | %rsi, %rax         | temp1 = y             |
| imulq    | %rdx, %rax         | temp1 = z * temp1     |
| ret      |                    | return                |
| **.L2:** |                    |                       |
| cmpq     | $2, %rdi           | comp x and 2          |
| jle      | .L4                | if (x <= 2) goto .L4  |
| movq     | %rdi, %rax         | temp1 = x             |
| imulq    | %rdx, %rax         | temp1 = temp1*z       |
| **.L4:** |                    |                       |
| rep; ret |                    | return                |

```C
long test(long x, long y, long z) {
    long val = x + y + z;
    if (x < -3) {+
    
        if (y < z)
            val = x * y;
        else
            val = y * z;
    } else if (x > 2)
        val = x * z;
    return val;
}
```

#### 练习题3.19

A. 30

B. 46

#### 练习题3.20
A. /

B.
| arith: |               |                       |
|--------|---------------|-----------------------|
| leaq   | 7(%rdi), %rax | temp1 = x + 7         |
| testq  | %rdi, %rdi    | test x & x            |
| cmovns | %rdi, %rax    | if (x >= 0) temp1 = x |
| sarq   | $3, %rax      | temp1 = temp1 >> 3    |
| ret    |               | return                |

#### 练习题3.21

| test:  |                    |                           |
|--------|--------------------|---------------------------|
| leaq   | 0(, %rdi, 8), %rax | temp1 = 8*x               |
| testq  | %rsi, %rsi         | test y & y                |
| jle    | .L2                | if (y <= 0) goto .L2      |
| movq   | %rsi, %rax         | temp1 = y                 |
| subq   | %rdi, %rax         | temp1 = temp1 - x         | 
| movq   | %rdi, %rdx         | temp2 = x                 |
| andq   | %rsi, %rdx         | temp2 = temp2 & y         |
| cmpq   | %rsi, %rdi         | comp x, y                 |
| cmovge | %rdx, %rax         | if (x >= y) temp1 = temp2 |
| ret    |                    | return                    |
| .L2:   |                    |                           |
| addq   | %rsi, %rdi         | x = x + y                 |
| cmpq   | $-2, %rsi          | comp y and -2             |
| cmovle | %rdi, %rax         | if (y <= -2) temp1 = x    | 
| ret    |                    | return                    |

```C
long test(long x, long y) {
    long val = 8 * x;
    if (y > 0) {
        if (x < y) 
            val = y - x;
        else
            val = x & y;
    } else if (y <= -2)
        val = x + y;
    return val;
}
```

#### 练习题3.22

略

#### 练习题3.23

| dw_loop: |                     |                       |
|----------|---------------------|-----------------------|
| movq     | %rdi, %rax          | temp1 = x             | 
| movq     | %rdi, %rcx          | y = x                 |
| imulq    | %rdi, %rcx          | y *= x                |
| leaq     | (%rdi, %rdi), %rdx  | n = 2 * x             |
| .L2:     |                     |                       |
| leaq     | 1(%rcx, %rax), %rax | temp1 = temp1 + y + 1 |
| subq     | $1, %rdx            | n -= 1                |
| testq    | %rdx, %rdx          | test n & n            |
| jg       | .L2                 | if (n > 0) goto .L2   |
| rep; ret |                     | return                |

A. x->%rax , y->%rcx, n->%rdx

B. 没有对p的直接操作，所以对p的内容操作都可以变为对x的操作；(*p)++变为x+1并与上一步运算合并。

C. 见上。

#### 练习题3.24

| loop_while: |                    |                     |
|-------------|--------------------|---------------------|
| movl        | $1, %eax           | temp1 = 1           |
| jmp         | .L2                | goto .L2            |
| .L3:        |                    |                     |
| leaq        | (%rdi, %rsi), %rdx | temp2 = a + b       |
| imulq       | %rdx, %rax         | temp1 *= temp2      |
| addq        | $1, %rdi           | a--                 |
| .L2:        |                    |                     |
| cmpq        | %rsi, %rdi         | comp a and b        |
| jl          | .L3                | if (a < b) goto .L3 |
| rep;ret     |                    | return              |

```C
long loop_while(long a, long b) {
    long result = 1;
    while (a < b) {
        result = result * (a + b);
        a = a + 1;
    }
    return result;
}
```

#### 练习题3.25

| loop_while2: |            |                      |
|--------------|------------|----------------------|
| testq        | %rsi, %rsi | test b               |
| jle          | .L8        | if (b <= 0) goto .L8 |
| movq         | %rsi, %rax | temp1 = b            |
| .L7:         |            |                      |
| imulq        | %rdi, %rax | temp1 *= a           |
| subq         | %rdi, %rsi | b -= a               |
| testq        | %rsi, %rsi | test b               |
| jg           | .L7        | if (b > 0) goto .L7  |
| rep;ret      |            | return               |
| .L8:         |            |                      |
| movq         | %rsi, %rax | temp1 = b            |
| ret          |            | return               |

```C
long loop_while2(long a, long b) {
    long result = b;
    while (b > 0) {
        result = a * result;
        b = b - a;
    }
    return result;  
}
```

#### 练习题3.26

| fun_a: |            |                      |
|--------|------------|----------------------|
| movl   | $0, %rax   | temp1 = 0            |
| jmp    | .L5        | goto .L5             |
| .L6    |            |                      |
| xorq   | %rdi, %rax | temp1 ^= x           |
| shrq   | %rdi       | x >>= 1              |
| .L5:   |            |                      |
| testq  | %rdi, %rdi | test x               |
| jne    | .L6        | if (x != 0) goto .L6 |
| andl   | $1, %eax   | temp1 &= 1           |
| ret    |            | return               |

A. jump-to-middle

B. 
```C
long fun_a(unsigned long x) {
    long val = 0;
    while (x != 0) {
        val = val ^ x;
        x = x >> 1;
    }
    return val & 1;
}
```

C.
确定x位表示中1的个数是奇数还是偶数。

#### 练习题3.27

```C
long fact_for_gd_toto(long n) {
    long i = 2;
    long result = 1;
    if (i > n)
        goto done;
 loop:
    result *= i;
    i++;
    if (i != n)
        goto loop;
 done:
    return result;
}
```

#### 练习题3.28

| fun_b:  |            |                           |
|---------|------------|---------------------------|
| movl    | $64, %edx  | temp1 = 64                |
| movl    | $0, $eax   | temp2 = 0                 |
| .L10:   |            |                           |
| movq    | %rdi, %rcx | temp3 = x                 |
| andl    | $1, $ecx   | temp3 &= 1                |
| addq    | %rax, %rax | temp2 *= 2                |
| orq     | %rcx, %rax | temp2 \|= temp3           |
| shrq    | %rdi       | x >>= 1                   |
| subq    | $1, %rdx   | temp1 -= 1                |
| jne     | .L10       | if (temp1 != 0) goto .L10 |
| rep;ret |            | return                    |

A.
```C
long fun_b(unsigned long x) {
    long val = 0;
    long i;
    for (i=64; i!=0; --i) {
        val = (val*2) | (x&1);
        x = x >> 1;
    }
    return val;
}
```

B. 显然条件必定满足

C. 倒转x的位表示

#### 练习题3.29

```C
long sum = 0;
long i = 0;
while (i < 10) {
    if (i&1)
        continue;
    sum += i;
    i++;
}
```

导致update-expr没有执行

B. goto语句指向update-expr之前

#### 练习题3.30

A. -1, (0,7), 1, (2, 4), 5
B. 见上

#### 练习题3.31

| switcher: |                    |                     |
|-----------|--------------------|---------------------|
| cmpq      | $7, %rdi           | comp a and 7        |
| ja        | .L2                | if (a > 7) goto .L2 |
| jmp       | *.L4(,%rdi, 8)     | goto *jt[index]     |
| .section  | .rodata            | declare jump table  |
| .L7:      |                    | case 5              |
| xorq      | $15, %rsi          | b ^= 15             |
| movq      | %rsi, %rdx         | c = b               |
| .L3:      |                    | case 0              |
| leaq      | 112(%rdx), %rdi    | a = 112 + c         |
| jmp       | .L6                | goto .L6            |
| .L5:      |                    | case 2              |
| leaq      | (%rdx, %rsi), %rdi | a = b + c           |
| salq      | $2, %rdi           | a <<= 2             |
| jmp       | .L6                | goto .L6            |
| .L2       |                    | default             |
| movq      | %rsi, %rdi         | a = b               |
| .L6       |                    | done                |
| movq      | %rdi, (%rcx)       | *dest = b           |
| ret       |                    | return              |

```C
void switcher(long a, long b, long c, long *dest) {
    long val;
    switch(a) {
        case 5:
            c = b ^ 15;
        case 0:
            val = c + 112;
            break;
        case 2:
        case 7:
            val = (b + c) << 2;
            break;
        case 4:
            val = a;
            break;
        default:
            val = b;
    }
    *dest = val;
}
```

### 3.7 过程

#### 练习题3.32

|      | 指令     |           |      |      |      | 状态值（指令执行前） |          |                  |
|------|----------|-----------|------|------|------|----------------------|----------|------------------|
| 标号 | PC       | 指令      | %rdi | %rsi | %rax | %rsp                 | *%rsp    | 描述             |
| M1   | 0x400560 | callq     | 10   | --   | --   | 0x7fffffffe820       | --       | 调用first(10)    |
| F1   | 0x400548 | lea       | 10   | --   | --   | 0x7fffffffe818       | 0x400565 | x + 1            |
| F2   | 0x40054c | sub       | 10   | 11   | --   | 0x7fffffffe818       | 0x400565 | x - 1            |
| F3   | 0x400550 | callq     | 9    | 11   | --   | 0x7fffffff818        | 0x400565 | call last(9, 11) |
| L1   | 0x400540 | mov       | 9    | 11   | --   | 0x7fffffff810        | 0x400555 | u                |
| L2   | 0x400543 | imul      | 9    | 11   | 9    | 0x7fffffff810        | 0x400555 | u*v              |
| L3   | 0x400547 | retq      | 9    | 11   | 99   | 0x7fffffff810        | 0x400555 | return           |
| F4   | 0x400555 | repz retq | 9    | 11   | 99   | 0x7fffffff818        | 0x400565 | return           |
| M2   | 0x400565 | mov       | 9    | 11   | 99   | 0x7fffffff820        | --       | resume           |

#### 练习题3.33

int a, short b, long *u, char *v

#### 练习题3.34

A. a0-a6

B. a7 a8
 
C. 寄存器不够

#### 练习题3.35

| rfun: |            |                          |
|-------|------------|--------------------------|
| pushq | %rbx       | save %rbx                |
| movq  | %rdi, %rbx | %rdi -> %rbx             |
| movl  | $0, %eax   | %rax = 0                 |
| testq | %rdi, %rdi | test %rdi                |
| je    | .L2        | if (%rdi == 0) goto .L2  |
| shrq  | $2, %rdi   | %rdi >>(L) 2             |
| call  | rfun       | call rfun recursively    |
| addq  | %rbx, %rax | %rax += %rbx             |
| .L2:  |            |                          |
| popq  | %rbx       | get previouly saved %rbx |
| ret   |            | return                   |

```C
long rfun(unsigned long x) {
    if (x == 0)
        return 0;
    unsigned long nx = x >> 2;
    long rv = rfun(nx);
    return x + rv;
}
```

### 3.8 数组分配和访问

#### 练习题3.36

| 数组 | 元素大小 | 整个数组的大小 | 起始地址 | 元素i      |
|------|----------|----------------|----------|------------|
| S    | 2        | 14             | $x_S$    | $x_S$ + 2i |
| T    | 8        | 24             | $x_T$    | $x_T$ + 8i |
| U    | 8        | 48             | $x_U$    | $x_U$ + 8i |
| V    | 4        | 32             | $x_V$    | $x_V$ + 4i |
| W    | 8        | 32             | $x_W$    | $x_W$ + 8i |

#### 练习题3.37

| 表达式   | 类型   | 值             | 汇编代码                      |
|----------|--------|----------------|-------------------------------|
| S + 1    | short* | $x_S$+2        | leaq 2(%rdx), %rax            |
| S[3]     | short  | M[$x_S$+6]     | movw 6(%rdx), %ax             |
| &S[i]    | short* | $x_S$+2i       | leaq (%rdx, %rcx, 2), %rax    |
| S[4*i+1] | short  | M[$x_S$+8*i+2] | movw 2(%rdx, %rcx, 8), %ax    |
| S+i-5    | short* | $x_S$+2i-10    | leaq -10(%rdx, %rcx, 2), %rax |

#### 练习题3.38

| sum_element |                     |                     |
|-------------|---------------------|---------------------|
| leaq        | 0(,%rdi,8), %rdx    | %rdx = 8*i       |
| subq        | %rdi, %rdx          | %rdx -= i        |
| addq        | %rsi, %rdx          | %rdx += j        |
| leaq        | (%rsi,%rsi,4), %rax | %rax = 5*j       |
| addq        | %rax, %rdi          | %rdi += %rax        |
| movq        | Q(,%rdi,8), %rax    | %rax = M[Q+8*%rdi]  |
| addq        | P(,%rdx,8), %rax    | %rax += M[P+8*%rdx] |
| ret         |                     | return              |

从倒数二三行可知，%rdi = i * N + j, 而%rdx = j * M + i

结合之前的操作可以得出， %rdx = i + 5 * j, %rdi = 7 * i + j

M = 5, N = 7

#### 练习题3.39
略

#### 练习题3.40

| fix_set_diag |                   |                             |
|--------------|-------------------|-----------------------------|
| movl         | $0, %eax          | temp1 = 0                   |
| .L3          |                   |                             |
| movl         | %esi, (%rdi,%rax) | M[A+temp1] = val            |
| addq         | $68， %rax        | temp1 += 68                 |
| cmpq         | $1088, %rax       | comp temp1 and 1088         |
| jne          | .L3               | if (temp1 != 1088) goto .L3 |
| rep;ret      |                   | return                      |

```C
void fix_set_diag_opt(fix_matrix A, int val) {
    long len = 0;
    int *Ptr = A;
    do {
        *(Ptr+len) = val;
        len += N + 1;
    } while (len != N * (N+1));
    return;
}
```

### 3.9 异质的数据结构

#### 练习题3.41

A.

p: 0

s.x: 8

s.y: 12

next: 16

B. 24

C.  

```C
void sp_init(struct prob *sp) {
    sp->s.x = sp->s.y;
    sp->p = &(sp->s.x);
    sp->next = sp;
}
```

#### 练习题3.42

A.
| fun:     |               |                        |
|----------|---------------|------------------------|
| movl     | $0, %eax      | temp1 = 0              |
| jmp      | .L2           | goto .L2               |
| .L3:     |               |                        |
| addq     | (%rdi), %rax  | temp1 += ptr->v        |
| movq     | 8(%rdi), %rdi | ptr = ptr->p           |
| .L2:     |               |                        |
| testq    | %rdi, %rdi    | test ptr               |
| jne      | .L3           | if (ptr != 0) goto .L3 |
| rep; ret |               |                        |

```C
long fun(struct ELE *ptr) {
    long val = 0;
    while (ptr != 0) {
        val += ptr->v;
        ptr = ptr->p;
    }
    return val;
}
```

B.

实现了一个链表，fun对链表的值求和

#### 练习题3.43

| expr               | type  | 代码                                                                     |
|--------------------|-------|--------------------------------------------------------------------------|
| up->t1.u           | long  | movq (%rdi), %rax <br>movq %rax, (%rsi)                                  |
| up->t1.v           | short | movw 8(%rdi), %ax <br> movw %ax, (%rsi)                                  |
| &up->t1.w          | char* | leaq 10(%rdi), %rax <br> movq %rax, (%rsi)                               |
| up->t2.a           | int*  | movq %rdi, (%rsi)                                                        |
| up->t2.a[up->t1.u] | int   | movq (%rdi), %rax <br> movl (%rdi, %rsi, 4), %eax <br> movl %eax, (%rsi) |
| *up->t2.p          | char  | movq 8(%rdi), %rax <br> movb (%rax), %al <br> movb %al, (%rsi)           |

#### 练习题3.44

A. i:0, c:4, j:8, d:12 16 4

B. i:0, c:4, d:5, j:8 16 8

C. w:0, c:6 10 2

D. w:0, c:16 40 8

E. a:0, t:24 40 8

#### 练习题3.45

A.

| 字段     | 大小/对齐要求 | 偏移量-结束 |
|----------|---------------|-------------|
| char *a  | 8             | 0-7         |
| short b  | 2             | 8-9         | 
| double c | 8             | 16-23       |              
| char d   | 1             | 24-24       |         
| float e  | 4             | 28-31       |
| char f   | 1             | 32-32       |
| long g   | 8             | 40-47       |
| int h    | 4             | 48-51       |

B. 52字节（对齐要求为8，故实际占用为56字节）

C.

| 字段     | 大小/对齐要求 | 偏移量-结束 |
|----------|---------------|-------------|
| char *a  | 8             | 0-7         |
| double c | 8             | 8-15       |              
| long g   | 8             | 16-23       |
| float e  | 4             | 24-27       |
| int h    | 4             | 28-31       |
| short b  | 2             | 32-33       | 
| char d   | 1             | 34-34       |         
| char f   | 1             | 35-35       |

总大小为36字节，实际占用40字节

### 3.10 在机器级程序中将控制与数据结合起来

#### 练习题3.46
略

#### 练习题3.47

A. 0x2000 = 8192 字节

B. 8192 / 128 = 64

#### 练习题3.48

A. 

无保护的代码中：v在偏移量24位置，buf在偏移量0位置

有保护的代码中：v在偏移量24位置，buf在偏移量16位置，canary在偏移量40位置

#### 练习题3.49

A. 

temp1 = 8*n + 22

temp1 = temp1 & 0xFFF...F0 （最后四位置零）

s2 = s1 - temp1

B.

temp1 = s2 + 7

temp1 = temp1 >>(L) 3

以上两条等于整除8并向零取整

temp2 = 8 * temp1

以上三条等价于把temp1向下取为8的倍数

p= temp2