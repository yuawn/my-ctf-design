FROM ubuntu
MAINTAINER yuawn
RUN apt-get update
RUN apt-get install xinetd -y
RUN apt-get install libc6-dev-i386 -y
RUN useradd -m shellcode_revenge++
RUN chown -R root:root /home/shellcode_revenge++
CMD ["/usr/sbin/xinetd","-dontfork"]