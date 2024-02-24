ipath= /opt/include
nlibpath= /opt/lib/native
rlibpath= /opt/lib/riscv32

libsysy= $(nlibpath)/libsysy.a
libkoopa= $(nlibpath)/libkoopa.a

hello-from-koopa: hello.koopa
	koopac $< | llc --filetype=obj -o hello.o
	clang hello.o -I$(ipath) -L$(nlibpath) -lsysy -o $@ 	
	./$@

hello-from-asm: hello.S 
	clang $< -c -o hello.o -target riscv32-unknown-linux-elf -march=rv32im -mabi=ilp32
	ld.lld hello.o -L$(rlibpath) -lsysy -o $@
	qemu-riscv32-static $@

clean: 
	rm -f *.o hello-from-koopa hello-from-asm