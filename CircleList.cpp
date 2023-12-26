#include"Circlelist.h"
#include<stdio.h>
#include<stdlib.h>
typedef struct _tag_CircleList
{
	CircleListNode* header;/*ͷ�����*/
	CircleListNode* slider;
	int length;
}TCircleList;
#pragma region ����ѭ������
CircleList* CircleList_Creat()
{
	TCircleList* list = nullptr;
	list = (TCircleList*)malloc(sizeof(TCircleList));
	/*�ж��Ƿ񴴽��ɹ�*/
	if (list == NULL)
	{
		printf("����ʧ��");
		return NULL;
	}
	/*�����ɹ�*/
	list->length = 0;
	list->header->next = nullptr;
	list->slider = nullptr;
}
#pragma endregion
#pragma region ����ѭ������
void CircleList_Destory(CircleList* circlelist)
{
	if (circlelist == nullptr)
	{
		printf("��ָ�벻������");
		return;
	}
	/*�ǿ�ָ������free*/
	free(circlelist);
}
#pragma endregion
#pragma region ���ѭ������
void CircleList_Clear(CircleList* circlelist)
{
	/*�ж�ָ���Ƿ�Ϊ��ָ��*/
	if (circlelist == nullptr)
	{
		printf("ָ�������");
		return;
	}
	/*ָ��ǿ�*/
	TCircleList* tmp = (TCircleList*)circlelist;
	tmp->header->next = nullptr;
	tmp->length = 0;
	tmp->slider = NULL;
	delete tmp;
}
#pragma endregion
#pragma region ��ȡѭ������ĳ���
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
#pragma region ��ȡposλ�õĽ��
CircleListNode* CircleList_Get(CircleList* circlelist, int pos)
{
	if (circlelist == nullptr || pos<0)
	{
		printf("�޷���ȡpos����λ�õĽ��");
		return NULL;
	}
	TCircleList* tlist = (TCircleList*)circlelist;
	/*�ø���ָ�����ָ��ͷ�����*/
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
#pragma region ��ѭ�������posλ�ò���node���
int CircleList_Get(CircleList* circlelist, CircleListNode* insert_node,int pos)
{
	/*�жϲ����Ƿ���Ч*/
	if (circlelist == NULL || insert_node == nullptr||pos<0)
	{
		printf("������Ч");
		return -1;
	}
	/*������Ч*/
	TCircleList *tlist = nullptr;
	tlist = (TCircleList *)circlelist;
	CircleListNode* current = (CircleListNode*)tlist;
	for (int i = 0;(i<pos)&&(current->next!= NULL); i++)
	{
		current = current->next;
	}
	/*���޵��е�β�巨 �Լ�ͷ�巨��������Ҫ��*/
	insert_node->next = current->next;
	current->next = insert_node;/*�ߵ��ⲽ����������ǿգ�ͬʱ�������ͨλ��*/
	if (tlist->length == 0)
	{
		tlist->slider = insert_node;
	}
	if (current == (CircleListNode*)tlist)/*��ʾû��ִ��forѭ�� ���ܴ������ֿ���*/
		/*���޵��е�β�巨�Լ�ͷ�巨*/
	{
		CircleListNode* lastNode = CircleList_Get(tlist, tlist->length - 1);/*��ȡβ��Ԫ��*/
		/*�����ͷ�巨����Ҫ��β����Ԫ��ָ��insertnode����Ľ��
		�����ڴ��޵��еĽ����˵ ��Ҫ������ĵ�һ������nextָ�� ָ����*/
		lastNode->next = current->next;
	}
	tlist->length++;
	return pos;
}
#pragma endregion
#pragma region ���α��ֵָ������ĵ�һ��Ԫ��
CircleListNode* CircleList_Reset(CircleList* circlelist)
{
	if (circlelist == NULL)
	{
		printf("����Ϊ��");
		return NULL;
	}
	TCircleList* tmp = (TCircleList*)circlelist;
	CircleListNode* tmpnode = NULL;
	tmpnode = tmp->slider = tmp->header->next;
	return tmpnode;
}
#pragma endregion
#pragma region ɾ��posλ�õĽ��
CircleListNode* CircleList_Delete(CircleList* circlelist, int pos)
{
	if (circlelist == nullptr && pos <=0)
	{
		printf("ɾ������Ϊ�ս��");
		return nullptr;
	}
	TCircleList* tlist = (TCircleList*)circlelist;
	CircleListNode* current = (CircleListNode*)tlist;
	/*����ɾ������*/
	for (int i = 0; i < pos; i++)
	{
		current = current->next;
	}
	CircleListNode* tmpNode = nullptr;
	tmpNode = current->next;
	current->next = tmpNode->next;
	/*ɾ������ͷ��Ԫ��*/
	if (current == (CircleListNode*)tlist)
	{
		CircleListNode* tmpLast = CircleList_Get(circlelist, tlist->length - 1);
		tmpLast->next = current->next;/*ɾ�����ǵ�һ��Ԫ�� ��ô�����β��Ԫ��ָ���µ���Ԫ��*/
	}
	/*���ɾ���Ľ���ǵ�һ������Ľ��  ��ô�α��λ����Ҫ�ı� 
	��ɾ��������һ����㸳ֵ��slider
	*/
	if (tlist->slider == tmpNode)
	{
		tlist->slider = tmpNode->next;
	}
	tlist->length--;
	/*�������Ԫ��ɾ��*/

	/*ɾ��Ԫ�غ� ����ĳ���Ϊ0 */
	if (tlist->length == 0)
	{
		printf("������Ԫ��ɾ���� ����Ϊ��");
		tlist->header->next = nullptr;
		tlist->slider = nullptr;
		tlist->length = 0;
	}
	return tmpNode;



	return tmpNode;
}
#pragma endregion
#pragma region ֱ��ָ��ɾ�������е�ĳ������Ԫ��
CircleListNode* CircleList_DeleteCeertainNode(CircleList* circlelist, CircleListNode* node)
{
	TCircleList* tlist = (TCircleList*)circlelist;
	CircleListNode* tmpNode1 = nullptr;
	CircleListNode* tmp = (CircleListNode*)tlist;
	if (circlelist == nullptr|| node == NULL)
	{
		printf("ɾ��ʧ��");
		return NULL;
	}
	/*ɾ��ָ�����*/
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
	/*ָ��ͷ�����*/
	/*
	CircleListNode* tmpNode2 = nullptr;
	tmpNode2 = (CircleListNode*)circlelist;
	int count = 0;
	while ((tmp != node))
	{
		tmp = tmp->next;//ѭ����һ��ָ��0��λ��Ԫ��
		count++;
		if (count>tlist->length)
		{
			printf("��������ָ��Ԫ��");
			return NULL;
		}
	}
	for (int i = 0; i < count; i++)
	{
		tmpNode2 = tmpNode2->next;//tmpNode2->next��tmp���ȼ�
	}
	//tmp��Ҫɾ����Ԫ��
	tmpNode1 = tmp->next;
	tmpNode2->next = tmpNode1;
	return tmp;
	*/
}
#pragma endregion
#pragma region ��ȡ��ǰ�α�ָ���Ԫ��
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
#pragma region ���α��ƶ��������е���һ��Ԫ��
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






