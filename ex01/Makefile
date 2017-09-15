obj-m += hello.o

all:
	make -C /lib/modules/4.12.7-knage/build M=$(PWD) modules

clean:
	make -C /lib/modules/4.12.7-knage/build M=$(PWD) clean
