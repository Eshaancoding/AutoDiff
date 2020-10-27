## Implementing the Computational graph.

- I tried various forms of variables operators
I wanted to do namespace, and to create a global variable
Then I learned about lvalue and rvalue and stuff, and all I had to do is 
make a copy of the temperary value. At first I was hesistant about this,
because I was worried about effiecency, but then I was like you know what
let's just do it. It turned out good after that.

- Now onto making sure that we don't have to input two values when we eval x + x. 
I was thinking of creating an ID system. Where we create an ID for each variable. The combined variables
(ex: x + x) have an ID of -1. 
Then we also have to update our eval.cpp and grad.cpp according to our ID system.
Not too much errors for eval.cpp

- Now i'm testing a Rediculous equation:
(x + 3) - (x^2) / ((y*y / x) - 3);
and checking my answer with desmos :)
eval is fine, grad isn't. (as always lol)

- The problem was that I was calculating the derivative with respect to x. Which is fine if we are only passing down 
the error to the left node. But it's not fine when we are passing the error to the right node. So therefore we need
calculate the error with respect to y :)
After so much debugging, I finally got it working :) YEAAAAAAAAAA

## Adding MORE operations!!!!! 
- I need some operations that support the PPO surrogate loss, as I think I am going to use
PPO as my next video. So I need to add operations that are: min, max, clip, sin, cos
Implementing clip, sin, and cos was fine.
Implementing min and max was also fine, except on one thing.

- GRAD wasn't producing the same results when executed twice, for example:
```c
result = min_op(x^4, y^3)
cout<<result.grad({0,5}) // this wasn't the 
cout<<result.grad({0,5}) // same as this :(
``` 

- I had to make sure that I set the error to zero to the other argument. The error would go the equation x^4, since that the min value. But the error is also suppose to go to y^3, but just as error 0. If I don't do this, it would cause random results. 

-  I also noticed the importance of memory leaks.
Thankfully, I don't need to incoperate memory leaks into this project because there are no "unused memory". Every memory allocated with the new operation is important. However, when I work with future projects, then decreasing memory leaks will be important since it gives more room to the RAM. 

## Matrix 
I need this to represent the policy of the neural network (for PPO). So I need to add operations that adds, subtract, dot product, multiply, etc. And I also need to figure out how to calc the partial derivative of that :( This actually introduces to Jacobian matrixes 

Suprisingly definition operator overloading was not that hard. Most of the grunt work was already done for me when I was writing the operators for equations

### Testing the WHOLE THING out using the Surrogate loss! 


### EXEC:
clear && c++ -I AutoDiff/Headers/ AutoDiff/src/* main.cpp && ./a.out && rm a.out

Or you can take the compiled library in the lib folder and use it there :) 
