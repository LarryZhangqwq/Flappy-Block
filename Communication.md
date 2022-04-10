### 0. 代码规范：

1. 所有数组从0开始，若num为数组a的长度，那么a中存储数据的起止为[ 0 , num - 1 ]. 第num位没有数据！！
2. 除临时变量外，所有的数组、变量名都要可以明确的知道这个变量是什么，不可以使用a, b..作为变量名。
3. main.cpp是主代码，其他文件都是function的文件。
   * 比如：
     * Ranklist_store_function.h 是表明这个function名字的文件
     * Ranklist_store_function.cpp 是将整个function写出来的文件
4. 注意函数名是自己定义的，不一定是这些文件名。函数名字以及需要的变量都写完之后写到下面的对应表格中。

### 1. 需要进行算法调研的事情：

1. 如何使用动态内存
2. 整个游戏的UI如何输出
3. 整个游戏的UI界面要多大



### 2. Discussion area

* 20220410 zyx：
  * 优先做一下算法调研中2.3的研究，这些文件夹只是暂时创建，并没有定死，可以随时根据需要加减
  * ``Ranklist_create_function``在这个function里面用动态数组
  * 冲！





### 文件名以及其函数名称对应表格

| 函数名称以及其需要的变量                        | 文件名称                   |
| :---------------------------------------------- | :------------------------- |
| void ranklist_store( int rank_list[], int num ) | Ranklist_store_function.h  |
|                                                 | Ranklist_create_function.h |
|                                                 | Path_create_function.h     |
|                                                 | Wall_create_function.h     |
|                                                 |                            |

