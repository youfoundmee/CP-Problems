#include <iostream>
#include <set>
#include <vector>
using namespace std;

#define nl endl

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int t = 1;
    cin >> t;
    
    while (t--) {
        long long n, k;
        cin >> n >> k;
        
        set<int> st;
        vector<int> vt(n, 0);

        for (int i = 1; i <= n; ++i) {
            st.insert(i);
        }
        
        int lim = n / k;
        int pos = k-1;  
        
        while (lim--) {
            vt[pos] = *st.begin();
            st.erase(st.begin());  
            pos += k; 
        }

        for (int i = 0; i < n; ++i) {
            if (vt[i] == 0) {
                vt[i] = *st.begin();  
                st.erase(st.begin());  
            }
        }

        for (int i = 0; i < n; ++i) {
            cout << vt[i] << " ";
        }
        cout << nl;
    
}
}
