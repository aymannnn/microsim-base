# Description

This repository contains code to create a microsimulation project in C++. Specifically, a disease modeling microsimulation. All of the code is in source/. The only dependency is Boost, which is what I use for random number generation and for statistical distributions.

Currently devleoping on Windows (since it's what I use at my research facility) but I will be testing for compatability with GCC and CLANG soon, after the more important things TODO are done.

The overall purpose of this project is twofold: 1) to increase the speed at which I can write simulation models for the work that I do and 2) set up a standard so that documentation of future models is easy and the models themselves are maintainable. In general, research code tends to be sloppy; most people, like me, are not programmers by training but rather have learned as we go. Partially, this project is for me to work on design and benchmarking algorithm implementations, something that I lack as a consequence of my on-the-fly experience.


# To do:

* Incorporate basic calibration code and provide multiple parameter search methods. Most of the interface will be settings modifyable by external configuration files.
* Start writing documentation in parallel to code.
* Write a basic example projects; a tumor growth project, an agent-based one, and a simple microsimulation.
