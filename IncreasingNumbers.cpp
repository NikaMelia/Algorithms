#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>


using namespace std;

const int me = 1000025;

int T, N, L;
int a[me], ft[me];

void update(int pos, int value){
    for( ; pos < me; pos += (pos & -pos))
        ft[pos] = max(ft[pos], value);
}
int query(int pos){
    int s = 0;
    for( ; pos > 0; pos -= (pos & -pos))
        s = max(s, ft[pos]);
    return s;
}

int main(int argc, const char * argv[]) {
    
    cin>>T;
    while(T--){
        cin>>N;
        for(int i = 0; i < N; i ++){
            cin>>a[i];
            ++a[i];

        }
        cin>>L;
        fill(ft, ft + me, 0);
        int result = me;
        for(int i = 0; i < N; i ++){
            int g = query(a[i] - 1);
            update(a[i], g + 1);
            if(g + 1 >= L)
                result = min(result, a[i] - 1);
        }
        if(result == me)
            result = -1;
        cout<<result<<endl;
    }
    
    
    return 0;
}