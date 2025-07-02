#include <iostream>
#include <string>
using namespace std;

// Function to build LPS array
void constructLps(string &pat, int lps[]) {
    int len = 0;
    lps[0] = 0;  // lps[0] is always 0

    int i = 1;
    while (i < pat.length()) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];  // Avoid rechecking
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// Search function returns match positions in res[], resCount = number of matches
void search(string &pat, string &txt, int res[], int &resCount) {
    int n = txt.length();
    int m = pat.length();
    int lps[100];  // Assuming max pattern length = 100

    constructLps(pat, lps);

    int i = 0; // index for txt
    int j = 0; // index for pat
    resCount = 0;

    while (i < n) {
        if (txt[i] == pat[j]) {
            i++;
            j++;

            if (j == m) {
                res[resCount++] = i - j;
                j = lps[j - 1];  // Continue searching
            }
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
}

// Main function
int main() {
    string txt;
    string pat;
    cout<<"Enter the txt"<<endl;
    cin>>txt;

    cout<<"Enter the pattern"<<endl;
    cin>>pat;

    int res[100];      // Assuming max 100 matches
    int resCount = 0;  // Number of matches found

    search(pat, txt, res, resCount);

    for (int i = 0; i < resCount; i++) {
        cout << res[i] << " ";
    }

    return 0;
}
