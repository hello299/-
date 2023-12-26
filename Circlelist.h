#pragma once
#ifndef _CIRCLELIST_H_
#define _CIRCLELIST_H_

typedef void CircleList;
/*������*/
//typedef struct _tag_CircleListNode CircleListNode;
//struct _tag_CircleListNode
//{
//	CircleListNode *next;
//};
typedef struct  _tag_CircleListNode
{
	struct _tag_CircleListNode* next;
}CircleListNode;

/*����ѭ������*/
CircleList* CircleList_Creat();
/*����ѭ������*/
void CircleList_Destory(CircleList* circlelist);
/*���ѭ������*/
void CircleList_Clear(CircleList* circlelist);
/*��ȡposλ�õĽ��*/
CircleListNode* CircleList_Get(CircleList* circlelist, int pos);
/*��ȡѭ������ĳ���*/
int CircleList_Length(CircleList* circlelist);
/*��ѭ�������posλ�ò���node���*/
int CircleList_Get(CircleList* circlelist, CircleListNode* insert_node,int pos);
/*ɾ��posλ�õĽ��*/
CircleListNode* CircleList_Delete(CircleList* circlelist, int pos);

/*����ڵ�����
ѭ��������¹��ܣ��α�
��ѭ�������п��Զ���һ����ǰָ�� ���ָ��Ϊ�α�
����ͨ���α������������е�����Ԫ��*/

/*ֱ��ɾ�������е�ĳ������Ԫ��*/
CircleListNode* CircleList_DeleteCeertainNode(CircleList* circlelist, CircleListNode* node);
/*���α��ֵָ������ĵ�һ��Ԫ��*/
CircleListNode* CircleList_Reset(CircleList* circlelist);
/*��ȡ��ǰ�α�ָ���Ԫ��*/
CircleListNode* CircleList_Current(CircleList* circlelist);
/*���α��ƶ��������е���һ��Ԫ��*/
CircleListNode* CircleList_Next(CircleList* circlelist);
#endif // !_CIRCLELIST_H_
