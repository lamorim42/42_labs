FROM ubuntu:20.04

WORKDIR /api_42

RUN apt-get update
RUN apt-get -y install default-libmysqlclient-dev libmysqlclient-dev build-essential

COPY . .

EXPOSE 3306

RUN make

ENTRYPOINT [ "./my_api" ]
