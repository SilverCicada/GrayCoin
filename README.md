# GrayFortune
 something not presentable


## c/cpp  

+ Cmd Simple Text Editor 
    + 55 /  / 
    + 作业：学习 string 类的使用

+ Cache Effect Experiment
    + 200 / 3h / 1d 
    + 研究 cache miss 与 乘法运算对于程序运行时间的影响， 并以此猜测 L1, L2, L3 cache 的大小

+ Calculate With Designed formula   
    + 30 / 1h / 1d   
    + 用指定公式计算 txt 文件中的数据    

+ Dynamic Clock With EGE  
    + 170 / 10h / 3d     (三号客服 尾款未结算, 首款未领取)
    + 使用 EGE 库完成一个动态时钟, 要求定时器 / 调时间等功能  
    + 类设计的还不错, 可惜后期因为客户需求不明确导致临时返工, 逻辑部分处理的不够优雅  

+ SJTU IPCP Backend Management System  
    + 300 / 26h / 2d / 0.33 
    + 上交 2021 acm？ 练习题, 模拟 OJ 后端, 实现滚榜/查分等  
        详见： https://github.com/ACM-Programming-2021/ICPC-Management-System-2021   
    + 类设计很满意, 自以为是合适的现代 CPP 标准库入门, 检验自己能力的好机会, 可惜是用工程方法解决算法问题, 算是走了歪路.  
        1. 优雅地实现了输入输出数据与处理逻辑的分离。  
            正则处理输入数据   
            使用二级散转表, 条件码与带有可空值的元组配合, 比较优雅的处理了输出数据(固定输出 + 条件输出).  
            ~~想念 Rust 中的宏~~ 
        2. 主循环模拟 "取指-执行"   
            依然使用散转表隔离了不同逻辑的处理, 维护性 / 可读性很强.  
        3. 借用数据库分表的思路解决多对多引用问题 (二分图问题？)  
            一个队伍可以提交多个题的题解, 每个题可以被多个队伍提交.
            为了避免数据冗余存储带来的不同步的问题, 让队伍与题均保存提交记录的引用计数指针, 函数查表.   
            回顾的时候发现这东西有点像寄存器式虚拟机(Lua)的 Function 结构中常 / 变量表与字节码中的操作数的关系  
            ~~想念 Rust 中的默认不可变~~     
        4. 标准库容器与 CPP20 的使用  
            tuple, 与之配套的结构化绑定, 语法糖很方便    
            optional, 我仿佛在用 CPP 写 Rust  
            enum class + variant, 模仿 Rust 的带值枚举(tagged union) (附: 这让我想到了脚本语言对于动态类型的解决方案)  
            format / functor / lambda, 有点现代语言的样子了   
    + 最后没有完全解决问题, 因为没弄懂文档中给出的一些定义导致写不出正确的逻辑, 自认为在一个周末写出这样的代码还算不错, 听客户说有 acm 选手 三百行解决问题, 我大为震撼~~我TM直接拜他为师~~.        

## java  
+ Simple-Inhereit-In-4-Class  
    120 / 1.5h / 1d 
    + 简单的四个类之间的继承

+ Simple-Factory-Pattern  
    170 / 4h / 4d   
    + 使用工厂模式与备忘录模式实现一个小 deemo  
    + ~~java正统在C#~~

## python 

+ WebServer and WebProxy    
    170 / 2.5h / 1d
    + 从 tcp 流中解析 http 请求头, 返回同目录下请求的文件并以 http 响应包返回。 Proxy 功能与前者相同, 但作为 http 代理服务器在本地缓存文件。 当本地 cache 不存在所请求的文件时请求 webserver 获取所请求的文件并缓存。 


## other  
+ 20r  java     统计字符串中每个字符出现的频率  
+ 100r cpp      命令行编辑器, 借用了某人的作业后平分, 还嫖了一份夜宵   
+ 0r   cpp      使用 STML 库完成 tcp客户端服务端通信, 服务端写入文件, 外包  
