import timeit
from functools import partial

from typing import cast as tpcast
from fastercast import cast as fcast


def main():
    def test_no_func():
        sum = 0
        for i in range(20000):
            i = i
            sum += i

    def test_func(typ, func):
        sum = 0
        for i in range(20000):
            i = func(typ, i)
            sum += i

    iterations = 3_000
    test_types = [list[int], list, "list"]
    for typ in test_types:
        print(f"---- Testing with type: {typ!r} ----")
        print("typing.cast:    ", timeit.timeit(partial(test_func, typ, tpcast), number=iterations))
        print("fastercast.cast:", timeit.timeit(partial(test_func, typ, fcast), number=iterations))
        print("no cast:        ", timeit.timeit(test_no_func, number=iterations))
        print()


if __name__ == "__main__":
    raise SystemExit(main())
