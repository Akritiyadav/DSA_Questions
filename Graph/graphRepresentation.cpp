#include<bits/stdc++.h>
using namespace std;

int main(){
     map<int, vector<int>> graph;

    graph[0] = vector<int>();
    graph[0].push_back(6);
    graph[0].push_back(2);


    graph[1] = vector<int>();

    graph[2] = vector<int>();
    graph[2].push_back(1);
    graph[2].push_back(4);

    graph[3] = vector<int>();

    graph[4] = vector<int>();

    graph[5] = vector<int>();
    graph[5].push_back(3);
    
    graph[6] = vector<int>();
    graph[6].push_back(5);

    for (int i = 0; i < 7; i++) {
        cout << i << "    ->";
        for (auto j : graph[i]) {
            cout << j << " ";
        }
        printf("\n");
    }

    //-------------------------------------//

     vector<list<int>> graph(7, list<int>());

    graph[0].push_back(6);
    graph[0].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(4);

    graph[5].push_back(3);

    graph[6].push_back(5);

    for (int i = 0; i < 7; i++) {
        cout << i << "    ->";
        for(auto j: graph[i]){
            cout<<j<<" ";
        }
        printf("\n");
    }


    //----------------------------------------------


    list<int> graph[7];

    fill_n(&graph[0], 7, list<int>());


    graph[0].push_back(6);
    graph[0].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(4);

    graph[5].push_back(3);

    graph[6].push_back(5);

    for (int i = 0; i < 7; i++) {
        cout << i << "    ->";
        for(auto j: graph[i]){
            cout<<j<<" ";
        }
        printf("\n");
    }


    //----------------------------------------


     vector<int> graph[7];

    fill_n(&graph[0], 7, vector<int>());

    graph[0].push_back(6);
    graph[0].push_back(2);

    graph[2].push_back(1);
    graph[2].push_back(4);

    graph[5].push_back(3);

    graph[6].push_back(5);

    for (int i = 0; i < 7; i++) {
        cout << i << "    ->";
        for (int j = 0; j < graph[i].size(); j++) {
            cout << graph[i][j] << "  ";
        }
        printf("\n");
    }


    //-----------------------------------------

    vector<vector<int>> graph(7, vector<int>());

    vector<int> graph[7];

    graph[0].push_back(6);
    graph[0].push_back(2);


    graph[2].push_back(1);
    graph[2].push_back(4);


    graph[5].push_back(3);
    
    graph[6].push_back(5);


    for(int i=0; i<graph.size(); i++){
        cout<<i<<"    ->";
        for(int j=0; j<graph[i].size(); j++){
            cout<<graph[i][j]<<"  ";
        }
        printf("\n");
    }


    //-------------------------------------------

     map<string, vector<string>> mp;

    mp["mumbai"].push_back("delhi");
    mp["mumbai"].push_back("california");
    mp["mumbai"].push_back("bengaluru");

    mp["delhi"].push_back("new york");

    mp["new york"].push_back("los angeles");
    mp["california"].push_back("los angeles");

    for (auto city : mp) {
        cout << city.first << "   ->";
        for (auto connectedcities : city.second) {
            cout << connectedcities << "  ";
        }
        cout << "\n";
    }

}