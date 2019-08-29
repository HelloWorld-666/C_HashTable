# C_HashTable
哈希表

散列表(hash表):是一种线性 顺序操作结构,是通过一个key(关键值)访问元素值.  
hash函数:是用来计算元素值所对应key值..是元素与key关系体现.不存在一个通用的公共的hash函数,必须根据当前的元素数值与需求,给出一个最合适hash函数
key=hash(value)  
如何选择一个最合适hash函数
&emsp；1.尽量将元素值均分散存储
&emsp；2.尽量不要产生冲突(不同的元素之计算的key相同)  
常用hash函数算法:
&emsp；1.直接取值法
&emsp；2.加减乘除法
&emsp；3.余数法
&emsp；4.位运算法(字符操作经典hash函数)
&emsp；5.平方取中法  
如何解决冲突:
&emsp；1.链表法(将冲突元素用链表管理)
&emsp；2.多次hash  
hash(表)函数作用:
&emsp；1.快速查找
&emsp；2.加密  
单向函数:只能通过元素值计算出key,但不能通过key值计算出元素值  