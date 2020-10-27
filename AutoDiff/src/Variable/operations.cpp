#include "Variable.hpp"

Variable::Variable (bool t) {
    this->child[0] = nullptr;
    this->child[1] = nullptr;
    this->arg = nullptr;
    this->operation = op::input; 
    this->value = -1;
    static int id_counter = 0;
    if (t) {
        id_counter++;
        this->id = id_counter;
    }
}

Variable* copy_contents_var (const Variable &l, bool a = false) {
    Variable *new_var = new Variable(a);
    new_var->child[0] = l.child[0];
    new_var->child[1] = l.child[1];
    new_var->operation = l.operation;
    new_var->value = l.value;
    new_var->id = l.id; 
    new_var->arg = l.arg; 
    return new_var;
}

// **************************************************************************
// *                                   ADD                                  *    
// **************************************************************************

Variable operator+ (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::add;
    // continue
    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable operator+ (const double &a, const Variable &b) {
    Variable new_var = Variable(false);
    new_var.operation = op::add; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = a_var;
    new_var.child[1] = copy_contents_var(b);
    return new_var;
}

Variable operator+ (const Variable &b, const double &a) {
    Variable new_var = Variable(false);
    new_var.operation = op::add; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // create new var for b
    new_var.child[0] = copy_contents_var(b);
    new_var.child[1] = a_var;
    return new_var;
}



// **************************************************************************
// *                             SUBTRACT                                   *    
// **************************************************************************

Variable operator- (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::subtract;
    // continue
    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable operator- (const double &a, const Variable &b) {
    Variable new_var = Variable(false);
    new_var.operation = op::subtract; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = a_var;
    new_var.child[1] = copy_contents_var(b);
    return new_var;
}

Variable operator- (const Variable &b, const double &a) {
    Variable new_var = Variable(false);
    new_var.operation = op::subtract; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = copy_contents_var(b);
    new_var.child[1] = a_var;
    return new_var;
}


// **************************************************************************
// *                             MULTIPLY                                   *    
// **************************************************************************

Variable operator* (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::multiply;
    // continue
    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable operator* (const double &a, const Variable &b) {
    Variable new_var = Variable(false);
    new_var.operation = op::multiply; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = a_var;
    new_var.child[1] = copy_contents_var(b);
    return new_var;
}

Variable operator* (const Variable &b, const double &a) {
    Variable new_var = Variable(false);
    new_var.operation = op::multiply; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // create new var for b
    // combine both vars
    new_var.child[0] = copy_contents_var(b);
    new_var.child[1] = a_var;
    return new_var;
}

// **************************************************************************
// *                               DIVIDE                                   *    
// **************************************************************************

Variable operator/ (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::divide;
    // continue
    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable operator/ (const double &a, const Variable &b) {
    Variable new_var = Variable(false);
    new_var.operation = op::divide; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = a_var;
    new_var.child[1] = copy_contents_var(b);
    return new_var;
}

Variable operator/ (const Variable &b, const double &a) {
    Variable new_var = Variable(false);
    new_var.operation = op::divide; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = copy_contents_var(b);
    new_var.child[1] = a_var;
    return new_var;
}

// **************************************************************************
// *                               EXPONENT                                 *    
// **************************************************************************

Variable operator^ (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false);
    new_var.operation = op::exponent;
    // continue
    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable operator^ (const double &a, const Variable &b) {
    Variable new_var = Variable(false);
    new_var.operation = op::exponent; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = a_var;
    new_var.child[1] = copy_contents_var(b);
    return new_var;
}

Variable operator^ (const Variable &b, const double &a) {
    Variable new_var = Variable(false);
    new_var.operation = op::exponent; 
    // create new var for a 
    Variable *a_var = new Variable(true);
    a_var->operation = op::argument;
    a_var->value = a;
    // combine both vars
    new_var.child[0] = copy_contents_var(b);
    new_var.child[1] = a_var;
    return new_var;
}


// **************************************************************************
// *                                  MIN.                                  *    
// **************************************************************************

Variable min_op (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false); 
    new_var.operation = op::min;

    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right); 
    return new_var;
}

Variable min_op (const Variable &a, const double b) {
    // create b var
    Variable *b_var = new Variable();
    b_var->value = b;
    b_var->operation = op::argument;

    Variable new_var = Variable(false);
    new_var.operation = op::min; 
    new_var.child[0] = copy_contents_var(a);
    new_var.child[0] = b_var;
    return new_var;
}

Variable min_op (double b, const Variable &a) {
    Variable *b_var = new Variable();
    b_var->value = b;
    b_var->operation = op::argument;

    Variable new_var = Variable(false);
    new_var.operation = op::min; 
    new_var.child[0] = b_var;
    new_var.child[1] = copy_contents_var(a);
    return new_var;
}


// **************************************************************************
// *                                  MAX.                                  *    
// **************************************************************************


Variable max_op (const Variable &left, const Variable &right) {
    Variable new_var = Variable(false); 
    new_var.operation = op::max;

    new_var.child[0] = copy_contents_var(left);
    new_var.child[1] = copy_contents_var(right);
    return new_var;
}

Variable max_op (const Variable &a, const double b) {
    Variable *b_var = new Variable();
    b_var->value = b;
    b_var->operation = op::argument;
    
    Variable new_var = Variable(false);
    new_var.operation = op::max; 
    new_var.child[0] = copy_contents_var(a);
    new_var.child[1] = b_var;
    return new_var;
}

Variable max_op (const double b, const Variable &a) {
    Variable *b_var = new Variable();
    b_var->value = b;
    b_var->operation = op::argument;
    
    Variable new_var = Variable(false);
    new_var.operation = op::max; 
    new_var.child[0] = b_var;
    new_var.child[1] = copy_contents_var(a);
    return new_var;
}

// **************************************************************************
// *                                   CLIP                                 *    
// **************************************************************************

Variable Variable::clip (double min, double max) {
    Variable new_var = Variable(false);
    
    Variable *min_var = new Variable();
    min_var->value = min;
    min_var->operation = argument;
    
    Variable *max_var = new Variable();     
    max_var->value = max;
    max_var->operation = argument; 
    
    new_var.child[0] = min_var;
    new_var.child[1] = max_var;
    new_var.operation = op::clip; 
    new_var.arg = this; 
    return new_var; 
}

Variable Variable::clip (const Variable &min, const Variable &max) {
    Variable new_var = Variable(false);
    new_var.child[0] = copy_contents_var(min);
    new_var.child[1] = copy_contents_var(max);
    new_var.operation = op::clip;
    new_var.arg = this;
    return new_var;
}



Variable Variable::clip (double min, const Variable &max) {
    Variable new_var = Variable(false);
    
    Variable *min_var = new Variable();
    min_var->value = min;
    min_var->operation = argument;
    
    new_var.child[0] = min_var;
    new_var.child[1] = copy_contents_var(max); 
    new_var.operation = op::clip; 
    new_var.arg = this;
    return new_var;
}

Variable Variable::clip (const Variable &min,  double max) {
    Variable new_var = Variable(false);
    
    Variable *max_var = new Variable();
    max_var->value = max;
    max_var->operation = argument;
    
    new_var.child[0] = copy_contents_var(min); 
    new_var.child[1] = max_var;
    new_var.operation = op::clip; 
    new_var.arg = this;
    return new_var;
}

// **************************************************************************
// *                                 SIN/COS.                               *    
// **************************************************************************

Variable Variable::cos_radians () {
    Variable new_var = Variable(false); 
    new_var.operation = op::cos_r_op;
    new_var.child[0] = this;
    return new_var;
}

Variable Variable::sin_radians () {
    Variable new_var = Variable(false); 
    new_var.operation = op::sin_r_op;
    new_var.child[0] = this;
    return new_var;
}

Variable Variable::cos_degrees () {
    Variable new_var = Variable(false); 
    new_var.operation = op::cos_d_op;
    new_var.child[0] = this;
    return new_var;
}

Variable Variable::sin_degrees () {
    Variable new_var = Variable(false); 
    new_var.operation = op::sin_d_op;
    new_var.child[0] = this;
    return new_var;
}