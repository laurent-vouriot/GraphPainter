/*----------------------------------------------------------------------------
  EzPainter
  debut : Decembre 2020
-------------------------------------------------------------------------------*/
/**
* @file    main.cpp
* @author  Laurent VOURIOT
* @version 0.1
* @date    11/12/2020
*/
//-----------------------------------------------------------------------------
// INCLUDES
//-----------------------------------------------------------------------------
#include <iostream>
#include <iomanip>
#include <stdlib.h> // srand, rand
#include <time.h>   // time

#include <QApplication>

#include "mainwindow.h"

using namespace std;


Graph randomKGraph()
{
    vector<Node *> vnodes;
    // random seed
    srand(time(NULL));

    // génération aléatoire de 10 sommets
    for(unsigned i = 0; i < 10; ++i)
    {
        // source : stackoverflow
        string s = to_string(i);
        char const *pchar = s.c_str();
        vnodes.push_back(new Node(rand() % 500 + 1,rand() % 500 + 1, pchar));
    }
    Graph graph(vnodes);

    // génération aléatoire des arêtes
    for(const Node* begin:vnodes)
    {
        for(const Node* end:vnodes)
        {
            if(begin != end)
                graph.link((*begin),(*end));
        }
    }

    return graph;
}// randomKGraph()

Graph fixedGraph()
{
    Node n1(456,45,"A");
    Node n2(253,456,"B");
    Node n3(45,201,"D");
    Node n4(111,200,"E");
    Node n5(55,88,"F");
    Node n6(231,100,"G");
    Node n7(89,300,"H");

    vector<Node *> vnodes{&n1,&n2,&n3,&n4,&n5,&n6,&n7};
    Graph graph(vnodes);

    graph.link(n1, n4);
    graph.link(n1, n5);
    graph.link(n1, n2);
    graph.link(n1, n6);
    graph.link(n2, n4);
    graph.link(n2, n3);
    graph.link(n6, n4);
    graph.link(n6, n2);
    graph.link(n5, n4);
    graph.link(n5, n7);
    graph.link(n5, n4);

    return graph;
}// fixedGraph()


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // TODO pour l'instant c'est un peu tb gros
    unsigned generation;
    cout << "génération aléatoire : 0 \n" <<
            "génération fixée : 1 \n" << endl;

    // Graph graph = fixedGraph();
    Graph graph = randomKGraph();

//    cin >> generation;
//    if(generation == 0)
//    {
//        Graph graph = randomKGraph();
//    }
//    else
//        Graph graph = fixedGraph();

    MainWindow w(nullptr, &graph);
    w.show();
    return a.exec();

}
