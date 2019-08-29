#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
int node_count = 0;

typedef struct hash_node
{
	char ch[100];
	hash_node* next;				// 单向链表
}hash_node;

// 定义hash表
hash_node* hash_table[N];			// 全局变量"hash_table"是一个hash表类型

void init_hash_table()
{
	memset(hash_table, 0, N);		// 初始化数组长度N
}

int get_hash_key(char* str)
{
	int i = 0;
	int sum = 0;
	for (i = 0; i < strlen(str); i++)
	{
		sum += str[i];
	}
	return sum % N;
}

hash_node* find_element_from_hash_table(char* value)
{
	int i = 0;
	int key = get_hash_key(value);
	hash_node* ptr_current = hash_table[key];

	while (ptr_current != NULL)
	{
		if (strcmp(ptr_current->ch, value) == 0)			// 不能 ptr_current->ch = value,这是指针地址的比较，应该用值比较。 s1 = s2;返回0;
		{

			printf("find dest value successful ! dest value is : %s\n", ptr_current->ch);
			return ptr_current;
		}
		ptr_current = ptr_current->next;
	}

	printf("not find dest value !\n");
	return NULL;
}

void push_element_to_hash_table(char* value)
{
	// 构建new_node
	hash_node* new_node = (hash_node*)malloc(1*sizeof(hash_node));
	strcpy(new_node->ch, value);							// 赋值
	new_node->next = NULL;

	int key = get_hash_key(value);
	hash_node* ptr_current = hash_table[key];
	// 
	if (hash_table[key] == NULL)							// 若hash_table数组中的元素为空  非冲突链表
	{
		hash_table[key] = new_node;
	}
	else
	{
		while (ptr_current->next != NULL)
		{
			ptr_current = ptr_current->next;
		}
		ptr_current->next = new_node;
	}
}

bool delete_element_from_hash_table(char* value)
{
	hash_node* find_node = find_element_from_hash_table(value);
	if (find_node == NULL)
	{
		printf("delete failed, not find dest value:%s !\n", find_node->ch);

		return false;
	}
	
	int key = get_hash_key(value);
	hash_node* ptr_current = hash_table[key];
	hash_node* ptr_temp = hash_table[key]; 

	while (ptr_current != NULL)
	{
		if (strcmp(hash_table[key]->ch, value) == 0)		// 不能 ptr_current->ch = value,这是指针地址的比较，应该用值比较。 s1 = s2;返回0;
		{
			// 第一个节点为目标节点
			hash_table[key] = ptr_current->next;
			printf("delete successful, find dest value: %s !\n", ptr_current->ch);
			free(ptr_current);
			ptr_current = NULL;
			
			return true;
		}
		else
		{
			// 目标节点位于第一个节点之后
			ptr_current = ptr_current->next;				// 一开始指向hash_table[key]的下一个节点
			if (strcmp(ptr_current->ch, value) == 0)		// strcmp比较相等返回值为0
			{
				ptr_temp->next = ptr_current->next;			// 当 ptr_current = ptr_current->next 后，ptr_temp为ptr_current该操作之前的节点，用之前的节点指向将要删除节点的下一个节点
				printf("delete successful, find dest value: %s !\n", ptr_current->ch);
				free(ptr_current);
				ptr_current = NULL;
			}
			ptr_temp = ptr_current;							// ptr_temp备份ptr_current的上一次指向的节点
		}
	}
}

void printf_hash_table()
{
	int i;
	for (i = 0; i < N; i++)									// 这里要和宏定义中的N大小相等，为数字长度值
	{
		hash_node* ptr_current = hash_table[i];
		printf("key = %d:\t", i);
		while (ptr_current != NULL)
		{
			printf("%s ->", ptr_current->ch);
			ptr_current = ptr_current->next;
		}
		printf("NULL\n");
	}
}

int main()
{
	init_hash_table();
	push_element_to_hash_table("peng");
	push_element_to_hash_table("meng");
	push_element_to_hash_table("yuan");
	push_element_to_hash_table("six");
	push_element_to_hash_table("six");
	push_element_to_hash_table("six");
	push_element_to_hash_table("megn");
	push_element_to_hash_table("mgne");
	push_element_to_hash_table("mgen");
	printf("初始hash_table：\n");
	printf_hash_table();

	//find_element_from_hash_table("340");
	delete_element_from_hash_table("six");
	printf("delete操作后hash_table：\n");
	printf_hash_table();

	//printf("====%s\n", hash_table[6]->ch);	// hash_table[key]数组元素中也存储了一个node节点

	getchar();

	return 0;
}


/*
	char array[10];
	memset(array, 0, 10);  // 初始化字符数组

	int array1[10];
	memset(array1, 0, 10); // 初始化整型数组
*/
