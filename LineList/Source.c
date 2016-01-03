
#include <stdio.h>
#include <stdlib.h>
#include "Header.h"


struct ListNode gOrigin;
struct ListNode *gpFront;
struct ListNode *gpBack;

int main(void)
{
	int Option;

	gOrigin.Value = 0;
	gOrigin.pNext = 0;
	gpFront = gpBack = &gOrigin;
	
	while (1)
	{
		printf("\nOptions list:\n");
		printf("\t%d.Clean screen\n", RO_cleanscreen);
		printf("\t%d.Receive inputs\n", RO_recinput);
		printf("\t%d.Operate list\n", RO_operatelist);
		printf("\t%d.List nodes\n", RO_listnodes);
		printf("\t%d.Exit\n", RO_exit);
		printf("Option: ");
		scanf("%d", &Option);
		printf("\n");

		switch (Option)
		{
			case RO_cleanscreen:
				system("cls");
				break;
			case RO_recinput:
				DoRecInputs();
				break;
			case RO_operatelist:
				DoOperateList();
				break;
			case RO_listnodes:
				ListNodes();
				break;
			case RO_exit:
				DoFreeAll();
				goto end;
				break;
			default:
				printf("No such option\n");
				break;
		}	
	}

	end:
	return 0;
}

//--------------------------------------------------------------
// Function implements
//--------------------------------------------------------------
struct ListNode *New(LNValueType Value)
{
	struct ListNode *pNode = malloc(sizeof(struct ListNode));
	pNode->Value = Value;
	pNode->pNext = 0;
	return pNode;
}
void Insert(struct ListNode *pParent, struct ListNode *pNode)
{
	pNode->pNext = pParent->pNext;
	pParent->pNext = pNode;
}
void Remove(struct ListNode *pParent)
{
	struct ListNode *pNode;
	if (pParent != 0)
	{
		pNode = pParent->pNext;
		pParent->pNext = pNode->pNext;
		free(pNode);
	}
}
void DoFreeAll(void)
{
	gpFront = gpFront->pNext;

	struct ListNode *pCur = gpFront;
	while (pCur != 0)
	{
		pCur = pCur->pNext;
		free(gpFront);
		gpFront = pCur;
	}
}

void ListNodes(void)
{
	struct ListNode *pCur = gpFront->pNext;
	int nCount = 1;

	for (; pCur != 0; ++nCount, pCur = pCur->pNext)
	{
		switch (LNVT)
		{
			case LNVT_char:
				printf("%d. Value: %c\n", nCount, pCur->Value);
				break;
			case LNVT_int:
				printf("%d. Value: %d\n", nCount, pCur->Value);
				break;
			case LNVT_uint:
				printf("%d. Value: %u\n", nCount, pCur->Value);
				break;
			case LNVT_float:
				printf("%d. Value: %.6f\n", nCount, pCur->Value);
				break;
			case LNVT_double:
				printf("%d. Value: %.12f\n", nCount, pCur->Value);
				break;
		}
	}
}
void DoRecInputs(void)
{
	char ch;
	int in;
	unsigned int ui;
	float fl;
	double dou;

	void *pValue;

	switch (LNVT)
	{
		case LNVT_char:
			printf("Construct a node with value(char): ");
			getchar();
			scanf("%c", &ch);
			pValue = &ch;
			break;
		case LNVT_int:
			printf("Construct a node with value(int): ");
			scanf("%d", &in);
			pValue = &in;
			break;
		case LNVT_uint:
			printf("Construct a node with value(uint): ");
			scanf("%u", &ui);
			pValue = &ui;
			break;
		case LNVT_float:
			printf("Construct a node with value(float): ");
			scanf("%f", &fl);
			pValue = &fl;
			break;
		case LNVT_double:
			printf("Construct a node with value(double): ");
			scanf("%lf", &dou);
			pValue = &dou;
			break;
		default:
			// throw an error.
			pValue = 0;
			break;
	}
	Insert(gpBack, New(*(LNValueType*)pValue));
	gpBack = gpBack->pNext;
}
void DoOperateList(void)
{
	int nIndex;
	printf("Only <Remove> available...\n");
	printf("Remove node(index): ");
	scanf("%d", &nIndex);

	struct ListNode *pCur = gpFront;
	int i = 0;
	for (; i < nIndex - 1; ++i)
	{
		pCur = pCur->pNext;
		if (pCur == 0)
		{
			break;
		}
	}

	if ((i != nIndex -1) || (pCur->pNext == 0))
	{
		printf("No such node existed.\n");
	}
	else
	{
		if (pCur->pNext->pNext == 0)	// list back.
		{
			gpBack = pCur;
		}
		Remove(pCur);
	}
}