FROM node:16.13.0-alpine


WORKDIR /usr/src/app/Area

COPY . .
RUN ls -la

RUN npm install

RUN npm install -g @angular/cli

WORKDIR /usr/src/app/Area/web

# RUN npm install @angular-devkit/build-angular

EXPOSE 4200
CMD [ "ng", "serve", "--host", "0.0.0.0", "--port", "8081"]
