PWD         = $(shell pwd) 
KVERSION    = $(shell uname -r)
KERNEL_DIR  = /usr/src/linux-headers-$(KVERSION)/

obj-m       = demo_drv.o 

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

install:
	sudo insmod demo.ko
	#check the result by typing: lsmod | grep "demo"

uninsall:
	sudo rmmod demo
