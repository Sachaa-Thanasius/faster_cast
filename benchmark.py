import sys
import timeit
from functools import partial

from typing import cast as tpcast
from fastercast import cast as fcast


def main():
    def test_no_func():
        sum = 0
        for i in range(1000):
            sum += i

    def test_func(typ, func):
        sum = 0
        for i in range(1000):
            sum += func(typ, i)

    iterations = 50_000
    test_types = [list[int], list, "list"]

    print(f"python version: {'.'.join(map(str, sys.version_info[:2]))}")
    for typ in test_types:
        print(f"---- Testing with type: {typ!r} ----")
        print("typing.cast:    ", timeit.timeit(partial(test_func, typ, tpcast), number=iterations))
        print("fastercast.cast:", timeit.timeit(partial(test_func, typ, fcast), number=iterations))
        print("no cast:        ", timeit.timeit(test_no_func, number=iterations))
        print()


if __name__ == "__main__":
    raise SystemExit(main())
