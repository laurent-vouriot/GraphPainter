/*----------------------------------------------------------------------------
  GraphPainter
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


NonOrientedGraph randomKGraph()
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
    NonOrientedGraph graph(vnodes);

    // génération des arêtes
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

NonOrientedGraph fixedGraph()
{
    char *str = "A";
//    Node n2(253,456,"B");
//    Node n3(45,201,"D");
//    Node n4(111,200,"E");
//    Node n5(55,88,"F");
//    Node n6(231,100,"G");
//    Node n7(89,300,"H");

    vector<Node *> vnodes{new Node(45,45,str)/*,&n2,&n3,&n4,&n5,&n6,&n7*/};
    NonOrientedGraph graph(vnodes);

    /*graph.link(n1, n4);
    graph.link(n1, n5);
    graph.link(n1, n2);
    graph.link(n1, n6);*/

    return graph;
}// fixedGraph()

OrientedGraph fixedOGraph()
{

    char * str = "A";
    vector<Node *> vnodes{new Node(45,45,str), new Node(500,45,str), new Node(56, 300,str)};
    OrientedGraph graph(vnodes);

    graph.link((*vnodes[0]), (*vnodes[1]));
    graph.link((*vnodes[0]), (*vnodes[2]));
    graph.link((*vnodes[1]), (*vnodes[2]));

    return graph;
}// fixedOGraph()


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    // TODO pour l'instant c'est un peu tb gros

    //NonOrientedGraph graph = randomKGraph();
    // NonOrientedGraph graph = fixedGraph();
    OrientedGraph graph = fixedOGraph();

    MainWindow w(nullptr, &graph);
    w.show();
    return a.exec();

}
