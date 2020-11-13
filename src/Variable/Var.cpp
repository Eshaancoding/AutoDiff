#include "Variable.hpp"

Variable::Variable (double value, bool t) {
    this->child[0] = nullptr;
    this->child[1] = nullptr;
    this->arg = nullptr;
    this->operation = op::input; 
    this->value = value;
    static int id_counter = 0;
    if (t) {
        id_counter++;
        this->id = id_counter;
    }
}