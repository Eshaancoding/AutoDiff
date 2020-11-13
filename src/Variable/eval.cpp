//  eval.cpp
//  AutoDiff
//  Created by Eshaan Arnav on 9/23/20.

#include "Variable.hpp"

const double pi = 3.1415926;

double Variable::exec_op(double num_one, op operation, double num_two) {
    if (operation == add) return num_one + num_two;
    else if (operation == subtract) return num_one - num_two;
    else if (operation == multiply) return num_one * num_two;
    else if (operation == divide) return num_one / num_two;
    else if (operation == exponent) return pow(num_one, num_two);
    else if (operation == op::min && num_one > num_two) return num_two;
    else if (operation == op::min && num_one < num_two) return num_one;
    else if (operation == op::max && num_one > num_two) return num_one;
    else if (operation == op::max && num_one < num_two) return num_two; 
    else if (operation == op::sin_r_op) return sin(num_one);
    else if (operation == op::cos_r_op) return cos(num_one);
    else if (operation == op::sin_d_op) return sin(num_one * (pi/180)); 
    else if (operation == op::cos_d_op) return cos(num_one * (pi/180)); 
    else {throw invalid_argument("exec op error");}
}

double Variable::eval (bool is_top_node) {
    static int INPUT_ITERATION = 0;
    static vector<int> value_index;
    static vector<int> id_array;
    if (is_top_node) { 
        INPUT_ITERATION = 0;
        id_array.clear();
        value_index.clear();
    }
    if (this->operation == op::clip) {
        // get values
        this->arg->eval(false);
        this->child[0]->eval(false);
        this->child[1]->eval(false);
        // check if max is less than min, or vise versa. (Gives out warning)
        if (this->child[0]->value >= this->child[1]->value) {
            string red = "\033[4;34m";
            string normal = "\033[0m"; 
            cout<<red<<"Warning:"<<normal<<" min is more than / equal to max"<<endl; 
        }
        // do actual clip operations
        if (this->arg->value >= this->child[0]->value &&
            this->arg->value <= this->child[1]->value) {
            // in range
            this->value = this->arg->value;
            return this->value;
        } else if (this->arg->value <= this->child[0]->value) {
            this->value = this->child[0]->value; 
            return this->value;
        } else {
            this->value = this->child[1]->value;
            return this->value;
        }
    }
    else if (this->child[0] != NULL) {
        // this is called binary tree traversal
        // execute left child
        double input_one = this->child[0]->eval(false);
        // execute right child (may not work becuase of 1 input function)
        double input_two = 0;
        if (this->child[1] != NULL) input_two = this->child[1]->eval(false);
        this->value = this->exec_op(input_one, this->operation, input_two);
        // could throw weird numbers (for ex: 3.344105426e74)
        return this->value;
    }
    else {
        // input
        if (this->operation == op::argument || this->operation == op::input) return this->value;
        else {throw invalid_argument("No children return error");}
    }
}

void Variable::find_unique_id (vector<int> *ID_ARRAY, vector<int> *input_map) {
    if (this->child[0] != NULL && child[1] != NULL) {
        if (this->child[1] != NULL) {
            this->child[0]->find_unique_id(ID_ARRAY, input_map);
            this->child[1]->find_unique_id(ID_ARRAY, input_map);
        } else {
            this->child[0]->find_unique_id(ID_ARRAY, input_map);
        }
    } else {
        if (this->operation == op::input) {
            // ID_ARRAY
            bool found = false;
            for (auto i : *ID_ARRAY) {
                if (i == this->id) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                ID_ARRAY->push_back(this->id);   
            }
            // input-map
            found = false;
            for (auto i : *input_map) {
                if (i == this->id) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                input_map->push_back(this->id);
            }
        }
    }
}