==========
fastercast
==========

An attempt at making Python's `typing.cast <https://docs.python.org/3/library/typing.html#typing.cast>`_ faster by writing in C.

Random Benchmark
---------------
Note: Numbers are the output of running `python benchmark.py` after installing the package. Currently tests `list[int]`, `list`, and `"list"`::

    ---- Testing with type: list[int] ----
    typing.cast:     2.4610866919974796
    fastercast.cast: 1.7257666940022318
    no cast:         1.3628550940011337

    ---- Testing with type: <class 'list'> ----
    typing.cast:     2.5556980910005223
    fastercast.cast: 1.7648501980002038
    no cast:         1.3131538080015162

    ---- Testing with type: 'list' ----
    typing.cast:     2.627829914999893
    fastercast.cast: 1.7981364110019058
    no cast:         1.2604371079978591
