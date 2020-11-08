//  dir.cpp
//  AutoDiff
//  Created by Eshaan Arnav on 9/23/20.

#include "Variable.hpp"

void print_array (vector<double> array, string name = "") {
    if (name != "") {
        cout<<name<<": ";
    }
    for (auto a : array) {
        cout<<a<<" ";
    }
    cout<<endl; 
}

double r_to_d (double r) {
    return r * (180/3.1415926);
}

double d_to_r (double d) {
    return d * (3.1415926/180); 
}

double Variable::dir_eval (double x, op operation, double y, bool respect_x) {
    if (operation == op::add) return 1;
    if (operation == op::multiply) return y;
    if (operation == op::min) return 1;
    if (operation == op::max) return 1;
    if (operation == op::clip) return 1; 
    if (operation == op::sin_d_op) return d_to_r(cos(r_to_d(x))); 
    if (operation == op::sin_r_op) return cos(x);
    if (operation == op::cos_d_op) return d_to_r(-sin(r_to_d(x)));
    if (operation == op::cos_r_op) return -sin(x); 
    if (respect_x) {
        if (operation == op::subtract) return 1;
        if (operation == op::divide) return 1 / y;
        if (operation == op::exponent) return y * pow(x, y - 1);
    } else {
        if (operation == op::subtract) return -1;
        if (operation == op::divide) return (-y) / pow(x,2);
        if (operation == op::exponent) return pow(y,x)*log10(y);
    }
    cout<<"ERROR OPERATION: "<<operation<<endl; 
    throw invalid_argument("operation not valid when running dir_eval()");
}

vector<double> Variable::grad (vector<double> input, op last_operation, double ERROR_NODE, bool top_node, double other_value, bool left) {
    static vector<double> GRAD_OUTPUT = {};
    static vector<int> ID_ARRAY = {};
    static vector<int> input_index = {};
    static int INDEX = 0;
    double error = ERROR_NODE;

    if (top_node) {
        this->eval(input); // get values
        GRAD_OUTPUT.clear();
        ID_ARRAY.clear();
        input_index.clear();
        INDEX = 0;
        // we already computed error_node (1), pass to sub nodes
    } 
    else {
        // compute error_node
        error *= this->dir_eval(this->value, last_operation, other_value, left);
    }
    // pass error node to sub nodes and execute
    if (this->operation == op::clip) {
        if (this->arg->value >= this->child[0]->value && 
            this->arg->value <= this->child[1]->value) {
            // in range of clip
            this->arg->grad({}, this->operation, error, false);    
        } else {
            this->arg->grad({}, this->operation, 0, false);
        }
    }
    else if (this->operation == op::min) {
        // determine what child
        if (this->child[0]->value >= this->child[1]->value) {
            this->child[0]->grad({}, this->operation, 0, false, this->child[1]->value, false);
            this->child[1]->grad({}, this->operation, error, false, this->child[0]->value, true); 
        } else {
            this->child[0]->grad({}, this->operation, error, false, this->child[1]->value, false); 
            this->child[1]->grad({}, this->operation, 0, false, this->child[0]->value, true); 
        }
    } 
    else if (this->operation == op::max) {
        if (this->child[0]->value >= this->child[1]->value) {
            this->child[0]->grad({}, this->operation, error, false, this->child[1]->value, true); 
            this->child[1]->grad({}, this->operation, 0, false, this->child[0]->value, false); 
        } else {
            this->child[0]->grad({}, this->operation, 0, false, this->child[1]->value, true); 
            this->child[1]->grad({}, this->operation, error, false, this->child[0]->value, false); 
        }
    }
    else if (this->child[0] != NULL) {
        if (this->child[1] != NULL) {
            // operation is a two parameter function (e.i plus, multiply, subtract, etc...) 
            this->child[0]->grad({},this->operation, error, false, this->child[1]->value, true);
            this->child[1]->grad({},this->operation, error, false, this->child[0]->value, false);
        } else {
            // operation is a one parameter function (e.i sin, cos, atan)
            this->child[0]->grad({},this->operation, error, false);
        }
    } else if (this->operation == op::input) {
        // append to grad_output
        bool find = false;
        for (int i = 0; i < ID_ARRAY.size(); i++) {
            if (this->id == ID_ARRAY[i]) {
                find = true;
                GRAD_OUTPUT[input_index[i]] += error;
                break;
            }
        }
        if (!find) {
            input_index.push_back(INDEX); 
            ID_ARRAY.push_back(this->id);                
            INDEX++;
            GRAD_OUTPUT.push_back(error);
        }
    }
    if (top_node) {
        return GRAD_OUTPUT;
    } else {
        return {};
    }
}