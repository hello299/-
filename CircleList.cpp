#include"Circlelist.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct _tag_CircleList
{
	CircleListNode* header;/*头部结点*/
	CircleListNode* slider;
	int length;
}TCircleList;
#pragma region 创建循环链表
CircleList* CircleList_Creat()
{
	TCircleList* list = nullptr;
	list = (TCircleList*)malloc(sizeof(TCircleList));
	/*判断是否创建成功*/
	if (list == NULL)
	{
		printf("创建失败");
		return NULL;
	}
	/*创建成功*/
	list->length = 0;
	list->header->next = nullptr;
	list->slider = nullptr;
}
#pragma endregion
#pragma region 销毁循环链表
void CircleList_Destory(CircleList* circlelist)
{
	if (circlelist == nullptr)
	{
		printf("空指针不用销毁");
		return;
	}
	/*非空指针销毁free*/
	free(circlelist);
}
#pragma endregion
#pragma region 清空循环链表
void CircleList_Clear(CircleList* circlelist)
{
	/*判断指针是否为空指针*/
	if (circlelist == nullptr)
	{
		printf("指针已清空");
		return;
	}
	/*指针非空*/
	TCircleList* tmp = (TCircleList*)circlelist;
	tmp->header->next = nullptr;
	tmp->length = 0;
	tmp->slider = NULL;
	delete tmp;
}
#pragma endregion
#pragma region 获取循环链表的长度
int CircleList_Length(CircleList* circlelist)
{
	if (circlelist == nullptr)
	{
		return -1;
	}
	TCircleList* tmp = (TCircleList*)circlelist;
	return tmp->length;
}
#pragma endregion
#pragma region 获取pos位置的结点
CircleListNode* CircleList_Get(CircleList* circlelist, int pos)
{
	if (circlelist == nullptr || pos<0)
	{
		printf("无法获取pos输入位置的结点");
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)circlelist;
	/*让辅助指针变量指向头部结点*/
	CircleListNode* current = (CircleListNode*)tlist;
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	CircleListNode* tmpNode = NULL;
	tmpNode = current->next;
	return tmpNode;
}
#pragma endregion
#pragma region 向循环链表的pos位置插入node结点
int CircleList_Get(CircleList* circlelist, CircleListNode* insert_node,int pos)
{
	/*判断插入是否有效*/
	if (circlelist == NULL || insert_node == nullptr||pos<0)
	{
		printf("插入无效");
		return -1;
	}
	/*插入有效*/
	TCircleList *tlist = nullptr;
	tlist = (TCircleList *)circlelist;
	CircleListNode* current = (CircleListNode*)tlist;
	for (int i = 0;(i<pos)&&(current->next!= NULL); i++)
	{
		current = current->next;
	}
	/*从无到有的尾插法 以及头插法都不满足要求*/
	insert_node->next = current->next;
	current->next = insert_node;/*走到这步适用于链表非空，同时插入的普通位置*/
	if (tlist->length == 0)
	{
		tlist->slider = insert_node;
	}
	if (current == (CircleListNode*)tlist)/*表示没有执行for循环 可能存在两种可能*/
		/*从无到有的尾插法以及头插法*/
	{
		CircleListNode* lastNode = CircleList_Get(tlist, tlist->length - 1);/*获取尾部元素*/
		/*针对于头插法，需要将尾部的元素指向insertnode插入的结点
		二对于从无到有的结点来说 需要将插入的第一个结点的next指针 指向本身*/
		lastNode->next = current->next;
	}
	tlist->length++;
	return pos;
}
#pragma endregion
#pragma region 将游标充值指向链表的第一个元素
CircleListNode* CircleList_Reset(CircleList* circlelist)
{
	if (circlelist == NULL)
	{
		printf("链表为空");
		return NULL;
	}
	TCircleList* tmp = (TCircleList*)circlelist;
	CircleListNode* tmpnode = NULL;
	tmpnode = tmp->slider = tmp->header->next;
	return tmpnode;
}
#pragma endregion
#pragma region 删除pos位置的结点
CircleListNode* CircleList_Delete(CircleList* circlelist, int pos)
{
	if (circlelist == nullptr && pos <=0)
	{
		printf("删除链表为空结点");
		return nullptr;
	}
	TCircleList* tlist = (TCircleList*)circlelist;
	CircleListNode* current = (CircleListNode*)tlist;
	/*满足删除条件*/
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	CircleListNode* tmpNode = nullptr;
	tmpNode = current->next;
	current->next = tmpNode->next;
	/*删除的是头部元素*/
	if (current == (CircleListNode*)tlist)
	{
		CircleListNode* tmpLast = CircleList_Get(circlelist, tlist->length - 1);
		tmpLast->next = current->next;/*删除的是第一个元素 那么链表的尾部元素指向新的首元素*/
	}
	/*如果删除的结点是第一个插入的结点  那么游标的位置需要改变 
	将删除结点的下一个结点赋值给slider
	*/
	if (tlist->slider == tmpNode)
	{
		tlist->slider = tmpNode->next;
	}
	tlist->length--;
	/*以上完成元素删除*/

	/*删除元素后 链表的长度为0 */
	if (tlist->length == 0)
	{
		printf("链表经过元素删除后 链表为空");
		tlist->header->next = nullptr;
		tlist->slider = nullptr;
		tlist->length = 0;
	}
	return tmpNode;



	return tmpNode;
}
#pragma endregion
#pragma region 直接指定删除链表中的某个数据元素
CircleListNode* CircleList_DeleteCeertainNode(CircleList* circlelist, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)circlelist;
	CircleListNode* tmpNode1 = nullptr;
	CircleListNode* tmp = (CircleListNode*)tlist;
	if (circlelist == nullptr|| node == NULL)
	{
		printf("删除失败");
		return NULL;
	}
	/*删除指定结点*/
	int count = 0;
	for (count; count < tlist->length; count++)
	{
		if (tmp->next == node)
		{
			tmpNode1 = tmp->next;
			break;
		}
	}
	if (tmpNode1 !=NULL)
	{
		CircleList_Delete(circlelist, count);
	}
	return tmpNode1;
	/*指向头部结点*/
	/*
	CircleListNode* tmpNode2 = nullptr;
	tmpNode2 = (CircleListNode*)circlelist;
	int count = 0;
	while ((tmp != node))
	{
		tmp = tmp->next;//循环第一次指向0号位置元素
		count++;
		if (count>tlist->length)
		{
			printf("链表中无指定元素");
			return NULL;
		}
	}
	for (int i = 0; i < count; i++)
	{
		tmpNode2 = tmpNode2->next;//tmpNode2->next与tmp结点等价
	}
	//tmp是要删除的元素
	tmpNode1 = tmp->next;
	tmpNode2->next = tmpNode1;
	return tmp;
	*/
}
#pragma endregion
#pragma region 获取当前游标指向的元素
CircleListNode* CircleList_Current(CircleList* circlelist)
{
	if (circlelist == nullptr)
	{
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)circlelist;
	CircleListNode* tmpNode = NULL;
	tmpNode = tlist->slider;
	return tmpNode;
}
#pragma endregion
#pragma region 将游标移动到链表中的下一个元素
CircleListNode* CircleList_Next(CircleList* circlelist)
{
	TCircleList* Tlist= (TCircleList*)circlelist;
	if (Tlist->header->next == nullptr)
	{
		return NULL;
	}
	CircleListNode* tmpNode = Tlist->slider->next;
}
#pragma endregion






