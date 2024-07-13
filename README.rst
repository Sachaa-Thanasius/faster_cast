==========
fastercast
==========

An attempt at making Python's `typing.cast <https://docs.python.org/3/library/typing.html#typing.cast>`_ faster by writing in C.

Random Benchmark
---------------
Calculated by running ``python benchmark.py`` on Windows 10 (WSL) with python3.9:::

    python version: 3.9
    ---- Testing with type: list[int] ----
    typing.cast:     3.3762012170009257
    fastercast.cast: 2.126949010998942
    no cast:         1.474510318999819

    ---- Testing with type: <class 'list'> ----
    typing.cast:     3.527785660000518
    fastercast.cast: 2.0718492360028904
    no cast:         1.500492025999847

    ---- Testing with type: 'list' ----
    typing.cast:     3.4441693799999484
    fastercast.cast: 1.911562644996593
    no cast:         1.4730412349999824
