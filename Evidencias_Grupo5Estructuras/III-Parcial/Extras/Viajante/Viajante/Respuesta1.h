#pragma once
#include <vector>
#include <iostream>
#define V 20
using namespace std;
class Respuesta {
private:
    vector<int> res;
public:
    void add(int);
    vector<int> get_res();    
    void set_res(vector<int> ve);    
    void mostrar();
    int sum(int [][V]);
    void insertar(int);

};

