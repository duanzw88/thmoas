# 查找
  使用符号表构建一张抽象的表格，将信息存储在其中，然后按照指定的键来搜索并获取这些信息。
  键和值的具体意义取决于不同的应用。
## 符号表

符号表最主要的目的就是将一个键和一个值联系起来。  

能够将一个**键值对**对插入符号表并期望在之后能够从符号表中的所有键值对中按照**键**直接找到相对应的值。  
符号表是一种存储键值对的数据结构，支持两种基本操作:  
	- 插入(input) 将一组新的键值对存入表中  
	- 查找(get)  根据给定的键得到相应的值
	
### API  
符号表是一种典型的**抽象数据类型**，它代表着一组定义清晰的值以及相应的操作，能够将类型的实现和使用区分开来。  

#### 泛型  
在设计方法时没有指定处理对象的类型，而是使用了泛型。  

#### 重复的键  
- 每个键只对应一个值
- 向表中插入已经存在的键值对，新的值会代替旧的值  

#### 空键  
键不允许为空  

#### 空值  
不允许有空值   
#### 删除操作  
#### 便捷方法  
#### 迭代  
#### 键的等价性  

### 有序符号表
#### 最大键和最小键
#### 向下取整和向上取整
#### 排名和选择  
排名 rank 找出小于指定键的数量  
选择 select 找出排名为k的键
#### 范围和查找
#### 例外情况
#### 便捷方法
#### 键的等价性
#### 成本模型
### 无序链表中的顺序查找
#### 二分查找
### 对二分查找的分析

## 二叉查找树
能够将链表插入的灵活性和有序数组的高效性结合起来的符号表的实现。
## 红黑树
## 散列表
