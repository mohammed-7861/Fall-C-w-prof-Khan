# One thing you learned about implicit vs explicit conversion.

At first I was a bit lost in the sense that I didn't know what the difference was between explicit and implicit conversion. After doing some research I realized that it wasn't that difficult to understand. Implicit conversion is basically where the compiler automatically assumes that something is an integer, whereas in explicit conversion, you can explicitly state if you want a certain number to be a double or an integer. In explicit, you can make the compiler change the way it sees a number whereas in implicit the compiler chooses for you, and it might not always give you the result you were looking for.


# One bug you fixed and how you found it.

One big I fixed was in part D of the assignment where the code written was :
```c++ 
double discount = total * (static_cast<double>(discountPercent) / 100.0);
```
I fixed this error by attempting to run the code and then recieving an error message saying that there was a syntactic error. I looked more closely at the area where the error appeared and noticed that there was an extra set of parenthesis where there didn't need to be. Of course this wasn't the most pleasent form of troubleshooting, but it allowed me to find and fix my error. 
