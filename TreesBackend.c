#include <stdbool.h>
#include <malloc.h>
#include "GameFrontend.c"

struct tree
{
    int data, h, k, leftPotentialNumber, rightPotentialNumber, reducedXFactor;
    struct tree *left, *right;
};

static struct tree *result;
struct tree *potentialNode, *childNode, *lastNode;

bool isEnteringData = true, isChoosingDirection = false;

int ans, node, gameType, parentData = 0, childData = 0, potentialNumber[50], potentialNumberIndex = 1, treeArray[50],
        arraySize = 0, numOptions = 12, optionNums[30], alternateOptionNums[30], optionNumXPos = 230, treeNumXPos = 155, lastOptionalNumberIndex;

void FillOptions()
{
    int i, j, value;

    for (i = 0; i < numOptions; ++i)
    {
        bool alreadyPresent;
        do
        {
            value = rand() % 50 + 1;
            alreadyPresent = false;

            for (j = 0; j < i; ++j)
            {
                if (value == optionNums[j])
                {
                    alreadyPresent = true;
                    break;
                }
            }
        } while (alreadyPresent);

        optionNums[i] = value;
        alternateOptionNums[i] = value;
    }

    lastOptionalNumberIndex = numOptions - 1;
}

bool AnyBallLeft()
{
    int i;

    for (i = 0; i < numOptions; ++i)
    {
        if (optionNums[i] != -1)
        {
            return true;
        }
    }

    return false;
}

bool SortedOrNot()
{
    int i;

    if (arraySize == 0 || arraySize == 1)
    {
        return true;
    }

    for (i = 1; i < arraySize; ++i)
    {
        if (treeArray[i - 1] >= treeArray[i])
        {
            return false;
        }
    }

    return true;
}

int GetPotentialNumber()
{
    int i;

    for (i = 1; i <= potentialNumberIndex; ++i)
    {
        if (potentialNumber[i] == -1)
        {
            potentialNumber[i] = 1;
//            printf("\nPN: %d", i);
            return i;
        }
    }

    potentialNumberIndex++;
    potentialNumber[potentialNumberIndex] = 1;

    //printf("\nPN: %d", potentialNumberIndex);
    return potentialNumberIndex;
}

struct tree *GetNode(struct tree *node, int potentialNumber)
{
    if (node == NULL)
    {
        return NULL;
    } else if (node->leftPotentialNumber == potentialNumber || node->rightPotentialNumber == potentialNumber)
    {
        result = node;
    }

    GetNode(node->left, potentialNumber);
    GetNode(node->right, potentialNumber);

    return result;
}

bool CheckPreorder(struct tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    treeArray[arraySize++] = node->data;
    CheckPreorder(node->left);
    CheckPreorder(node->right);

    return SortedOrNot();
}

bool CheckInorder(struct tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    CheckInorder(node->left);
    treeArray[arraySize++] = node->data;
    CheckInorder(node->right);

    return SortedOrNot();
}

bool CheckPostorder(struct tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    CheckPostorder(node->left);
    CheckPostorder(node->right);
    treeArray[arraySize++] = node->data;

    return SortedOrNot();
}

void *TraversePreorderAndDraw(struct tree *node)
{
    if (node == NULL)
    {
        return NULL;
    }

    if (isChoosingDirection)
    {
        if (node->leftPotentialNumber != 0)
        {
            DrawPotentialLines(node->h, node->k, node->h - node->reducedXFactor + 40, node->k + YFactor);
            DrawPotentialCircle(node->h - node->reducedXFactor + 40, node->k + YFactor, node->leftPotentialNumber);
        } else
        {
            DrawLines(node->h, node->k, node->left->h, node->left->k);
            DrawCircle(node->left->h, node->left->k, node->left->data);
        }

        if (node->rightPotentialNumber != 0)
        {
            DrawPotentialLines(node->h, node->k, node->h + node->reducedXFactor - 40, node->k + YFactor);
            DrawPotentialCircle(node->h + node->reducedXFactor - 40, node->k + YFactor, node->rightPotentialNumber);
        } else
        {
            DrawLines(node->h, node->k, node->right->h, node->right->k);
            DrawCircle(node->right->h, node->right->k, node->right->data);
        }
    } else
    {
        if (node->leftPotentialNumber == 0)
        {
            DrawLines(node->h, node->k, node->left->h, node->left->k);
            DrawCircle(node->left->h, node->left->k, node->left->data);
        }

        if (node->rightPotentialNumber == 0)
        {
            DrawLines(node->h, node->k, node->right->h, node->right->k);
            DrawCircle(node->right->h, node->right->k, node->right->data);
        }
    }

    TraversePreorderAndDraw(node->left);
    TraversePreorderAndDraw(node->right);
}

bool InsertLeft(struct tree *parent)
{
    struct tree *child;
    child = (struct tree *)
            malloc(sizeof(struct tree));

    potentialNumber[parent->leftPotentialNumber] = -1;
    parent->leftPotentialNumber = 0;

    child->data = childData;
    child->left = NULL;
    child->right = NULL;
    child->reducedXFactor = parent->reducedXFactor - 30;
    child->h = parent->h - child->reducedXFactor;
    child->k = parent->k + YFactor;
    child->leftPotentialNumber = GetPotentialNumber();
    child->rightPotentialNumber = GetPotentialNumber();

    parent->left = child;
}

bool InsertRight(struct tree *parent)
{
    struct tree *child;
    child = (struct tree *)
            malloc(sizeof(struct tree));

    potentialNumber[parent->rightPotentialNumber] = -1;
    parent->rightPotentialNumber = 0;

    child->data = childData;
    child->left = NULL;
    child->right = NULL;
    child->reducedXFactor = parent->reducedXFactor - 40;
    child->h = parent->h + child->reducedXFactor;
    child->k = parent->k + YFactor;
    child->leftPotentialNumber = GetPotentialNumber();
    child->rightPotentialNumber = GetPotentialNumber();

    parent->right = child;
}

bool CheckIfCorrect(struct tree *root)
{
    if (gameType == 1)
    {
        return CheckPreorder(root);

    } else if (gameType == 2)
    {
        return CheckInorder(root);

    } else if (gameType == 3)
    {
        return CheckPostorder(root);
    }
}

int HitAndTrial(struct tree *root)
{
    int i;

    for (i = 0; i < numOptions; ++i)
    {
        arraySize = 0;

        if (optionNums[i] != -1)
        {
            childNode->data = optionNums[i];

            if (CheckIfCorrect(root))
            {
                optionNums[i] = -1;
                return 1;
            }
        }
    }

    potentialNumber[childNode->rightPotentialNumber] = -1;
    potentialNumber[childNode->leftPotentialNumber] = -1;

    return 0;
}

int BotItIsYourTurn(struct tree *root)
{
    int i, j, answer;

    for (i = 1; i <= potentialNumberIndex; ++i)
    {
        if (potentialNumber[i] == 1)
        {
            potentialNode = GetNode(root, i);

            if (potentialNode->rightPotentialNumber == i)
            {
                InsertRight(potentialNode);
                childNode = potentialNode->right;
                answer = HitAndTrial(root);

                if (answer != 0)
                {
                    answer = childNode->data;
                    ans = answer;
                    node = i;
                    lastNode = childNode;
                    DrawLastCircle(lastNode->h, lastNode->k, lastNode->data);
                    return answer;
                } else
                {
                    potentialNode->rightPotentialNumber = i;
                    potentialNumber[potentialNode->rightPotentialNumber] = 1;
                    potentialNode->right = NULL;
                }

            } else if (potentialNode->leftPotentialNumber == i)
            {
                InsertLeft(potentialNode);
                childNode = potentialNode->left;
                answer = HitAndTrial(root);

                if (answer != 0)
                {
                    answer = childNode->data;
                    ans = answer;
                    node = i;
                    lastNode = childNode;
                    DrawLastCircle(lastNode->h, lastNode->k, lastNode->data);
                    //14*10=140+6
                    return answer;
                } else
                {
                    potentialNode->leftPotentialNumber = i;
                    potentialNumber[potentialNode->leftPotentialNumber] = 1;
                    potentialNode->left = NULL;
                }
            }
        }
    }

    ClearInstructions();
    DrawBitmapString("No Valid Input Left", 40,
                     30, 0);

    ans = -1;
    return -1;
}
