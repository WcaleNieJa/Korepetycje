#include <bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;//n - liczba banknotow
    int W[n];
    int L[n];
    for (int i=0;i<n;i++){
        cin >> W[i];//wartosc
    }
    for (int i=0;i<n;i++){
        cin >> L[i];//liczba
    }
    vector <int> Osiagalne;
    int wo[20000]; //te co uzywam
    int wp[20000];//te co bez uzycia obecnej liczby
    int T[200][20000];//k,n
    int T2[200][20000];//k,n
    int k;
    cin >> k;
    for (int i=0;i<=k;i++){
            T2[0][i]=0;
            T[0][i]=0;
    }
    for (int i=1; i <=k;i++){
        wo[i]=-1;
    }
    Osiagalne.push_back(0);
    wo[0]=0;
    for (int i=0; i < n;i++){
        int z = Osiagalne.size();
        for (int t=0;t <= k;t++){
            wp[t]=wo[t];
        }
        for (int o=0;o<n;o++){
            for (int p=0;p <= k;p++){
                T2[o][p]=T[o][p];
            }
        }
        for (int h=0; h < z;h++){
                for (int j=1; j <= L[i];j++){
                    if(j*W[i]+Osiagalne[h] <= k){
                        if(wo[j*W[i]+Osiagalne[h]]!=-1){
                                if (wo[j*W[i]+Osiagalne[h]]>wp[Osiagalne[h]]+j){
                                    wo[j*W[i]+Osiagalne[h]]=wp[Osiagalne[h]]+j;
                                    for (int b=0;b < n;b++){
                                        T[j*W[i]+Osiagalne[h]][b]=T2[Osiagalne[h]][b];
                                    }
                                    T[j*W[i]+Osiagalne[h]][i]=T2[j*W[i]+Osiagalne[h]][i]+j;
                                }
                        }else{
                            Osiagalne.push_back(j*W[i]+Osiagalne[h]);
                            wo[j*W[i]+Osiagalne[h]]= wp[Osiagalne[h]]+j;
                            for (int b=0;b < n;b++){
                                    T[j*W[i]+Osiagalne[h]][b]=T2[Osiagalne[h]][b];
                                }
                            T[j*W[i]+Osiagalne[h]][i]=T2[j*W[i]+Osiagalne[h]][i]+j;
                        }
                    }

                }
        }

    }
    cout << wo[k];
    cout <<'\n';
    for (int i=0; i < n;i++){
        cout << T[k][i] << " ";
    }







    }
