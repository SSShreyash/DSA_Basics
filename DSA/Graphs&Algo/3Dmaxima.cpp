#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<chrono>

class Points{
    public:
        int x;
        int y;
        int z;
};

/*
void Maximal(vector<Points>& P, int n){
    for(int i=1; i<=n; i++){
        bool maximal = true;
        for(int j=1; j<=n; j++){
            if( (i!=j) && (P[j].x >= P[i].x) && (P[j].y >= P[i].y) && (P[j].z >= P[i].z) ){
                maximal = false;
                break;
            }
        }

        if(maximal){
            //cout<<P[i].x<<", "<<P[i].y<<", "<<P[i].z;
            //cout<<endl;
        }
    }
}
*/

int main(){

    int n;
    cin >> n;
    vector<Points> P(n+1);
    vector<int> X;
    vector<int> Y;
    vector<int> Z;

    for(int k=1; k<=n; k++){
        cin>>P[k].x;
        cin>>P[k].y;
        cin>>P[k].z;
        X[k] = P[k].x;
        Y[k] = P[k].y;
        Z[k] = P[k].z;
    }

//    Maximal(P,n);             //O(n^2) time complexity.               


//Maximal algorithm in O(nlogn) time complexity...using sorting.
/*
    auto start = chrono :: steady_clock :: now();

    bool maxima;
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());
    sort(Z.begin(), Z.end());

    int Xmax = X[n];
    int Ymax = Y[n];
    int Zmax = Z[n];

    for(int j=1; j<=n; j++){
        if((P[j].x  P[n].y && P[j].x >= P[n].z) || && P[j].y && P[j].z)){
            
            cout<<endl;
        }
    }

    auto stop = chrono :: steady_clock :: now();
    auto diff = stop - start;

    cout<<chrono::duration<double,milli>(diff).count()<<"ms";
*/
    return 0;
}
