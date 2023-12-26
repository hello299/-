#pragma once
#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;
/*定义结点*/
//typedef struct _tag_CircleListNode CircleListNode;
//struct _tag_CircleListNode
//{
//	CircleListNode *next;
//};
typedef struct  _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;

/*创建循环链表*/
CircleList* CircleList_Creat();
/*销毁循环链表*/
void CircleList_Destory(CircleList* circlelist);
/*清空循环链表*/
void CircleList_Clear(CircleList* circlelist);
/*获取pos位置的结点*/
CircleListNode* CircleList_Get(CircleList* circlelist, int pos);
/*获取循环链表的长度*/
int CircleList_Length(CircleList* circlelist);
/*向循环链表的pos位置插入node结点*/
int CircleList_Get(CircleList* circlelist, CircleListNode* insert_node,int pos);
/*删除pos位置的结点*/
CircleListNode* CircleList_Delete(CircleList* circlelist, int pos);

/*相对于单链表
循环链表的新功能：游标
在循环链表中可以定义一个当前指针 这个指针为游标
可以通过游标来遍历链表中的所有元素*/

/*直接删除链表中的某个数据元素*/
CircleListNode* CircleList_DeleteCeertainNode(CircleList* circlelist, CircleListNode* node);
/*将游标充值指向链表的第一个元素*/
CircleListNode* CircleList_Reset(CircleList* circlelist);
/*获取当前游标指向的元素*/
CircleListNode* CircleList_Current(CircleList* circlelist);
/*将游标移动到链表中的下一个元素*/
CircleListNode* CircleList_Next(CircleList* circlelist);
#endif // !_CIRCLELIST_H_
