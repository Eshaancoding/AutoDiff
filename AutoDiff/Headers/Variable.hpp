//
//  AutoDiff.h
//  AutoDiff
//
//  Created by Eshaan Arnav on 9/23/20.
//
#ifndef VARIABLE_HPP
#define VARIABLE_HPP

#include <iostream>
#include <vector>
#include <cmath>
#include <assert.h>
using namespace std;

enum op {
    input,    // special
    argument, // special
    add,
    subtract,
    divide,
    multiply,
    exponent,
    nan_op,
    min,
    max, 
    clip,
    sin_d_op,
    cos_d_op,
    sin_r_op,
    cos_r_op,
};

class Variable {
public:
    // helper func vec / mat (defined eval.cpp)
    void find_unique_id (vector<int> *ID_ARRAY, vector<int> *input_map);
    // variables
    double value;
    op operation;
    Variable* child[2];
    int id = -1; 
    Variable* arg;
    // init (Var.cpp)
    Variable (bool t = true);
    // eval functions (src/evalEq.cpp)
    double eval (vector<double> input, bool is_top_node = true);
    double exec_op (double num_one, op operation, double num_two);
    // dir eval (src/gradEq.cpp)
    vector<double> grad (vector<double> input, op last_operation = op::nan_op, double ERROR_NODE = 1, bool top_node = true, double other_value = std::nan("-1"), bool left=true);
    double dir_eval (double x, op operation, double y = std::nan("-1"), bool respect_x = true); 
    // operations (src/operationsEq.cpp)
    void operator= (double num);
    Variable cos_radians ();
    Variable sin_radians (); 
    Variable cos_degrees ();
    Variable sin_degrees ();
    Variable clip (double min, double max);
    Variable clip (const Variable &min, const Variable &max);
    Variable clip (double min, const Variable &max); 
    Variable clip (const Variable &min, double max);  
};

// operations (src/operationsEq.cpp)
Variable operator+ (const Variable &left, const Variable &right);
Variable operator+ (const Variable &b, const double &a);
Variable operator+ (const double &a, const Variable &b);

Variable operator- (const Variable &left, const Variable &right);
Variable operator- (const Variable &b, const double &a);
Variable operator- (const double &a, const Variable &b);

Variable operator* (const Variable &left, const Variable &right);
Variable operator* (const Variable &b, const double &a);
Variable operator* (const double &a, const Variable &b);

Variable operator/ (const Variable &left, const Variable &right);
Variable operator/ (const Variable &b, const double &a);
Variable operator/ (const double &a, const Variable &b);

Variable operator^ (const Variable &left, const Variable &right);
Variable operator^ (const Variable &b, const double &a);
Variable operator^ (const double &a, const Variable &b);

Variable min_op (const Variable &left, const Variable &right);
Variable min_op (const Variable &a, const double b);
Variable min_op (const double b, const Variable &a);

Variable max_op (const Variable &left, const Variable &right);
Variable max_op (const Variable &a, const double b);
Variable max_op (const double b, const Variable &a);

#endif 