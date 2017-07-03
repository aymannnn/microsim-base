# Description

This repository contains code to create a microsimulation project in C++. Specifically, a disease modeling microsimulation. This setup is what has worked the best for me in the past. To use, open the solution file and export a template. For more information, see

https://msdn.microsoft.com/en-us/library/xkh1wxd8.aspx

# Dependencies

Boost.

Also, this project is coded as a visual studio project, but you can extract the files and use a different build system.

# To do ...

* Incorporate basic calibration code; implement greedy search, simulated annealing, greedy descent with simulated annealing at local minmium solutions.
* Update parser and RNG files.
* Remove dependency on PCH.
* Include basic life tables (2012) and show an example with a single cohort.
