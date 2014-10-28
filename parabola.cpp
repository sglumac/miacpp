#include <iostream>
#include <algorithm>
#include <cstdlib>
#include "mia.h"
using namespace std;

class ParabolaProblem : public MiaProblem {
private:
    int _n;
    double* _center;
public:
    ParabolaProblem(double* center, int n) : _n(n) {
        _center = new double[n];
        copy(center, center + n, _center);
    }

    double evaluateSolution(const double* solution) const {
        double p = 0;
        for (int i = 0; i < _n; i++) {
            double x = solution[i] - _center[i];
            p += x * x;
        }
        return p;
    }

    int getDimension() const {
        return _n;
    }

    ~ParabolaProblem() {
        delete[] _center;
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    double center[] = {1.5, 3.5};
    ParabolaProblem parabolaProblem(center, 2); 
    MiaSolver miaSolver(7, 0.93, 1e-3); 

    double solution[2];
    miaSolver.solve(parabolaProblem, solution);

    cout << "MiaSolver found an optimal solution in [ "; 
    for (int i = 0; i < 2; i++)
        cout << solution[i] << " ";
    cout << "]" << endl;
    cout << "for a parabola centered in [ 1.5 3.5 ]" << endl;

    return 0;
}
