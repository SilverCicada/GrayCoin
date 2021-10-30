# 开发文档

请详细阅读 https://github.com/ACM-Programming-2021/ICPC-Management-System-2021   

## 操作-结果-条件   
 
~~~
    结果, 方括号中的可能情况  
    I   -> info
    E   -> error   
    W   -> warning  

    附加, 方括号之后的内容  
    su  -> successfully 
    fa  -> failed 
~~~

- AddTeam  
    - @Arg  
        - teamname: string
    
    - @Result 
        - info - su - 比赛未开始    
        - error - fa - 比赛开始 | 队伍重名     

- Start  
    - @Arg  
        - duration: int  
        - problem_count: int  
    
    - @Result  
        - info - su - 比赛未开始  
        - error - fa - 比赛已经开始过    

- Submit   
    - @Arg  
        - problem_name: string  
        - team_name: string     
        - sub_status: enum A | W | R | T   
        - time: size_t 

    - @Comment   
    除了A算作通过以外, 其他均不算, 且保证在所有sub操作中 time 的 出现次序单调递增   

- Flush  
    - @Result  
        - info - su  
    
- Freeze  
    - @Result  
        - info - su - 
        - error - fa - 已封榜但未滚榜   
    
- Scroll  
    - @Result  
        - info - su -   
        有一定输出内容      
        - error - fa - 未封榜   

- Query  
    - @Arg  
        - team_name: string 
        - problem_name: string  
        - status: enum A | W | R | T     
    - @Ret  
        - info - su -   
        有一定输出  
        - error - fa - 队伍不存在  

        - warnning - fa - 已经封榜 

        - some output(not error ) - - 没有满足的查询结果   

    - @Comment
      保证询问中的 problem_name 与 status 合法。


- End  
    - @Ret  
        - info - -    


## 类设计  

- OpKind : enum   
    输入文件中每一行的操作种类, 可能取值为: 
    - AddTeam  
    - Start  
    - Submit 
    - Flush 
    - Freeze 
    - Scroll 
    - Query 
    - End  

- SubStatus : enum   
    提交题解的状态  
    - A  
    accepted 
    
    - W   
    warning  
    
    - R   
    runtime error  

    - T 
    time out  

- Command<T> : class (tagged union)  
    一个封装好的命令, 包括命令种类的对应的参数, 对于某些没有参数的命令, arg_ 成员没有意义. 
    - @mem  
        - kind_ : OpKind    
        - arg_ : T , requires (T = tuple\<string> | tuple\<int, int> | tuple\<string, string, SubStatus, size_t> | tuple\<string, string, SubStatus> | tuple<nullopt>)


- ManSystem : class  
