/*
ID: your_id_here
PROG: ride
LANG: C++11
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

string commet;
string group;

int value_commet = 1;
int value_group = 1;

const int mod = 47;

int main() {
    ofstream fout ("ride.out");
    ifstream fin ("ride.in");
    fin >> commet >> group;

    for (int i = 0; i < commet.size(); ++i)
    {
    	int value = int(commet[i]) - int('A') + 1;
    	value_commet = (value_commet* value)%mod;
    	// fout<< value_commet << " " << int(commet[i]) << endl;
    }

    for(int i = 0; i < group.size(); ++i){
    	int value = int(group[i]) - int('A') + 1;
    	value_group = (value_group * value)%mod;
    }

    if(value_commet == value_group){
    	fout<< "GO" << endl;
    } else{
    	fout<<"STAY"<<endl;
    }
    return 0;
}