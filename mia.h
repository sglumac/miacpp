#ifndef MIA_H
#define MIA_H

class MiaProblem {
public:
    virtual double evaluateSolution(const double* solution) const = 0;
    virtual int getDimension() const = 0;
};

class MiaSolver {
private:
    int _L;
    double _lambda;
    double _eps;

    void _generateSolution(double d, const double* bestSolution, double* solution, int n);
    void _generateInitialSolution(double* solution, int n);
public:
    MiaSolver(int L, double lambda, double eps);
    double solve(const MiaProblem& miaProblem, double* solution);
};

#endif // MIA_H
