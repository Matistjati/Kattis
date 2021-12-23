#include <bits/stdc++.h>

using namespace std;

#pragma GCC target ("avx2")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")

#define enablell 0

#define ll long long
#if enablell
#define int ll
#endif
#define vi vector<int>
#define vb vector<bool>
#define vvb vector<vb>
#define vvvb vector<vvb>
#define vvi vector<vi>
#define vvvi vector<vvi>
#define p2 pair<int, int>
#define p3 tuple<int,int,int>
#define p4 tuple<int,int,int,int>
#define vp2 vector<p2>
#define vvp2 vector<vp2>
#define vp3 vector<p3>
#define vp4 vector<p4>
#if enablell
#define inf 1e18
#else
#define inf int(1e9)
#endif

#define read(a) cin >> a
#define write(a) cout << (a) << "\n"
#define quit cout << endl; _Exit(0);
#define dread(type, a) type a; cin >> a
#define dread2(type, a, b) dread(type, a); dread(type, b)
#define dread3(type, a, b, c) dread2(type, a, b); dread(type, c)
#define dread4(type, a, b, c, d) dread3(type, a, b, c); dread(type, d)
#define dread5(type, a, b, c, d, e) dread4(type, a, b, c, d); dread(type, e)
#ifdef _DEBUG
#define noop cout << "";
#define deb __debugbreak();
#else
#define noop ;
#define deb ;
#endif

#define rep(i, high) for (int i = 0; i < high; i++)
#define repp(i, low, high) for (int i = low; i < high; i++)
#define repe(i, container) for (auto& i : container)
#define per(i, high) for (int i = high; i >= 0; i--)
#define perr(i, low, high) for (int i = high; i >= low; i--)

#define readpush(type,vect) type temp; read(temp); vect.(temp);
#define readvector(type, name, size) vector<type> name(size); rep(i,size) {dread(type,temp); name[i]=temp;}
#define readinsert(type,a) {type temp; read(temp); a.insert(temp);}
#define all(a) begin(a),end(a)
#define setcontains(set, x) (set.find(x) != set.end())
#define stringcontains(str, x) (str.find(x) != string::npos)
#define within(a, b, c, d) (a >= 0 && a < b && c >= 0 && c < d)
#define insideinterval(v, interval) (v >= interval.first && v <= interval.second)
#define sz(container) ((int)container.size())
#define mp(a,b) (make_pair(a,b))

#define ceildiv(x,y) ((x + y - 1) / y)
#define fract(a) (a-floor(a))
#define sign(a) ((a>0) ? 1 : -1)

auto Start = chrono::high_resolution_clock::now();

inline void fast()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}

template <typename T, typename U>
void operator+=(std::pair<T, U>& l, const std::pair<T, U>& r)
{
    l = { l.first + r.first,l.second + r.second };
}

#define X 1
#define S 0

bool solve(vvvi& memo, string& state, int pos, int prev, int top)
{
    int& dp = memo[pos][prev][top];
    if (dp != -1) return dp;

    if (pos==state.size())
    {
        return true;
    }

    bool ret = false;
    if (state[pos] == 'X')
    {
        ret |= solve(memo, state, pos + 1, top, X);
        ret |= solve(memo, state, pos + 1, top, S);
    }
    else
    {
        int have = prev + top;
        if (pos > 0) have += (state[pos - 1] == 'X');
        if (pos + 1 < state.size()) have += (state[pos + 1] == 'X');
        int wanted = state[pos] - '0';
        if (have > wanted || wanted > have + 1 || (wanted == have + 1 && pos == state.size()-1))
        {
            return false;
        }
        else if (wanted == have + 1)
        {
            ret = solve(memo, state, pos + 1, top, X);
        }
        else
        {
            ret = solve(memo, state, pos + 1, top, S);
        }
    }

    return dp = ret;
}


int32_t main()
{
    fast();

#if 0
    ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Debug\\in.txt");
#endif

    dread(string, state);

    vvvi dp(state.size()+1, vvi(2, vi(2,-1)));

    bool possible = solve(dp, state, 0, 0, X) | solve(dp, state, 0, 0, S);

    if (!possible)
    {
        cout << "fel";
    }
    else
    {
        rep(i, state.size())
        {
            int mine = (dp[i][X][X] == 1 || dp[i][S][X] == 1);
            int safe = (dp[i][X][S] == 1 || dp[i][S][S] == 1);
            if (mine == 1 && safe == 0)
            {
                cout << 'X';
            }
            else if (safe == 1 && mine == 0)
            {
                cout << 'S';
            }
            else
            {
                cout << 'O';
            }
        }
    }

    quit;
}
