#include<bits/stdc++.h>
using namespace std;
bool queencanbeplaced(vector<string>&temp, int row, int col) {
    
    for(int i = 0; i < col; ++i) {
        if(temp[row][col]=='Q')
            return false;
    }
    
    for(int i = 0; i < row; ++i) {
        if(temp[i][col] == 'Q')
            return false;
    }
    
    int a = row - 1,b = col - 1;
    while(a >= 0 && b >= 0) {
        if(temp[a][b] == 'Q')
            return false;
        --a;
        --b;
    }
    
    a = row-1;
    b = col+1;
    while(a >= 0 && b < temp.size()) {
        if(temp[a][b] == 'Q')
            return false;
        --a;
        ++b;
    }
    return true;
}
void solveNqueens(vector<vector<string>>&res, vector<string>&temp, int row, int queens) {
    if(row == (int)temp.size() && queens == 0) {
        res.push_back(temp);
        return;
    }
    else {
        for(int i = 0; i < (int)temp.size(); ++i) {
            if(queencanbeplaced(temp,row,i)) {
                temp[row][i] = 'Q';
                solveNqueens(res,temp,row+1,queens-1);
                temp[row][i] = '.';
            }
        }
    }
    return;
}
vector<vector<string>> solveNqueens(int n) {
    vector<vector<string>>res;
    vector<string>temp(n,string(n,'.'));
    solveNqueens(res,temp,0,n);
    return res;
}


int main() {
    
    int n;
    cin>>n;
    
    vector<vector<string>>ans;
    ans = solveNqueens(n);
    
    for(int i = 0; i < ans.size(); ++i) {
        cout<<"Answer "<<i+1<<" :"<<endl;
        for(int j = 0; j < n; ++j) {
            cout<<ans[i][j]<<endl;
        }
    }
}