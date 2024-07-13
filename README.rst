==========
fastercast
==========

An attempt at making Python's `typing.cast <https://docs.python.org/3/library/typing.html#typing.cast>`_ faster by writing in C.

Random Benchmark
---------------
Calculated by running ``python benchmark.py`` on Windows 10 (WSL). It's not comprehensive, but it shows potential:

Python3.9::

    python version: 3.9
    ---- Testing with type: list[int] ----
    typing.cast:     3.465584092999052
    fastercast.cast: 1.9172640960023273
    no cast:         1.4130047959988588

    ---- Testing with type: <class 'list'> ----
    typing.cast:     3.4464493919986126
    fastercast.cast: 1.9092626999990898
    no cast:         1.4313703090010677

    ---- Testing with type: 'list' ----
    typing.cast:     3.424010521001037
    fastercast.cast: 1.9051031120034168
    no cast:         1.463806901996577

Python3.12::

    python version: 3.12
    ---- Testing with type: list[int] ----
    typing.cast:     2.0208555909994175
    fastercast.cast: 1.5888119939991157
    no cast:         1.2391334939966328

    ---- Testing with type: <class 'list'> ----
    typing.cast:     2.0552524880004057
    fastercast.cast: 1.558741792003275
    no cast:         1.2164903929988213

    ---- Testing with type: 'list' ----
    typing.cast:     2.1068942889978644
    fastercast.cast: 1.5963142889995652
    no cast:         1.226719090998813
