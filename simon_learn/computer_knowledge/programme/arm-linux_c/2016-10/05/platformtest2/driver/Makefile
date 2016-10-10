ifneq ($(KERNELRELEASE),)
	obj-m := pdriver.o
else 

default:
	$(MAKE) -C /usr/linuxf/linux-2.6.35.3 M=$(shell pwd) modules

endif

clean:
	rm *.o *.ko  *.order  *.symvers  *.mod.c 
