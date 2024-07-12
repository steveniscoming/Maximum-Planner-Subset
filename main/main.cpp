#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;
//--------------------------------------------------------------------------------------------------------------
bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}
//--------------------------------------------------------------------------------------------------------------------
void write_to_file(const string& outputFileName, int number, const vector<pair<int, int>>& values) {
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Unable to open output file" << endl;
        return;
    }

    outputFile << number << "\n";
    for (const auto& p : values) {
        outputFile << p.first << " " << p.second << "\n";
    }

    outputFile.close();
}
//----------------------------------------------------------------------------------------------------------------------
void print_result( vector<vector<int>> &order,vector<vector<int>> &value, int row, int col,vector<pair<int, int>> &answer){
	while( col-row >= 1)
	{
		if (order[col][row] == 2)
		{
			int k=value[col][row];
            answer.emplace_back(k,col);
			print_result(order,value,k,col-1,answer);
			col = k - 1;
		}
		else if(order[col][row] == 4)
		{
			int  k=value[col][row];
			answer.emplace_back(k,col);
			print_result(order,value,row+1,col-1,answer);
			col = row - 1;
		} 
		else
		{
			col--;
		}
	}
}
//-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------
void max_planar_subset( vector<pair<int, int>> chords, int n,vector<pair<int, int>> &answer,int &max) {
    vector<int> findk;                         //find responding k
    findk.resize(n);
     for(int w=0 ; w<(n/2); w++){  //find the corresponding point k for each j
           findk[chords[w].first]=chords[w].second;
           findk[chords[w].second]=chords[w].first;
            }
    vector<vector<int>> table;              //construct matrix:table 
    vector<vector<int>> order;               //construct matrix:order
    vector<vector<int>> value;               //construct matrix:value
    table.resize(n, vector<int>(n, 0));    //define the size
    order.resize(n, vector<int>(n, 0));    //define the size
    value.resize(n, vector<int>(n, 0));    //define the size
    for(int g=0; g<n;g++ ){
        for(int i=0;i+g<n;i++){            //dicede the filling order
            int j=i+g;
            int k=findk[j];
            if (i==j){                 //case0 
                table[j][i]=0;
                order[j][i]=0;
            }
            else if(k>j||k<i){              //case1
                table[j][i]=table[j-1][i];
                order[j][i]=1;
             }
             if(k<j && k>i){              //case2
                int cmp1=table[j-1][i];
                int cmp2=table[k-1][i]+table[j-1][k+1]+1;
                if(cmp1<cmp2){
                    table[j][i]=cmp2;
                    order[j][i]=2;
                    value[j][i]=k;

                }
                else{
                    table[j][i]=cmp1;
                    order[j][i]=3;
                }
             }
              if(k==i){                   //case3
                table[j][i]=table[j-1][i+1]+1;
                    order[j][i]=4;
                    value[j][i]=k;
             }

        }
    }
    max=table[n-1][0];
    int row=0;
    int col=n-1;
    print_result(order,value,row,col,answer);
}
//--------------------------------------------------------------------------------------------------------------------
int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Usage: ./[exe] [input file] [output file]" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cerr << "Unable to open input file" << endl;
        return 1;
    }
    vector<pair<int, int>> chords;
    vector<pair<int, int>> answer;
    int max;
    int x, y;
    int n=0;
    inputFile >>n;
    while (inputFile >> x >> y) {
        chords.push_back({x, y});
    }
    inputFile.close();
    max_planar_subset(chords,n,answer,max);
    sort(answer.begin(), answer.end(), compare);
    write_to_file(argv[2], max, answer);
}

