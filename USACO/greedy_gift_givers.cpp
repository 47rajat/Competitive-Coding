/*
ID: your_id_here
PROG: gift1
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>
#include <bits/stdc++.h>

using namespace std;

int np;
map<string, int> gains;
vector<string> names;



int main() {
    ifstream fin ("gift1.in");
    ofstream fout ("gift1.out");

    fin>> np;
    string name;
    for(int i = 0; i < np; i++){
    	fin>>name;
    	gains[name] = 0;
    	names.push_back(name);
    }

    string giver;
    int giver_amount;
    int total_reciever;
    for(int i = 0; i < np; i++){
    	fin>> giver;
    	fin>>giver_amount>>total_reciever;
    	for(int j = 0; j < total_reciever; j++){
    		string reciever;
    		fin>>reciever;
    		gains[reciever] += giver_amount/total_reciever;
    	}

    	if(total_reciever != 0){
    		gains[giver] += giver_amount%total_reciever - giver_amount;
    	}

    }

    for(int i = 0; i < np; i++){
    	fout << names[i] << " " << gains[names[i]] << endl;
    }

    return 0;
}