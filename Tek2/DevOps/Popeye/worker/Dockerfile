FROM maven:3.5-jdk-8-alpine AS builder

WORKDIR /code
COPY ./ ./

RUN mvn dependency:resolve
COPY ./ ./
RUN mvn package

FROM openjdk:8-jre-alpine

WORKDIR /code

COPY --from=builder /code/target/worker-jar-with-dependencies.jar .
CMD ["java", "-jar", "worker-jar-with-dependencies.jar"]
