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
#include <stdlib.h> // srand, rand
#include <time.h>   // time
#include <string>

#include <QApplication>

#include "headers/mainwindow.h"

#include "headers/path/orientedpath.h"
#include "headers/path/nonorientedpath.h"

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

vector<Node *> createNodes(vector<Node *> & vnodes)
{
    int x = -1, y;
    string name;

    while(x != 0)
    {
        cout << "entrez x, y, nom, tapez 0"<< endl;
        cin >> x;
        if(x != 0)
        {

            cin >> y;
            cin.ignore();
            getline(cin, name);
            vnodes.push_back(new Node(x,y,new QString(name.c_str())));
        }
    }
    return vnodes;
}// createNodes()

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // création des sommets
    // ____________________
    int x, y;
    vector<Node *> vnodes;
    string name;
    cout << "entrez x, y, tapez 0 pour quitter"<< endl;

    cin >> x;
    cin >> y;
    cin.ignore();
    getline(cin, name);

    vnodes.push_back(new Node(x,y,new QString(name.c_str())));
    vnodes = createNodes(vnodes);


    // création du graphe
    //___________________

    int choice;
    cout << "tapez 0 pour pour créer un graphe non orienté \n"
            "tapez 1 pour créer un graphe orienté " << endl;
    cin >> choice;

    AbsGraph *graph;
    StrategyPath *path;

    switch (choice)
    {
        case 0:
            graph = new NonOrientedGraph(vnodes);
            path  = new NonOrientedPath;
            break;
        case 1:
            graph = new OrientedGraph(vnodes);
            path  = new OrientedPath;
            break;
        default:
            path  = new NonOrientedPath;
            graph = new NonOrientedGraph(vnodes);
            break;
    }

    // création des arêtes
    //____________________

    string begin;
    string end;

    cout << "entrez begin end, tapez 0" << endl;
    cin.ignore();
    getline(cin, begin);
    getline(cin, end);

    cout << begin	<< " " << end << endl;

    QString qbegin = begin.c_str();
    QString qend = end.c_str();

    Node *nbegin;
    Node *nend;
    for(Node *n : vnodes)
    {
        if((*n->getName()) == qbegin)
            nbegin = n;
        else if((*n->getName()) == qend)
            nend = n;
    }
    graph->link((*nbegin), (*nend));

    while(begin != "stop")
    {
        cout << "entrez begin end, tapez 0" << endl;
        getline(cin, begin);
        if(begin != "stop")
        {
            getline(cin, end);

            cout << begin	<< " " << end << endl;

            QString qbegin = begin.c_str();
            QString qend = end.c_str();

            Node *nbegin;
            Node *nend;

            for(Node *n : vnodes)
            {
                if((*n->getName()) == qbegin)
                    nbegin = n;
                else if((*n->getName()) == qend)
                    nend = n;
            }
            graph->link((*nbegin), (*nend));
        }
    }

    // darwer & mainwindow
    //____________________

    // drawer
    Drawer drawer(path);

    // main window
    MainWindow w(&drawer, graph);
    w.show();
    return a.exec();

}// main()
