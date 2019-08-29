#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 20
int node_count = 0;

typedef struct hash_node
{
	char ch[100];
	hash_node* next;				// ��������
}hash_node;

// ����hash��
hash_node* hash_table[N];			// ȫ�ֱ���"hash_table"��һ��hash������

void init_hash_table()
{
	memset(hash_table, 0, N);		// ��ʼ�����鳤��N
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
		if (strcmp(ptr_current->ch, value) == 0)			// ���� ptr_current->ch = value,����ָ���ַ�ıȽϣ�Ӧ����ֵ�Ƚϡ� s1 = s2;����0;
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
	// ����new_node
	hash_node* new_node = (hash_node*)malloc(1*sizeof(hash_node));
	strcpy(new_node->ch, value);							// ��ֵ
	new_node->next = NULL;

	int key = get_hash_key(value);
	hash_node* ptr_current = hash_table[key];
	// 
	if (hash_table[key] == NULL)							// ��hash_table�����е�Ԫ��Ϊ��  �ǳ�ͻ����
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
		if (strcmp(hash_table[key]->ch, value) == 0)		// ���� ptr_current->ch = value,����ָ���ַ�ıȽϣ�Ӧ����ֵ�Ƚϡ� s1 = s2;����0;
		{
			// ��һ���ڵ�ΪĿ��ڵ�
			hash_table[key] = ptr_current->next;
			printf("delete successful, find dest value: %s !\n", ptr_current->ch);
			free(ptr_current);
			ptr_current = NULL;
			
			return true;
		}
		else
		{
			// Ŀ��ڵ�λ�ڵ�һ���ڵ�֮��
			ptr_current = ptr_current->next;				// һ��ʼָ��hash_table[key]����һ���ڵ�
			if (strcmp(ptr_current->ch, value) == 0)		// strcmp�Ƚ���ȷ���ֵΪ0
			{
				ptr_temp->next = ptr_current->next;			// �� ptr_current = ptr_current->next ��ptr_tempΪptr_current�ò���֮ǰ�Ľڵ㣬��֮ǰ�Ľڵ�ָ��Ҫɾ���ڵ����һ���ڵ�
				printf("delete successful, find dest value: %s !\n", ptr_current->ch);
				free(ptr_current);
				ptr_current = NULL;
			}
			ptr_temp = ptr_current;							// ptr_temp����ptr_current����һ��ָ��Ľڵ�
		}
	}
}

void printf_hash_table()
{
	int i;
	for (i = 0; i < N; i++)									// ����Ҫ�ͺ궨���е�N��С��ȣ�Ϊ���ֳ���ֵ
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
	printf("��ʼhash_table��\n");
	printf_hash_table();

	//find_element_from_hash_table("340");
	delete_element_from_hash_table("six");
	printf("delete������hash_table��\n");
	printf_hash_table();

	//printf("====%s\n", hash_table[6]->ch);	// hash_table[key]����Ԫ����Ҳ�洢��һ��node�ڵ�

	getchar();

	return 0;
}


/*
	char array[10];
	memset(array, 0, 10);  // ��ʼ���ַ�����

	int array1[10];
	memset(array1, 0, 10); // ��ʼ����������
*/
