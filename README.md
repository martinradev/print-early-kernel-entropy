This module prints:
* the virtual and physical KASLR offsets
* the virtual offsets of the randomized memory regions
* the IRQ stack cookie of each logical CPU
* the stack cookie of the first 16 processes

Tested on Linux 4.19.43

Example output:
```
print_kaslr: _text virt_addr: ffffffffa5400000
print_kaslr: _text phys_addr: 5600000
print_kaslr: page_offset_base: ffff92c280000000
print_kaslr: vmalloc_base: ffffb24a40000000
print_kaslr: vmemmap_base: fffff04840000000
print_kaslr: boot/irq_stack cpu 0 canary: 66f5d705d7cf3500
print_kaslr: Task pid 1. canary: e8d8199a6c3b2700
print_kaslr: Task pid 2. canary: 81f97889ba6a3000
print_kaslr: Task pid 3. canary: 7d379c468a942700
print_kaslr: Task pid 4. canary: 450457b6ab000600
print_kaslr: Task pid 5. canary: dc8f4e033e14d400
print_kaslr: Task pid 6. canary: f2b300fe88ecb700
print_kaslr: Task pid 7. canary: 6a1919cd4a37f500
print_kaslr: Task pid 8. canary: 3d6e2c17afda4500
print_kaslr: Task pid 9. canary: 538d37bda256aa00
print_kaslr: Task pid 10. canary: 307ac2295e5bba00
print_kaslr: Task pid 11. canary: b378fe95a44eda00
print_kaslr: Task pid 12. canary: 39bbc994f8d14100
print_kaslr: Task pid 13. canary: cfd232e49e239800
print_kaslr: Task pid 14. canary: af6e2508bc25dd00
print_kaslr: Task pid 15. canary: b2d91e461ec86400
print_kaslr: Task pid 16. canary: 4e4ffdeac6e7d400
print_kaslr: Task pid 17. canary: fc8a739b20ac2d00
```
