FROM golang:1.15

LABEL version="1.0" maintainer="Clement Bolin <clement.bolin@epitech.eu>"

ARG workdir="btop"

WORKDIR /${workdir}

COPY . .

RUN apt-get update -y
RUN chmod +x ./install.sh
RUN echo "clement.bolin@epitech.eu" > .btop_config
RUN mv .btop_config ~/
RUN make build
