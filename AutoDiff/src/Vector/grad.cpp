#include "Vector.hpp"

Vector Vector::grad (vector<double> input ) {
    vector<int> input_map;
    vector<int> IDs[this->width];
    for (int i = 0; i < this->width; i++) {
        // find unique ID;
        this->array[i].find_unique_id(&IDs[i], &input_map); 
    }
    if (input_map.size() != input.size()) {
        throw invalid_argument("Error when calculating gradient of vector: invalid size. Expected " + to_string(input_map.size()));
    }
    Vector grad = Vector(input_map.size());
    // reset val
    for (int i = 0; i < grad.width; i++) {
        grad.array[i].value = 0;
    }
    for (int i = 0; i < this->width; i++) {
        grad.array[i].operation = op::argument;
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
        vector<double> grad_array = this->array[i].grad(input_m);
        // check if grad_array size is valid
        if (grad_array.size() != IDs[i].size()) {
            throw invalid_argument("grad array invalid");
        }
        // turn grad_array into the grad :)
        for (int x = 0; x < grad_array.size(); x++) {
            for (int g = 0; g < input_map.size(); g++) {
                if (input_map[g] == IDs[i][x]) {
                    grad.array[g].value += grad_array[x]; 
                    break;
                }
            }
        }  
    }
    return grad;
}