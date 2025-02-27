#include <iostream>
#include <vector>
using namespace std;

long long maxBooksRead(vector<long long>& A, vector<long long>& B, long long K) {
    int N = A.size(), M = B.size();
    vector<long long> prefixA(N + 1, 0), prefixB(M + 1, 0);

    for (int i = 1; i <= N; i++) {
        prefixA[i] = prefixA[i - 1] + A[i - 1];
    }
    for (int i = 1; i <= M; i++) {
        prefixB[i] = prefixB[i - 1] + B[i - 1];
    }

    long long maxBooks = 0;
    int j = M;

    for (int i = 0; i <= N; i++) {
        if (prefixA[i] > K) break;

        while (j > 0 && prefixA[i] + prefixB[j] > K) {
            j--;
        }

        maxBooks = max(maxBooks, (long long)(i + j));
    }

    return maxBooks;
}

int main() {
    int N, M;
    long long K;
    cout << "Enter the value of N , M , K : " << endl;
    cin >> N >> M >> K;

    vector<long long> A(N), B(M);
    cout << "Enter elements of deck A : "<< endl;
    for (int i = 0; i < N; i++) cin >> A[i];
    cout << "Enter elements of deck B : " << endl;
    for (int i = 0; i < M; i++) cin >> B[i];

    cout << "the maximum number of books that can be read : "<< maxBooksRead(A, B, K) << endl;

    return 0;
}
