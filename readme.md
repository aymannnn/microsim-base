# Description

This repository contains code to create a microsimulation project in C++. Specifically, a disease modeling microsimulation. All of the code is in source/ (if you'd like to see how I write). The only dependency is Boost, which is what I use for random number generation and for distributions.

Currently devleoping on Windows (since it's what I use at my research facility) but I will be testing for compatability with GCC and CLANG soon, after the more important things TODO are done.

# To do ...

* Incorporate basic calibration code; implement greedy search, simulated annealing, greedy descent with simulated annealing at local minmium solutions.
* See if there is a cleaner way to sort though literature parameters; perhaps with a map? A method that makes it not as difficult to manage.
* Actually start writing documentation while writing code ... 
