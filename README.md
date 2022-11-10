# lvm nonsense

build a debug build
via `mkdir cmake-build-debug && (cd cmake-build-deb; cmake --build ./cmake-build-debug --target lvm_bullshit)`

## Required Tools

- cmake
- pkg-config
- libblockdev
- lvm2

## notes

Don't use this code. I was trying to debug why my rust bindings had issues calling bd_lvm_pvcreate because clearly it
does in fact work with raw C.