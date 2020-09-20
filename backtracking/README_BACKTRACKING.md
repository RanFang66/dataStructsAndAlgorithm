## 回溯法

在程序设计中，有一类求一组可行解或者求最优解的问题，不是根据某种确定的计算法则，而是利用试探和回溯的方法进行求解，这种求解过程实质上是一个先序遍历一棵状态树的过程，只是这棵树不是遍历前预先建立的，而是隐含在遍历过程中。

###回溯法的一般框架

在回溯法执行时，应当：1. 保存当前步骤，如果是一个解就输出；2. 维护状态，使搜索路径（含子路径）尽量不重复，必要时需要对不可能为解的部分做剪枝处理。

```c
bool finished = FALSE;
backtrack(int a[], int k, data input)
{
    int c[MAXCANDIDATES];
    int ncandidates;
    int i;
    if (is_a_solution(a, k, input))
        process_solution(a, k, input);
    else {
        k++;
        construct_candidates(a, k, input, c, &ncandidates);
        for (i = 0; i < ncandidates; i++) {
            a[k] = c[i];
            make_move(a, k, input);
            backtrack(a, k, input);
            ummake_move(a, k, input);
            if (finished)
                return;
        }
    }
}
```

其中的变量和函数说明如下：

- a[]表示当前获得的部分解；
- k表示搜索的深度
- input表示用于信息传递的更多参数
- Is_a_solution(a, k, input)表示判断当前的部分解向量a[1...k]是否是一个满足条件的解。
- Construct_candidates(a, k, input, c, &ncandidates)表示根据当前的状态，构造出进一步解可能的选择，存入c[]，其长度存入ncandidates
- Process_solution(a, k, input)对于符合条件的解进行处理，或是输出，或是保存到一个解集中
- Make_move(a, k, input)和unmake_move(a, k, input)分别表示将采取的选择更新到原始数据结构中以及将这一更新取消。

### 求集合子集

#### 问题

求含n个元素的集合A的所有子集。

#### 思路

A的子集是一个集合，它要么是空集，要么含有A中的1至n个元素。但反过来想，对于A中的每一个元素来说，它只有两种状态，要么属于一个子集，要么不属于一个子集。求A的所有子集就可以看成是对A中所有元素依次进行”取“或者”舍“的操作，这样就可以用一棵二叉树来表示子集元素的变化状况，例如一个集合A={1,2,3}，依次对集合中的元素进行取舍操作就可以得到如下的二叉树：

![backtracking1](/Users/ran.fang/Documents/LeetCode/backtracking1.png)

如上的二叉树中，根结点表示初始状态，每一层表示一次对A中不同元素做取舍操作之后到达的不同状态，叶子结点表示终结状态，所有叶子结点就是A的所有子集。

#### 伪代码

假设集合用List数据结构

```c
void OutputSubset(int i, List A, List &B)
//A表示集合A
//B表示A的子集的其中一个元素
//i表示进入函数时，已经对A中的前i个元素进行了取舍操作，初始i=0
{
    if (i >= ListLength(A))
        Output(B);
    else {
        getElem(A, i, &x);
        k = ListLength(B);
        //对第i个元素选择“取”
        ListInsert(B, k+1, x);
        OutputSubset(i+1, A, B);
        //对第i个元素选择“舍”
        ListDelete(B, k+1, x);
        OutputSubset(i+1, A, B);
    }
}
```

