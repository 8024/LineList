
#ifndef __HeaderH__
#define __HeaderH__


enum RouteOption
{
	RO_cleanscreen = 1,
	RO_recinput,
	RO_operatelist,
	RO_listnodes,
	RO_exit
};	// End enumeration RouteOption.
enum LN_Value_Type
{
	LNVT_char,	// char
	LNVT_int,	// int
	LNVT_uint,	// unsigned int
	LNVT_float,	// float
	LNVT_double	// double
};	// End enumeration LN_Value_Type.
typedef int LNValueType;
#define LNVT LNVT_int

//--------------------------------------------------------------
// Structures
//--------------------------------------------------------------
struct ListNode
{
	LNValueType Value;
	struct ListNode *pNext;
};	// End structure ListNode.

//--------------------------------------------------------------
// Functions
//--------------------------------------------------------------
struct ListNode *New(LNValueType Value);
void Insert(struct ListNode *pParent, struct ListNode *pNode);
void Remove(struct ListNode *pParent);
void DoFreeAll(void);

void ListNodes(void);
void DoRecInputs(void);
void DoOperateList(void);

//--------------------------------------------------------------
// Global variables
//--------------------------------------------------------------
extern struct ListNode gOrigin;
extern struct ListNode *gpFront;
extern struct ListNode *gpBack;

#endif	// End __HeaderH__.