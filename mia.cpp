#include <algorithm>
#include <cstdlib>
#include "mia.h"

MiaSolver::MiaSolver(int L, double lambda, double eps) : _L(L), _lambda(lambda), _eps(eps) {}


double MiaSolver::solve(const MiaProblem& miaProblem, double* bestSolution) {

    int n = miaProblem.getDimension();

    double jNew, jBest;
    double* tempSolution = new double[n];

    _generateInitialSolution(bestSolution, n);
    jBest = miaProblem.evaluateSolution(bestSolution);

    double d = 1;

    while (d > _eps) {
        for (int i = 0; i < _L; i++) {
            _generateSolution(d, bestSolution, tempSolution, n);
            jNew = miaProblem.evaluateSolution(tempSolution);
            if (jNew < jBest) {
                jBest = jNew;
                std::copy(tempSolution, tempSolution + n, bestSolution);
            }
        }
        d *= _lambda;
    }

    delete[] tempSolution;

    return jBest;
}


void MiaSolver::_generateInitialSolution(double* solution, int n) {
    for (int i = 0; i < n; i++)
        solution[i] = static_cast<double>(rand()) / RAND_MAX;
}


void MiaSolver::_generateSolution(double d, const double* bestSolution, double* solution, int n) {
    for (int i = 0; i < n; i++) {
        double r = static_cast<double>(rand()) / RAND_MAX;
        solution[i] = (r * 2.0 - 1) * d + bestSolution[i];
    }
}
