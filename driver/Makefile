PWD         = $(shell pwd) 
KVERSION    = $(shell uname -r)
KERNEL_DIR  = /usr/src/linux-headers-$(KVERSION)/

obj-m       = demo_drv.o 

all:
	make -C $(KERNEL_DIR) M=$(PWD) modules

clean:
	make -C $(KERNEL_DIR) M=$(PWD) clean

install:
	sudo insmod demo_drv.ko
	#check the result by typing: lsmod | grep "demo_drv"

uninsall:
	sudo rmmod demo_drv

dev_node:
	sudo mknod /dev/demo_drv c 60 0 #60 and 0 are major and minor revision number
	#check the result by typing: ls /dev/demo_drv
