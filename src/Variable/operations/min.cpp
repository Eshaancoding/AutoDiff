#include "Variable.hpp"

// operations
Variable min_op (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = new Variable();
    new_var.child[1] = new Variable();
    *(new_var.child[0]) = left;
    *(new_var.child[1]) = right;
    return new_var;
}

Variable min_op (const Variable &left, Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = new Variable();
    *(new_var.child[0]) = left;
    new_var.child[1] = &right;
    return new_var;
}

Variable min_op (const Variable &left, const double &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = new Variable();
    *(new_var.child[0]) = left;
    
    new_var.child[1] = new Variable(false);
    new_var.child[1]->value = right;
    new_var.child[1]->operation = op::argument;    
    return new_var;
}

Variable min_op (Variable &left, const Variable &right) {
    Variable new_var = Variable(false); 
    new_var.operation = op::min;
    new_var.child[0] = &left;
    new_var.child[1] = new Variable();
    *(new_var.child[1]) = right;
    return new_var;
}

Variable min_op (Variable &left, Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = &left; 
    new_var.child[1] = &right;
    return new_var;
}

Variable min_op (Variable &left, const double &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = &left;
    new_var.child[1] = new Variable(false);
    new_var.child[1]->value = right;
    new_var.child[1]->operation = op::argument;
    
    return new_var;
}

Variable min_op (const double &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::min;
    new_var.child[0] = new Variable(false);
    new_var.child[0]->value = left;
    new_var.child[0]->operation = op::argument;
    new_var.child[1] = new Variable();
    *(new_var.child[1]) = right; 
    return new_var;
}

Variable min_op (const double &left, Variable &right) {
    Variable new_var = Variable(false); 
    new_var.operation = op::min; 
    new_var.child[0] = new Variable(false);
    new_var.child[0]->operation = op::argument;
    new_var.child[0]->value = left;
    new_var.child[1] = &right;
    return new_var;
}