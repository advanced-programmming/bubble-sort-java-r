#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

struct punto {
    int x;
    int y;
    punto(int x, int y) : x(x), y(y){};
    punto() : x(-1), y(-1){};
};

ostream &operator<<(ostream &out, punto &p) {
    out<< "(" << p.x << "," << p.y << ");";
    return out;
}

// size_t es un tipo int sin signo
int burbuja(vector<int> a) {
    int total = 0;
    
    for (size_t i = 0; i < a.size(); i++) {
        for (size_t j = 0; j < (a.size() - 1) - i; j++) {
            if (a[j] > a[j + 1]) {
                int tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
                total += 3;
            }
        }
    }
    
    return total;
}

vector<int> generarArreglo(int n) {
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        v[i] = rand() % n;
    return v;
}

vector<punto> simulacionBurbuja(int k, int n, int t) {
    vector<punto> vec;
    
    for (int i = 0; i < k; i++) {
        vector<int> v = generarArreglo(n);
        int totalPasos = burbuja(v);
        vec.push_back(punto(n, totalPasos));
        n += t;
    }
    
    return vec;
}

// en R x<- c(1,4,7,8,0,..); esto es un arreglo
void print(vector<punto> v) {
    cout<< "X <- c(";
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].x << ",";
    
    cout << ");\n";
    cout << "Y <- c(";
    
    for (size_t i = 0; i < v.size(); i++)
        cout << v[i].y << ",";
    cout << ");\n";
}

int main(){
    int k;
    int n0;
    int t;
    cin >> k >> n0 >> t;
    print(simulacionBurbuja(k, n0, t));
    cout << "plot(X, Y,type=\"l\", main=\"puntos: " << k << ", tamaño: " << n0 << ", incr: " << t << "\");";
    return 0;
}
