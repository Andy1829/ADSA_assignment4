#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

template <typename T>
void printMatrix(vector<vector<T>> matrix) {        // Works correctly
    for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++)
			cout << matrix[i][j] << " ";
		cout << endl;
	}    
}

int translate(char character) {      // Works correctly
    int key = int(character);
    
    if ((key >= 48) && (key <= 57))  {              // Returns for 0-9
        return character - '0';
    } else 
    if ((key >= 65) && (key <= 90)) {               // Returns for A-Z 
        return character - 64;
    } else if ((key >= 97) && (key <= 122)){        // Returns for a-z
        return character - 70;
    }
    return 0;
}

// Problem
vector<vector<int>> populateMatrix(vector<vector<char>> matrix, vector<vector<int>> output) {
    for(int i = 0; i < matrix.size(); i++){
		for(int j = 0; j < matrix[i].size(); j++) {
            output[i][j] = translate(matrix[i][j]);
        }
	}    
    return output;
}

void translateTest() {   // Works correctly
    string test = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    vector<char> vect(test.begin(), test.end());

    for (size_t i = 0; i < vect.size(); i++) {
        cout << translate(vect.at(i)) << endl;
    }
}

int main() {
    // Takes input, separates by word. 
    string input;
    vector<vector<char>> country {{}, {}, {}};
    vector<vector<char>> build {{}, {}, {}};
    vector<vector<char>> destroy {{}, {}, {}};

    vector<vector<char>> buildMatrix {{}, {}, {}};

    // Input:
    // getline(cin, input);

    // Manual Insertion
    input = "000,000,000 ABD,BAC,DCA ABD,BAC,DCA";

    // Counts which matrix we're observing
    int counter = 0;

    istringstream row(input);
    while(row >> input) {           // Grabs space separated values
        string temp;
        int rowCounter = 0;

        istringstream unit(input);
        while (getline(unit, temp, ',')) {      // Grabs comma separated values
            vector<char> vect(temp.begin(), temp.end());
            buildMatrix.at(rowCounter) = vect;
            rowCounter++;
        }
        // printMatrix(buildMatrix);

        if (counter == 0)
            country = buildMatrix;

        if (counter == 1)
            build = buildMatrix;

        if (counter == 2) 
            destroy = buildMatrix;

        counter++;
    }

    // printMatrix(buildMatrix);
    printMatrix(country);
    printMatrix(build);
    printMatrix(destroy);

    


    // Test Code
    // translateTest();

}