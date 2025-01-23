#include "Header.h"

int main() {
    char S[MAX];

    cin.getline(S, MAX);

    CharFrequency freq[52];
    for (int i = 0; i < 52; i++) {
        freq[i].character = (i < 26) ? ('a' + i) : ('A' + i - 26);
        freq[i].frequency = 0;
    }

    for (int i = 0; S[i] != '\0'; i++) {
        char c = S[i];
        if (c >= 'a' && c <= 'z') {
            freq[c - 'a'].frequency++;
        } else if (c >= 'A' && c <= 'Z') {
            freq[c - 'A' + 26].frequency++;
        }
    }

    bubbleSort(freq, 52);

    int current_frequency = 0;
    bool first = true;
    for (int i = 0; i < 52; i++) {
        if (freq[i].frequency == 0) break;

        if (freq[i].frequency != current_frequency) {
            if (!first) cout << endl;
            current_frequency = freq[i].frequency;
            cout << current_frequency << ": ";
            first = false;
        }

        cout << freq[i].character << " ";
    }
    cout << endl;

    return 0;
}
