FROM node:16.13.0-alpine

MAINTAINER alexandre.juan@epitech.eu

# WORKDIR /app
WORKDIR /usr/src/app/Dashboard
# COPY ./Dashboard/ ./

COPY Dashboard/package*.json ./

RUN npm install -g @angular/cli
RUN yarn add @angular-devkit/build-angular --dev
RUN npm install --save --legacy-peer-deps
EXPOSE 4200
CMD [ "npm", "start" ]
# RUN npm run build --prod

# FROM nginx:1.16.0-alpine

# COPY --from=build /app/dist/Dashboard /usr/share/nginx/html
# COPY nginx.conf /etc/nginx/nginx.conf

# EXPOSE 80

# CMD [ "nginx", "-g", "daemon off;" ]