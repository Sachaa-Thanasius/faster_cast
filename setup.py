from setuptools import Extension, setup

setup(ext_modules=[Extension(name="fastercast", sources=["fastercastmodule.c"])])
