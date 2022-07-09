
#include <iostream>
using namespace std;
class DisjointSet {
int *rank, *parent, n;

public:
DisjointSet(int n)
{
rank = new int[n];
parent = new int[n];
this->n = n;
make_set();
}

void make_set()
{
for (int i = 0; i < n; i++) {
parent[i] = i;
}
}

// Finds set of given item x
int find_set(int x)
{
if (parent[x] != x) {

parent[x] = find_set(parent[x]);

}

return parent[x];
}

void Union(int x, int y)
{
int xset = find_set(x);
int yset = find_set(y);

if (xset == yset)
return;

if (rank[xset] < rank[yset]) {
parent[xset] = yset;
}
else if (rank[xset] > rank[yset]) {
parent[yset] = xset;
}

else {
parent[yset] = xset;
rank[xset] = rank[xset] + 1;
}
}
};

int main()
{
DisjointSet obj(5);
obj.Union(0, 2);
obj.Union(4, 2);
obj.Union(3, 1);
if (obj.find_set(4) == obj.find_set(0))
cout << "Yes\n";
else
cout << "No\n";
if (obj.find_set(1) == obj.find_set(0))
cout << "Yes\n";
else
cout << "No\n";

return 0;
}
