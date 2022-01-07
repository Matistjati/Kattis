#include <bits/stdc++.h>
//#include <bits/extc++.h>

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
#define vvvvi vector<vvvi>
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
#define read2(a,b) cin >> a >> b
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
#define first(a) (*begin(a))

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

#define NONE 0
#define INCREASING 1
#define DECREASING 2




int32_t main()
{
    fast();

#if 0
    ifstream cin("C:\\Users\\Matis\\source\\repos\\Comp prog\\x64\\Release\\in.txt");
#endif

    dread3(int, n, m, q);

    readvector(int, notes, n);

    vi illegalIntervals;

    int prev = notes[0];
    int prevBegin = 0;
    int state = 0;


    vp2 intervalsToProcess;
    vi indexMap(n);
    int index = 0;

    repp(i, 1, notes.size())
    {
        // Increase
        if (prev < notes[i])
        {
            if (state == DECREASING)
            {
                if (index - prevBegin >= m)
                {
                    intervalsToProcess.emplace_back(prevBegin, index);
                }
                prevBegin = index;
            }
            prev = notes[i];
            state = INCREASING;
            index++;
        }
        // Decreasing
        else if (prev > notes[i])
        {
            if (state == INCREASING)
            {
                if (index - prevBegin >= m)
                {
                    intervalsToProcess.emplace_back(prevBegin, index);
                }
                prevBegin = index;
            }
            prev = notes[i];
            state = DECREASING;
            index++;
        }
        indexMap[i] = index;
    }

    if (index - prevBegin >= m)
    {
        intervalsToProcess.emplace_back(prevBegin, index);
    }

    repe(interval, intervalsToProcess)
    {
        for (int i = interval.first; i+m <= interval.second; i++)
        {
            illegalIntervals.emplace_back(i);
        }
    }
    sort(all(illegalIntervals));

    while (q--)
    {
        bool works = true;
        dread2(int, left, right);
        left = indexMap[left-1];
        right = indexMap[right-1];

        auto it = lower_bound(all(illegalIntervals), left);

        if (it==illegalIntervals.end())
        {
            cout << "ja\n";
            continue;
        }

        if (*it+m <= right)
        {
            cout << "nej\n";
            continue;
        }
        cout << "ja\n";
    }


    quit;
}
