NAME := fortytwo

obj-m += $(NAME).o

# Source files
$(NAME)-y := main.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
