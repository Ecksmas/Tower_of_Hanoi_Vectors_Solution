#include <iostream>
#include <vector>

using namespace std;

    void printPegs(vector<int> &pegA, vector<int> &pegB, vector<int> &pegC) {
    cout << "Peg A: ";
    for (int i : pegA) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Peg B: ";
    for (int i : pegB) {
        cout << i << " ";
    }

    cout << endl;

    cout << "Peg C: ";
    for (int i : pegC) {
        cout << i << " ";
    }

    cout << endl;
    cout << "----------------" << endl;
}

void moveDisk(vector<int> &source, vector<int> &destination) {
    int disk = source.back();
    source.pop_back();
    destination.push_back(disk);
}

void towerOfHanoi(int disks, vector<int> &source, vector<int> &destination, vector<int> &temp) {
    if (disks == 1) {
        moveDisk(source,destination);
        printPegs(source, temp, destination);
        return;
    }
    towerOfHanoi(disks - 1, source, temp, destination);
    moveDisk(source, destination);
    printPegs(source,temp,destination);
    towerOfHanoi(disks - 1, temp, destination, source);

}

int main() {

    int numDisks = 3;

    vector<int> pegA, pegB, pegC;

    for (int i = numDisks; i > 0; --i) {
        pegA.push_back(i);
    }

    printPegs(pegA,pegB,pegC);

    towerOfHanoi(numDisks,pegA,pegC,pegB);

}
