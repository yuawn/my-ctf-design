FROM ubuntu
MAINTAINER yuawn
RUN apt-get update
RUN apt-get install xinetd -y
RUN apt-get install libc6-dev-i386 -y
RUN useradd -m three_page
RUN chown -R root:root /home/three_page
CMD ["/usr/sbin/xinetd","-dontfork"]