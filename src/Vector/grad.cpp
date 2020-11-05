#include "Vector.hpp"
#include "Matrix.hpp"

Matrix Vector::grad (vector<double> input ) {
    if (this->width <= -1) throw invalid_argument("Vector not initialized ");
    // vector<int> input_map;
    // vector<int> IDs[this->width];
    // for (int i = 0; i < this->width; i++) {
    //     // find unique ID;
    //     this->array[i].find_unique_id(&IDs[i], &input_map); 
    // }
    // if (input_map.size() != input.size()) {
    //     throw invalid_argument("Error when calculating gradient of vector: invalid size. Expected " + to_string(input_map.size()));
    // }
    // // get maximum size of variables
    // int max_size = -1;
    // for (int i = 0; i < this->width; i++) {
    //     if (IDs[i].size() > max_size) {
    //         max_size = IDs[i].size();
    //     }
    // }
    // // initalize grad
    // Matrix grad = Matrix(this->width, max_size);
    
    // for (int i = 0; i < this->width; i++) {
    //     // reset grad
    //     for (int x = 0; x < max_size; x++) {
    //         grad.array[i * grad.height + x].operation = op::argument;
    //         grad.array[i * grad.height + x].value = 0;
    //     }
    //     // map input
    //     vector<double> input_m;
    //     for (auto x : IDs[i]) {
    //         for (int f = 0; f < input_map.size(); f++) {
    //             if (input_map[f] == x) {    
    //                 input_m.push_back(input[f]);
    //                 break;
    //             }
    //         }
    //     }  
    //     // get grad
    //     vector<double> grad_i = this->array[i].grad(input_m);
    //     // assign grad
    //     for (int x = 0; x < grad_i.size(); x++) {
    //         grad.array[i * grad.height + x].value = grad_i[i];
    //     }
    // }
    return Matrix(2,2);
}