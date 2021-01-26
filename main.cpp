//#include <stdio.h>
//#include <time.h>
//#include "TreesBackend.c"
//
//int winID, gameMode;
//struct tree *root, *activeNode;
//bool playerLost = false;
//
//void PlantTree(int num)
//{
//    root = (struct tree *)
//            malloc(sizeof(struct tree));
//
//    activeNode = (struct tree *)
//            malloc(sizeof(struct tree));
//
//    root->data = num;
//    root->left = NULL;
//    root->right = NULL;
//    root->h = SCREEN_WIDTH / 2;
//    root->k = 80 + r;
//    root->leftPotentialNumber = GetPotentialNumber();
//    root->rightPotentialNumber = GetPotentialNumber();
//    root->reducedXFactor = XFactor;
//
//    activeNode = root;
//}
//
//void ResetPotentialNumbers()
//{
//    int i;
//
//    for (i = 0; i < 50; ++i)
//    {
//        potentialNumber[i] = -1;
//    }
//}
//
//void UpdateLastOptionalNumberIndex()
//{
//    int i, temp = 0;
//
//    for (i = 0; i < numOptions; ++i)
//    {
//        if (optionNums[i] != -1)
//        {
//            temp = i;
//        }
//    }
//
//    lastOptionalNumberIndex = temp;
//}
//
//bool CheckIfNumFromOptions(int input)
//{
//    int i;
//
//    for (i = 0; i < numOptions; ++i)
//    {
//        if (optionNums[i] == input)
//        {
//            optionNums[i] = -1;
//            UpdateLastOptionalNumberIndex();
//            return true;
//        }
//    }
//
//    return false;
//}
//
//void ShowGameMode(int x, int y)
//{
//    SetColor4d(66, 66, 66, 1);
//
//    if (gameType == 1)
//    {
//        DrawBitmapString("Tree must be Increasing in Preorder Traversal", x,
//                         y, 0);
//
//    } else if (gameType == 2)
//    {
//        DrawBitmapString("Tree must be Increasing in Inorder Traversal", x,
//                         y, 0);
//
//    } else if (gameType == 3)
//    {
//        DrawBitmapString("Tree must be Increasing in Postorder Traversal", x,
//                         y, 0);
//    }
//}
//
//void ShowAvailableNumbers()
//{
//    int i, XToIncrease = 23;
//    char c[50];
//
//    DrawBitmapString("Tree nodes value options: ", 30, 60, 0);
//
//    for (i = 0; i < numOptions; ++i)
//    {
//        optionNumXPos += XToIncrease;
//
//        if (optionNums[i] != -1)
//        {
//            SetColor4d(TEXTCOLOR, 1);
//        } else
//        {
//            SetColor4d(SELECTEDTEXTCOLOR, 1);
//        }
//
//        if (alternateOptionNums[i] > 9)
//        {
//            XToIncrease = 33;
//        } else
//        {
//            XToIncrease = 23;
//        }
//
//        if (i != lastOptionalNumberIndex)
//        {
//            sprintf(c, "%d", alternateOptionNums[i]);
//            strcat(c, ",");
//        } else
//        {
//            sprintf(c, "%d", alternateOptionNums[i]);
//        }
//
//        DrawBitmapString(c, optionNumXPos,
//                         60, 0);
//    }
//
//    optionNumXPos = 230;
//}
//
//void ShowTutorialExplanation(int x, int y, int ans, int node)
//{
//    char c[100];
//
//    SetColor4d(66, 66, 66, 1);
//
//    if (ans != -1)
//    {
//        DrawBitmapString("Cyan Colored Node was selected.", x,
//                         y, 0);
//
//        sprintf(c, "%d", ans);
//        x += 290;
//
//        if (gameType == 1)
//        {
//            strcat(c,
//                   " value was chosen because, as we can see, it makes Preorder Tree Traversal in increasing order ");
//
//        } else if (gameType == 2)
//        {
//            strcat(c, " value was chosen because, as we can see, it makes Inorder Tree Traversal in increasing order");
//
//        } else if (gameType == 3)
//        {
//            strcat(c,
//                   " value was chosen because, as we can see, it makes Postorder Tree Traversal in increasing order");
//        }
//
//        DrawBitmapString(c, x,
//                         y, 0);
//    } else
//    {
//        DrawBitmapString("No option left. Tree completed", x,
//                         y, 0);
//    }
//}
//
//void ShowCorrectOption()
//{
//    char c[10];
//
//    DrawBitmapString("Player should have taken", 20,
//                     SCREEN_HEIGHT - 20, 0);
//
//    sprintf(c, "%d", ans);
//    printf("\nCorrect: %d  %d", ans, node);
//    DrawBitmapString("x", 50,
//                     SCREEN_HEIGHT - 20, 0);
//}
//
//void ShowTutorialText(int x, int y)
//{
//    SetColor4d(66, 66, 66, 1);
//
//    if (gameType == 1)
//    {
//        DrawBitmapString("Tree must be Increasing in Preorder Traversal. Preorder is Root->Left->Right", x,
//                         y, 0);
//
//    } else if (gameType == 2)
//    {
//        DrawBitmapString("Tree must be Increasing in Inorder Traversal. Inorder is Left->Root->Right", x,
//                         y, 0);
//
//    } else if (gameType == 3)
//    {
//        DrawBitmapString("Tree must be Increasing in Postorder Traversal. Postorder is Left->Right->Root", x,
//                         y, 0);
//    }
//}
//
//void ShowTreeMade(int x, int y)
//{
//    int i;
//    char c[50];
//
//    SetColor4d(TEXTCOLOR, 1);
//
//    for (i = 0; i < arraySize; ++i)
//    {
//        if (treeArray[i] != -1)
//        {
//            if (treeArray[i] > 9)
//            {
//                treeNumXPos += 33;
//            } else
//            {
//                treeNumXPos += 23;
//            }
//
//            if (i != arraySize - 1)
//            {
//                sprintf(c, "%d", treeArray[i]);
//                strcat(c, ",");
//            } else
//            {
//                sprintf(c, "%d", treeArray[i]);
//            }
//
//            DrawBitmapString(c, treeNumXPos,
//                             y, 0);
//        }
//    }
//
//    treeNumXPos = 155;
//}
//
//void ShowTreeAndText()
//{
//    SetColor4d(TEXTCOLOR, 1);
//
//    ShowTreeMade(30, 30);
//    DrawBitmapString("Choose Node Number and Press Enter", 40,
//                     90, 0);
//
//    ShowGameMode(600, 60);
//}
//
//void ShowTreeAndTutorialText()
//{
//    SetColor4d(TEXTCOLOR, 1);
//    DrawBitmapString("Correct! Tree: ", 50, SCREEN_HEIGHT - 40, 0);
//    ShowTreeMade(30, SCREEN_HEIGHT - 40);
//    ShowTutorialText(40, 20);
//}
//
//void DoRemainingTasks()
//{
//    ShowTreeAndText();
//    ShowAvailableNumbers();
//
//    isEnteringData = false;
//    isChoosingDirection = true;
//}
//
//void keyUp(unsigned char key, int x, int y)
//{
//    static int num = 0;
//    char c[10];
//
//    ClearInstructions();
//    SetColor4d(66, 66, 66, 1);
//
//    if (isChoosingDirection == false)
//    {
//        ShowGameMode(550, 30);
//
//        ShowAvailableNumbers();
//    } else
//    {
//        ShowGameMode(600, 30);
//    }
//
//    if (AnyBallLeft())
//    {
//        switch (key)
//        {
//            case 8:
//                num /= 10;
//
//                if (isEnteringData)
//                {
//                    DrawCircle(activeNode->h, activeNode->k, num);
//                } else
//                {
//                    sprintf(c, "%d", num);
//                    SetColor4d(66, 66, 66, 1);
//                    DrawBitmapString(c, SCREEN_WIDTH / 2 - 110, 60, 0);
//                }
//
//                break;
//
//            case 13:
//
//                if (gameMode == 3)
//                {
//                    DoRemainingTasks();
//
//                    BotItIsYourTurn(root);
//
//                    ClearInstructions();
//                    ClearTree();
//                    TraversePreorderAndDraw(root);
//                    DrawCircle(root->h, root->k, root->data);
//
//                    printf("\nAns: %d", ans);
//
//                    ShowTutorialExplanation(30, SCREEN_HEIGHT - 10, ans, node);
//                    ShowAvailableNumbers();
//                    DrawLastCircle(lastNode->h, lastNode->k, lastNode->data);
//
//                    if (ans != -1)
//                    {
//                        ShowTreeAndTutorialText();
//                    }
//
//                } else
//                {
//                    ClearInstructions();
//                    ClearTree();
//                    SetColor4d(66, 66, 66, 1);
//
//                    if (playerLost)
//                    {
//                        root = (struct tree *)
//                                malloc(sizeof(struct tree));
//                        ResetPotentialNumbers();
//                        FillOptions();
//                        PlantTree(0);
//
//                        playerLost = false;
//                    }
//
//                    if (isEnteringData)
//                    {
//                        activeNode->data = num;
//
//                        if (CheckIfNumFromOptions(num))
//                        {
//                            arraySize = 0;
//
//                            if (CheckIfCorrect(root) == true)
//                            {
//                                printf("\nGameMode: %d", gameMode);
//
//                                if (gameMode == 1)
//                                {
//                                    BotItIsYourTurn(root);
//                                    DoRemainingTasks();
//
//                                } else if (gameMode == 2)
//                                {
//                                    DoRemainingTasks();
//                                }
//
//                                if (!AnyBallLeft())
//                                {
//                                    DrawBitmapString(
//                                            "Well Played. Your concepts of Tree Traversal are really strong! No option left. Tree completed.",
//                                            30,
//                                            SCREEN_HEIGHT - 10, 0);
//                                }
//                            } else
//                            {
//                                playerLost = true;
//                                DrawBitmapString(
//                                        "Wrong choice! As you can see, your choice made invalid tree. Press Enter to Re-start",
//                                        50,
//                                        SCREEN_HEIGHT - 40, 0);
//                                DrawBitmapString(
//                                        "Tree:", 20,
//                                        30, 0);
//
//                                ShowTreeMade(30, 30);
//                            }
//                        } else
//                        {
//                            DrawBitmapString(
//                                    "Invalid choice! No such number exists!",
//                                    130,
//                                    30, 0);
//                            ShowAvailableNumbers();
//                            num = 0;
//                        }
//
//                    } else if (isChoosingDirection)
//                    {
//                        result = NULL;
//                        activeNode = GetNode(root, num);
//
//                        if (activeNode != NULL)
//                        {
//                            DrawBitmapString("Press Enter to submit value & Backspace to Clear", 20, 30,
//                                             0);
//                            ShowGameMode(550, 30);
//                            ShowAvailableNumbers();
//                            isEnteringData = true;
//                            isChoosingDirection = false;
//
//                            if (activeNode->rightPotentialNumber == num)
//                            {
//                                InsertRight(activeNode);
//                                activeNode = activeNode->right;
//
//                            } else if (activeNode->leftPotentialNumber == num)
//                            {
//                                InsertLeft(activeNode);
//                                activeNode = activeNode->left;
//                            }
//                        } else
//                        {
//                            ClearInstructions();
//                            SetColor4d(66, 66, 66, 1);
//                            DrawBitmapString("No such node exists!", 130, 30,
//                                             0);
//                            num = 0;
//                        }
//                    }
//
//                    TraversePreorderAndDraw(root);
//
//                    DrawCircle(root->h, root->k, root->data);
//                    //DrawLastCircle(activeNode->h, activeNode->k, 0)
//                    num = 0;
//                }
//
//                break;
//
//            case 27:
//                glutDestroyWindow(winID);
//                exit(0);
//
//            case 48 ... 57:
//                num = (num * 10) + (key - '0');
//
//                if (num >= 100)
//                {
//                    num /= 10;
//                }
//
//                SetColor4d(102, 204, 255, 1);
//
//                if (isEnteringData)
//                {
//                    DrawCircle(activeNode->h, activeNode->k, num);
//                } else
//                {
//                    sprintf(c, "%d", num);
//                    SetColor4d(66, 66, 66, 1);
//                    DrawBitmapString(c, SCREEN_WIDTH / 2 - 110, 60, 0);
//                }
//
//                break;
//
//            default:
//                num = 0;
//                break;
//        }
//    } else if (gameMode != 3)
//    {
//        DrawBitmapString(
//                "Well Played. Your concepts of Tree Traversal are really strong! No option left. Tree completed", 30,
//                SCREEN_HEIGHT - 10, 0);
//    } else if (gameMode == 3)
//    {
//        DrawBitmapString("No option left. Tree completed", 30,
//                         SCREEN_HEIGHT - 10, 0);
//    }
//}
//
//void ChooseGameType()
//{
//    char temp;
//
//    do
//    {
//        printf("\nSelect the Game Type: \n");
//        printf("1. Value of tree nodes should increase in Preorder\n");
//        printf("2. Value of tree nodes should increase in Inorder\n");
//        printf("3. Value of tree nodes should increase in Postorder\n");
//
//        scanf(" %c", &temp);
//        gameType = temp - '0';
//
//    } while (!(gameType == 1 || gameType == 2 || gameType == 3));
//}
//
//void ChooseNoOfPlayers()
//{
//    char temp;
//    int i, t;
//
//    printf("\nWelcome!\n");
//
//    do
//    {
//        printf("Press\n1. For Single Player\n2. For Multi Player\n3. For Tutorial\n");
//        scanf("%c", &temp);
//        gameMode = temp - '0';
//
//    } while (!(gameMode == 1 || gameMode == 2 || gameMode == 3 || gameMode == 4));
//
////    if (gameMode == 4)
////    {
////        printf("\nEnter Tree Size:\n");
////        scanf("%d", &treeSize);
////
////        printf("\nEnter Inorder Traversal: \n");
////
////        for (i = 0; i < treeSize; ++i)
////        {
////            scanf("%d", &t);
////            inorder[i] = t;
////        }
////
////        printf("\nEnter Postorder Traversal: \n");
////
////        for (i = 0; i < treeSize; ++i)
////        {
////            scanf("%d", &t);
////            preorder[i] = t;
////        }
////    }
//}
//
//void OpenGLInit()
//{
//    int argc = 0;
//    char **argv = NULL;
//
//    glutInit(&argc, argv);
//    glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
//    glutInitWindowPosition(0, 0);
//
//    winID = glutCreateWindow("Treeversal");
//    gluOrtho2D(0, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
//
//    glutDisplayFunc(Display);
//    glutKeyboardUpFunc(keyUp);
//
//    glClearColor(255 / 255.f, 255 / 255.f, 255 / 255.f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//
//    if (gameMode == 3)
//    {
//        root->data = optionNums[1];
//        optionNums[1] = -1;
//
//        ClearInstructions();
//        ClearTree();
//        TraversePreorderAndDraw(root);
//        DrawCircle(root->h, root->k, root->data);
//
//        if (gameType == 1)
//        {
//            CheckPreorder(root);
//        }
//        if (gameType == 2)
//        {
//            CheckInorder(root);
//        }
//        if (gameType == 3)
//        {
//            CheckPostorder(root);
//        }
//
//        ShowTutorialExplanation(30, SCREEN_HEIGHT - 10, root->data, 0);
//
//        ShowTreeAndTutorialText();
//    }
//
//    glutMainLoop();
//}
//
//int main()
//{
//    lastOptionalNumberIndex = numOptions - 1;
//    srand((unsigned int) time(0));
//    ResetPotentialNumbers();
//    FillOptions();
//    PlantTree(0);
//
//    ChooseNoOfPlayers();
//    ChooseGameType();
//    OpenGLInit();
//
//    return 0;
//}


#include<windows.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include <iostream>
#include <list>
using namespace std;

int ver,flag=0;
int map[14];
list<int> *adList;
string colorSet[3] = {"Red","Green","Blue"};

void Text(char c[], double x, double y, double z)
{glRasterPos3d(x, y, z);
    int i;
    for(i=0;c[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,c[i]);
}
void Text1(char c[], double x, double y, double z)
{glRasterPos3d(x, y, z);
    int i;
    for(i=0;c[i]!='\0';i++)
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_10,c[i]);
}

//class makeGraph
//{

//public:
void createEdge(int v1, int v2)
{
    adList[v1].push_back(v2);
    adList[v2].push_back(v1);  // We can go either way on an edge, not directed
}
void addEdges()
{
    createEdge(0,12);
    createEdge(0,8);
    createEdge(0,7);
    createEdge(7,6);
    createEdge(7,9);
    createEdge(8,12);
    createEdge(5,13);
    createEdge(13,12);
    createEdge(3,13);
    createEdge(1,4);
    createEdge(1,2);
    createEdge(8,10);
    createEdge(10,11);
}

//void makeGraph::createEdge(int v1, int v2)


//void makeGraph::colorTheMap()
void colorTheMap()
{
    //Array with with vertices, to store value of colour each vertex gets

    map[0] = 0;

    // -1 = NO COLOR, 0 = RED, 1 = GREEN, 2 = BLUE

    for(int i = 1; i < ver; i++)
        map[i] = -1;

    int color[3];  // 3 colours are available R,G,B

    for(int j = 0; j < 3; j++)
        color[j] = -1;  // -1 means that color is "not assigned" to an adjacent vertex
    //  1 means that the color is "assigned" to an adjacent vertex
    for(int x = 1; x < ver; x++)
    {
        list<int>::iterator i;
        for(i = adList[x].begin(); i != adList[x].end(); i++)
            if (map[*i] != -1)  // if the vertex is assigned a color
                color[map[*i]] = 1; // set the color as assigned

        int avl;
        for(avl = 0; avl < 3; avl++)
            if (color[avl] == -1) // search for available color;
                break;

        map[x] = avl;

        for(i = adList[x].begin(); i != adList[x].end(); i++ )
            if(map[*i] != -1)
                color[map[*i]] = -1;
    }

    for(int i = 0; i < ver; i++)
        cout << "Block: " << i << "  is colored " << colorSet[map[i]] << endl;

}

void makeGraph(int V)
{
    ver = V;
    adList = new list<int>[V];

    addEdges();

    colorTheMap();
}
//void addEdges();

// void createEdge( int v1, int v2);  // Create an edge of graph

//void colorTheMap();

//};

//void makeGraph::addEdges()

void Key(unsigned char key, int x, int y)
{
    if(key=='S' || key =='s')
    {
//cout<<"s pressed"<<endl;
        flag=1;
        glutPostRedisplay();
    }
}
void Map()
{glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);  //1st Block
    glVertex2f(295,50);
    glVertex2f(445,50);
    glVertex2f(445,125);
    glVertex2f(295,125);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);  //1st Block
    glVertex2f(295,50);
    glVertex2f(445,50);
    glVertex2f(445,125);
    glVertex2f(295,125);
    glEnd();
    Text("1",365,95, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//4th Block
    glVertex2f(215,87);
    glVertex2f(295,87);
    glVertex2f(295,167);
    glVertex2f(215,167);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//4th Block
    glVertex2f(215,87);
    glVertex2f(295,87);
    glVertex2f(295,167);
    glVertex2f(215,167);
    glEnd();
    Text("4",250,132, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//2nd Block
    glVertex2f(445,87);
    glVertex2f(525,87);
    glVertex2f(525,167);
    glVertex2f(445,167);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//2nd Block
    glVertex2f(445,87);
    glVertex2f(525,87);
    glVertex2f(525,167);
    glVertex2f(445,167);
    glEnd();
    Text("2",480,132, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//5th Block
    glVertex2f(215,167);
    glVertex2f(295,167);
    glVertex2f(295,247);
    glVertex2f(215,247);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//5th Block
    glVertex2f(215,167);
    glVertex2f(295,167);
    glVertex2f(295,247);
    glVertex2f(215,247);
    glEnd();
    Text("5",250,212, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//3rd Block
    glVertex2f(445,167);
    glVertex2f(525,167);
    glVertex2f(525,247);
    glVertex2f(445,247);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//3rd Block
    glVertex2f(445,167);
    glVertex2f(525,167);
    glVertex2f(525,247);
    glVertex2f(445,247);
    glEnd();
    Text("3",480,212, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//Cafeteria
    glVertex2f(295,207);
    glVertex2f(445,207);
    glVertex2f(445,282);
    glVertex2f(295,282);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//Cafeteria
    glVertex2f(295,207);
    glVertex2f(445,207);
    glVertex2f(445,282);
    glVertex2f(295,282);
    glEnd();
    Text("Cafeteria",335,250, 0);
    Text("(13)",355,270, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//NAT
    glVertex2f(370,282);
    glVertex2f(485,282);
    glVertex2f(485,357);
    glVertex2f(370,357);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//NAT
    glVertex2f(370,282);
    glVertex2f(485,282);
    glVertex2f(485,357);
    glVertex2f(370,357);
    glEnd();
    Text("NAT",410,325, 0);
    Text("(12)",412,345, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//8th Block
    glVertex2f(445,357);
    glVertex2f(525,357);
    glVertex2f(525,437);
    glVertex2f(445,437);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//8th Block
    glVertex2f(445,357);
    glVertex2f(525,357);
    glVertex2f(525,437);
    glVertex2f(445,437);
    glEnd();
    Text("8",480,405, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//10th Block
    glVertex2f(445,437);
    glVertex2f(525,437);
    glVertex2f(525,517);
    glVertex2f(445,517);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//10th Block
    glVertex2f(445,437);
    glVertex2f(525,437);
    glVertex2f(525,517);
    glVertex2f(445,517);
    glEnd();
    Text("10",475,480, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//11th Block
    glVertex2f(370,517);
    glVertex2f(525,517);
    glVertex2f(525,597);
    glVertex2f(370,597);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);//11th Block
    glVertex2f(370,517);
    glVertex2f(525,517);
    glVertex2f(525,517);
    glVertex2f(525,597);
    glVertex2f(525,597);
    glVertex2f(445,597);
    glEnd();
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//11th Block
    glVertex2f(370,597);
    glVertex2f(445,597);
    glVertex2f(445,737);
    glVertex2f(370,737);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);//11th Block
    glVertex2f(445,597);
    glVertex2f(445,737);
    glVertex2f(445,737);
    glVertex2f(370,737);
    glVertex2f(370,737);
    glVertex2f(370,517);
    glEnd();
    Text("11",400,610, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//GC
    glVertex2f(485,270);
    glVertex2f(590,270);
    glVertex2f(590,357);
    glVertex2f(485,357);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//GC
    glVertex2f(485,270);
    glVertex2f(590,270);
    glVertex2f(590,357);
    glVertex2f(485,357);
    glEnd();
    Text("GC",525,320, 0);
    Text("(0)",527,340, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//7th Block
    glVertex2f(560,270);
    glVertex2f(640,270);
    glVertex2f(640,165);
    glVertex2f(560,165);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//7th Block
    glVertex2f(560,270);
    glVertex2f(640,270);
    glVertex2f(640,165);
    glVertex2f(560,165);
    glEnd();
    Text("7",595,220, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//6th Block
    glVertex2f(560,165);
    glVertex2f(640,165);
    glVertex2f(640,60);
    glVertex2f(560,60);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//6th Block
    glVertex2f(560,165);
    glVertex2f(640,165);
    glVertex2f(640,60);
    glVertex2f(560,60);
    glEnd();
    Text("6",595,115, 0);
    glColor3f(0.658,0.658,0.658);
    glBegin(GL_POLYGON);//9th Block
    glVertex2f(640,290);
    glVertex2f(720,290);
    glVertex2f(720,165);
    glVertex2f(640,165);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//9th Block
    glVertex2f(640,290);
    glVertex2f(720,290);
    glVertex2f(720,165);
    glVertex2f(640,165);
    glEnd();
    Text("9",675,230, 0);
    /*glBegin(GL_POINTS);//LYGON);//2nd Block
     glVertex2f(315,137);
     glVertex2f(395,137);
     glVertex2f(395,287);
     glVertex2f(315,287);
    glEnd();*/

    glFlush();
}

void ColoredMap()
{
    if(colorSet[map[1]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[1]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[1]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);  //1st Block
    glVertex2f(295,50);
    glVertex2f(445,50);
    glVertex2f(445,125);
    glVertex2f(295,125);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);  //1st Block
    glVertex2f(295,50);
    glVertex2f(445,50);
    glVertex2f(445,125);
    glVertex2f(295,125);
    glEnd();
    Text("1",365,95, 0);
    if(colorSet[map[4]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[4]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[4]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//4th Block
    glVertex2f(215,87);
    glVertex2f(295,87);
    glVertex2f(295,167);
    glVertex2f(215,167);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//4th Block
    glVertex2f(215,87);
    glVertex2f(295,87);
    glVertex2f(295,167);
    glVertex2f(215,167);
    glEnd();
    Text("4",250,132, 0);
    if(colorSet[map[2]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[2]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[2]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//2nd Block
    glVertex2f(445,87);
    glVertex2f(525,87);
    glVertex2f(525,167);
    glVertex2f(445,167);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//2nd Block
    glVertex2f(445,87);
    glVertex2f(525,87);
    glVertex2f(525,167);
    glVertex2f(445,167);
    glEnd();
    Text("2",480,132, 0);
    if(colorSet[map[5]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[5]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[5]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//5th Block
    glVertex2f(215,167);
    glVertex2f(295,167);
    glVertex2f(295,247);
    glVertex2f(215,247);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//5th Block
    glVertex2f(215,167);
    glVertex2f(295,167);
    glVertex2f(295,247);
    glVertex2f(215,247);
    glEnd();
    Text("5",250,212, 0);
    if(colorSet[map[3]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[3]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[3]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//3rd Block
    glVertex2f(445,167);
    glVertex2f(525,167);
    glVertex2f(525,247);
    glVertex2f(445,247);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//3rd Block
    glVertex2f(445,167);
    glVertex2f(525,167);
    glVertex2f(525,247);
    glVertex2f(445,247);
    glEnd();
    Text("3",480,212, 0);
    if(colorSet[map[13]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[13]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[13]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//Cafeteria
    glVertex2f(295,207);
    glVertex2f(445,207);
    glVertex2f(445,282);
    glVertex2f(295,282);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//Cafeteria
    glVertex2f(295,207);
    glVertex2f(445,207);
    glVertex2f(445,282);
    glVertex2f(295,282);
    glEnd();
    Text("Cafeteria",335,250, 0);
    Text("(13)",355,270, 0);
    if(colorSet[map[12]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[12]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[12]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//NAT
    glVertex2f(370,282);
    glVertex2f(485,282);
    glVertex2f(485,357);
    glVertex2f(370,357);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//NAT
    glVertex2f(370,282);
    glVertex2f(485,282);
    glVertex2f(485,357);
    glVertex2f(370,357);
    glEnd();
    Text("NAT",410,325, 0);
    Text("(12)",412,345, 0);
    if(colorSet[map[8]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[8]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[8]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//8th Block
    glVertex2f(445,357);
    glVertex2f(525,357);
    glVertex2f(525,437);
    glVertex2f(445,437);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//8th Block
    glVertex2f(445,357);
    glVertex2f(525,357);
    glVertex2f(525,437);
    glVertex2f(445,437);
    glEnd();
    Text("8",480,405, 0);
    if(colorSet[map[10]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[10]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[10]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//10th Block
    glVertex2f(445,437);
    glVertex2f(525,437);
    glVertex2f(525,517);
    glVertex2f(445,517);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//10th Block
    glVertex2f(445,437);
    glVertex2f(525,437);
    glVertex2f(525,517);
    glVertex2f(445,517);
    glEnd();
    Text("10",475,480, 0);
    if(colorSet[map[11]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[11]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[11]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//11th Block
    glVertex2f(370,517);
    glVertex2f(525,517);
    glVertex2f(525,597);
    glVertex2f(370,597);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);//11th Block
    glVertex2f(370,517);
    glVertex2f(525,517);
    glVertex2f(525,517);
    glVertex2f(525,597);
    glVertex2f(525,597);
    glVertex2f(445,597);
    glEnd();
    if(colorSet[map[11]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[11]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[11]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//11th Block
    glVertex2f(370,597);
    glVertex2f(445,597);
    glVertex2f(445,737);
    glVertex2f(370,737);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINES);//11th Block
    glVertex2f(445,597);
    glVertex2f(445,737);
    glVertex2f(445,737);
    glVertex2f(370,737);
    glVertex2f(370,737);
    glVertex2f(370,517);
    glEnd();
    Text("11",400,610, 0);
    if(colorSet[map[0]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[0]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[0]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//GC
    glVertex2f(485,270);
    glVertex2f(590,270);
    glVertex2f(590,357);
    glVertex2f(485,357);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//GC
    glVertex2f(485,270);
    glVertex2f(590,270);
    glVertex2f(590,357);
    glVertex2f(485,357);
    glEnd();
    Text("GC",525,320, 0);
    Text("(0)",527,340, 0);
    if(colorSet[map[7]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[7]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[7]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//7th Block
    glVertex2f(560,270);
    glVertex2f(640,270);
    glVertex2f(640,165);
    glVertex2f(560,165);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//7th Block
    glVertex2f(560,270);
    glVertex2f(640,270);
    glVertex2f(640,165);
    glVertex2f(560,165);
    glEnd();
    Text("7",595,220, 0);
    if(colorSet[map[6]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[6]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[6]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//6th Block
    glVertex2f(560,165);
    glVertex2f(640,165);
    glVertex2f(640,60);
    glVertex2f(560,60);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//6th Block
    glVertex2f(560,165);
    glVertex2f(640,165);
    glVertex2f(640,60);
    glVertex2f(560,60);
    glEnd();
    Text("6",595,115, 0);
    if(colorSet[map[9]]=="Red")
        glColor3f(1,0,0);
    else if(colorSet[map[9]]=="Green")
        glColor3f(0,1,0);
    else if(colorSet[map[9]]=="Blue")
        glColor3f(0,0,1);
    glBegin(GL_POLYGON);//9th Block
    glVertex2f(640,290);
    glVertex2f(720,290);
    glVertex2f(720,165);
    glVertex2f(640,165);
    glEnd();
    glColor3f(0,0,0);
    glBegin(GL_LINE_LOOP);//9th Block
    glVertex2f(640,290);
    glVertex2f(720,290);
    glVertex2f(720,165);
    glVertex2f(640,165);
    glEnd();
    Text("9",675,230, 0);
    /*glBegin(GL_POINTS);//LYGON);//2nd Block
     glVertex2f(315,137);
     glVertex2f(395,137);
     glVertex2f(395,287);
     glVertex2f(315,287);
    glEnd();*/

    glFlush();
}


void Show()
{glPointSize(5);
    glClearColor(0.909,0.909,0.909,0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    if(flag==0)
        Map();
    else
        ColoredMap();

}

int main(int argc,char *argv[])
{glutInit(&argc,argv);
    glutInitWindowSize(1024,768);
    glutCreateWindow("UPES Map");
    gluOrtho2D(0,1024,768,0);
    makeGraph(14);
    glutDisplayFunc(Show);
    glutKeyboardFunc(Key);
    glutMainLoop();
    return 0;
}
