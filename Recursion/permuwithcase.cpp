// CPP code to print all permutations
// with respect to cases
#include <bits/stdc++.h>
using namespace std;

// Function to generate permutations
void permute(string ip, string op)
{
    // base case
    if (ip.size() == 0) {
        cout << op << " ";
        return;
    }
    // pick lower and uppercase
    char ch = tolower(ip[0]);
    char ch2 = toupper(ip[0]);
    ip = ip.substr(1);

    permute(ip, op + ch);
    permute(ip, op + ch2);
}

// Driver code
int main()
{
    string ip = "aB";
    permute(ip, "");
    return 0;
}
