ifneq ($(KERNELRELEASE),)
	obj-m := pdevice.o
else

default:
	$(MAKE) -C /usr/linuxf/linux-2.6.35.3  M=$(shell pwd) modules
endif

clean:
	rm  *.o *.ko *.mod.c  *.order *.symvers
