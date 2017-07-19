# Description

This repository contains code to create a microsimulation project in C++. Specifically, a disease modeling microsimulation. This setup is what has worked the best for me in the past
# Dependencies

Boost.

# Operating Systems

Windows, testing for compatability with GCC and CLANG soon, after the more important things TODO are done.

# To do ...

* Incorporate basic calibration code; implement greedy search, simulated annealing, greedy descent with simulated annealing at local minmium solutions.
* Update parser and RNG files. (DONE)
* Remove dependency on PCH. (DONE)
* Include basic life tables (2012) and show an example with a single cohort.
* See if there is a cleaner way to sort though literature parameters; perhaps with a map? A method that makes it not as difficult to manage.