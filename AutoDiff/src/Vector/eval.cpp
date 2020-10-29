#include "Vector.hpp"

Vector Vector::eval (vector<double> input) {
    vector<int> input_map;
    vector<int> IDs[this->width];
    for (int i = 0; i < this->width; i++) {
        // find unique ID;
        this->array[i].find_unique_id(&IDs[i], &input_map); 
    }
    if (input_map.size() != input.size()) {
        throw invalid_argument("Error when evaluating vector: invalid size. Expected " + to_string(input_map.size()));
    }
    Vector new_vec = Vector(this->width);
    for (int i = 0; i < this->width; i++) {
        // map input
        vector<double> input_m;
        for (auto x : IDs[i]) {
            for (int f = 0; f < input_map.size(); f++) {
                if (input_map[f] == x) {    
                    input_m.push_back(input[f]);
                    break;
                }
            }
        } 
        new_vec.array[i].value = this->array[i].eval(input_m);
        new_vec.array[i].operation = op::argument;
    }
    return new_vec;
}