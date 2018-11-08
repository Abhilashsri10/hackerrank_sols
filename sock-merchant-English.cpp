#include <bits/stdc++.h>

using namespace std;

vector<string> split_string(string);
#define fr(i,a,b) for(int i=a;i<b;i++)

int sockMerchant(int n, vector<int> ar) {
    int count,main_c=0;//,reg=0;
    /*O(n2)
    set<int> s;
    for(auto c:ar){
        s.insert(c);
    }
    for(set<int>::iterator it=s.begin();it!=s.end();++it){
        count=0;
        for(auto u:ar){
            if(u==*it)
                count++;
        }
        if(count>0)
            main_c+=count/2;
    }
    return main_c;
    */
    //O(n)
    multiset<int> s;
    set<int> s1;
    for(auto u:ar){
        s.insert(u);
        s1.insert(u);
    }
    for(set<int>::iterator it=s1.begin();it!=s1.end();++it){
        if(s.count(*it)>1){
            main_c+=(s.count(*it))/2;
        }
    }
    return main_c;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int n;
    cin >> n;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string ar_temp_temp;
    getline(cin, ar_temp_temp);

    vector<string> ar_temp = split_string(ar_temp_temp);

    vector<int> ar(n);

    for (int i = 0; i < n; i++) {
        int ar_item = stoi(ar_temp[i]);

        ar[i] = ar_item;
    }

    int result = sockMerchant(n, ar);

    fout << result << "\n";

    fout.close();

    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });

    input_string.erase(new_end, input_string.end());

    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }

    vector<string> splits;
    char delimiter = ' ';

    size_t i = 0;
    size_t pos = input_string.find(delimiter);

    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));

        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }

    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

    return splits;
}
