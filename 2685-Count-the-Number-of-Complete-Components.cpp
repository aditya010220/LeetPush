class DSU{
private:
    vector<int>par,sze,edge;
public:
    DSU(int n){
        par.resize(n+1);
        sze.resize(n+1,1);
        edge.resize(n+1);
        iota(par.begin(),par.end(),0);
    }

    int find(int x){
        if(x==par[x]) return x;
        return par[x]=find(par[x]);
    }

    void unite(int x, int y){
        x=find(x);
        y=find(y);
        if(x==y){
            edge[x]++;
            return;
        }
        par[y]=x;
        sze[x]+=sze[y];
        edge[x]+=edge[y]+1;
    }

    int getsz(int x){
        return sze[find(x)];
    }
    int getedge(int x){
        return edge[find(x)];
    }

};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        int m=edges.size();
        DSU ds(n);
        int cnt=0;
        for(int i=0;i<m;i++){
            ds.unite(edges[i][0],edges[i][1]);
        }
        for(int i=0;i<n;i++){
            if(ds.find(i)==i){
                if(ds.getedge(i)==((ds.getsz(i)*(ds.getsz(i)-1))/2)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};