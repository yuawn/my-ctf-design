FROM ubuntu
MAINTAINER yuawn
RUN apt-get update
RUN apt-get install xinetd -y
RUN apt-get install libc6-dev-i386 -y
RUN useradd -m baby_heap
RUN chown -R root:root /home/baby_heap
CMD ["/usr/sbin/xinetd","-dontfork"]