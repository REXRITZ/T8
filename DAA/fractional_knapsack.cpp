#include <bits/stdc++.h>
using namespace std;
#define loop(i,n) for (int i=0;i<n;++i)

bool cmp(double a, double b, double c, double d) {
    double x = c/a;
    double y = d/b;
    return x>y;
}
void bubblesort (vector<double>&val, vector<double>&wt, int n) {
    
    for(int i=0;i<n-1;++i) {
        for(int j=i+1;j<n;++j) {
            if(cmp(wt[i],wt[j],val[i],val[j])) {
                swap(wt[i],wt[j]);
                swap(val[i],val[j]);
            }
        }
    }
}

void knapsack(vector<double>val, vector<double>wt, vector<double>&ratio,int w,int n) {
    int i;
    for(i=0;i<n;++i) {
        if(w < wt[i])
            break;
        ratio[i]=1.0;
        //cout<<w<<" ";
        w -= wt[i];
    }
    if(i<=n)
        ratio[i]=w/wt[i];
}

int main()
{
    int n,w;
    cout<<"\nEnter the total elements : ";
    cin>>n;
    vector<double>val(n);
    vector<double>wt(n);
    vector<double>ratio(n,0.0);
    cout<<"\nEnter the weight and profit : ";
    loop(i,n) {
        cin>>wt[i]>>val[i];
    }
    cout<<"\nEnter max weight : ";
    cin>>w;
    bubblesort(wt,val,n);
    knapsack(val,wt,ratio,w,n);
    double ans=0.0;
    cout<<"\nRatio array is : ";
    loop(i,n) cout<<ratio[i]<<" ";
    cout<<"\nWeights in knapsack are : ";
    loop(i,n) {
        if(ratio[i]>0.0) {
            cout<<wt[i]<<" ";
            ans += val[i]*ratio[i];
        }
    }
    cout<<"\nTotal profit is : ";
    cout<<ans;
}
