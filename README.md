# Determine-zeros

This project is about different ways to determine zeros of a polynomial function.

## Methods

### Bisection method (interval halving method)
Conditions: The function has to be coninious.
Procedure: Firstly, determine an interval with a changing sign. After that, cut the interval in half and check on wich side the zero is. Than do the same with the new (smaller) interval again until the third decimal place is not changing anymore.
##### Structogram
![bisection](https://github.com/JoBo33/Determine-zeros/blob/main/Diagrams/bisection%20structogram.png "bisection structogram")
##### Example
> f(x) = x<sup>2</sup>-2

Firstly, find the interval. Therefore, use x-values as simple as possible. Here one can use 0 and 2 to get -2 and 2. So, the sign is changing in this interval. Now, find the middle of the interval.  
a = 0  
b = 2  
x = (a+b)/2  ((0+2)/2 = 1)  
After that, calculate the output of 1. f(x) = 1<sup>2</sup>-2 = -1
For the next iteration a = x because f(a) and f(x) have the same sign.
![bisection](https://github.com/JoBo33/Determine-zeros/blob/main/Examples/Bisection%20example%20table.png "bisection example table")
### Regula falsi
Conditions: The function has to be coninious and to determine the zero, the zero has to be in the given interval.  
Formula: 
> x<sub>n+1</sub> = (x<sub>n-1</sub>*f(x<sub>n</sub>)-x<sub>n</sub>*f(x<sub>n-1</sub>))/(f(x<sub>n</sub>-f(x<sub>n-1</sub>)) 

The algorithm determines if the third decimal place did not change between 2 iterations.  
##### Structogram
![Regula falsi](https://github.com/JoBo33/Determine-zeros/blob/main/Diagrams/regulaFalsi%20structogram.png "Regula falsi structogram")
##### Example
> f(x) = x<sup>3</sup>-2x+2 [-2;0]

Firstly, one have to check if the sign is changing between the begin and end of the interval. If one insert -2 into the given function, one will get the value -2. On the other hand, if one put the end of the interval in the function, one will get the value 2. So, one can see that the sign is changing. After that, the begin of the interval is going to be the x<sub>n-1</sub> and the end of the interval is going to be the x<sub>n</sub> for the first iteration. After getting the x<sub>n+1</sub>, the f(x<sub>n+1</sub>) will be calculated. With help of this value, the next x<sub>n-1</sub> and  x<sub>n</sub> will be determined. One just have to take a look to the sign of the three output values and change the value of x<sub>n-1</sub> and  x<sub>n</sub> to x<sub>n+1</sub> depending on wich output value have the same sign like f(x<sub>n+1</sub>).
As one can see in the following table, the algorithm determines after 7 iteration because the x<sub>n+1</sub> value is equal to x<sub>n</sub> up to three decimal places and the zero was found.
![regula-falsi](https://github.com/JoBo33/Determine-zeros/blob/main/Examples/Regula%20falsi%20example%20table.png "Regula falsi example table")

### Newton-Raphson-method
Condition: The function must not be linear. Furthermore the derivative (f prime) has to be not null. Lastly, the startpoint has to be near the zero.  
Formula: 
> x<sub>n+1</sub>  = x<sub>n</sub> - f(x<sub>n</sub>) / f'(x<sub>n</sub> )

The algorithm determines if the third decimal place did not change between 2 iterations. 
##### Structogram
![Newton-Raphson](https://github.com/JoBo33/Determine-zeros/blob/main/Diagrams/NewtonRaphson%20structogram.png "Newton-Raphson structogram")
##### Example
> f(x) = x<sup>3</sup>+3x<sup>2</sup>-x-8  
> f'(x) = 3x<sup>2</sup>+6x-1

startpoint x<sub>0</sub> = 1  
Insert x<sub>0</sub> into f(x) and f'(x). Now, one can fill the formula and calculate the next x-value. Repeat these steps, until the third decimal place is not changing anymore.  
![Newton-Raphson](https://github.com/JoBo33/Determine-zeros/blob/main/Examples/Newton-Raphson%20example%20table.png "Newton-Raphson example-table")
## GUI-concept
![GUI](https://github.com/JoBo33/Determine-zeros/blob/main/Examples/GUI-concept.png "GUI-concept")





















