#include "Variable.hpp"

Variable Variable::clip (const Variable &left, const Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = new Variable();
    *(new_var.child[0]) = left;
    new_var.child[1] = new Variable();
    *(new_var.child[1]) = right;
    return new_var;
}

Variable Variable::clip (const Variable &left, Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = new Variable(); 
    *(new_var.child[0]) = left;
    new_var.child[1] = &right;
    return new_var;
}

Variable Variable::clip (const Variable &left, const double &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = new Variable();
    *(new_var.child[0]) = left;
    new_var.child[1] = new Variable();
    new_var.child[1]->operation = op::argument;
    new_var.child[1]->value = right;
    return new_var;
}

Variable Variable::clip (Variable &left, const Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = &left;
    new_var.child[1] = new Variable(); 
    *(new_var.child[1]) = right;
    return new_var;
}

Variable Variable::clip (Variable &left, Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = &left;
    new_var.child[1] = &right;
    return new_var;
}

Variable Variable::clip (Variable &left, const double &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = &left;
    new_var.child[1] = new Variable();
    new_var.child[1]->operation = op::argument;
    new_var.child[1]->value = right;
    return new_var;
}

Variable Variable::clip (const double &left, const Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = new Variable();
    new_var.child[0]->value = left;
    new_var.child[0]->operation = op::argument;
    new_var.child[1] = new Variable();
    *(new_var.child[1]) = right;
    return new_var;
}

Variable Variable::clip (const double &left, Variable &right) {
    Variable new_var = Variable();
    new_var.arg = new Variable(); 
    new_var.arg->value = this->value;
    new_var.operation = op::clip;
    new_var.child[0] = new Variable(); 
    new_var.child[0]->value = left;
    new_var.child[0]->operation = op::argument; 
    new_var.child[1] = &right;
    return new_var;
}