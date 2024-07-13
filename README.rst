==========
fastercast
==========

An attempt at making Python's `typing.cast <https://docs.python.org/3/library/typing.html#typing.cast>`_ faster by writing in C.

Random Benchmark
---------------
Note: Numbers are the output of running ``python benchmark.py`` after installing the package. Currently tests ``list[int]``, ``list``, and ``"list"``::

    ---- Testing with type: list[int] ----
    typing.cast:     2.120711169001879
    fastercast.cast: 1.4870567479993042
    no cast:         1.0273198340000818

    ---- Testing with type: <class 'list'> ----
    typing.cast:     2.0532028609995905
    fastercast.cast: 1.4377407290012343
    no cast:         1.0522564219972992

    ---- Testing with type: 'list' ----
    typing.cast:     2.0583050429995637
    fastercast.cast: 1.4673071300021547
    no cast:         1.053293021999707
