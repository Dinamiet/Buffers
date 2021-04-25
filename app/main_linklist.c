#include <stdio.h>

#include "linkedlist.h"

#define NUM_NODES 10

int main(int argc, char* argv[])
{
    LinkedList list;
    LinkedList_Init(&list);

    Node nodes[NUM_NODES];
    uint32_t data[NUM_NODES];

    // Setup nodes
    for (size_t i = 0; i < NUM_NODES; i++)
    {
        data[i] = i;
        nodes[i].Data= &data[i];
    }

    // Add nodes to front
    LinkedList_LinkHead(&list, &nodes[3]);
    LinkedList_LinkHead(&list, &nodes[2]);
    LinkedList_LinkHead(&list, &nodes[1]);
    LinkedList_LinkHead(&list, &nodes[0]);

    LinkedList_LinkTail(&list, &nodes[4]);
    LinkedList_LinkTail(&list, &nodes[5]);
    LinkedList_LinkTail(&list, &nodes[6]);
    LinkedList_LinkTail(&list, &nodes[7]);

    Node* testNode;
    uint32_t testData;

    //Test 1;
    testNode= LinkedList_UnlinkHead(&list);
    if (!testNode)
        return 1;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 0)
        return 1;

    // 2
    testNode= LinkedList_UnlinkHead(&list);
    if (!testNode)
        return 2;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 1)
        return 2;

    // 3
    testNode= LinkedList_UnlinkTail(&list);
    if (!testNode)
        return 3;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 7)
        return 3;

    // 4
    testNode= LinkedList_UnlinkTail(&list);
    testNode= LinkedList_UnlinkTail(&list);
    testNode= LinkedList_UnlinkTail(&list);
    testNode= LinkedList_UnlinkTail(&list);
    testNode= LinkedList_UnlinkTail(&list);
    if (!testNode)
        return 4;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 2)
        return 4;

    // 5
    testNode= LinkedList_UnlinkTail(&list);
    if (testNode != NULL)
        return 5;

    testNode= LinkedList_UnlinkHead(&list);
    if (testNode != NULL)
        return 5;

    // 6
    LinkedList_LinkTail(&list, &nodes[9]);
    testNode= LinkedList_UnlinkHead(&list);
    if (!testNode)
        return 6;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 9)
        return 6;

    LinkedList_LinkHead(&list, &nodes[8]);
    testNode= LinkedList_UnlinkHead(&list);
    if (!testNode)
        return 6;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 8)
        return 6;

    LinkedList_LinkHead(&list, &nodes[2]);
    testNode= LinkedList_UnlinkTail(&list);
    if (!testNode)
        return 6;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 2)
        return 6;

    LinkedList_LinkTail(&list, &nodes[0]);
    testNode= LinkedList_UnlinkTail(&list);
    if (!testNode)
        return 6;
    testData= *(uint32_t*)testNode->Data;
    if (testData != 0)
        return 6;

    // Checking itteration
    // populate list
    LinkedList_LinkHead(&list, &nodes[0]);
    LinkedList_LinkTail(&list, &nodes[2]);
    LinkedList_LinkTail(&list, &nodes[4]);
    LinkedList_LinkTail(&list, &nodes[6]);
    LinkedList_LinkTail(&list, &nodes[8]);

    // Checking forward links
    testNode= list.Head;
    for (size_t i = 0; i < NUM_NODES; i+= 2)
    {
        if (testNode == NULL)
            return 7;
        testData= *(uint32_t*)testNode->Data;
        if (testData != i)
            return 7;

        testNode= testNode->Next;
    }

    if (testNode != list.Head)
        return 7;

    // Checking backward links
    testNode= list.Tail;
    for (int i = NUM_NODES-2; i >= 0; i-= 2)
    {
        if (testNode == NULL)
            return 8;
        testData= *(uint32_t*)testNode->Data;
        if (testData != i)
            return 8;

        testNode= testNode->Prev;
    }

    if (testNode != list.Tail)
        return 8;


    testNode= LinkedList_UnlinkHead(&list);
    LinkedList_LinkTail(&list, testNode);

    // Checking forward links
    testNode= list.Head->Prev;
    for (size_t i = 0; i < NUM_NODES; i+= 2)
    {
        if (testNode == NULL)
            return 9;
        testData= *(uint32_t*)testNode->Data;
        if (testData != i)
            return 9;

        testNode= testNode->Next;
    }

    // Checking backward links
    testNode= list.Tail->Prev;
    for (int i = NUM_NODES-2; i >= 0; i-= 2)
    {
        if (testNode == NULL)
            return 10;
        testData= *(uint32_t*)testNode->Data;
        if (testData != i)
            return 10;

        testNode= testNode->Prev;
    }

    return 0;
}
