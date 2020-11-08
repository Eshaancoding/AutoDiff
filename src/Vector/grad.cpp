#include "Vector.hpp"
#include "Matrix.hpp"
#include "Variable.hpp"

Matrix Vector::grad (vector<double> input) {
    if (this->width <= -1) throw invalid_argument("Vector not initialized ");
    vector<int> input_map;
    vector<int> IDs[this->width];
    for (int i = 0; i < this->width; i++) {
        // find unique ID;
        this->array[i].find_unique_id(&IDs[i], &input_map); 
    }
    if (input_map.size() != input.size()) {
        throw invalid_argument("Error when calculating gradient of vector: invalid size. Expected " + to_string(input_map.size()));
    }
    // get maximum size of variables
    int max_size = IDs[0].size();
    for (int i = 1; i < this->width; i++) {
        if (IDs[i].size() > max_size) {
            max_size = IDs[i].size();
        }
    }
    // initalize grad
    Matrix grad = Matrix(this->width, max_size);
    
    for (int i = 0; i < this->width; i++) {
        // reset grad
        for (int x = 0; x < max_size; x++) {
            grad.array[i].array[x].operation = op::argument;
            grad.array[i].array[x].value = 0;
        }
        vector<double> input_m;
        vector<int> indexs; 
        for (auto x : IDs[i]) {
            for (int f = 0; f < input_map.size(); f++) {
                if (input_map[f] == x) {    
                    indexs.push_back(f);
                    input_m.push_back(input[f]);
                    break;
                }
            }
        }  
        // get grad
        vector<double> grad_i = this->array[i].grad(input_m);
        // assign grad
        for (int x = 0; x < grad_i.size(); x++) {
            grad[i][indexs[x]] = grad_i[x];
        }
    }
    return grad;
}