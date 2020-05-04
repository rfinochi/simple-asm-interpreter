FROM ubuntu:16.04

ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gcc make && \
    rm -rf /var/lib/apt/lists/*

COPY . /app
WORKDIR /app

RUN make build

ENTRYPOINT ["/app/smli.out"]