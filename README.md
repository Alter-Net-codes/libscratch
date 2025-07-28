# libscratch
Another implementation of the Scratch block-code interpreter and virtual machine. 


## About
libscratch is a library that aims to emulate and replicate the behaviour of Scratch 3's virtual machine: specifically the parts that deal with interpreting your block-code. 
When completed, it should be possible to create Scratch programs in C++ or Python, instead of writing JavaScript Turbowarp extensions or using blockcode.

``` python

from libscratch import ScratchBlock, ScratchVirtualMchine

```

## Installation
libscratch should soon be available on [pip](https://pypi.org), so you can install it like this to use the complimentary Python API:
`pip install libscratch`

Or, if you like C++, you can install it using the CMakeLists.txt in the root directory. Please note the use of the BSD-3-Clause "New" or "Revised" License.

## Documentation
There will be a `docs/` folder when the API is *relatively* stable. 

## Contribution
If you want to contribute, put a PR from the dev branch. Releases should consiste of **BOTH** a Python release and C++ release.
