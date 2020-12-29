#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

vector<vector<int>> bWorld;
vector<int> mapInitToCurrent;

void returnBackTopOfBlocks(int pos, int no) {
    int temp;
    while ((temp = bWorld[pos].back()) != no) {
        mapInitToCurrent[temp] = temp;
        bWorld[temp].push_back(temp);
        bWorld[pos].pop_back();
    }
}

void moveMulBlocks(int pos, int newPos, int no) {
    stack<int> ts;
    int temp;
    while ((temp = bWorld[pos].back()) != no) {
	ts.push(temp);
	bWorld[pos].pop_back();
    }
    bWorld[pos].pop_back();
    ts.push(no);
    while (!ts.empty()) {
	temp = ts.top();
	ts.pop();
	mapInitToCurrent[temp] = newPos;
	bWorld[newPos].push_back(temp);
    }
}

void moveOnto(int a, int b, int aPos, int bPos) {
    if (aPos != bPos) {
	//cout << "debug-moveonto" << aPos << bPos << a << b << endl;
	// return Pos
	returnBackTopOfBlocks(aPos, a);	
	//cout << "debug-moveonto" << aPos << bPos << a << b << endl;
	returnBackTopOfBlocks(bPos, b);
	// move a onto b
	//mapInitToCurrent[a] = b;  //spend 40min
	mapInitToCurrent[a] = bPos; 
	bWorld[aPos].pop_back();
	bWorld[bPos].push_back(a);
    }
}

void moveOver(int a, int b, int aPos, int bPos) {
    if (aPos != bPos) {
	returnBackTopOfBlocks(aPos, a);
	mapInitToCurrent[a] = bPos;
	bWorld[aPos].pop_back();
	bWorld[bPos].push_back(a);
    }
}

void pileOnto(int a, int b, int aPos, int bPos) {
    if (aPos != bPos) {
	returnBackTopOfBlocks(bPos, b);
	moveMulBlocks(aPos, bPos, a);
    }
}

void pileOver(int a, int b, int aPos, int bPos) {
    if (aPos != bPos) {
	moveMulBlocks(aPos, bPos, a);
    }
    
}

int main() {
    int n;
    cin >> n;
    bWorld.resize(n);
    mapInitToCurrent.resize(n);
    for (int i = 0; i < n; i++) {
	mapInitToCurrent[i] = i;
	bWorld[i].push_back(i);
    }
    //cout << "debug-init" << endl;
    string s1, s2;
    int a, b;
    while (cin >> s1 >> a >> s2 >> b && s1 != "quit") {
	if (s1 == "move") {
	    if (s2 == "onto") {
		moveOnto(a, b, mapInitToCurrent[a], mapInitToCurrent[b]);
		//cout << "debug-if-else: " << bWorld[mapInitToCurrent[b]].size() << endl;
	    } else {
		moveOver(a, b, mapInitToCurrent[a], mapInitToCurrent[b]);	
	    }
	} else {
	    if (s2 == "onto") {
		pileOnto(a, b, mapInitToCurrent[a], mapInitToCurrent[b]);	
	    } else {
		pileOver(a, b, mapInitToCurrent[a], mapInitToCurrent[b]);	
	    }
	}
    }
    for (int i = 0; i < n; i++) {
	cout << i << ":";
	for (int j = 0; j < bWorld[i].size(); j++) {
	    cout << " " << bWorld[i][j];
	}
	cout << "\n";
    }
    return 0;
}
