//
//  main.cpp
//  ExpanderGraphs
//
//  Created by Brendan Carey on 4/18/20.
//  Copyright © 2020 Brendan Carey. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#include <set>
#include <fstream>


using namespace std;

void clearSets(vector<set<int>> &sets) {
    for(int i = 0; i < sets.size(); i++) {
        sets[i].clear();
    }
}

void checkConstraints(const vector<int>& bits, vector<int> &constraints, const vector<vector<int>> &adj) {
    for(int i = 0; i < constraints.size(); i++) {
        
        int sum = 0;
        for(int j = 0; j < bits.size(); j++) {
            
            //check for connection
            if(bits[j] == 1) {
                
                sum += adj[i][j];
            }
            
        } //for2
        
        if( sum % 2 == 0) {
            //constraint is satisfied by even number of set bits
            constraints[i] = 1;
            
        }
        else {
            //constraint is unsatisfied due to uneven amount of bits
            constraints[i] = 0;
            
        }
    } //for1
}

void checkBits(const vector<int> &bits, const vector<int> &constraints, const vector<vector<int>>& adj, vector<set<int>> &sets) {
    
    for(int i = 0; i < bits.size(); i++) {
        
        int amt = 0;
        for(int j =0; j < constraints.size();j++) {
            
            if(adj[j][i] == 1 and constraints[j] == 0) {
                amt++;
            }
        }
        
        sets[amt].insert(i);
    }

}



int main(int argc, const char * argv[]) {
   
    
    //figure out input stream for adjacency matrix
    
    vector<int> bits;
    vector<int> constraints;
    vector<vector<int>> adj;
    
    string codeword;
    cout << "Input the codeword you wish to decode: " << endl;
    cin >> codeword;
    
    //initialize bits
    for(int i = 0; i < codeword.size(); i++) {
        if(codeword[i] == 49) {
            bits.push_back(1);
        }
        else {
            bits.push_back(0);
        }

    }
    
    string row;
    int numConstraints;
    cout << "Enter the number of constraints in this expander graph: " << endl;
    cin >> numConstraints;
    ifstream input;
    input.open("/Users/brendancarey/Desktop/ExpanderGraphs/ExpanderGraphs/B-1.9715.txt");
    if(!input) {
        cout << "error";
    }
    
    for(int i = 0; i < numConstraints; i++) {
        
        string row;
        getline(input, row);
        vector<int> temp;
        for(int j = 0; j < row.size(); j++) {
            if(row[j] == 49) {
                temp.push_back(1);
            }
            else {
                temp.push_back(0);
            }
            
        }
        adj.push_back(temp);
    }
    constraints.resize(numConstraints);
    
    //initialize vector of sets
    vector<set<int>> sets;
    for(int i = 0; i < constraints.size(); i++) {
        set<int> temp;
        sets.push_back(temp);
    }
    
    
    while(1) {
        
        //refresh sets
        clearSets(sets);
        
        //see if constraints are satisfied by inputed codeword
        checkConstraints(bits, constraints, adj);
        
        //count number of unsatisfied constraints for each bit
        //load sets
        checkBits(bits, constraints, adj, sets);
        
        //find index of highest index set that is not empty
        //e.g. find the variables that have the highest dissatisfaction rate
        int setIndex = 0;
        for(int i = static_cast<int>(sets.size() - 1); i >= 0; i--) {
            
            if(sets[i].empty() == false) {
                setIndex = i;
                break;
            }
            
        }
        
        if(setIndex < ceil(static_cast<double>(constraints.size() / 2))) {
            break;
            //algo is done
        }
        
        //flip a bit
        //not sure if this works atm
        auto ite = sets[setIndex].begin();
        if(bits[*ite] == 1) {
            
            bits[*ite] = 0;
        }
        else {
            bits[*ite] = 1;
        }
        
    } //while
    
    //algo conclusion
    if(sets[0].size() == bits.size()) {
        //a valid codeword has been returned
        cout << "A valid codeword has been decoded: ";
        for(int i = 0; i < bits.size(); i++) {
            
            cout << bits[i];
        }
        cout << endl;
        exit(0);
    }
    else {
        //unsuccessful decoding
        cout << "Decoding unsuccesful. Exiting program" << endl;
        exit(0);
    }
    
}
