#include <bits/stdc++.h>
using namespace std;

void creat_table(vector<double> X,vector<double> y,int n, vector<vector<double> > &res){
    for (int i = 1; i < n; i++){
        for (int j = 0; j < n - i; j++){
        	if (i==0)
        		res[i][j]=y[j];
        	else
				res[i][j] = (res[i-1][j+1] - res[i-1][j])/(X[i+j] - X[j]);
        }
    }
}

void print_table_newton(vector<vector<double> > tb_n, int n){
    cout << "Table: " << endl;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i; j++){
            cout << tb_n[i][j] << "  ";
        }
        cout << endl;
    }
    cout << endl;
}

double solve(double _x, vector<vector<double> >table_newton,vector<double> x){
    double giatri=table_newton[0][0];
    double tam=1;
    for (int i=1;i<table_newton.size();i++){
        tam*=(_x-x[i-1]);
        giatri+=table_newton[i][0]*tam;
    }
    return giatri;
}

int main() {

    freopen("INP.TXT","r",stdin);
    freopen("OUT.TXT","w",stdout);
    int n;
    double _x,__x;

    cin >> n;

    vector<double> X(n),
        Y(n);
    vector<vector<double> >table_newton(n, vector<double>(n, 0));

    for (int i = 0; i < n; i++){
        cin >> X[i] >> Y[i];
        table_newton[0][i] = Y[i];
    }

    cin >> _x>>__x;

    creat_table(X,Y, n, table_newton);


    cout << solve(_x, table_newton,X)*solve(__x,table_newton,X) << endl;

    return 0;
}
