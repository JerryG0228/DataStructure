//
//  Lab09.cpp
//  Lab09
//
//  Modified by Jeman Park on 2023/11/28.
//

#include <iostream>
#include "GraphType.h"

using namespace std;

int main() {

    GraphType<const char *> graph;

    graph.AddVertex("Seoul");
    graph.AddVertex("Tokyo");
    graph.AddVertex("Osaka");
    graph.AddVertex("Beijing");
    graph.AddVertex("NewYork");
    graph.AddVertex("LA");
    graph.AddVertex("DC");
    graph.AddVertex("London");
    graph.AddVertex("Paris");
    graph.AddVertex("Roma");
    graph.AddVertex("Berlin");
    graph.AddVertex("Madrid");
    graph.AddVertex("Moscow");

    graph.AddVertex("Bangkok");
    graph.AddVertex("Manila");
    graph.AddVertex("Taipei");

    graph.AddEdge("Seoul", "Tokyo", 1147);
    graph.AddEdge("Beijing", "Tokyo", 2093);
    graph.AddEdge("Beijing", "LA", 10053);

    graph.AddEdge("Seoul", "NewYork", 11047);
    graph.AddEdge("Seoul", "DC", 11158);
    graph.AddEdge("Seoul", "LA", 9580);

    graph.AddEdge("DC", "NewYork", 361);
    graph.AddEdge("LA", "DC", 3744);

    graph.AddEdge("Seoul", "London", 8870);
    graph.AddEdge("Seoul", "Paris", 8874);
    graph.AddEdge("Seoul", "Berlin", 8066);
    graph.AddEdge("Seoul", "Madrid", 9974);
    graph.AddEdge("Seoul", "Moscow", 6547);
    graph.AddEdge("Seoul", "Roma", 8912);

    graph.AddEdge("Paris", "London", 346);
    graph.AddEdge("Paris", "Berlin", 1296);
    graph.AddEdge("Paris", "Moscow", 2486);
    graph.AddEdge("Paris", "Roma", 1368);
    graph.AddEdge("Paris", "Madrid", 1058);

    graph.AddEdge("London", "Berlin", 907);
    graph.AddEdge("London", "Moscow", 2500);
    graph.AddEdge("London", "Roma", 1407);
    graph.AddEdge("London", "Madrid", 1214);

    graph.AddEdge("Berlin", "Moscow", 1609);
    graph.AddEdge("Berlin", "Roma", 1182);
    graph.AddEdge("Berlin", "Madrid", 1869);

    graph.AddEdge("Roma", "Madrid", 1364);
    graph.AddEdge("Roma", "NewYork", 6888);
    graph.AddEdge("Roma", "LA", 10214);

    graph.AddEdge("Paris", "NewYork", 5863);
    graph.AddEdge("Paris", "LA", 9061);

    graph.AddEdge("London", "NewYork", 5575);
    graph.AddEdge("London", "LA", 8708);

    graph.AddEdge("Bangkok", "Manila", 2203);
    graph.AddEdge("Taipei", "Manila", 1176);


    graph.PrintGraph();
    //                 Seoul   Tokyo    Osaka    Beijing  NewYork  LA      DC       London  Paris   Roma    Berlin  Madrid  Moscow  Bangkok Manila  Taipei
    //        Seoul    0       1147     0        0        11047    9580    11158    8870    8874    8912    8066    9974    6547    0       0       0
    //        Tokyo    1147    0        0        2093     0        0       0        0       0       0       0       0       0       0       0       0
    //        Osaka    0       0        0        0        0        0       0        0       0       0       0       0       0       0       0       0
    //        Beijing  0       2093     0        0        0        10053   0        0       0       0       0       0       0       0       0       0
    //        NewYork  11047   0        0        0        0        0       361      5575    5863    6888    0       0       0       0       0       0
    //        LA       9580    0        0        10053    0        0       3744     8708    9061    10214   0       0       0       0       0       0
    //        DC       11158   0        0        0        361      3744    0        0       0       0       0       0       0       0       0       0
    //        London   8870    0        0        0        5575     8708    0        0       346     1407    907     1214    2500    0       0       0
    //        Paris    8874    0        0        0        5863     9061    0        346     0       1368    1296    1058    2486    0       0       0
    //        Roma     8912    0        0        0        6888     10214   0        1407    1368    0       1182    1364    0       0       0       0
    //        Berlin   8066    0        0        0        0        0       0        907     1296    1182    0       1869    1609    0       0       0
    //        Madrid   9974    0        0        0        0        0       0        1214    1058    1364    1869    0       0       0       0       0
    //        Moscow   6547    0        0        0        0        0       0        2500    2486    0       1609    0       0       0       0       0
    //        Bangkok  0       0        0        0        0        0       0        0       0       0       0       0       0       0       2203    0
    //        Manila   0       0        0        0        0        0       0        0       0       0       0       0       0       2203    0       1176
    //        Taipei   0       0        0        0        0        0       0        0       0       0       0       0       0       0       1176    0




    graph.UpdateEdge("Moscow", "Berlin", 1817);
    cout << "After UpdateEdge: " << endl;
    graph.PrintGraph();
    //                 Seoul   Tokyo    Osaka    Beijing  NewYork  LA      DC       London  Paris   Roma    Berlin  Madrid  Moscow  Bangkok Manila  Taipei
    //        Seoul    0       1147     0        0        11047    9580    11158    8870    8874    8912    8066    9974    6547    0       0       0
    //        Tokyo    1147    0        0        2093     0        0       0        0       0       0       0       0       0       0       0       0
    //        Osaka    0       0        0        0        0        0       0        0       0       0       0       0       0       0       0       0
    //        Beijing  0       2093     0        0        0        10053   0        0       0       0       0       0       0       0       0       0
    //        NewYork  11047   0        0        0        0        0       361      5575    5863    6888    0       0       0       0       0       0
    //        LA       9580    0        0        10053    0        0       3744     8708    9061    10214   0       0       0       0       0       0
    //        DC       11158   0        0        0        361      3744    0        0       0       0       0       0       0       0       0       0
    //        London   8870    0        0        0        5575     8708    0        0       346     1407    907     1214    2500    0       0       0
    //        Paris    8874    0        0        0        5863     9061    0        346     0       1368    1296    1058    2486    0       0       0
    //        Roma     8912    0        0        0        6888     10214   0        1407    1368    0       1182    1364    0       0       0       0
    //        Berlin   8066    0        0        0        0        0       0        907     1296    1182    0       1869    1817    0       0       0
    //        Madrid   9974    0        0        0        0        0       0        1214    1058    1364    1869    0       0       0       0       0
    //        Moscow   6547    0        0        0        0        0       0        2500    2486    0       1817    0       0       0       0       0
    //        Bangkok  0       0        0        0        0        0       0        0       0       0       0       0       0       0       2203    0
    //        Manila   0       0        0        0        0        0       0        0       0       0       0       0       0       2203    0       1176
    //        Taipei   0       0        0        0        0        0       0        0       0       0       0       0       0       0       1176    0


    graph.DeleteEdge("Tokyo", "Seoul");
    cout << "After DeleteEdge: " << endl;
    graph.PrintGraph();
    //                 Seoul   Tokyo    Osaka    Beijing  NewYork  LA      DC       London  Paris   Roma    Berlin  Madrid  Moscow  Bangkok Manila  Taipei
    //        Seoul    0       0        0        0        11047    9580    11158    8870    8874    8912    8066    9974    6547    0       0       0
    //        Tokyo    0       0        0        2093     0        0       0        0       0       0       0       0       0       0       0       0
    //        Osaka    0       0        0        0        0        0       0        0       0       0       0       0       0       0       0       0
    //        Beijing  0       2093     0        0        0        10053   0        0       0       0       0       0       0       0       0       0
    //        NewYork  11047   0        0        0        0        0       361      5575    5863    6888    0       0       0       0       0       0
    //        LA       9580    0        0        10053    0        0       3744     8708    9061    10214   0       0       0       0       0       0
    //        DC       11158   0        0        0        361      3744    0        0       0       0       0       0       0       0       0       0
    //        London   8870    0        0        0        5575     8708    0        0       346     1407    907     1214    2500    0       0       0
    //        Paris    8874    0        0        0        5863     9061    0        346     0       1368    1296    1058    2486    0       0       0
    //        Roma     8912    0        0        0        6888     10214   0        1407    1368    0       1182    1364    0       0       0       0
    //        Berlin   8066    0        0        0        0        0       0        907     1296    1182    0       1869    1817    0       0       0
    //        Madrid   9974    0        0        0        0        0       0        1214    1058    1364    1869    0       0       0       0       0
    //        Moscow   6547    0        0        0        0        0       0        2500    2486    0       1817    0       0       0       0       0
    //        Bangkok  0       0        0        0        0        0       0        0       0       0       0       0       0       0       2203    0
    //        Manila   0       0        0        0        0        0       0        0       0       0       0       0       0       2203    0       1176
    //        Taipei   0       0        0        0        0        0       0        0       0       0       0       0       0       0       1176    0


    // Exercise 9-2
    cout << "Moscow to Seoul: " << endl;
    if (graph.DepthFirstSearch("Moscow", "Seoul")) {
        cout << "Path exists!" << endl;
    } else {
        cout << "Path NOT exists!" << endl;
    }
    // Path exists!


    cout << "Manila to Seoul: " << endl;
    if (graph.DepthFirstSearch("Manila", "Seoul")) {
        cout << "Path exists!" << endl;
    } else {
        cout << "Path NOT exists!" << endl;
    }
    // Path NOT exists!

    // Exercise 9-3
    cout << "Moscow to LA: " << endl;
    if (graph.BreadthFirstSearch("Moscow", "LA")) {
        cout << "Path exists!" << endl;
    } else {
        cout << "Path NOT exists!" << endl;
    }
    // Path exists!

    cout << "Manila to Seoul: " << endl;
    if (graph.BreadthFirstSearch("Manila", "Seoul")) {
        cout << "Path exists!" << endl;
    } else {
        cout << "Path NOT exists!" << endl;
    }
    // Path NOT exists!



    // Exercise (Bonus)
    // Call your function here and then print the recorded paths.
    cout<<"\n< Bonus Exercise Result >"<<endl;
    graph.DepthFirstSearch_Path("Moscow", "LA");

    return 0;
}
