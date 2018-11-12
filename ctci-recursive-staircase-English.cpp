#include <bits/stdc++.h>

using namespace std;

// Complete the stepPerms function below.
#define fr(i,a,b) for(int i=a;i<b;i++)
#define pb push_back
vector<int> LUT(10001,0);
int stepPerms(int n) {
    if(LUT[n]!=0)
        return LUT[n];
    if(n>=3)
       LUT[n]=stepPerms(n-1)+stepPerms(n-2)+stepPerms(n-3); 
    else if(n==1 || n==2)
        return n;
    else
        return 1;        
    return LUT[n];
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int s;
    cin >> s;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int s_itr = 0; s_itr < s; s_itr++) {
        int n;
        cin >> n;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int res = stepPerms(n);

        fout << res << "\n";
    }

    fout.close();

    return 0;
}
