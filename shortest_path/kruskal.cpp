#include <iostream>
#include <algorithm>
using namespace std;
// 교재데이터
// vertex = 7
// edge = 5
// 1 2 1
// 3 5 2
// 1 3 3
// 2 3 3
// 3 4 4
// 4 5 5
// 2 4 6

// 자작데이터
// vertex = 7
// edge = 5
// 1 2 1
// 2 5 3
// 1 3 7
// 2 3 5
// 2 4 4
// 4 5 2
// 3 5 6



typedef struct nodetype{// 부모와 그것의 깊이를 나타내는 구조체
    int parent;
    int depth;
}nodetype;

typedef struct Edge{//v의 출발점과 도착점, 그에대한 가중치를 나타내는 구조체
    int pair[2];
    int weight;
}Edge;

int compare(const void* a,const void* b){// sort함수를 사용하기 위해 필요한 비교 함수 (가중치 비교)
	Edge *edgeA = (Edge *)a;
    Edge *edgeB = (Edge *)b;
    return ((edgeB->weight < edgeA->weight)-(edgeB->weight > edgeA->weight));
}

void makeset(int i,nodetype* U){// 배열의 부모와 깊이 초기값 설정

    U[i].parent = i;
    U[i].depth = 0;
}

void initial(int n, nodetype* U){// 배열 초기화

    int i;
    for(i = 1; i<=n;i++){
        makeset(i,U);
    }
}

int find(int i,nodetype* U){// 각 배열의 부모값을 갱신하는 함수
    int j;
    j = i;
    while(U[i].parent!=j) 
        j = U[j].parent;
    return j;
}

void merge(int p, int q, nodetype* U){// 배열을 합병시키는 함수
    if(U[p].depth == U[q].depth){
        U[p].depth +=1; // depth: 노드가 몇개 연결되어있는지 알려줌 
        U[q].parent = p; // P(root가 되는 노드를 parent에 저장)
    } else if(U[p].depth<U[q].depth) U[p].parent = q; // q의 depth가 더 크면(= q에 연결되어있는 노드의 개수가 더 많으면) q(parent값)를 p의 parent에 넣음 
    else U[q].parent = p;

    for(int i=1;i<=5;i++){
        cout<<U[i].parent<<"\t";
    }
    cout<<"\n";

    for(int i=1;i<=5;i++){
        cout<<U[i].depth<<"\t";
    }
    cout<<"\n";
}
    
bool equals(int p, int q){
    if(p==q) return true;
    else return false; 
}   


void kruskal(int n, int m, Edge* E, Edge* F){
    int i, j;
    int k =0;
    int p, q;
    int count=1;
    nodetype* U = new nodetype[n+1];// vertex의 수만큼 할당
    Edge edge;
    qsort(E,n,sizeof(Edge),compare);// 정렬 알고리즘 

    initial(n,U);

    while(count<n-1){
        edge = E[k];
        i = E[k].pair[0];
        j = E[k].pair[1];
        p = find(i,U);
        q = find(j,U);

        if(!equals(p,q)){
            merge(p,q,U);
            F[count] = edge; 
            count++;
        }
        k++; 
    }



}

int main(void){
    int n, m;
    cout<<"vertex의 개수를 입력하세요: ";
    cin>>n;
    cout<<"edge의 개수를 입력하세요: ";
    cin>>m;

    Edge* F = new Edge[m+1];
    Edge* E = new Edge[m+1];

    cout<<"\n";
    cout<<"vertex의 숫자와 그의 가중치를 입력하세요."<<"\n";
    for(int i=1;i<=n;i++){
        cin>>E[i].pair[0];
        cin>>E[i].pair[1];
        cin>>E[i].weight;
    }

    kruskal(n,m,E,F);
    cout<<"\n";
    cout<<"F"<<endl;
    for(int i=1;i<m;i++){
        cout<<F[i].pair[0]<<"\t"<<F[i].pair[1]<<"\t"<<F[i].weight<<"\n";
    }

}