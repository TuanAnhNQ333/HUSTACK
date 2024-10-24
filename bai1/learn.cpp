
#include <iostream>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    vector<int> v(3,100);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(5);
    vector<int>::iterator it = v.begin() + 4;
    cout << * it << endl;

    int n; cin >>n;
    vector<int> b(n);         
    for(int i = 0; i < n; i ++) {
        int tmp; cin >> tmp;
        v.push_back(tmp);
    }
    for(int x : b) cout << x << ' ';
    for(int i = 0; i < n; i ++) {
        cin >> v[i];
    }
    vector<int>::iterator it = v.begin();
    v.insert(v.begin() + 2, 100);
    
}
 
