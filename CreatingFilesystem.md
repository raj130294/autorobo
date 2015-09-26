Different possible methods:
  1. using rootstock (for experts)
  1. online Angstrom build

# 1. rootstock #
## You want to boot your BeagleBoard to be able to login and use hardware interfaces? ##

### Here's how: ###
  1. boot into **Ubuntu 9.10**
  1. install needed tools via:
```
sudo apt-get -y install rootstock uboot-mkimage
```
  1. generate an ARM rootfs development environment via:
```
rootstock --fqdn vector --login master --password master --imagesize 3G --kblayout gb --serial ttyS2 --locale en_US --seed \
ubuntu-standard,build-essential,openssh-server,nano,linux-firmware,wireless-tools,usbutils
```

### Troubleshooting ###

rootstock uses qemu-arm-rootfs to execute ARM binaries without booting into a qemu virtualised kernel, thus relies on _misc binary format_ support from the kernel, and related distro services started (ie /etc/init.d/binfmt-support)

# 2. Online Angstrom build #

You can use this online service to build Angstrom for BeagleBoard:
http://www.angstrom-distribution.org/narcissus/

Now the TI SGX drivers (with demos) are included for the unstable version.