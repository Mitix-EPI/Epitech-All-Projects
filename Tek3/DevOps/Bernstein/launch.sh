#!/bin/bash

# Monitoring Tool - Cadvisor
echo "$(tput setaf 2)Monitoring Tool - Cadvisor$(tput sgr 0)"
kubectl apply -f cadvisor.daemonset.yaml

# DB1 - Postgres
echo "$(tput setaf 2)# DB1 - Postgres$(tput sgr 0)"
kubectl apply -f postgres.secret.yaml       \
              -f postgres.configmap.yaml    \
              -f postgres.volume.yaml       \
              -f postgres.deployment.yaml   \
              -f postgres.service.yaml

# DB2 - Redis
echo "$(tput setaf 2)# DB2 - Redis$(tput sgr 0)"
kubectl apply -f redis.configmap.yaml   \
              -f redis.deployment.yaml  \
              -f redis.service.yaml


# Services - poll / worker / result
echo "$(tput setaf 2)# Services - poll / worker / result$(tput sgr 0)"
kubectl apply -f poll.deployment.yaml   \
              -f worker.deployment.yaml \
              -f result.deployment.yaml \
              -f poll.service.yaml      \
              -f result.service.yaml    \
              -f poll.ingress.yaml      \
              -f result.ingress.yaml

# Load Balancer - Traefik
echo "$(tput setaf 2)# Load Balancer - Traefik$(tput sgr 0)"
kubectl apply -f traefik.rbac.yaml          \
              -f traefik.deployment.yaml    \
              -f traefik.service.yaml

# Create database manually after first deploy
echo "$(tput setaf 2)# Create database manually after first deploy$(tput sgr 0)"
echo 'CREATE TABLE IF NOT EXISTS votes ( id text PRIMARY KEY , vote text NOT NULL );' | kubectl exec -i $(kubectl get pods --no-headers -o custom-columns=":metadata.name" | grep postgres) -- psql -U admin -d root && \
echo -e "\n$(tput setaf 2)DATABASE SUCCESS$(tput sgr 0)\n"


# Adds 2 fake DNS to /etc/hosts
echo "$(tput setaf 2)# Add 2 fake DNS$(tput sgr 0)"
INTERNAL_IP=$(kubectl get nodes -o jsonpath='{ $.items[*].status.addresses[?(@.type =="InternalIP")].address }')
echo "${INTERNAL_IP} poll.dop.io result.dop.io" | sudo tee -a /etc/hosts >/dev/null && \
echo -e "\n$(tput setaf 2)DNS SUCCESS$(tput sgr 0)\n\n"

echo -e "$(tput setaf 1)Poll:$(tput sgr 0)     http://poll.dop.io:30541/\n"
echo -e "$(tput setaf 3)Result:$(tput sgr 0)     http://result.dop.io:31539/\n"

minikube service list
