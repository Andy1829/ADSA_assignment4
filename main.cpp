#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <utility>
#include <bits/stdc++.h>
using namespace std;

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

int translateMatrixIndex(vector<vector<char>> matrix, int row, int col) {       // Works correctly 
    return translate(matrix[row][col]);
}

template <typename T> 
void printMatrix(vector<vector<T>> matrix) {        // Works correctly
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            cout << matrix[i][j] << " ";
        cout << endl;
    }    
}

template <typename T> 
void printMatrixValues(vector<vector<T>> matrix) {
    for(int i = 0; i < matrix.size(); i++){
        for(int j = 0; j < matrix[i].size(); j++)
            cout << translate(matrix[i][j]) << " ";
        cout << endl;
    }   
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
    vector<vector<char>> country;
    vector<vector<char>> build;
    vector<vector<char>> destroy;

    // Input:
    // getline(cin, input);

    // Manual Insertion
    // input = "000,000,000 ABD,BAC,DCA ABD,BAC,DCA";
    input = "011000,101000,110000,000011,000101,000110 ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA ABDFFF,BACFFF,DCAFFF,FFFABD,FFFBAC,FFFDCA";

    // Counts which matrix we're observing
    int counter = 0;

    istringstream row(input);
    while(row >> input) {           // Grabs space separated values
        vector<vector<char>> buildMatrix;
        string temp;
        int rowCounter = 0;

        istringstream unit(input);
        while (getline(unit, temp, ',')) {      // Grabs comma separated values
            vector<char> vect(temp.begin(), temp.end());
            buildMatrix.push_back(vect);
            rowCounter++;
        }

        if (counter == 0)
            country = buildMatrix;
        if (counter == 1)
            build = buildMatrix;
        if (counter == 2) 
            destroy = buildMatrix;
        counter++;
    }

    printMatrix(country);
    cout << endl;
    printMatrixValues(country);
    cout << endl;
    printMatrix(build);
    cout << endl;
    printMatrixValues(build);
    cout << endl;
    printMatrix(destroy);
    cout << endl;
    printMatrixValues(destroy);

    // cout << translateMatrixIndex(build, 3, 0);

    // Test Code
    // translateTest();

}