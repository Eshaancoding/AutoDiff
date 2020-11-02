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