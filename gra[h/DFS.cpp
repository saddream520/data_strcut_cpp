#include<iostream>
#include<string>
using namespace std;
#define maxsize 100
class graph{
    struct mat_Grphnode
    {
        char *vertes;
        int **arc;
        int vexnum,arcnum;
    };
    mat_Grphnode *G;
    int *visited;
public:
    graph(int vexnum,int arcnum)
    {
        // 这个初始化函数给予初始的顶点数和边数，创建了一个初始矩阵
        G=new mat_Grphnode;
        // G->vexnum=vexnum;
        this->G->vexnum=vexnum;
        this->G->arcnum=arcnum;
        this->G->vertes=new char[maxsize];
        this->visited=new int[maxsize]();
        this->G->arc=new int*[maxsize];//给予行指针100
        for(int i=0;i<maxsize;i++)
            this->G->arc[i]=new int[maxsize];//给予每行100列，做到100*100
    }
    void create_graph(mat_Grphnode *G)
    {
        cout<<"请输入顶点信息："<<endl;
        for(int i=0;i<G->vexnum;i++)
            cin>>G->vertes[i];
        cout<<"请输入边的信息："<<endl;
        for(int i=0;i<G->arcnum;i++)
        {
            int v1,v2;
            cin>>v1>>v2;
            G->arc[v1][v2]=1;
            G->arc[v2][v1]=1;
            // 对角线对称赋值
        }
    }
    void create_graph_origin()
    {
        G->vertes[0]='A';
        G->vertes[1]='B';
        G->vertes[2]='C';
        G->vertes[3]='D';
        G->vertes[4]='E';
        G->vertes[5]='F';
        G->vertes[6]='G';
        G->vertes[7]='H';
        G->vertes[8]='I';
        for(int i = 0;i<G->vexnum;i++)
        { 
            for(int j = 0;j<G->vexnum;j++)
            {
                G->arc[i][j]=0;
            }
        }
        //A-B A-F
        G->arc[0][1]=1;
        G->arc[0][5]=1;

        //B-C B-G B-I
        G->arc[1][2]=1;
        G->arc[1][6]=1;
        G->arc[1][8]=1;

        // C-D C-G
        G->arc[2][3]=1;
        G->arc[2][6]=1;//错

        // D-E D-G D-H D-I
        G->arc[3][4]=1;
        G->arc[3][6]=1;
        G->arc[3][7]=1;
        G->arc[3][8]=1;

        // E-F E-H
        G->arc[4][5]=1;
        G->arc[4][7]=1;

        // F-G
        G->arc[5][6]=1;

        // G-H
        G->arc[6][7]=1;

        // 无向图的对称
        for(int i =0;i<G->vexnum;i++)
        {
            for(int j=0;j<G->vexnum;j++)
            {
                G->arc[j][i]=G->arc[i][j];
            }
        }
    }
    void DFS(int i)
    {
        visited[i]=1;
        cout<<G->vertes[i]<<endl;
        for(int j =0;j<G->vexnum;j++)
        {
            if(G->arc[i][j]==1 && visited[j]==0)//如果有边且未访问的顶点
            {
                DFS(j);
            }
        }
    }
};
int main()
{
    graph G(9,15);
    G.create_graph_origin();
    G.DFS(0);
    return 0;
}