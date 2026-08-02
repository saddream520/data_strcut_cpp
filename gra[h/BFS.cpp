#include<iostream>
#include<string>
#include<queue>
using namespace std;
#define maxsize 100
class graph
{
    struct mat_Grphnode
    {
        char* vertes;
        int** arc;
        int vexnum, arcnum;
    };
    int* visited;
    mat_Grphnode* G;

public:
    graph(int vexnum, int arcnum)
    {
        G = new mat_Grphnode;
        this->visited = new int[maxsize]();
        this->G->vertes = new char[maxsize];
        this->G->arc = new int* [maxsize];
        this->G->vexnum = vexnum;
        this->G->arcnum = arcnum;
        for (int i = 0; i < maxsize; i++)
        {
            this->G->arc[i] = new int[maxsize];
        }

    }
    void create_graph_origin()
    {
        G->vertes[0] = 'A';
        G->vertes[1] = 'B';
        G->vertes[2] = 'C';
        G->vertes[3] = 'D';
        G->vertes[4] = 'E';
        G->vertes[5] = 'F';
        G->vertes[6] = 'G';
        G->vertes[7] = 'H';
        G->vertes[8] = 'I';
        for (int i = 0; i < G->vexnum; i++)
        {
            for (int j = 0; j < G->vexnum; j++)
            {
                G->arc[i][j] = 0;
            }
        }
        //A-B A-F
        G->arc[0][1] = 1;
        G->arc[0][5] = 1;

        //B-C B-G B-I
        G->arc[1][2] = 1;
        G->arc[1][6] = 1;
        G->arc[1][8] = 1;

        // C-D C-G
        G->arc[2][3] = 1;
        G->arc[2][6] = 1;//错

        // D-E D-G D-H D-I
        G->arc[3][4] = 1;
        G->arc[3][6] = 1;
        G->arc[3][7] = 1;
        G->arc[3][8] = 1;

        // E-F E-H
        G->arc[4][5] = 1;
        G->arc[4][7] = 1;

        // F-G
        G->arc[5][6] = 1;

        // G-H
        G->arc[6][7] = 1;

        // 无向图的对称
        for (int i = 0; i < G->vexnum; i++)
        {
            for (int j = 0; j < G->vexnum; j++)
            {
                G->arc[j][i] = G->arc[i][j];
            }
        }
    }
    void BFS()
    {
        if (G == nullptr)
            return;
        int i = 0;
        visited[i] = 1;
        cout << G->vertes[i] << endl;
        queue<int>q;
        //载入初始根
        q.push(i);
        while (!q.empty())
        {
            //当前层（或者说矩阵行）已经遍历完，切换另外一个层根
            i = q.front();
            q.pop();
            for (int j = 0; j < G->vexnum; j++)
            {
                if (G->arc[i][j] == 1 && visited[j] == 0)
                    // 这个标记访问原理和DFS是一样的，都是为了防止重复访问
                {
                    visited[j] = 1;//找到未标记的，标记为一
                    cout << G->vertes[j] << endl;
                    q.push(j);//置入新层数
                   
                }
            }
        }

    }
};
int main()
{
    graph G(9, 15);
    G.create_graph_origin();
    G.BFS();
    return 0;
}